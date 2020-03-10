/*
음계
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char * delete_blank(char* input_main) {

	char * refine_input = new char[8];
	int j = 0;
	for (int i = 0; strlen(input_main); i++) {

		if (input_main[i] != ' ') {

			refine_input[j] = input_main[i];
			j++;
		}

		if (input_main[i] == NULL) break;
	}


	return refine_input;

}


int main() {

	int as_flag = 0;
	int des_flag = 0;
	char * input_str = new char[16];

	scanf("%[^\n]", input_str);
	input_str = delete_blank(input_str);


	for (int i = 0; i < strlen(input_str)-1; i++) {


		if (input_str[i] <= input_str[i + 1]) {

			as_flag = 1;

		}

		else if(input_str[i] >= input_str[i+1]){

			des_flag = 1;

		}

	}

	if (as_flag == 1 && des_flag == 0) cout << "ascending" << endl;
	if (as_flag == 0 && des_flag == 1) cout << "descending" << endl;
	if (as_flag * des_flag==1) cout << "mixed" << endl;


	return 0;





}
