#include "input.h"
#include "printing_functions.h"

double eye_distance=30;
double eye_inc=0;



void myKeyboardFunc(unsigned char key, int x, int y){
	switch ( key ) {
	case 'r':
		RunMode = 1-RunMode;		// Toggle to opposite value
		if (RunMode==1) {
			glutPostRedisplay();
		}
		break;
	case 't':
		RunMode = 1;
		glutPostRedisplay();
		RunMode = 0;
		break;
	case '1':
		break;
	case '2':
		break;
	case '3':

		break;
	case 'w':
		eye[0]+=sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[1]+=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 's':
		eye[0]-=sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[1]-=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'a':
		eye[1]-=-sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[0]-=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'd':
		eye[1]+=-sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[0]+=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'c':
		eye[2]-=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'v':
		eye[2]+=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 27:	// Escape key
		exit(1);
	}
	glutPostRedisplay();
}
/**
 * @brief compute the camera position
 * This function set the the eye position (camera) using the angle (horizontal and vertical) and the distance
 */
void locateCamera(){
	//printf("%f %f %f\n",eye_ed[0],eye_ed[1],eye_ed[2]);
	eye_ed[2]=eye[2]-sin(viewAngle_vertical)*eye_distance;
	eye_ed[0]=eye[0]+sin(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
	eye_ed[1]=eye[1]+cos(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
}


void mySpecialKeyFunc( int key, int x, int y ){
	switch ( key ) {
	case GLUT_KEY_UP:		
		if ( AnimateStep < 1.0e3) {			// Avoid overflow problems
			AnimateStep *= sqrt(2.0);		// Increase the angle increment
		}
		break;
	case GLUT_KEY_DOWN:
		if (AnimateStep>1.0e-6) {		// Avoid underflow problems.
			AnimateStep /= sqrt(2.0);	// Decrease the angle increment
		}
		break;
	}
}


void mouseMovement(int _x, int _y) {
	//printf("moving\n");
 	viewAngle_horizontal+=(_x-window_h/2)*0.0003;
 	viewAngle_vertical+=(_y-window_h/2)*0.0003;

 	CGSetLocalEventsSuppressionInterval(0.0);
 	glutWarpPointer(window_h/2,window_w/2);
 	glutPostRedisplay();
 	// eye_ed[0]=sin(viewAngle_horizontal)*40;
 	// eye_ed[1]=cos(viewAngle_horizontal)*40;

 	// eye_ed[1]+=(1-cos(viewAngle_vertical))*40;
 	// eye_ed[2]=-sin(viewAngle_vertical)*40;
 	// printf("vert: %f hor: %f\n",viewAngle_vertical,viewAngle_horizontal);
 	// printf("vert: %d hor: %d\n",_x,_y);
}

