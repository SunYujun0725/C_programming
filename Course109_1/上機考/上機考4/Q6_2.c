//
//  main.c
//  6-2.
//
//  Created by 孫渝鈞 on 2020/12/24.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
#include <stdio.h>
int m,n;
int arr[105][105];
int dirTRDL[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int star[2];
void margin()
{
    int margin = 0;
    for(int i=1;i<=m;i++, margin++)
    {
        arr[n+1][i] = margin;
    }
    for(int i=n;i>=1;i--, margin++)
    {
        arr[i][m+1] = margin;
    }
    for(int i=m;i>=1;i--, margin++)
    {
        arr[0][i] = margin;
    }
    for(int i=1;i<=n;i++, margin++)
    {
        arr[i][0] = margin;
    }
}
void dfs(int y, int x){
    int t = 0;
    while(1){
        if(arr[y][x] > 1 || (arr[y][x]<=1 && y == n+1)) {
            printf("%d\n",arr[y][x]);
            break;
        }
        if(arr[y][x] == 1)
        {
            t = (t+1)%2;
        }
       
        y+=dirTRDL[star[t]][0];
        x+=dirTRDL[star[t]][1];
    }
}
void reflect()
{
    for(int i=1;i<=m;i++)
    {
      
        star[0] = 0; star[1] = 1;
        dfs(n+1+dirTRDL[star[0]][0],i+dirTRDL[star[0]][1]);
    }
    for(int i=n;i>=1;i--)
    {
        star[0] = 3; star[1] = 2;
        dfs(i+dirTRDL[star[0]][0],m+1+dirTRDL[star[0]][1]);
    }
    for(int i=m;i>=1;i--)
    {
        star[0] = 2; star[1] = 3;
        dfs(0+dirTRDL[star[0]][0],i+dirTRDL[star[0]][1]);
    }
    for(int i=1;i<=n;i++)
    {
        star[0] = 1; star[1] = 0;
        dfs(i+dirTRDL[star[0]][0],0+dirTRDL[star[0]][1]);
    }
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           scanf("%d",&arr[i][j]);

    margin();
    reflect();

}
