#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int ans;
vector<vector<pair<int, int> > > g;
vector<int> used;
vector<vector<int> > m;

int dfs(int v, int p, ll num, ll sw, ll &_num, ll &_sw){
    int to; ll w;
    ll num_, sw_;
    _sw=sw;
    _num=num;
    sw%=1000000000;
    ans+=sw;
    ans%=1000000000;

    for(vector<pair<int,int> >::iterator it=g[v].begin(); it<g[v].end(); ++it){
        to=it->first;
        w=it->second;
        if(to==p) continue;
        dfs(to,v,num+1,sw+w*(num+1),num_,sw_);

        sw+=sw_+w*(num_+1);
        sw%=1000000000;
        num+=num_+1;
    }
    _sw=sw-_sw;
    while(_sw<0)
        _sw+=1000000000;
    _sw%=1000000000;
    _num=num-_num;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n);
    g.assign(n+1,vector<pair<int, int> >());
    used.assign(n+1,0);
    m.assign(n+1,vector<int>());
    for(int i=0;i<=n;++i)
        m[i].assign(n+1,0);

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
        scanf("%d",&m[i][j]);

    ll _sw,_num;
    dfs(1,1,0,0,_sw,_num);

    printf("%d\n",ans);

}
