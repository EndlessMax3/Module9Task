#pragma once
#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>
using std::cout;
using std::endl;

#include "Shape.h"
#include "Coords.h"
#include "MoveableCoords.h"

//�����-��������� Point
class Point : public Shape, public MoveableCoords, protected Coords{

//protected:
//	int x, y;
public:
	//����������� �����
	Point(int _x = 0, int _y = 0, const char* _color = DEFAULT_COLOR) : Shape(_color), Coords(_x,_y)
	{
		cout << "Point(int,int)" << endl;
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }

	//������� ����� � �������
	void draw() const override
	{
		//this->Shape::draw(); ����� ������ ��������
		cout << "Point(" << GetX() << ", " << GetY() << ") " << GetColor() << endl;
	}

	//���������� �����
	~Point()
	{
		cout << "~Point()" << endl;
	}
};

#endif // !_POINT_H_

