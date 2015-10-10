#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX2 1048576
#define INF 100000010

int n;
int p=MAX2;
int a[MAX2+1];
int b[2*MAX2];

using namespace std;

void Build(){
    a[0]=-INF;
    /*p=1; for(; p<n; p*=2);*/
    for(int i=0; i<p; ++i)
        b[p+i]=i+1;
    /*for(int i=n+1; i<=p; ++i) a[i]=-INF;
    for(int i=p-1; i>0; --i)
        if(a[b[2*i]]>a[b[2*i+1]])
            b[i]=b[2*i];
        else
            b[i]=b[2*i+1];*/
}

/*int GetMax(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    int u1=GetMax(v*2,ll,m,l,r), u2=GetMax(v*2+1,m+1,rr,l,r);
    if(a[u1]>=a[u2]) return u1; return u2;
}*/

int Set(int i, int v){
    a[i]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        if(a[b[2*pr]]>=a[b[2*pr+1]])
            b[pr]=b[2*pr];
        else
            b[pr]=b[2*pr+1];
        pr/=2;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Build();

    int k,x,y;
    char c;
    scanf("%d",&k);

    for(int i=0; i<k; ++i){
        scanf("%c",&c);
        if(c=='+' || c=='-'){
            scanf("%d",&x);
            if(c=='+')
                Set(x,a[x]+1);
            else
                Set(x,a[x]-1);
            if(a[b[1]]==0) printf("0\n");
            else printf("%d\n",b[1]);
        } else --i;
    }
}

