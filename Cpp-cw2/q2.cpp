# include <iostream>
int main () {
int i = 5;
int j = i++;
int k = ++i;
std :: cout << "i: " << i << std :: endl ;
std :: cout << "j: " << j << std :: endl ;
std :: cout << "k: " << k << std :: endl ;
}

/*
The output produced by this program is:

i: 7
j: 5
k: 7

Because we first define i to be 5. Next, we initialize the value of j by using 'int j = i++'.
This means that the current value of i (which is 5) is first assigned to j, and then i is 
increased by 1. As a result, i = 6 and j = 5. 

Then, we we initialize the value of j by using 'int k = ++i'. This means we first increase 
the value of i by 1, making i equal to 7, and then the new value of i is assigned to k. 
Therefore, the final values are:
i = 7, j = 5, k = 7
*/
