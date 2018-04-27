/* FEWTWO
copyright 2017 William La Cava
license: GNU/GPL v3
*/
#ifndef NODE_ADD
#define NODE_ADD

#include "nodeDx.h"

namespace FT{
	class NodeAdd : public NodeDx
    {
    	public:
    	
    		NodeAdd()
       		{
    			name = "+";
    			otype = 'f';
    			arity['f'] = 2;
    			arity['b'] = 0;
    			complexity = 1;

                for (int i = 0; i < arity['f']; i++) {
                    W.push_back(1);
                }
    		}
    		
            /// Evaluates the node and updates the stack states. 
            void evaluate(const MatrixXd& X, const VectorXd& y, vector<ArrayXd>& stack_f, 
                    vector<ArrayXb>& stack_b)
			{
        		ArrayXd x2 = stack_f.back(); stack_f.pop_back();
                ArrayXd x1 = stack_f.back(); stack_f.pop_back();
                stack_f.push_back(limited(this->W[1] * x1 + this->W[0] * x2));
            }
            
            /// Evaluates the node symbolically
            void eval_eqn(vector<string>& stack_f, vector<string>& stack_b)
            {
        		string x2 = stack_f.back(); stack_f.pop_back();
                string x1 = stack_f.back(); stack_f.pop_back();
                stack_f.push_back("(" + x1 + "+" + x2 + ")");
            }

            // NEED TO MAKE SURE CASE 0 IS TOP OF STACK, CASE 2 IS w[0]
            ArrayXd getDerivative(vector<ArrayXd>& stack_f, int loc) {
                switch (loc) {
                    case 3: 
                        return stack_f[stack_f.size()-2];
                    case 2: 
                        return stack_f[stack_f.size()-1];
                    case 1:
                        return this->W[1] * ArrayXd::Ones(stack_f[stack_f.size()-2].size());
                    case 0:
                    default:
                        return this->W[0] * ArrayXd::Ones(stack_f[stack_f.size()-1].size());
                } 
            }

        protected:
            NodeAdd* clone_impl() const override { return new NodeAdd(*this); };  
    };
}	

#endif
