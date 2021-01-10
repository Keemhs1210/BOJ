#include <iostream>

using namespace std;

int main(void){

	int TestCase, Student_Num;

	cin >> TestCase;	
	
	for(int i = 0; i < TestCase; i++){
		cin >> Student_Num;
		
		double average = .0;
		int score[1001];
		int sum = 0;
		
		for(int j = 0; j < Student_Num; j++){
			cin >> score[j];
			sum += score[j];
		}
		
		average = (double)sum/Student_Num;
		int count;
		double result;
		count = 0;
		
		for(int k = 0; k < Student_Num; k++){
			if(average < score[k]) count ++;
		}
		
		result = (double)count*100/ Student_Num;
		
		cout << fixed;
		cout.precision(3);
		cout << result << "%" << endl;
	}

	int count = 0;
	return 0;
}