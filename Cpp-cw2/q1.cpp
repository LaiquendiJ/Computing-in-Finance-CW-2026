# include <iostream>

int main () {
std :: cout << 25u - 50;
}
/*
The output produced by this program is:

4294967271 

According to the 'usual arithmetic conversions', the arithmetic
between an unsigned int and an int while the and the maximum value representable by unsigned int is greater 
than or equal to the maximum value representable by int, the int operand is converted to unsigned int. 
The result would also be the type of unsigned int. Since unsigned int cannot be negative, so the result(res) 
the result has the same value modulo 2^32. Since 25-50=-25, so res = 2^32-25 = 4294967271.
*/