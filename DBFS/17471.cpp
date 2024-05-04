#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, ans = 987654321;
int person[11];
int vis [11];
int con[11][11];
int sel[11];

void calc(){
    int an, bn;
    an = bn = 0;
    for(int i=1;i<=N;i++){  
        if(sel[i] == 1) an = an + person[i];
        else bn = bn + person[i];
    }
    int v1 = abs(an - bn);
    if(ans > v1) ans = v1;
}

int check_conn(vector<int> V, int T){
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(V[0]);
    vis[V[0]] = 1;
    int cnt = 1;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i=1;i<=N;i++){  
            if(con[x][i] == 1 && sel[i] == T && vis[i] == 0){
                vis[i] = 1;
                cnt++;
                Q.push(i);
            }
        }
    }
    if(V.size() == cnt ) return 1;
    return 0;
}

int check(){
    vector<int> A, B;
    for(int i =1;i<=N;i++){  
        if(sel[i] == 1) A.push_back(i);
        else B.push_back(i);
    }
    if(A.size() == 0 || B.size() == 0) return 0;
    if(check_conn(A,1) == 0) return 0;
    if(check_conn(B,0) == 0) return 0;
    return 1;
}

void DFS(int idx, int cnt){
    if(cnt >= 1){
        if(check() == 1)
            calc();
    }
    for(int i=idx;i<=N;i++){  
        if(sel[i] == 1) continue;
        sel[i] = 1;
        DFS(i, cnt+1);
        sel[i] = 0;
    }
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){  
        int x; cin >> x;
        person[i] = x;
    }
    for(int i=1;i<=N;i++){ 
        int v1; cin >> v1;
        for(int j =0;j<v1;j++){
            int v2; cin >> v2;
            con[i][v2] = 1;
            con[v2][i] = 1;
        }
    }

    DFS(1,0);
    if(ans == 987654321)
        cout << -1;
    else
        cout << ans << endl;
}
