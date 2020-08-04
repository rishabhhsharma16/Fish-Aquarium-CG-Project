#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <iostream>
#define DEG2RAD 3.14159 / 180.0

using namespace std;

float x[10],buby[10]= {-.95},bubx=-3.14,r[10],offset[10],pos[10],z[10],yy[10],speed[10],sizee[10],grass[100],ff=-.6,tv[10]= {0};
int dx[10]= {1},bx=1,zx[10],ee[10],fx=1;

float _fish1Xaxis=1.5f;
float _fish1Yaxis=-2.0f;

float _fish2Xaxis=-1.5f;
float _fish2Yaxis=2.8f;

float _fish3Xaxis=-0.1f;
float _fish3Yaxis=-0.7f;

float _fish4Xaxis=0.0f;
float _fish4Yaxis=0.6f;
float angle=0.0;
bool flag=true;
float a=0.8,b=0.8;
float c=0.5,d=0.5;
float e=0.4,f=0.4;
int colors[10][3] = {{50,200 , 10},
    {225, 90, 0},
    {144, 40, 180},
    {219, 10, 91},
    {236,236,236},
    {243, 156, 18},
    {102, 51, 153},
    {224, 130, 131},
    {207, 0, 15},
    {162, 222, 208}
};

void circle(float x, float y, float r);
void DrawEllipse(float x, float y, float radiusX, float radiusY);
void DrawBubble(int i,float t);
void DrawCrab(int,float, float, float);
void Drawcircle(float x, float y, float r,float n,bool f1,bool f2);
void DrawFish(int, int*,float);
void ground();
void DrawTree2();
void init();
void display();

void update(int value) {
    //UPDATING VALUE FOR BLUE ROUND FISH-1
    if(_fish1Xaxis<-2.5){ //X-AXIS
        _fish1Xaxis=1.5f;
    }
    _fish1Xaxis-=0.0045f;

    _fish1Yaxis=sin(_fish1Xaxis+10)+0.00001; //y-AXIS
    if(_fish1Xaxis<0){
        _fish1Yaxis*(-1);
    }

    //UPDATING VALUE FOR RED ROUND FISH-2
    if(_fish2Xaxis>2.1){
        _fish2Xaxis=-2;
    }
    _fish2Xaxis+=0.004f;
    _fish2Yaxis=sin(_fish2Xaxis+.5)-.00001;
    if(_fish2Xaxis<3){
        _fish2Yaxis*=(-1);
    }

    //UPDATING VALUE FOR Yellow FISH-3
    if(_fish3Xaxis<-1.80f){
        _fish3Xaxis=-.1f;
    }
    _fish3Xaxis-=0.0035;
    _fish3Yaxis=sin(_fish3Xaxis+0.1)+.5;

     //UPDATING VALUE FOR Yellow FISH-4
     if(_fish4Xaxis>1.8){
        _fish4Xaxis=0.0;
     }
    _fish4Xaxis+=0.004;

    _fish4Yaxis=sin(_fish4Xaxis+.1)-0.5;

    //UDATING VALUE OF BUBBLE



	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(35, update, 0);
	angle+=0.8;
	if(angle>360.0)
        angle=angle-360.0;

}


static void key( unsigned char key,int x,int y){
switch(key){
case 'i': a+=0.08f;
        b+=0.08f;
        c+=0.05f;
        d+=0.05f;
        e+=0.035f;
        f+=0.035f;
        break;
case 'd': a-=0.08f;
            b-=.08f;
            c-=0.05f;
            d-=.05f;
            e-=0.04f;
            f-=.04f;
            break;


  //   glutDisplayFunc(display);		//inc speed
  //          glutTimerFunc(0, update, 0);

/*
_fish1Xaxis-=0.006f;
_fish2Xaxis+=0.006f;
 _fish3Xaxis-=0.0055f;
 _fish4Xaxis+=0.0055f;
 angle+=1.5;
	if(angle>360.0)
        angle=angle-360.0;
*/

}
}






