#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include "Plate.h"

//Ekran boyutlar�
const int WIDTH = 800, HEIGHT = 400;

//Renklerin tan�mlar�
const GLfloat ORANGE[] = { 237.0f / 255.0f, 77.0f / 255.0f, 22.0f / 255.0f };
const GLfloat GREEN[] = { 11.0f / 255.0f, 127.0f / 255.0f, 26.0f / 255.0f };

//Plaka listesi tan�mla
std::vector<Plate> plates;


 void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	 if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		 glfwSetWindowShouldClose(window, GLFW_TRUE);
	 }
	 else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		 //rastgele a�� se�imi
		 int angles[] = { 10, 15, 20, 30, 40, 45 };
		 int angle = angles[rand() %6];
		 int direction = rand() % 2 == 0 ? -1 : 1;
		 angle *= direction;

		 //plak olu�tur ve listeye ekle
		 Plate new_plate(WIDTH / 2, HEIGHT, angle);
		 plates.push_back(new_plate);
	 }
}

 void draw_plates() {
	 for (auto& plate : plates) {
		 plate.move();
		 plate.draw();
	 }
 }

 int main() {
	 srand(time(0)); //rastgelelik i�in seed

	 //GLFW ba�latma
	 if (!glfwInit()) {
		 std::cerr << "GLFW ba�lat�lamad�!" << std::endl;
		 return -1;
	 }

	 //OpenGL pencere olu�turma
	 GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Trap At�� Sim�layonu", nullptr, nullptr);
	 if (!window) {
		 glfwTerminate();
		 std::cerr << "Pencere olu�turulmad�!" << std::endl;
		 return -1;
	 }

	 glfwMakeContextCurrent(window);

	 //Arka plan rengi ye�il
	 glClearColor(GREEN[0], GREEN[1], GREEN[2], 1.0f);

	 // Ortho ayar� (2D �izim i�in)
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glOrtho(0, WIDTH, HEIGHT, 0, -1.0, 1.0);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();

	 //Klavye girdileri i�in callback
	 glfwSetKeyCallback(window, key_callback);

	 // Ana d�ng�
	 while (!glfwWindowShouldClose(window)) {
		 glClear(GL_COLOR_BUFFER_BIT);  // Ekran� temizle
		 
		 draw_plates(); 

		 glfwSwapBuffers(window);  // Ekran� g�ncelle
		 glfwPollEvents();  
	 }

	 glfwDestroyWindow(window);
	 glfwTerminate();  // GLFW'yi sonland�r

	 return 0;

 }