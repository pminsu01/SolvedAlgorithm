/*
 벌집
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;


int main() {

	int input_number=0;
	int answer = 0;
	scanf("%d", &input_number);
	for (int i = 1;i< 1000000000; i++) {

		int array_input_number = 3 * pow(i,2) - 3 * i + 1;

		if (array_input_number >= input_number) {

			printf("%d", i);
			break;

		}



	}


}
