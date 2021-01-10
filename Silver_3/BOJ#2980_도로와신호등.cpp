#include<iostream>
#include<vector>

using namespace std;

typedef struct { //구조체 선언 
	int D;
	int R;
	int G;
	int Cycle;
}Signal_Lamp;

int N, L;
vector<Signal_Lamp> V;

void Input(){ //입력 함수 
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		Signal_Lamp S;
		int D, R, G;
		cin >> D >> R >> G;
		S.D = D;
		S.R = R;
		S.G = G;
		S.Cycle = S.R + S.G;
		V.push_back(S);
	}
}

bool Traffic_State(int idx, int T){ //현재 도달한 신호등이 빨간불이면 fasle 파란불이면 true 
	if( T % V[idx].Cycle <= V[idx].R) return false;
	//3m에서 빨간 불 지속 시간 5초 일경우 { 3 % 10 -> 3 < 5  res: 빨간 불  
	//5m에서 빨간 불 지속 시간 2초 일경우  {7(5초 + 2초(3m 지점에서 빨간불 대기시간) % 10 (5 + 5) } -> 3 > 2  res: 파란 불  
	return true;
}

void Solution(){

	int Distance = 0;
	int Time = 0;
	int idx = 0;
	
	while(1){
		if(Distance == L) break; //Distance 변수와 입력 받은 거리 값이 같아지면 break 실행 
		if(idx < V.size()) //V.size가 idx 보다 작을 시 
		{
			if(V[idx].D == Distance){ //신호등 위치에 도달할 때 
				if(Traffic_State(idx, Time) == true){ //신호등 상태가 초록불일 경우 
					Distance++;
					Time++;
				}
				else{
					int temp = Time % V[idx].Cycle;
					Time = Time + V[idx].R - temp; 
					//신호등이 빨간 불일 경우 ex. 3m 빨간불 5초이면 0 + 5 - (3 % 5 = 3) 
				}
				idx++; //다음 신호등 탐색 
				continue; 
			}
		}
		Distance++; //시간과 거리 계속 증가 
		Time++;
	}
	cout << Time << "\n";
}

void solve(){
	Input();
	Solution();
}

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(void){

	init();
	solve();
	return 0;
}