// 1525
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<string> Q;
    string TARGET = "123456780";
    map<string, int> vis;
    string s1 = "";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char t; cin >> t;
            s1 = s1 + t;
        }
    }
    Q.push(s1);
    vis[s1] = 0;
    while(!Q.empty()){
        string str = Q.front();
        Q.pop();
        if(str == TARGET){break;}
        else {
            int zero = str.find("0");
            int x = zero / 3;
            int y = zero % 3;
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 3 && ny < 3 && nx >=0 && ny >= 0){
                    string tmp = str;
                    swap(tmp[nx*3+ny],tmp[x*3+y]);
                    if(!vis.count(tmp)){
                        vis[tmp] = vis[str]+1;
                        Q.push(tmp); 
                    }
                }
            }
        }
    }
    if (!vis.count(TARGET)) cout << -1;
    else cout << vis[TARGET];
    return 0;
}


