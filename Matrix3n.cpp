#include "Matrix3n.h"
#include <iostream>

namespace MathEngine{
	
		//empty constructor
		Matrix3n::Matrix3n(){
			for(int i = 0; i < 9; i++){
				matrixData[i] = 0.0f;
			}
			matrixData[0]=matrixData[4]=matrixData[8]=1.0f;
		}
		
		//constructor
		Matrix3n::Matrix3n(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8){
			matrixData[0] = m0;
			matrixData[3] = m3;
			matrixData[6] = m6;
			
			matrixData[1] = m1;
			matrixData[4] = m4;
			matrixData[7] = m7;
			
			matrixData[2] = m2;
			matrixData[5] = m5;
			matrixData[8] = m8;
		}
				
		//destructor
		Matrix3n::~Matrix3n(){}
		
		//print matrix data
		void Matrix3n::show(){
			std::cout << "[" << matrixData[0] << "," <<matrixData[3] << ","<< matrixData[6] << "," << std::endl;
    		std::cout << matrixData[1] << "," << matrixData[4] << "," << matrixData[7] << "," << std::endl;
    		std::cout << matrixData[2] << "," << matrixData[5] << "," << matrixData[8] << "]" << std::endl;
		}
		
		//copy constructor
		Matrix3n& Matrix3n::operator=(const Matrix3n& m){
			matrixData[0] = m.matrixData[0];
			matrixData[3] = m.matrixData[3];
			matrixData[6] = m.matrixData[6];
			
			matrixData[1] = m.matrixData[1];
			matrixData[4] = m.matrixData[4];
			matrixData[7] = m.matrixData[7];
			
			matrixData[2] = m.matrixData[2];
			matrixData[5] = m.matrixData[5];
			matrixData[8] = m.matrixData[8];
			
			return *this;
		}
		
		//overload operator+
		Matrix3n Matrix3n::operator+(const Matrix3n& m)const{
			Matrix3n n;
			for(int i = 0; i < 9; i++){
				n.matrixData[i] = matrixData[i] + m.matrixData[i];
			}
			return n;
		}
		//overload operator+=
		void Matrix3n::operator+=(const Matrix3n& m){
			for(int i = 0; i < 9; i++){
				matrixData[i] += m.matrixData[i];
			}
		}
		
		//overload operator-
		Matrix3n Matrix3n::operator-(const Matrix3n& m)const{
			Matrix3n n;
			for(int i = 0; i < 9; i++){
				n.matrixData[i] = matrixData[i] - m.matrixData[i];
			}
			return n;
		}
		//overload operator-=
		void Matrix3n::operator-=(const Matrix3n& m){
			for(int i = 0; i < 9; i++){
				matrixData[i] -= m.matrixData[i];
			}
		}
		
		//overload opertor * for scalar multiplication
		Matrix3n Matrix3n::operator*(const float s)const{
			Matrix3n n;
			for(int i = 0; i < 9; i++){
				n.matrixData[i] = matrixData[i] * s;
			}
			return n;
		}
		//overload operator *= for scalar multiplication to self
		void Matrix3n::operator*=(const float s){
			for(int i = 0; i < 9; i++){
				matrixData[i] *= s;
			}
		}
		
		//overload opertor * for multiplication
		Matrix3n Matrix3n::operator*(const Matrix3n& m)const{
			return Matrix3n(matrixData[0]*m.matrixData[0]+ matrixData[3]*m.matrixData[1]+matrixData[6]*m.matrixData[2],
                       		matrixData[0]*m.matrixData[3]+ matrixData[3]*m.matrixData[4]+matrixData[6]*m.matrixData[5],
                       		matrixData[0]*m.matrixData[6]+ matrixData[3]*m.matrixData[7]+matrixData[6]*m.matrixData[8],

                       		matrixData[1]*m.matrixData[0]+ matrixData[4]*m.matrixData[1]+matrixData[7]*m.matrixData[2],
                       		matrixData[1]*m.matrixData[3]+ matrixData[4]*m.matrixData[4]+matrixData[7]*m.matrixData[5],
                       		matrixData[1]*m.matrixData[6]+ matrixData[4]*m.matrixData[7]+matrixData[7]*m.matrixData[8],

                       		matrixData[2]*m.matrixData[0]+ matrixData[5]*m.matrixData[1]+matrixData[8]*m.matrixData[2],
                       		matrixData[2]*m.matrixData[3]+ matrixData[5]*m.matrixData[4]+matrixData[8]*m.matrixData[5],
                       		matrixData[2]*m.matrixData[6]+ matrixData[5]*m.matrixData[7]+matrixData[8]*m.matrixData[8]);
		}
		//overload operator *= for multiplication to self
		void Matrix3n::operator*=(const Matrix3n& m){
			float t1;
    		float t2;
    		float t3;

    		t1=matrixData[0]*m.matrixData[0]+ matrixData[3]*m.matrixData[1]+matrixData[6]*m.matrixData[2];
    		t2=matrixData[0]*m.matrixData[3]+ matrixData[3]*m.matrixData[4]+matrixData[6]*m.matrixData[5];
    		t3=matrixData[0]*m.matrixData[6]+ matrixData[3]*m.matrixData[7]+matrixData[6]*m.matrixData[8];

    		matrixData[0]=t1;
    		matrixData[3]=t2;
    		matrixData[6]=t3;

    		t1=matrixData[1]*m.matrixData[0]+ matrixData[4]*m.matrixData[1]+matrixData[7]*m.matrixData[2];
    		t2=matrixData[1]*m.matrixData[3]+ matrixData[4]*m.matrixData[4]+matrixData[7]*m.matrixData[5];
    		t3=matrixData[1]*m.matrixData[6]+ matrixData[4]*m.matrixData[7]+matrixData[7]*m.matrixData[8];

    		matrixData[1]=t1;
    		matrixData[4]=t2;
    		matrixData[7]=t3;


    		t1=matrixData[2]*m.matrixData[0]+ matrixData[5]*m.matrixData[1]+matrixData[8]*m.matrixData[2];
    		t2=matrixData[2]*m.matrixData[3]+ matrixData[5]*m.matrixData[4]+matrixData[8]*m.matrixData[5];
    		t3=matrixData[2]*m.matrixData[6]+ matrixData[5]*m.matrixData[7]+matrixData[8]*m.matrixData[8];

    		matrixData[2]=t1;
    		matrixData[5]=t2;
    		matrixData[8]=t3;
		}
		
