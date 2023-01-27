#include <stdio.h>
#include <stdlib.h>

void dgemm_scalar(int N, double *a, double *b, double *c) {
	for (int i=0; i<N; i++)
	    for (int j=0; j<N; j++) {
		double cij = 0;
		for (int k = 0; k<N; k++)
		    cij += a[i+k*N] * b[k+j*N];
		c[i+j*N] = cij;
	    }
}

//  The benchmark
int main( void ) {
    const int M = 1024; // The benchmark runs on a fixed size of work
    printf( "Running IAXPY operation of size %d x 1\n", M );

    //  Prep
    double *a = (double *) malloc( M * M * sizeof(double) );      // First vector
    double *b = (double *) malloc( M * M * sizeof(double) );      // Second vector
    double *c = (double *) malloc( M * M * sizeof(double) );
    // Call the algorithm
    dgemm_scalar( M, a, b, c );
    
    // Free up the memory
    free( a );
    free( b );
    free( c );
    return 0;
}
