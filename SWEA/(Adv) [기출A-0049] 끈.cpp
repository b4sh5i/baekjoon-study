/*
3 22  
3 1
3 9
5 2
8 15 17  -> 17
2 9 17  -> 17
8 10 17  -> 17
7 9 17  -> 17
2 10 17  -> 17
7 15 17  -> 17
5
*/

#include<iostream>
#include<vector>
#include<deque>
#include<cmath>

using namespace std;

int N, L;
int vis[20];
deque<pair<int, int>> dq;
int result = 987654321;

void calc(deque<pair<int, int>> p){
    int ret = 0;
    for(int i=0;i<N;i++){
        if (i == N-1){
            ret += sqrt(pow(p[i].first - p[0].first, 2) + pow(p[i].second - p[0].second, 2));
            cout << ret << " ";
        }
        else {
            ret += sqrt(pow(p[i].first - p[i+1].first, 2) + pow(p[i].second - p[i+1].second, 2));
            cout << ret << " ";
        }
    }
    cout << " -> " << ret << endl;
    if(ret < result) result = ret;
    // cout << endl;
}

void dfs(vector<pair<int,int>> input, deque<pair<int, int>> dp, int * vis){
    if (dq.size() == N) {
        calc(dq);
        return;
    }
    for(int i=0;i<N; i++){
        if(!vis[i]){
            vis[i] = 1;
            dq.push_back(input[i]);
            dfs(input, dq, vis);
            dq.pop_back();
            vis[i] = 0;
        }
    }
}

int main(){
    cin >> N >> L;
    vector<pair<int,int>> input(20);
    for(int i=0;i<N;i++){
        cin >> input[i].first >> input[i].second;
    }
    dfs(input, dq, vis);
    cout << L - result;
}