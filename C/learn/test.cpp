#include <iostream>
using namespace std;
int a[1000100];
int main()
{
  // 请在此输入您的代码    模拟26进制，从0-25
  long int x;
  scanf("%ld",&x);
  if(x==0)printf("A");
  int i=0;
  while(x)
  {
    x--;  //***最重要的一行***// 1对应的是A，相当于模拟中的0，所以要减一
    a[i]=x%26;  //得到对应26进制的数
    i++;
    x/=26;
  }
  for(int j=i-1;j>=0;j--)
    printf("%c",a[j]+'A');  //再将26进制数转换为对应字符
  return 0;
}