// 단지번호붙이기 BFS/DFS 이용 완전탐색 (https://www.acmicpc.net/problem/2667)
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>

#define MAX_SIZE 25

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int groups[MAX_SIZE*MAX_SIZE];
int group_id;
int n;

// 위, 오른쪽, 아래, 왼쪽
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs_recursion(int x, int y)
{
    visited[x][y] = true;
    groups[group_id]++;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx <n && 0 <= ny && ny <n){
            if(map[nx][ny]==1 && visited[nx][ny]==false){
                dfs_recursion(nx,ny);
            }
        }
    }
}

void dfs_stack(int x, int y)
{
    stack<pair<int,int>> s;
    s.push(make_pair(x,y));
    
    visited[x][y] = true;
    groups[group_id]++;

    while(!s.empty()){
        x = s.top().first;
        y = s.top().second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <n && 0 <= ny && ny <n){
                if(map[nx][ny]==1 && visited[nx][ny]==false){
                    visited[nx][ny] = true;
                    groups[group_id]++;    
                    
                    s.push(make_pair(x,y));
                    s.push(make_pair(nx,ny));
                }
            }
        }
    }

}


void bfs_queue(int x, int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    visited[x][y] = true;
    groups[group_id]++;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx <n && 0 <= ny && ny <n){
                if(map[nx][ny]==1 && visited[nx][ny]==false){
                    visited[nx][ny] = true;
                    groups[group_id]++;    
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]==1 && visited[i][j]==false){
                group_id++;

                //dfs_recursion(i,j);
                //dfs_stack(i,j);
                bfs_queue(i,j);
            }
        }
    }
    cout << group_id << endl;

    // sort(groups+1, groups+group_id+1);
    // for(int i=1; i<=group_id; i++){
    //     cout << groups[i] << endl;
    // }

    return 0;
}