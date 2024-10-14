// Types and functions for working with vectors and screen coordinates

#ifndef VECTOR_GUARD

#define VECTOR_GUARD

// ================  TYPES ================

// Used for points in 3D space
typedef struct {

	double x;
	double y;
	double z;

} Vector3;

// Used for points in 2D space
typedef struct {

	double x;
	double y;

} Vector2;

// Used for integer points on the screen
typedef struct {
	
	int x;
	int y;

} ScreenPos;

typedef struct {

	Vector2 i;
	Vector2 j;

} Transform;

typedef struct {

	ScreenPos* start;
	ScreenPos* end;

} ScreenBuffer;

// ================ FUNCTIONS ================

double randNorm(); // Returns double in [0, 1)
double floatRandRange(double min, double max); // Returns double in [min, max)
Vector3 vector3RandRange(Vector3 min, Vector3 max); // Returns vector in [min, max)
Vector3* pointArray(Vector3 min, Vector3 max, int n); // Returns a variable-length array of 3D points


ScreenPos perspMap(Vector3 pt, ScreenPos limit); // Maps to screen coordinates

Transform generateTransform(double theta); // Generates a 2D rotation matrix. Don't call this too often, as it makes usage of trig functions.

Vector2 applyTransform2D(Vector2 vec, Transform trans); // Applies a transformation matrix. This can be called as much as you want, it only uses multiplication and addition.

Vector3 applyTransform3D(Vector3 vec, Transform trans); // Ditto, but in 3D. (The rotation is still 2D, it doesn't touch the Z-axis.)

// Add vectors together
Vector2 vector2Add(Vector2 a, Vector2 b);
Vector3 vector3Add(Vector3 a, Vector3 b);

// Multiply vectors by scalars
Vector2 vector2Multiply(Vector2 a, double s);
Vector3 vector3Multiply(Vector3 a, double s);

#endif
