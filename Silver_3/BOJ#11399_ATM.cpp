#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	int awaiter[N];
	
	for (int i = 0; i < N; i++) cin >> awaiter[i];

	
	sort(awaiter, awaiter+N);
	
	int sum = 0;
	for(int i = 0; i < N; i++) sum += awaiter[i] * (N-i);
	
	cout << sum;
	return 0;
}