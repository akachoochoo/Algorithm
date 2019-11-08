// Not solved!!!
// 계단 오르기 (https://www.acmicpc.net/problem/2579)
#include <iostream>
#include <algorithm>
using namespace std;

int step[300];
int dp[300][2];
int N;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    step[0] = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> step[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<2; j++){
            dp[i][j] = -1;
        }
    }

    dp[N-1][0] = 1;
    dp[N-1][1] = step[N-1];
    for(int i=N-2; i>=0; i--){
        if(dp[i+1][0]<2){
            dp[i][0]=dp[i+1][0]+1;
            dp[i][1]=dp[i+1][1]+step[i];
        }
        else{
            if(dp[i+1][1] >= dp[i+2][1]+step[i])
            {
                dp[i][1]=dp[i+1][1];
                dp[i][0]=0;
            }
            else
            {
                dp[i][1]=dp[i+2][1]+step[i];
                dp[i][0]=1;
            }
        }
    }

    // cout << endl;
    // for(int i=N-1; i>=0; i--)
    //     cout << dp[i][1] << ", " << dp[i][0] << endl;
    cout << dp[0][1];

    return 0;
}