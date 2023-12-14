#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

//�����-�������� Shape
class Shape{
	//int z; //private

private:
	//����� ����������� Shape
	void copyRef(const Shape& s)
	{
		this->color = strcpy(new char[strlen(s.color) + 1], s.color);
	}

protected:
	char* color;

public:
	//�������� ���� ��-���������
	constexpr const static char* DEFAULT_COLOR = "Black";

	char* GetColor() const { return color; }
	
	//����������� Shape 
	Shape(const char* _color = DEFAULT_COLOR)
	{
		color = new char[strlen(_color) + 1];
		strcpy(color, _color);
		cout << "Shape(char*)" << endl;
	}
	
	//����������� �����������
	Shape(const Shape& s)
	{
		copyRef(s);
	}
	
	//�������� �����������
	Shape& operator =(const Shape& s)
	{
		copyRef(s);
		return *this;
	}

	//������� ������ � �������
	virtual void draw() const = 0;
	/* {
		cout << "Shape. " << this->GetColor() << endl;
	}*/

	//���������� Shape. ������� ������ ���������� ��� color
	virtual ~Shape()
	{
		cout << "~Shape()" << endl;
		delete[] color;
		color = NULL;
	}

};

#endif
