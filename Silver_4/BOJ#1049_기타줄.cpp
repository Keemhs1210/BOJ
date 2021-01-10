#include<iostream>
#include <algorithm>

using namespace std;

int main(void){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M; cin >> N >> M;
	int pack, piece,  pack_num = N/6 , piece_num = N%6
	, pack_min = 1001, piece_min = 1001;
	
	for(int i = 0; i < M; i++) {
		cin >> pack >> piece;	
		if(pack_min > pack)  pack_min = pack; //패키지 가격 최솟값 찾기 
		if(piece_min > piece) piece_min = piece; // 낱개 가격 최솟값 찾기	
	}
	
	int res[3] = {0,};
	
	res[0] = pack_num * pack_min + piece_num * piece_min;
	res[1] = (pack_num+1)*pack_min; // 패키지 구매로만 저렴할 경우 
	res[2] = N * piece_min;  // 낱개 구매로만 저렴할 경우 
	
	sort(res, res+3);
	
	cout << res[0];
	
	return 0;
} 