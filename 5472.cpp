#include "stdio.h"
#include "math.h"
#include "algorithm"

#define INF 4294967295

using namespace std;

int n,m,p;
unsigned int a,b;

unsigned int arr[65540];

unsigned int help[25001][16];

void build(){
    int pp;

    for(int j=1,p=2; p<=n; ++j,p*=2){
        pp=p>>1;
        for(int i=1; i<=n-p+1; ++i){
            help[i][j]=min(help[i][j-1], help[i+pp][j-1]);
        }
    }/**/
}

unsigned int rmq(int l, int r){
    if(l>r) swap(l,r);
    int length = r-l+1;
    int st=0,p=1;

    for(; p<=length; ++st,p=p<<1); --st; p=p>>1;

    return(min(help[l][st],help[r-p+1][st]));
}

void build(unsigned int a, unsigned int b){
    p=1;
    for(; p<n; p*=2);

    arr[p]=a+b;
    for(int i=1; i<n; ++i)
        arr[p+i]=arr[p+i-1]+a;

    for(int i=n; i<p; ++i)
        arr[p+i]=INF;

    for(int i=p-1; i>0; --i)
        arr[i]=min(arr[i*2],arr[i*2+1]);
}

unsigned int rmq(int v, int ll, int rr, int l, int r){
    if(ll>l) l=ll;
    if(rr<r) r=rr;
    if(l>r) return INF;
    if(ll==l && rr==r) return arr[v];
    int m = (ll+rr)/2;
    return min(rmq(v*2, ll, m, l, r), rmq(v*2+1,m+1, rr, l,r));
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    unsigned int l,r;
    int nl, nr;
    long long ans=0;

    scanf("%d %d %u %u",&n,&m,&a,&b);
    do{
        ans=0;

        if(n>m){
            build(a,b);

            r=arr[p+n-1];
            for(int i=0; i<m; ++i){
               l=r+a;
               r=l+a;
               nl=l%n+1;
               nr=r%n+1;
               if(nl>nr) swap(nl,nr);
               ans+=rmq(1, 1, p,nl, nr);
            }
        } else {
            help[1][0]=a+b;
            for(int i=1; i<n; ++i){
                help[i+1][0]=help[i][0]+a;
            }

            build();
            r=help[n][0];
            for(int i=0; i<m; ++i){
               l=r+a;
               r=l+a;
               ans+=rmq(l%n+1, r%n+1);
            }
        }

        printf("%lld\n",ans);

        scanf("%d %d %u %u",&n,&m,&a,&b);
    }while(n!=0 || m!=0 || a!=0 || b!=0);

    return 0;
}

