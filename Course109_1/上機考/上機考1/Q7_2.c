//
//  main.c
//  7-4
//
//  Created by 孫渝鈞 on 2020/10/16.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//確認整數
bool IsInteger(double val)
{
    int truncated = (int)val;
    return (val == truncated);
}
//掃描點數
int CheckPoint(int x1, int y1, int x2, int y2)
{
    int PointNum=0;
    float value=0;
    int m=0;
    //垂直線
    if(x2==x1)
        return y2-y1+1;
    //求斜率
    m=(y2-y1)/(x2-x1);
    //水平掃描整數點
    for(int i=x1; i<=x2 ; i++)
    {
        value = m*(i-x1) + y1;
        //printf("check value = %f\n", value);
        if(IsInteger(value))
        {
            PointNum += 1;
            //printf("Point num = %d\n", PointNum);
        }
        //為大數字確認進度
        if(i%10000001==0 && i>0)
        {
           // printf("i = %d\n", i);
        }
    }
    return PointNum;
}
int main() {
    
    int N;
    scanf("%d", &N);
    int X1[N], Y1[N], X2[N], Y2[N];
    for(int i=0 ; i<N ; i++)
    {
        scanf( "%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
    }
    printf("答案為\n");
    for(int i=0 ; i<N ; i++)
    {
        if(X2[i] > X1[i])
        {
            printf("CheckPoint is %d\n", CheckPoint(X1[i], Y1[i], X2[i], Y2[i]));
         
        }
        else
        {
            printf("CheckPoint is %d\n", CheckPoint(X2[i], Y2[i], X1[i], Y1[i]));
           
        }
    }
    return 0;
}
