#include<iostream>
#include <queue>
#include <cstring> 

using namespace std;

queue<pair<int,int> >Q;
int map[50][50],vis[50][50];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
int w,h;

void bfs(){
    while(!Q.empty()){
        int h1 = Q.front().first;
        int w1 = Q.front().second;
        Q.pop();
        for(int i=0;i<8;i++){
            int nh = h1+dy[i];
            int nw = w1+dx[i];
            if(nh < 0 || nw < 0 || nh >= h || nw >= w) continue;
            if(map[nh][nw] && !vis[nh][nw]){
                    Q.push(make_pair(nh,nw));
                    vis[nh][nw] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    while(1){
        int cnt=0;
        cin>>w>>h;
        if(!w&&!h)break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vis[i][j] && map[i][j]){
                    Q.push(make_pair(i,j));
                    vis[i][j] = 1;
                    bfs();
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
    }
}
