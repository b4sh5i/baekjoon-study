#include<iostream>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int N;
vector<int> edge[3001];
int vis[3001];
int cyc;
int check_cyc[3001];

void dfs(int cur, int start, int line){
    if(cur == start && line >= 2){
        cyc = 1;
        return;
    }
    vis[cur] = 1;
    for(int i=0;i<edge[cur].size();i++){
        int next = edge[cur][i];
        if(vis[next] == 0){
            dfs(next, start, line+1);
        }
        else{
            if(next == start && line >=2){
                dfs(next, start, line);
            }
        }

        if(cyc == 1) return;
    }
}

int bfs(int start){
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> Q;
    Q.push({start,0});
    vis[start]=1;

    while(!Q.empty()){
        int cur = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if(check_cyc[cur] == 1) return cnt;
        for(int i=0;i<edge[cur].size(); i++){
            int next = edge[cur][i];
            if(vis[next] == 0){
                vis[next] = 1;
                Q.push({next, cnt+1});
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    for(int i=1;i<=N;i++){
        memset(vis, 0, sizeof(vis));
        cyc = 0;
        int start = i;
        dfs(i, start, 0);
        if(cyc == 1){
            check_cyc[i] = 1;
        }
    }

    vector<int> ret;
    for(int i=1;i<=N;i++){
        if(check_cyc[i] ==  1){
            ret.push_back(0);
            continue;
        }
        ret.push_back(bfs(i));
    } 

    for(int i=0;i<ret.size();i++){
        cout << ret[i] << " ";
    }

}
