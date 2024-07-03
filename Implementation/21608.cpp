#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[21][21]; 
int N;

void find_p(int idx, vector<int> input[]){
    int v_cnt1[21][21] = {0};
    int v_cnt2[21][21] = {0};
    int max_cnt2 = -1;
    int ret_x = -1, ret_y = -1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] != 0) continue;

            int cnt1 = 0;
            int cnt2 = 0;

            for(int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(x >= 0 && x < N && y >= 0 && y < N) {
                    if(map[x][y] == 0) cnt1++;
                    for(int l = 0; l < 4; l++) {
                        if(input[idx][l] == map[x][y]) cnt2++;
                    }
                }
            }
            v_cnt1[i][j] = cnt1;
            v_cnt2[i][j] = cnt2;

            if(cnt2 > max_cnt2 || 
              (cnt2 == max_cnt2 && cnt1 > v_cnt1[ret_x][ret_y]) || 
              (cnt2 == max_cnt2 && cnt1 == v_cnt1[ret_x][ret_y] && (i < ret_x || (i == ret_x && j < ret_y)))) {
                max_cnt2 = cnt2;
                ret_x = i;
                ret_y = j;
            }
        }
    }
    map[ret_x][ret_y] = idx;
}

int main(){
    cin >> N;
    vector<int> input[N * N + 1];

    int idx, tmp;
    for(int i = 0; i < N * N; i++) {
        cin >> idx;
        for(int j = 0; j < 4; j++) {
            cin >> tmp;
            input[idx].push_back(tmp);
        }
        find_p(idx, input);
    }

    int ret = 0;
    int calc[4] = {1, 10, 100, 1000};

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int T = map[i][j];
            int cnt = 0;

            for(int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(x >= 0 && x < N && y >= 0 && y < N) {
                    for(int l = 0; l < 4; l++) {
                        if(map[x][y] == input[T][l]) {
                            cnt++;
                        }
                    }
                }
            }
            if(cnt > 0) ret += calc[cnt - 1];
        }
    }

    cout << ret << endl;
}
