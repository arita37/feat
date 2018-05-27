/* FEAT
copyright 2017 William La Cava
license: GNU/GPL v3
*/
#ifndef NODE_COS
#define NODE_COS

#include "nodeDx.h"

namespace FT{
	class NodeCos : public NodeDx
    {
    	public:
    	  	
    		NodeCos(vector<double> W0 = vector<double>());
    		
            /// Evaluates the node and updates the stack states. 
            void evaluate(Data& data, Stacks& stack);

            /// Evaluates the node symbolically
            void eval_eqn(Stacks& stack);

            ArrayXd getDerivative(vector<ArrayXd>& stack_f, int loc);

        protected:
            NodeCos* clone_impl() const override;
      
            NodeCos* rnd_clone_impl() const override;
    };
}	

#endif
