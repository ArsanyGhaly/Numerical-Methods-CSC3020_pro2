#include "Example.h"
#include "Secant.h"

#include <cmath>
#include <iostream>
using namespace std;


Evaluate::Evaluate() : MultiVarAndEqnsFunction()
{
}

Evaluate::~Evaluate()
{
}

double* Evaluate::evaluate(double* xyz)
{
   double w = xyz[0];
   double x = xyz[1];
   double y = xyz[2];
   double z = xyz[3];

   double* result = new double[4];
   //double* result = new double[2];
   //result[0] = y + (x*x) - x -0.75;
   //result[1] = y+ (5*x*y) - (x*x);
   
   result[0] = 9*w + 3*x - 17.2;
   result[1] = log(y) + x*x*x - 4;
   result[2] = pow(z, 1.6) - 4.72*pow(w, 6.2) - 0.8;
   result[3] = w + cos(x) + y/7.4 + 0.5*z - 11;
   
   return result;
}

int main()
{
   MultiVarAndEqnsFunction* f = new Evaluate();
   int numEqns = 4;
   double* start = new double[numEqns];
   //double* start = new double[2];
   //start[0] =  1.2 ;//.0317675
   //start[1] =  1.2;//
   start[0] = 1.0;
   start[1] = 3.7;
   start[2] = 2.2;
   start[3] = 16.5;
   
   cout << "9w + 3x - 17.2=0" <<endl;
   cout << "log(y) + x^3 - 4=0" <<endl;
   cout << "(z^1.6) - 4.72*(w^6.2) - 0.8=0" <<endl;
   cout << "w + cos(x) + y/7.4 + 0.5z - 11=0" <<endl;
   cout << "------------------------------------"<<endl;
 
   
   double* incr = new double[numEqns];
   incr[0] = .01;
   incr[1] = .01;
   incr[2] = .01;
   incr[3] = .01;

   //Secant secant;
   Secant secant;
   double* result = secant.multipleEquationModifiedSecant(f, start, 4, incr, .001, 100);

   //cout << "x: " << start[0] << endl;
   //cout << "y: " << start[1] << endl;
   
   cout << "w: " << start[0] << endl;
   cout << "x: " << start[1] << endl;
   cout << "y: " << start[2] << endl;
   cout << "z: " << start[3] << endl;
   cout << "------------------------------------"<<endl;

   //double* result = f->evaluate(start);


   //cout << "a(w, x, y, z): " << result[0] << endl;
   //cout << "b(w, x, y, z): " << result[1] << endl;



   cout << "a(w, x, y, z): " << result[0] << endl;
   cout << "b(w, x, y, z): " << result[1] << endl;
   cout << "c(w, x, y, z): " << result[2] << endl;
   cout << "d(w, x, y, z): " << result[3] << endl;
   cout << "------------------------------------"<<endl;

   delete f;
   delete[] start;
   delete[] incr;
   delete[] result;

   return 0;
}
