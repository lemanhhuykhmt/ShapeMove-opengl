#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <GL/freeglut.h>
#include <math.h>;
#include "Border.h"
#include "Box.h"
#include "CircleCollider.h"
#define PI 3.1415956

using namespace std;




//int main()
//{
//
//
//
//
//
//
//
//
//
//
//
//	/*Collider *listCollider[2];
//	BoxCollider *n1 = new BoxCollider(Vector33(1, 1, 1) , 10, 10, 10);
//	CircleCollider *c1 = new CircleCollider(Vector33(0.0, 0.5, 0.5), 1);
//	listCollider[0] = n1;
//	listCollider[1] = c1;
//	   
//	cout << "" << listCollider[1]->IsCollsion(*listCollider[0]);
//
//
//	
//	Vector3<Vector33> der = c1->GetPointsToCheck();
//	system("pause");
//	return 0;*/
//}




///open gl
void frameMove();
void DrawOxyz();
void display();
void ReShape(int width, int height);
void init();
unsigned char* readBMP(const char* filename, int &w, int &h);
GLuint initTexture(const char *fileName);
void OnSpecialDown(int key, int x, int y);
void OnKeyUp(unsigned char key, int x, int y);
void OnKeyDown(unsigned char key, int x, int y);
void mouseButton(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mouseWheel(int button, int dir, int x, int y);



//float *cam_pos = new float[3]{0.0, 0.0, 20.0};
Vector3 cam_pos(0.0, 0.0, 3.5);
//float *center_pos = new float[3]{0.0, 0.0, 0.0};
Vector3 center_pos(0.0, 0.0, 0.0);
//float *up_pos = new float[3]{0.0, 1.0, 0.0};
Vector3 up_point(0.0, 1.0, 3.5);
Vector3 up_point_forCam(0.0, 1.0, 3.5);

Vector3 up_pos(-cam_pos.getX() + up_point_forCam.getX(), -cam_pos.getY() + up_point_forCam.getY(), -cam_pos.getZ() + up_point_forCam.getZ());
bool isRotatingCam = false;
bool isKeyDown = false;
float xdeltaAngle = 0.0f;
float ydeltaAngle = 0.0f;
float zdeltaAngle = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
int zOrigin = -1;
float deltaMove = 0.01;
bool *keyStatesMove = new bool[256];
//GLuint tex_Box = ;
int oldTimeSinceStart = 0;
Border *border;
Box *box;
Box *box1;

void DrawBox()
{
	box->Draw();
	box1->Draw();
	border->Draw();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotate Cam");
	glutReshapeFunc(ReShape);
	glutDisplayFunc(display);
	glutIdleFunc(frameMove);
	init();
	glutSpecialFunc(OnSpecialDown);
	glutKeyboardFunc(OnKeyDown);
	glutKeyboardUpFunc(OnKeyUp);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutMouseWheelFunc(mouseWheel);
	glutMainLoop();
}
void frameMove()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	deltaTime /= 1000;
	box->Move(deltaTime);
	box1->Move(deltaTime);
	if (border->IsCollision(box))
	{
		border->Collision(box);
	}
	if (border->IsCollision(box1))
	{
		border->Collision(box1);
	}
	if (box->IsCollision(box1))
	{
		box->Collision(box1);
	}
	if (box1->IsCollision(box))
	{
		box1->Collision(box);
	}
	//box->Draw();
	////////////
	/*float *v = new float[3];
	for (int i = 0; i < 3; ++i)
	{
		v[i] = center_pos[i] - cam_pos[i];
	}*/


	if (keyStatesMove['w'])
	{
		/*Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Add(v.Mul(deltaMove));
		center_pos = center_pos.Add(v.Mul(deltaMove));
		up_point = up_point.Add(v.Mul(deltaMove));*/
		Vector3 up;
		up = up_point.Sub(cam_pos);
		up.Normalize();
		//cam_pos.setY(up.getY() + deltaMove * 10);
		cam_pos = cam_pos.Add(up.Mul(deltaMove));
		//center_pos.setY(center_pos.getY() + deltaMove * 10);
		center_pos = center_pos.Add(up.Mul(deltaMove));

		up_point = up_point.Add(up.Mul(deltaMove));
		up_point_forCam = up_point_forCam.Add(up.Mul(deltaMove));
		up_pos = up_point_forCam.Sub(cam_pos);
	}
	if (keyStatesMove['s'])
	{
		/*Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Sub(v.Mul(deltaMove));
		center_pos = center_pos.Sub(v.Mul(deltaMove));
		up_point = up_point.Sub(v.Mul(deltaMove));*/
		Vector3 up;
		up = up_point.Sub(cam_pos);
		up.Normalize();
		//cam_pos.setY(up.getY() + deltaMove * 10);
		cam_pos = cam_pos.Sub(up.Mul(deltaMove));
		//center_pos.setY(center_pos.getY() + deltaMove * 10);
		center_pos = center_pos.Sub(up.Mul(deltaMove));

		up_point = up_point.Sub(up.Mul(deltaMove));
		up_point_forCam = up_point_forCam.Sub(up.Mul(deltaMove));
		up_pos = up_point_forCam.Sub(cam_pos);
	}
	if (keyStatesMove['a'])
	{
		/*float *n = new float[3];
		n[0] = up_pos[1] * v[2] - up_pos[2] * v[1];
		n[1] = up_pos[2] * v[0] - up_pos[0] * v[2];
		n[2] = up_pos[0] * v[1] - up_pos[1] * v[0];
		Normalize(n);
		for (int i = 0; i < 3; ++i)
		{
			cam_pos[i] += deltaMove * n[i];
			center_pos[i] += deltaMove * n[i];
		}*/
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		Vector3 n;
		n = up_pos.CrossProduct(v);
		n.Normalize();
		cam_pos = cam_pos.Add(n.Mul(deltaMove));
		center_pos = center_pos.Add(n.Mul(deltaMove));
		up_point = up_point.Add(n.Mul(deltaMove));
		up_point_forCam = up_point_forCam.Add(n.Mul(deltaMove));
		up_pos = up_point_forCam.Sub(cam_pos);
	}
	if (keyStatesMove['d'])
	{
		/*float *n = new float[3];
		n[0] = up_pos[1] * v[2] - up_pos[2] * v[1];
		n[1] = up_pos[2] * v[0] - up_pos[0] * v[2];
		n[2] = up_pos[0] * v[1] - up_pos[1] * v[0];
		Normalize(n);
		for (int i = 0; i < 3; ++i)
		{
			cam_pos[i] -= deltaMove * n[i];
			center_pos[i] -= deltaMove * n[i];
		}
		delete n;*/
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		Vector3 n;
		n = up_pos.CrossProduct(v);
		n.Normalize();
		cam_pos = cam_pos.Sub(n.Mul(deltaMove));
		center_pos = center_pos.Sub(n.Mul(deltaMove));
		up_point = up_point.Sub(n.Mul(deltaMove));
		up_point_forCam = up_point_forCam.Sub(n.Mul(deltaMove));
		up_pos = up_point_forCam.Sub(cam_pos);
	}
	////////////////
	isKeyDown = false;

	glutPostRedisplay();
}
void DrawOxyz()
{
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-10.0, 0.0, -10.0);
	glVertex3f(10.0, 0.0, -10.0);
	glVertex3f(10.0, 0.0, 10.0);
	glVertex3f(-10.0, 0.0, 10.0);
	/*glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 0.0, 0.0);*/
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-10.0, -10.0, 0.0);
	glVertex3f(10.0, -10.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(-10.0, 10.0, 0.0);
	/*glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);*/
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, -10.0, -10.0);
	glVertex3f(0.0, -10.0, 10.0);
	glVertex3f(0.0, 10.0, 10.0);
	glVertex3f(0.0, 10.0, -10.0);
	/*glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 5.0);*/
	glEnd();

	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam_pos.getX(), cam_pos.getY(), cam_pos.getZ(),
		center_pos.getX(), center_pos.getY(), center_pos.getZ(),
		up_pos.getX(), up_pos.getY(), up_pos.getZ());
	//DrawOxyz();
	DrawBox();
	glPointSize(5.0);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(center_pos.getX(), center_pos.getY(), center_pos.getZ());
	glVertex3f(up_point.getX(), up_point.getY(), up_point.getZ());
	glEnd();
	glutSwapBuffers();
	glFlush();
}
void ReShape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	float ratio = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	gluPerspective(60.0, ratio, 1.0, 100.0);


}
void init()
{
	for (int i = 0; i < 256; ++i)
	{
		keyStatesMove[i] = false;
	}
	box = new Box(Vector3(0.0, 0.0, 0.0), 1, 1, 1, Vector3(1, 1, 0));
	box->setVelocity(Vector3(5, 5, 0));
	box1 = new Box(Vector3(2.0, 2.0, 0.0), 1, 1, 1, Vector3(0, 0, 1));
	box1->setVelocity(Vector3(-5, -5, 0));

	border = new Border(Vector3(0.0, 0.0, 0.0), 8, 8, 8);
	border->setVelocity(Vector3(0, 0, 0));
	border->setColor(Vector3(1.0, 0 ,0));



	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);


}

