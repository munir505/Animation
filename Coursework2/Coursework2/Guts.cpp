#include "stdafx.h"
#include <stdio.h>
#include "glut.h"
#include <math.h>

void circle(double radius, double xc, double yc)
{
	int i;
	double angle = 2 * 3.1415 / 50;
	double x, y;

	glBegin(GL_POLYGON);

	for (i = 0; i < 50; i++)
	{
		x = radius * cos(i *angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}

	glEnd();
}
void rightLeg() {
	int L1[] = { 50 , 0 };
	int L2[] = { 85 , 0 };
	int L3[] = { 85 , 20 };
	int L4[] = { 80 , 20 };
	int L5[] = { 80 , 100 };
	int L6[] = { 50 , 100 };
	int L7[] = { 50 , 0 };

	
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	
	glVertex2iv(L1);
	glVertex2iv(L2);
	glVertex2iv(L3);
	glVertex2iv(L4);
	glVertex2iv(L5);
	glVertex2iv(L6);
	glVertex2iv(L7);

	glEnd();
}
void rightLegPivot()
{
	circle(15.0, 65, 100);
}
void rightLeg2() {
	
	int RL1[] = { 50 , 100 };
	int RL2[] = { 80 , 100 };
	int RL3[] = { 80 , 200 };
	int RL4[] = { 50 , 200 };
	int RL5[] = { 50 , 100 };
	
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(RL1);
	glVertex2iv(RL2);
	glVertex2iv(RL3);
	glVertex2iv(RL4);
	glVertex2iv(RL5);

	glEnd();
}
void HipPivot()
{
	circle(15.0, 65, 200);
}
void leftLeg1() {

	int LL1[] = { 65 , 185 };
	int LL2[] = { 165 , 185 };
	int LL3[] = { 165 , 215 };
	int LL4[] = { 65 , 215 };
	int LL5[] = { 65 , 185 };

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(LL1);
	glVertex2iv(LL2);
	glVertex2iv(LL3);
	glVertex2iv(LL4);
	glVertex2iv(LL5);

	glEnd();

}
void leftLegPivot()
{
	circle(15.0, 165, 200);
}
void leftLeg2() {
	
	int LL1[] = { 150 , 90 };
	int LL2[] = { 185 , 90 };
	int LL3[] = { 185 , 110 };
	int LL4[] = { 180 , 110 };
	int LL5[] = { 180 , 200 };
	int LL6[] = { 150 , 200 };
	int LL7[] = { 150 , 90 };
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(LL1);
	glVertex2iv(LL2);
	glVertex2iv(LL3);
	glVertex2iv(LL4);
	glVertex2iv(LL5);
	glVertex2iv(LL6);
	glVertex2iv(LL7);

	glEnd();
	

}
void bodyMain() {

	int B1[] = { 50 , 200 };
	int B2[] = { 80 , 200 };
	int B3[] = { 80 , 340 };
	int B4[] = { 50 , 340 };
	int B5[] = { 50 , 200 };

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(B1);
	glVertex2iv(B2);
	glVertex2iv(B3);
	glVertex2iv(B4);
	glVertex2iv(B5);

	glEnd();

}
void head() {
	circle(30, 65, 370);
}

void armPivot1()
{
	circle(10.0, 65, 330);
}
void rightArm1() {
	int A1[] = { 65 , 320 };
	int A2[] = { 165 , 320 };
	int A3[] = { 165 , 340 };
	int A4[] = { 65 , 340 };
	int A5[] = { 65 , 320 };
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();
}
void rightArmPivot()
{
	circle(10.0, 165, 330);
}
void rightArm2() {
	int A1[] = { 165, 320 };
	int A2[] = { 265, 320 };
	int A3[] = { 265, 340 };
	int A4[] = { 165, 340 };
	int A5[] = { 165, 320 };
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();
}
void rightHand()
{
	circle(10.0, 275, 330);
}
void leftArm1() {

	int A1[] = { 65 , 320 };
	int A2[] = { 165 , 320 };
	int A3[] = { 165 , 340 };
	int A4[] = { 65 , 340 };
	int A5[] = { 65 , 320 };

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();

}
void leftArmPivot()
{
	circle(10.0, 165, 330);
}
void leftArm2() {

	int A1[] = { 165, 320 };
	int A2[] = { 265, 320 };
	int A3[] = { 265, 340 };
	int A4[] = { 165, 340 };
	int A5[] = { 165, 320 };

	glBegin(GL_POLYGON);
	//glColor3f(0.0, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();

}
void leftHand()
{
	circle(10.0, 275, 330);
}
void sword() {

	int S1[] = { 270, 350 };
	int S2[] = { 280, 350 };
	int S3[] = { 280, 260 };
	int S4[] = { 270, 260 };
	int S5[] = { 270, 350 };
	int S6[] = { 245, 350 };
	int S7[] = { 245, 600 };
	int S8[] = { 275, 650 };
	int S9[] = { 305, 600 };
	int S10[] = { 305, 350 };
	int S11[] = { 270, 350 };

	glBegin(GL_POLYGON);

	

	glVertex2iv(S1);
	glVertex2iv(S2);
	glVertex2iv(S3);
	glVertex2iv(S4);
	glVertex2iv(S5);
	glVertex2iv(S6);
	glVertex2iv(S7);
	glVertex2iv(S8);
	glVertex2iv(S9);
	glVertex2iv(S10);
	glVertex2iv(S11);

	glEnd();

}
void evilSmile() {
	//glColor3f(0.34, 0.0, 0.0);
	circle(30, 65, 370);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	int ES1[] = { 65 , 370 };
	int ES2[] = { 94 , 360 };
	int ES3[] = { 89 , 350 };
	int ES4[] = { 65 , 370 };
	glBegin(GL_POLYGON);
	glVertex2iv(ES1);
	glVertex2iv(ES2);
	glVertex2iv(ES3);
	glVertex2iv(ES4);
	glEnd();
	glPopMatrix();
}

void ErightLeg() {
	int L1[] = { 50 , 0 };
	int L2[] = { 85 , 0 };
	int L3[] = { 85 , 20 };
	int L4[] = { 80 , 20 };
	int L5[] = { 80 , 100 };
	int L6[] = { 50 , 100 };
	int L7[] = { 50 , 0 };


	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);

	glVertex2iv(L1);
	glVertex2iv(L2);
	glVertex2iv(L3);
	glVertex2iv(L4);
	glVertex2iv(L5);
	glVertex2iv(L6);
	glVertex2iv(L7);

	glEnd();
}
void ErightLegPivot()
{
	circle(15.0, 65, 100);
}
void ErightLeg2() {

	int RL1[] = { 50 , 100 };
	int RL2[] = { 80 , 100 };
	int RL3[] = { 80 , 200 };
	int RL4[] = { 50 , 200 };
	int RL5[] = { 50 , 100 };

	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(RL1);
	glVertex2iv(RL2);
	glVertex2iv(RL3);
	glVertex2iv(RL4);
	glVertex2iv(RL5);

	glEnd();
}
void EHipPivot()
{
	circle(15.0, 65, 200);
}
void EleftLeg1() {

	int LL1[] = { 65 , 185 };
	int LL2[] = { 165 , 185 };
	int LL3[] = { 165 , 215 };
	int LL4[] = { 65 , 215 };
	int LL5[] = { 65 , 185 };

	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(LL1);
	glVertex2iv(LL2);
	glVertex2iv(LL3);
	glVertex2iv(LL4);
	glVertex2iv(LL5);

	glEnd();

}
void EleftLegPivot()
{
	glColor3f(0.34, 0.0, 0.0);
	circle(15.0, 165, 200);
}
void EleftLeg2() {

	int LL1[] = { 150 , 90 };
	int LL2[] = { 185 , 90 };
	int LL3[] = { 185 , 110 };
	int LL4[] = { 180 , 110 };
	int LL5[] = { 180 , 200 };
	int LL6[] = { 150 , 200 };
	int LL7[] = { 150 , 90 };
	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(LL1);
	glVertex2iv(LL2);
	glVertex2iv(LL3);
	glVertex2iv(LL4);
	glVertex2iv(LL5);
	glVertex2iv(LL6);
	glVertex2iv(LL7);

	glEnd();


}
void EbodyMain() {

	int B1[] = { 50 , 200 };
	int B2[] = { 80 , 200 };
	int B3[] = { 80 , 340 };
	int B4[] = { 50 , 340 };
	int B5[] = { 50 , 200 };

	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(B1);
	glVertex2iv(B2);
	glVertex2iv(B3);
	glVertex2iv(B4);
	glVertex2iv(B5);

	glEnd();

}

