#include <iostream>
#include <stack>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int T; cin >> T;
	
	stack<char> st;
	
	for(int i = 0; i < T; i++){
		string s;
		cin >> s;
		
		for(int j = 0; j < s.length(); j++){
			if(s[j] == '(' || st.empty()) st.push(s[j]); // 닫는 괄호면 push 
			else if(st.top() == '(') st.pop(); //여는 괄호이고 닫는 괄호면 pop 
		}
		if(st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		while(!st.empty()) st.pop(); //stack 초기화 
	}

	return 0;
}