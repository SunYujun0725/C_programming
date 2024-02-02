//
//  main.c
//  Bonus 2
//
//  Created by 孫渝鈞 on 2020/10/23.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>

int main() {
    char data[33];
    for(int a=0; a<32; a++) {
        data[a]='0';
    }
    data[32]='\0';
    int n;
    int isNegative=0;
    scanf("%d",&n); //-85 => 10101011
    if(n<0) {
        isNegative = 1;
        n = -1*n-1; //84 => 01010100
    }
    int i=0;
    while(n!=0) {
        int m = n%2;
        if(isNegative) {
            m = !m;
        }
        data[i++]='0'+m;
        n=n/2;
    }
    if(isNegative) {
        //data[7]='1';
        data[i]='1';
    }
    for(int j=0; j<=i; j++) {
        printf("%c",data[i-j]);
        if((i-j)%4==0) printf(" ");
    }

    printf("\n");

    return 0;
}
