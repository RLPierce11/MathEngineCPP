#include <iostream>
#include "Vector3n.h"
//#include "Matrix3n.h"
//#include "Quaternion.h"


int main(){
	
	MathEngine::Vector3n vect(5, 5, 5);
	
	MathEngine::Vector3n axis(1, 0, 0);
	
	MathEngine::Vector3n newvect = vect.rotateVectorAboutAngleAndAxis(90, axis);
										
	
	newvect.show();
	
	return 0;
}
