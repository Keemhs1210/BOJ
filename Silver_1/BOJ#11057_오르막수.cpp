#include <iostream> 
#define MAX 1001
#define MOD 10007
#define num_max 10
using namespace std;

int N;
int DP[MAX][num_max] = {0, };

void dp(){  
	for(int i = 0; i < num_max; i++) DP[0][i] = 1; //한자리수  
	
	for(int i = 1; i < N; i++){ 
		for(int j = 0; j < 10; j++){ 
			for(int k = j; k < 10; k++){ 
				DP[i][k] += DP[i-1][j]; 
				DP[i][k] %= MOD;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < 10; i++) sum += DP[N-1][i];
	cout << sum % MOD;
}
void init(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int main(){
	init();
	cin >> N;
	dp();
	
	return 0;
} 
