#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 501
using namespace std;

int T;
char cmd[MAX];

//상하좌우 
int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {1, 0, -1, 0}; 

void solve(){
	int x, y;
	int min_x, min_y, max_x, max_y;
	x = y = min_x = min_y = max_x = max_y = 0;
	int direction = 0; 

	cin >> cmd;
	int n = strlen(cmd);

	for(int i = 0; i < n; i++){
		switch (cmd[i]){
			case 'F' :
				x += dx[direction];
				y += dy[direction];
				break;
			case 'B' :
				x -= dx[direction];
				y -= dy[direction];
				break;
			case 'L' :
				direction = (direction + 1) % 4; //인터넷 참고 
				break;
			case 'R' :
				direction = (direction + 3) % 4; //인터넷 참고 
				break;
			default :
				break;
		}
		max_x = max(x, max_x);
		max_y = max(y, max_y);
		min_x = min(x, min_x);
		min_y = min(y, min_y);
	}
	int width = max_x - min_x;
	int height = max_y - min_y;
	cout << width * height << "\n";
}
void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

void input(){
	cin >> T;
}

int main(){
	init();
	input();
	while(T--){
		solve();
	}
	return 0;
}