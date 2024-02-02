//
//  main.c
//  HW W7-2-3
//
//  Created by 孫渝鈞 on 2020/10/23.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>

int main()
{   int n;
    scanf("%d",&n);
    int a[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int left=0;
    int right=n-1;
  
    int s=n;
    for(int i=0; i<n;n--){
          int m=i;
          int k=m+1;
        while(left<right){
               if(a[m]<a[k]){
                  k++;
                  right--;
               }
               else{
                  m=k;
                  k=m+1;
                  right--;
               }
            }
        printf("%d",a[m]);
        printf(" ");
        a[s]=a[m];
        s++;
        }
    
    return 0;
}
