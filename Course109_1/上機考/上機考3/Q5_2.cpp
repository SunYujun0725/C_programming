//
//  main.cpp
//  5-2
//
//  Created by 孫渝鈞 on 2020/11/25.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include<iostream>
using namespace std;
int n;
int a[100010];
  int k;
int partition(int s, int e)
  {
   int key = a[s];
  int i = s;
   int j = e;
    while (i < j)
    {
         while (a[j] >= key & i < j)
         {
             j--;
          }
         while (a[i] <= key & i < j)
        {
            i++;
        }
        swap(a[i], a[j]);
     }
    if (a[i] < key)
     {
              swap(a[s], a[i]);
   }
   else
    swap(a[s], a[i - 1]);
   return i;
  }
 void quickSort(int s,int e)
 {
   if (s < e)
 {
       int m = partition(s, e);
       quickSort(s, m - 1);
         quickSort(m+1, e);
      }
 }
  void arrangeRight(int s,int e,int k)
  {
     if (e - s + 1 == k)//如果要找到大數個數就是陣列長度，不進行操作，直接排序
     {
         return;
     }
      //找一個基準數，使比這個數大的都在右邊，小的都在左邊
    int key = a[s];
     int i = s;
     int j = e;
    while (i < j)
    {
        while ((a[j] >= key) && (i < j))
         {
            j--;
        }
        while ((a[i] <= key) &&( i < j))
        {
            i++;
        }
        swap(a[i], a[j]);
     }
     if (a[i] < key)
     {
        swap(a[s], a[i]);
    }
     else
     {
         swap(a[s],a[i-1]);
     }
     int index = i;//最後基準數的位置
     int len = e - index + 1;
     if (len == k)
    {
        return;
    }
     else if (len > k)//找到的大數多餘規定的，再往右縮小範圍
     {
        arrangeRight(index+1,e,k);
    }
     else//找到的大數不夠k個，往左擴大尋找範圍，已找到len個，還差len-m個
     {
         arrangeRight(s,index-1,k-len);
 }
 }
 int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
         cin >> a[i];
   }
    cin >> k;
    arrangeRight(0, n - 1,k);
     quickSort(n-k,n-1);
     for (int i = n-1; i >= n - k; --i)
   {
          cout << a[i] << endl;
     }
    system("pause");
     return 0;
 }

