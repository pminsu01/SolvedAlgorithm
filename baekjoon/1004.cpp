#include<stdio.h>
#include<math.h>

using namespace std;

int main() {


	//중심과 중심의 거리가 반지름 보다 작으면 속해 있다는 것이다.

	int term = 0;
	scanf("%d",&term);
	int CirArray[50][3] = { 0 };
	bool BoolOneCir[50] = { false }; // 첫번째 점이 원에 포함되었을 여부의 배열
	bool BoolTwoCir[50] = { false }; // 두번째 점이 원에 포함되었을 여부의 배열
	while (term--) {

		int X1, Y1;
		int X2, Y2;

		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2); // 점 2개.

		int CirNum = 0;
		scanf("%d", &CirNum);

		for (int i = 0; i < CirNum; i++) {

			int X=0;
			int Y=0;
			int R=0;
			scanf("%d %d %d", &X, &Y, &R);
			BoolOneCir[i] = false;	// 다시초기화
			BoolTwoCir[i] = false; //다시 초기화

			CirArray[i][0] = X;
			CirArray[i][1] = Y;
			CirArray[i][2] = R;

			int X1Length = pow((X - X1), 2);
			int Y1Length = pow((Y - Y1), 2);

			int X2Length = pow((X - X2), 2);
			int Y2Length = pow((Y - Y2), 2);

			int Radious = pow(R, 2);


			if ((X1Length + Y1Length) < Radious) { // 빼는 것 있었음... 까먹..
				BoolOneCir[i] = true;
			}

			if((X2Length + Y2Length) <Radious) {
				BoolTwoCir[i] = true;

			}


		}

		int temp = 0;
		int temp2 = 0;
		for (int i = 0; i < CirNum; i++) {
			if (BoolOneCir[i] == true || BoolTwoCir[i] == true) {

				temp++;

			}

			if (BoolOneCir[i] == true && BoolTwoCir[i] == true) {

				temp2++;
			}



		}

		int result = abs(temp2 - temp);



		printf("%d\n", result);

	
	}
}
