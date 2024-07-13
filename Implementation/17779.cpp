#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 21;
int T;
int map[MAX][MAX];
int dist[MAX][MAX];
int ret;
int diffck = 987654321;

void calc(int x, int y, int d1, int d2) {
    // 경계선을 따라 5번 선거구 설정
    for (int i = 0; i <= d1; i++) {
        dist[x + i][y - i] = 5;
        dist[x + d2 + i][y + d2 - i] = 5;
    }
    for (int i = 0; i <= d2; i++) {
        dist[x + i][y + i] = 5;
        dist[x + d1 + i][y - d1 + i] = 5;
    }

    // 경계선 내부를 5번 선거구로 설정
    for (int i = x + 1; i < x + d1 + d2; i++) {
        bool inside = false;
        for (int j = 0; j <= T; j++) {
            if (dist[i][j] == 5) inside = !inside;
            if (inside) dist[i][j] = 5;
        }
    }

    int ckpoint[6] = {0};

    // 각 칸에 대해 선거구 번호 지정 및 인구 계산
    for (int r = 0; r < T; r++) {
        for (int c = 0; c < T; c++) {
            if (dist[r][c] == 5) {
                ckpoint[5] += map[r][c];
            } else if (0 <= r && r < x + d1 && 0 <= c && c <= y) {
                dist[r][c] = 1;
                ckpoint[1] += map[r][c];
            } else if (0 <= r && r <= x + d2 && y < c && c < T) {
                dist[r][c] = 2;
                ckpoint[2] += map[r][c];
            } else if (x + d1 <= r && r < T && 0 <= c && c < y - d1 + d2) {
                dist[r][c] = 3;
                ckpoint[3] += map[r][c];
            } else if (x + d2 < r && r < T && y - d1 + d2 <= c && c < T) {
                dist[r][c] = 4;
                ckpoint[4] += map[r][c];
            }
        }
    }

    // 최소 최대 인구 차이 갱신
    int maxckpoint = ckpoint[1];
    int minckpoint = ckpoint[1];
    for (int i = 2; i <= 5; i++) {
        if (ckpoint[i] > maxckpoint) maxckpoint = ckpoint[i];
        if (ckpoint[i] < minckpoint) minckpoint = ckpoint[i];
    }
    if (maxckpoint - minckpoint < diffck) {
        diffck = maxckpoint - minckpoint;
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            cin >> map[i][j];
            ret += map[i][j];
        }
    }

    for (int x = 0; x < T; x++) {
        for (int y = 0; y < T; y++) {
            for (int d1 = 1; d1 < T; d1++) {
                for (int d2 = 1; d2 < T; d2++) {
                    if (x + d1 + d2 >= T) continue;
                    if (y - d1 < 0 || y + d2 >= T) continue;
                    memset(dist, 0, sizeof(dist));
                    calc(x, y, d1, d2);
                }
            }
        }
    }

    cout << diffck << endl;

    return 0;
}
