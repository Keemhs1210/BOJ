#include <iostream>
#include <cstdio>
#define MAX 2188
using namespace std;

int N;
int map[MAX][MAX];
int result[3]; //0, 1, -1 일 경우 

bool cmp(int x, int y, int n){ //종이값 비교 함수 
	for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++){
			if(map[x][y] != map[i][j]) 
				return false ;
		}
	}
	return true;
}
void solve(int x, int y, int n){
	if(cmp(x,y,n)){ //같은 숫자로 이루어진 종이면 
		result[map[x][y] + 1] += 1;
		return ; 
	}
	
	int m = n / 3;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <3; j++){
			solve(x+i*m,y+j*m,m);
		}
	}
}



void input(){
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
}

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}
int main(){
	init();
	input();
	solve(0, 0, N);
    for(int i = 0; i < 3; i++) cout << result[i] << "\n";
	return 0;
} 