#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include "Plate.h"

//Ekran boyutlarý
const int WIDTH = 800, HEIGHT = 400;

//Renklerin tanýmlarý
const GLfloat ORANGE[] = { 237.0f / 255.0f, 77.0f / 255.0f, 22.0f / 255.0f };
const GLfloat GREEN[] = { 11.0f / 255.0f, 127.0f / 255.0f, 26.0f / 255.0f };

//Plaka listesi tanýmla
std::vector<Plate> plates;


 void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	 if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		 glfwSetWindowShouldClose(window, GLFW_TRUE);
	 }
	 else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		 //rastgele açý seçimi
		 int angles[] = { 10, 15, 20, 30, 40, 45 };
		 int angle = angles[rand() %6];
		 int direction = rand() % 2 == 0 ? -1 : 1;
		 angle *= direction;

		 //plak oluþtur ve listeye ekle
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
	 srand(time(0)); //rastgelelik için seed

	 //GLFW baþlatma
	 if (!glfwInit()) {
		 std::cerr << "GLFW baþlatýlamadý!" << std::endl;
		 return -1;
	 }

	 //OpenGL pencere oluþturma
	 GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Trap Atýþ Simülayonu", nullptr, nullptr);
	 if (!window) {
		 glfwTerminate();
		 std::cerr << "Pencere oluþturulmadý!" << std::endl;
		 return -1;
	 }

	 glfwMakeContextCurrent(window);

	 //Arka plan rengi yeþil
	 glClearColor(GREEN[0], GREEN[1], GREEN[2], 1.0f);

	 // Ortho ayarý (2D çizim için)
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glOrtho(0, WIDTH, HEIGHT, 0, -1.0, 1.0);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();

	 //Klavye girdileri için callback
	 glfwSetKeyCallback(window, key_callback);

	 // Ana döngü
	 while (!glfwWindowShouldClose(window)) {
		 glClear(GL_COLOR_BUFFER_BIT);  // Ekraný temizle
		 
		 draw_plates(); 

		 glfwSwapBuffers(window);  // Ekraný güncelle
		 glfwPollEvents();  
	 }

	 glfwDestroyWindow(window);
	 glfwTerminate();  // GLFW'yi sonlandýr

	 return 0;

 }