#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M, K;
int x1, y1, x2, y2;
char T[1002][1002];
int V[1002][1002];

int bfs() {
    queue<pair<int, int>> Q;
    Q.push({x1, y1});
    V[x1][y1] = 0;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if (x == x2 && y == y2) {
            return V[x][y];
        }

        for (int i = 0; i < 4; ++i) {
            for (int k = 1; k <= K; ++k) {
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;

                if (nx < 0 || ny < 0 || nx >= N || ny >= M || T[nx][ny] == '#') {
                    break;
                }

                if (V[nx][ny] > V[x][y] + 1) {
                    Q.push({nx, ny});
                    V[nx][ny] = V[x][y] + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> T[i][j];
            V[i][j] = INF;
        }
    }

    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;

    int result = bfs();

    cout << result << '\n';

    return 0;
}
