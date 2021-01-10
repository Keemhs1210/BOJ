#include <iostream>
#include <string.h>
#define num 5
#define max 15
using namespace std;

int main(void){
	
	string sentence[num];
		
	for(int i = 0; i < num ; i++ ) cin >> sentence[i];
	for(int i = 0; i < max; i++){
		for(int j = 0; j < num; j++)
			if(i < sentence[j].length()) 
				cout << sentence[j][i]; //이차원 배열 생성이 가능한 이유? 
	}
	
	cout << "\n";
	
	return 0;
}