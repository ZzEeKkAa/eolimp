#include <fstream>
#include <vector>

using namespace std;

int n,comp;
vector<int> used;
vector<vector<int> > g;
vector<vector<int> > gt;
vector<int> f;
vector<int> c;

void dfs1(int v){
    used[v]=1;
    vector<int>::iterator finish = g[v].end();
    for(vector<int>::iterator it = g[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs1(*it);
    }

    f.push_back(v);
}

void dfs2(int v){
    used[v]=1;
    c[v]=comp;
    vector<int>::iterator finish = gt[v].end();
    for(vector<int>::iterator it = gt[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs2(*it);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m,a,b;

    fin>>n>>m;

    g.assign(n+1,vector<int>());
    gt.assign(n+1,vector<int>());
    used.assign(n+1, 0);
    c.assign(n+1, 0);

    for(int i=0; i<m; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!used[i]) dfs1(i);
    }

    used.clear();
    used.assign(n+1, 0);

    comp=0;
    for(int i=f.size()-1; i>=0; --i){
        if(!used[f[i]]) { ++comp; dfs2(f[i]); }
    }

    fout<<comp<<endl;

    fout<<c[1];
    for(int i=2; i<=n; i++){
        fout<<" "<<c[i];
    }
    fout<<endl;

    fin.close();
    fout.close();
}
