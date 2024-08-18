#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int map1[10];
int vis[10];
int arr[10];

void dfs_func(int P){
    if(P == M){
        for(int i=0;i<M;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<N;i++){
        if(vis[i] == 0){
            arr[P] = map1[i];
            vis[i] = 1;
            dfs_func(P+1);
            vis[i] = 0;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> map1[i];
    }
    sort(map1, map1+N);
    dfs_func(0);
}