void DrawFish4() {
 //   a=1.0f,b=1.0f;
    glScalef(a,b,0.0f); //THIS IS TO SCALE THE FISH
    glTranslatef(_fish4Xaxis, _fish4Yaxis, 0.0); //THIS IS TO TRANSLATING THE FISH
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glPushMatrix();

    //fishbody              //purple fish
    if(flag==true)
    glColor3f(0.6, 0.4, 1.0);
    else
       glColor3f(0.2, .75, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.7, -0.05);
    glVertex2f(0.80, -0.1);
    glVertex2f(0.90, -0.05);
    glVertex2f(0.77, 0.0);
    glEnd();

//mouth
    glBegin(GL_TRIANGLES);
    if(flag==true)
        glColor3f(66/255.,161/255.,198/255.);
    else
        glColor3f(66/255.,60/255.,240/255.);
    glVertex2f(0.70,-.080);
    glVertex2f(0.75,-.035);
    glVertex2f(0.7,-.045);
    glEnd();

 //tail
if(flag==true)
        glColor3f(0.5,.5,1.0);
    else
    glColor3f(0.5,.8,1.0);;
    glBegin(GL_TRIANGLES);
    glVertex2f(0.88, -0.052);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.92, -0.09);
    glVertex2f(0.92, -0.01);
    glEnd();
//lowerwing

    glBegin(GL_TRIANGLES);
    glVertex2f(0.84, -0.155);
    if(flag==true)
        glColor3f(0.5,.5,1.0);
    else
    glColor3f(0.5,.8,1.0);
    glVertex2f(0.77, -0.085);
    glVertex2f(0.83, -0.080);
    glEnd();
//upperwing
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.84, 0.060);
    if(flag==true)
        glColor3f(0.5,.5,1.0);
    else
    glColor3f(0.5,.8,1.0);
    glVertex2f(0.77, -0.003);
    glVertex2f(0.83, -0.020);
    glEnd();
//eye
    glPushMatrix();
    glTranslatef(0.760, -0.025, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1., 1.);

    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.009;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    //inner ball
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.004;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    glPopMatrix();

}


void DrawFish3(){
 //   a=1.0f,b=1.0f;
    glScalef(a,b, 0.0f); //THIS IS TO SCALE THE FISH
    glTranslatef(_fish3Xaxis,_fish3Yaxis, 0.0); //THIS IS TO TRANSLATING THE FISH
    glPushMatrix();
//body
if(flag==true)
    glColor3f(1.0,0.58,0.25);
    else
     glColor3f(1.0,0.4,0.25);                              //orange fish
    glBegin(GL_POLYGON);
    glVertex2f(0.70,-0.05);
    glVertex2f(0.80,-0.1);
    glVertex2f(0.89,-0.05);
    glVertex2f(0.79,0.0);
    glEnd();

//mouth
     glBegin(GL_TRIANGLES);
    if(flag==true)
        glColor3f(66/255.,161/255.,198/255.);
    else
        glColor3f(66/255.,60/255.,240/255.);
    glVertex2f(0.73,-0.064);
    glVertex2f(0.76,-0.060);
    glVertex2f(0.74,-0.080);
    glEnd();

//tail
    glColor3f(1.0,0.4,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.88,-0.05);
    glColor3f(1.0,1.0,0);
    glVertex2f(0.92,-0.09);
    glVertex2f(0.92,-0.01);
    glEnd();
//lowerwing
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(0.83,-0.085);
    glColor3f(1.0,0.6,0.2);
    glVertex2f(0.860,-0.14);
    glVertex2f(0.80,-0.100);

    glEnd();
//upperwing
    glColor3f(1.0,0.6,0.2);
    glBegin(GL_TRIANGLES);
	glVertex2f(0.860,0.040);
	glVertex2f(0.79,-0.001);
	glColor3f(1.0,1.0,0.0);
    glVertex2f(0.825,-0.015);
    glEnd();

    //eye
    glPushMatrix();
    glTranslatef(.745, -.040, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);

    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.009;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    //inner ball
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.0040;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    glPopMatrix();



}

