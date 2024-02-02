//
//  main.cpp
//  6-2
//
//  Created by 孫渝鈞 on 2020/11/25.
//  Copyright © 2020 孫渝鈞. All rights reserved.
//
#include<iostream>
using namespace std;
    string prt[4]={"****","*  *","*   ","   *"};
    int main(){

    string input;
    cin >> input;

    int mynum[10][7]={
    {0,1,1,1,1,1,0},
    {3,3,3,3,3,3,3},
    {0,3,3,0,2,2,0},
    {0,3,3,0,3,3,0},
    {1,1,1,0,3,3,3},
    {0,2,2,0,3,3,0},
    {0,2,2,0,1,1,0},
    {0,1,1,1,3,3,3},
    {0,1,1,0,1,1,0},
    {0,1,1,0,3,3,0}};

    for(int i=0;i<7;i++){
        for(int j=0;j<input.length();j++){
            cout << prt[mynum[input[j]-'0'][i]]<<' ';
        }
        cout <<endl;
    }


    return 0;


}

