#include "Vector3n.h"

namespace MathEngine{
	
	class Matrix3n{
			private:
			
			public:
				float matrixData[9] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
				
				//empty constructor
				Matrix3n();
				//constructor
				Matrix3n(float m0, float m3, float m6, 
						 float m1, float m4, float m7,
						 float m2, float m5, float m8);
				//destructor
				~Matrix3n();
				
				//print matrix data
				void show();	
				
				//copy constructor
				Matrix3n& operator=(const Matrix3n& m);
				
				//overload operator+
				Matrix3n operator+(const Matrix3n& m)const;
				//overload operator+=
				void operator+=(const Matrix3n& m);
				
				//overload operator
				Matrix3n operator-(const Matrix3n& m)const;
				//overload operator-=
				void operator-=(const Matrix3n& m);
				
				//overload opertor * for scalar multiplication
				Matrix3n operator*(const float s)const;
				//overload operator *= for scalar multiplication to self
				void operator*=(const float s);
				
				//overload opertor * for matrix multiplication
				Matrix3n operator*(const Matrix3n& m)const;
				//overload operator *= for matrix multiplication to self
				void operator*=(const Matrix3n& m);
				
				//set matrix as an identity matrix
				void setAsIdentityMatrix();
				
				//set as inverse matrix
				void setAsInverseMatrix(const Matrix3n& m);
				
				//get the inverse of matrix
				Matrix3n getInverseofMatrix()const;
				
				//invert matrix
				void invertMatrix();
				
				//set matrix as transpose of a given matrix
				void setMatrixAsTransposeMatrix(const Matrix3n& m);
				
				//get transpose of matrix
				Matrix3n getTranspose()const;
				
				//matrix vector transformation overload operator *
				Vector3n operator*(const Vector3n& vect)const;
				
				//matrix vector transformation
				Vector3n transformVector(const Vector3n& vect)const;
	};
	
}














