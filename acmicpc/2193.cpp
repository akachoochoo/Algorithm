// 이친수 (https://www.acmicpc.net/problem/2193)
#include <iostream>
using namespace std;

long long int dp[91];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<=N; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    
    cout << dp[N] << endl;

    return 0;
}