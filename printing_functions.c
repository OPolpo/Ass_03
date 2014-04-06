/**
 * @file printing_functions.c
 * @author Andrea Bocchese
 * @date 31 Mar 2014
 * @brief draw house and other stuff
 *
 * In this file there are the function the print all the object present in the map
 */

#include "printing_functions.h"

int HALF=0;//just an inutility variable to enable on screen crowbar

SDL_Surface* sdlimage;

//nature
static GLuint texGrass1;
static GLuint texGrass2;
static GLuint texTree0;
static GLuint texTree1;
static GLuint texTree2;
static GLuint texTree3;//bush

//house stuff
static GLuint texBuild;
static GLuint texParquet;
static GLuint texDoor;
static GLuint texRoof;
static GLuint texGround3;
static GLuint texSchermatura;

//external house stuff
static GLuint texSwim;
static GLuint texFence;
static GLuint texHedge;
static GLuint texGate;
static GLuint texStoneGround;
static GLuint texPath;
static GLuint texSky;

//inutility
static GLuint texCrowBar;

const GLfloat light_0_col[] = {100.0, 100.0, 100.0};
const GLfloat light_pos[] = {-80.0, 48.0, -45.0, 1};


void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	HalfLifeCrowbar();//this pront crowbar (only if HALF is != 0)

	gluLookAt (eye[0], eye[1], eye[2], eye_ed[0], eye_ed[1], eye_ed[2], 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_EMISSION, light_0_col);
	
	// //this print a little sphere to localize the sun (now is outside the dome)
	// glPushMatrix();
	// glTranslatef(light_pos[0],light_pos[1],light_pos[2]); //to see where the light is
	// glutSolidSphere(0.1,10,10); 
	// glPopMatrix();
	
	//the 2 big tree in front of the house
	printTree(20,-20,12,0);
	printTree(-20,-20,12,0);


	//randome tree in the world
	printTree(-30,45,10,1);
	printTree(-20,33,8,2);
	printTree(-10,-49,3,3);
	printTree(30,60,5,0);
	printTree(-25,75,6,2);
	printTree(35,30,7,0);
	printTree(14,-60,8,2);
	printTree(13,-40,7,0);
	printTree(-14,54,10,1);
	printTree(-20,19,8,2);
	printTree(24,30,5,0);
	printTree(-21,27,6,2);
	printTree(19,22,7,0);
	printTree(50,40,7,0);
	printTree(-50,15,10,1);
	printTree(-50,10,8,2);
	printTree(-50,-19,3,3);
	printTree(50,30,5,0);
	printTree(-55,25,6,2);
	printTree(55,30,7,0);
	printTree(54,-30,8,2);
	printTree(-70,69,8,2);
	printTree(94,80,5,0);
	printTree(-71,87,6,2);
	printTree(69,72,7,0);
	printTree(-59,-80,7,0);
	printTree(-60,-65,10,1);
	printTree(60,-70,8,2);
	printTree(50,-89,3,3);
	printTree(57,-60,5,0);
	printTree(-65,25,6,2);
	printTree(-55,80,7,0);
	printTree(-54,-70,8,2);

	//bush near the swimming pool
	printTree(-10,17,3,3);
	printTree(10,17,3,3);
	printTree(-10,33,3,3);
	printTree(10,33,3,3);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	

	printHouse(0,0,15,25,8);
	//new grass near the house
	glPushMatrix();
		glTranslatef(0,0.001,0);
		printGround(0,5,70,60,texGrass2);
	glPopMatrix();
	//swimming pool
	glPushMatrix();
		glTranslatef(0,0.003,0);
		printGround(0,25,12,20,texSwim);
	glPopMatrix();
	//ground under the swimmingpool
	glPushMatrix();
		glTranslatef(0,0.002,0);
		printGround(0,25,14,22,texStoneGround);
	glPopMatrix();


	//bush near the path
	printTree(-5,-10,3,3);
	printTree(5,-10,3,3);
	printTree(-5,-20,3,3);
	printTree(5,-20,3,3);
	//the path from gate to the door
	glPushMatrix();
		glTranslatef(0,0.002,0);
		printGround(0,-19,24,7,texPath);
	glPopMatrix();

	//fence	
	printFence(-30,-30,-30,40);
	printFence(-30,40,30,40);
	printFence(30,40,30,-30);
	
	//front fence and gate
	printFence(30,-30,5,-30);
	printFence(-5,-30,-30,-30);
	printGate(-5,-30,5,-30);


	//hedge
	glPushMatrix();
		glTranslatef(0,0,38);
		printHedge(59,2,5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(28,0,5);
		glRotatef(90,0,1,0);
		printHedge(69,2,5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-28,0,5);
		glRotatef(90,0,1,0);
		printHedge(69,2,5);
	glPopMatrix();


	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);


	underTheDome();// print the sky
	printGrass();
	

    glFlush();
    glutSwapBuffers();
    locateCamera();
}



