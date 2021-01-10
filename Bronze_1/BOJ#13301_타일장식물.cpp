#include <iostream>
#define MAX 81

using namespace std;

long long dp[MAX] = {0 ,};

long long res(int n){
	
	dp[1] = 4;
	dp[2] = 6;
	
	for(int i = 3; i <= n; i++){ 
		dp[i] = dp[i-1] + dp[i-2];
		//3번째 일 경우는 둘레가 10이다 10은 dp[1](4) + dp[2](6)의 값을 가진다.
		//4번째 일 경우는 둘레가 16이다 16은 dp[2](6) + dp[3](10)의 값을 가진다.		 
	}	
	return dp[n];
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	
	res(N);
	cout << res(N);
	return 0;
} 