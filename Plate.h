#pragma once

#ifndef PLATE_H //Yalnýzca bir kez derlemek için
#define PLATE_H

class Plate {
public:
	Plate(float x, float y, float angle); //constructor'ý
	void move();
	void draw();

private:
	float x, y; //Konum
	float angle; //Hareket açýsý
	float speed; //Hareket hýzý

};
#endif
