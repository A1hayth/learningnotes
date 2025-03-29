//#include<iostream>
//#include<fstream>
//#include <algorithm>
//
//using namespace std;
//
////创建学生类
//class Student
//{
//public:
//	char Name[64];
//	int ID;
//	int CnScore;
//	int MaScore;
//	int EnScore;
//	friend istream& operator >> (istream& in, Student &s);
//	friend ostream& operator << (ostream& out, Student &s);
//};
//
////重载输入
//istream& operator >> (istream& in, Student &s)
//{
//	in >> s.Name >> s.ID >> s.CnScore >> s.MaScore >> s.EnScore;
//	return in;
//}
//
////重载输出
//ostream &operator << (ostream& out, Student& s)
//{
//	out << "姓名：" << s.Name << endl;
//	out << "学号：" << s.ID << endl;
//	out << "语文成绩：" << s.CnScore << endl;
//	out << "数学成绩：" << s.MaScore << endl;
//	out << "英语成绩：" << s.EnScore << endl;
//	return out;
//}
//
////总成绩
//bool totals(Student s1,Student s2)
//{
//	return (s1.CnScore + s1.MaScore + s1.EnScore > s2.CnScore + s2.MaScore + s2.EnScore);
//}
////写入文件数据
//void resultIn(int s)
//{
//	
//	Student S[100] = {};
//	cout << "请输入学生数据： " << endl;
//	for (int i = 0; i < s; i++)
//	{
//		cin >> S[i];
//	}
//	ofstream result;
//	result.open("result.dat", ios::out | ios::binary);
//	for (int i = 0; i < s; i++)
//	{
//		result.write((const char*)&S[i], sizeof(Student));
//	}
//	result.close();
//}
//
////读取文件数据并存入新文件
//void resultOut(int s)
//{
//	//读取
//	Student S[100] = {};
//	ifstream result;
//	result.open("result.dat", ios::in | ios::binary);
//	result.read((char*)&S, sizeof(Student) * s);
//
//	// 排序
//	sort(S, S + s, totals);
//
//	//写入
//	ofstream sort;
//	sort.open("sort.dat", ios::out | ios::binary);
//	for (int i = 0; i < s; i++)
//	{
//		sort.write((const char*)&S[i], sizeof(Student));
//	}
//	sort.close();
//}
//
////检测
//void test(int s)
//{
//	Student S[100] = {};
//	ifstream sort;
//	sort.open("sort.dat", ios::in | ios::binary);
//	sort.read((char*)&S, sizeof(Student) * s);
//	for (int i = 0; i < s; i++)
//	{
//		cout << S[i] << endl;
//	}
//	sort.close();
//}
//
//int main()
//{
//	int size;
//	cout << "请输入学生个数" << endl;
//	cin >> size;
//
//	resultIn(size);
//	resultOut(size);
//	test(size);
//
//	return 0;
//}