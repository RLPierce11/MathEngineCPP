//#include "Vector3n.h"
#include "Quaternion.h"
#include <iostream>
#include <cmath>

namespace MathEngine{
	//empty constructor
	Vector3n::Vector3n():x(0.0), y(0.0), z(0.0){};
	
	//constructor
	Vector3n::Vector3n(float ux, float uy, float uz):x(ux), y(uy), z(uz){};
	
	//destructor
	Vector3n::~Vector3n(){};
	
	//print vector
	void Vector3n::show(){
		std::cout << x << " " << y << " " << z << std::endl;
	}
	
	//copy cnstructor
	Vector3n::Vector3n(const Vector3n& vect):x(vect.x), y(vect.y), z(vect.z){};
	
	//overload operator =
	Vector3n& Vector3n::operator=(const Vector3n& vect){
		x = vect.x;
		y = vect.y;
		z = vect.z;
		
		return *this;
	}
	
	//overload operator +=
	void Vector3n::operator+=(const Vector3n& vect){
			x += vect.x;
			y += vect.y;
			z += vect.z;
	}
	//overload operator +
	Vector3n Vector3n::operator+(const Vector3n& vect)const{
			return Vector3n(x+vect.x, y+vect.y, z+vect.z);
	}
	
	//overload operator -=
	void Vector3n::operator-=(const Vector3n& vect){
			x -= vect.x;
			y -= vect.y;
			z -= vect.z;		
	}
	//overload operator -
	Vector3n Vector3n::operator-(const Vector3n& vect)const{
			return Vector3n(x-vect.x, y-vect.y, z-vect.z);
	}
	
	//overload operator *= for scaler multiplication
	void Vector3n::operator*=(const float s){
			x *= s;
			y *= s;
			z *= s;
	}
	//overload operator * for scaler multiplication
	Vector3n Vector3n::operator*(const float s)const{
			return Vector3n(x*s, y*s, z*s);
	} 
			
	//overload operator /= for scaler division
	void Vector3n::operator/=(const float s){
			x /= s;
			y /= s;
			z /= s;
	}
	//overload operator / for scaler division
	Vector3n Vector3n::operator/(const float s)const{
			return Vector3n(x/s, y/s, z/s);
	}
	
	//dot product overload operator *
	float Vector3n::operator*(const Vector3n& vect)const{
			return x*vect.x+y*vect.y+z*vect.z;
	}
	//dot product function
	float Vector3n::dot(const Vector3n& vect)const{
			return x*vect.x+y*vect.y+z*vect.z;
	}
	
	//cross product function
	Vector3n Vector3n::cross(const Vector3n& vect)const{
			return Vector3n(
							y*vect.z-z*vect.y,
							z*vect.x-x*vect.z,
							x*vect.y-y*vect.x
							);
	}
	//cross product to self overload operator %=
	void Vector3n::operator%=(const Vector3n& vect){
			*this=cross(vect);
	}
	//cross product overlaod operator %
	Vector3n Vector3n::operator%(const Vector3n& vect)const{
			return Vector3n(
							y*vect.z-z*vect.y,
							z*vect.x-x*vect.z,
							x*vect.y-y*vect.x
							);
	}
	
	//magnitude of vector
	float Vector3n::mag(){
		float magnitude = std::sqrt(x*x+y*y+z*z);
		return magnitude;
	}
	
	// normailize a vector
	void Vector3n::normalize(){
		float mag = std::sqrt(x*x+y*y+z*z);
		
		if(mag > 0.0f){
			float oneOverMag = 1.0f / mag;
			
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;
		}
	}
	
	
	
	//Vector rotation by quaternion
		Vector3n Vector3n::rotateVectorAboutAngleAndAxis(float uangle, Vector3n& uaxis){
			
			//convert my vector to a pure quaternion
			Quaternion p(0, (*this));
			
			//normalize the input axis
			uaxis.normalize();
			
			//create the real quaternion
			Quaternion q(uangle, uaxis);
			
			//convert the real quaternion to unit norm quaternion
			q.convertToUnitNorm();
			
			//get the inverse of that quaternion
			Quaternion qInverse = q.inverse();
			
			//rotate the quaternion
			Quaternion rotatedVector = q * p * qInverse;
			
			return rotatedVector.vector;
		}
	
}









