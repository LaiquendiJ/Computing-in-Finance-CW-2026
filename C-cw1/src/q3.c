#include <stdio.h>


int main(){
    int cont=0;
    float max_val, min_val;
    while (1)
    {   
        int val;
        scanf("%d",&val);
        cont++;
        max_val = (val > max_val) ? val : max_val;
        if (val<0){   
            min_val = val;
            break;
        }  
    }
    printf("count=%d, max=%.2f, min=%.2f, range=[%.2f,%.2f]", cont, max_val, min_val,min_val, max_val);
}