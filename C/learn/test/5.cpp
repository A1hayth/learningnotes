//#include<iostream>
//#include<cstring>
//using namespace std;
//
//class Employee
//{
//protected:
//	int num;
//	char name[18];
//	char sex[3];
//    int wage;
//	static int count;
//	static int totalWage;
//public:
//	Employee(int nu,const char* nm,const char* sx, int wg)
//	{
//		num = nu;
//		strcpy_s(name, nm);
//		strcpy_s(sex, sx);
//		wage = wg;
//		count++;
//		totalWage += wage;
//	}
//
//	void ShowBase()
//	{
//		cout << "编号：" << num << endl;
//		cout << "姓名：" << name << endl;
//		cout << "性别：" << sex << endl;
//		cout << "工资：" << wage << endl;
//	}
//	static void ShowStatic()
//	{
//		cout << "人数：" << count << endl;
//		cout << "总工资：" << totalWage << endl;
//	}
//};
//
//int Employee::count = 0;
//int Employee::totalWage = 0;
//
//int main()
//{
//	Employee e1(1,"张三","男",3000);
//	Employee e2(2, "李四", "男", 4000);
//	Employee e3(3, "王五", "男", 5000);
//	Employee e4(4, "小红", "女", 6000);
//
//	e1.ShowBase();
//	cout << endl;
//	e2.ShowBase();
//	cout << endl;
//	e3.ShowBase();
//	cout << endl;
//	e4.ShowBase();
//	cout << endl;
//	Employee::ShowStatic();
//
//	system("pause");
//	return 0;
//}