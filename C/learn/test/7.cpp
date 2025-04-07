//#include<iostream>
//using namespace std;
//
//const float PI = 3.14;
////高度类
//class Height
//{
//protected:
//	int height;
//public:
//	Height(int hei) : height(hei) {};
//};
////圆类
//class Circle
//{
//protected:
//	int R;
//	
//public:
//	Circle(int r) :R(r) {};
//	//计算圆面积
//	float getArea()
//	{
//		return PI * R * R;
//	}
//	//计算圆周长
//	float getPerimeter()
//	{
//		return PI * 2 * R;
//	}
//};
////圆柱类
//class Cylinder : public Height,public Circle
//{
//public:
//	Cylinder(int hei, int r) : Height(hei), Circle(r) {};
//	//计算面积
//	float getArea()
//	{
//		return Circle::getArea() * 2 + Circle::getPerimeter() * height;
//	}
//	//输出面积
//	void showArea()
//	{
//		cout << "面积为: " << getArea() << endl;
//	}
//	//计算体积
//	float getVolume()
//	{
//		return Circle::getArea() * height;
//	}
//	//输出体积
//	void showVolume()
//	{
//		cout << "体积为: " << (PI * R * R) * height;
//	}
//};
//
//int main()
//{
//	Cylinder cy(3, 2);
//	cy.showArea();
//	cy.showVolume();
//
//	return 0;
//}