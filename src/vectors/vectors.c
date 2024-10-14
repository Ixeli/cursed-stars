#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "../config.h"

ScreenPos perspMap(Vector3 pt, ScreenPos limit) {

	Vector2 projPos; // Position of point on imaginary 2D camera plane
	ScreenPos finalPos; // Position of point on actual character buffer

	Vector3 offset = pt; // Position of point relative to camera

	if (offset.x <= 0) { // Make sure the point isn't *behind* the camera
		return (ScreenPos) {-1, -1};
	}

	// Project onto camera plane
	projPos.x = offset.y / offset.x;
	projPos.y = offset.z / offset.x;

	// Convert coordinate system to screen coordinates
	finalPos.x = (int) (limit.x * (projPos.x + 1) / 2);
	finalPos.y = (int) ((-limit.x * projPos.y + limit.y) / 2);

	// Make sure the point is actually on the screen
	if (finalPos.x < 0 || finalPos.x >= limit.x || finalPos.y < 0 || finalPos.y >= limit.y) return (ScreenPos) {-1, -1};

	return finalPos;
}

Vector2 vector2Add(Vector2 a, Vector2 b) {

	return (Vector2) {
		a.x + b.x,
		a.y + b.y
	};
}

Vector3 vector3Add(Vector3 a, Vector3 b) {

	return (Vector3) {
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	};
}

Vector2 vector2Multiply(Vector2 a, double s) {

	return (Vector2) {
		a.x * s,
		a.y * s
	};
}

Vector3 vector3Multiply(Vector3 a, double s) {

	return (Vector3) {
		a.x * s,
		a.y * s,
		a.z * s
	};
}