void EarmPivot1()
{
	glColor3f(0.34, 0.0, 0.0);
	circle(10.0, 65, 330);
}
void ErightArm1() {
	int A1[] = { 65 , 320 };
	int A2[] = { 165 , 320 };
	int A3[] = { 165 , 340 };
	int A4[] = { 65 , 340 };
	int A5[] = { 65 , 320 };
	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();
}
void ErightArmPivot()
{
	circle(10.0, 165, 330);
}
void ErightArm2() {
	int A1[] = { 165, 320 };
	int A2[] = { 265, 320 };
	int A3[] = { 265, 340 };
	int A4[] = { 165, 340 };
	int A5[] = { 165, 320 };
	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();
}
void ErightHand()
{
	circle(10.0, 275, 330);
}
void EleftArm1() {

	int A1[] = { 65 , 320 };
	int A2[] = { 165 , 320 };
	int A3[] = { 165 , 340 };
	int A4[] = { 65 , 340 };
	int A5[] = { 65 , 320 };

	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();

}
void EleftArmPivot()
{
	circle(10.0, 165, 330);
}
void EleftArm2() {

	int A1[] = { 165, 320 };
	int A2[] = { 265, 320 };
	int A3[] = { 265, 340 };
	int A4[] = { 165, 340 };
	int A5[] = { 165, 320 };

	glBegin(GL_POLYGON);
	glColor3f(0.34, 0.0, 0.0);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);

	glEnd();

}
void EleftHand()
{
	circle(10.0, 275, 330);
}

