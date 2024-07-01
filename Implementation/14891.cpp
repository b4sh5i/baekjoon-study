#include<iostream>
#include <cstring>

using namespace std;

string gear[4];
int isCheck[4];
int K;
int ans = 0;

void init(){
    for(int i=0;i<4;i++){
        isCheck[i] = 0;
    }
}

void left_check(int idx, int w) {
    if (idx <= 0) 
        return;
    if (gear[idx][6] != gear[idx - 1][2]){
        isCheck[idx - 1] = w * -1;
        left_check(idx - 1, w * -1);
    }
}

void right_check(int idx, int w) {
    if (idx >= 3) 
        return;
    if (gear[idx][2] != gear[idx + 1][6]){
        isCheck[idx + 1] = w * -1;
        right_check(idx + 1, w * -1);
    }
}

void move(int idx, int w){
    if(w == 1)
        gear[idx] = gear[idx].substr(7) + gear[idx].substr(0,7);
    else if(w == -1)
        gear[idx] = gear[idx].substr(1,7) + gear[idx].substr(0,1);
}

void check(int idx, int w){
    isCheck[idx] = w;
    left_check(idx, w);
    right_check(idx, w);
    for(int i = 0; i < 4; i++){
        move(i, isCheck[i]);
    }
}

int main(){
    for(int i = 0;i<4;i++){
        cin >> gear[i];
    }
    cin >> K;
    int g; int r;
    for (int i = 0; i < K; i++) {
        cin >> g >> r;
        init();
        check(g - 1, r);
    }
    int mul = 1;
    for (int i = 0; i < 4; i++) {
        ans += (gear[i][0] - '0') * mul;
        mul *= 2;
    }
    cout << ans;
}