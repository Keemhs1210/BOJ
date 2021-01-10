#include <iostream>

using namespace std;

int main(void){
	
	long long N;
	cin >> N;
	long long result[N];
	long long sum,count;
	sum = count = 0;
	
	
	for( long long i = 0; i < N-1; i++){
		count++;
		result[N] = (N+1)*count;
		sum += result[N]; 
	}
	
	cout << sum << endl;
	
	return 0;
}