void drawAlert() {
	int AL1[] = { 290 , 435 };
	int AL2[] = { 290 , 455 };
	int AL3[] = { 310 , 455 };
	int AL4[] = { 310 , 435 };
	int AL5[] = { 290 , 435 };
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2iv(AL1);
	glVertex2iv(AL2);
	glVertex2iv(AL3);
	glVertex2iv(AL4);
	glVertex2iv(AL5);
	glEnd();

	int AL21[] = { 290 , 465 };
	int AL22[] = { 290 , 565 };
	int AL23[] = { 310 , 565 };
	int AL24[] = { 310 , 465 };
	int AL25[] = { 290 , 465 };
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2iv(AL21);
	glVertex2iv(AL22);
	glVertex2iv(AL23);
	glVertex2iv(AL24);
	glVertex2iv(AL25);
	glEnd();
}


void eyesAlert() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(5, 85, 380);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(2, 88, 380);
	glPopMatrix();
}

void thoughtBubbles1() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(11, 130, 400);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(10, 130, 400);
	glPopMatrix();
}
void thoughtBubbles2() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(16, 160, 420);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(15, 160, 420);
	glPopMatrix();
}
void thoughtBubbles3() {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(101, 300, 500);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(100, 300, 500);
	glPopMatrix();
}
void mouth() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(10, 85, 360);
	glPopMatrix();
}
void drawWait() {
	glPushMatrix();
	glClearColor(0.96, 0.85, 0.26, 0.0);
	glColor3f(0.15, 0.47, 1.0);
	glLineWidth(30.0);

	glPushMatrix();
	glTranslatef(50, 480, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'O');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200, 480, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'N');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 480, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(250, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'H');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'O');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(550, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'U');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(700, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'R');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(600, 120, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'L');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(750, 120, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'A');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900, 120, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'T');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1050, 120, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1200, 120, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'R');
	glPopMatrix();

	glPopMatrix();
}
void brick() {
	//65 200
	int BR1[] = { 1290 , 130};
	int BR2[] = { 1290 , 150 };
	int BR3[] = { 1330 , 150 };
	int BR4[] = { 1330 , 130 };
	int BR5[] = { 1290 , 130 };
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.54, 0.21);
	glVertex2iv(BR1);
	glVertex2iv(BR2);
	glVertex2iv(BR3);
	glVertex2iv(BR4);
	glVertex2iv(BR5);
	glEnd();
}

