/*
연구소
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int map[8][8] = { 0, };
bool visit[8][8] = { false, };

int mapx = 0;
int mapy = 0;
int maxTemp = 0;
int result = 0;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

struct virus {

	int x;
	int y;

};

vector<virus> vc; // 바이러스들의 vc
queue<pair<int, int>> que;

void bfs() {

	int backup[8][8] = { 0, };

	for (int i = 0; i < mapx; i++) {
		for (int j = 0; j < mapy; j++) {

			backup[i][j] = map[i][j];

		}

	}

	for (int i = 0; i < vc.size(); i++) {

		int virx = vc.at(i).x;
		int viry = vc.at(i).y;

		que.push({ virx, viry });


		while (!que.empty()) {

			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			visit[x][y] = true;

			for (int i = 0; i < 4; i++) {

				int ndx = x + dx[i];
				int ndy = y + dy[i];


				if (ndx<0 || ndx>=mapx || ndy<0 || ndy>=mapy) continue;

				if (backup[ndx][ndy] == 0 && visit[ndx][ndy] == false) {

					backup[ndx][ndy] = 2;
					visit[ndx][ndy] = true;
					que.push({ ndx,ndy });


				}

			}

		}
	}


	for (int i = 0; i < mapx; i++) {
		for (int j = 0; j < mapy; j++) {

			int temp = backup[i][j];
			visit[i][j] = false;
			if (temp == 0) {

				maxTemp++;
			}
		}

	}

	if (maxTemp > result) {

		result = maxTemp;
	}

	maxTemp = 0;



}


void bukdfs(int count, int sx, int sy) {

	if (count == 3) {

		bfs();
		return;

	}

	for (int x = sx; x < mapx; x++) {

		for (int y = sy; y < mapy; y++) {

			if (map[x][y] == 0) {

				map[x][y] = 1;
				bukdfs(count + 1, x, y);
				map[x][y] = 0;
			}

		}
		sy = 0;


	}



}
int main() {

	cin >> mapx;
	cin >> mapy;
	for (int i = 0; i < mapx; i++) {

		for (int j = 0; j < mapy; j++) {

			int temp;
			cin >> temp;
			map[i][j] = temp;

			if (temp == 2) {

				struct virus vr;
				vr.x = i;
				vr.y = j;
				vc.push_back(vr);
			}


		}
	}


	bukdfs(0, 0, 0);
	cout << result << endl;

	return 0;

}
