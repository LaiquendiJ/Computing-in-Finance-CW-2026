#include <iostream>
class MyClass
{
public:
    MyClass(int x) : x(x)
    {
        std ::cout << "constructor called , x = " << this->x << std ::endl;
    }
    MyClass(const MyClass &other) : x(other.x)
    {
        std ::cout << "copy constructor called , x = " << x << std ::endl;
    }
    MyClass &operator=(const MyClass &other)
    {
        std ::cout << "assignment operator called , x was " << x << " and became " << other.x << std ::endl;
        x = other.x;
        return *this;
    }
    ~MyClass()
    {
        std ::cout << "destructor called , x = " << this->x << std ::endl;
    }

private:
    int x;
};
int main()
{
    MyClass a{3};
    MyClass b{5};
    MyClass c{a};
    c = b;
    a = b;
}

/*
The output produced by this program is:

constructor called , x = 3
constructor called , x = 5
copy constructor called , x = 3
assignment operator called , x was 3 and became 5
assignment operator called , x was 3 and became 5
destructor called , x = 5
destructor called , x = 5
destructor called , x = 5

For the first two lines, the constructor of MyClass is called with an int value, so the constructor 
MyClass(int x) : x(x) is invoked, and the code inside this constructor is executed.

For the third line, the constructor of MyClass is called with a value of type Myclass, so the constructor 
MyClass(const MyClass &other) : x(other.x) is invoked, and the code inside this constructor is executed.
Accoriding to the code inside the function, we now have c.x = a.x = 3.

The following lines utilize the overloaded assignment operator. When c = b and a = b are executed, the 
operator= function is invoked, performing a member-wise assignment where the value of other.x is copied 
to the current instance. Due to the right-associativity of the operator, c.x is assigned to b.x, and also,
b.x is assigned to a.x. All three instances now hold an x value of 5.

Upon the completion of main(), he automatic variables are cleaned up. The ~MyClass() destructor is invoked 
for each object in the reverse order of their construction.

*/