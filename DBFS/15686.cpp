// 15686
#include<iostream>
#include <cmath>
#include<vector>

using namespace std;

int N, M;
struct Home_ {
    int r, c;
};
struct Chik_ {
    int r, c;
    bool vis;
};
int min_v1 = 2147483647;
vector<Home_> home;
vector<Chik_> chik;

void dfs(int idx, int cont){
    if(cont == M){
        int v1 = 0;
        for(int i=0;i<home.size();i++){
            int min_v2 = 2147483647;
            for(int j=0;j<chik.size();j++){
                if(chik[j].vis){
                    int v2 = abs(home[i].r - chik[j].r) + abs(home[i].c - chik[j].c);
                    if(v2 < min_v2){
                        min_v2 = v2;
                    }
                }
            }
            v1 += min_v2;
        }
        if(v1 < min_v1){
            min_v1 = v1;
        }
    }
    
    for(int i=idx;i<chik.size();i++){
        if(!chik[i].vis){
            chik[i].vis = true;
            dfs(i, cont+1);
            chik[i].vis = false;
        }
    }

}


int main(){
    cin >> N >> M;
    int t;
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            cin >> t;
            if(t == 1){ home.push_back({i,j}); }
            else if(t == 2){ chik.push_back({i,j,false}); }
        }
    }
    dfs(0,0);
    cout << min_v1;
}
