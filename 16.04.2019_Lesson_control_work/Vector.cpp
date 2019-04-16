#include"Vector.h"


Vector::Vector()
{
	cur_size = 0;
	buf_size = 0;
	els = new Array[buf_size];
}

Vector::Vector(int size)
{
	cur_size = 0;
	buf_size = size;
	els = new Array[buf_size];
}

Vector::Vector(int size, int value)
{
	cur_size = buf_size = size;
	els = new Array[buf_size];
	for (int i = 0; i < cur_size; i++)
		els[i] = value;
}

Vector::Vector(const Vector & obj)
{
	this->buf_size = this->cur_size = obj.cur_size;
	this->els = new Array[buf_size];
	for (int i = 0; i < cur_size; i++)
		this->els[i] = obj.els[i];
}

Vector::~Vector()
{
	delete[] els;
}



void Vector::push_back(Array obj)//???
{
	if (buf_size == 0) {
		buf_size = 4;
		els = new Array[buf_size];
	}
	else
	{
		if (cur_size == buf_size) {
			buf_size *= 2;
			Array *tmp = new Array[buf_size];
			for (int i = 0; i < cur_size; i++)
				tmp[i] = els[i];

			delete[] els;
			els = tmp;
		}
	}
	els[cur_size++] = obj;
}

int Vector::size()
{
	return cur_size;
}
Array & Vector::operator[](int index)
{
	return els[index];
}

Vector Vector::operator=(const Array & obj)
{
	push_back(obj);
	return *this;
}
