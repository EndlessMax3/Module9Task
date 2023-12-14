#pragma once
#include "Shape.h"
#include "IScaleable.h"
#include "IMoveable.h"
#include <iostream>
#include "List.h"

//класс сцена
class Scene {

private:
	List<Shape>* objects; //лист объектов Shape
	int size; //итератор

public:
	Scene() : size(0) { this->objects = new List<Shape>; } //создание листа
	//деструктор массива, очищает память выделенную под лист
	~Scene()
	{
		delete objects;
	}

	//нарисовать фигуры из листа
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

	//отмасштабировать сцену
	void scale(double factor)
	{
		for (int i = 0; i < size; i++)
		{
			IScalable* sc = dynamic_cast<IScalable*>(objects->next());
			if (sc != NULL)
				sc->scale(factor);
		}
	}

	//сдвинуть сцену
	void moveBy(int dx, int dy)
	{
		for (int i = 0; i < size; i++)
		{
			IMoveable* mv = dynamic_cast<IMoveable*>(objects->next());
			if (mv != NULL)
				mv->moveBy(dx,dy);
		}
	}

	//добавить фигуру в массив Scene
	void add(Shape* s) 
	{
		objects->push_back(s);
	}
};
