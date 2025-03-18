#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//选择排序(升序)
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

//插入排序(升序)
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

//快速排序
//划分函数
int partition(int a[], int s, int t)
{
    int i = s, j = t;
    int base = a[i];
    while (i < j)
    {
        while (i < j && a[j] > base)
        {
            j--;
        }
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }
        while (i < j && a[i] < base)
        {
            i++;
        }
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    a[i] = base;
    return i;  // 修正返回值为 i
}

//递归实现左右子表的排序
void _quicksort(int a[], int s, int t)
{
    if (s < t) {
        int i = partition(a, s, t);
        _quicksort(a, s, i - 1);  // 左子表递归
        _quicksort(a, i + 1, t);  // 右子表递归
    }
}
//调用
void quicksort(int a[], int t)
{
    _quicksort(a, 0, t);
}

//基数排序
void counting_sort(vector<int>& arr, int exp) {
  int n = arr.size();
  vector<int> output(n);
  int count[10] = {0};
  
  // 统计出现次数
  for (int i = 0; i < n; i++) {
      int index = (arr[i] / exp) % 10;
      count[index]++;
  }
  
  // 计算前缀和，确定每个元素的位置
  for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
  }
  
  // 逆序遍历原数组，稳定排序
  for (int i = n - 1; i >= 0; i--) {
      int index = (arr[i] / exp) % 10;
      output[count[index] - 1] = arr[i];
      count[index]--;
  }
  
  // 复制回原数组
  for (int i = 0; i < n; i++) {
      arr[i] = output[i];
  }
}

void radix_sort(vector<int>& arr) {
  int max_num = *max_element(arr.begin(), arr.end());
  for (int exp = 1; max_num / exp > 0; exp *= 10) {
      counting_sort(arr, exp);
  }
}
int main()
{
  return 0;
}