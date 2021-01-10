#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N; //풍선 개수 

deque <pair<int, int> > d; //deque 선언 

void ballon(){
	int val = d.front().second; //첫번째 풍선이 가진 번호 변수로 지정 
	cout << d.front().first << " ";
	d.pop_front(); //풍선 터트렸으므로 pop  
	while(!d.empty()){
	
		if(val > 0){ //풍선이 가진 번호가 양수일 경우  
			for(int i = 0; i < val; i++){ //오른쪽으로 이동 push 
				d.push_back (make_pair(d.front().first, d.front().second)); 
				d.pop_front(); // 뒤에 추가하였으니 앞에 중복 값 제거 
			}
			val = d.back().second; //맨 뒤에 있는 값을 출력  
			cout << d.back().first << " ";
			d.pop_back();
		}
		else{ // 음수 일 경우 왼쪽으로 이동 
			for(int i = 0; i < abs(val); i++){
				d.push_front (make_pair(d.back().first, d.back().second));
				d.pop_back(); //앞에 추가하였으니 뒤의  중복 값 제거  
			}
			val = d.front().second;
			cout << d.front().first << " ";
			d.pop_front();
		}
	}
}

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){	
		int a;
		cin >> a; 
		d.push_back(make_pair(i+1, a));	
	}
}

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(){
	init();
	input();
	ballon();
	return 0;

}