		//set matrix as an identity matrix
		void Matrix3n::setAsIdentityMatrix(){
			for(int i = 0; i < 9; i++){
				matrixData[i] = 0.0f;
			}
			matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
		}
		
		//set as inverse matrix
		void Matrix3n::setAsInverseMatrix(const Matrix3n& m){
				
				float t1 = m.matrixData[0] * m.matrixData[4];
    			float t2 = m.matrixData[0] * m.matrixData[7];
    			float t3 = m.matrixData[3] * m.matrixData[1];
    			float t4 = m.matrixData[6] * m.matrixData[1];
    			float t5 = m.matrixData[3] * m.matrixData[2];
    			float t6 = m.matrixData[6] * m.matrixData[2];

    			//calculate the determinant
    			float det = (t1 * m.matrixData[8] - t2 * m.matrixData[5] - t3 * m.matrixData[8] + t4 * m.matrixData[5] + t5 * m.matrixData[7] - t6 * m.matrixData[4]);

    			//make sure the det is non-zero
    			if (det==0.0) return;

    			float invd = 1.0f / det;

    			float m0 = (m.matrixData[4] * m.matrixData[8] - m.matrixData[7] * m.matrixData[5]) * invd;
    			
				float m3 = -(m.matrixData[3] * m.matrixData[8] - m.matrixData[6] * m.matrixData[5]) * invd;

    			float m6 = (m.matrixData[3] * m.matrixData[7] - m.matrixData[6] * m.matrixData[4]) * invd;

    			float m1 = -(m.matrixData[1] * m.matrixData[8] - m.matrixData[7] * m.matrixData[2]) * invd;

    			float m4 = (m.matrixData[0] * m.matrixData[8] - t6) * invd;

    			float m7 = -(t2 - t4) * invd;

    			float m2 = (m.matrixData[1] * m.matrixData[5] - m.matrixData[4] * m.matrixData[2]) * invd;

    			float m5= -(m.matrixData[0] * m.matrixData[5] - t5) * invd;

    			float m8= (t1 - t3) * invd;

    			matrixData[0]=m0;
    			matrixData[3]=m3;
    			matrixData[6]=m6;

    			matrixData[1]=m1;
    			matrixData[4]=m4;
    			matrixData[7]=m7;

    			matrixData[2]=m2;
    			matrixData[5]=m5;
    			matrixData[8]=m8;
		}
		
		//get the inverse of matrix
		Matrix3n Matrix3n::getInverseofMatrix()const{
				Matrix3n m;
				m.setAsInverseMatrix(*this);
				return m;
		}
		
		//invert matrix
		void Matrix3n::invertMatrix(){
				setAsInverseMatrix(*this);
		}
		
		//set matrix as transpose of a given matrix
		void Matrix3n::setMatrixAsTransposeMatrix(const Matrix3n& m){
				matrixData[0] = m.matrixData[0];
    			matrixData[3] = m.matrixData[1];
    			matrixData[6] = m.matrixData[2];

    			matrixData[1] = m.matrixData[3];
    			matrixData[4] = m.matrixData[4];
    			matrixData[7] = m.matrixData[5];

    			matrixData[2] = m.matrixData[6];
    			matrixData[5] = m.matrixData[7];
    			matrixData[8] = m.matrixData[8];
		}
		
		//get transpose of matrix
		Matrix3n Matrix3n::getTranspose()const{
				Matrix3n m;
				m.setMatrixAsTransposeMatrix(*this);
				return m;
		}
		
		//matrix vector transformation
		Vector3n Matrix3n::operator*(const Vector3n& vect)const{
				return Vector3n(matrixData[0] * vect.x + matrixData[3] * vect.y + matrixData[6] * vect.z,
								matrixData[1] * vect.x + matrixData[4] * vect.y + matrixData[7] * vect.z,
								matrixData[2] * vect.x + matrixData[5] * vect.y + matrixData[8] * vect.z);
		}
		
		//matrix vector transformation
		Vector3n Matrix3n::transformVector(const Vector3n& vect)const{
				return (*this) * vect;
		}
		
}








