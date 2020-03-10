/*
2*n 타일링
*/
#include<iostream>
#include<stdio.h>

using namespace std;


int main() {

	int array[1001];
	int number;
	scanf("%d", &number);

	array[1] = 1;
	array[2] = 2;

	for (int i = 3; i <= number; i++) {


		array[i] = (array[i - 2] + array[i - 1]) % 10007;

	}

	printf("%d", array[number]);




}
