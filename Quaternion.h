#include "Vector3n.h"

namespace MathEngine{
	
	class Quaternion{
		private:
			
		public:
			//Quaternion Q[s, vector]
			float s;//scalar
			Vector3n vector;//vector
			
			Quaternion();//empty constructor
			Quaternion(float us, Vector3n vect);//constructor
			~Quaternion();//destructor
			
			Quaternion(const Quaternion& q);//copy constructor
			Quaternion& operator=(const Quaternion& q);//copy constructor overload operator =
			
			void show();//print quaternion
			
			//overload operator +=
			void operator+=(const Quaternion& q);
			//overload operater +
			Quaternion operator+(const Quaternion& q)const;
			
			//overload operator -=
			void operator-=(const Quaternion& q);
			//overload operater -
			Quaternion operator-(const Quaternion& q)const;
			
			//overload operator *=
			void operator*=(const Quaternion& q);
			//overload operater *
			Quaternion operator*(const Quaternion& q)const;
			//multiply Quaternions
			Quaternion multiply(const Quaternion& q)const;
			
			//scalar multiplication overload operator *=
			void operator*=(const float us);
			//scaler multiplication overlaod operator *
			Quaternion operator*(const float us)const;
			
			//norm of quaternion
			float norm();
			
			//normalize
			void normalize();
			
			//convert to unit norm quaternion
			void convertToUnitNorm();
			
			//conjugate
			Quaternion conjugate();
			
			//inverse of quaternion
			Quaternion inverse();
			
			
			
	};
	
}