void DrawFish2(){
 //   a=0.6f,b=0.6f;
    glScalef(c,d, 0.0f); //THIS IS TO SCALE THE FISH
    glTranslatef(_fish2Xaxis, _fish2Yaxis, 0.0);//THIS IS TO TRANSLATING THE FISH
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glPushMatrix();
    glColor3f(0.6,1.0,0.4);
    //fishTail                          //green fish
      glBegin(GL_POLYGON);
        glVertex3f(0.450, 0.127, 0.0);
         glColor3f(1,0.35,0);
        glVertex3f(0.508, 0.020, 0.0);
        glColor3f(0.6,1.0,0.4);
        glVertex3f(0.500, 0.108, 0.0);
        glVertex3f(0.475, 0.162, 0.0);
        glVertex3f(0.473, 0.148, 0.0);
        glVertex3f(0.495, 0.233, 0.0);
        glVertex3f(0.515, 0.282, 0.0);
        glColor3f(1,0.35,0);
        glVertex3f(0.550, 0.318, 0.0);
        glColor3f(0.6,1.0,0.4);
        glVertex3f(0.451, 0.245, 0.0);
        glEnd();

    //fishWingTOP

    glColor3f(0.6,1.0,0.4);
    glBegin(GL_POLYGON);
    glVertex3f(0.160, 0.304, 0.0);
    glVertex3f(0.177, 0.326, 0.0);
    glVertex3f(0.193, 0.334, 0.0);
    glVertex3f(0.221, 0.346, 0.0);
    glVertex3f(0.224, 0.348, 0.0);
    glVertex3f(0.244, 0.348, 0.0);
    glVertex3f(0.265, 0.345, 0.0);
    glColor3f(1,0.35,0);
    glVertex3f(0.303, 0.333, 0.0);
    glVertex3f(0.276, 0.304, 0.0);
    glEnd();


    //fishBody
    if(flag==true)
    glColor3f(0.4,.8,0.0);
    else
        glColor3f(0.15,.75,0.1);
  glBegin(GL_POLYGON);
    glVertex3f(0.450, 0.190, 0.0);
    glVertex3f(0.350, 0.276, 0.0);
    glVertex3f(0.292, 0.301, 0.0);
    glVertex3f(0.226, 0.316, 0.0);
    glVertex3f(0.200, 0.319, 0.0);
    glVertex3f(0.164, 0.309, 0.0);
    glVertex3f(0.117, 0.288, 0.0);
    glVertex3f(0.077, 0.256, 0.0);
    glVertex3f(0.052, 0.222, 0.0);
    glVertex3f(0.000, 0.187, 0.0);
    glVertex3f(0.041, 0.144, 0.0);
    glVertex3f(0.061, 0.119, 0.0);
    glVertex3f(0.108, 0.083, 0.0);
    glVertex3f(0.168, 0.060, 0.0);
    glVertex3f(0.204, 0.053, 0.0);
    glVertex3f(0.231, 0.054, 0.0);
    glVertex3f(0.288, 0.067, 0.0);
    glVertex3f(0.340, 0.087, 0.0);
    glVertex3f(0.400, 0.115, 0.0);
    glVertex3f(0.450, 0.160, 0.0);
    glEnd();

//fishEye
    glPushMatrix();
    glTranslatef(.1, 0.22, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1., 1.);

	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=0.019;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	//inner ball
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=0.008;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    //FishMouth
    glBegin(GL_TRIANGLES);
  //  glColor3f(0,0,0);
  if(flag==true)
    glColor3f(66/255.,161/255.,198/255.);
    else
     glColor3f(66/255.,60/255.,240/255.);
      glVertex2f(0.1,0.140);
    glVertex2f(0.060,0.115);
    glVertex2f(0.085,0.100);
    glEnd();




    //FihBelowWing
    glColor3f(0.6,1.0,0.4);
    glBegin(GL_POLYGON);
    glVertex3f(0.165, 0.118, 0.0);
    glVertex3f(0.169, 0.098, 0.0);
    glVertex3f(0.182, 0.086, 0.0);
    glVertex3f(0.213, 0.076, 0.0);
    glVertex3f(0.253, 0.075, 0.0);
    glColor3f(1,.35,0);
    glVertex3f(0.281, 0.082, 0.0);
    glVertex3f(0.286, 0.094, 0.0);
    glVertex3f(0.281, 0.102, 0.0);
    glVertex3f(0.267, 0.113, 0.0);
    glEnd();
    glPopMatrix();
}



