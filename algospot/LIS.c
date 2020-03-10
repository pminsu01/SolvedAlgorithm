#include<stdio.h>
#include<stdlib.h>


int find_num(int a[], int amount_1) {					//배열을 매개변수로 받는다. ,배열의 갯수도 받는다.

	int max_num = 0;									// 결과값 초기화
	int max[500];				//500개이하의 동적배열할당


	for (int a = 0; a < amount_1; a++) {				//max값 초기화

		max[a] = 1;
	}
	for (int i = 0; i < amount_1; i++) {				// 수열의 갯수로 for문 돌려


		for (int j = 0; j < i; j++) {					// 이중 for j가 먼저 늘어난다

			if (a[i] > a[j] && max[i] < max[j]+1) {		//a[i]가 a[j]가 컸을때 ,

				max[i] = max[j] + 1;
			}

			if (max_num < max[i]) {

				max_num = max[i];
			}
		}


	}

	return max_num;
}



int main() {


	int method_num = 0;
	int amount = 0;
	int result = 0;
	int num[500];

	scanf("%d", &method_num);


	while(method_num) {

	scanf("%d", &amount);

	for (int i = 0; i < amount; i++) {

		scanf("%d", &num[i]);
	}


		result = find_num(num,amount);

		printf("%d\n", result);

		method_num--;
	}

	return 0;
}
