//1,2,3 더하기

#include <iostream> 

using namespace std;

int dp[11];
int N;

int solve(void){
	dp[1] = 1; // 1 1가지 
	dp[2] = 2; // 1+1, 2 2가지 
	dp[3] = 4;  // 1+1+1 , 1+2, 2+1, 3, 4가지 
	
	for(int i = 4; i <= N; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	
	return dp[N];
}
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	
	for(int i = 0; i < T; i++){
		cin >> N;
		cout << solve() << "\n";
	}
	
	return 0;
} 