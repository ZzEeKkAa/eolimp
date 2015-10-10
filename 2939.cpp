#include <stdio.h>
#include <cmath>
#include <algorithm>

#define INF 1000000000
#define MAX2 524288

int n,p;
int s[2*MAX2];
int b[2*MAX2];

using namespace std;

void Build(){
    for(int i=p+n; i<p<<1; ++i) b[i]=0;
    for(int i=p-1; i>0; --i)
        b[i]=b[2*i]+b[2*i+1];
    for(int i=0; i<p<<1; ++i) s[i]=INF;
}

void Push(int v, int len){
    if(s[v]!=INF){
        len=len>>1;
        s[2*v]=s[2*v+1]=s[v];
        b[2*v]=b[2*v+1]=len*s[v];
        s[v]=INF;
    }
}

int GetSum(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    Push(v,rr-ll+1);
    return GetSum(v*2,ll,m,l,r)+GetSum(v*2+1,m+1,rr,l,r);
}

void Set(int v, int ll, int rr, int l, int r, int val){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) {
        b[v]=(rr-ll+1)*val;
        s[v]=val;
        return;
    }
    if(l>r) return;
    int m=(ll+rr)/2;
    Push(v,rr-ll+1);
    Set(v*2,ll,m,l,r,val);
    Set(v*2+1,m+1,rr,l,r,val);
    b[v]=b[2*v]+b[2*v+1];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int k,x,y,v;
    char c;
    scanf("%d %d",&n,&k);
    p=1; for(; p<n; p*=2);
    for(int i=1; i<=n; ++i){
        scanf("%d",b+p+i-1);
    }
    Build();

    for(int i=0; i<k; ++i){
        scanf("%c",&c);
        if(c=='='){
            scanf("%d %d %d",&x,&y,&v);
            Set(1,1,p,x,y,v);
            //for(int i=1; i<p<<1; ++i) printf("%d ",b[i]); printf("\n");
        }
        else
        if(c=='?'){
            scanf("%d %d",&x,&y);
            printf("%d\n",GetSum(1,1,p,x,y));
        } else --i;
    }
}


