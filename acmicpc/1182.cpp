// 부분수열의 합 (https://www.acmicpc.net/problem/1182)
// 좀 더 이해 필요....
#include <iostream>

#define MAX 20
using namespace std;

int val[MAX]; 
int n, s;
int cnt, currentSum;

void dfs(int current){
    cout << current << ", " << currentSum << endl;
    if(current == n) return;
    if(currentSum + val[current] == s) cnt++;
    dfs(current+1);

    currentSum += val[current];
    dfs(current+1);

    currentSum-=val[current];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> val[i];
    
    dfs(0);

    cout << cnt;

    return 0;
}