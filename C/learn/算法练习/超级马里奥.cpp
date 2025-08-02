//https://www.luogu.com.cn/problem/P1000
#include <iostream>
#include <string>
using namespace std;

string s[31];
int main() {
	for (int i = 0; i < 21; i++)
		getline(cin, s[i]);
	for (int i = 0; i < 21; i++)
		cout << "printf(\"" + s[i] + "\\n\")\;" << endl;
	return 0;
}