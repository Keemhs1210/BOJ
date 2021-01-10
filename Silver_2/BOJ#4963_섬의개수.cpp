#include <iostream>
#include <cstring>
#define MAX 50

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

int w, h;
int cnt = 0;
//상하좌우대각선 검사 배열 
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int x, int y){
	
	visited[x][y] = true; //방문 체크 
	for(int i = 0; i < 8; i++){ //w,h의 배열을 넘지 않는 곳에서 연결된 섬 확인 
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		if(nx < 0 || nx >= w || ny < 0 || ny >=h)	continue;
		//재귀함수를 사용하여 연결된 섬 확인 
		if(map[nx][ny] == 1 && visited[nx][ny] == false) dfs(nx,ny);
	}
}

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(true){
		memset(map, 0, sizeof(map));  //배열 초기화 
        memset(visited, false, sizeof(visited)); //배열 초기화 
		cnt = 0;
		cin >> h >> w;
		if(w == 0 && h == 0) break; //Test Case 종료 
		
		for(int i = 0; i < w; i++)
			for(int j =0; j < h; j++)
				cin >> map[i][j];
	
		for(int i = 0; i < w; i++){
			for(int j =0; j < h; j++){
				if(map[i][j] == 1 && visited[i][j] == false){ //방문하지 않는 곳이면 dfs를 사용하여 섬 확인 
					cnt++; //다음 섬을 확일할 때마다 카운트 1씩 증가 
					dfs(i,j);
				}
			}
		}
		cout << cnt << "\n";
	}	
	return 0;
}
