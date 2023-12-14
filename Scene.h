#pragma once
#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"
#include <iostream>
#include "List.h"

//����� �����
class Scene {

private:
	List<Shape>* objects; //���� �������� Shape
	int size; //��������

public:
	Scene() : size(0) { this->objects = new List<Shape>; } //�������� �����
	//���������� �������, ������� ������ ���������� ��� ����
	~Scene()
	{
		delete objects;
	}

	//���������� ������ �� �����
	void draw()
	{
		Shape* s;
		cout << "************ Drawing Scene ************" << endl;
		while ((s = objects->next()) != nullptr)
		{
			s->draw();
		}
		cout << "***************************************" << endl;
	}

	//���������������� �����
	void scale(double factor)
	{
		for (int i = 0; i < size; i++)
		{
			IScalable* sc = dynamic_cast<IScalable*>(objects->next());
			if (sc != NULL)
				sc->scale(factor);
		}
	}

	//�������� �����
	void moveBy(int dx, int dy)
	{
		for (int i = 0; i < size; i++)
		{
			IMoveable* mv = dynamic_cast<IMoveable*>(objects->next());
			if (mv != NULL)
				mv->moveBy(dx,dy);
		}
	}

	//�������� ������ � ������ Scene
	void add(Shape* s) 
	{
		objects->push_back(s);
	}
};
