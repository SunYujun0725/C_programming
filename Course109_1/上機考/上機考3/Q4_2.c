//
//  main.c
//  4-2.
//
//  Created by 孫渝鈞 on 2020/12/24.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
#include <stdio.h>
#define MAX_N 100
#define MAX_M 100
int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//'+'
int dirs1[4][2]={{1,0},{-1,0},{0,0},{0,0}};//'|'
int dirs2[4][2]={{0,0},{0,0},{0,1},{0,-1}};//'-'
int n,m;
char A[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
void Explore(int a,int b){
    visited[a][b]=1;
    if(A[a][b]=='+'){
        for(int i=0;i<=3;i++){
            if(A[a+dirs[i][0]][b+dirs[i][1]]=='+'){
                if(visited[a+dirs[i][0]][b+dirs[i][1]]==0){
                    if(a+dirs[i][0]>=0&&a+dirs[i][0]<n&&b+dirs[i][1]>=0&&b+dirs[i][1]<m){
                        Explore(a+dirs[i][0],b+dirs[i][1]);
                    }
                }
            }
            else if(A[a+dirs1[i][0]][b+dirs1[i][1]]=='|'){
                if(visited[a+dirs1[i][0]][b+dirs1[i][1]]==0){
                    if(a+dirs1[i][0]>=0&&a+dirs1[i][0]<n&&b+dirs1[i][1]>=0&&b+dirs1[i][1]<m){
                        Explore(a+dirs1[i][0],b+dirs1[i][1]);
                    }
                }
            }
            else if(A[a+dirs2[i][0]][b+dirs2[i][1]]=='-'){
                if(visited[a+dirs2[i][0]][b+dirs2[i][1]]==0){
                    if(a+dirs2[i][0]>=0&&a+dirs2[i][0]<n&&b+dirs2[i][1]>=0&&b+dirs2[i][1]<m){
                        Explore(a+dirs2[i][0],b+dirs2[i][1]);
                    }
                }
            }
        }
    }
    else if(A[a][b]=='|'){
        for(int i=0;i<=3;i++){
            if(A[a+dirs1[i][0]][b+dirs1[i][1]]=='+'){
                if(visited[a+dirs1[i][0]][b+dirs1[i][1]]==0){
                    if(a+dirs1[i][0]>=0&&a+dirs1[i][0]<n&&b+dirs1[i][1]>=0&&b+dirs1[i][1]<m){
                        Explore(a+dirs1[i][0],b+dirs1[i][1]);
                    }
                }
            }
            else if(A[a+dirs1[i][0]][b+dirs1[i][1]]=='|'){
                if(visited[a+dirs1[i][0]][b+dirs1[i][1]]==0){
                    if(a+dirs1[i][0]>=0&&a+dirs1[i][0]<n&&b+dirs1[i][1]>=0&&b+dirs1[i][1]<m){
                        Explore(a+dirs1[i][0],b+dirs1[i][1]);
                    }
                }
            }
        }
    }
    else if(A[a][b]=='-'){
        for(int i=0;i<=3;i++){
            if(A[a+dirs2[i][0]][b+dirs2[i][1]]=='+'){
                if(visited[a+dirs2[i][0]][b+dirs2[i][1]]==0){
                    if(a+dirs2[i][0]>=0&&a+dirs2[i][0]<n&&b+dirs2[i][1]>=0&&b+dirs2[i][1]<m){
                        Explore(a+dirs2[i][0],b+dirs2[i][1]);
                    }
                }
            }
            else if(A[a+dirs2[i][0]][b+dirs2[i][1]]=='-'){
                if(visited[a+dirs2[i][0]][b+dirs2[i][1]]==0){
                    if(a+dirs2[i][0]>=0&&a+dirs2[i][0]<n&&b+dirs2[i][1]>=0&&b+dirs2[i][1]<m){
                        Explore(a+dirs2[i][0],b+dirs2[i][1]);
                    }
                }
            }
        }
    }
    
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&A[i][j]);
            visited[i][j]=0;
        }
    }
    int x,y;
    scanf("%d %d",&x,&y);
    int endx,endy;
    scanf("%d %d",&endx,&endy);
    Explore(x,y);
    if(visited[endx][endy]==1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
  
    return 0;
}
