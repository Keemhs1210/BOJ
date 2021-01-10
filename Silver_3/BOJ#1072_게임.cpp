#include <iostream>
#define MAX 1000000000

using namespace std;

int main(){
	long long x, y, z, low, high, mid, temp_z;
	cin >> x >> y;
	z = (y * 100) / x;
	if( z >= 99){
		cout << -1;
		return 0;
	}
	low = 0;
	high = MAX;
	
	while(low <= high){ //high가 low보다 작을 때까지 루프 
		mid = (low + high) / 2; //중간 값을 찾는 이진 탐색  
		temp_z = 100 * (y + mid) / (x + mid); //temp_z는 이진 탐색하여 승률 바뀌는 값을 찾는다. 
		if( z < temp_z){ // 현재 승률이 이진 탐색 중간 값인 z보다 작다면 high 값을 -1하여 범위를 줄인다  
			high = mid - 1;
		}
		else{ //temp_z <= Z 인 지점부터 결과가 갱신되어 +1이다. 
			low = mid + 1;		
		}
	}

	cout << low;

}

