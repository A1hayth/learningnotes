#include<iostream>
#include<cstring>
using namespace std;

class Student
{
private:
	char m_Name[20];
	int m_Age;
	int m_Grade;
public:
	//默认构造函数
	Student()
	{
		strcpy_s(m_Name,"name");
		m_Age = 0;
		m_Grade = 0;
	}
	//有参构造函数
	Student(const char* NAME, int AGE, int GRADE)
	{
		strcpy_s(m_Name,NAME);
		m_Age = AGE;
		m_Grade = GRADE;
	}
	//拷贝构造函数
	Student(Student& s)
	{
		strcpy_s(m_Name, s.m_Name);
		m_Age = s.m_Age;
		m_Grade = s.m_Grade;
	}
	//重载>>和<<
	friend istream & operator>>(istream &in,Student &s);
	friend ostream & operator<<(ostream &out,Student &s);
	//重载类的转换函数
	operator float() { return m_Grade; }
	//重载类的转换构造函数
	Student(int x) :m_Name(""), m_Age(x), m_Grade(x){}

};

istream& operator>>(istream& in, Student& s)
{
	cin >> s.m_Name >> s.m_Age >> s.m_Grade;
	return cin;
}
ostream& operator<<(ostream& out, Student& s)
{
	cout << "姓名： " << s.m_Name << endl;
	cout << "年龄： " << s.m_Age << endl;
	cout << "成绩： " << s.m_Grade << endl;
	return cout;
}

int main()
{
	Student s1("吴天天", 20, 88), s2, s3;
	cout << s1 << endl; //测试重载运算符<<
	s2 = s1; //对象赋值
	cout << s2 << endl;
	cin >> s3;//测试重载运算符>>   魏华兵 19 90
	cout << s3 << endl;
	float x;
	x = s2;//测试类的转换函数
	cout << x << endl;
	Student s4(s2);//测试拷贝构造函数
	cout << s4 << endl;
	Student s5 = 89;//测试类的转换构造函数	
	cout << s5 << endl;


	return 0;
}