void DrawFish1(){
 //   a=0.6f,b=0.6f;
    glScalef(c,d, 0.0f); //THIS IS TO SCALE THE FISH
    glTranslatef(_fish1Xaxis,_fish1Yaxis, 0.0); //THIS IS TO TRANSLATING THE FISH
    glPushMatrix();
    if(flag==true)
    glColor3f(1.0,0.5,.6);
    else
        glColor3f(1.0,0.3,.3);

    //fishTail
    glPushMatrix();
	glBegin(GL_POLYGON);			//pink fish
	   glBegin(GL_POLYGON);
        glVertex3f(0.450, 0.127, 0.0);
        glVertex3f(0.508, 0.020, 0.0);
        glVertex3f(0.500, 0.108, 0.0);
        glVertex3f(0.475, 0.162, 0.0);
        glVertex3f(0.473, 0.148, 0.0);
        glVertex3f(0.495, 0.233, 0.0);
        glVertex3f(0.515, 0.282, 0.0);
        glVertex3f(0.550, 0.318, 0.0);
        glVertex3f(0.451, 0.245, 0.0);
        glEnd();



    //fishWingTOP
       glColor3f(1.0,0.5,.6);
        glBegin(GL_POLYGON);
        glVertex3f(0.160, 0.304, 0.0);
        glVertex3f(0.177, 0.326, 0.0);
        glVertex3f(0.193, 0.334, 0.0);
        glVertex3f(0.221, 0.346, 0.0);
        glVertex3f(0.224, 0.348, 0.0);
        glVertex3f(0.244, 0.348, 0.0);
        glVertex3f(0.265, 0.345, 0.0);
        glVertex3f(0.303, 0.333, 0.0);
        glVertex3f(0.276, 0.304, 0.0);
        glEnd();

    //fishBody
    if(flag==true)
    glColor3f(1.0,0.3,.4);
    else
        glColor3f(1.0,0.2,.3);
    glBegin(GL_POLYGON);
    glVertex3f(0.450, 0.180, 0.0);
    glVertex3f(0.350, 0.276, 0.0);
    glVertex3f(0.292, 0.301, 0.0);
    glVertex3f(0.226, 0.316, 0.0);
    glVertex3f(0.200, 0.319, 0.0);
    glVertex3f(0.164, 0.309, 0.0);
    glVertex3f(0.117, 0.288, 0.0);
    glVertex3f(0.077, 0.256, 0.0);
    glVertex3f(0.052, 0.222, 0.0);
    glVertex3f(0.000, 0.187, 0.0);
    glVertex3f(0.041, 0.144, 0.0);
    glVertex3f(0.061, 0.119, 0.0);
    glVertex3f(0.108, 0.083, 0.0);
    glVertex3f(0.168, 0.060, 0.0);
    glVertex3f(0.204, 0.053, 0.0);
    glVertex3f(0.231, 0.054, 0.0);
    glVertex3f(0.288, 0.067, 0.0);
    glVertex3f(0.340, 0.087, 0.0);
    glVertex3f(0.400, 0.115, 0.0);
    glVertex3f(0.450, 0.150, 0.0);
    glEnd();
//mouth
    glBegin(GL_TRIANGLES);
    if(flag==true)
        glColor3f(66/255.,161/255.,198/255.);
    else
        glColor3f(66/255.,60/255.,240/255.);
    glVertex2f(0.095,0.140);
    glVertex2f(0.060,0.110);
    glVertex2f(0.085,0.110);
    glEnd();

//fishEye
    glPushMatrix();
    glTranslatef(.1, 0.22, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1., 1.);

    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.018;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    //inner ball
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/50;
        float r=0.009;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex3f(x,y,0 );
    }
    glEnd();
    glPopMatrix();


    //FishBelowWing
    glColor3f(1.0,0.5,.6);
    glBegin(GL_POLYGON);
    glVertex3f(0.165, 0.118, 0.0);
    glVertex3f(0.169, 0.098, 0.0);
    glVertex3f(0.182, 0.086, 0.0);
    glVertex3f(0.213, 0.076, 0.0);
    glVertex3f(0.253, 0.075, 0.0);
    glVertex3f(0.281, 0.082, 0.0);
    glVertex3f(0.286, 0.094, 0.0);
    glVertex3f(0.281, 0.102, 0.0);
    glVertex3f(0.267, 0.113, 0.0);
    glEnd();
    glPopMatrix();

}

