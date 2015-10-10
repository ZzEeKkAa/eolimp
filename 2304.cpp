#include <stdio.h>

#define MAX 131072

using namespace std;

typedef long long ll;

int n,p;
struct Node{
    ll sum, add;
} a[MAX*2];

int Push(int v, ll len){
    len=len>>1;
    if(a[v].add){
        a[v*2].add+=a[v].add;
        a[v*2+1].add+=a[v].add;
        a[v*2].sum+=len*a[v].add;
        a[v*2+1].sum+=len*a[v].add;
        a[v].add=0;
    }
}

void Add(int v, int ll, int rr, int l, int r, long long val){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return;
    if(ll==l && rr==r) {
        a[v].sum+=((long long)(rr-ll+1))*val;
        a[v].add+=val;
        return;
    }
    Push(v,rr-ll+1);
    int mm=(ll+rr)/2;
    Add(v*2,ll,mm,l,r,val);
    Add(v*2+1,mm+1,rr,l,r,val);
    a[v].sum=a[v*2].sum+a[v*2+1].sum;
}

ll GetSum(int v, int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return 0;
    if(ll==l && rr==r) return a[v].sum;
    Push(v,rr-ll+1);
    int mm=(ll+rr)/2;
    return GetSum(v*2,ll,mm,l,r)+GetSum(v*2+1,mm+1,rr,l,r);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tests;
    scanf("%d",&tests);
    for(int test=0; test<tests; ++test){
        int c;
        scanf("%d %d",&n,&c);
        p=1; for(; p<n; p*=2);
        for(int i=1; i<p<<1;++i)
            a[i].sum=a[i].add=0;

        int t,l,r,v;
        for(int i=0; i<c; ++i){
            scanf("%d",&t);
            if(t==0){
                scanf("%d %d %d",&l,&r,&v);
                Add(1,1,p,l,r,v);
            } else{
                scanf("%d %d",&l, &r);
                printf("%lld\n",GetSum(1,1,p,l,r));
            }
        }
    }
    return 0;
}
