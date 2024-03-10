// 2146
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[101][101];
int vis[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;

int Min(int A, int B) { if (A < B) return A; return B; }

int bfs(int idx){
    int ret = 0;
    queue<pair<int,int> > Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == idx){
                Q.push(make_pair(i,j));
                vis[i][j] = 1;
            }
        }
    }

    while(!Q.empty()){
        for(int j=0;j<Q.size();j++){
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                    if(map[ny][nx] != 0 && map[ny][nx] != idx){
                        return vis[y][x]-1;
                    }
                    else if(map[ny][nx] == 0 && vis[ny][nx] == 0){
                        Q.push(make_pair(ny,nx));
                        vis[ny][nx] = vis[y][x]+1;
                    }
                }
            }
        }
        ret++;
    }
}

int main(){
    ios::sync_with_stdio(0);
   cin.tie(0);
    int ret = 987654321;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    queue<pair<int,int> > Q;
    int land_num = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vis[i][j] == 0 && map[i][j] == 1){
                map[i][j] = land_num;
                Q.push(make_pair(i,j));
                while (!Q.empty()) {
                    int y = Q.front().first;
                    int x = Q.front().second;
                    Q.pop();
                    for(int k=0;k<4;k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                            if(vis[ny][nx] == 0 && map[ny][nx] == 1){
                                Q.push(make_pair(ny,nx));
                                vis[ny][nx] = 1;
                                map[ny][nx] = land_num;
                            }
                        }
                    }
                }
                land_num++;
            }
        }
    }

    for(int i=1;i<land_num;i++){
        memset(vis, 0, sizeof(vis));
        ret = Min(ret, bfs(i));
    }

    cout << ret;
}
