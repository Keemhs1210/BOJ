#include <iostream>
using namespace std;

int n = 0, k = 0;
int dp[31][31] = { 0 };

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1, dp[i][i] = 1;
		for (int j = 2; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][k] << '\n';
}