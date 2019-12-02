#include <stdlib.h>
#include <glut.h>
#include <cmath>
#include <random>
#include<iostream>
#include<windows.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")


void Display();
int minY = 0;
double random1 = 1;
double random2= 1;
double random3 = 1;
double random4 = 1;
double random5 = 1;
double random6 = 1;
double random7 = 1;
bool reset = false;
bool warmUp= true; 
int minX = 0;
int maxX = 0;
int maxY = 0;
int set = 0;
int heart = 1000;
int level = 1;
int gameSpeed = 125;
int gameSpeedPenalty = 125;
int frame = 0;
int freeze = 2500;
//Hero Attributes
int speX = 0;
int speY = 0;
int heroHeight = 105;
int heroWidth = 80;
int minXH1 = 40;
int maxXH1 = 120;
int minYH1 = 20;
int maxYH1 = 125;

//Health Bar
int healthX = 0;
int healthY = 0;
int healthC = 0;
float health = 900.0f;
int heartTemp = 0;
//building 1
int city1X = 0;
int city1Y = 0;
float b1scale = 1.01f;
int minXC1 = 0;
int maxXC1 = 0;
int minYC1 = 0;
int maxYC1 = 0;
//Starting Value of Building 1
float minOXC1 = 0.0f;
float maxOXC1 = 0.0f;
float minOYC1 = 0.0f;
float maxOYC1 = 0.0f;

//building 2
int city2X = 0;
int city2Y = 0;
float b2scale = 1.01f;
int minXC2 = 0;
int maxXC2 = 0;
int minYC2 = 0;
int maxYC2 = 0;
//Starting Value of Building 2
float minOXC2 = 0.0f;
float maxOXC2 = 0.0f;
float minOYC2 = 0.0f;
float maxOYC2 = 0.0f;

//building 3
int city3X = 0;
int city3Y = 0;
float b3scale = 1.01f;
int minXC3 = 0;
int maxXC3 = 0;
int minYC3 = 0;
int maxYC3 = 0;
//Starting Value of Building 3
float minOXC3 = 0.0f;
float maxOXC3 = 0.0f;
float minOYC3 = 0.0f;
float maxOYC3 = 0.0f;

//building 4
int city4X = 0;
int city4Y = 0;
float b4scale = 1.01f;
int minXC4 = 0;
int maxXC4 = 0;
int minYC4 = 0;
int maxYC4 = 0;
//Starting Value of Building 4
float minOXC4 = 0.0f;
float maxOXC4 = 0.0f;
float minOYC4 = 0.0f;
float maxOYC4 = 0.0f;


//building 5
int city5X = 0;
int city5Y = 0;
float b5scale = 1.01f;
int minXC5 = 0;
int maxXC5 = 0;
int minYC5 = 0;
int maxYC5 = 0;
//Starting Value of Building 2
float minOXC5= 0.0f;
float maxOXC5 = 0.0f;
float minOYC5 = 0.0f;
float maxOYC5 = 0.0f;

//building 6
int city6X = 0;
int city6Y = 0;
float b6scale = 1.01f;
int minXC6 = 0;
int maxXC6 = 0;
int minYC6 = 0;
int maxYC6 = 0;
//Starting Value of Building 6
float minOXC6 = 0.0f;
float maxOXC6 = 0.0f;
float minOYC6 = 0.0f;
float maxOYC6 = 0.0f;

//building 7
int city7X = 0;
int city7Y = 0;
float b7scale = 1.01f;
int minXC7 = 0;
int maxXC7 = 0;
int minYC7 = 0;
int maxYC7 = 0;
//Starting Value of Building 7
float minOXC7 = 0.0f;
float maxOXC7 = 0.0f;
float minOYC7 = 0.0f;
float maxOYC7 = 0.0f;

float heartR = 1.0f;
float heartG = 0.0f;
float heartB = 0.0f;

bool flag = true;

