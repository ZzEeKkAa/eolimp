#include <fstream>
#include <vector>

using namespace std;

int n, comp;
vector<vector<int> > g,gt;
vector<int> used, color, l;

int dfs1(int v){
    used[v]=1;

    vector<int>::iterator finish = g[v].end();
    for(vector<int>::iterator it = g[v].begin(); it < finish; it++){
        if(!used[*it]) dfs1(*it);
    }

    l.push_back(v);
}

int dfs2(int v){
    color[v]=comp;

    vector<int>::iterator finish = gt[v].end();
    for(vector<int>::iterator it = gt[v].begin(); it<finish; ++it){
        if(!color[*it]) {
            dfs2(*it);
        }
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m,a,b,ans;

    // Input
    fin>>n>>m;
    g.assign(n+1, vector<int>());
    gt.assign(n+1, vector<int>());
    for(int i=0; i<m; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    // Dividing by components
    used.assign(n+1,0);
    for(int i=1; i<=n; ++i){
        if(!used[i]) dfs1(i);
    }

    color.assign(n+1, 0);
    for(int i=l.size()-1; i>=0; --i){
        if(!color[l[i]]) {
            ++comp;
            dfs2(l[i]);
        }
    }

    // Getting answer
    used.assign(comp+1,1);
    for(int i=1; i<=n; ++i){
        vector<int>::iterator finish = g[i].end();
        for(vector<int>::iterator it = g[i].begin(); it<finish; ++it){
            if(color[i]!=color[*it]) used[color[*it]]=0;
        }
    }

    ans=0;
    for(int i=1; i<=comp; ++i){
        if(used[i]) ++ans;
    }

    fout<<ans<<endl;


    fin.close();
    fout.close();
}
