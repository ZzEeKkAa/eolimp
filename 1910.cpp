#include <fstream>
#include <vector>

using namespace std;

int n, comp;
vector<int> used;
vector<vector<int> > g;
vector<vector<int> > gt;
vector<int> l;
vector<int> c;

vector<int> cv;
vector<int> usedc;

int dfs( int v ) {
    used[v] = 1;
    usedc[c[v]] = 1;
    vector<int>::iterator finish = g[v].end();
    for(vector<int>::iterator it = g[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs(*it);
    }
}

int dfs1( int v ) {
    used[v] = 1;
    vector<int>::iterator finish = g[v].end();
    for(vector<int>::iterator it = g[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs1(*it);
    }
    l.push_back(v);
}

int dfs2(int v){
    used[v]=1;
    vector<int>::iterator finish = gt[v].end();
    for(vector<int>::iterator it = gt[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs2(*it);
    }
    c[v]=comp;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m,a,b,ans;
    bool check;

    fin>>n>>m;

    g.assign(n+1, vector<int>());
    gt.assign(n+1, vector<int>());
    used.assign(n+1, 0);

    for(int i=0; i<m; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    for(int i=1; i<=n; ++i){
        if(!used[i]) dfs1(i);
    }

    used.clear();
    used.assign(n+1, 0);
    c.assign(n+1, 0);
    comp=0;
    cv.push_back(0);

    for(int i=l.size()-1; i>=0; --i){
        if(!used[l[i]]) {
            ++comp;
            cv.push_back(l[i]);
            dfs2(l[i]);
        }
    }

    used.clear();
    used.assign(n+1, 0);
    usedc.assign(comp+1, 0);

    ans=-1;
    for(int i=1; i<=comp; ++i){
        if(!usedc[i]){
            check=false;
            if(i!=c[1] && !used[1]) check=true;
            dfs(cv[i]);
            if(check) if(used[1]) ans++;
            ans++;
        }
    }

    fout<<ans<<endl;

    fin.close();
    fout.close();
}
