// 경로찾기 (https://www.acmicpc.net/problem/11403)
#include <iostream>
#include <vector>
#include <stack>

#define MAX_VERTEX 100

using namespace std;

int n, idx;
int a[MAX_VERTEX+1][MAX_VERTEX+1];

void dfs(vector<int> graph[], bool c[], int v)
{
    for(int i=0; i<graph[v].size(); i++){
        int next = graph[v][i];

        if(c[next] == false){
            c[next] = true;
            a[idx][next] = 1;
            dfs(graph, c, next);
        }
    }

}

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    bool c[n];
    vector<int> graph[n+1];

    for(int i=1; i<=n; i++){
        c[i] = false;
        for(int j=1; j<=n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                graph[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        idx = i;
        dfs(graph,c,i);
        for(int j=1; j<=n; j++){
            c[j] = false;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}