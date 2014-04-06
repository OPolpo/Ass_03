#ifndef PRINT_H
	#define PRINT_H

	#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
	#else
	#include <GL/glut.h>
	#endif

	#include <math.h>
	#include <SDL.h>
	#include <SDL_image.h>
	#include "input.h"

	
	void drawScene();
	HalfLifeCrowbar();
	printHouse(int center_x, int center_y, int base_min, int base_max, int height);
	void printSwimmingPool(int center_x, int center_y, int base_min, int base_max);
	void printGround(int center_x, int center_y, int base_min, int base_max, GLuint texture);
	void printFence(int start_x, int start_y, int end_x, int end_y);
	void printHedge(int length, int width, int height);
	void printGate(int start_x, int start_y, int end_x, int end_y);
	void printTree(int x, int y, int h, int type);
	void printGrass();
	void underTheDome();

#endif