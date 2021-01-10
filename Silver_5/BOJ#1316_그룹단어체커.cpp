#include <iostream>
#include <string.h>

using namespace std;

bool wordCheck(string word){
	bool alpabet[26] = {false};
	
	for(int i = 0; i <word.length(); i++){
		
		if(alpabet[word[i] - 'a']){
			return false;
		}else{
			
			char temp = word[i];
			alpabet[word[i] - 'a'] = true;
			
			while(1){
				if(temp != word[++i]){
					i--;
					break;

				}
			}	
		}			
	}

	return true;
}

int main(void){
	int group;
	int count = 0;
	
	cin >> group; 
	
	for(int i = 0; i < group; i++){
		string word;
		cin >> word;
		
		if(wordCheck(word)){
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}