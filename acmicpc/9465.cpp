#include <iostream>
#include <algorithm>
using namespace std;

#define MAX (100000)

int N;
int score[2][MAX];
int dp[MAX][3];

int sticker(int i, int status){
    if(i == N) return 0;
    if(dp[i][status] != -1) return dp[i][status];

    int result = sticker(i+1,0);
    if(status != 1) result = max(result, sticker(i+1, 1) + score[0][i]);
    if(status != 2) result = max(result, sticker(i+1, 2) + score[1][i]);

    dp[i][status] = result;
    return result;
}   

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, s; 
    cin >> T;

    while(T--){
        cin >> N;
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                cin >> s;
                score[i][j]=s;
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<3; j++){
                dp[i][j]=-1;
            }
        }

        cout << sticker(0,0) << endl;
    }

    return 0;
}