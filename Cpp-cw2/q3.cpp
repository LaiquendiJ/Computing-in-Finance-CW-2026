#include <iostream>
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    std ::cout << "swap1 : a: " << a << ", b: " << b << std ::endl;
}
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    std ::cout << "swap2 : *a: " << *a << ", *b: " << *b << std ::endl;
}
void swap3(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    std ::cout << "swap3 : a: " << a << ", b: " << b << std ::endl;
}
int main()
{
    int a = 3;
    int b = 5;
    std ::cout << "main : a: " << a << ", b: " << b << std ::endl;
    swap1(a, b);
    std ::cout << "main : a: " << a << ", b: " << b << std ::endl;
    swap2(&a, &b);
    std ::cout << "main : a: " << a << ", b: " << b << std ::endl;
    swap3(a, b);
    std ::cout << "main : a: " << a << ", b: " << b << std ::endl;
}

/*
The output produced by this program is:

main : a: 3, b: 5
swap1 : a: 5, b: 3
main : a: 3, b: 5
swap2 : *a: 5, *b: 3
main : a: 5, b: 3
swap3 : a: 3, b: 5
main : a: 3, b: 5

The first line shows the original values of a and b produced in the main() function, 
where a is 3 and b is 5.

Next, the function swap1() is called. The parameters are declared as 'int a, int b', 
which means the function receives copies of the values of a and b. 
In swap1, we use a temporary variable temp to store the value of a. Then the value 
of b is assigned to a, and next the value stored in temp is assigned to b. 
As a result, we swap the local copies of the a and b. The output produced
inside swap1() shows a = 5 and b = 3.

Since we only changed the copy of a and b inside swap1(), this would not affect the 
original variables in main(). So back to main(), we still have a = 3, b = 5.

Next, the function swap2() is called. Its parameters are declared as 'int* a and int* b', 
and the function is invoked using swap2(&a, &b). This means that the function receives 
the addresses of the variables a and b. 
In swap2(), a temporary variable temp is used to store the value pointed to by a. The value 
pointed to by b is then assigned to the location pointed to by a, and finally the value 
stored in temp is assigned to the location pointed to by b. 
As a result, we swap the values stored at the memory locations of a and b. The output
produced inside swap2() shows *a = 5 and *b = 3.

Since we changed values stored at the memory locations of a and b inside swap1(), this 
would also changes the original variables in main(). 
So back to main(), we have a = 5, b = 3.

Next, the function swap3() is called. Its parameters are declared as 'int &a and int &b', 
This means that the function receives references to the original variabless a and b. 
In swap3(), we use a temporary variable temp to store the value of a. Then the value 
of b is assigned to a, and next the value stored in temp is assigned to b. 
As a result, we swap the original values of a and b. The output produced inside swap3() 
shows a = 3 and b = 5.

Since we changed the original values of a and b inside swap3(), this would also affect 
the variable values in main(). So back to main(), we have a = 3, b = 5.
*/