void DrawStar(int k,float x,float y,float sc)
{
    glPushMatrix();
    glTranslatef(x,y,-1.0);
    glScalef(e,f,0);

    glRotatef(angle,0,0,1);

    if(flag==true)
    glColor3f(1,.2,.3);
    else
        glColor3f(1,.35,.45);
//        glColor3f(.8,.8,.8);
    glLineWidth(3);
    glScalef(1,1,1);
    float tt=0;
    {
        glBegin (GL_TRIANGLES);
        glVertex3f(0.0,0.2,tt);
        glVertex3f(0.04,0.08,tt);
        glVertex3f(-0.04,0.08,tt);
        glVertex3f(0.04,0.08,tt);
        glVertex3f(0.17,0.08,tt);
        glVertex3f(0.07,0.0,tt);
        glVertex3f(0.07,0.0,tt);
        glVertex3f(0.12,-.14,tt);
        glVertex3f(0,-.04,tt);
        glVertex3f(0,-.04,tt);
        glVertex3f(-0.12,-.14,tt);
        glVertex3f(-0.06,0,tt);
        glVertex3f(-0.06,0,tt);
        glVertex3f(-0.16,0.08,tt);
        glVertex3f(-0.04,0.08,tt);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0.04,0.08,tt);
        glVertex3f(0.07,0.0,tt);
        glVertex3f(0,-.04,tt);
        glVertex3f(-0.07,0.0,tt);
        glVertex3f(-0.04,0.08,tt);
        glEnd();
    }
    glPopMatrix();

}






void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffe
        if(flag==true)
    glClearColor(66/255.,161/255.,198/255.,1);
    // Black and opaque
    else
            glClearColor(66/255.,60/255.,240/255.,1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glLineWidth(2);

     // ground
 //   ground();

    for(int i=0; i<10; i++)
      DrawBubble(i,pos[i]);



    DrawStar(0,0,.7,.5);


    for(int i=0; i<3; i++)
   //     DrawFish(i,colors[i],sizee[i]);

     glPushMatrix();
    DrawFish3();
    glPopMatrix();


    glPushMatrix();
    DrawFish4();
    glPopMatrix();

    glPushMatrix(); //DRAW FISH
    DrawFish1();
    glPopMatrix();

     glPushMatrix();
   DrawFish2();
    glPopMatrix();


    glPushMatrix();
    DrawTree2();
    glPopMatrix();



    glutPostRedisplay(); // Post a re-paint request to activate display()

    glutSwapBuffers(); // Double buffered - swap the front and back buffers
}
void mymenu(int value){
    if(value==1)
        flag=true;
    else if(value==2)
        flag=false;
    else if(value==3)
        exit(0);

}
int main(int argc, char **argv)
{


    for(int i=0; i<10; i++)
    {
        r[i] = (float)(rand()%4+4)/1000;
        offset[i] = (2*(float)rand()/RAND_MAX)-1;
        pos[i]=2*(float)rand()/RAND_MAX-1;
        yy[i] = (rand()%(9- (-7)+1)+-7)/10.0;
        sizee[i] = (float)(rand()%5)/10+.5;
        speed[i] = (float)(rand()%70)/10000+.001;
        z[i]=0;
        zx[i]=1;
        ee[i] = -10+2*i;//2*(rand()%2)-10; //-10,-8,-6
        x[i] = (2*(float)rand()/RAND_MAX)-1;
        tv[i]=0;

    }


    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE);                // Enable double buffered mode
    glutInitWindowSize(1024, 720);                    // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);                  // Position the window's initial top-left corner
    glutCreateWindow("Fish Aquarium");
    glutCreateMenu(mymenu);
        glutAddMenuEntry("Day Mode",1);
        glutAddMenuEntry("Night Mode",2);
        glutAddMenuEntry("Exit",3);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
     // Create window with the given title
    init();
    glutDisplayFunc(display);
            glutTimerFunc(35, update, 0);
    glutKeyboardFunc(key);                            // Register callback handler for window re-paint event
    glutMainLoop();                                  // Enter the infinite event-processing loop
    //return 0;
}

void ground()
{

    glPushMatrix();
    glTranslatef(0,-.5,0);
    glRotatef(50,1,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_POLYGON);
    glColor3f(255.,161/255.,255.);
    glVertex2d(-1, -0.45);
    glColor3ub(255, 250, 100);
    glVertex2d(-1, -1);
    glVertex2d(1, -1);
    glColor3f(0,255.,255.);
    glVertex2d(1, -0.35);
    glEnd();
    glPopMatrix();
}

