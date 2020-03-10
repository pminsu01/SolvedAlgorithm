#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stack>
#include<vector>

using namespace std;

int x; // row
int y; // clumn
int point = 0;

//int **visitField = new int*[50];
//int **Field = new int*[50];

int visitField[50][50] = { 0 };
int Field[50][50] = { 0 };

int Array_Y[4] = { -1,0,1,0 };
int Array_X[4] = { 0,-1,0,1 };


void DFS(int startY, int startX) { //x좌표 y좌표

	//cout << startY << "," << startX << endl;

	visitField[startY][startX] = true;

	for (int i = 0; i < 4; i++) {


		int Direction_Y = startY + Array_Y[i];
		int Direction_X = startX + Array_X[i];


		//cout << "DY : " << Direction_Y << "DX : " << Direction_X << endl;
		if(Direction_X >= 0 && Direction_Y >= 0 && Direction_X < x && Direction_Y < y) {

			if (Field[Direction_Y][Direction_X] ==1 && visitField[Direction_Y][Direction_X] == false) {

				visitField[Direction_Y][Direction_X] = true;

				DFS(Direction_Y, Direction_X);

			}

		}

	}



}

int main() {

	int term;

	cin >> term;

	while (term--) {

		//중복된다. 다시 시도할 것


		cin >> x >> y >> point;
		int count = 0;



		/*

		X, Y 만큼 동적 배열 할당해주기 방문한 곳
		2차원 배열 생성

		1) 방문 Field
		2) Field
		3) Field에 배추있는 곳 채워 넣기

		*/


		/*
		for (int i = 0; i < y; i++) {

			visitField[i] = new int[x];
			Field[i] = new int[x];
			memset(visitField[i], 0, sizeof(int)*y); //0으로 초기화
			memset(Field[i], 0, sizeof(int)*y);

		}
		*/


		for (int i = 0; i < x; i++) {

			for (int j = 0; j < y; j++) {

				visitField[i][j] = 0;
				Field[i][j] = 0;
			}
		}



		for (int j = 0; j < point; j++) {

			int tempX=0;
			int tempY=0;

			cin >> tempX >> tempY;
			Field[tempY][tempX] = 1;

		}

		/*
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++){
				cout << Field[i][j] << " ";

			}

			cout << endl;

		}
		*/


		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++)
			{
				if (Field[j][i] == 1 && visitField[j][i] == false) {

					DFS(j, i);
					count++;
					//cout << "count 끝" << endl;
				}
			}
		}


		cout << count << endl;

	}

}
