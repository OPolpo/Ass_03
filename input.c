#include "input.h"

double eye_distance=30;
double eye_inc=0;


void myKeyboardFunc(unsigned char key, int x, int y){
	switch ( key ) {
	case '1':
		if(enableHalf()==0)
			disableHalf();
		break;
	case 'w':
		eye[0]+=-sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[2]+=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		locateCamera();
		break;
	case 's':
		eye[0]-=-sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[2]-=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		locateCamera();
		break;
	case 'a':
		eye[2]+=sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[0]+=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		locateCamera();
		break;
	case 'd':
		eye[2]-=sin(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		eye[0]-=cos(viewAngle_horizontal)*MOVEMENT_COEFFICIENT;
		locateCamera();
		break;
	case 'c':
		eye[1]-=MOVEMENT_COEFFICIENT;
		locateCamera();
		break;
	case 'v':
		eye[1]+=MOVEMENT_COEFFICIENT;
		locateCamera();
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
	eye_ed[1]=eye[1]-sin(viewAngle_vertical)*eye_distance;
	eye_ed[0]=eye[0]-sin(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
	eye_ed[2]=eye[2]+cos(viewAngle_horizontal)*(eye_distance-(1-cos(viewAngle_vertical))*eye_distance);
}

void mouseMovement(int _x, int _y) {
	//printf("moving\n");
 	viewAngle_horizontal+=(_x-window_h/2)*0.0003;
 	viewAngle_vertical+=(_y-window_h/2)*0.0003;
 	
 	if(viewAngle_vertical>1.5)//otherwise you can be damage your neck
 		viewAngle_vertical=1.5;
 	if(viewAngle_vertical<-1.5)//otherwise you can be damage your neck
 		viewAngle_vertical=-1.5;

 	CGSetLocalEventsSuppressionInterval(0.0);
 	glutWarpPointer(window_h/2,window_w/2);
 	glutPostRedisplay();
}

void mySpecialKeyFunc( int key, int x, int y ){
	switch (key) {
	case GLUT_KEY_UP:
		if(viewAngle_vertical>-1.5)// everybody know that PI/2 is 1.5 :D
			viewAngle_vertical-=0.03;
		locateCamera();	
	break;
	case GLUT_KEY_DOWN:
		if(viewAngle_vertical<1.5)// everybody know that PI/2 is 1.5 :D
		viewAngle_vertical+=0.03;
		locateCamera();
	break;
	case GLUT_KEY_LEFT:
		viewAngle_horizontal+=0.03;
		locateCamera();
	break;
	case GLUT_KEY_RIGHT:
		viewAngle_horizontal-=0.03;
		locateCamera();
	break;
	}
	glutPostRedisplay();
}

