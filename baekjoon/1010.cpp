#include<stdio.h>
#include<iostream>

using namespace std;

/* 조합은 오버플로우...*/

long long Factorial(int Number) {

	if (Number == 1) return 1;


	return Number * Factorial(Number - 1);

}

int main() {

	int term;

	scanf("%d", &term);

	while (term--) {

		int left;
		int right;
		long long result;
		scanf("%d %d", &left, &right);
		//right C  left

		long long temp = 1;
		long long temp1 = 1;

		if (right == left)  result = 1; // 스팟이 각각 하나 있을 때

		// 14  C 7, 14 C 8   14 C8 , right C left
		else {
			if (right / 2 < left) {

				left = right - left;
			}
			temp1 = Factorial(left);

			while (left  > 0) {


				temp = right*temp;
				right--;
				left--;
			}




			result = temp / temp1;
		}

		printf("%lld\n", result);

	}
}
