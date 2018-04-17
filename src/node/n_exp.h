/* FEWTWO
copyright 2017 William La Cava
license: GNU/GPL v3
*/
#ifndef NODE_EXP
#define NODE_EXP

#include "node.h"

namespace FT{
	class NodeExp : public Node
    {
    	public:
   	
    		NodeExp()
    		{
    			name = "exp";
    			otype = 'f';
    			arity['f'] = 1;
    			arity['b'] = 0;
    			complexity = 4;
    		}
    		
            /// Evaluates the node and updates the stack states. 
            void evaluate(const MatrixXd& X, const VectorXd& y, vector<ArrayXd>& stack_f, 
                    vector<ArrayXb>& stack_b);

            /// Evaluates the node symbolically
            void eval_eqn(vector<string>& stack_f, vector<string>& stack_b)
            {
        		string x = stack_f.back(); stack_f.pop_back();
                stack_f.push_back("exp(" + x + ")");
            }
        protected:
            NodeExp* clone_impl() const override { return new NodeExp(*this); };  
    };
#ifndef USE_CUDA
    void NodeExp::evaluate(const MatrixXd& X, const VectorXd& y, vector<ArrayXd>& stack_f, 
                    vector<ArrayXb>& stack_b)
    {
        ArrayXd x = stack_f.back(); stack_f.pop_back();
        stack_f.push_back(limited(exp(x)));
    }
#else
    void NodeExp::evaluate(const MatrixXd& X, const VectorXd& y, vector<ArrayXd>& stack_f, 
                    vector<ArrayXb>& stack_b)
    {
        GPU_NodeExp(stack.dev_f, stack.idx[otype], stack.N);
    }
#endif
}	

#endif
