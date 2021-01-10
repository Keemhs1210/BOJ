#include <iostream>
#define Right 0 //오른쪽 이동 
#define Left 1  //왼쪽 이동 

using namespace std;

struct ant{
	int dir;
	char id;
} ;
//개미는 알파벳 수만큼 존재
struct ant temp, ants[27];

void swap(int A, int B){ //dir이 다른 개미 그룹이 모이면 스왑을 해주는 함수 
	temp = ants[A];
	ants[A] = ants[B];
	ants[B] = temp;
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int first_Grp, Second_Grp, T;
	char name;
	
	cin >> first_Grp >> Second_Grp;
	
	for(int i = 0; i < first_Grp; i++){
		cin >> name;
		ants[first_Grp - (i+1)] = {Right, name};  //A, B, C로 입력받아 C, B, A로 정렬 
	}
	for(int i = first_Grp; i < first_Grp + Second_Grp ;i++){
		cin >> name;
		ants[i] = {Left, name};
	} 
	
	cin >> T;
	while(T--){
		for(int i = 0; i < first_Grp + Second_Grp - 1; i++){ 
			if(ants[i].dir == Right && ants[i].dir != ants[i + 1].dir){
				// 오른쪽 진행방향의 개미를 기준으로
				//진행 방향이 다른 개미를 만난다면 서로 자리를 바꾸어 준다.
				swap(i, i+1);
				i++; //스왑이 두번 일어나지 않도록 i++를 해준다. 
			} 
		}
	}
	for(int i = 0; i < first_Grp + Second_Grp; i++) cout << ants[i].id; 
} 