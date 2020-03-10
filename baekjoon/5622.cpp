/*
다이얼
*/

#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>



using namespace std;




int main() {

	int array_int[29] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };

	char *input_int = new char[15];
	int start = 65;
	int last = 90;

	int count = 0;


	scanf("%[^\n]", input_int);

	for (int i = 0; i < strlen(input_int); i++) {

		int value = input_int[i] - 65;
		count += array_int[value];
		count++;


	}


	cout << count << endl;





	return 0;



}
