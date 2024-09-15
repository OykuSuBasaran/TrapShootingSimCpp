#include "Plate.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415



const GLfloat ORANGE[] = { 237.0f / 255.0f, 77.0f / 255.0f, 22.0f / 255.0f };

Plate::Plate(float x, float y, float angle) : x(x), y(y), angle(angle), speed(5.0f){} //constructor

void Plate::move() {
	float radian_angle = angle *  M_PI/ 180.f; //a�� hesab�
	int direction = angle < 0 ? -1 : 1;
	x += direction * speed * cos(radian_angle);
	y -= speed * std::abs(sin(radian_angle));

}

void Plate::draw() {
	//Plaka �izim fonksiyonu (OpenGL QUAD)
	glColor3f(ORANGE[0], ORANGE[1], ORANGE[2]); //renk ayar�
	glBegin(GL_QUADS); //d�rtgen �izecek demek, �izme i�lemini ba�lat�r
	glVertex2f(x, y); //s�rayla �izilecek pla��n 4 k��e noktas� tan�mland�
	glVertex2f(x + 20, y);
	glVertex2f(x + 20, y + 10);
	glVertex2f(x, y + 10);
	glEnd(); //�izme i�lemini sonland�r�r
}
#endif // !M_PI