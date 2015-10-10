#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 1000000010
#define MAX 1000001

using namespace std;

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

vector<vector<pair<int,int> > > x,y;
int cl_r(int _x, int _y){
    int l,r,m;
    l=0; r=x[_y].size()-1;

    while(l<r){
        //printf("%d %d\n",l,r);
        m=(l+r)/2;
        if(x[_y][m].first>_x){
            r=m;
        } else l=m+1;
    }

    if(x[_y][l].first==_x) return -1;
    return x[_y][l].first;
}

int cl_l(int _x, int _y){
    int l,r,m;
    l=0; r=x[_y].size()-1;

    while(l<r){
        //printf("%d %d\n",l,r);
        m=(l+r)/2;
        if(x[_y][m].first<=_x){
            r=m;
        } else l=m+1;
    }

    if(x[_y][l].first==_x) return -1;
    return x[_y][l].first;
}

int cl_t(int _x, int _y){
    int t,d,m;
    t=0; d=y[_x].size()-1;

    while(t<d){
        //printf("%d %d\n",l,r);
        m=(t+d)/2;
        if(y[_x][m].first>=_y){
            d=m;
        } else t=m+1;
    }

    if(y[_x][t].first==_y) return -1;
    return y[_x][t].first;
}


int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int r, c, m, n;
    scanf("%d %d %d %d",&r,&c,&m,&n);

    x.assign(c,vector<pair<int, int> >());
    y.assign(r,vector<pair<int, int> >());

    int tx,ty;
    for(int i=0; i<m; ++i){
        scanf("%d %d",&ty,&tx); --tx; --ty;
        x[ty].push_back(make_pair(tx,1));
        y[tx].push_back(make_pair(ty,1));
    }
    for(int i=0; i<n; ++i){
        scanf("%d %d",&ty,&tx); --tx; --ty;
        x[ty].push_back(make_pair(tx,-1));
        y[tx].push_back(make_pair(ty,-1));
    }

    for(int i=0; i<c; ++i){
        if(!x[i].empty()) sort(x[i].begin(),x[i].end());
    }
    for(int i=0; i<r; ++i){
        if(!y[i].empty()) sort(y[i].begin(),y[i].end());
    }

    printf("%d\n",cl_t(1,0));
    printf("%d\n",cl_t(1,3));
    printf("%d\n",cl_t(2,3));
    printf("%d\n",cl_t(2,1));

}

