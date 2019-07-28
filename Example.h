#if !defined (EVALUATE_H)
#define EVALUATE_H

#include "MultiVarAndEqnsFunction.h"

class Evaluate : public MultiVarAndEqnsFunction
{
   private:

   public:
      Evaluate();
      ~Evaluate();
      double* evaluate(double* xyz);
};

#endif
