#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"
#include "vectors/vectors.h"
#include "draw/draw.h"

int main(int argc, char** argv) {

	int nStars;

	Vector3 camera_pos = {INIT_X, INIT_Y, INIT_Z}; // Position of the camera
	
	double viewAngle = 0; // Rotation of world relative to camera.
	Transform viewMatrix = { // Rotated the wrong way but ssshhh...
		{1, 0},
		{0, 1}
	};

	Transform moveMatrix = { // Seperate matrix for camera movement
		{1, 0},
		{0, 1}
	};

	// Limits of rectangular prism in which stars generate
	Vector3 boundMin = {X_MIN, Y_MIN, Z_MIN};
	Vector3 boundMax = {X_MAX, Y_MAX, Z_MAX};
	
	// Star positions
	Vector3* points;
	Vector3 currentPoint;

	ScreenPos newPos; // Next pixel to draw
	ScreenPos* points2D;
	int pointsCount;

	// Bottom-right corner of screen
	ScreenPos screenLimit;
	
	int k = 0; // Key buffer
	
	if (argc != 2) {
		printf("Invalid argument count!\n");
		return 1;
	}

	sscanf(argv[1], "%d", &nStars);

	points = pointArray(boundMin, boundMax, nStars);
	points2D = malloc(sizeof(ScreenPos)*nStars); // Buffer of screen coordinates

	srand(time(NULL)); // Init PRNG
	
	initCurses(&(screenLimit.x), &(screenLimit.y));
	
	while (k != C_QUIT) {

		k = getKeyLower(); // Get keyboard input

		switch (k) { // Move camera based on keyboard input

			case C_FWD: 
				camera_pos.x += SPD_X * moveMatrix.i.x;
				camera_pos.y += SPD_X * moveMatrix.i.y;
				break;

			case C_BCK:
				camera_pos.x -= SPD_X * moveMatrix.i.x;
				camera_pos.y -= SPD_X * moveMatrix.i.y;
				break;

			case C_LFT:
				viewAngle += SPD_Y;
				break;
			
			case C_RIG:
				viewAngle -= SPD_Y;
				break;

			case C_UP:
				camera_pos.z += SPD_Z;
				break;
			case C_DWN:
				camera_pos.z -= SPD_Z;
				break;
		}

		// Drawing is done in two steps to minimize screen flickering
		
		viewMatrix = generateTransform(viewAngle);
		moveMatrix = generateTransform(-viewAngle);
		pointsCount = 0;

		for (int i=0; i<nStars; i++) { // Calculate positions of stars on screen
			
			currentPoint = points[i];

			currentPoint.x -= camera_pos.x;
			currentPoint.y -= camera_pos.y;
			currentPoint.z -= camera_pos.z;

			currentPoint = applyTransform3D(currentPoint, viewMatrix);

			newPos = perspMap(currentPoint, screenLimit);
			if (newPos.x != -1 && newPos.y != -1) {
				points2D[pointsCount] = newPos;
				pointsCount++;
			}
		}

		clear();

		for (int i=0; i<pointsCount; i++) {

			drawStar(points2D[i].x, points2D[i].y);

		}

#ifdef SHOW_INFO
		mvprintw(0, 0, "x=%f, y=%f, z=%f", camera_pos.x, camera_pos.y, camera_pos.z);
		mvprintw(1, 0, "%f rad", viewAngle);
		mvprintw(2, 0, "%d stars visible", pointsCount);
#endif

	}

	endwin();
	free(points);
	free(points2D);

	return 0;
}
