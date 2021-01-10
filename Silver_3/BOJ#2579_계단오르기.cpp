//계단 오르기
#include <iostream>
using namespace std;
#define max 301

int N; 
int Stairs[max];
int Score[max];

int MAX(int A, int B) { if ( A > B) return A; return B; }

void dp(){
	Score[1] = Stairs[1];
	Score[2] = Stairs[1] + Stairs[2];
	Score[3] = MAX(Stairs[1] + Stairs[3], Stairs[2] + Stairs[3]);
	
	for(int i = 4; i <= N; i++)		
		Score[i] = MAX(Score[i-2] + Stairs[i], Score[i - 3] + Stairs[i - 1] + Stairs[i]);
	
	cout << Score[N];
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> Stairs[i];
	
	dp();

	return 0; 
} 