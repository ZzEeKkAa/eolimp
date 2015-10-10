#include <fstream>
#include <vector>

using namespace std;

int n,k;
vector<vector<int> > g;
vector<int> used;

void dfs(int v){
    used[v]=1;

    for(int i = 0; i<g[v].size(); ++i){
        if(!used[g[v][i]]) dfs(g[v][i]);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int a,b;
    int comp=0;

    fin>>n>>k>>k;

    g.assign(n+1, vector<int>());
    used.assign(n+1,0);

    for(int i=0; i<k; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; ++i){
        if(!used[i]) {
            dfs(i);
            ++comp;
        }
    }

    fout<<(comp-1)<<endl;

    fin.close();
    fout.close();
}
