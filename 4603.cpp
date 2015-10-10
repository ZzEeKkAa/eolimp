#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

vector<int> used, gr, a_len;
vector<vector<int> > g;

ll len;
int dfs(int v){
    int n=0;
    used[v]=1;
    if(a_len[v]) return a_len[v];

    for(vector<int>::iterator to = g[v].begin(); to<g[v].end(); ++to){
        if(!used[*to]) n+=dfs(*to);
    }
    len+=n;
    n+=g[v].size();
    printf("%d %d\n",v,n);
    return n;
}
/*
void deycstra(int v){
    int d;
    priority_queue<pair<int, int>,vector<pair<int, int> >,less<pair<int, int> > > q;
    q.push(make_pair(0,v));

    while(!q.empty()){
        d=q.top().first;
        v=q.top().second;
        q.pop();

        //printf("(%d,%d)\n",d,v);

        if(dist[v]!=d) continue;

        for(vector<int>::iterator to=g[v].begin(); to<g[v].end(); ++to){
            if(d+1>dist[*to]) {
                q.push(make_pair(d+1,*to));
                dist[*to]=d+1;
            }
        }

    }

}*/


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    int u,v;
    ll ans=0;
    scanf("%d %d",&n,&k);
    g.assign(n+1,vector<int>());
    gr.assign(n+1,0);
    a_len.assign(n+1,0);

    for(int i=0; i<k; ++i){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        ++gr[v];
    }


    /*/printf("end: ");
    for(int i=1; i<=n; ++i){
        if(g[i].size()==0) to.push_back(i);
        //printf("%d ",i);}
    }//printf("\n");*/

    ans=0;
    for(int i=1; i<=n; ++i){
        if(!gr[i]) {
            //len=0;
            //dist.assign(n+1,0);
            used.assign(n+1,0);
            //printf("dist(%d): ",i);
            //deycstra(i);

            //for(int j=1; j<=n; ++j) printf("%d ",dist[j]); printf("\n");

            /*for(vector<int>::iterator it=to.begin(); it<to.end(); ++it){
                len=dist[*it];
                ans+=(len*(len-1))>>1;
                //printf("len: %lld; ans: %lld\n",len,ans);
            }*/
            dfs(i);
        }
    }

    printf("%lld\n",ans);

    return 0;
}
