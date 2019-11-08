// 알파벳 (https://www.acmicpc.net/problem/1987)
#include <iostream>

using namespace std;

int R, C;
int cnt;
char board[20][20];
bool checked[26];
bool visited[20][20];

//up, down, right, left
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void backtrack(int x, int y, int dist){
    cnt = max(cnt, dist);
    visited[x][y] = true;
    checked[board[x][y]-'A'] = true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if( 0<=nx && nx<R && 0<=ny && ny<C)
            if(visited[nx][ny]==false && checked[board[x][y]-'A']==false)
                backtrack(nx,ny, dist+1);
    }

    visited[x][y] = false;
    checked[board[x][y]-'A'] = false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%1c",&board[i][j]);
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    backtrack(0,0,1);

    cout << cnt;

    return 0;
}