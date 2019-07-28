#if !defined (SECANT_H)
#define SECANT_H

#include "MultiVarAndEqnsFunction.h"
#include <cmath>
#include <iostream>
#include "Matrix.h"

using namespace std;
class Secant
{
   private:

   public:
      static double* multipleEquationModifiedSecant(MultiVarAndEqnsFunction* f, double* xy, int numEqns, double* dxy, double tol, int max);
};

/*
double** get_driv(MultiVarAndEqnsFunction* f,double*xy, double*dxy,int numEqns,double tol)
{
//create new 2d array 
double** temp =  new double*[numEqns];
double h =100;
int s=0;
while (h * 100 > tol){
	cout << "iter: " <<s <<endl;
double* res = f->evaluate(xy);

double** temp =  new double*[numEqns];
		for(int i = 0; i < numEqns; ++i )
		{
		    temp[i]  = new double[numEqns];
		}

	
//loop to add delta
   for (int i =0;i<numEqns;i++){
   		for (int j =0;j<numEqns;j++){
   			if (j == i){
   				temp[i][j] = xy[j] + dxy[j];

   			}else{
   				temp[i][j] = xy[j];
   			}
   			cout << " delta" <<i <<" "<<j <<temp[i][j] <<endl;
   		}

   }


double** result2 =  new double*[numEqns];

		for(int i = 0; i < numEqns; ++i )
		{
		    result2[i]  = new double[numEqns];
		}
for (int i=0;i<numEqns;i++){
	  result2[i]= f->evaluate(temp[i]);

}
/*
for (int i=0;i<numEqns;i++){
	for (int j=0;j<numEqns;j++){
	  cout <<result2[i][j] <<endl;

}}
*//*
//loop to add delta
Matrix m1 = Matrix(numEqns,numEqns);
Matrix* m2 =new  Matrix(numEqns,1);
Matrix* m5 =new  Matrix(numEqns,1);
m1.displayMatrix();		
for (int i =0;i<numEqns;i++){
   	for (int j =0;j<numEqns;j++){ 
   		m1.setElement (j+1,i+1,(result2[i][j] - res[j]) / dxy[j]);
   		m2->setElement(j+1,1, xy[j]);
   		m5->setElement(j+1,1, -res[j]);
   		}
   cout << "============" <<endl;
}


m1.displayMatrix();	
m2->displayMatrix();
Matrix* m3 = m1.inverse();
m3->displayMatrix();
Matrix* m4 = m1.multiply(m2);
m4->displayMatrix();
m5->displayMatrix();
Matrix* m6=m4->add(m5);
m6->displayMatrix();
Matrix* m7 = m3->multiply(m6);
m7->displayMatrix();

for (int i=0;i<numEqns;i++){
 	xy[i] = m7->getElement(i+1,1);
}
	h=0;
	for (int i=0;i<numEqns;i++){
		h += pow((m7->getElement(i+1,1) - m2->getElement(i+1,1)) /m7->getElement(i+1,1),2); 
	}
	cout << "error: " << sqrt(h) *100;
	s++;
}
 //double* result3 = f->evaluate(start);
 //double g= abs(pow((result[0]-result3[0]),2) + pow((result[1]-result3[1]),2) ) * 100;
 //cout << sqrt(g)<<endl;
//delete[] result2;
//delete result;

return temp;
}
*/







double* Secant::multipleEquationModifiedSecant(MultiVarAndEqnsFunction* f, double* xy, int numEqns, double* dxy, double tol, int max){
	//create new 2d array 
	double** temp =  new double*[numEqns];
	double err =100;
	int iter=0;
	double* r;
	while ((err * 100) > tol || iter >= max){
		cout << "------------------------------------"<<endl;
		cout << "iter: " <<iter <<endl;
		//get f,g(w,x,y,z)
		double* res = f->evaluate(xy);
		
		//create 2d array to store the new+ delta
		double** temp =  new double*[numEqns];
				for(int i = 0; i < numEqns; ++i )
				{
				    temp[i]  = new double[numEqns];
				}

		

		//loop to add delta
	   	for (int i =0;i<numEqns;i++){
	   		for (int j =0;j<numEqns;j++){
	   			if (j == i){
	   				temp[i][j] = xy[j] + dxy[j];
	   			}else{
	   				temp[i][j] = xy[j];
	   			}
	   		}

	   }

	   //get f,g(w,x,y,z) adding the delta to them
	   double** result2 =  new double*[numEqns];
		for(int i = 0; i < numEqns; ++i )
		{
		    result2[i]  = new double[numEqns];
		}

		//evalute useing delata
		for (int i=0;i<numEqns;i++){
		  result2[i]= f->evaluate(temp[i]);

        }

		//m1 hold P (preturbed)
		Matrix m1 = Matrix(numEqns,numEqns);
		
		//m2 hold the current (w,x,y,z)
		Matrix* m2 =new  Matrix(numEqns,1);

		//hold -f(,wx,y,z)
		Matrix* m5 =new  Matrix(numEqns,1);
		
		for (int i =0;i<numEqns;i++){
		   	for (int j =0;j<numEqns;j++){ 
		   		m1.setElement (j+1,i+1,(result2[i][j] - res[j]) / dxy[j]);
		   		m2->setElement(j+1,1, xy[j]);
		   		m5->setElement(j+1,1, -res[j]);
		   		}
		}

		//cout << "preturbed:" <<endl;
		//m1.displayMatrix();	
		
		//solve p^-1
		Matrix* m3 = m1.inverse();
		//cout << "inverse:" <<endl;
		//m3->displayMatrix();

		Matrix* m4 = m1.multiply(m2);
		//m4->displayMatrix();
		//m5->displayMatrix();
		
		//solve for the right hand side
		Matrix* m6=m4->add(m5);
		//cout << "rds:" <<endl;
		//m6->displayMatrix();
		
		//solve the +1
		Matrix* m7 = m3->multiply(m6);
		cout << "Next:" <<endl;
		m7->displayMatrix();

		//update the value to next
		for (int i=0;i<numEqns;i++)
		{
 			xy[i] = m7->getElement(i+1,1);
		}
		
		//get the error sqrt(sum of ea^2)
		err=0;
		for (int i=0;i<numEqns;i++){
			err += pow((m7->getElement(i+1,1) - m2->getElement(i+1,1)) /m7->getElement(i+1,1),2); 
		}
		cout << "error: " << sqrt(err) *100 <<endl;
		iter++;
}
r = f->evaluate(xy);
return r;
}

#endif
