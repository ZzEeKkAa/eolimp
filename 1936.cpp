#include <stdio.h>
//#include <fstream>
#include <vector>


using namespace std;

int n,m,num;
vector<vector<int> > g;
vector<int> used;
vector<int> l;

void dfs1(int v){
    used[v]=1;

    for(int i=0; i<n; ++i){
        if(!used[i] && g[v][i]<=m) dfs1(i);
    }

    l.push_back(v);
}

void dfs2(int v){
    used[v]=1; num++;

    for(int i=0; i<n; ++i){
        if(!used[i] && g[i][v]<=m) dfs2(i);
    }
}

int globaldfs(int m_){
    m=m_;
    l.clear();
    num=0;
    used.assign(n,0);

    for(int i=0; i<n; ++i){
        if(!used[i]) dfs1(i);
    }

    used.assign(n,0);

    dfs2(l.back());

    if(num<n) return 1;

    return 0;
}

int main(){
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    int minm, maxm,c;

    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    //fin>>n;
    scanf("%d",&n);

    g.assign(n, vector<int>(n,0));

    minm=0; maxm=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            //fin>>g[i][j];
            scanf("%d",&g[i][j]);
            if(g[i][j]>maxm) maxm=g[i][j];
        }
    }

    while(minm<maxm){
        m=(minm+maxm)/2;
        if(globaldfs(m)==0){
            maxm=m;
        } else {
            minm=m+1;
        }
    }

    printf("%d\n",minm);
    //fout<<minm<<endl;

    //fin.close();
    //fout.close();
}
