/**
 * @file planets.c
 * @author Andrea Bocchese
 * @date 31 Mar 2014
 * @brief draw planets and other stuff
 *
 * In this file there are the function the print all the object present in the map
 */

#include "printing_functions.h"

int HALF=0;

SDL_Surface* sdlimage;

static GLuint texGrass1;
static GLuint texGrass2;
static GLuint texTree0;
static GLuint texTree1;
static GLuint texTree2;
static GLuint texTree3;
static GLuint texCrowBar;

static GLuint texBuild;
static GLuint texParquet;
static GLuint texDoor;
static GLuint texRoof;
static GLuint texGround3;
static GLuint texSchermatura;

static GLuint texSwim;
static GLuint texFence;
static GLuint texHedge;
static GLuint texGate;
static GLuint texStoneGround;
static GLuint texPath;
static GLuint texSky;


const GLfloat light_0_col[] = {100.0, 100.0, 100.0};
const GLfloat light_pos[] = {-80.0, 48.0, -45.0, 1};


void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	HalfLifeCrowbar();

	gluLookAt (eye[0], eye[1], eye[2], eye_ed[0], eye_ed[1], eye_ed[2], 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_EMISSION, light_0_col);
	

	// glPushMatrix();
	// glTranslatef(light_pos[0],light_pos[1],light_pos[2]); //to see where the light is
	// glutSolidSphere(0.1,10,10); 

	
	//the 2 big tree in front of the house
	printTree(20,-20,12,0);
	printTree(-20,-20,12,0);

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
	//printTree(-15,-19,3,3);
	printTree(24,30,5,0);
	printTree(-21,27,6,2);
	printTree(19,22,7,0);
	//printTree(8,-17,8,2);
	printTree(50,40,7,0);
	printTree(-50,15,10,1);
	printTree(-50,10,8,2);
	printTree(-50,-19,3,3);
	printTree(50,30,5,0);
	printTree(-55,25,6,2);
	printTree(55,30,7,0);
	printTree(54,-30,8,2);

	//near the swimming pool
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

	//ground near the swimmingpool
	glPushMatrix();
		glTranslatef(0,0.002,0);
		printGround(0,25,14,22,texStoneGround);
	glPopMatrix();



	printTree(-5,-10,3,3);
	printTree(5,-10,3,3);
	printTree(-5,-20,3,3);
	printTree(5,-20,3,3);

	//the path from gate to the door
	glPushMatrix();
		glTranslatef(0,0.002,0);
		printGround(0,-19,24,7,texPath);
	glPopMatrix();

	
	printFence(-30,-30,-30,40);
	printFence(-30,40,30,40);
	printFence(30,40,30,-30);
	
	printFence(30,-30,5,-30);
	printFence(-5,-30,-30,-30);
	printGate(-5,-30,5,-30);

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


	underTheDome();
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

		glPushMatrix();
			glTranslatef(0,0.002,0);
			printGround(center_x, center_y, base_min, base_max, texParquet);
		glPopMatrix();

		glPushMatrix();
			int base_patio_min=base_min;
			int base_patio_max=base_max/2;
			glTranslatef(-base_max/2-base_patio_max/2,0.002,0);
			printGround(center_x, center_y, base_patio_min, base_patio_max, texGround3);

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
	createTexture(&texGrass1,"./texture/grass.jpg");
	createTexture(&texGrass2,"./texture/grass2.jpg");
	createTexture(&texTree0,"./texture/tree0.png");
	createTexture(&texTree1,"./texture/tree1.png");
	createTexture(&texTree2,"./texture/tree2.png");
	createTexture(&texTree3,"./texture/tree3.png");
	createTexture(&texCrowBar,"./texture/crowbar2.png");

	//house section
	createTexture(&texBuild,"./texture/build.jpg");
	createTexture(&texParquet,"./texture/parquet.jpg");
	createTexture(&texDoor,"./texture/door.png");
	createTexture(&texRoof,"./texture/roof.jpg");
	createTexture(&texGround3,"./texture/ground3.jpg");
	createTexture(&texSchermatura,"./texture/schermatura.png");


	createTexture(&texSwim,"./texture/water.jpg");
	createTexture(&texFence,"./texture/fence.png");
	createTexture(&texHedge,"./texture/hedge.jpg");
	createTexture(&texGate,"./texture/gate.png");
	createTexture(&texStoneGround,"./texture/stoneground.jpg");
	createTexture(&texPath,"./texture/path.jpg");

	createTexture(&texSky,"./texture/sky2.jpg");
}


void drawString (void * font, char *s, float x, float y, float z){
     unsigned int i;
     glRasterPos3f(x, y, z);
     glColor3f( 1, 1, 1 );
     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
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

