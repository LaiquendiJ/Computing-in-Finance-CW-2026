#include <iostream>
class MyClass
{
public:
    MyClass(int x);
    const int *get() const;
    int *get();

private:
    int x;
};
MyClass ::MyClass(int x) : x(x) {}
const int *MyClass ::get() const
{
    std ::cout << "I am const , x = " << x << std ::endl;
    return &x;
}
int *MyClass ::get()
{
    std ::cout << "I am not const , x = " << x << std ::endl;
    return &x;
}
int main()
{
    const MyClass a{1};
    MyClass b{2};
    MyClass *c = new MyClass{3};
    const MyClass *d = new MyClass{4};
    const MyClass &e{a};
    MyClass &f{b};
    a.get();
    b.get();
    c->get();
    d->get();
    e.get();
    f.get();
    delete d;
    delete c;
}

/*
The output produced by this program is:

I am const , x = 1
I am not const , x = 2
I am not const , x = 3
I am const , x = 4
I am const , x = 1
I am not const , x = 2

The get() function is called for both the const object a and non-const object b. The 
corresponding version of get() is triggered for each instance, printing 1 and 2.

Pointers c (non-const) and d (const-pointed) use the -> operator to call get(). The 
compiler selects the appropriate function based on whether the pointed-to object is 
const, printing the values 3 and 4 respectively.

Two references are defined: e (const) and f (non-const) are bound to a and b. Calling 
.get() triggers the corresponding function overload for each, based on the reference 
type, printing the stored values 1 and 2 respectively.

Delete c and delete d are called at the end of the program. This triggers the destructors 
for the heap-resident MyClass instances and deallocates the associated memory blocks.
*/