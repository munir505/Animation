#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include <time.h>
#include "Guts.h"
#define SPRAYSIZE 1000
#define SNOWSIZE 150

int counter = -200;
int movementCounter = 0;
float theta = 0;
float theta2 = 0;
float xA = 0;
float yA = 0;
float rotateScene = 0;
float enemyRotate = 0;
int sprayCounter = 0;
float angle = 90;
float sprayWidth = 30;
float sprayCenterX, sprayCenterY;
float fr = 1; float fg = 0;  float fb = 0;
float gy = -0.05;
int winWidth = 1350, winHeight = 650;
float throwObject = 0;
float above = 0;
float fallDown = 0;
float cut = -45;
float moveRight = 0;
float moveLeft = 0;
float moveWhole = 0;
float headFall = 0;
float xRC = 0;
float rollingHead = 0;
float rollingHeadMove = 0;
float c1 = 0.34;
float c2 = 0;
float c3 = 0;


struct sprayParticle {
	float x = 0; // current position  x
	float y = 0; // current position  y
	float startx = 0; // birth position  x
	float starty = 0; // birth position y
	int startTime; // a birthtime in frames when it will be born
	int startRange = 10000; // the maximum time at which a birth can happen
	bool started = false; // tracks whether the particle has benn born or not
	float speed = 0.1;
	float radius;
	float startxd = 0; // starting direction vector x value
	float startyd = 0; // startingdirection vestor y value
	float xd = 0;  //  current direction vector x value
	float yd = 0;  // current direction vector x value
	float alpha = 1.0; // transparency
};
struct drop {
	float x = 400;
	float y = 400;
	float inc = 0.01;
	float radius = 5;
	float scale = 1.0;
	float rotationAngle = 0;
	float rotationInc = 1;
	float r, g, b, a;
};
time_t t;
sprayParticle spray[SPRAYSIZE];
drop SNOW[SNOWSIZE];
void snow(double radius, double xc, double yc)
{
	int i;
	double angle = 2 * 3.1415 / 20;
	double circle_xy[40][2];

	circle_xy[0][0] = radius + xc;
	circle_xy[0][1] = yc;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	for (i = 1; i < 20; i++)
	{
		circle_xy[i][0] = radius * cos(i *angle) + xc;
		circle_xy[i][1] = radius * sin(i * angle) + yc;
		glVertex2f(circle_xy[i - 1][0], circle_xy[i - 1][1]);
		glVertex2f(circle_xy[i][0], circle_xy[i][1]);
	}
	glEnd();
}
void initSNOW()
{
	for (int i = 0; i < SNOWSIZE; i++) {
		SNOW[i].x = rand() % winWidth;
		SNOW[i].y = rand() % winHeight;
		SNOW[i].inc = 0.8 + (float)(rand() % 100) / 1000.0;
		SNOW[i].r = 1;
		SNOW[i].g = 1;
		SNOW[i].b = 1;
		SNOW[i].a = 1;
		SNOW[i].scale = (float)(rand() % 20000) / 1000.0;
		SNOW[i].rotationAngle = (float)(rand() % 3000) / 1000.0;
		SNOW[i].rotationInc = (float)(rand() % 100) / 1000.0;
		if ((rand() % 100) > 50) {
			SNOW[i].rotationInc = -SNOW[i].rotationInc;
		}
	}
}
void drawParticleShape(int i)
{
	snow(SNOW[i].radius, SNOW[i].x, SNOW[i].y);
	glPushMatrix();
	glTranslatef(SNOW[i].x, SNOW[i].y, 0.0);
	glScalef(SNOW[i].scale, SNOW[i].scale, 1);
	glTranslatef(-SNOW[i].x, -SNOW[i].y, 0.0);
	glTranslatef(SNOW[i].x, SNOW[i].y, 0.0);
	glRotatef(SNOW[i].rotationAngle, 0, 0, 1);
	glTranslatef(-SNOW[i].x, -SNOW[i].y, 0.0);

	glColor4f(SNOW[i].r, SNOW[i].g, SNOW[i].b, SNOW[i].a);
	glPopMatrix();
	SNOW[i].rotationAngle += SNOW[i].rotationInc;
}
void drawSNOW()
{
	for (int i = 0; i < SNOWSIZE; i++)
	{
		glLineWidth(2);

		drawParticleShape(i);
		SNOW[i].y -= SNOW[i].inc;
		if (SNOW[i].y < 0) {
			SNOW[i].y = winHeight;
		}
	}
}
void circle2(double radius, double xc, double yc)
{
	int i;
	double angle = 2 * 3.1415 / 20;
	double circle_xy[40][2];

	circle_xy[0][0] = radius + xc;
	circle_xy[0][1] = yc;
	glBegin(GL_POLYGON);
	for (i = 1; i<20; i++)
	{
		circle_xy[i][0] = radius * cos(i *angle) + xc;
		circle_xy[i][1] = radius * sin(i * angle) + yc;

		glVertex2f(circle_xy[i - 1][0], circle_xy[i - 1][1]);
		glVertex2f(circle_xy[i][0], circle_xy[i][1]);
	}
	glEnd();
}
void normalise(int i)
{
	float mag;
	mag = sqrt((spray[i].xd*spray[i].xd) + (spray[i].yd*spray[i].yd));
	spray[i].xd = spray[i].xd / mag;
	spray[i].yd = spray[i].yd / mag;
}
void setDirectionVector(int i)
{
	float minAngle, maxAngle, range, newangle;
	double newAngleInRadians;
	int rangeInt;
	minAngle = angle - (sprayWidth / 2.0);
	maxAngle = angle + (sprayWidth / 2.0);
	range = maxAngle - minAngle;
	rangeInt = (int)(range*100.0);
	newangle = minAngle + ((float)(rand() % rangeInt) / 100.0);
	newAngleInRadians = (double)(newangle / 360.0)*(2 * 3.1415);

	spray[i].xd = (float)cos(newAngleInRadians);
	spray[i].yd = (float)sin(newAngleInRadians);
}
void initspray()
{
	for (int i = 0; i < SPRAYSIZE; i++) {
		spray[i].x = 805; // set current start x position
		spray[i].y = 270;// set current start y position
		spray[i].startx = spray[i].x; spray[i].starty = spray[i].y;
		spray[i].speed = 2 + (float)(rand() % 150) / 1000.0;// speed is 0.1 to 0.25
		spray[i].startTime = rand() % spray[i].startRange;// set birth time
		spray[i].radius = (float)(rand() % 8); // random radius
		setDirectionVector(i);// set the current direction vector
		spray[i].startxd = spray[i].xd; spray[i].startyd = spray[i].yd; // set start direction vector to current
	}
	// set colour of spray 
	fr = 1;
	fg = 0;
	fb = 0;
}
void drawsprayParticle(int i)
{
	glLineWidth(2);
	if (!spray[i].started) {
		if (sprayCounter == spray[i].startTime) {
			spray[i].started = true;
		}
	}
	if (spray[i].started)
	{
		glColor4f(fr, fg, fb, spray[i].alpha);
		circle2(spray[i].radius, spray[i].x, spray[i].y);
		spray[i].x = spray[i].x + (spray[i].xd*spray[i].speed);
		spray[i].y = spray[i].y + (spray[i].yd*spray[i].speed);
		spray[i].yd = spray[i].yd + gy;
		normalise(i);
		spray[i].alpha -= 0;
	}
	if (spray[i].x<0 || spray[i].x>1350 + 500 || spray[i].y<0 || spray[i].y>650)
	{
		spray[i].x = spray[i].startx; spray[i].y = spray[i].starty;
		spray[i].xd = spray[i].startxd; spray[i].yd = spray[i].startyd;
		spray[i].alpha = 1.0;
	}
}
void drawspray()
{
	for (int i = 0; i < SPRAYSIZE; i++)
	{
		drawsprayParticle(i);
	}
	sprayCounter++;
}
void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(7, Timer, value);
}
void visibility(int state)
{
	switch (state) {
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default: break;
	}
}
void init() {
	glClearColor(0.47, 0.67, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1350, 0, 650);
}
void drawPerson() {

	glColor3f(0.0, 0.0, 0.0);

	HipPivot();
	bodyMain();

	head();

	armPivot1();
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(-15, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(-10, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	rightArm1();
	rightArmPivot();
	rightArm2();
	rightHand();
	glPopMatrix();

	leftArm1();
	leftArmPivot();
	leftArm2();
	leftHand();
	glPushMatrix();
	glColor3f(0.267, 0.267, 0.267);
	sword();
	glPopMatrix();
	glPopMatrix();

}
void transformBody() {
	
	glTranslatef(xA, -25, 0);
	xA = xA + 1;
}
void transformUpperArm(){
	glTranslatef(165, 330, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-165, -330, 0);
}
void moveBody() {
	transformBody();
	drawPerson();
}
void moveLegs() {
	transformBody();
	glTranslatef(65, 200, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-65, -200, 0);
}
void moveLegs2() {
	transformBody();
	glTranslatef(65, 200, 0);
	glRotatef(theta2, 0, 0, 1);
	glTranslatef(-65, -200, 0);
}
void personRun() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	moveLegs();
	leftLeg1();
	leftLegPivot();
	leftLeg2();
	glPopMatrix();
}
void personRun2() {
	glPushMatrix();
	moveLegs2();
	glPushMatrix();
	glTranslatef(65, 100, 0);
	glRotatef(-90, 0, 0, 1);
	glTranslatef(-65, -100, 0);
	rightLeg();
	glPopMatrix();
	rightLegPivot();
	rightLeg2();
	glPopMatrix();
}
void runD1() {
	theta = theta - 1;
	personRun();
}
void runD2() {
	theta = theta + 1;
	personRun();
}
void runR1() {
	theta2 = theta2 - 1;
	personRun2();
}
void runR2() {
	theta2 = theta2 + 1;
	personRun2();
}
void scene1() {
	glPushMatrix();
	moveBody();
	glPopMatrix();

	if (movementCounter > 0 && movementCounter < 100) {
		runD1();
		runR2();
	}
	else if (movementCounter >= 100) {
		runD2();
		runR1();
	}

	if (movementCounter > 200) {
		movementCounter = 0;
	}
}
void backGroundGrass() {
	int G21[] = { 0, 0 };
	int G22[] = { 0, 101 };
	int G23[] = { 1350, 101 };
	int G24[] = { 1350, 0 };

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2iv(G21);
	glVertex2iv(G22);
	glVertex2iv(G23);
	glVertex2iv(G24);
	glEnd();
	int G1[] = { 0, 0 };
	int G2[] = { 0, 100 };
	int G3[] = { 1350, 100 };
	int G4[] = { 1350, 0 };
	glBegin(GL_POLYGON);
	glColor3f(0.47, 1.0, 0.58);
	glVertex2iv(G1);
	glVertex2iv(G2);
	glVertex2iv(G3);
	glVertex2iv(G4);
	glEnd();
}
void drawEnemy() {
	glPushMatrix();
	glTranslatef(1350, 0, 0);
	glScalef(-1, 1, 1);

	EHipPivot();
	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	ErightLeg();
	ErightLegPivot();
	ErightLeg2();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-80, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	EleftLeg1();
	EleftLegPivot();

	glPushMatrix();
	glTranslatef(165, 200, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-165, -200, 0);
	EleftLeg2();
	glPopMatrix();
	glPopMatrix();
	EbodyMain();

	evilSmile();

	EarmPivot1();
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(-60, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glPushMatrix();

	glTranslatef(65, 330, 0);
	glRotatef(throwObject, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	

	glTranslatef(65, 330, 0);
	glRotatef(-10, 0, 0, 1);
	glTranslatef(-65, -330, 0);

	ErightArm1();
	ErightArmPivot();

	glTranslatef(165, 330, 0);
	glRotatef(40, 0, 0, 1);
	glTranslatef(-165, -330, 0);

	ErightArm2();
	ErightHand();

	glPopMatrix();

	EleftArm1();
	EleftArmPivot();
	glTranslatef(165, 330, 0);
	glRotatef(enemyRotate, 0, 0, 1);
	glTranslatef(-165, -330, 0);

	glPushMatrix();

	glTranslatef(165, 330, 0);
	glRotatef(100, 0, 0, 1);
	glTranslatef(-165, -330, 0);
	EleftArm2();
	EleftHand();

	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

}
void moveArms() {
	glPushMatrix();
	glTranslatef(50, 50, 0);
	glRotatef(fallDown, 0, 0, 1);
	glTranslatef(-50, -50, 0);

	glTranslatef(65, 330, 0);
	glRotatef(-15, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(-10, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glColor3f(0.0, 0.0, 0.0);
	rightArm1();
	rightArmPivot();
	rightArm2();
	rightHand();
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	leftArm1();
	leftArmPivot();
	leftArm2();
	leftHand();

	glPushMatrix();
	glColor3f(0.267, 0.267, 0.267);
	sword();
	glPopMatrix();
	glPopMatrix();
}
void drawPerson2() {
	glPushMatrix();
	glTranslatef(50, 50, 0);
	glRotatef(fallDown, 0, 0, 1);
	glTranslatef(-50, -50, 0);

	glColor3f(0.0, 0.0, 0.0);
	HipPivot();
	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	rightLeg();
	rightLegPivot();
	rightLeg2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-80, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	leftLeg1();
	leftLegPivot();

	glPushMatrix();
	glTranslatef(165, 200, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-165, -200, 0);
	leftLeg2();
	glPopMatrix();
	glPopMatrix();
	bodyMain();

	head();

	armPivot1();
	glPopMatrix();
}
void rotateArms() {
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(rotateScene, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	moveArms();
	glPopMatrix();
}
void scene2() {
	if (counter < 1940) {
		drawPerson2();
		rotateArms();
	}
	drawEnemy();
	if (counter > 700 && counter < 915) {
		rotateScene = rotateScene - 0.2;
	}
	if (counter > 915 && counter < 1750) {
		eyesAlert();
	}
	if (counter > 1015 && counter < 1200) {
		thoughtBubbles1();
		
	}
	if (counter > 1065 && counter < 1200) {
		thoughtBubbles2();

	}
	if (counter > 1115 && counter < 1200) {
		thoughtBubbles3();
	}
	if (counter > 1165  && counter < 1200) {
		drawAlert();
	}
	if (counter > 1165 && counter < 1250) {
		mouth();
	}

	if (counter > 1200 && counter < 1415) {
		rotateScene = rotateScene + 0.2;
	}

	if (counter > 1200 && counter < 1250) {
		enemyRotate = enemyRotate + 1;
	}
	if (counter > 1250 && counter < 1300) {
		enemyRotate = enemyRotate - 1;
	}
	if (counter > 1300 && counter < 1350) {
		enemyRotate = enemyRotate + 1;
	}
	if (counter > 1350 && counter < 1400) {
		enemyRotate = enemyRotate - 1;
	}
	if (counter > 1400 && counter < 1450) {
		enemyRotate = enemyRotate + 1;
	}
	if (counter > 1450 && counter < 1500) {
		enemyRotate = enemyRotate - 1;
	}
	if (counter > 1500 && counter < 1550) {
		throwObject = throwObject - 1;
	}
	if (counter > 1550  && counter < 1590) {

		throwObject = throwObject + 2;
		glPushMatrix();
		glTranslatef(1285, 330, 0);
		glRotatef(-(throwObject + 50), 0, 0, 1);
		glTranslatef(-1285, -330, 0);
		brick();
		glPopMatrix();
	}
	if (counter > 1590  && counter < 1630) {
		glPushMatrix();
		glTranslatef(-210,210, 0);
		glTranslatef(0, above, 0);
		brick2();
		glPopMatrix();
		above = above + 10;
	}
	if (counter > 1610 && counter < 1640) {
		throwObject = throwObject - 1;
	}
	if (counter > 1680 && counter < 1900) {
		glPushMatrix();
		glTranslatef(-1250, 700, 0);
		glTranslatef(0, above, 0);
		brick2();
		glPopMatrix();
		above = above - 15;
	}
	if(counter > 1760 && counter < 1910){
		drawPerson2();
		moveArms();
		fallDown = fallDown - 0.5;
	}

}
void drawEnemySleep() {
	glPushMatrix();
	glColor3f(0.34, 0.0, 0.0);

	enemyShin();
	enemyLegPiviot();
	enemyLeg();
	enemyHipPiviot();
	enemyBody();
	enemyArm();

	glPushMatrix();
	glTranslatef(0, headFall, 0);
	enemyHead();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glColor3f(0.66, 0.35, 0.16);

	chair();
	chair2();

	glPopMatrix();
}
void personFinal() {
	glPushMatrix();
	glTranslatef(moveWhole, 0, 0);
	glColor3f(0.0, 0.0, 0.0);
	HipPivot();
	
	bodyMain();

	head();

	armPivot1();
	glPopMatrix();
}
void moveRightLeg() {
	glPushMatrix();
	glTranslatef(moveWhole, 0, 0);
	glTranslatef(65, 200, 0);
	glRotatef(moveRight, 0, 0, 1);
	glTranslatef(-65, -200, 0);


	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	rightLeg();
	rightLegPivot();
	rightLeg2();
	glPopMatrix();

	glPopMatrix();
}
void moveLeftLeg() {
	glPushMatrix();
	glTranslatef(moveWhole, 0, 0);

	glTranslatef(65, 200, 0);
	glRotatef(moveLeft, 0, 0, 1);
	glTranslatef(-65, -200, 0);

	glPushMatrix();
	glTranslatef(65, 200, 0);
	glRotatef(-80, 0, 0, 1);
	glTranslatef(-65, -200, 0);
	leftLeg1();
	leftLegPivot();

	glPushMatrix();
	glTranslatef(165, 200, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(-165, -200, 0);
	leftLeg2();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void moveArms2() {
	glPushMatrix();
	glTranslatef(moveWhole, 0, 0);
	glTranslatef(65, 330, 0);
	glRotatef(cut, 0, 0, 1);
	glTranslatef(-65, -330, 0);


	glTranslatef(65, 330, 0);
	glRotatef(-15, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glPushMatrix();
	glTranslatef(65, 330, 0);
	glRotatef(-10, 0, 0, 1);
	glTranslatef(-65, -330, 0);
	glColor3f(0.0, 0.0, 0.0);
	rightArm1();
	rightArmPivot();
	rightArm2();
	rightHand();
	glPopMatrix();
	glColor3f(0.0, 0.0, 0.0);
	leftArm1();
	leftArmPivot();
	leftArm2();
	leftHand();

	glPushMatrix();
	glColor3f(0.267, 0.267, 0.267);
	sword();
	glPopMatrix();
	glPopMatrix();
}
void scene3() {
	drawEnemySleep();
	personFinal();
	moveRightLeg();
	moveLeftLeg();
	moveArms2();
	
	if (counter > 2110 && counter < 3325) {
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Z');
		glRasterPos2f(760, 350);
	}
	if (counter > 2410 && counter < 3325) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Z');
		glRasterPos2f(780, 350);
	}
	if (counter > 2510 && counter < 3325) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Z');
		glRasterPos2f(800, 350);
	}
	if (counter > 2710 && counter < 3325) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Z');
		glRasterPos2f(820, 350);
	}
	if(counter > 2110 && counter < 2300){
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 2300 && counter < 2500) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 2500 && counter < 2700) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 2700 && counter < 2900) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 2900 && counter < 3100) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 3100 && counter < 3200) {
		cut = cut + 1;
	}
	if (counter > 3300 && counter < 3325) {
		cut = cut - 4;
	}
	if (counter > 3400 && counter < 3600) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 3600 && counter < 3800) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 3800 && counter < 4000) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4000 && counter < 4200) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4200 && counter < 4400) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4400 && counter < 4600) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4600 && counter < 4800) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4800 && counter < 5000) {
		moveRight = moveRight + 0.1;
		moveLeft = moveLeft - 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 5000 && counter < 5200) {
		moveRight = moveRight - 0.1;
		moveLeft = moveLeft + 0.1;
		moveWhole = moveWhole + 0.5;
	}
	if (counter > 4100 && counter < 4150) {
		headFall = headFall - 3;
	}
	if (counter > 4100) {
		drawspray();
	}
	
}
void rolling() {
	glPushMatrix();
	glTranslatef(rollingHeadMove, 0, 0);
	glColor3f(0.34, 0.0, 0.0);
	glTranslatef(1250, 100, 0);
	glRotatef(rollingHead, 0,0,1);
	glTranslatef(-1250, -100, 0);
	headRoll();
	glPushMatrix();
	glColor3f(c1, c2, c3);
	deadSmile();
	glPopMatrix();

	glPopMatrix();

}
void scene4() {
	rolling();
	if (counter > 6000 && counter < 7050) {
		rollingHead = rollingHead + 1;
		rollingHeadMove = rollingHeadMove - 1;
	}
	if (counter > 7050 && counter < 7170) {
		glScalef(1.01, 1.01, 1);
	}
	if (counter > 7170) {
		c1 = 1;
		c2 = 1;
		c3 = 1;
	}
	
}
void randomCube(float point)
{
	glBegin(GL_QUADS);
	// front face
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(point / 2, point / 2, point / 2);
	glVertex3f(-point / 2, point / 2, point / 2);
	glVertex3f(-point / 2, -point / 2, point / 2);
	glVertex3f(point / 2, -point / 2, point / 2);
	// left face
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-point / 2, point / 2, point / 2);
	glVertex3f(-point / 2, -point / 2, point / 2);
	glVertex3f(-point / 2, -point / 2, -point / 2);
	glVertex3f(-point / 2, point / 2, -point / 2);
	// back face
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(point / 2, point / 2, -point / 2);
	glVertex3f(-point / 2, point / 2, -point / 2);
	glVertex3f(-point / 2, -point / 2, -point / 2);
	glVertex3f(point / 2, -point / 2, -point / 2);
	// right face
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(point / 2, point / 2, point / 2);
	glVertex3f(point / 2, -point / 2, point / 2);
	glVertex3f(point / 2, -point / 2, -point / 2);
	glVertex3f(point / 2, point / 2, -point / 2);
	// top face
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(point / 2, point / 2, point / 2);
	glVertex3f(-point / 2, point / 2, point / 2);
	glVertex3f(-point / 2, point / 2, -point / 2);
	glVertex3f(point / 2, point / 2, -point / 2);
	// bottom face
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(point / 2, -point / 2, point / 2);
	glVertex3f(-point / 2, -point / 2, point / 2);
	glVertex3f(-point / 2, -point / 2, -point / 2);
	glVertex3f(point / 2, -point / 2, -point / 2);
	glEnd();
}

