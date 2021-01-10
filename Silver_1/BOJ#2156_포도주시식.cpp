#include <iostream>
#define MAX_SIZE 10001

using namespace std;



int max_3 (int x, int y, int z) { //정수 3개 최대 값 찾기 
	if( x >= y && x >= z) return x;
	else if ( y >= x && y >= z) return y;
	else if ( z >= x && z >= y) return z;
}

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; 	cin >> n;
	int glass[MAX_SIZE] = {0, };
	int dp[MAX_SIZE] = {0, };

	for(int i = 1; i <= n; i++) cin >> glass[i];
	
	dp[1] = glass[1]; //1잔 만 있을 경우 
	if(n > 1) dp[2] = glass[1] + glass[2]; //2잔만 있을 경우 
	if(n > 2){ //3잔 있을 경우 
		for(int i = 3; i <= n; i++){
			dp[i] = max_3(dp[i-1], dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]); 
			//1) i = 3
			//첫째잔 + 둘째잔, 첫째잔 + 셋째잔, 둘째잔 + 셋째잔 순으로 큰 값 찾아 DP 진행  
			//2) i = 4
			//dp[3] 값, 첫째잔 + 둘째잔 + 넷째잔, 첫째잔 + 셋째잔 + 넷째잔 순으로 진행  
		}
	}		
	
	cout << dp[n]; //최대 값 출력 


	return 0;
}