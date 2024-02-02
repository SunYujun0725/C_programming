//
//  main.c
//  Bonus 5
//
//  Created by 孫渝鈞 on 2020/10/23.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
//
#include <stdio.h>
int main(){
    int M,D;
    scanf("%d%d",&M,&D); //3/31
    if(M<1 || M>12 || D<1 || D>31){
        printf("invalid\n");
    } else{
        //
        int days[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
        int begins[13]={22,52,80,111,141,172,204,235,266,296,327,357,1};
        int ends[13]={51,79,110,140,171,203,234,265,295,326,356,365,21};
        char names[13][20] = {"Aquarius", "Pisces","Aries","Taurus","Gemini","Cancer",
        "Leo","Virgo","Libra","Scorpio","Sagittarius","Capricorn","Capricorn"};
        if(M==2 && D==29){
            printf("Pisces\n");
        } else{
            //365 days a year
            //計算M+D ->該年的第幾天
            int sum=0;
            for(int n=1; n<M; n++){// M:3 -> n=1..2
                sum+=days[n-1];
            }
            sum+=D;
            //printf("第幾天:%d\n",sum);
            //check ranges
            for(int n=0; n<13; n++){
                if(sum>=begins[n] && sum<=ends[n]){
                    printf("%s\n",names[n]);
                }
            }
        }
        return 0;
    }
}
