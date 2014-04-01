#include "input.h"
#include "printing_functions.h"



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
		eye_distance-=MOVEMENT_COEFFICIENT*5;
		glutPostRedisplay();
		break;
	case 's':
		eye_distance+=MOVEMENT_COEFFICIENT*5;
		glutPostRedisplay();
		break;
	case 'a':
		viewAngle_horizontal+=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'd':
		viewAngle_horizontal-=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'c':
		viewAngle_vertical-=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 'v':
		viewAngle_vertical+=MOVEMENT_COEFFICIENT;
		glutPostRedisplay();
		break;
	case 27:	// Escape key
		exit(1);
	}
	locateCamera();
}
/**
 * @brief compute the camera position
 * This function set the the eye position (camera) using the angle (horizontal and vertical) and the distance
 */
void locateCamera(){
	eye[2]=-sin(viewAngle_vertical)*eye_distance;
	eye[0]=sin(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
	eye[1]=cos(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
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


// void mouseMovement(int _x, int _y) {
// 	viewAngle_horizontal+=(_x-window_h/2)*0.0003;
// 	viewAngle_vertical+=(_y-window_h/2)*0.0003;

// 	CGSetLocalEventsSuppressionInterval(0.0);
// 	glutWarpPointer(window_h/2,window_w/2);
// 	eye_ed[0]=sin(viewAngle_horizontal)*40;
// 	eye_ed[1]=cos(viewAngle_horizontal)*40;

// 	eye_ed[1]+=(1-cos(viewAngle_vertical))*40;
// 	eye_ed[2]=-sin(viewAngle_vertical)*40;
// 	printf("vert: %f hor: %f\n",viewAngle_vertical,viewAngle_horizontal);
// 	printf("vert: %d hor: %d\n",_x,_y);
// }

