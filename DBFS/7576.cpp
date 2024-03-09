// 7576
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N, M;
int map[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int,int> > Q;

// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> M >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){ Q.push(make_pair(i,j));}
        }
    }
    while(!Q.empty()){
        int n = Q.front().first;
        int m = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int n1 = n + dy[i];
            int m1 = m + dx[i];
            if(n1 >= 0 && m1 >= 0 && n1 < N && m1 < M){
                if(map[n1][m1] == 0){
                    map[n1][m1] = map[n][m] + 1;
                    Q.push(make_pair(n1,m1));
                }
            }
        }
    }
    int ret = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == 0){ cout << "-1"; return 0; }
            if(map[i][j] > ret){ ret = map[i][j]; }
        }
    }
    cout << ret-1;
    return 0;
}
