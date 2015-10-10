#include <fstream>
#include <memory.h>
#define MAX 11

using namespace std;

int n;
int g[MAX][MAX];
int used[MAX];
int l[MAX], len;

void dfs1(int v){
    used[v]=1;

    for(int i=1; i<=n; ++i) if(g[v][i]){
        if(!used[i]) dfs1(i);
    }

    l[++len]=v;
}

void dfs2(int v){
    used[v]=1;

    for(int i=1; i<=n; ++i) if(g[i][v]){
        if(!used[i]) dfs2(i);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m,a,b;
    int comp;

    len=0; comp=0;
    memset(g,0,sizeof(g));

    fin>>n>>m;

    for(int i = 0; i<m; ++i){
        fin>>a>>b;
        g[a][b]=1;
    }

    memset(used, 0, sizeof(used));

    for(int i=1; i<=n; ++i){
        if(!used[i]) dfs1(i);
    }

    memset(used, 0, sizeof(used));

    for(int i=len; i>0; --i){
        if(!used[l[i]]) { ++comp; dfs2(l[i]); }
    }

    fout<<comp<<endl;

    fin.close();
    fout.close();
}
