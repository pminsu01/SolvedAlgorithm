/*

백준 17143문제

제목 : 낚시왕
주소 : https://www.acmicpc.net/problem/17143
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)

둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다.
(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.

*/
struct JossValue {

	int direction; // 1: up, 2: under, 3: right, 4: left
	int size;
	int speed;

};

//JossValue map[100][100] = { {0,0,0}, };
int x; //행의 갯수
int y; // 열의 갯수
int Num; // 조스의 마리수
vector<JossValue> tempMap[101][101]; //임시 Mapping
vector<JossValue> Map[101][101];  // 본 Mapping
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 }; //조스의 이동 Direction 별로 배열 작성
int result = 0; //최종 결과, 답


/*
조스가 움직이는 함수
*/
void moveJoss() {

	// 1: up , 2: under, : x값 변함
	// 3: right, 4: left : y값 변함
	// 왼쪽과 위의 경계선은 1
	// 오른쪽 경계선은 y, 아랫쪽 경계선은 x
	// 겹칠 경우에는 크기가 큰 상어가 작은 상어를 모두 잡아먹는다.
	// 행으로 움직였을 때 1로 가면 방향이
	// 2*(y-1), 2*(x-1) 일 때 원래 순서대로 돌아온다.

	int yStay = 2 * (y - 1);
	int xStay = 2 * (x - 1);

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {

			tempMap[i][j] = Map[i][j];
			Map[i][j].clear();

		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {

			if (tempMap[i][j].size() == 0) continue;


			int nx = i;
			int ny = j;
			int tempDir = tempMap[i][j].front().direction;
			int tempSpeed = tempMap[i][j].front().speed;
			int tempSize = tempMap[i][j].front().size;


			if (tempDir == 1 || tempDir == 2) { //x 좌표만 바뀔 때(위, 아래 이동)

				if (tempSpeed > xStay) {
					tempSpeed = tempSpeed % xStay;
				}


				for (int a = 0; a < tempSpeed; a++) {

					nx = nx + dx[tempDir - 1];
					ny = ny + dy[tempDir - 1];

            /*
            Map의 범위를 넘어 갔을 때
              */
					if (nx < 1) {
						tempDir = 2;
						nx = 2;
					}

					if (nx > x) {

						tempDir = 1;
						nx = x - 1;
					}


				}

			}

			else{ //y좌표만 바뀔 때 (오른쪽, 왼쪽 이동)
				if (tempSpeed > yStay) {
					tempSpeed = tempSpeed % yStay;
				}


				for (int j = 0; j < tempSpeed; j++) {

					nx = nx + dx[tempDir - 1];
					ny = ny + dy[tempDir - 1];

					if (ny < 1) {
						tempDir = 3;
						ny = 2;
					}

					if (ny > y) {
						tempDir = 4;
						ny = y - 1;
					}

				}


			}

			JossValue jossvalue;
			jossvalue.speed = tempSpeed;
			jossvalue.direction = tempDir;
			jossvalue.size = tempSize;
			Map[nx][ny].push_back(jossvalue);
			//cout << "움직 인 후 조스 : " << nx << " , " << ny << endl;


		}
	}
}

/*
조스끼리 잡아먹는 함수 : Size가 큰 조스가 작은 조스를 잡아먹는다.
*/
void surviceJoss() {

	for (int i = 1; i <= x; i++) {

		for (int j = 1; j <= y; j++) {

			if (Map[i][j].size() > 1) { // 두개 이상의 조스가 있을 경우에는 큰 사이즈 조스의 Index를 찾는다.
				vector<int> tempIndex;
				for (int a = 0; a < Map[i][j].size(); a++) {
					int temp = Map[i][j].at(a).size;
					tempIndex.push_back(temp);
				}
				int index = max_element(tempIndex.begin(), tempIndex.end()) - tempIndex.begin();

				JossValue jossvalue;
				jossvalue.direction = Map[i][j].at(index).direction;
				jossvalue.size = Map[i][j].at(index).size;
				jossvalue.speed = Map[i][j].at(index).speed;

				Map[i][j].clear();
				Map[i][j].push_back(jossvalue);

			}
		}
	}
}

/*
낚시왕이 조스를 잡는 함수
*/
void catchJoss() {


	int startPoint = 1; //y좌표(열) 시작
	while (startPoint <= y) {

		for (int i = 1; i <= x; i++) {
			if (Map[i][startPoint].size() == 0) {
				continue;
			}
			else {
				result += Map[i][startPoint].front().size;
				Map[i][startPoint].clear();
				break;
			}
		}
		moveJoss();
		surviceJoss();
		startPoint++;
	}

}

int main() {

	cin >> x >> y >> Num;
	if (Num == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < Num; i++) {

		int tempX, tempY, tempSpeed, tempDirection, tempSize;

		cin >> tempX >> tempY >> tempSpeed >> tempDirection >> tempSize;
		JossValue jossvalue;
		jossvalue.direction = tempDirection;
		jossvalue.size = tempSize;
		jossvalue.speed = tempSpeed;

		Map[tempX][tempY].push_back(jossvalue);
	}
	catchJoss();
	cout << result << endl;
}
