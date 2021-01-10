#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define max 1001

using namespace std;

struct tomato {
	int y, x;
};

queue<tomato> q;

int N, M;
int map[max][max];
int dx[] = { 0, 0, -1, 1 }; //상하좌우 지정 
int dy[] = { 1, -1, 0, 0 };

bool isInside(int ny, int nx) {
	return (nx >= 0 && ny >= 0 && nx < M && ny < N);
}

void bfs(void) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isInside(ny, nx) == 1 && map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int solve() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			if (result < map[i][j]) result = map[i][j];
		}
	}
	cout << result - 1;
	return 0;
}
void input(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push({ i,j }); //익은 토마토 큐에 추가 
		}
	}

}

void init(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(map, 0, sizeof(map));
}

int main(void) {
	init();
	input();
	bfs();
	solve();
	return 0;
}