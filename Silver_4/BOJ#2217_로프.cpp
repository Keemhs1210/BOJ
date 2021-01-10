#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	int rope[N];
	for(int i = 0; i < N; i++) cin >> rope[i];
	
	sort(rope,rope+N, greater<int>()); //로프 오름차순 정렬 
	
	long long result = 0;
	for(int i = 0; i < N; i++){
		long long sum = rope[i] * (i + 1);
		if( sum > result) result = sum;
		//110*1 / 70*2 / 40*3 / 35*4 / 20*5 / 5*6 이런 순서대로 계산을 해준 것들 중에서 가장 큰 값을 정답
	}
	cout << result;
	return 0;
}