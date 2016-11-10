#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    
    int array_size = 10;
    
    // Declare an array of array_size integers in the usual way
    float array[array_size]; //changed type from int to float

    // Allocate a block of array_size integers and assign the address
    // of the beginning of the memory block to the pointer array2
    long double *memblock = malloc(array_size * sizeof(long double)); //changed *memblock type from int to long double; changed sizeof(int) to long double
    /* WARNING: malloc may fail and return a NULL value for the pointer
                Good programming practice mandates checking for such failures.
    */
    if (NULL == memblock) {
      // Print to the "file" of standard error, rather than standard out
      fprintf(stderr, "malloc failed\n");
      // Return a non-successful integer
      return -1;
    }
   
    char foo[array_size];
 
    set_arrays(array_size, array, memblock, &foo);
    print_arrays(array_size, array, memblock, &foo);
   
  
    // explicitly free the block of memory malloc-ed at memblock 
    free(memblock);

    // memory not explicitly freed is automatically freed on function exit
    return 0;
}

void set_arrays(int arraySize, float *anArray, long double *memBlock, char *fooBar) {
    
    // iteration index
    int i;
    char *foo = "Foo bar .";

    for (i=0; i < arraySize; i++)
    {
        // assign the value i to the ith element 
        anArray[i] = i;
        
        // set the value inside the memory address at memblock + (i bytes) to i
        *(memBlock+i) = i;

        fooBar[i] = foo[i];
    }

}

void print_arrays(int arraySize, float * anArray, long double *memBlock, char *fooBar) {
    
 
    int i;

    // increment three bytes BEYOND the allocated memory (buffer overrun)
    for (i=0; i < (arraySize + 3); i++)
    {
        // print the array values in the usual way
        printf("array[%d] : %f\t", i, anArray[i]); //changed second formatting from int to float
        
        // print the values contained in each memory address from memblock on
        printf("*(memblock + %d) : %Lf\t", i, *(memBlock+i));//changed second formatting from int to long float
        // print each character in the string
        printf("foo[%d] : %c\t", i, fooBar[i]);
        
        // do the same thing, but in pointer notation
        printf("*(foo + %d) : %c\n", i, *(fooBar+i));

    }
}

