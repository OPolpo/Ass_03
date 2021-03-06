/**
 * @file my_world.c
 * @author Andrea Bocchese
 * @date 31 Mar 2014
 * @brief main file, contain init function and the main.
 *
 * The progrma print a little world whith an house, a patio, a swimming pool (outside the house), some three and other stuff.
 * you can move around the house whith WASD and Mouse or if you want (no one will blame you for this) whit the arrow key.
 *
 */

#include <math.h>		// For math routines (such as sqrt & trig).
#include <stdio.h>
#include <stdlib.h>		// For the "exit" function

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "printing_functions.h"
#include "input.h"

#define SDL_main main //poi qualcuno me la dovrà spiegare sta cosa...


// this to set initial view point
double viewAngle_horizontal=0;//radiant
double viewAngle_vertical=-0.39	;//radiant

double eye[3]={0,2.,-40};
double eye_ed[3]={0,0,0};

const GLfloat material_col[] = {1.0, 1.0, 1.0};


int window_h=720;
int window_w=720;


float AnimationAngle = 0.0f;
float AnimateStep = 0.0001f;


const double Xmin = -10.0, Xmax = 10.0;
const double Ymin = -10.0, Ymax = 10.0;


const GLfloat light_ambient[] = {0.2, 0.2, 0.2};

void initRendering(){

	glutSetCursor(GLUT_CURSOR_NONE); // to pin the mouse at the center of the screen

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	//this stuff is for alpha channel
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable (GL_ALPHA_TEST) ;
	glAlphaFunc(GL_GREATER, 0.0f);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_col);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);
	
	locateCamera();
	loadTexture();

}

void resizeWindow(int w, int h){
	glViewport(0, 0, w, h);
	window_h=h;
	window_w=w;
	
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,w/h,1,200);
	
}


int main( int argc, char** argv ){
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    glutInitWindowPosition(10, 60);
	glutInitWindowSize(window_h, window_h);
  	glutCreateWindow("My little BIG world");

 	initRendering();
	
	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);
	//glutSpecialUpFunc(keySpecialUp); //no time for do this (sorry is pretty unusable without this)
	glutPassiveMotionFunc(mouseMovement);

   	glutReshapeFunc(resizeWindow);
   	glutDisplayFunc(drawScene);
	glutMainLoop();

    return(0);
}