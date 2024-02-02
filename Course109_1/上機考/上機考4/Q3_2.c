//
//  main.c
//  3-2.
//
//  Created by 孫渝鈞 on 2020/12/2.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>
int n,m;
char map[110][110];
int num[110][110];
int visited[110][110];
void Explore(int x,int y){
    visited[x][y]=1;
    if(map[x][y]=='|'){
        if((map[x-1][y]=='|'||map[x-1][y]=='+')&&x-1>=0&&visited[x-1][y]==0&&num[x][y]>=num[x-1][y]){
            Explore(x-1,y);
        }
         if((map[x+1][y]=='|'||map[x+1][y]=='+')&&x+1<n&&visited[x+1][y]==0&&num[x][y]>=num[x+1][y]){
                   Explore(x+1,y);
        }
        
    }
    else if(map[x][y]=='-'){
        if((map[x][y+1]=='-'||map[x][y+1]=='+')&&y+1<m&&visited[x][y+1]==0&&num[x][y]>=num[x][y+1]){
            Explore(x,y+1);
        }
        if((map[x][y-1]=='-'||map[x][y-1]=='+')&&y-1>=0&&visited[x][y-1]==0&&num[x][y]>=num[x][y-1]){
            Explore(x,y-1);
        }
    }
    else if(map[x][y]=='+'){
        if((map[x][y+1]=='-'||map[x][y+1]=='+')&&y+1<m&&visited[x][y+1]==0&&num[x][y]>=num[x][y+1]){
            Explore(x,y+1);
        }
        if((map[x][y-1]=='-'||map[x][y-1]=='+')&&y-1>=0&&visited[x][y-1]==0&&num[x][y]>=num[x][y-1]){
            Explore(x,y-1);
        }
        if((map[x-1][y]=='|'||map[x-1][y]=='+')&&x-1>=0&&visited[x-1][y]==0&&num[x][y]>=num[x-1][y]){
            Explore(x-1,y);
        }
         if((map[x+1][y]=='|'||map[x+1][y]=='+')&&x+1<n&&visited[x+1][y]==0&&num[x][y]>=num[x+1][y]){
                   Explore(x+1,y);
        }
        
    }
    
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",map[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&num[i][j]);
            visited[i][j]=0;
        }
    }
    int x,y,p1,p2;
    scanf("%d %d %d %d",&x,&y,&p1,&p2);
    Explore(x,y);
    if(visited[p1][p2]==1){
        printf("YES\n");
        
    }
    else{
        printf("NO\n");
    }
    return 0;
}
