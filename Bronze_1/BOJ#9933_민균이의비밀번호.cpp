 #include<iostream>
 #include<string>
 #include<algorithm>
 #include <map>
  
 using namespace std;
 
 map<string, bool> visited;
 
 int main(void){
 	
 	int N;
 	cin >> N;
 	
 	
 	for(int i = 0; i < N; i++){
	 	
	 	string PW;
	 	cin >> PW;
	 	
	 	string RE_PW = PW;
	 	reverse(RE_PW.begin(), RE_PW.end());
	 	
	 	if(PW == RE_PW || visited.count(RE_PW)){
			 cout << PW.length() << " " << PW[PW.length()/ 2];
			 break;
		 }
		 else
		 	visited[PW] = true;

	 }
 	
 
 	return 0;
 }
 