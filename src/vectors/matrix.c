#include <math.h>
#include <stdlib.h>
#include "vectors.h"

Transform generateTransform(double theta) {

	Transform newTrans;

	newTrans.i.x =  cos(theta);
	newTrans.i.y =  sin(theta);

	newTrans.j.x = -sin(theta);
	newTrans.j.y =  cos(theta);

	return newTrans;
}

Vector2 applyTransform2D(Vector2 vec, Transform trans) {

	return (Vector2) {
		trans.i.x*vec.x + trans.j.x*vec.y,
		trans.i.y*vec.x + trans.j.y*vec.y
	};

}

Vector3 applyTransform3D(Vector3 vec, Transform trans) {

	return (Vector3) {
		trans.i.x*vec.x + trans.j.x*vec.y,
		trans.i.y*vec.x + trans.j.y*vec.y,
		vec.z
	};
}


