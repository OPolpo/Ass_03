/**
 * @file planets.c
 * @author Andrea Bocchese
 * @date 31 Mar 2014
 * @brief draw planets and other stuff
 *
 * In this file there are the function the print planet orbit and axis and the menu
 */

#include "printing_functions.h"
#include <SDL.h>
#include <SDL_image.h>

#define PI 3.141592653589793238462643383
int AXIS=0;
int ORBIT=0;
int TARDIS=0;

SDL_Surface* sdlimage;

static GLuint texName1;
static GLuint texName2;
static GLuint texName3;
static GLuint texName4;
static GLuint texName5;




/**
 * @brief Print Grass.
 * This function print Grass.
 */
void printGrass(){
	glPushAttrib(GL_LIGHTING_BIT);
		GLfloat material_col[] = {1.0, 1.0, 1.0};
		glMaterialfv(GL_FRONT, GL_EMISSION, material_col);



	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texName1);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); 
			glVertex3f(-50.0, -50.0, 0.0);
			glTexCoord2f(0.0, 10.0); 
			glVertex3f(-50.0, 50.0, 0.0);
			glTexCoord2f(10.0, 10.0); 
			glVertex3f(50.0, 50.0, 0.0);
			glTexCoord2f(10.0, 0.0); 
			glVertex3f(50.0, -50.0, 0.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
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
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, sdlimage->w, sdlimage->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sdlimage->pixels );
}

/**
 * @brief create all texture needed.
 * This function build all the texture.
 */
void loadTexture(){
	createTexture(&texName1,"./texture/grass.jpg");
	// createTexture(&texName2,"./texture/earth.png");
	// createTexture(&texName3,"./texture/mars.jpg");
	// createTexture(&texName4,"./texture/stars.png");
	// createTexture(&texName5,"./texture/Tardis.png");
}











//*****************************************************************
//*****************************************************************
//                           INUTILITY :)
//*****************************************************************
//*****************************************************************

/**
 * The follow function are not commented cause are just random stuff
 * added to the original request of the assignment.
 */


int enableOrbit(){
	if(ORBIT){
		ORBIT=1;
		return 0;
	}
	ORBIT=1;
	return 1;
}

void disableOrbit(){ORBIT=0;};


void drawOrbit(double radius, GLfloat color[3]){
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f (color[0], color[1], color[2]);
	glBegin(GL_LINES);
		double i;
		for(i = 0; i < 2 * PI; i += PI / 100)
 			glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void drawAxis(double radius, GLfloat color[3]){
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f (color[0], color[1], color[2]);
	glBegin( GL_LINES );
		glVertex3f(0.0, 0.0, -2*radius);
		glVertex3f(0.0, 0.0, +2*radius);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void drawString (void * font, char *s, float x, float y, float z){
     unsigned int i;
     glRasterPos3f(x, y, z);
     glColor3f( 1, 1, 1 );
     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}

void menu()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

 	glColor3f( 1.0, 0.8, 0.5 );
  	drawString(GLUT_BITMAP_HELVETICA_12, "Show Axis: 1       Show Orbit: 2         Enable Tardis: 3", -5, 5.3, -10);
  	glColor3f( 1.0, 1.0, 1.0 );
  	drawString(GLUT_BITMAP_HELVETICA_12, "Zoom: W/A          Horizontal: A/D       Vertical: C/V", -5, 4.9, -10);
  	drawString(GLUT_BITMAP_HELVETICA_12, "Speed: Arrow Up/down", -5, 4.5, -10);
  	glEnable(GL_TEXTURE_2D);

  	glEnable(GL_LIGHTING);
}

// Just a simple joke
void WHO(double angle){
	if(TARDIS){
		glPushAttrib(GL_LIGHTING_BIT);
			GLfloat material_col[] = {1.0, 1.0, 1.0, 0.0};
			glMaterialfv(GL_FRONT, GL_EMISSION, material_col);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texName5);
			glPushMatrix();
				glRotatef(10*angle*0.9, 0, 0, 1);
				glRotatef(10*angle*0.8, 0, 1, 0);
				glRotatef(10*angle*0.5, 1, 0, 0);
				glTranslatef(15,15,0);
				glRotatef(135, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0); 
					glVertex3f(-2.0, -1.0, 0.0);
					glTexCoord2f(0.0, 1.0); 
					glVertex3f(-2.0, 1.0, 0.0);
					glTexCoord2f(1.0, 1.0); 
					glVertex3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0, 0.0); 
					glVertex3f(0.0, -1.0, 0.0);
				glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	}
}
