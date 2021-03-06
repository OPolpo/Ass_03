#ifndef INPUT_H
	#define INPUT_H
	#include <stdlib.h>
	#include <math.h>
	#ifdef __APPLE__
		#include <OpenGL/gl.h>
		#include <OpenGL/glu.h>
		#include <GLUT/glut.h>
	#else
		#include <GL/glut.h>
	#endif
	
	#include "printing_functions.h"

	extern double eye[3];
	extern double eye_ed[3];
	
	extern double viewAngle_horizontal;
	extern double viewAngle_vertical;
	
	#define MOVEMENT_COEFFICIENT 0.5
	
	extern int window_h;
	extern int window_w;
	
	void myKeyboardFunc( unsigned char key, int x, int y );
	
	void mySpecialKeyFunc( int key, int x, int y );
	
	void mouseMovement(int _x, int _y);
	
	void locateCamera();

#endif