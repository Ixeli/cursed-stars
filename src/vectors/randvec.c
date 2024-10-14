#include <stdlib.h>
#include <stddef.h>
#include "vectors.h"

double randNorm() { 
	return (double) rand() / RAND_MAX;
}

double floatRandRange(double min, double max) {

	double range = max - min;
	return range * randNorm() + min;
}

Vector3 vector3RandRange(Vector3 min, Vector3 max) {
	return (Vector3) {floatRandRange(min.x, max.x), floatRandRange(min.y, max.y), floatRandRange(min.z, max.z)};
}

Vector3* pointArray(Vector3 min, Vector3 max, int n) {

	Vector3* arr = malloc(sizeof(Vector3)*n);

	for (int i=0; i<n; i++) {
		arr[i] = vector3RandRange(min, max);
	}

	return arr;
}
