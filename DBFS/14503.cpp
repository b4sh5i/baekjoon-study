// 14503
#include<iostream>
#include<queue>

using namespace std;

int map[51][51];
int vis[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int N, M, SN, SM, front;
    int ret = 0;
    cin >> N >> M;
    cin >> SN >> SM >> front;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    while(1){
        if(vis[SN][SM] == 0){
            vis[SN][SM] = 1;
            ret++;
        }
        int ch = 0;
        for(int i=0;i<4;i++){
            front = (front+3) % 4;
            int n1 = SN + dx[front];
            int m2 = SM + dy[front];
            if( map[n1][m2] == 0 && vis[n1][m2] == 0){
                SN += dx[front];
                SM += dy[front];
                ch = 1;
                break;
            }
        }
        if(!ch){
            int back = (front+2) % 4;
            if(map[SN+dx[back]][SM+dy[back]] == 1) break;
            SN += dx[back];
            SM += dy[back];
        }
    }

    cout << ret;
}
