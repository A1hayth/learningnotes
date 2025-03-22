#include<iostream>
using namespace std;

const float PI = 3.14;

class Shape
{
public:
	virtual float GetArea() = 0;
	virtual float GetPerim() = 0;
};

class Rectangle :public Shape
{
private:
	float Long;
	float Width;
public:
	Rectangle(float l, float w) : Long(l), Width(w) {};
	virtual float GetArea()
	{
		return Long * Width;
	}
	virtual float GetPerim()
	{
		return 2 * (Long + Width);
	}
};

class Circle :public Shape
{
private:
	float R;
public:
	Circle(float r) : R(r) {};
	virtual float GetArea()
	{
		return PI * R * R;
	}
	virtual float GetPerim()
	{
		return 2 * PI * R;
	}
};

int main()
{
	Rectangle rec(2, 3);
	Circle c(2);
	Shape* p[2] = { &rec,&c };
	for (int i = 0; i < 2; i++)
	{
		cout << p[i]->GetArea() << endl;
		cout << p[i]->GetPerim() << endl;
	}

	return 0;
}