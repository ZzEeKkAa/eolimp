#include <stdio.h>
#include <vector>

using namespace std;

int n,m, col;
vector<vector<int> > g, gr;
vector<int> used, color, l, colors, ans;

int dfs(int v){
    used[v]=1;
    for(vector<int>::iterator it = g[v].begin(); it<g[v].end(); ++it){
        if(!used[*it]) dfs(*it);
    }
    l.push_back(v);
}

int dfs2(int v){
    color[v]=col;
    for(vector<int>::iterator it = gr[v].begin(); it<gr[v].end(); ++it){
        if(!color[*it]) dfs2(*it);
    }
}

int main(){
    int a,b;
    freopen("input.txt", "r", stdin); freopen("output.txt","w", stdout);

    scanf("%d",&n);
    g.assign(n+1,vector<int>());
    gr.assign(n+1, vector<int>());
    used.assign(n+1,0);
    color.assign(n+1,0);

    scanf("%d", &m);
    for(int i=0; i<m; ++i){
        scanf("%d %d", &a,&b);
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i=1; i<=n; ++i)
        if(!used[i]) dfs(i);

    col=0;
    for(int i=l.size()-1; i>=0; --i)
        if(!color[l[i]]) { ++col; dfs2(l[i]); }

    colors.assign(col+1, 1);
    for(int i=gr.size()-1; i>=1; --i)
    for(int j=gr[i].size()-1; j>=0; --j){
        if(color[i]!=color[gr[i][j]]) { colors[color[gr[i][j]]]=0; if(colors[color[i]]) colors[color[i]]=i; }
    }

    for(int i=1; i<=col; ++i){
        if(colors[i]) ans.push_back(colors[i]);
    }

    printf("%d\n%d",ans.size(),ans[0]);
    for(int i=1; i<ans.size(); ++i){
        printf(" %d",ans[i]);
    } printf("\n");/**/

    return 0;
}
