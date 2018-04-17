/* FEAT
copyright 2017 William La Cava
license: GNU/GPL v3
*/
#include "cuda_utils.h"

static void Initialize()
{
    cudaDeviceGetAttribute(&NUM_SMS, cudaDevAttrMultiProcessorCount, 0); 
    DIM_GRID = 32*NUM_SMS;
    DIM_BLOCK = 128; 

}
static void HandleError( cudaError_t err, const char *file, int line )
{
	// CUDA error handeling from the "CUDA by example" book
	if (err != cudaSuccess)
    {
		printf( "%s in %s at line %d\n", cudaGetErrorString( err ), file, line );
		exit( EXIT_FAILURE );
	}
}


