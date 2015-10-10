#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX2 1048576

typedef long long ll;

int n,p;
ll b[2*MAX2];

using namespace std;

void Build(){
    for(int i=p+n; i<p<<1; ++i) b[i]=0;
    for(int i=p-1; i>0; --i)
        b[i]=b[2*i]+b[2*i+1];
}

ll GetSum(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    return GetSum(v*2,ll,m,l,r)+GetSum(v*2+1,m+1,rr,l,r);
}

void Set(int i, int v){
    b[p+i-1]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        b[pr]=b[2*pr]+b[2*pr+1];
        pr/=2;
    }
}

int GetLen(ll weight){
    int l=1,r=n,m;
    while(l<r){
        m=(l+r+1)/2;
        if(weight>=GetSum(1,1,p,1,m))
            l=m;
        else
            r=m-1;
    }
    return l;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int k,x,y;
    scanf("%d",&n);
    p=1; for(; p<n; p*=2);
    for(int i=0; i<n; ++i){
        scanf("%lld",b+p+i);
    }
    Build();

    scanf("%d",&k);
    int t;
    for(int i=0; i<k; ++i){
        scanf("%d",&t);
        if(t==2){
            scanf("%d %d",&x,&y);
            Set(x,y);
        }
        else if(t==1){
            scanf("%d",&x);
            if(b[p]>(ll)x)
                printf("0\n");
            else
                printf("%d\n",GetLen(x));
        } else --i;
    }
}