/**
 * @brief Print Grass.
 * This function print Grass.
 */
void printGrass(){
		glEnable(GL_TEXTURE_2D);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, light_0_col);
		glBindTexture(GL_TEXTURE_2D, texGrass1);
		glPushMatrix();
			glBegin(GL_QUADS);
				glNormal3f(0,1,0);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-100.0, 0.0, -100.0);
				glTexCoord2f(0.0, 10.0); 
				glVertex3f(-100.0, 0.0, 100.0);
				glTexCoord2f(10.0, 10.0); 
				glVertex3f(100.0, 0.0, 100.0);
				glTexCoord2f(10.0, 0.0); 
				glVertex3f(100.0, 0.0, -100.0);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
}
/**
 * @brief Print custom tree.
 * This function print a tree.
 */
void printTree(int x, int y, int h, int type){
		glEnable(GL_TEXTURE_2D);
		switch(type){
			case 0:
				glBindTexture(GL_TEXTURE_2D, texTree0);
			break;
			case 1:
				glBindTexture(GL_TEXTURE_2D, texTree1);
			break;
			case 2:
				glBindTexture(GL_TEXTURE_2D, texTree2);
			break;
			case 3:
				glBindTexture(GL_TEXTURE_2D, texTree3);
			break;
		}
		int i=0;
		int layer=4;
		for(i=0;i<layer;i++){
			glPushMatrix();
				glTranslatef(x,h,y);
				glRotatef(360/(2*layer)*i,0,1,0);
				glRotatef(-180, 1, 0, 0);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0); 
					glVertex3f(-h*0.6, 0.0, 0.0);
					glTexCoord2f(0.0, 1.0); 
					glVertex3f(-h*0.6, h, 0.0);
					glTexCoord2f(1.0, 1.0); 
					glVertex3f(h*0.6, h, 0.0);
					glTexCoord2f(1.0, 0.0); 
					glVertex3f(h*0.6, 0.0, 0.0);
				glEnd();
			glPopMatrix();
		}
		glDisable(GL_TEXTURE_2D);
}

/**
 * @brief Print an House.
 * This function print a very very very beautifull house whit a patio and parquet inner pavment.
 * @param center_x x coordinate of the center of the house (x of the projection).
 * @param center_y y coordinate of the center of the house (z of the projection).
 * @param base_min length of the base z axis (max and min non have much sense).
 * @param base_max length of the base x axis (max and min non have much sense).
 * @param height height of the house.
 */
