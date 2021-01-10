//Virus

#include <iostream>
#include <queue>

using namespace std;

bool map[101][101];
bool visit [101];
int Computer, cnt = 0;

void num_of_virus_computer_BFS(int start){
	visit[start] = 1;
	queue <int> q;
	q.push(start);
	while(!q.empty()){
		int node = q.front();
		q.pop();	
		
		for(int i = 1; i <= Computer; i++){
			if(!visit[i] && map[node][i] == 1){ 
				q.push(i);
				visit[i] = 1;
				cnt++;
			}
		}
	}
} 
int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int virus_computer;
	int x, y;
	
	cin >> Computer;
	cin >> virus_computer;
	
	for(int i = 0; i < virus_computer; i++){
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}
	
	 num_of_virus_computer_BFS(1);
	 cout << cnt;
	
	return 0;
} 