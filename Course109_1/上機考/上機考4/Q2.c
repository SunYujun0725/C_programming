//
//  main.c
//  2.
//
//  Created by 孫渝鈞 on 2020/12/2.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int k=0;
int n,m;
int v[200][200]={0};
int arr[200][200]={-1};
void e(int x,int y,int k,int z){
  
    if(k<n*m){
          arr[x][y]=k;
          v[x][y]=2;
        if(z==0){
        if(v[x][y+1]==1){
            e(x,y+1,++k,z);
        }
        else {
            e(x+1,y,++k,z=1);
        }
        }
    else if(z==1){
        if(v[x+1][y]==1){
            e(x+1,y,++k,z);
        }
        else  {
            
            e(x,y-1,++k,z=2);
        }
    }
    else if(z==2){
        if(v[x][y-1]==1){
            e(x,y-1,++k,z);
        }
        else{
            e(x-1,y,++k,z=3);
        }
    }
    else if(z==3){
        if(v[x-1][y]==1){
            e(x-1,y,++k,z);
        }
        else{
            e(x,y+1,++k,z=0);
        }
     }
    }
}
int main(){
  
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j]=1;
        }
    }
    e(0,0,k,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
