#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX2 1048576
#define INF 100000010

int n;
int p;
int a[MAX2+1];
int b[2*MAX2];

using namespace std;

void Build(){
    a[0]=INF;
    p=1; for(; p<n; p*=2);
    for(int i=0; i<p; ++i)
        b[p+i]=i+1;
    for(int i=n+1; i<=p; ++i) a[i]=INF;
    for(int i=p-1; i>0; --i)
        if(a[b[2*i]]<a[b[2*i+1]])
            b[i]=b[2*i];
        else
            b[i]=b[2*i+1];
}

int GetMin(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    int u1=GetMin(v*2,ll,m,l,r), u2=GetMin(v*2+1,m+1,rr,l,r);
    if(a[u1]<a[u2]) return u1; return u2;
}

int GetMinSum(int l, int r){
    int v = GetMin(1,1,p,l,r);
    int u1 = GetMin(1,1,p,l,v-1);
    int u2 = GetMin(1,1,p,v+1,r);
    int u;
    if(a[u1]<a[u2]) u=u1; else u=u2;
    return a[v]+a[u];
}

int Set(int i, int v){
    a[i]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        if(a[b[2*pr]]<a[b[2*pr+1]])
            b[pr]=b[2*pr];
        else
            b[pr]=b[2*pr+1];
        pr/=2;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int q;
    scanf("%d %d",&n,&q);



    for(int i=1; i<=n; ++i){
        scanf("%d",a+i);
    }
    Build();

    int k,x,y;
    char c;
    scanf("%d",&k);

    for(int i=0; i<k; ++i){
        scanf("%c",&c);
        if(c=='2'){
            scanf("%d %d",&x,&y);
            Set(x,y);
        }
        else
        if(c=='1'){
            scanf("%d %d",&x,&y);
            if(GetMinSum(x,y)<=q)
                printf("Yes\n");
            else
                printf("No\n");
        } else --i;
    }
}

