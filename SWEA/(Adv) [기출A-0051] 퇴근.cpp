#include<iostream>
#include<queue>
#include<string>
using namespace std;

int T;
int end_x, end_y;
int s_x, s_y;
int map[101][101];
int vis[101][101][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{x, y}, {0, 0}});
    vis[x][y][0] = 1;
    
    while(!Q.empty()){
        int x1 = Q.front().first.first;
        int y1 = Q.front().first.second;
        int deep = Q.front().second.first;
        int key = Q.front().second.second;
        Q.pop();
        
        if(map[x1][y1] == 2){
            cout << deep << endl;
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if(nx >= 0 && ny >= 0 && nx < end_x && ny < end_y && !vis[nx][ny][key]){
                if(map[nx][ny] == 4){
                    vis[nx][ny][1] = 1;
                    Q.push({{nx, ny}, {deep + 1, 1}});
                }
                else if (map[nx][ny] == 3 && key == 1) {
                    vis[nx][ny][key] = 1;
                    Q.push({{nx, ny}, {deep + 1, key}});
                }
                else if (map[nx][ny] == 0) {
                    vis[nx][ny][key] = 1;
                    Q.push({{nx, ny}, {deep + 1, key}});
                }
                else if (map[nx][ny] == 2) {
                    vis[nx][ny][key] = 1;
                    Q.push({{nx, ny}, {deep + 1, key}});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main(){
    cin >> end_x >> end_y;
    cin >> s_x >> s_y;
    string v1;
    for(int i = 0; i < end_x; i++){
        cin >> v1;
        for(int j = 0; j < end_y; j++){
            if(v1[j] == '_') map[i][j] = 0;
            else if(v1[j] == 'X') map[i][j] = 1;
            else if(v1[j] == 'O') map[i][j] = 2;
            else if(v1[j] == 'A') map[i][j] = 3;
            else if(v1[j] == 'a') map[i][j] = 4;
        }
    }
    
    bfs(s_x - 1, s_y - 1);
    return 0;
}
