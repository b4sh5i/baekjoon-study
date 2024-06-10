#include<iostream>
#include<cstring>

int P[20];
int V[20];
int N, H, ret;

using namespace std;

void dfs(int v1, int cnt){
    if(cnt >= H){
        int dif = cnt - H;
        ret = min(ret, dif);
        return;
    }
    for(int i = v1;i<N;i++){
        if(V[i] == 1) continue;
        V[i] = 1;
        dfs(i, cnt+P[i]);
        V[i] = 0;
    }
}


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> H;
        ret = 987654321;
        memset(V,0,sizeof(V));
        memset(V,0,sizeof(V));
        for(int i=0;i<N;i++){
            cin >> P[i];
        }
        dfs(0,0);
        cout << "#" << T << " " << ret << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
