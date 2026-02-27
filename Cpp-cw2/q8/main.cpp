#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

// Standard normal CDF using erfc
double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

// Black-Scholes formula for European call option
double black_scholes_price(double S, double K, double r, double sigma, double T) {
    if (S <= 0.0 || K <= 0.0) {
        throw std::invalid_argument("Spot and strike must be positive.");
    }
    if (T <= 0.0) {
        throw std::invalid_argument("Time to maturity must be positive.");
    }
    if (sigma < 0.0) {
        throw std::invalid_argument("Volatility cannot be negative.");
    }
    if (sigma == 0.0) {
        // If zero vol, payoff is deterministic under risk-neutral: S_T = S * exp(rT)
        // Price = exp(-rT) * payoff
        double ST = S * std::exp(r * T);
        double payoff = std::max(ST - K, 0.0);
        return std::exp(-r * T) * payoff;
    }
    const double sqrtT = std::sqrt(T);
    const double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrtT);
    const double d2 = d1 - sigma * sqrtT;
    const double disc = std::exp(-r * T);
    return S * norm_cdf(d1) - K * disc * norm_cdf(d2);
}

// Functor for Black-Scholes call price as a function of volatility
class BlackScholesCallFunctor {
private:
    double S_;
    double K_;
    double r_;
    double T_;

public:
    BlackScholesCallFunctor(double S, double K, double r, double T)
        : S_(S), K_(K), r_(r), T_(T) {}

    double operator()(double sigma) const {
        return black_scholes_price(S_, K_, r_, sigma, T_);
    }
};

// Generic interval bisection method
template<typename T>
double interval_bisection(double y_target, double left, double right, double epsilon, T functor) {
    if (epsilon <= 0.0) {
        throw std::invalid_argument("Epsilon must be positive.");
    }
    if (left >= right) {
        throw std::invalid_argument("Left endpoint must be less than or equal to right endpoint.");
    }
    
    double f_left = functor(left) - y_target;
    double f_right = functor(right) - y_target;

    // Check if endpoints are roots or if they bracket a root
    if (f_left == 0.0) {
        return left;
    }
    if (f_right == 0.0) {
        return right;
    }
    if (f_left * f_right > 0.0) {
        throw std::invalid_argument("Function values at endpoints must have opposite signs.");
    }

    // Bisection loop until interval is smaller than epsilon
    while ((right - left) > epsilon) {
        const double mid = (left + right) / 2.0;
        const double f_mid = functor(mid) - y_target;

        // Exact root found
        if (f_mid == 0.0) {
            return mid;
        }
        // Determine which subinterval contains the root
        if (f_mid * f_left < 0.0) {
            right = mid;
            f_right = f_mid;
        } else {
            left = mid;
            f_left = f_mid;
        }
    }
    // Return midpoint as best estimate
    return (left + right) / 2.0;
}

int main() {
    const double market_price = 13.6953;
    const double T = 0.25;
    const double K = 95.0;
    const double S = 100.0;
    const double r = 0.10;

    // Create functor for Black-Scholes call price as a function of volatility
    BlackScholesCallFunctor f(S, K, r, T);

    // Starting interval for implied volatility search: [0%, 500%]
    const double left = 0.0;
    const double right = 5.0;
    const double epsilon = 1e-8;

    const double implied_vol = interval_bisection(market_price, left, right, epsilon, f);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Implied volatility = " << implied_vol << "\n";

    // quick sanity: reprice using implied vol
    std::cout << "Price at implied vol = " << f(implied_vol) << "\n";
    return 0;
}
