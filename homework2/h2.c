
#include <stdio.h>

void printBinary(int x)
{
    /* This function print integer numbers in binary format.
    It is not fully tested but work well with test cases I did.
    Report any issues with this function to my email.
    email: abushattal.1@osu.edu
    */
    char a[32]; 
    int i = 0;
    
    for(i = 0; i< 32; i++)
        a[i] = 0;
    
    if(x < 0){    
        x = 2147483647 - x + 1;  /* get the 2's complement */
        a[31] = 1; /* The sign bit */
    }
    
    i = 0;
    while(i<32)
    {
        if(x%2 != 0)
            a[i] = 1;
        ++i;
        x = x/2;
        if(x==0)
            break;
    }
     
    for(i = 0; i< 32; i++)
        printf("%i", a[31-i]);
}

int main()
{
    int x = -1;  /* 32 bits long = 4 bytes  = 8 hex digits*/ 

    printf("x as hexadecimal number: %x\n", x);
    printf("x+1 as octal number: %o\n", x);
    printf("x as signed number: %i\n", x);
    printf("x as unsigned number: %u\n", x);
    printf("x+1 as unsigned number: %u\n", x+1);

    
    printBinary(x); /* custom function to print numbers in binary format */
    return 0;
}
