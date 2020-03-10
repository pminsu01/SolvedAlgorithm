/*
DFS와 BFS
*/

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> vc[10001];
bool visit_dfs[1001];
bool visit_bfs[1001];
stack<int> stc;
queue<int> que;


void dfs(int start) {


	visit_dfs[start] = true;

	cout<<start<<" ";

	for (int i = 0; i < vc[start].size(); i++) {

		int index = vc[start][i];


		if (visit_dfs[index] == false) {

			dfs(index);

		}


	}




	}



void bfs(int start) {


	que.push(start);
	visit_bfs[start] = true;

	while (!que.empty()) {


		int front = que.front();
		que.pop();
		cout<<front<<" ";
		for (int i = 0; i < vc[front].size(); i++) {

			int index = vc[front][i];
			if (visit_bfs[index] == false) {

				visit_bfs[index] = true;
				que.push(index);

			}

		}




	}


}



int main() {

	int point;
	int line;
	int start;
	scanf("%d %d %d", &point, &line, &start);

	for (int i = 0; i < line; i++) {

		int st=0;
		int de=0;

		scanf("%d %d", &st, &de);

		vc[st].push_back(de);
		vc[de].push_back(st);

	}


	for (int i = 1; i <= point; i++) {

		sort(vc[i].begin(), vc[i].end());
	}



	dfs(start);
	cout << endl;
	bfs(start);


}
