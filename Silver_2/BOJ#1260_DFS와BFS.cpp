#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

int map[MAX][MAX];
int visited[MAX];
int Node, Line, v;
queue <int> q;

void dfs(int v){
	
	cout << v << " ";
	visited[v] = 1;
	for(int i = 1; i <= Node; i++){
		if(map[v][i] == 1 && !visited[i]){
			dfs(i);
		}
	}
}

void bfs(int v){
	
	visited[v] = 1;
	q.push(v);	
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		cout << v << " ";
		for(int i = 1; i <= Node; i++){
			if(map[v][i] && !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
} 

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
   
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));	
    
	cin >> Node >> Line >> v;
    
	for(int i = 0; i < Line; i++){
		int a, b;
		cin >> a >> b; 
		map[a][b] = 1;
		map[b][a] = 1;
	}	
	dfs(v);
	cout << "\n";
	
	memset(visited, 0, sizeof(visited));	
	bfs(v);
	cout << "\n";	
	return 0;
}