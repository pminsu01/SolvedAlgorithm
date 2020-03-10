#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include <sstream>

#define N 1000000

using namespace std;


int main()
{

	int count = 0;
	char *input_str = new char[N];

	scanf("%[^\n]", input_str); //  \n가 나올 때 까지 문자열 그대로 받는다.

	char *analysis_str = strtok(input_str, " "); //문자열을 조각한다. 자를 문자열이 없으면  NULL값을 반환한다.




	while (analysis_str != NULL) { //자른 문자열이 나오지 않을 때 까지.



		count++;

		analysis_str = strtok(NULL, " ");


	}

	cout << count << endl;




}
	
