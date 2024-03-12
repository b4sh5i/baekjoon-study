// 13460
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int Y, X;
char map[11][11];
int vis[11][11][11][11]; // R , B
struct step {
    int Rx, Ry;
    int Bx, By;
    int Count;
};

void move(int& rx, int& ry, int& distance, int& i)
{
    while (map[ry + dy[i]][rx + dx[i]] != '#' && map[ry][rx] != 'O')
    {
        rx += dx[i];
        ry += dy[i];
        distance += 1;
    }
    if (rx < 0 || ry < 0 || rx >= X || ry >= Y) {
        rx -= dx[i];
        ry -= dy[i];
    }
}

void bfs(int Rx, int Ry, int Bx, int By){
    queue<step> Q;
    Q.push({Rx,Ry,Bx,By,0});
    vis[Rx][Ry][Bx][By] = 1;
    while(!Q.empty()){
        int rx = Q.front().Rx;
        int ry = Q.front().Ry;
        int bx = Q.front().Bx;
        int by = Q.front().By;
        int cnt = Q.front().Count;
        Q.pop();

        if(cnt >= 10){break;}
        
        for(int i=0;i<4;i++){
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            int rc = 0, bc = 0;

            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);

            if(map[nby][nbx] == 'O') continue;
            if(map[nry][nrx] == 'O'){ cout << cnt + 1; return;}
            if(nrx == nbx && nry == nby){
                if(rc > bc){
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            if(vis[nry][nrx][nby][nbx] == 0){
                vis[nry][nrx][nby][nbx] = 1;
                Q.push({nrx,nry,nbx,nby,cnt+1});
            }
        }
    }
    cout << "-1";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> Y >> X;
    int Rx = 0, Ry = 0, Bx = 0, By = 0;
    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            cin >> map[i][j];
            if(map[i][j] == 'B') {
                Bx = j;
                By = i;
            }
            else if(map[i][j] == 'R') {
                Rx = j;
                Ry = i;
            }
        }
    }
    bfs(Rx, Ry, Bx, By);
}
