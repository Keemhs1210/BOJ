#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	int N; 
	cin >> N;
	
	vector<int> A;
	vector<int> B;
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}
	
	for(int i = 0; i < N; i++){
		int b;
		cin >> b;
		B.push_back(b);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		sum += A[i]*B[i];
	}
	cout << sum;

	return 0;

}
