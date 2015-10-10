#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 1000000010

using namespace std;

vector<int> x,y;
vector<int> tmp;
vector<pair<int, int> > points;
vector<int> s,e;
vector<vector<int> > ss;
vector<vector<int> > es;
vector<int> sx,ex;

bool comp_x(int i, int j){
    return(x[i]<x[j]);
}
bool comp_y(int i, int j){
    return(y[i]<y[j]);
}


int n;
vector<int> t;

void init(int nn){
    n=nn;
    t.assign(n,0);
    //for(int i=0; i<n; ++i) t[i]=0;
}

int sum(int i){
    int res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

void add(int i, int d){
    for(;i<n;i=(i|(i+1)))
        t[i]+=d;
}

int sum(int l, int r){
    return sum(r)-sum(l-1);
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);

    int tx,ty;
    for(int i=0; i<n; ++i){
        scanf("%d %d",&tx,&ty);
        points.push_back(make_pair(x.size(),y.size()));
        x.push_back(tx);
        y.push_back(ty);
    }

    /*for(int i=0; i<x.size(); ++i) printf("%d ",x[i]); printf("\n");
    for(int i=0; i<y.size(); ++i) printf("%d ",y[i]); printf("\n");
    printf("\n");*/

    tmp.assign(x.size(),0);
    for(int i=0; i<tmp.size(); ++i) tmp[i]=i;
    sort(tmp.begin(), tmp.end(),comp_x);


    /*/for(int i=0; i<x.size(); ++i) printf("%d ",x[i]); printf("\n");
    for(int i=0; i<tmp.size(); ++i) printf("%d ",tmp[i]); printf("\n");
    for(int i=0; i<tmp.size(); ++i) printf("%d ",x[tmp[i]]); printf("\n");
    printf("\n");*/

    int pr = INF;
    int xs = -1;
    for(int i=0; i<tmp.size(); ++i){
        if(x[tmp[i]]!=pr){
            pr=x[tmp[i]];
            ++xs;
        }
        x[tmp[i]]=xs;
    }++xs;

    tmp.assign(y.size(),0);
    for(int i=0; i<tmp.size(); ++i) tmp[i]=i;
    sort(tmp.begin(), tmp.end(),comp_y);
    pr = INF;
    int ys = -1;
    for(int i=0; i<tmp.size(); ++i){
        if(y[tmp[i]]!=pr){
            pr=y[tmp[i]];
            ++ys;
        }
        y[tmp[i]]=ys;
    }++ys;

    /*for(int i=0; i<x.size(); ++i) printf("%d ",x[i]); printf("\n");
    for(int i=0; i<y.size(); ++i) printf("%d ",y[i]); printf("\n");*/

    s.assign(xs,INF);
    e.assign(xs,-INF);
    es.assign(ys,vector<int>());
    ss.assign(ys,vector<int>());
    sx.assign(ys,INF);
    ex.assign(ys,-INF);

    for(vector<pair<int, int> >::iterator point = points.begin(); point<points.end(); ++point){
        if(y[point->second]<s[x[point->first]]) s[x[point->first]]=y[point->second];
        if(y[point->second]>e[x[point->first]]) e[x[point->first]]=y[point->second];
        if(x[point->first]<sx[y[point->second]]) sx[y[point->second]]=x[point->first];
        if(x[point->first]>ex[y[point->second]]) ex[y[point->second]]=x[point->first];
    }

    for(int i=0; i<xs; ++i){
        if(e[i]!=-INF)
        es[e[i]].push_back(i);
        if(s[i]!=INF)
        ss[s[i]].push_back(i);
    }


    init(xs);

    int res=0;
    for(int i=0; i<ys; ++i){
        for(vector<int>::iterator it=ss[i].begin(); it<ss[i].end(); ++it){
            add(*it,1);
        }
        if(ex[i]!=-INF && sx[i]!=INF)

            res+=sum(sx[i],ex[i]);
            //printf("y = %d: (%d .. %d) %d\n",i,sx[i],ex[i],res);
        for(vector<int>::iterator it=es[i].begin(); it<es[i].end(); ++it){
            add(*it,-1);
        }
    }

    printf("%d\n",res);/**/


}
