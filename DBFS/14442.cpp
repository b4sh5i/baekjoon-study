#include<iostream>
#include<queue>

using namespace std;

int N, M, K;
int map[1001][1001];
int vis[1001][1001][11];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct block{ 
    int n, m;
    int kick;
};


int main(){
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        string t;
        cin >> t;
        for(int j=0;j<M;j++){
            map[i][j] = int(t[j]-48);
        }
    }
    queue<block> Q;
    Q.push({0,0,0});
    vis[0][0][0] = 1; 
    while (!Q.empty()) {
        int n = Q.front().n;
        int m = Q.front().m;
        int k = Q.front().kick;
        if(n == N-1 && m == M-1){
            break;
        }
        Q.pop();
        for(int i=0;i<4;i++){
            int nn = n+dx[i];
            int nm = m+dy[i];
            if(nn >= 0 && nm >= 0 && nn < N && nm < M){ 
                if(map[nn][nm] == 0 && vis[nn][nm][k] == 0){ 
                    Q.push({nn,nm,k});
                    vis[nn][nm][k] = vis[n][m][k] + 1;
                }
                else if(map[nn][nm] == 1 && k < K && vis[nn][nm][k+1] == 0){
                    Q.push({nn,nm,k+1});
                    vis[nn][nm][k+1] = vis[n][m][k] + 1;
                }
            }
        }
    }
    int result = -1;
    for(int i=0;i<=K;i++){ 
        if(vis[N-1][M-1][i] != 0){
            result = vis[N-1][M-1][i];
            break;
        }
    }
    cout << result << endl;
}
