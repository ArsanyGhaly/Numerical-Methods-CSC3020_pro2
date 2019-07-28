#if !defined MATRIX_H
#define MATRIX_H

//the indices are 1-based!!
namespace CSC2110
{
class Matrix
{
   private:
      int rows;
      int cols;

      double* mat;
	  
	  void pivotRows(int i, int j);
      void normalizeRow(int row, int col);
      int partialPivot(int currentRow);
      Matrix* augment(Matrix* rhs);
      Matrix* extract();

   public:
      Matrix(int rows, int cols);  //constructor
      ~Matrix();                   //destructor
	  
      void displayMatrix();
      int getNumRows();
      int getNumCols();

      double getElement(int row, int col);
      void setElement(int row, int col, double val);

      Matrix* add(Matrix* other);
      Matrix* multiply(Matrix* other);

      static Matrix* readMatrix(const char* file_name);  //discuss static
      void writeMatrix(const char* file_name);
	  
	  Matrix* gaussJordan(Matrix* rhs);
};
}

#endif
