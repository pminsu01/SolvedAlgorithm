/*
백준 16235문제
https://www.acmicpc.net/problem/16235

해당 문제는 단순 시뮬레이션 문제
vector를 사용할 수도 있고 Deque를 사용할 수도 있다.

이 문제 푸는데 오래 걸린 이유는
처음 영양분 5에서 입력된 영양분을 더해줘서 오래걸렸다..
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//N은 Map크기, M은 나무의 수, K는 년도
int N, M, K;
int eatMap[11][11]; //땅의 영양분 Map
int wintereatMap[11][11]; //겨울에 주입되는 영양분 Map

vector<int> oldTreeMap[11][11];		// Tree의 나이
vector<int> dieoldTreeMap[11][11]; // 죽은 Tree 나이

/*
봄:
양분의 양과 나무의 갯수가 달라진다.
*/
void spring() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			vector<int> tempvc; //임시 나무 나이 vector
			vector<int> vc = oldTreeMap[i][j]; //각 칸에 있는 나무들의 나이
			oldTreeMap[i][j].clear();
			sort(vc.begin(), vc.end()); // 오름차순 정리

			for (int a = 0; a < vc.size(); a++) {
				int tempAge = vc.at(a); //a번째 나무의 나이
				int removeAge = 0;
				if (tempAge <= eatMap[i][j]) { //먹이가 나이가보다 클 경우에는 나이만큼 먹이를 먹고 먹이는 감소
					eatMap[i][j] -= tempAge; //양분이 줄어든다.
					tempAge++; //한살이 늘었다.
					tempvc.push_back(tempAge); //나이가 늘어난 값을 저장한다.
				}

				else {
					dieoldTreeMap[i][j].push_back(tempAge); //죽은 나무 map에 push한다. 그리고 해당 나무는 죽는다. 해당 나무 처리는 summer에서 진행한다.
				}
			}
			oldTreeMap[i][j].clear();
			oldTreeMap[i][j] = tempvc;
		}
	}
}

/*
여름
각 행렬의 양분의 양이 달라진다.
*/
void summer() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int a = 0; a < dieoldTreeMap[i][j].size(); a++) {
				eatMap[i][j] += (dieoldTreeMap[i][j].at(a) / 2);
			}
			dieoldTreeMap[i][j].clear();
		}
	}



}


int dx[] = { -1,-1,-1, 0, 0, 1,1,1 };
int dy[] = { -1, 0, 1,-1, 1,-1,0,1 };

/*
가을 :
(r - 1, c - 1), (r - 1, c), (r - 1, c + 1), (r, c - 1), (r, c + 1), (r + 1, c - 1), (r + 1, c), (r + 1, c + 1) 이다.
나무의 갯수가 달라진다.
*/
void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int a = 0; a < oldTreeMap[i][j].size(); a++) {
				if (oldTreeMap[i][j].at(a) % 5 == 0 && oldTreeMap[i][j].at(a) > 0) {
					for (int b = 0; b < 8; b++) {
						int nx = i + dx[b];
						int ny = j + dy[b];
						if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
						oldTreeMap[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

/*
겨울 :
각 행렬의 양분의 양이 달라진다.
*/
void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			eatMap[i][j] += wintereatMap[i][j];
		}
	}
}

void survive() {

	int result=0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result += oldTreeMap[i][j].size();
		}
	}
	cout << result << endl;
}



int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int count = 0;
			cin >> count;
			eatMap[i][j] = 5;
			wintereatMap[i][j] = count;
		}
	}

	for(int i = 1; i <= M; i++) {
		int x = 0;
		int y = 0;
		int old = 0;
		cin >> x  >> y >> old;
		oldTreeMap[x][y].push_back(old);
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();

	}

	survive();

}
