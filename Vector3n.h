namespace MathEngine{
	
	class Vector3n{
		private:
			
		public:
			
			float x;
			float y;
			float z;
			
			Vector3n();//empty constructor
			Vector3n(float ux, float uy, float uz);//constructor
			~Vector3n();//destructor
			
			void show(); //print Vector3n
			
			Vector3n(const Vector3n& vect);//copy cnstructor
			Vector3n& operator=(const Vector3n& vect);//overload operator =
			
			void operator+=(const Vector3n& vect);//overload operator +=
			Vector3n operator+(const Vector3n& vect)const;//overload operator +
			
			void operator-=(const Vector3n& vect);//overload operator -=
			Vector3n operator-(const Vector3n& vect)const;//overload operator -
			
			void operator*=(const float s);//overload operator *= for scaler multiplication
			Vector3n operator*(const float s)const; //overload operator * for scaler multiplication
			
			void operator/=(const float s);//overload operator /= for scaler diviosion
			Vector3n operator/(const float s)const; //overload operator / for scaler division
			
			float operator*(const Vector3n& vect)const;//dot product overload operator *
			float dot(const Vector3n& vect)const;//dot product function
			
			void operator%=(const Vector3n& vect);//cross product to self overload operator %=
			Vector3n operator%(const Vector3n& vect)const;//cross product overlaod operator %
			Vector3n cross(const Vector3n& vect)const;//cross product function
			
			float mag();//magnitude of vector
			
			void normalize(); // normailize a vector
			
			
			//Vector rotation by quaternion
			Vector3n rotateVectorAboutAngleAndAxis(float uangle, Vector3n& uaxis);
	};
}






