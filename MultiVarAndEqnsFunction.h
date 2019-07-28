#if !defined (MULTIVARANDEQNSFUNCTION_H)
#define MULTIVARANDEQNSFUNCTION_H

class MultiVarAndEqnsFunction
{
   private:

   public:
      MultiVarAndEqnsFunction() {};
      ~MultiVarAndEqnsFunction() {};
      virtual double* evaluate(double* xy) = 0;
};

#endif
