# 말이 되고픈 원숭이
- https://www.acmicpc.net/problem/1600
```C++
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int K, X, Y;
int map[201][201];
int vis[201][201][31]; 
queue<pair<pair<int, int>, int> > Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int hx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> K >> X >> Y;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cin >> map[i][j];
        }
    }
    memset(vis, -1, sizeof(vis));
    Q.push(make_pair(make_pair(0, 0), 0));
    vis[0][0][0] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int k = cur.second;

        if (x == X-1 && y == Y-1) {
            cout << vis[y][x][k] << endl;
            return 0;
        }

        if (k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx >= 0 && ny >= 0 && nx < X && ny < Y && map[ny][nx] == 0 && vis[ny][nx][k + 1] == -1) {
                    Q.push(make_pair(make_pair(nx, ny), k + 1));
                    vis[ny][nx][k + 1] = vis[y][x][k] + 1;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < X && ny < Y && map[ny][nx] == 0 && vis[ny][nx][k] == -1) {
                Q.push(make_pair(make_pair(nx, ny), k));
                vis[ny][nx][k] = vis[y][x][k] + 1;
            }
        }
    }
    cout << -1 << endl;
}
```
