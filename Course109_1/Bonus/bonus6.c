//
//  main.c
//  bonus6-2
//
//  Created by 孫渝鈞 on 2020/11/7.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
/*#include <stdio.h>

int gcd(int a, int b){
    int c;
    while(b!=0){
        c= a%b;
        a = b;
        b=c;
    }
    return a;
}

#define SIZE 100
int main() {
    //
    int n;
    int pax[SIZE],pay[SIZE],pbx[SIZE],pby[SIZE];
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d",&pax[i],&pay[i],&pbx[i],&pby[i]);
    }
    //
    for(int i=0; i<n; i++){
        int dx = pbx[i]-pax[i]; //3-1 =2
        int dy = pby[i]-pay[i]; //6-2 = 4
        if(dx<0) dx*=-1;
        if(dy<0) dy*=-1;
        int count=0;
        int g = gcd(dx,dy);
        int ey;
        if(g!=0){
            ey = dy/g;
            
            for(int a=0; a<=dy; a+=ey){
                count++;
            }
        } else{
            if(dx == 0){
                count = dy+1;
            } else if(dy==0){
                count = dx+1;
            }
        }
        printf("%d\n",count);
    }
    
     
    return 0;
}
#include <stdio.h>

int gcd(int a, int b){
    int c;
    while(b!=0){
        c= a%b;
        a = b;
        b=c;
    }
    return a;
}

#define SIZE 100
int main() {
    //
    int n;
    int pax[SIZE],pay[SIZE],pbx[SIZE],pby[SIZE];
    scanf("%d",&n);
    if(n<0 || n>100) return 0;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d",&pax[i],&pay[i],&pbx[i],&pby[i]);
    }
    //
    for(int i=0; i<n; i++){
        int dx = pbx[i]-pax[i]; //3-1 =2
        int dy = pby[i]-pay[i]; //6-2 = 4
      
        if(dy<0) dy*=-1;
        int count=0;
        int g = gcd(dx,dy);
        int ex,ey;
        if(g!=0){
            ex = dx/g;
            
            
            for(int a=0; a<=dy; a+=ey){
                count++;
            }
        }
        else{
            if(dx == 0){
                count = dy+1;
            }
        else if(dy==0){
                count = dx+1;
            }
        }
        printf("%d\n",count);
    }
    
     
    return 0;
}*/
#include <stdio.h>

int gcd(int a, int b){
    int c;
    while(b!=0){
        c= a%b;
        a = b;
        b=c;
    }
    return a;
}

#define SIZE 100
int main() {
    //
    int n;
    int pax[SIZE],pay[SIZE],pbx[SIZE],pby[SIZE];
    scanf("%d",&n);
    if(n<0 || n>100) return 0;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d",&pax[i],&pay[i],&pbx[i],&pby[i]);
    }
    //
    for(int i=0; i<n; i++){
        int dx = pbx[i]-pax[i]; //3-1 =2
        int dy = pby[i]-pay[i]; //6-2 = 4
        if(dx<0) dx*=-1;
        if(dy<0) dy*=-1;
        int count=0;
        int g = gcd(dx,dy);
        int ey;
        if(g!=0){
            ey = dy/g;
            count = dy/ey + 1;
        } else{
            if(dx == 0){
                count = dy+1;
            } else if(dy==0){
                count = dx+1;
            }
        }
        printf("%d\n",count);
    }
    
     
    return 0;
}