unsigned char* readBMP(const char* filename, int &w, int &h)
{
	int i;
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	w = *(int*)&info[18];
	h = *(int*)&info[22];

	int size = 3 * w * h;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}

	return data;
}
GLuint initTexture(const char *fileName)
{
	GLuint textureId;
	glGenTextures(1, &textureId);

	glBindTexture(GL_TEXTURE_2D, textureId);

	unsigned char *imgData;
	int imgW, imgH;
	imgData = readBMP(fileName, imgW, imgH);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, imgW, imgH, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	return textureId;
}
void OnSpecialDown(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Add(v.Mul(deltaMove * 50));
		center_pos = center_pos.Add(v.Mul(deltaMove * 50));
		up_point = up_point.Add(v.Mul(deltaMove * 50));
		up_pos = up_point.Sub(cam_pos);
	}
	else if (key == GLUT_KEY_DOWN)
	{
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Sub(v.Mul(deltaMove * 50));
		center_pos = center_pos.Sub(v.Mul(deltaMove * 50));
		up_point = up_point.Sub(v.Mul(deltaMove * 50));
		up_pos = up_point.Sub(cam_pos);
	}
	else if (key == GLUT_KEY_F1)
	{
		std::cout << "up cu: " << up_point.getX() << "; " << up_point.getY() << "; " << up_point.getZ() << "//";
		std::cout << "up moi : " << up_point_forCam.getX() << "; " << up_point_forCam.getY() << "; " << up_point_forCam.getZ() << "//";

	}
}
void OnKeyUp(unsigned char key, int x, int y)
{
	keyStatesMove[key] = false;
}
void OnKeyDown(unsigned char key, int x, int y)
{
	 
	if (isRotatingCam) return;
	isKeyDown = true;
	keyStatesMove[key] = true;

}
void mouseButton(int button, int state, int x, int y)
{
	// only start motion if the left button is pressed
	if (isKeyDown) return;
	if (button == GLUT_LEFT_BUTTON)
	{
		// when the button is released
		if (state == GLUT_UP)
		{
			isRotatingCam = false;
			xOrigin = -1;
			yOrigin = -1;
		}
		else
		{
			isRotatingCam = true;
			xOrigin = x;
			yOrigin = y;

			xdeltaAngle = 0.0;
			ydeltaAngle = 0.0;
			zdeltaAngle = 0.0;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		//// when the button is released
		//if (state == GLUT_UP)
		//{
		//	isRotatingCam = false;
		//	yOrigin = -1;
		//}
		//else
		//{
		//	isRotatingCam = true;
		//	yOrigin = y;
		//	ydeltaAngle = 0.0;
		//}
	}
}
void mouseMove(int x, int y)
{
	if (isRotatingCam)
	{
		/*if (xOrigin > 0)
		{
			xdeltaAngle = (x - xOrigin) * 0.003;
			center_pos = center_pos.Rotate_Y(-xdeltaAngle, cam_pos);
			xOrigin = x;
		}
		if (yOrigin > 0)
		{
			ydeltaAngle = (y - yOrigin) * 0.003;
			center_pos = center_pos.Rotate_X(-ydeltaAngle, cam_pos);
			yOrigin = y;
		}*/

		Vector3 v;
		v = center_pos.Sub(cam_pos);
		Vector3 up;
		up = up_point.Sub(cam_pos);
		Vector3 X(1.0, 0.0, 0.0);
		Vector3 Y(0.0, 1.0, 0.0);
		Vector3 Z(0.0, 0.0, 1.0);
		float alphaX = X.GetAlpha(v) * 180 / PI;
		float alphaY = Y.GetAlpha(v) * 180 / PI;
		float alphaZ = Z.GetAlpha(v) * 180 / PI;

		if (((alphaX >= 45 && alphaX <= 135) || (alphaX >= 255 && alphaX <= 325)) && ((alphaZ >= 45 && alphaZ <= 135) || (alphaZ >= 255 && alphaZ <= 325)))
		{
			float betaX = X.GetAlpha(up) * 180 / PI;

			//float betaZ = Z.GetAlpha(up) * 180 / PI;
			if ((betaX >= 45 && betaX <= 135) || (betaX >= 255 && betaX <= 325))
			{
				int orienteRotate = -Y.DotProduct(v) / (abs(Y.DotProduct(v))) * Z.DotProduct(up) / (abs(Z.DotProduct(up)));
				ydeltaAngle = (y - yOrigin) * 0.004;
				up_point = up_point.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
				up_point_forCam = up_point_forCam.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
				center_pos = center_pos.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
				up_pos = up_point_forCam.Sub(cam_pos);
				yOrigin = y;
			}
			else
			{
				int orienteRotate = -Y.DotProduct(v) / (abs(Y.DotProduct(v))) * X.DotProduct(up) / (abs(X.DotProduct(up)));
				ydeltaAngle = (y - yOrigin) * 0.004;
				up_point = up_point.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
				//up_point_forCam = up_point_forCam.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
				center_pos = center_pos.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
				//up_pos = up_point_forCam.Sub(cam_pos);
				yOrigin = y;
			}

			//////////////
			xdeltaAngle = (x - xOrigin) * 0.004;
			up_point = up_point.Rotate_Y(-xdeltaAngle, cam_pos);
			up_point_forCam = up_point_forCam.Rotate_Y(-xdeltaAngle, cam_pos);
			center_pos = center_pos.Rotate_Y(-xdeltaAngle, cam_pos);
			up_pos = up_point_forCam.Sub(cam_pos);
			xOrigin = x;
		}
		if (((alphaY >= 45 && alphaY <= 135) || (alphaY >= 255 && alphaY <= 325)) && ((alphaX >= 45 && alphaX <= 135) || (alphaX >= 255 && alphaX <= 325)))
		{
			int orienteRotate = Z.DotProduct(v) / (abs(Z.DotProduct(v)));
			ydeltaAngle = (y - yOrigin) * 0.004;
			up_point = up_point.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
			up_point_forCam = up_point_forCam.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
			center_pos = center_pos.Rotate_X(orienteRotate * ydeltaAngle, cam_pos);
			up_pos = up_point_forCam.Sub(cam_pos);
			yOrigin = y;

			xdeltaAngle = (x - xOrigin) * 0.004;
			up_point = up_point.Rotate_Y(-xdeltaAngle, cam_pos);
			up_point_forCam = up_point_forCam.Rotate_Y(-xdeltaAngle, cam_pos);
			center_pos = center_pos.Rotate_Y(-xdeltaAngle, cam_pos);
			up_pos = up_point_forCam.Sub(cam_pos);
			xOrigin = x;
		}
		if (((alphaY >= 45 && alphaY <= 135) || (alphaY >= 255 && alphaY <= 325)) && ((alphaZ >= 45 && alphaZ <= 135) || (alphaZ >= 255 && alphaZ <= 325)))
		{
			int orienteRotate = X.DotProduct(v) / (abs(X.DotProduct(v)));
			ydeltaAngle = (y - yOrigin) * 0.004;
			up_point = up_point.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
			//up_point_forCam = up_point_forCam.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
			center_pos = center_pos.Rotate_Z(orienteRotate * ydeltaAngle, cam_pos);
			//up_pos = up_point_forCam.Sub(cam_pos);
			yOrigin = y;

			xdeltaAngle = (x - xOrigin) * 0.004;
			up_point = up_point.Rotate_Y(-xdeltaAngle, cam_pos);
			up_point_forCam = up_point_forCam.Rotate_Y(-xdeltaAngle, cam_pos);
			center_pos = center_pos.Rotate_Y(-xdeltaAngle, cam_pos);
			up_pos = up_point_forCam.Sub(cam_pos);
			xOrigin = x;
		}
	}

}
void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		// Zoom in
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Add(v.Mul(deltaMove * 200));
		center_pos = center_pos.Add(v.Mul(deltaMove * 200));
		up_point = up_point.Add(v.Mul(deltaMove * 200));
		up_point_forCam = up_point_forCam.Add(v.Mul(deltaMove * 200));

		up_pos = up_point_forCam.Sub(cam_pos);
	}
	else
	{
		// Zoom out
		Vector3 v;
		v = center_pos.Sub(cam_pos);
		v.Normalize();
		cam_pos = cam_pos.Sub(v.Mul(deltaMove * 200));
		center_pos = center_pos.Sub(v.Mul(deltaMove * 200));
		up_point = up_point.Sub(v.Mul(deltaMove * 200));
		up_point_forCam = up_point_forCam.Sub(v.Mul(deltaMove * 200));
		up_pos = up_point_forCam.Sub(cam_pos);
	}
}