#include <stdio.h>
#include <math.h>

/* 
    This function print integer numbers in binary format in N bits.
    It is not fully tested but work well with test cases I did.
    Report any issues with this function to my email.
    Email: abushattal.1@osu.edu
    Credit: Shivam Gupta
*/ 

void printBinary(int x, int N) {
 
    char a[N]; // create the char array that stores the bits
  
    int i = 0; // for the for and while loops
  
    for (i = 0; i < N; i++){  // initially assigns all bits in the array to zero
        a[i] = 0;
    }
        
    if (x < 0){  // deals with converting negative values to binary
      
        x = (int)(pow(2, N-1)) + x;	// changes x so that we figure out all bits except the leading bit in algorithm below
              
        a[N-1] = 1;		// makes the sign bit 1, since it must be since we are dealing with a negative number
    
    }
  
    i=0; // resets value of i
    
    
    // remainder algorithm to get the binary bits, and store them in the array
    
    while (i < N){
      
        if (x % 2 != 0){
            
            a[i] = 1;
            
        }
    
        i++;
    
        x = x/2; // keep on dividing by 2
        
        if (x == 0){ // we reached the end of the remainders, so we break and we are done
            break;
        }
    }
  
  
    for (i = 0; i < N; i++){
        
        // print all the bits in a backward fashion due to the nature of the algorithm
        
        printf ("%d", a[(N-1) - i]);  // could also use "%i" here
    }
    
}



int main() {
  
    int x = 32099;			/* N bits long = N/8 bytes = N/4 hex digits */
      
    printf ("x as hexadecimal number: %x\n", x);
      
    printf ("x as octal number: %o\n", x);
      
    printf ("x as signed number: %i\n", x);
      
    printf ("x as unsigned number: %u\n", x);
      
    printf ("x+1 as unsigned number: %u\n", x + 1);
      
    printBinary(x, 20);		/* custom function to print numbers in binary format */
      
    return 0;

}
