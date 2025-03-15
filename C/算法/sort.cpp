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

//插入排序
void insertionSort(int a[],int n)
{
    for(int i = 1; i < n; i++)
  {
    int key = a[i];//设置哨兵
    int j = i - 1;

    //将比key大的元素都向后移动
    while(j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j--;
    }
    //将key插入正确位置
    a[j + 1] = key;
  }
}

int main()
{
  return 0;
}