/*
 * @Author: SunYujun0725 91317039+SunYujun0725@users.noreply.github.com
 * @Date: 2020-11-25 22:43:09
 * @LastEditors: SunYujun0725 91317039+SunYujun0725@users.noreply.github.com
 * @LastEditTime: 2024-02-02 16:06:07
 * @FilePath: /C_Programming/C上機考/上機考3./行列式.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>   
#include <iostream>  
#include<cmath>
using namespace std;
int n = 0;
double A[9][9];
/*
double determinant(double B[9][9],int level){
	long double sum = 0.0;
	int x = 1;
	int y = 0;
	int z = 1;

	double **b = new double*[level];
	for (int m = 0; m < level; m++) {
		b[m] = new double[level];
	}
	
	if (level == 2)
		return ( B[0][0] * B[1][1] - B[0][1] * B[1][0] );

	else if (level == 3) {

		return B[0][0] * B[1][1] * B[2][2] + B[0][1] * B[1][2] * B[2][0] + B[0][2] * B[1][0] * B[2][1] - B[0][2] * B[1][1] * B[2][0] - B[1][2] * B[2][1] * B[0][0] - B[2][2] * B[1][0] * B[0][1];
	}

	else {
// 
		for (int i = 0; i < level - 1; i++) {
			z = 1;
			for (int j = 0; j < level - 1; j++) {
				b[i][j] = B[y][y] * B[x][z] - B[y][z] * B[x][y];
				z++;
			}
			x++;
		}

		sum += ( 1 / pow((double)B[0][0], level - 2) ) * determinant(b, level - 1);

		return sum;
	}
}
*/
double determinant(int m,double data[9][9] ){
	double sum = 0.0;
	int x = 1,y = 0,z = 1,ans;
	
	
	double b[9][9];

	
	if (m == 2) {
		ans=( data[0][0] * data[1][1] - data[0][1] * data[1][0] )	;
		return ans;
	}
	else if (m == 3) {
		ans=data[0][0] * data[1][1] * data[2][2] + data[0][1] * data[1][2] * data[2][0] + data[0][2] * data[1][0] * data[2][1] - data[0][2] * data[1][1] * data[2][0] - data[1][2] * data[2][1] * data[0][0] - data[2][2] * data[1][0] * data[0][1];
		return ans;
	}

	else {

		for (int i = 0; i < m - 1; i++) {
			z = 1;
			for (int j = 0; j < m - 1; j++) {
				b[i][j] = data[y][y] * data[x][z] - data[y][z] * data[x][y];
				z++;
			}
			x++;
		}

		sum += ( 1 / pow(data[0][0], m - 2) ) * determinant(m - 1, b);
		ans=sum;
		
		return ans;
		
	}
}


int main(){
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lf", &A[i][j]);
	printf("%f\n",determinant(n,A));	
	
	return 0;	
}