void random3D()
{
	float front1[] = { -0.5, -0.5, 0.5 };
	float front2[] = { 0.5, -0.5, 0.5 };
	float front3[] = { 0, 0.5, 0 };

	float back1[] = { -0.5, -0.5, -0.5 };
	float back2[] = { 0.5, -0.5, -0.5 };
	float back3[] = { 0, 0.5, 0 };

	float right1[] = { 0.5, -0.5, -0.5 };
	float right2[] = { 0.5, -0.5, 0.5 };
	float right3[] = { 0, 0.5, 0 };

	float left1[] = { -0.5, -0.5,-0.5 };
	float left2[] = { -0.5, -0.5, 0.5 };
	float left3[] = { 0, 0.5, 0 };

	float bottom1[] = { -0.5, -0.5, 0.5 };
	float bottom2[] = { 0.5, -0.5, 0.5 };
	float bottom3[] = { 0.5, -0.5, -0.5 };
	float bottom4[] = {- 0.5, -0.5, -0.5 };
	

	glBegin(GL_POLYGON);

	glColor3f(1, 0.88, 0.29);
	glVertex3fv(front1);
	glVertex3fv(front2);
	glVertex3fv(front3);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.85, 0.74, 0.2);
	glVertex3fv(back1);
	glVertex3fv(back2);
	glVertex3fv(back3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.92, 0.76, 0.04);
	glVertex3fv(right1);
	glVertex3fv(right2);
	glVertex3fv(right3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0.82, 0);
	glVertex3fv(left1);
	glVertex3fv(left2);
	glVertex3fv(left3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.55, 0.46, 0.05);
	glVertex3fv(bottom1);
	glVertex3fv(bottom2);
	glVertex3fv(bottom3);
	glVertex3fv(bottom4);
	glEnd();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.47, 0.67, 1, 0.0);
	glLineWidth(3.0);
	
	if (counter < 0) {
		glClearColor(0, 0, 0, 0.0);
		pegi18();
	}

	if (counter > 0 && counter < 460) {
		drawSNOW();
		backGroundGrass();
		movementCounter++;
		scene1();
	}
	if (counter > 460 && counter < 660) {
		drawWait();
	}
	if (counter > 660 && counter < 1910) {
		drawSNOW();
		backGroundGrass();
		scene2();
	}
	if (counter > 1910 && counter < 2110) {
		epilogue();
	}
	if (counter > 2110 && counter < 5300) {
		glClearColor(0.29, 0.34, 0.49, 0.0);
		drawSNOW();
		backGroundGrass();
		scene3();
	}
	if(counter > 5300 && counter < 6000){
		glClearColor(0.39, 0.41, 0.44, 0);
		advert();
	}
	if (counter > 6000 && counter < 7450) {

		glClearColor(0.29, 0.34, 0.49, 0.0);
		drawSNOW();
		backGroundGrass();
		scene4();
	}
	if (counter == 7450) {
		glClearColor(0, 0, 0, 0);
		glScalef(1, 1, 1);
	}
	if (counter > 7450) {
		
		glClearColor(0, 0, 0, 0);
		glEnable(GL_DEPTH_TEST);
		glLoadIdentity();
		glPushMatrix();
		glRotatef(xRC, xRC, xRC, 0);
		glViewport(1350 / 2, 0, 1350 / 2, 650);
		random3D();
		glPopMatrix();

		glRotatef(xRC, xRC, xRC, 0);
		glViewport(0, 0, 1350 / 2, 650);
		randomCube(1);

		xRC++;
	}
	glutSwapBuffers();
	glFlush();
	counter++;
}

int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_DOUBLE);
	srand((unsigned)time(&t));
	initSNOW();
	initspray();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1350, 650);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Coursework 1");
	init();
	glutDisplayFunc(display);
	glLineWidth(1.0);
	glutVisibilityFunc(visibility);
	glutMainLoop();

	return 0;
}
