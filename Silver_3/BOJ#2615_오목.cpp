#include <iostream>
 
using namespace std;

int map[20][20];
int dir[8][2] = {{1,0},{0,1},{1,1},{-1,1}};
int visited[20][20][4];

int dfs(int y, int x, int d){
	int cnt = 1;
	visited[y][x][d] = 1;
	int ny = y + dir[d][0], nx = x + dir[d][1];
	if(map[y][x] == map[ny][nx])	cnt += dfs(ny, nx, d);
	
	return cnt;
}

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
}

void input(){
	for(int i = 1; i <= 19; i++)
		for(int j = 1; j <= 19; j++)
			cin >> map[i][j];
}

int main(){
	init();
	int flag = 1;
	input();
	
	for(int i = 1; i <= 19; i++){
		for(int j = 1; j <= 19; j++){
			if(map[j][i] == 0) continue; //0이면 무시 
			for(int k = 0; k < 4; k++){
				if(visited[j][i][k]) continue; //확인한 돌 무시  
				if(dfs(j,i,k) == 5){
					cout << map[j][i] << "\n" << j << " "<< i;
					flag = 0;
				}
			}
		}
	}
	if(flag) cout << "0"; 
	return 0;
}

