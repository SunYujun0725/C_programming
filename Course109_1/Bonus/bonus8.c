//
//  main.c
//  Bonus8
//
//  Created by 孫渝鈞 on 2020/11/14.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
/*
給定一整數 X，試求兩正整數 a,b，使得 LCM(a,b)=X，且 max(a,b)盡可能的小。
輸入格式
輸入一整數 X，1?X?1012。
輸出格式
輸出兩正整數 a 與 b，以空白隔開，輸出順序不限。
Ryan notes:
LCM = a*b/GCD, if GCD is 1 then a*b is smallest.
Basically try to get two co-prime numbers below sqrt(n) of which their product is equals to n.
since we need to make the max(a,b) as small as possible, so we need to make a( or b) as close to sqrt(n) as possible.
*/
#include<stdio.h>
#include<math.h>
long long gcd (long long a, long long b){
    long long remainder;
    while(b!=0){
        remainder = a%b;
        a=b;
        b=remainder;
    }
    return a;
}
int main(){
    long long n;
    scanf("%lld",&n);
    if(n<1 || n>pow(10,12)){
        return 0;}
    long long a=(long long) sqrt(n);
    long long b;
    for(;a>=1; a--){
        if(n%a==0){
            b = n/a;
            if(gcd(a,b)==1){
                printf("%lld %lld\n",a,b);
                break;
            }
            else{
                continue;
            } 
        }
    }
}
