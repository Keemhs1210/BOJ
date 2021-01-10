#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	set<string> answer;
	
	while(t--){
		string name, commute;
		cin >> name >> commute;
		if(commute == "enter") answer.insert(name);
		else answer.erase(name);
	}
	
	for(auto it = answer.rbegin(); it != answer.rend(); it++) 
		cout << *it << '\n';	
	
	return 0;
}