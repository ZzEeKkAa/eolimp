#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<vector<int> > b;

int getMin(int u, int v){
    if(u>v) swap(u,v);
    int l=v-u+1;
    int i,p=1;
    for(i=0; p<=l; ++i){p*=2;}
    p/=2; --i;

    return min(b[u][i], b[v-p+1][i]);
}


int main(){
    int u,v,m;
    scanf("%d %d",&n,&m);
    a.assign(n+1,0);
    scanf("%d",&a[1]);
    scanf("%d %d",&u,&v);

    for(int i=1; i<n; ++i){
        a[i+1]=(23*a[i]+21563)%16714589;
    }

    int l = log2(n)+1;
    vector<int> e;
    e.assign(l+1,0);
    b.assign(n+1, e);


    // preprocessing
    for(int i=1; i<=n;++i){
        b[i][0]=a[i];
    }
    for(int j=0,p=1; p<=n; ++j,p*=2){
        for(int i=1; i<=n-p; ++i){
            b[i][j+1]=min(b[i][j],b[i+p][j]);
        }
    }

    int ans;
    int nv=v,nu=u;
    int i=1;
    do{
        u=nu;v=nv;
        ans=getMin(u,v);
        nu = ((17*u + 751 + ans + 2*i) % n) +1;
        nv = ((13*v + 593 + ans + 5*i) % n) +1;
        ++i;
    }while(i<=m);

    printf("%d %d %d\n",u,v,ans);
}