void drawCharacter(int scale) {
	//Left Foot
	glPushMatrix();
	glTranslated(speX, speY, 0);
	
	
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(40.0f*scale, 20.0f*scale, 0.0f);
	glVertex3f(60.0f*scale, 20.0f*scale, 0.0f);
	glVertex3f(60.0*scale, 30.0f*scale, 0.0f);
	glVertex3f(40.0*scale, 30.0f*scale, 0.0f);
	glEnd();

	

	//Left Leg
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(50.0f*scale, 30.0f*scale, 0.0f);
	glVertex3f(60.0f*scale, 30.0f*scale, 0.0f);
	glVertex3f(80.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(70.0f*scale, 60.0f*scale, 0.0f);
	glEnd();

	//Right Foot
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(100.0f*scale, 20.0f*scale, 0.0f);
	glVertex3f(120.0f*scale, 20.0f*scale, 0.0f);
	glVertex3f(120.0f*scale, 30.0f*scale, 0.0f);
	glVertex3f(100.0f*scale, 30.0f*scale, 0.0f);
	glEnd();

	//Right Leg
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(100.0f*scale, 30.0f*scale, 0.0f);
	glVertex3f(110.0f*scale, 30.0f*scale, 0.0f);
	glVertex3f(90.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(80.0f*scale, 60.0f*scale, 0.0f);
	glEnd();

	//Torso
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(70.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(90.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(90.0f*scale, 100.0f*scale, 0.0f);
	glVertex3f(70.0f*scale, 100.0f*scale, 0.0f);
	glEnd();

	//Right Arm
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(90.0f*scale, 80.0f*scale, 0.0f);
	glVertex3f(120.0f*scale, 80.0f*scale, 0.0f);
	glVertex3f(120.0f*scale, 90.0f*scale, 0.0f);
	glVertex3f(90.0f*scale, 90.0f*scale, 0.0f);
	glEnd();

	

	//Left Arm
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(70.0f*scale, 80.0f*scale, 0.0f);
	glVertex3f(70.0f*scale, 90.0f*scale, 0.0f);
	glVertex3f(40.00*scale, 90.0f*scale, 0.0f);
	glVertex3f(40.0f*scale, 80.0f*scale, 0.0f);
	glEnd();

	//Symbol
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(75.0f*scale, 90.0f*scale, 0.0f);
	glVertex3f(85.0f*scale, 90.0f*scale, 0.0f);
	glVertex3f(80.0f*scale, 70.0f*scale, 0.0f);
	glEnd();

	//Neck
	glBegin(GL_QUADS);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(77.0f*scale, 100.0f*scale, 0.0f);
	glVertex3f(83.0f*scale, 100.0f*scale, 0.0f);
	glVertex3f(83.0f*scale, 105.0f*scale, 0.0f);
	glVertex3f(77.0f*scale, 105.0f*scale, 0.0f);
	glEnd();

	//Head
	glPushMatrix();
	glColor3f(0.37f, 0.29f, 0.22f);
	glTranslated(80.0f*scale, 115.0f*scale, 0.0f);
	GLUquadric * quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, 10 * scale, 50, 50);
	glPopMatrix();

	
	//Left Eye
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslated(75.0f*scale, 120.0f*scale, 0.0f);
	GLUquadric * quadObjl = gluNewQuadric();
	gluDisk(quadObjl, 0, 2 * scale, 50, 50);
	glPopMatrix();

	//Right Eye
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslated(85.0f*scale, 120.0f*scale, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 2 * scale, 50, 50);
	glPopMatrix();

	//Mouth x:70->90	y:105-> 125
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.102f, 0.204f);
	glVertex3f(77.0f*scale, 107.0f*scale, 0.0f);
	glVertex3f(80.0f*scale, 110.0f*scale, 0.0f);
	glVertex3f(75.0f*scale, 113.0f*scale, 0.0f);
	glVertex3f(73.0f*scale, 107.0f*scale, 0.0f);
	glVertex3f(70.0f*scale, 107.0f*scale, 0.0f);
	glEnd();

	//Left Cape
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(90.0f*scale, 80.0f*scale, 0.0f);
	glVertex3f(90.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(120.0f*scale, 80.0f*scale, 0.0f);
	glEnd();

	//Right Cape
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(70.0f*scale, 80.0f*scale, 0.0f);
	glVertex3f(70.0f*scale, 60.0f*scale, 0.0f);
	glVertex3f(40.0f*scale, 80.0f*scale, 0.0f);
	glEnd();

	glPopMatrix();
}

void drawBuilding(int scale,float x,float y) {
	//Building
	glPushMatrix();
	glTranslated(city1X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x+10.0f, y+10.0f, 0.0f);
	glVertex3f(x+70.0f, y+10.0f, 0.0f);
	glVertex3f(x+70.0f, y+120.0f*b1scale, 0.0f);
	glVertex3f(x+10.0f, y+120.0f*b1scale, 0.0f);
	glEnd();

	minOXC1 = (x + 10.0f);
	maxOXC1 = (x + 70.0f);
	minOYC1 = (y + 10.0f);
	maxOYC1 = (y + 120.0f*b1scale);

	
	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x+30.0f, y+10.0f, 0.0f);
	glVertex3f(x+50.0f, y+10.0f, 0.0f);
	glVertex3f(x+50.0f, y+30.0f, 0.0f);
	glVertex3f(x+30.0f, y+30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x+35.0f, y+30.0f, 0.0f);
	glVertex3f(x+40.0f, y+30.0f, 0.0f);
	glVertex3f(x+45.0f, y+30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+20.0f, y+35.0f, 0.0f);
	glVertex3f(x+30.0f, y+35.0f, 0.0f);
	glVertex3f(x+30.0f, y+45.0f, 0.0f);
	glVertex3f(x+20.0f, y+45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+20.0f, y+55.0f, 0.0f);
	glVertex3f(x+30.0f, y+55.0f, 0.0f);
	glVertex3f(x+30.0f, y+65.0f, 0.0f);
	glVertex3f(x+20.0f, y+65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+20.0f, y+75.0f, 0.0f);
	glVertex3f(x+30.0f, y+75.0f, 0.0f);
	glVertex3f(x+30.0f, y+95.0f, 0.0f);
	glVertex3f(x+20.0f, y+95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+50.0f, y+35.0f, 0.0f);
	glVertex3f(x+60.0f, y+35.0f, 0.0f);
	glVertex3f(x+60.0f, y+45.0f, 0.0f);
	glVertex3f(x+50.0f, y+45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+50.0f, y+55.0f, 0.0f);
	glVertex3f(x+60.0f, y+55.0f, 0.0f);
	glVertex3f(x+60.0f, y+65.0f, 0.0f);
	glVertex3f(x+50.0f, y+65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x+50.0f, y+75.0f, 0.0f);
	glVertex3f(x+60.0f, y+75.0f, 0.0f);
	glVertex3f(x+60.0f, y+95.0f, 0.0f);
	glVertex3f(x+50.0f, y+95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding2(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city2X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, 360.0f*b2scale, 0.0f);
	glVertex3f(x + 70.0f, 360.0f*b2scale, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f, 0.0f);
	glEnd();

	minOXC2 = (x + 10.0f);
	maxOXC2 = (x + 70.0f);
	minOYC2 = (y + 10.0f*b2scale);
	maxOYC2 = (y + 120.0f);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding3(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city3X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f*b3scale, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f*b3scale, 0.0f);
	glEnd();

	minOXC3 = (x + 10.0f);
	maxOXC3 = (x + 70.0f);
	minOYC3 = (y + 10.0f);
	maxOYC3 = (y + 120.0f*b3scale);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding4(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city4X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, 360.0f*b4scale, 0.0f);
	glVertex3f(x + 70.0f, 360.0f*b4scale, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f, 0.0f);
	glEnd();

	minOXC4 = (x + 10.0f);
	maxOXC4 = (x + 70.0f);
	minOYC4 = (y + 10.0f*b4scale);
	maxOYC4 = (y + 120.0f);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding5(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city5X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f*b5scale, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f*b5scale, 0.0f);
	glEnd();

	minOXC5 = (x + 10.0f);
	maxOXC5 = (x + 70.0f);
	minOYC5 = (y + 10.0f);
	maxOYC5 = (y + 120.0f*b5scale);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding6(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city6X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, 360.0f*b6scale, 0.0f);
	glVertex3f(x + 70.0f, 360.0f*b6scale, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f, 0.0f);
	glEnd();

	minOXC6 = (x + 10.0f);
	maxOXC6 = (x + 70.0f);
	minOYC6 = (y + 10.0f*b6scale);
	maxOYC6 = (y + 120.0f);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 60.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}
void drawBuilding7(int scale, float x, float y) {
	//Building
	glPushMatrix();
	glTranslated(city7X, 0, 0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x + 10.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 70.0f, y + 120.0f*b7scale, 0.0f);
	glVertex3f(x + 10.0f, y + 120.0f*b7scale, 0.0f);
	glEnd();

	minOXC7 = (x + 10.0f);
	maxOXC7 = (x + 70.0f);
	minOYC7 = (y + 10.0f);
	maxOYC7 = (y + 120.0f*b7scale);


	//printf("%d till %d  and  City1X is %d \n", minXC1, maxXC1, city1X);

	/*printf("Width =");
	printf("%d \n", width1);
	printf("Height =");
	printf("%d \n", height1);
	printf("------------------------------------ \n");
	*/
	//Door
	glBegin(GL_POLYGON);
	glColor3f(0.37f, 0.29f, 0.22f);
	glVertex3f(x + 30.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 10.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 30.0f, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(x + 35.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 40.0f, y + 30.0f, 0.0f);
	glVertex3f(x + 45.0f, y + 30.0f, 0.0f);
	glEnd();

	// Window R1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window R2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window R3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 20.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 30.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 20.0f, y + 95.0f, 0.0f);
	glEnd();

	// Window L1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 35.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 45.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 45.0f, 0.0f);
	glEnd();

	// Window L2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 55.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 65.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 65.0f, 0.0f);
	glEnd();

	// Window L3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(x + 50.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 75.0f, 0.0f);
	glVertex3f(x + 60.0f, y + 95.0f, 0.0f);
	glVertex3f(x + 50.0f, y + 95.0f, 0.0f);
	glEnd();

	//Right Eye
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslated(x + 30.0f, y + 75.0f, 0.0f);
	GLUquadric * quadObjr = gluNewQuadric();
	gluDisk(quadObjr, 0, 5 * scale, 50, 50);
	glPopMatrix();

	glPopMatrix();
}


void drawHeart()
{
	//glClearColor(0.26f, 0.33f, 0.35f, 0.0f);
	glPointSize(15.0);
	glPushMatrix();
	glTranslated(heart, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(500.0f, 300.0f, 0.0f);
	glVertex3f(500.0f, 330.0f, 0.0f);
	glVertex3f(590.0f, 300.0f, 0.0f);
	glEnd();
	glColor3f(heartR, heartB, heartB);
	glVertex3f(500.0f, 300.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPointSize(4.0);
}
void drawFreeze()
{
	glPointSize(15.0);
	glPushMatrix();
	glTranslated(freeze, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(500.0f, 300.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPointSize(4.0);
}
void drawHealthBar(){

	glPushMatrix();
	glTranslated(healthX, healthY, 0);

	glBegin(GL_POLYGON);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glColor3d(1, healthC, 0);
	glVertex3f(600.0f, 590.0f, 0.0f);
	glVertex3f(health, 590.0f, 0.0f);
	glVertex3f(health, 600.0f, 0.0f);
	glVertex3f(600.0f, 600.0f, 0.0f);
	glEnd();

	glPopMatrix();
}
void powerUp(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
		printf("Clicked \n");

		if (heart > -400 && heart < 420 && heart%25==0){
		//We can activate the power up
			health = 900.0f;
			heart = -2000;
			printf("Healed \n");
			glutPostRedisplay();
		}
		if (freeze > -400 && freeze < 420){
			//We can activate the power up
			flag = false;
			printf("Freezed");
			
		}
	}
}	
void fly(int k, int x, int y){
	if (health < 600.0f ){
		//You died
		return;

	}
	if (level == 4){
		// You Won
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		return;
	}
	if (k == GLUT_KEY_RIGHT && k == GLUT_KEY_UP){ //( moving upright)
		speX = (speX + 10) % 1000;
		minXH1 = minXH1 + 10.0f;
		maxXH1 = maxXH1 + 10.0f;
		speY = speY + 10;
		minYH1 = minYH1 + 10.0f;
		maxYH1 = maxYH1 + 10.0f;

	}
	if (k == GLUT_KEY_DOWN && k == GLUT_KEY_RIGHT){
		speX = (speX + 10) % 1000;
		minXH1 = minXH1 + 10.0f;
		maxXH1 = maxXH1 + 10.0f;
		speY -= 10;
		minYH1 = minYH1 - 10.0f;
		maxYH1 = maxYH1 - 10.0f;
	}
	if (k == GLUT_KEY_RIGHT){//(moving right)
		speX = (speX + 20) % 1000;
		minXH1 = minXH1 + 20.0f;
		maxXH1 = maxXH1 + 20.0f;

	}
	if (k == GLUT_KEY_LEFT){//(moving left)
		if (speX < 0){
			return;
		}
		speX -= 20;
		minXH1 = minXH1 - 20.0f;
		maxXH1 = maxXH1 - 20.0f;
	}
	if (k == GLUT_KEY_UP){// (moving upwards)
		if (speY > 460){
			return;
		}
		speY = speY + 20;
		minYH1 = minYH1 + 20.0f;
		maxYH1 = maxYH1 + 20.0f;
	}
	if (k == GLUT_KEY_DOWN){//(moving downwards)
		if (speY < -0){
			return;
		}
		speY -= 20;
		minYH1 = minYH1 - 20.0f;
		maxYH1 = maxYH1 - 20.0f;
	}
	
	
	glutPostRedisplay();

	

}


void createObstacle(int val){
	frame = frame + 1;
	if (flag){
		gameSpeed = 125;
	}
	if (reset){
		flag = true;
		freeze = freeze - 2000;
	}
	if (!flag){
		printf("Freeze confirmed");
		gameSpeed = 2500;
		reset = true;
	}
	city1X = (city1X - 10);
	city2X = (city2X - 10);
	city3X = (city3X - 10);
	city4X = (city4X - 10);
	city5X = (city5X - 10);
	city6X = (city6X - 10);
	city7X = (city7X - 10);

	if (city1X < -1000){
		city1X = 900;
	}
	else if (city2X < -500){
		city2X = 900;
	}
	else if (city3X < -700){
		city3X = 1000;
	}
	else if (city4X < -900){
		city4X = 900;
	}
	else if (city5X < -1000){
		city5X = 900;

	}
	else if (city6X < -1200){
		city6X = 900;
	}
	else if (city7X < -1400){
		city7X = 900;
		level = level + 1;
	}

	//Leveling up
	if (level == 2 && flag){
		gameSpeed = 75;
		//drawHeart();
	}
	else if (level == 3 && flag){
		gameSpeed = 40;

	}
	if (level == 4 && flag){
		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		return;
	}
	//Powere Ups

	if ((int)health%25 == 0){
		//glClearColor(0.26f, 0.33f, 0.35f, 0.0f);
		heartR = 0.26f;
		heartG = 0.33f;
		heartB = 0.35f;
	}
	if (level == 2 && health == 0){
		//drawHeart();
		heartR = 1.0f;
		heartB = 0.0f;
		heartB = 0.0f;
		health = health - 10;

	}
	else if (health < 0){
		health = health - 10;
	}
	heart = heart - 10;
	freeze = freeze - 10;
	//printf("The Value is %d \n",heart);

	//Randmoizer
	if (frame < 50 && warmUp){
		b1scale = b2scale = b3scale = b4scale = b5scale = b7scale = 1;
		warmUp = false;

	}
	else{
		if (frame % 50 == 0){
			random1 = rand() % 3 + 1;
			random2 = rand() % 3 + 1;
			random3 = rand() % 3 + 1;
			random4 = rand() % 3 + 1;
			random5 = rand() % 3 + 1;
			random6 = rand() % 3 + 1;
			random7 = rand() % 3 + 1;
			frame = 0;
		}

		b1scale = random1;
		b3scale = random3;
		b5scale = random5;
		b7scale = random7;
				
		b2scale = 1 / random2;
		b4scale = 1 / random4;
		b6scale = 1 / random6;

		frame++;
			
	
	
	}	
	
	//Height of the buidling is 110
	// ONE Update scalke and refresh upper and lower bounds
	//b1scale = b1scale * 1.0005;
	maxXC1 = (maxOXC1) +city1X;
	minXC1 = (minOXC1) +city1X;
	minYC1 = minOYC1;
	maxYC1 = minYC1 + (110 * b1scale);
	// TWO Update scalke and refresh upper and lower bounds
	//b2scale = b2scale * 1.0005;
	maxXC2 = (maxOXC2) + city2X;
	minXC2 = (minOXC2) + city2X;
	maxYC2 = maxOYC2;
	minYC2 =  (360 * b2scale);
	// THREE  Update scalke and refresh upper and lower bounds
	//b3scale = b3scale * 1.0005;
	maxXC3 = (maxOXC3) + city3X;
	minXC3 = (minOXC3) + city3X;
	minYC3 = minOYC3;
	maxYC3 = minYC3 + (110 * b3scale);
	// FOUR Update scalke and refresh upper and lower bounds
	//b4scale = b4scale * 1.0005;
	maxXC4 = (maxOXC4) + city4X;
	minXC4 = (minOXC4) + city4X;
	maxYC4 = maxOYC4;
	minYC4 =  (360 * b4scale);
	
	// FIVE Update scalke and refresh upper and lower bounds
	//b5scale = b5scale * 1.0005;
	maxXC5 = (maxOXC5) + city5X;
	minXC5 = (minOXC5) + city5X;
	minYC5 = minOYC5;
	maxYC5 = minYC5 + (110 * b5scale);
	// FOUR Update scalke and refresh upper and lower bounds
	maxXC6 = (maxOXC6)+city6X;
	minXC6 = (minOXC6)+city6X;
	maxYC6 = maxOYC6;
	minYC6 = (360 * b6scale);
	// SEVEN Update scalke and refresh upper and lower bounds
	//b7scale = b7scale * 1.0007;
	maxXC7 = (maxOXC7)+city7X;
	minXC7 = (minOXC7)+city7X;
	minYC7 = minOYC7;
	maxYC7 = minYC7 + (110 * b7scale);

	//ONE Calculating Coordinates
	/*printf("The Y Boundries of Building One is %d till %d \n", minYC1, maxYC1);
	printf("The Y Dat Boi is %d till %d \n", minYH1, maxYH1);
	printf("---------------------------------------------- \n");*/

	bool max_hero_x1_inrange = maxXH1 > minXC1 && maxXH1 < maxXC1;
	bool min_hero_x1_inrange = minXH1 > minXC1 && minXH1 < maxXC1;
	bool the_x1_inrange = max_hero_x1_inrange || min_hero_x1_inrange;

	bool max_hero_y1_inrange = maxYH1 > minYC1 && maxYH1 < maxYC1;
	bool min_hero_y1_inrange = minYH1 > minYC1 && minYH1 < maxYC1;
	bool the_y1_inrange = max_hero_y1_inrange || min_hero_y1_inrange;

	bool in_range1 = the_x1_inrange && the_y1_inrange;

	//TWO Calculating Coordinates
	bool max_hero_x2_inrange = maxXH1 > minXC2 && maxXH1 < maxXC2;
	bool min_hero_x2_inrange = minXH1 > minXC2 && minXH1 < maxXC2;
	bool the_x2_inrange = max_hero_x2_inrange || min_hero_x2_inrange;

	bool max_hero_y2_inrange = maxYH1 > minYC2 && maxYH1 < maxYC2;
	bool min_hero_y2_inrange = minYH1 > minYC2 && minYH1 < maxYC2;
	bool the_y2_inrange = max_hero_y2_inrange || min_hero_y2_inrange;

	bool in_range2 = the_x2_inrange && the_y2_inrange;

	//THREE Calculatin coordinates 
	bool max_hero_x3_inrange = maxXH1 > minXC3 && maxXH1 < maxXC3;
	bool min_hero_x3_inrange = minXH1 > minXC3 && minXH1 < maxXC3;
	bool the_x3_inrange = max_hero_x3_inrange || min_hero_x3_inrange;

	bool max_hero_y3_inrange = maxYH1 > minYC3 && maxYH1 < maxYC3;
	bool min_hero_y3_inrange = minYH1 > minYC3 && minYH1 < maxYC3;
	bool the_y3_inrange = max_hero_y3_inrange || min_hero_y3_inrange;

	bool in_range3 = the_x3_inrange && the_y3_inrange;

	//FOUR Calculatin coordinates 
	bool max_hero_x4_inrange = maxXH1 > minXC4 && maxXH1 < maxXC4;
	bool min_hero_x4_inrange = minXH1 > minXC4 && minXH1 < maxXC4;
	bool the_x4_inrange = max_hero_x4_inrange || min_hero_x4_inrange;

	bool max_hero_y4_inrange = maxYH1 > minYC4 && maxYH1 < maxYC4;
	bool min_hero_y4_inrange = minYH1 > minYC4 && minYH1 < maxYC4;
	bool the_y4_inrange = max_hero_y4_inrange || min_hero_y4_inrange;

	bool in_range4 = the_x4_inrange && the_y4_inrange;

	//FIVE Calculatin coordinates 
	bool max_hero_x5_inrange = maxXH1 > minXC5 && maxXH1 < maxXC5;
	bool min_hero_x5_inrange = minXH1 > minXC5 && minXH1 < maxXC5;
	bool the_x5_inrange = max_hero_x5_inrange || min_hero_x5_inrange;

	bool max_hero_y5_inrange = maxYH1 > minYC5 && maxYH1 < maxYC5;
	bool min_hero_y5_inrange = minYH1 > minYC5 && minYH1 < maxYC5;
	bool the_y5_inrange = max_hero_y5_inrange || min_hero_y5_inrange;

	bool in_range5 = the_x5_inrange && the_y5_inrange;

	//SIX Calculatin coordinates 
	bool max_hero_x6_inrange = maxXH1 > minXC6 && maxXH1 < maxXC6;
	bool min_hero_x6_inrange = minXH1 > minXC6 && minXH1 < maxXC6;
	bool the_x6_inrange = max_hero_x6_inrange || min_hero_x6_inrange;

	bool max_hero_y6_inrange = maxYH1 > minYC6 && maxYH1 < maxYC6;
	bool min_hero_y6_inrange = minYH1 > minYC6 && minYH1 < maxYC6;
	bool the_y6_inrange = max_hero_y6_inrange || min_hero_y6_inrange;

	bool in_range6 = the_x6_inrange && the_y6_inrange;

	//FIVE Calculatin coordinates 
	bool max_hero_x7_inrange = maxXH1 > minXC7 && maxXH1 < maxXC7;
	bool min_hero_x7_inrange = minXH1 > minXC7 && minXH1 < maxXC7;
	bool the_x7_inrange = max_hero_x7_inrange || min_hero_x7_inrange;

	bool max_hero_y7_inrange = maxYH1 > minYC7 && maxYH1 < maxYC7;
	bool min_hero_y7_inrange = minYH1 > minYC7 && minYH1 < maxYC7;
	bool the_y7_inrange = max_hero_y7_inrange || min_hero_y7_inrange;

	bool in_range7 = the_x7_inrange && the_y7_inrange;


	if (in_range1 || in_range2 || in_range3 || in_range4 || in_range5 || in_range6 || in_range7){
		healthC = 1;
		health = health - 20;
		gameSpeed = 500;
		//mciSendString("play mp3 ", NULL, 0, NULL);
	//	mciSendString("play oof.mp3 wait", NULL, 0, NULL);
	//	PlaySound("D:\My stuff\GUC\Year 4\Semester 7\Computer Graphics\Superman\OpenGL2DTemplate\audio.wav", NULL, SND_FILENAME);
		if (health < 600.0f){
			//You died
			glClearColor(0.7f, 0.0f, 0.0f, 0.0f);
			glutPostRedisplay();
			return;

		}
		
	}
	else{
		healthC = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(gameSpeed, createObstacle, 0);

}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawCharacter(1);
	drawHealthBar();
	drawBuilding(1,  200.0f,0.0f);
	drawBuilding2(1, 400.0f, 350.0f);
	drawBuilding3(1, 600.0f, 0.0f);
	drawBuilding4(1, 800.0f, 350.0f);
	drawBuilding5(1, 1000.0f, 0.0f);
	drawBuilding6(1, 1200.0f, 350.0f);
	drawBuilding7(1, 1400.0f, 0.0f);
	drawHeart();
	drawFreeze();
	glFlush();
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Superman The Game");
	glutDisplayFunc(Display);
	//mciSendString("open oof.mp3 type mpegvideo alias mp3", NULL, 0, NULL);
	glClearColor(0.26f, 0.33f, 0.35f, 0.0f);
	glutSpecialFunc(fly);
	glPointSize(4.0);
	glutTimerFunc(0, createObstacle, 6);
	glutMouseFunc(powerUp);
	gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
	glutMainLoop();
}
