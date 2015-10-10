#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<vector<pair<int, int> > > g;

vector<int> height, order, first,weight;
vector<vector<int> > M;

int time=0;
int h=0;
void dfs(int v, int p){
    if(!first[v]) first[v]=time;
    order[time]=v;
    height[time]=++h;
    ++time;

    int to, w;
    for(vector<pair<int,int> >::iterator it = g[v].begin(); it<g[v].end(); ++it){
        to=it->first;
        w=it->second;
        if(to==p) continue;
        weight[to]=weight[v]+w;
        dfs(to,v);
        order[time]=v;
        height[time]=h;
        ++time;
    }

    --h;
}

void build(void){
    int st=log2(time)+1;

    vector<int> tmp;
    tmp.assign(st,0);
    M.assign(time,tmp);

    for(int i=0; i<time; ++i) M[i][0]=i;

    for(int j=1,p=2; j<st; ++j,p*=2){
        for(int i=0; i<time-p+1; ++i){
            if(height[M[i][j-1]]<=height[M[i+p/2][j-1]])
                M[i][j]=M[i][j-1];
            else
                M[i][j]=M[i+p/2][j-1];
        }
    }
}

int rmq(int a, int b){
    if(a>b) swap(a,b);
    //printf("rmq %d %d\n",a,b);
    int length = b-a+1;
    int p=1,st=0;
    for(; p<=length; p*=2,++st); p/=2; --st;
    //printf("length: %d; st: %d; pow: %d\n",length,st,p);

    if(height[M[a][st]]<=height[M[b-p+1][st]])
        return M[a][st];
    else
        return M[b-p+1][st];
}

int lca(int v1, int v2){
    //printf("-> %d %d: ")
    return order[rmq(first[v1],first[v2])];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m;
    int u,v,w;

    scanf("%d",&n);
    g.assign(n,vector<pair<int, int> >());

    for(int i=1; i<n; ++i){
        scanf("%d %d %d",&u,&v,&w);
        g[v].push_back(make_pair(u,w));
        g[u].push_back(make_pair(v,w));
    }


    weight.assign(n,0);

    first.assign(n,0);
    order.assign(2*n+1,0);
    height.assign(2*n+1,0);
    dfs(0,0);
    build();

    /*for(int i=0; i<2*n+1; ++i) printf("%d ",order[i]); printf("\n");
    for(int i=0; i<2*n+1; ++i) printf("%d ",height[i]); printf("\n");
    for(int i=0; i<n; ++i) printf("%d ",first[i]); printf("\n");

    int st=log2(time)+1;
    for(int j=0; j<st; ++j){
        for(int i=0; i<time; ++i){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }*/

    scanf("%d",&m);

    for(int i=0; i<m; ++i){
        scanf("%d %d",&u,&v);
        w=lca(u,v);
        printf("%d\n",weight[u]+weight[v]-2*weight[w]);
    }

    return 0;
}

