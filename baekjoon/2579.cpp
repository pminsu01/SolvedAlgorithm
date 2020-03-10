/*
계단 오르기
*/
#include<iostream>
#include<stdio.h>

using namespace std;

int stair[301] = { 0 };
int stair_array[301] = { 0 };

int max(int a, int b) {

	return(a > b ? a : b);
}
int main() {


	int stair_num;

	scanf("%d", &stair_num);

	for (int i = 1; i <= stair_num; i++) {

		scanf("%d", &stair[i]);

	}

	stair_array[0] = stair[0];
	stair_array[1] = max(stair[0]+stair[1],stair[1]);
	stair_array[2] = max(stair[0]+stair[2],stair[1]+stair[2]);

	for (int j = 3; j <= stair_num; j++) {

		stair_array[j] = max((stair_array[j - 3] + stair[j-1]+stair[j]), (stair_array[j - 2] + stair[j]));


	}

	cout << stair_array[stair_num];

}