printHouse(int center_x, int center_y, int base_min, int base_max, int height){
		glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_SPECULAR, light_0_col);
		
		int i=0;
		int top=height+3;
		glPushMatrix();
			glTranslatef(center_x,0,center_y);

			//long sides
			glBindTexture(GL_TEXTURE_2D, texBuild);
			glBegin(GL_QUADS);
				glNormal3f(0,0,-1);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-base_max/2, 0.0, base_min/2);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(-base_max/2, height, base_min/2);
				glTexCoord2f(10.0, 2.0); 
				glVertex3f(base_max/2, height, base_min/2);
				glTexCoord2f(10.0, 0.0); 
				glVertex3f(base_max/2, 0.0, base_min/2);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, texRoof);
			glBegin(GL_TRIANGLES);
				glNormal3f(0,top-height,-base_min/2);
				glTexCoord2f(0.0, 1.2); 
				glVertex3f(-base_max/2, height, base_min/2);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(0, top, 0);
				glTexCoord2f(2.0, 1.2); 
				glVertex3f(base_max/2, height, base_min/2);
			glEnd();

			
			glBindTexture(GL_TEXTURE_2D, texBuild);
			glBegin(GL_QUADS);
				glNormal3f(0,0,-1);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-base_max/2, 0.0, -base_min/2);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(-base_max/2, height, -base_min/2);
				glTexCoord2f(10.0, 2.0); 
				glVertex3f(base_max/2, height, -base_min/2);
				glTexCoord2f(10.0, 0.0); 
				glVertex3f(base_max/2, 0.0, -base_min/2);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, texRoof);
			glBegin(GL_TRIANGLES);
				glNormal3f(0,top-height,-base_min/2);
				glTexCoord2f(0.0, 1.2); 
				glVertex3f(-base_max/2, height, -base_min/2);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(0, top, 0);
				glTexCoord2f(2.0, 1.2); 
				glVertex3f(base_max/2, height, -base_min/2);
			glEnd();

			//short sides
			glBindTexture(GL_TEXTURE_2D, texBuild);
			glBegin(GL_QUADS);
				glNormal3f(1,0,0);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(base_max/2, 0.0, -base_min/2);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(base_max/2, height, -base_min/2);
				glTexCoord2f(10.0, 2.0); 
				glVertex3f(base_max/2, height, base_min/2);
				glTexCoord2f(10.0, 0.0); 
				glVertex3f(base_max/2, 0.0, base_min/2);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, texRoof);
			glBegin(GL_TRIANGLES);
				glNormal3f(base_max/2,top-height,0);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(base_max/2, height, -base_min/2);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(0, top, 0);
				glTexCoord2f(2.0, 2.0); 
				glVertex3f(base_max/2, height, base_min/2);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, texBuild);
			glBegin(GL_QUADS);
				glNormal3f(1,0,0);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-base_max/2, 0.0, -base_min/2);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(-base_max/2, height, -base_min/2);
				glTexCoord2f(10.0, 2.0); 
				glVertex3f(-base_max/2, height, base_min/2);
				glTexCoord2f(10.0, 0.0); 
				glVertex3f(-base_max/2, 0.0, base_min/2);
			glEnd();
			glBindTexture(GL_TEXTURE_2D, texRoof);
			glBegin(GL_TRIANGLES);
				glNormal3f(base_max/2,top-height,0);
				glTexCoord2f(0.0, 2.0); 
				glVertex3f(-base_max/2, height, -base_min/2);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(0, top, 0);
				glTexCoord2f(2.0, 2.0); 
				glVertex3f(-base_max/2, height, base_min/2);
			glEnd();

			//Door
			glBindTexture(GL_TEXTURE_2D, texDoor);
			glBegin(GL_QUADS);
				glNormal3f(0,0,-1);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-2, 0.0, -base_min/2-0.01);
				glTexCoord2f(0.0, 1.0); 
				glVertex3f(-2, 5, -base_min/2-0.01);
				glTexCoord2f(1.0, 1.0); 
				glVertex3f(2, 5, -base_min/2-0.01);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(2, 0.0, -base_min/2-0.01);
			glEnd();

			//parquet (inner)
			glPushMatrix();
				glTranslatef(0,0.002,0);
				printGround(center_x, center_y, base_min, base_max, texParquet);
			glPopMatrix();
			
			//patio
			glPushMatrix();
				//patio ground
				int base_patio_min=base_min;
				int base_patio_max=base_max/2;
				glTranslatef(-base_max/2-base_patio_max/2,0.002,0);
				printGround(center_x, center_y, base_patio_min, base_patio_max, texGround3);
				//patio wood wall
				glBindTexture(GL_TEXTURE_2D, texSchermatura);
				glBegin(GL_QUADS);
					glNormal3f(1,0,0);
					glTexCoord2f(0, base_patio_min/6); 
					glVertex3f(center_x-base_patio_max/2, 0.0, center_y-base_patio_min/2);
					glTexCoord2f(1.0, base_patio_min/6); 
					glVertex3f(center_x-base_patio_max/2, 5, center_y-base_patio_min/2);
					glTexCoord2f(1.0, 0.0); 
					glVertex3f(center_x+base_patio_max/2, 5, center_y-base_patio_min/2);
					glTexCoord2f(0.0, 0.0); 
					glVertex3f(center_x+base_patio_max/2, 0.0, center_y-base_patio_min/2);
				glEnd();
			glPopMatrix();
		glPopMatrix();	
}


/**
 * @brief Print a generic horizontal surface.
 * This function print a rectangular surface.
 * @param center_x x coordinate of the center of the surface (x of the projection).
 * @param center_y y coordinate of the center of the surface (z of the projection).
 * @param base_min length of the base z axis (max and min non have much sense).
 * @param base_max length of the base x axis (max and min non have much sense).
 * @param texture index of the texture binded to the surfcace.
 */
