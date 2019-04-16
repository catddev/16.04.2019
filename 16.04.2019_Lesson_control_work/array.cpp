#include"array.h"


Array::Array()
{
	size = 12;//
	els = new int[12];
}

Array::Array(int size)
{
	this->size = size;
	els = new int[this->size];
}

Array::Array(int size, int value)
{
	this->size = size;
	els = new int[size];
	for (int i = 0; i < size; i++)
		els[i] = value;
}

Array::Array(const Array & obj)
{
	this->size = obj.size;
	this->els = new int[size];
	for (int i = 0; i < size; i++)
		this->els[i] = obj.els[i];
}

Array::~Array()
{
	delete[] els;
}

void Array::setSize(int size)
{
	this->size = size;
}

int Array::getSize()
{
	return size;
}

int Array::operator[](int index)
{
	return els[index];
}

bool Array::operator>(Array obj)
{
	return(average() > obj.average());
}

bool Array::operator<(Array obj)
{
	return(average() < obj.average());
}

bool Array::operator==(Array obj)
{
	return(average() == obj.average());
}

bool Array::operator!=(Array obj)
{
	return(average() != obj.average());
}



void Array::print()
{
	for (int i = 0; i < size; i++)
		cout << els[i] << " ";
	cout << endl;
}

int Array::max_el()
{
	int max=els[0];
	for (int i = 0; i < size; i++)
		if (els[i] > max) max = els[i];
	return max;
}

int Array::min_el()
{
	int min = els[0];
	for (int i = 0; i < size; i++)
		if (els[i] > min) min = els[i];
	return min;
}

int Array::sum()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += els[i];
	return sum;
}

double Array::average()
{
	double average = 0;
	for (int i = 0; i < size; i++)
		average += els[i];
	average /= size;
	return average;
}

Array Array::random()
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		els[i] = rand() % 12;
	return *this;
}

Array Array::operator=(const Array & obj)
{
	this->size = obj.size;
	this->els = new int[size];
	for (int i = 0; i < size; i++)
		this->els[i] = obj.els[i];
	return *this;
}

Array Array::operator+(Array obj)
{
	Array tmp;
	for (int i = 0; i < size; i++)
		tmp.els[i] = els[i] + obj.els[i];
	return tmp;
}

Array Array::operator+=(Array obj)
{
	for (int i = 0; i < size; i++)
		els[i] += obj.els[i];
	return *this;
}

Array Array::operator-(Array obj)
{
	Array tmp;
	for (int i = 0; i < size; i++)
		tmp.els[i] = els[i] - obj.els[i];
	return tmp;
}

istream & operator>>(istream & is, Array & obj)
{
	for (int i = 0; i < obj.size; i++)
		is >> obj.els[i];
	return is;
}

ostream & operator<<(ostream & os, Array obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.els[i] << " ";
	os << endl;
	return os;
}