void tree2Code(float x){
    glPushMatrix();
    glScalef(0.2f, 0.3f, 0.0f);
    glTranslated(x,-3.75,0.0);
    glColor3f(0.3, 0.0, 0.0);
//timber
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.0, 0.0);
    glVertex3f(0.3, 0.0, 0.0);
    glVertex3f(0.3, 0.35, 0.0);
    glVertex3f(0.2, 0.35, 0.0);
    glVertex3f(0.2, 0.0, 0.0);
    glEnd();
//lowest
if(flag==true)
    glColor3f(0.7,1.0,0.0);
    else
        glColor3f(0.5,1.0,0.2);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.35, 0.0);
    glVertex3f(0.5, 0.35, 0.0);
    glVertex3f(0.40, 0.55, 0.0);
    glVertex3f(0.10, 0.55, 0.0);
    glVertex3f(0.0, 0.35, 0.0);
    glEnd();
//middle
    glBegin(GL_POLYGON);
    glVertex3f(0.05, 0.55, 0.0);
    glVertex3f(0.45, 0.55, 0.0);
    if(flag==true)
    glColor3f(1.0,1.0,0.0);
    else
            glColor3f(0.5,1.0,0.2);
    glVertex3f(0.30, 0.75, 0.0);
    glVertex3f(0.20, 0.75, 0.0);
    if(flag==true)
    glColor3f(1.0,1.0,0.0);
    else
        glColor3f(0.5,1.0,0.2);
    glVertex3f(0.05, 0.55, 0.0);
    glEnd();
//top
         if(flag==true)
    glColor3f(1.0,1.0,0.0);
    else
            glColor3f(0.5,1.0,0.2);
    glBegin(GL_POLYGON);
    glVertex3f(0.19, 0.75, 0.0);
    glVertex3f(0.40, 0.75, 0.0);
    if(flag==true)
    glColor3f(0.4,1.0,0.0);
    else
        glColor3f(0.5,1.0,0.2);
    glVertex3f(0.27, 0.95, 0.0);
    glVertex3f(0.10, 0.75, 0.0);
    glEnd();
    glPopMatrix();
}

void DrawTree2(){
    glPushMatrix();
    for(float f=-5;f<6;f+=1){
        tree2Code(f);
    }
    glPopMatrix();
}




  void circle(float x, float y, float r)
{
    float t;
    for (int i = -1000; i < 1000; i++)
    {
        t = i / 1000.0;
        glVertex2f(t + x, sqrt(r * r - t * t) + y);
        glVertex2f(t + x, -sqrt(r * r - t * t) + y);
    }
}


    void DrawEllipse(float x, float y, float radiusX, float radiusY)
{
    register int i;
    register float rad ;
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++)
    {
        glVertex2f(x + cos(i * DEG2RAD) * radiusX, y + sin(i * DEG2RAD) * radiusY);
    }
    glEnd();
}

    void DrawBubble(int i,float t)
{
    // bubble
    glPushMatrix();
    if (i%2==0)
    {
        if(flag==true)
        glColor4f(1,1,1,.3);
        else
            glColor3f(1.0,1.0,1.0);
        DrawEllipse(t+sin(bubx)/20,buby[i]+offset[i],.03,.03);
        glColor3f(1,1,1);
        glPointSize(1);
        glBegin(GL_POINTS);
        circle(t+sin(bubx)/20,buby[i]+offset[i],.03);
        glEnd();
    }
    else
    {
        if(flag==true)
        glColor4f(1,1,1,.3);
        else
            glColor3f(1.0,1.0,1.0);
        DrawEllipse(t+cos(bubx)/20,buby[i]+offset[i],.03,.03);
        glColor3f(1,1,1);
        glPointSize(1);
        glBegin(GL_POINTS);
        circle(t+cos(bubx)/20,buby[i]+offset[i],.03);
        glEnd();
    }
    glPopMatrix();


    buby[i]+=r[i]+.0005;

    if(buby[i]>1.3)
    {
        buby[i] =-1.5;
        pos[i]=2*(float)rand()/RAND_MAX-1;
    }
    bubx +=0.005;

}


void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 1, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}






