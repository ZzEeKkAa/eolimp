#include <stdio.h>

#define MAX 131072

using namespace std;

int n,p;
struct Node{
    int sum,ch;
} a[MAX*2];

int Push(int v, int len){
    len=len>>1;
    if(a[v].ch){
        a[v*2].ch+=1;
        a[v*2].ch%=2;
        a[v*2+1].ch+=1;
        a[v*2+1].ch%=2;

        a[v*2].sum=len-a[v*2].sum;
        a[v*2+1].sum=len-a[v*2+1].sum;
        a[v].ch=0;
    }
}

void Change(int v, int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return;
    if(ll==l && rr==r) {
        a[v].sum=rr-ll+1-a[v].sum;
        a[v].ch+=1;
        a[v].ch%=2;
        return;
    }
    Push(v,rr-ll+1);
    int mm=(ll+rr)/2;
    Change(v*2,ll,mm,l,r);
    Change(v*2+1,mm+1,rr,l,r);
    a[v].sum=a[v*2].sum+a[v*2+1].sum;
}

int GetSum(int v, int ll, int rr, int l, int r){
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
    int c;
    scanf("%d %d",&n,&c);
    p=1; for(; p<n; p*=2);
    for(int i=1; i<p<<1;++i)
        a[i].sum=a[i].ch=0;

    int t,l,r;
    for(int i=0; i<c; ++i){
        scanf("%d %d %d",&t,&l,&r);
        if(t==0)
            Change(1,1,p,l,r);
        else
            printf("%d\n",GetSum(1,1,p,l,r));
    }
    return 0;
}
