#include <iostream>
#define max 9
#define endl "\n"

using namespace std;

int N, M;
int map[max] = {0,};
bool visited[max] = {0,};

void dfs(int cnt){
	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << map[i] << ' ';
		cout << endl;
		return;
	}
	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			visited[i] = true;
			map[cnt] = i;
			dfs(cnt+1);
			visited[i] = false;
		}
	}
}

void input(){
	cin >> N >> M;
}

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(){
	init();
	input();
	dfs(0);
	return 0;
}