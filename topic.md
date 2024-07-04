민수는 회사에서 혼자 근무를 하고 있다. 일을 끝마친 민수는 퇴근을 하려고 하는데, 갑자기 회사의 문이 모두 잠겨버렸다. 잠긴 회사의 문을 열려면 열쇠가 필요하다. 회사의 문은 모두 동일한 문이며 하나의 열쇠로도 모든 문을 열 수 있다.


다행히 민수는 열쇠의 위치와 회사의 모습이 모두 그려져 있는 지도를 가지고 있다. 회사는 세로 R, 가로 C 크기의 1층짜리 건물이다. 그리고 민수는 지도상의 상하좌우 중 한 방향으로 이동할 수 있다. 민수가 한 칸 이동하는데 1의 시간이 소요될 때, 출구까지 가는 데 걸리는 최소 시간을 구하시오.



[지도의 기호]

X : 벽

_ : 이동할 수 있는 곳

O : 출구

A : 문

a : 열쇠





[제한 조건]

1. 일을 끝마친 순간의 민수는 열쇠를 가지고 있지 않다.

2. 문은 열리는 두 방향을 제외하고는 벽으로 둘러 쌓여있다.

3. 회사의 외곽은 모두 벽으로 둘러 쌓여있다.

4. 처음 민수가 위치한 곳은 벽이 아니고 열쇠가 존재하지 않는다.

5. 열쇠가 있는 곳은 벽이 아니며 열쇠는 최대 5개까지 있을 수 있다.

6. 열쇠는 여러 번 사용할 수 있다.

7. 민수는 상하좌우로 이동할 수 있다.



[입력]

첫 줄에 테스트 케이스의 개수 T가 주어지며, 그 다음 T 개의 테스트 케이스가 주어진다. 각 케이스의 첫째 줄에는 회사의 세로 R과 가로 C가(5 ≤ R, C ≤ 100) 주어지며, 둘째 줄에는 민수의 위치 세로 r(2 ≤ r ≤ R-1)과 가로 c(2 ≤ c ≤ C-1)가 주어진다. 그 다음 R개의 줄에 걸쳐서 지도에 그려진 회사의 모습이 표현된다.


[출력]

테스트 케이스 하나당 한 줄씩 출력한다. 맨 처음 #x (x는 테스트케이스 번호, 1부터 시작)을 출력하고 공백을 하나 둔 후 시간을 출력한다. 단, 퇴근을 할 방법이 없다면 시간 대신 -1을 출력하라.



[입출력 예]

(입력)

3
6 6
2 4
XXXXXX
X____X
X_X_aX
XAXXXX
X___OX
XXXXXX
7 7
2 2
XXXXXXX
X____aX
X_XXXXX
X____aX
X_XXXXX
X__AAOX
XXXXXXX
5 10
2 5
XXXXXXXXXX
X__a__Aa_X
XAXXXXXX_X
X_aXXXXXOX
XXXXXXXXXX


(출력)

#1 12
#2 16
#3 8



(sample_input.txt에 대한 출력)
#1 12
#2 16
#3 8
#4 22
#5 33
#6 29
#7 22
#8 -1
#9 194
#10 447




=====================
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
