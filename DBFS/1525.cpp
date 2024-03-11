// 1525
#include <iostream>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[20][20];
int vis[26];
int N, M, ret;

int check(int v1, int v2){ if(v1 > v2) return v1; return v2;}

void dfs(int x, int y, int cnt){
    ret = check(ret, cnt);
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < M && ny < N){
            if(vis[map[ny][nx]] == 0){
                vis[map[ny][nx]] = 1;
                dfs(nx, ny, cnt+1);
                vis[map[ny][nx]] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string t; cin >> t;
        for(int j=0;j<M;j++){
            map[i][j] = int(t[j]) - 0x40;
        }
    }
    vis[map[0][0]] = 1;
    dfs(0,0,1);
    cout << ret;
}
