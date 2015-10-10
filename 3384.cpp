#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 100001

typedef long long ll;

using namespace std;
int n, b;
ll scores=0;
int c[MAX],l[MAX];
vector<vector<int> > g;

//int lvl=-1;
vector<int>* dfs(int v){
    //++lvl;
    //for(int i=0;i<lvl;++i) printf("   "); printf("v: %d\n",v);
    ll sc=0;
    int n=0;
    vector<int>* res, *s=new vector<int>(), *tmp;
    s->push_back(c[v]);

    for(vector<int>::iterator to = g[v].begin(); to<g[v].end(); ++to){
        res=dfs(*to);
        /**for(int i=0;i<lvl;++i) printf("   "); printf("s: "); for(vector<int>::iterator it = s->begin(); it<s->end(); ++it) printf("%d ",*it); printf("\n");
        for(int i=0;i<lvl;++i) printf("   "); printf("res: "); for(vector<int>::iterator it = res->begin(); it<res->end(); ++it) printf("%d ",*it); printf("\n");
        /*printf("fine\n;");*/

        tmp=new vector<int>(s->size()+res->size());
        if(s->size()>res->size())
            merge(s->begin(), s->end(), res->begin(), res->end(), tmp->begin());
        else
            merge(res->begin(), res->end(), s->begin(), s->end(), tmp->begin());
        swap(s,tmp);
        delete tmp; delete res;
        tmp=NULL; res=NULL;

    }

    sc=(*s)[0];
    vector<int>::iterator it =s->begin();
    for(; it<s->end() && sc<=b; ++it,sc+=*it){
        ++n;
    }

    s->resize(it-s->begin());

    sc=((ll)n) * ((ll)l[v]);
    //for(int i=0;i<lvl;++i) printf("   "); printf("sc: %d\n",sc);
    if(sc>scores) scores =sc;

    //for(int i=0;i<lvl;++i) printf("   "); printf("s_end: "); for(vector<int>::iterator it = s->begin(); it<s->end(); ++it) printf("%d ",*it); printf("\n");

    //--lvl;
    return s;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int p;
    scanf("%d %d",&n,&b);
    g.assign(n+1, vector<int>());
    for(int i=1; i<=n; ++i){
        scanf("%d %d %d",&p,c+i,l+i);
        g[p].push_back(i);
    }
    //for(int i=1; i<=n; ++i) printf("%d ",c[i]); printf("\n");
    dfs(1);

    printf("%lld\n",scores);

}
