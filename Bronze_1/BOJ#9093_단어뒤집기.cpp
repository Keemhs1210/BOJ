#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	cin.ignore(); //남은 버퍼 삭제 역할
	
	while(T--){
		
		string s = "";
		getline(cin,s);
		s += '\n';
		
		stack<char> st;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ' ' || s[i] == '\n'){
				while(!st.empty()){
					cout << st.top();
					st.pop();	
				}
				cout << " ";
			}
			else st.push(s[i]);
		}
		cout << '\n';
	} 
	return 0;
}