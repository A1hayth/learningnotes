//#include<iostream>
//using namespace std;
//
//class Location {
//public:
//	Location(double a, double b);
//	double Getx()
//	{
//		return x;
//	}
//	double Gety()
//	{
//		return y;
//	}
//	double distance(Location &b)
//	{
//		return ((x - b.Getx()) * (x - b.Getx())) + ((y - b.Gety()) * (y - b.Gety()));
//	}
//	friend double distance(Location &a, Location &b);
//private:
//	double x, y;
//};
//Location::Location(double a, double b)
//{
//	x = a;
//	y = b;
//}
///*friend*/ double distance(Location& a, Location& b)
//{
//	return ((a.Getx() - b.Getx()) * (a.Getx() - b.Getx())) + ((a.Gety() - b.Gety()) * (a.Gety() - b.Gety()));
//}
//
//int main()
//{
//	Location A(1, 2);
//	Location B(3, 4);
//	cout << "A(" << A.Getx() << "," << A.Gety() << ")" << endl;
//	cout << "B(" << B.Getx() << "," << B.Gety() << ")" << endl;
//	cout << "Distancel = " << A.distance(B) << endl;
//	cout << "Distancel = " << distance(A, B) << endl;
//
//	system("pause");
//	return 0;
//}
