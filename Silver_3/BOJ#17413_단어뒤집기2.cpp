#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
string s;
stack <char> st;

void Swap(){
	bool checkFlag = false;
	for(int i = 0; i < s.size(); i++){
	
		if(s[i] == '<') {
			while(!st.empty()){
				cout << st.top();
				st.pop();
			}
			cout << "<";
			checkFlag = true;
		}
		
		else if(s[i] == '>'){
			cout << ">";
			checkFlag = false;
			
		}
		else if(checkFlag == 1) cout << s[i];
			
		else if (s[i] == '\n' || s[i] == ' '){
			while(!st.empty()){
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		else st.push(s[i]);		
	}		
}

void input(){
	getline(cin, s);
	s += '\n';
}
void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}
int main(){
	init();
	input();
	Swap();
	return 0;
	
} 