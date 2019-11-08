// 유기농 배추 (https://www.acmicpc.net/problem/1012)
#include <iostream>
#include <vector>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

using namespace std;

int count;
bool check[MAX_HEIGHT][MAX_WIDTH];
int map[MAX_HEIGHT][MAX_WIDTH];
int m,n;

// up, right, down, left
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x,int y){
    check[x][y] = true;

    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >= 0 && nx <m && ny >= 0 && ny<n)
            if(map[nx][ny]==1 && check[nx][ny]==false)
                dfs(nx,ny);
    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,k;
    cin >> t;
    vector<pair<int, int>>graph;
    while(t--){
        //Init
        count = 0;
        cin >> m >> n >> k;
        for(int i=0; i<k; i++){
            int u, v;
            cin >> u >> v;
            map[u][v] = 1;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(map[i][j]==1 and check[i][j]==false){
                    count++;
                    dfs(i,j);
                }
            }
        }

        cout << count << endl;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                check[i][j] = false;
                map[i][j] = 0;
            }
        }
    }
    return 0;
}