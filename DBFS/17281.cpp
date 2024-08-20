#include <iostream>
#include <cstring>   
using namespace std;

int N, ret;
int map[51][9];
int sel[9];
int order[9];

int check_big(int A, int B) { return A > B ? A : B; }

void start_point() {
    int score = 0;
    int start = 0;
    int base[4];

    for (int i = 0; i < N; i++) {
        int out_cnt = 0;
        memset(base, 0, sizeof(base));

        while (out_cnt < 3) {
            int player = order[start];
            int hit = map[i][player];

            if (hit == 0) {
                out_cnt++;
            } else if (hit == 1) {
                score += base[3];
                base[3] = base[2];
                base[2] = base[1];
                base[1] = 1;
            } else if (hit == 2) {
                score += base[3] + base[2];
                base[3] = base[1];
                base[2] = 1;
                base[1] = 0;
            } else if (hit == 3) {
                score += base[3] + base[2] + base[1];
                base[3] = 1;
                base[2] = base[1] = 0;
            } else if (hit == 4) {
                score += base[3] + base[2] + base[1] + 1;
                base[3] = base[2] = base[1] = 0;
            }

            start = (start + 1) % 9;
        }
    }

    ret = check_big(ret, score);
}

void dfs(int cnt) {
    if (cnt == 9) {
        start_point();
        return;
    }
    if (cnt == 3) {  
        dfs(cnt + 1);
        return;
    }
    for (int i = 1; i < 9; i++) { 
        if (sel[i] == 1) continue;
        sel[i] = 1;
        order[cnt] = i;
        dfs(cnt + 1);
        sel[i] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }
    
    order[3] = 0;
    sel[0] = 1;
    
    dfs(0);
    cout << ret << endl;
}
