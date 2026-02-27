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

int main() {
    double S = 100.0;       // spot
    double K = 95.0;        // strike
    double r = 0.1;         // cont comp
    double sigma = 0.5;     // vol
    double T = 0.25;        // year

    double call_price = black_scholes_price(S, K, r, sigma, T);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Call: " << call_price << "\n";

    return 0;
}
