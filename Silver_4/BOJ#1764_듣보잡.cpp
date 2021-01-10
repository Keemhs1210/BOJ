#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	string s;
	
	vector <string> v;
	vector <string> result;
	
	cin >> n >> m;
	
	v.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < m; i++){
		
		cin >> s;
		
		if(binary_search(v.begin(),v.end(),s)){
			result.push_back(s);
		}
	}	
	
	sort(result.begin(), result.end());
	
	cout << result.size() << "\n";
	
	for(int i = 0; i < result.size() ; i++)
		cout << result[i] << "\n";
		
	return 0;	 
}