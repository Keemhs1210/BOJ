#include <iostream>
#include <queue>

using namespace std;

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int idx = 0; // 출력 값 
	int testcase; cin >> testcase;
	
	int N, M, ipt; //문서 갯수, 찾고자 하는 문서, 중요도  
	
	for(int i = 0; i < testcase; i++){
		idx = 0;
		cin >> N >> M;
		queue<pair<int, int>> q; 
		priority_queue<int> pq; // 우선순위 큐
		
		for(int j = 0; j < N; j++){
			cin >> ipt;
			q.push({j, ipt}); //인덱스와 중요도 push 
			pq.push(ipt); //중요도만 push 
		} 
		
		while(!q.empty()){
			int index = q.front().first; //idx만 값 설정 
			int value = q.front().second; //중요도만 값 설정 
			q.pop(); //q를 pop 한다. 
			if(pq.top() == value) { //우선수위 q의 중요도와 value 값이 같다면 우선순위 pop 
				pq.pop();
				idx++; //idx를 ++해줌 
				if(index == M){ //idx와 찾고자 하는 문서 위치가 같다면 idx 출력하여 몇번째 위치 인지 확인 
					cout << idx << "\n";
					break; // while문을 끝냄 
				}
			}
			else q.push({index, value}); //만약 우선순위와 벨루값이 같지 않다면 index와 value를 pop한 내용을 q에푸쉬한다.  
		}
	}
	return 0;
}