//#include<iostream>
//using namespace std;
//
//class Rectangle
//{
//	int m_l;
//	int m_w;
//public:
//	Rectangle()
//	{
//		m_l = m_w = 1;
//	}
//	Rectangle(int L, int W)
//	{
//		m_l = L;
//		m_w = W;
//	}
//	Rectangle(Rectangle& p)
//	{
//		m_l = this->m_l;
//		m_w = this->m_w;
//	}
//	//计算面积
//	int S()
//	{
//		int s = this->m_l * this->m_w;
//		return s;
//	}
//	//析构
//	~Rectangle()
//	{
//		cout << "调用了析构函数" << endl;
//	}
//	//++重载
//	Rectangle operator ++()
//	{
//		++m_l;
//		++m_w;
//		return *this;
//	}
//	//==重载
//	friend bool operator==(Rectangle& r1,Rectangle& r2);
//};
//
//
//bool operator==(Rectangle& r1, Rectangle& r2)
//{
//	return r1.m_l == r2.m_l && r1.m_w == r2.m_w;
//}
//
//int main()
//{
//	Rectangle c1(10,10);
//	Rectangle c2(10, 20);
//	Rectangle c3(1,1);
//	cout << "r1的面积为： " << c1.S() << endl;
//	++c1;
//	cout << "r1前自增后的面积为： " << c1.S() << endl;
//	c3 = c2;
//	if (c1 == c2)
//	{
//		cout << "c1和c2相等" << endl;
//	}
//	else
//	{
//		cout << "c1和c2不相等" << endl;
//	}
//	if (c3 == c2)
//	{
//		cout << "c3和c2相等" << endl;
//	}
//	else
//	{
//		cout << "c3和c2不相等" << endl;
//	}
//
//	system("pause");
//	return 0;
//}