void brick2() {
	//65 200
	
	int BR1[] = { 1290 , 130 };
	int BR2[] = { 1290 , 150 };
	int BR3[] = { 1330 , 150 };
	int BR4[] = { 1330 , 130 };
	int BR5[] = { 1290 , 130 };
	glTranslatef(1310, 140, 0);
	glRotatef(80, 0, 0, 1);
	glTranslatef(-1310, -140, 0);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.54, 0.21);
	glVertex2iv(BR1);
	glVertex2iv(BR2);
	glVertex2iv(BR3);
	glVertex2iv(BR4);
	glVertex2iv(BR5);
	glEnd();
}
void epilogue() {
	glPushMatrix();
	glClearColor(0.35, 0.78, 0.24, 0.0);
	glColor3f(0.94, 0.16, 1.0);
	glLineWidth(30.0);

	glPushMatrix();
	glTranslatef(80, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(230, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'P');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(380, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'i');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(530, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'L');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(680, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'O');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(830, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'G');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(980, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'U');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1130, 300, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPopMatrix();
}

void enemyShin() {
	int S1[] = { 680 , 20 };
	int S2[] = { 680 , 30 };
	int S3[] = { 720 , 30 };
	int S4[] = { 720 , 20 };
	int S5[] = { 680 , 20 };
	glBegin(GL_POLYGON);
	glVertex2iv(S1);
	glVertex2iv(S2);
	glVertex2iv(S3);
	glVertex2iv(S4);
	glVertex2iv(S5);
	glEnd();

	int E1[] = { 690 , 20 };
	int E2[] = { 690 , 120 };
	int E3[] = { 720 , 120 };
	int E4[] = { 720 , 20 };
	int E5[] = { 690 , 20 };
	glBegin(GL_POLYGON);
	glVertex2iv(E1);
	glVertex2iv(E2);
	glVertex2iv(E3);
	glVertex2iv(E4);
	glVertex2iv(E5);
	glEnd();

}
void enemyLegPiviot() {
	circle(15, 705, 120);
}
void enemyLeg() {
	int L1[] = { 705 , 105 };
	int L2[] = { 705 , 135 };
	int L3[] = { 805 , 135 };
	int L4[] = { 805 , 105 };
	int L5[] = { 705 , 105 };
	glBegin(GL_POLYGON);
	glVertex2iv(L1);
	glVertex2iv(L2);
	glVertex2iv(L3);
	glVertex2iv(L4);
	glVertex2iv(L5);
	glEnd();
}
void enemyHipPiviot() {
	circle(15, 805, 120);
}
void enemyBody() {
	int B1[] = { 790 , 120 };
	int B2[] = { 790 , 270 };
	int B3[] = { 820 , 270 };
	int B4[] = { 820 , 120 };
	int B5[] = { 790 , 120 };
	glBegin(GL_POLYGON);
	glVertex2iv(B1);
	glVertex2iv(B2);
	glVertex2iv(B3);
	glVertex2iv(B4);
	glVertex2iv(B5);
	glEnd();
}
void enemyArm() {
	int A1[] = { 790 , 260 };
	int A2[] = { 690 , 120 };
	int A3[] = { 720 , 120 };
	int A4[] = { 820 , 260 };
	int A5[] = { 790 , 260 };
	glBegin(GL_POLYGON);
	glVertex2iv(A1);
	glVertex2iv(A2);
	glVertex2iv(A3);
	glVertex2iv(A4);
	glVertex2iv(A5);
	glEnd();
}
void enemyHead() {
	circle(30, 790, 290);
}

void chair() {
	int C1[] = { 730 , 20 };
	int C2[] = { 740 , 20 };
	int C3[] = { 740 , 105 };
	int C4[] = { 730 , 105 };
	int C5[] = { 730 , 20 };
	glBegin(GL_POLYGON);
	glVertex2iv(C1);
	glVertex2iv(C2);
	glVertex2iv(C3);
	glVertex2iv(C4);
	glVertex2iv(C5);
	glEnd();

	int C21[] = { 730 , 105 };
	int C22[] = { 820 , 105 };
	int C23[] = { 820 , 90 };
	int C24[] = { 730 , 90 };
	int C25[] = { 730 , 105 };
	glBegin(GL_POLYGON);
	glVertex2iv(C21);
	glVertex2iv(C22);
	glVertex2iv(C23);
	glVertex2iv(C24);
	glVertex2iv(C25);

	glEnd();
}
void chair2() {
	int BR1[] = { 820 , 20 };
	int BR2[] = { 820 , 250 };
	int BR3[] = { 850 , 250 };
	int BR4[] = { 850 , 20 };
	int BR5[] = { 820 , 20 };
	glBegin(GL_POLYGON);
	glVertex2iv(BR1);
	glVertex2iv(BR2);
	glVertex2iv(BR3);
	glVertex2iv(BR4);
	glVertex2iv(BR5);
	glEnd();
}

void randomSword() {
	int RS1[] = { 820 , 20 };
	int RS2[] = { 820 , 250 };
	int RS3[] = { 850 , 250 };
	int RS4[] = { 850 , 20 };
	int RS5[] = { 820 , 20 };
	glBegin(GL_POLYGON);
	glVertex2iv(RS1);
	glVertex2iv(RS2);
	glVertex2iv(RS3);
	glVertex2iv(RS4);
	glVertex2iv(RS5);
	glEnd();
}

void advert() {
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.94, 0.16, 1.0);
	glLineWidth(20.0);

	glPushMatrix();
	glTranslatef(150, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'C');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(250, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'O');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'M');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(450, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'P');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(550, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'L');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(650, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(750, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'T');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(850, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'E');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(950, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'L');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1050, 500, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'Y');
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.94, 0.16, 1.0);
	glLineWidth(30.0);

	glPushMatrix();
	glColor3f(0.80, 0.80, 0.80);
	glTranslatef(200, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'R');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'A');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(500, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'N');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(650, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'D');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(800, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'O');
	glPopMatrix();

	glPushMatrix();
	glTranslatef(950, 350, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'M');
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glRasterPos2f(550, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2f(570, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glRasterPos2f(590, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	
	glRasterPos2f(630, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
	glRasterPos2f(650, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glRasterPos2f(670, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');
	glRasterPos2f(690, 250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	

	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glRasterPos2f(549, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2f(569, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
	glRasterPos2f(589, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');

	glRasterPos2f(629, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
	glRasterPos2f(649, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glRasterPos2f(669, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');
	glRasterPos2f(689, 249);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');


	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRasterPos2f(200, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
	glRasterPos2f(220, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');
	glRasterPos2f(240, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
	
	glRasterPos2f(280, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glRasterPos2f(300, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glRasterPos2f(320, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'W');

	glRasterPos2f(360, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2f(380, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');

	glRasterPos2f(420, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
	glRasterPos2f(440, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glRasterPos2f(460, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');

	glRasterPos2f(500, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
	glRasterPos2f(520, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glRasterPos2f(540, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glRasterPos2f(560, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
	glRasterPos2f(580, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glRasterPos2f(600, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');

	glRasterPos2f(640, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
	glRasterPos2f(660, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');

	glRasterPos2f(700, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
	glRasterPos2f(720, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');
	glRasterPos2f(740, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
	glRasterPos2f(760, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');

	glRasterPos2f(800, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
	glRasterPos2f(820, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glRasterPos2f(840, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');

	glRasterPos2f(880, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glRasterPos2f(900, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'X');
	glRasterPos2f(920, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
	glRasterPos2f(940, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glRasterPos2f(960, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glRasterPos2f(980, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
	glRasterPos2f(1000, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'I');
	glRasterPos2f(1020, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glRasterPos2f(1040, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');

	glRasterPos2f(1080, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '!');
	glRasterPos2f(1100, 50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '!');

	glPopMatrix();

	glPushMatrix();
	glTranslatef(400, 100, 0);
	glColor3f(0.66, 0.35, 0.16);
	chair();
	chair2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.70, 0.70, 0.70);
	glRotatef(45, 0, 0, 0);
	glTranslatef(-100, -100, 0);
	sword();
	glPopMatrix();

	glPopMatrix();
}

void pegi18() {
	glPushMatrix();
	int P1[] = { 475 , 100 };
	int P2[] = { 475 , 550 };
	int P3[] = { 875 , 550 };
	int P4[] = { 875 , 100 };
	int P5[] = { 475 , 100 };
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2iv(P1);
	glVertex2iv(P2);
	glVertex2iv(P3);
	glVertex2iv(P4);
	glVertex2iv(P5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	int PI1[] = { 485 , 540 };
	int PI2[] = { 865 , 540 };
	int PI3[] = { 865 , 200 };
	int PI4[] = { 485 , 200 };
	int PI5[] = { 485 , 540 };
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2iv(PI1);
	glVertex2iv(PI2);
	glVertex2iv(PI3);
	glVertex2iv(PI4);
	glVertex2iv(PI5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(20.0);
	glScalef(2.4,2.4,1);
	glTranslatef(180, 100, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, '1');
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(20.0);
	glScalef(2.4, 2.4, 1);
	glTranslatef(255, 100, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, '8');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(800, 230, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'p');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(900, 220, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'e');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1000, 220, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'g');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1075, 210, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'i');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(5, 700, 130);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1150, 210, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'i');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1210, 210, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'n');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1285, 210, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'f');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glScalef(0.6, 0.6, 1);
	glTranslatef(1350, 210, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'o');
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(825, 515);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2f(840, 515);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');

	glPopMatrix();
}

void headRoll() {
	circle(30, 1250, 100);

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(5, 1227, 100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	circle(2, 1228, 100);
	glPopMatrix();
}

void deadSmile() {
	int ES1[] = { 1250 , 100 };
	int ES2[] = { 1225 , 85 };
	int ES3[] = { 1235 , 75 };
	int ES4[] = { 1250 , 100 };
	glBegin(GL_POLYGON);
	glVertex2iv(ES1);
	glVertex2iv(ES2);
	glVertex2iv(ES3);
	glVertex2iv(ES4);
	glEnd();
}


