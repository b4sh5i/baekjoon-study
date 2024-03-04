#include<iostream>
#include <queue>
#include <string>

using namespace std;

int N=0;
int M=0;
int map[101][101];
int visited[101][101];
int ret[101][101];

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1}; 

queue<pair<int,int> > q;

void bfs(int s_x, int s_y){
    visited[s_x][s_y] = 1;
    q.push({s_x,s_y});
    ret[s_x][s_y]++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];

            if((0<=nx && nx < N) && (0 <= ny && ny < M) && !visited[nx][ny] && map[nx][ny] == 1 ){
                visited[nx][ny] = 1;
                q.push({nx,ny});
                ret[nx][ny] = ret[x][y] + 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for (int i=0; i<N; ++i){
        string row;
        cin >> row;
        for (int j=0; j<M; ++j){
            map[i][j] = row[j]-'0';
        }
    }
    bfs(0,0);
    cout << ret[N-1][M-1];
}
