#include <fstream>
#include <vector>
#include <set>

using namespace std;

int n, time;
vector<vector<pair<int, int> > > g; // node, edge
vector<int> used, d, up;
set<int> bridges;

int bfs(int v, int p =-1){
    int to;
    used[v]=1;
    d[v] = up[v] = ++time;
    //cout<<v<<" // time = "<<time<<endl;

    for(vector<pair<int, int> >::iterator it = g[v].begin(); it<g[v].end(); ++it){
        to=(*it).first;

        if(to==p) continue;

        if(used[to]){
            if(d[to]<up[v]) up[v]=d[to];
        } else {
            bfs(to,v);
            if(up[to]<up[v]) up[v]=up[to];

            if(up[to]>d[v]){
                //cout<<v<<" "<<to<<endl;
                bridges.insert((*it).second);
            }
        }

    }

    //cout<<v<<" // up = "<<up[v]<<endl;

}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m,a,b;
    fin>>n>>m;

    g.assign(n+1, vector<pair<int, int> >());
    used.assign(n+1, 0);
    d.assign(n+1, 0);
    up.assign(n+1, 0);
    time=0;

    for(int i=1; i<=m; ++i){
        fin>>a>>b;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }

    for(int i=1; i<=n; ++i){
        if(!used[i]) bfs(i);
    }

    fout<<bridges.size()<<endl;

    if(bridges.size()>0){
        set<int>::iterator it = bridges.begin();
        fout<<*it++;

        for(; it!=bridges.end(); ++it){
            fout<<" "<<*it;
        }
        fout<<endl;
    }


    fin.close();
    fout.close();
}
