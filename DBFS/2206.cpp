// 2206
#include<iostream>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int map[1001][1001];
int vis[1001][1001][2];
int Y, X;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Y >> X;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }
    queue<pair<pair<int,int>, int> > Q;
    vis[0][0][0] = 1;
    Q.push(make_pair(make_pair(0, 0), 0)); 
    while(!Q.empty()){
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int broken = Q.front().second;
        Q.pop();

        if(y == Y-1 && x == X-1){ 
            cout << vis[y][x][broken] << endl; 
            return 0; 
        }

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && nx >= 0 && ny < Y && nx < X){
                if(map[ny][nx] == 0 && vis[ny][nx][broken] == 0){ 
                    vis[ny][nx][broken] = vis[y][x][broken] + 1;
                    Q.push(make_pair(make_pair(ny, nx), broken));
                }
                else if(map[ny][nx] == 1 && broken == 0){ 
                    vis[ny][nx][1] = vis[y][x][0] + 1; 
                    Q.push(make_pair(make_pair(ny, nx), 1)); 
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
