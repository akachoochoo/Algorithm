// DFS와 BFS (https://www.acmicpc.net/problem/1260)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool check[]){
    check[start] = true;
    cout << start << " ";

    for(int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];

        if(check[next] == false)
            dfs(next, graph, check);
    }
}

void dfs_stack(int start, vector<int> graph[], bool check[]){
    stack<int> s;
    s.push(start);
    check[start] = true;
    cout << start << " ";

    while(!s.empty()){
        int current = s.top();
        s.pop();
        for(int i=0; i<graph[current].size(); i++){
            int next = graph[current][i];

            if(check[next] == false)
                cout << next << " ";
                check[next] = true;

                s.push(current);
                s.push(next);
                break;
        }
    }
}

void bfs(int start, vector<int> graph[], bool check[]){
    queue<int> q;

    q.push(start);
    check[start] = true;
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";

        for(int i=0; i<graph[tmp].size(); i++)
        {
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                check[graph[tmp][i]]=true;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;

    vector<int> graph[n+1];
    bool check[n+1];
    fill(check, check+n+1, false);
    
    for(int i =0; i<m; i++){
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start,graph,check);
    cout << endl;
    fill(check, check+n+1, false);
    bfs(start,graph,check);
    cout << endl;

    return 0;
}