#include <iostream>
using namespace std;
//选择排序
void selectionSort(int a[],int N)
{
  for(int i = 0;i < N;i++)
  {
    //未排序部分中的最小索引
    int min = i;
    for(int j = i; j < N; j++)
    {
      if( a[j] < a[min])
        {
          min = j;
        }
    //将最小元素与未排序部分的第一个元素交换
      if(min != i)
          swap(a[i] , a[min]);
    }
  }
}
int main()
{
  return 0;
}