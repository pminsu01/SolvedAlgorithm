/*
이친수
*/

#include<iostream>
#include<stdio.h>


using namespace std;

int main() {

	long many_kind[91] = { 0 };
	int range_number;
	scanf("%d", &range_number);

	many_kind[1] = 1;
	many_kind[2] = 1;

	for (int i = 3; i <= range_number; i++) {

		//("%d %d %d\n", many_kind[i - 2], many_kind[i - 1], many_kind[i]);
		many_kind[i] = many_kind[i - 2] + many_kind[i - 1];
	}

	printf("%lld", many_kind[range_number]);
}