void printGround(int center_x, int center_y, int base_min, int base_max, GLuint texture){
		glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_SPECULAR, light_0_col);
		glPushMatrix();
			glTranslatef(center_x,0,center_y);//i know it's very ugly bidimensional swimmingpool
			glBindTexture(GL_TEXTURE_2D, texture);
			glBegin(GL_QUADS);
				glNormal3f(0,1,0);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-base_max/2, 0.0, -base_min/2);
				glTexCoord2f(0.0, 1.0); 
				glVertex3f(-base_max/2, 0, base_min/2);
				glTexCoord2f(1.0, 1.0); 
				glVertex3f(base_max/2, 0, base_min/2);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(base_max/2, 0.0, -base_min/2);
			glEnd();
		glPopMatrix();	

}


/**
 * @brief Print a fence.
 * This function print a fence.
 * @param start_x x coordinate of the start.
 * @param starty_ y coordinate of the start (z of the projection).
 * @param end_x x coordinate of the end.
 * @param end_ y coordinate of the end (z of the projection).
 */
void printFence(int start_x, int start_y, int end_x, int end_y){
	glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_SPECULAR, light_0_col);
		int length=sqrt(pow(start_x-end_x,2)+pow(start_y-end_y,2));
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texFence);
			glBegin(GL_QUADS);
				//glNormal3f(0,1,0);
				glTexCoord2f(0.0, 1.0); 
				glVertex3f(start_x, 0.0, start_y);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(start_x, 3, start_y);
				glTexCoord2f(length/3, 0.0); 
				glVertex3f(end_x, 3, end_y);
				glTexCoord2f(length/3, 1.0); 
				glVertex3f(end_x, 0.0, end_y);
			glEnd();
		glPopMatrix();	
}

/**
 * @brief Print an Hedge.
 * This function print an hedge centered in 0,0.
 * @param lenght length of the hedge on x axis.
 * @param width width of the hedge on z axis.
 * @param height height of the hedge on y axis.
 */
void printHedge(int length, int width, int height){
	glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_SPECULAR, light_0_col);
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texHedge);
			glBegin(GL_QUADS);//back
				glNormal3f(0,0,-1);
				glTexCoord2f(0.0, length/10); 
				glVertex3f(-length/2, 0.0, width/2);
				glTexCoord2f(height/5, length/10); 
				glVertex3f(-length/2, height, width/2);
				glTexCoord2f(height/5, 0.0); 
				glVertex3f(length/2, height, width/2);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(length/2, 0.0, width/2);
			glEnd();
			glBegin(GL_QUADS);//front
				glNormal3f(0,0,-1);
				glTexCoord2f(0.0, length/10); 
				glVertex3f(-length/2, 0.0, -width/2);
				glTexCoord2f(height/5, length/10); 
				glVertex3f(-length/2, height, -width/2);
				glTexCoord2f(height/5, 0.0); 
				glVertex3f(length/2, height, -width/2);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(length/2, 0.0, -width/2);
			glEnd();
			glBegin(GL_QUADS);//top
				glNormal3f(0,-1,0);
				glTexCoord2f(0.0, length/10); 
				glVertex3f(-length/2, height, width/2);
				glTexCoord2f(width/2, length/10); 
				glVertex3f(-length/2, height, -width/2);
				glTexCoord2f(width/2, 0.0);
				glVertex3f(length/2, height, -width/2);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(length/2, height, width/2);
			glEnd();
			glBegin(GL_QUADS);//side
				glNormal3f(1,0,0);
				glTexCoord2f(0.0, width/2); 
				glVertex3f(-length/2, 0.0, -width/2);
				glTexCoord2f(height/5, width/2); 
				glVertex3f(-length/2, height, -width/2);
				glTexCoord2f(height/5, 0.0); 
				glVertex3f(-length/2, height, +width/2);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-length/2, 0.0, +width/2);
			glEnd();
			glBegin(GL_QUADS);//side
				glNormal3f(1,0,0);
				glTexCoord2f(0.0, width/2); 
				glVertex3f(length/2, 0.0, -width/2);
				glTexCoord2f(height/5, width/2); 
				glVertex3f(length/2, height, -width/2);
				glTexCoord2f(height/5, 0.0); 
				glVertex3f(length/2, height, +width/2);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(length/2, 0.0, +width/2);
			glEnd();
		glPopMatrix();	
}

