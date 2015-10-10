#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, time;
vector<vector<int> > g;
vector<int> used, d, up;
set<int> u;

void dfs(int v, int p = -1){
    int children=0;

    used[v]=1;
    d[v] = up[v] = ++time;

    //cout<<v<<" // time = "<<time<<endl;

    for(vector<int>::iterator to = g[v].begin(); to < g[v].end(); ++to){
        if(*to==p) continue; // if parent

        if(used[*to]){ // if used
            if(d[*to]<up[v]) up[v]=d[*to];
        } else { // if new edge
            dfs(*to, v);
            ++children;
            if(up[*to]<up[v]) up[v]=up[*to];

            if(d[v]<=up[*to] && p!=-1){
                //cout<<v<<" "<<*to<<" ("<<d[v]<<", "<<up[*to]<<")"<<endl;
                u.insert(v);
            }
        }

    }

    //cout<<"up["<<v<<"] = "<<up[v]<<endl;
    if(p==-1 && children>1){
        u.insert(v);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m,a,b;

    fin>>n>>m;

    g.assign(n+1,vector<int>());
    used.assign(n+1,0);
    d.assign(n+1,0);
    up.assign(n+1,0);
    time = 0;

    for(int i=0; i<m; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; ++i){
        if(!used[i]) dfs(i);
    }

    /*for(int i=1; i<=n; ++i){
        fout<<d[i]<<" "<<up[i]<<endl;
    }*/

    fout<<u.size()<<endl;
    for(set<int>::iterator it=u.begin(); it!=u.end(); ++it){
        fout<<*it<<endl;
    }

    fin.close();
    fout.close();
}
