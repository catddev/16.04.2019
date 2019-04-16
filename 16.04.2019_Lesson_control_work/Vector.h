#pragma once
#include"array.h"

class Vector {
private:
	Array *els;
	int cur_size;
	int buf_size;
public:
	Vector();
	Vector(int size);
	Vector(int size, int value);
	Vector(const Vector& obj);
	~Vector();

	void push_back(Array obj);
	int size();
	Array& operator[](int index);
	Vector operator=(const Array& obj);//???
};
