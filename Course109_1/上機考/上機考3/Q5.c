//
//  main.c
//  5.
//
//  Created by 孫渝鈞 on 2020/11/25.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
/* probID: MT2A-5-Quick-Select */
//#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define swap(x,y) {int t; t = x; x = y; y = t;}
/*int A[10000000];
int quick_select(int [],int,int,int);
int main()
{
    int n,k,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    scanf("%d",&k);
    value=quick_select(A,0,n-1,k);
    printf("%d",value);
    
    return 0;
}*/

int partition(int A[], int left, int right)
{
    int x = A[right], i = left;
    for (int j = left; j <= right - 1; j++) {
        if (A[j] >= x) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[right]);
    return i;
}
  
int quick_select(int A[], int left, int right, int k)
{
  
    if (k > 0 && k <= right - left + 1) {
  
     
        int index = partition(A, left, right);
  
       
        if (index - left == k - 1)
            return A[index];
  
        if (index - left > k - 1)
            return quick_select(A, left, index - 1, k);
  
        
        return quick_select(A, index + 1, right,k - index + left - 1);
    }
    
    return k;
    
}
  





/*int quick_select(int A[],int left,int right,int k)
{
    
    if(left==right){
       return A[left];
    }
    int key;
    key=left+rand()%(right-left+1);   //隨機取值
   
       //partition分堆
        int B[200000];
        int i=left;
        int j=0;
          int count=0;
          int k2=left;
          for(int i=left;i<=right;i++){
              if(A[i]<A[key]){
                  B[j]=A[i];
                  j++;
                  count++;
                  k2++;
              }
          }
          B[j]=A[key];
          j++;
          count++;
          int l=A[key];
          for(int i=left;i<=right;i++){
              if(A[i]>=l){
                  if(i!=key){
                  B[j]=A[i];
                  j++;
                  count++;
                  }
                      
                  
              }
          }
          for(int j=0;j<count;j++){
              A[i]=B[j];
              i++;
          }
          
          
    
    if(A[k]<A[key])
        quick_select(A,left,k2-1,k);
    
    else if(A[k]==A[key])
        return A[key];
    
    else
        quick_select(A,k2+1,right,k);
    
    
}*/



