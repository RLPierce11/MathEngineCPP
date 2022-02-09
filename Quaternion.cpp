#include <iostream>
#include "Quaternion.h"
#include <cmath>

namespace MathEngine{
	
		//empty constructor
		Quaternion::Quaternion(){
			s= 0;
		}
		//constructor
		Quaternion::Quaternion(float us, Vector3n vect):s(us), vector(vect){}
		//destructor
		Quaternion::~Quaternion(){}
			
		//copy constructor
		Quaternion::Quaternion(const Quaternion& q){
			s = q.s;
			vector = q.vector;
		}
		//copy constructor overload operator =
		Quaternion& Quaternion::operator=(const Quaternion& q){
			s = q.s;
			vector = q.vector;
			return *this;
		}
		
		//print quaternion
		void Quaternion::show(){
			std::cout << "[" << s << ", " << vector.x << ", " << vector.y << ", " << vector.z << "]\n"; 
		}
		
		//overload operator +=
		void Quaternion::operator+=(const Quaternion& q){
			s += q.s;
			vector += q.vector;
		}
		//overload operater +
		Quaternion Quaternion::operator+(const Quaternion& q)const{
			float scaler = s + q.s;
			Vector3n imaginary = vector + q.vector;
			return Quaternion(scaler, imaginary);
		}
		
		//overload operator -=
		void Quaternion::operator-=(const Quaternion& q){
			s -= q.s;
			vector -= q.vector;
		}
		//overload operater -
		Quaternion Quaternion::operator-(const Quaternion& q)const{
			float scaler = s - q.s;
			Vector3n imaginary = vector - q.vector;
			return Quaternion(scaler, imaginary);
		}
		
		//multiply Quaternions
		Quaternion Quaternion::multiply(const Quaternion& q)const{
			float scaler = s * q.s - vector.dot(q.vector);
			Vector3n imaginary = q.vector * s + vector * q.s + vector.cross(q.vector);
			return Quaternion(scaler, imaginary);
		}
		//overload operator *=
		void Quaternion::operator*=(const Quaternion& q){
			(*this) = multiply(q);
		}
		//overload operater *
		Quaternion Quaternion::operator*(const Quaternion& q)const{
			float scaler = s * q.s - vector.dot(q.vector);
			Vector3n imaginary = q.vector * s + vector * q.s + vector.cross(q.vector);
			return Quaternion(scaler, imaginary);
		}
		
		//scalar multiplication overload operator *=
		void Quaternion::operator*=(const float us){
			s *= us;
			vector *= us;
		}
		//scaler multiplication overlaod operator *
		Quaternion Quaternion::operator*(const float us)const{
			float scaler = s * us;
			Vector3n imaginary = vector * us;
			return Quaternion(scaler, imaginary);
		}
		
		//norm of quaternion
		float Quaternion::norm(){
			float scaler = s * s;
			float imaginary = vector * vector;
			return std::sqrt(scaler + imaginary); 
		}
		
		//normalize
		void Quaternion::normalize(){
			if(norm() != 0){
				float normValue = 1 / norm();
				
				s *= normValue;
				vector *= normValue;
			}
		}
		
		//convert to unit norm quaternion
		void Quaternion::convertToUnitNorm(){
			float angle = s * (M_PI / 180.0);
			vector.normalize();
			s = cosf(angle * 0.5);
			vector = vector * sinf(angle * 0.5);
		}
		
		//conjugate
		Quaternion Quaternion::conjugate(){
			float scaler = s;
			Vector3n imaginary = vector * (-1);
			return Quaternion(scaler, imaginary);
		}
		
		//inverse of quaternion
		Quaternion Quaternion::inverse(){
			float absoluteValue = norm();
			absoluteValue *= absoluteValue;
			absoluteValue = 1 / absoluteValue;
			
			Quaternion conjugateValue = conjugate();
			
			float scaler = conjugateValue.s * absoluteValue;
			Vector3n imaginary = conjugateValue.vector * absoluteValue;
			
			return Quaternion(scaler, imaginary);
		}
		
		
	
}
