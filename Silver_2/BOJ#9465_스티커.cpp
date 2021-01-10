#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int MAXN = 100000;
 
int buf[2][MAXN + 1] = { 0, };
int dp[2][MAXN + 1] = { 0, };
 
int max(int a, int b) { if (a > b) return a; return b; }
 
int bottomUp(int n) {
    for (int i = 0; i < n; i++) 
        cin >> buf[0][i];
 
    for (int i = 0; i < n; i++)
        cin >> buf[1][i];
 
    dp[0][0] = buf[0][0];
    dp[1][0] = buf[1][0];
    dp[0][1] = buf[0][1] + dp[1][0];
    dp[1][1] = buf[1][1] + dp[0][0]; //[0,0], [0,1]에서 무조건 시작하며 대각선 1을 가짐 
 
    for (int i = 2; i < n; i++) { //대각선 +1과 대각선 +2의 값을 비교해가며 dp를 진행 
        dp[0][i] = buf[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = buf[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }
 
    return max(dp[0][n - 1], dp[1][n - 1]);
}
 
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << bottomUp(n) << "\n";
    }
    return 0;
}
