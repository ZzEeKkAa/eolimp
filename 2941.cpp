#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX  500010
#define MAX2 524288

int n,p;
//int a[MAX];
int b[2*MAX2];

using namespace std;

void Build(){

    /*for(int i=0; i<n; ++i)
        b[p+i]=a[i+1];*/
    for(int i=p+n; i<p<<1; ++i) b[i]=0;
    for(int i=p-1; i>0; --i)
        b[i]=b[2*i]+b[2*i+1];
}

int GetSum(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    return GetSum(v*2,ll,m,l,r)+GetSum(v*2+1,m+1,rr,l,r);
}

int Set(int i, int v){
    b[p+i-1]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        b[pr]=b[2*pr]+b[2*pr+1];
        pr/=2;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int k,x,y;
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
            scanf("%d %d",&x,&y);
            Set(x,y);
        }
        else
        if(c=='?'){
            scanf("%d %d",&x,&y);
            printf("%d\n",GetSum(1,1,p,x,y));
        } else --i;
    }
}

