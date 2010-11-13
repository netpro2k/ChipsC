#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")

//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#include <GLUT/glut.h>
#include "textures.h"
#include <iostream.h> 
#include "player.h"
#include "world.h"

void SizeOpenGLScreen(int width, int height);			// Initialize The GL Window
void keys(int key, int x, int y);
void init();      

world myWorld;

void init()                  
{
	glClearColor(0, 0, 0, 0) ;
	//texture properties
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glShadeModel(GL_SMOOTH) ;
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	myWorld.setup();

}

// The display function
void renderScene(void)              
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();	
	myWorld.draw();
	glutSwapBuffers();	
}

// The main function
int main(int argc, char** argv)   
{
	glutInit(&argc, argv) ;
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB) ;
	glutInitWindowSize(400, 400) ;
	glutInitWindowPosition(100, 100) ;
	glutCreateWindow("cool stuff") ;
/*	glutGameModeString("800x600:32");
	glutEnterGameMode();*/
	init();
	glutDisplayFunc(renderScene) ;
	glutReshapeFunc(SizeOpenGLScreen);
	glutSpecialFunc(keys);
	glutIdleFunc(renderScene);


	glutMainLoop() ;
	return 0 ;
}

//rezize screen
void SizeOpenGLScreen(int width, int height)			
{
	myWorld.mainCam.updateRatio(width,height);
}


void keys(int key, int x, int y)
{
	myWorld.checkNewPosition(key);
}