/**
 * @brief Print a gate.
 * This function print a gate, like a fence but change the texture and the binding.
 * @param start_x x coordinate of the start.
 * @param starty_ y coordinate of the start (z of the projection).
 * @param end_x x coordinate of the end.
 * @param end_ y coordinate of the end (z of the projection).
 */
void printGate(int start_x, int start_y, int end_x, int end_y){
	glEnable(GL_TEXTURE_2D);
		//glMaterialfv(GL_FRONT, GL_SPECULAR, light_0_col);
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texGate);
			glBegin(GL_QUADS);
				glNormal3f(0,1,0);
				glTexCoord2f(0.0, 1.0); 
				glVertex3f(start_x, 0.0, start_y);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(start_x, 5, start_y);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(end_x, 5, end_y);
				glTexCoord2f(1.0, 1.0); 
				glVertex3f(end_x, 0.0, end_y);
			glEnd();
		glPopMatrix();	
}

/**
 * @brief Print a Dome that actually is a sphere.
 * This function print a sphere whith the texture of a beautifull sky.
 */
void underTheDome(){
	//i'm not a big fan of the series but after breaking bad i start to whatch it.
	glPushAttrib(GL_LIGHTING_BIT);
		GLfloat material_col[] = {1.0, 1.0, 1.0};
		glMaterialfv(GL_FRONT, GL_EMISSION, material_col);
		glPushMatrix();
			GLUquadric *qobj = gluNewQuadric();
			gluQuadricTexture(qobj,GL_TRUE); 
			glRotatef(90, 1, 0, 0);
			glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D,texSky);
				gluSphere(qobj,100,1000,1000); 
				//	drawBox(50, GL_QUADS);
				gluDeleteQuadric(qobj); 
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPopAttrib();

}

/**
 * @brief Print a crowbar.
 * This function print a crowbar taken from half life.
 * In this assingment i don't put any information about the control key.
 * If you want enable this you must press '1'.
 */
HalfLifeCrowbar(){
	if(HALF){
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texCrowBar);
		glPushMatrix();
			glTranslatef(0.4,-0.4,-1.0);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); 
				glVertex3f(-0.2, -0.2, -0.0);
				glTexCoord2f(0.0, 1.0); 
				glVertex3f(-0.2, 0.2, -0.0);
				glTexCoord2f(1.0, 1.0); 
				glVertex3f(0.2, 0.2, 0.0);
				glTexCoord2f(1.0, 0.0); 
				glVertex3f(0.2, -0.2, 0.0);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	}
}


/**
 * @brief Create a texture.
 * This function build the texture from a path of an image.
 * @param text_name this is the address of a GLuint texture index.
 * @param file_path the path of the image file.
 */
void createTexture(GLuint* text_name, char* file_path){
	sdlimage = IMG_Load(file_path);
   	glGenTextures(1, text_name);
   	glBindTexture(GL_TEXTURE_2D, *text_name);
   	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, sdlimage->w, sdlimage->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sdlimage->pixels );
}

/**
 * @brief create all texture needed.
 * This function build all the texture.
 */
void loadTexture(){

	//nature
	createTexture(&texGrass1,"./texture/grass.jpg");
	createTexture(&texGrass2,"./texture/grass2.jpg");
	createTexture(&texTree0,"./texture/tree0.png");
	createTexture(&texTree1,"./texture/tree1.png");
	createTexture(&texTree2,"./texture/tree2.png");
	createTexture(&texTree3,"./texture/tree3.png");

	//house section
	createTexture(&texBuild,"./texture/build.jpg");
	createTexture(&texParquet,"./texture/parquet.jpg");
	createTexture(&texDoor,"./texture/door.png");
	createTexture(&texRoof,"./texture/roof.jpg");
	createTexture(&texGround3,"./texture/ground3.jpg");
	createTexture(&texSchermatura,"./texture/schermatura.png");

	//external house stuff
	createTexture(&texSwim,"./texture/water.jpg");
	createTexture(&texFence,"./texture/fence.png");
	createTexture(&texHedge,"./texture/hedge.jpg");
	createTexture(&texGate,"./texture/gate.png");
	createTexture(&texStoneGround,"./texture/stoneground.jpg");
	createTexture(&texPath,"./texture/path.jpg");

	createTexture(&texSky,"./texture/sky2.jpg");

	//Inutility
	createTexture(&texCrowBar,"./texture/crowbar2.png");
}

int enableHalf(){
	if(HALF){
		HALF=1;
		return 0;
	}
	HALF=1;
	return 1;
}
void disableHalf(){HALF=0;};

