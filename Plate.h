#pragma once

#ifndef PLATE_H //Yaln�zca bir kez derlemek i�in
#define PLATE_H

class Plate {
public:
	Plate(float x, float y, float angle); //constructor'�
	void move();
	void draw();

private:
	float x, y; //Konum
	float angle; //Hareket a��s�
	float speed; //Hareket h�z�

};
#endif
