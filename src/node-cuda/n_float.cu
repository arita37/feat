/* FEAT
copyright 2017 William La Cava
license: GNU/GPL v3
*/
#include "error_handling.h"
#include "cuda_utils.h"
//#include "../node/n_add.h"

namespace FT{
   		
    __global__ void Float(float * x, bool* y, size_t idxf, size_t idxb, size_t N)
    {                    
	    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < N; i += blockDim.x * gridDim.x)
            x[(idx)*N + i] = float(y[(idx-1)*N + i]);
            
        return;
    }
    
    __global__ void Float(float * x, int* y, size_t idxf, size_t idxi, size_t N)
    {                    
	    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < N; i += blockDim.x * gridDim.x)
            x[(idxf)*N + i] = float(y[(idxi-1)*N + i]);
            
        return;
    }
    
    void GPU_Float(float * x, bool* y, size_t idxf, size_t idxb, size_t N)
    {
        Add<<< DIM_GRID, DIM_BLOCK >>>(x, y, idxf, idxb, N);
    }
    
    void GPU_Float(float * x, int* y, size_t idxf, size_t idxf, size_t N)
    {
        Add<<< DIM_GRID, DIM_BLOCK >>>(x, y, idxf, idxi, N);
    }
}	


