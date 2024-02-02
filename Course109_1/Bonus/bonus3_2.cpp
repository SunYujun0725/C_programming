//
//  main.cpp
//  Bonns 3-2
//
//  Created by 孫渝鈞 on 2020/11/15.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//

#include<iostream>
#include<math.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void print(double (*pArray)[4], int iWidth,int iHigh);

int main(){
    int n,m;
    double a[3][4] = {
        {100, 10, 1, 10},
        {400, 20, 1, 20},
        {900, 30, 1, 10},
    };//第四列是增廣矩陣

    int i,j;
    n = 3;
    cout<<"輸入方程組介數：";
    cout<<n<<endl;
    cout<<"輸入增廣矩陣："<<endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < n + 1;j++){
            cout<<a[i][j]<<"   ";
        }
        cout<<endl;
    }


    for(j = 0; j < n; j++){
        double max = 0;
        double imax = 0;
        for(i = j; i < n; i++){
            if(imax < fabs(a[i][j])){
                imax = fabs(a[i][j]);
                max = a[i][j];//得到各行中所在列最大元素
                m = i;
            }
        }

        if(fabs(a[j][j]) != max) {
            double b = 0;
            for(int k = j;k < n + 1; k++){
                b = a[j][k];
                a[j][k] = a[m][k];
                a[m][k] = b;
            }
        }

        print(a, 3, 4);

        for(int r = j;r < n + 1;r++){
            a[j][r] = a[j][r] / max;//讓該行的所在列除以所在列的第一個元素，目的是讓首元素為1
        }
        print(a, 3, 4);

        for(i = j + 1;i < n; i++){
            double c = a[i][j];
            if(c == 0)  continue;
            for(int s = j;s < n + 1;s++){
                double tempdata = a[i][s];
                a[i][s] = a[i][s] - a[j][s] * c;//前後行數相減，使下一行或者上一行的首元素為0
                print(a, 3, 4);
            }
            print(a, 3, 4);
        }
        print(a, 3, 4);
    }

    for(i = n - 2; i >= 0; i--){
        for(j = i + 1;j < n; j++){
            double tempData = a[i][j];
            double data1 = a[i][n];
            double data2 = a[j][n];
            a[i][n] = a[i][n] - a[j][n] * a[i][j];
            print(a, 3, 4);
        }
    }
    print(a, 3, 4);
    
    cout<<"方程組的解是："<<endl;
    for(int k = 0; k < n; k++){
        cout<<"x"<<k<<" = "<<a[k][n]<<endl;
    }
}


void print(double (*pArray)[4], int iWidth,int iHigh) {
    std::cout<<"Array: "<<"\n";
    for(int i = 0; i < iWidth; i++){
        for(int j = 0; j < iHigh;j++){
            cout<<pArray[i][j]<<"   ";
        }
        cout<<endl;
    }
}
