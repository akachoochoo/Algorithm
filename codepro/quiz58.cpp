#include <iostream>
using namespace std;

int N;//후보자 수
int A[100000 + 10];//기질 값

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int abs(int i){
	if(i>0) return i;
	else return -1*i;
}

int main(){
	InputData();//	입력 함수

	//	코드를 작성하세요
	int i=0, j=N-1;
	int ans1, ans2;
	int min = 2147483647;

	while(i < j)
	{
		int temp = A[i]+A[j];
		
		if(abs(temp) < min){
			ans1 = i; 
			ans2 = j; 
			min = abs(temp);
		} 

		if( temp < 0)
			i++;
		else j--;
	}

	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}
