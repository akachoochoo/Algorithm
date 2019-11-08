// 평범한배낭 (https://www.acmicpc.net/problem/12865)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector <pair<int,int>> items;
int N,K;

bool compare(pair<int,int>a, pair<int,int>b){
    return a.second > b.second;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    int W, V;
    for(int i=0; i<N; i++){
        cin >> W >> V;
        items.push_back(make_pair(W, V));
    }

    sort(items.begin(), items.end(), compare);

    int max = -1;
    int remain;

    for(int i=0; i<N; i++){
        int total = 0;
        remain = K;
        for(int j=i; j<N; j++){
            if(remain >= items[j].first){
                total += items[j].second;
                remain -= items[j].first;
            }
        }
        
        if(total > max) max = total;
    }

    cout << max;

    return 0;
}