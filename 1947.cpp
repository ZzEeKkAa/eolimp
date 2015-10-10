//#include <fstream>
#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

int n;
vector<vector<int> > g,gt;
vector<int> used, l, color;
int comp;
set<pair<int, int> > cond;

void dfs1(int v){
    used[v]=1;

    vector<int>::iterator finish = g[v].end();
    for(vector<int>::iterator it = g[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs1(*it);
    }

    l.push_back(v);
}

void dfs2(int v){
    used[v]=1;

    vector<int>::iterator finish = gt[v].end();
    for(vector<int>::iterator it = gt[v].begin(); it<finish; ++it){
        if(!used[*it]) dfs2(*it);
    }

    color[v]=comp;
}

int main(){
    int m,a,b;
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    scanf("%d %d", &n, &m);

    g.assign(n+1, vector<int>());
    gt.assign(n+1, vector<int>());

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    used.assign(n+1,0);

    for(int i=1; i<=n; ++i){
        if(!used[i]) dfs1(i);
    }

    used.assign(n+1, 0);
    color.assign(n+1, -1);
    comp=0;

    for(int i=l.size()-1; i>=0; --i){
        if(!used[l[i]]) { dfs2(l[i]); ++comp; }
    }

    for(int i=1; i<=n; ++i)
    for(vector<int>::iterator it = g[i].begin(); it<g[i].end(); ++it){
        if(color[i]!=color[*it]) cond.insert(make_pair(color[i],color[*it]));
    }

    printf("%d\n",cond.size());
    //fout<<cond.size()<<endl;
}
