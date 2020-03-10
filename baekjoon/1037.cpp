include<stdio.h>
#include<math.h>

using namespace std;

int main() {


	int Num=0;
	int min=1000000;
	int max=0;
	int NumArray[50];
	scanf("%d", &Num);

	int result = 0;

	if (Num >= 2) {

		for (int i = 0; i < Num; i++) {

			int temp = 0;
			scanf("%d", &temp);

			if (max < temp) {

				max = temp;
			}

			if (min > temp) {

				min = temp;
			}

		}

		//printf("max: %d, min : %d\n", max, min);
		result = max * min;

	}

	else if (Num = 1) {

		int temp2 = 0;
		scanf("%d", &temp2);

		result = pow(temp2, 2);

	}
	// 2 (1,2)
	// 4 (1,2,4)
	// 6 (1,2,3,6)
	// 8 (1,2,4,8)
	// 9 (1,3,9)
	// 10(1,2,5,10)
	// 12(1,2,3,6,12)
	// 14(1,2,7,14)
	// 15(1,3,5,15)
	// 16(1,2,4,8,16)
	// 18(1,2,3,9,18)
	// 20(1,2,4,5,10,20)
	// 21(1,3,7,21)
	// 22(1,2,11,22)
	// 24(1,2,3,4,6,8,12,24)
	// 25(1,5,25)
	// 26(1,2,13,26)
	// 27(1,3,9,27)
	// 28(1,2,4,7,14,28)
	// 30(1,3,10,30)
	// 32(1,2,4,8,16,32)
	// 33(1,3,11,33)
	// 34(1,2,17,34)
	// 35(1,5,7,35)
	// 36(1,2,3,4,6,9,12,18,36)
	// 38(1,2,19,38)
	// 39(1,3,13,39)
	// 40(1,2,4,5,8,20,40)

	printf("%d\n", result);

}
