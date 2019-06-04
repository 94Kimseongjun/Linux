#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
         int i = 0; 
         int j = 0;

    

         for( i = 0; i < 4; ++i ) 
                for( j = 0; j < 4; ++j ) 
                     printf( "%d x %d = %d\n", i, j, i * j );
                
          assert( 0 );
          exit( 0 );
}
