#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<vector<int> > g;

vector<int> height, order, first;
vector<vector<int> > M;

int time=0;
int h=0;

void dfs(int v, int p){
    if(!first[v]) first[v]=time;
    order[time]=v;
    height[time]=++h;
    ++time;

    for(vector<int>::iterator to = g[v].begin(); to<g[v].end(); ++to){
        if(*to==p) continue;
        dfs(*to,v);
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

    int k;
    char c;
    int a,b;
    vector<pair<int, int> > get;

    scanf("%d",&k);
    for(int i=0; i<k; ++i){
        scanf("%c",&c);
        scanf("%c",&c);
        scanf("%c",&c);
        scanf("%c",&c);
        scanf("%d %d",&a,&b);
        --a; --b;

        //printf("%d %d %d\n",i,a,b);
        if(c=='T'){
            get.push_back(make_pair(a,b));
        } else{
            g.resize(max(a,b)+1, vector<int>());
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    int n = g.size();

    first.assign(n,0);
    order.assign(2*n+1,0);
    height.assign(2*n+1,0);
    dfs(0,0);
    build();

    int u,v;
    for(vector<pair<int, int> >::iterator it = get.begin(); it<get.end(); ++it){
        u=it->first;
        v=it->second;
        printf("%d\n",lca(u,v)+1);
    }

    return 0;
}
