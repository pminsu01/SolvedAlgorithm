#include<iostream>
#include<stdio.h>
using namespace std;

int a[1000][3];

int find_min(int a, int b){

	int result = a < b ? a : b;

	return result;


}
int main() {


	int number;
	scanf("%d", &number);

	for (int i = 0; i < number; i++) {

		for (int j = 0; j < 3; j++) {

			int input_number = 0;
			scanf("%d", &input_number);
			a[i][j] = input_number;
		}
	}

	for (int k = 0; k < number; k++) {

		a[k+1][0] = find_min(a[k][1], a[k][2]) + a[k+1][0];
		a[k+1][1] =find_min(a[k][0], a[k][2]) + a[k+1][1];
		a[k+1][2] = find_min(a[k][0], a[k][1]) + a[k+1][2];

	}

	int result = find_min(find_min(a[number-1][0], a[number-1][1]), a[number-1][2]);

	cout << result << endl;

}
