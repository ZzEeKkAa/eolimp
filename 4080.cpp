#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX 20001
#define MAX2 32768

int n,p,st;
int a[2*MAX2];

using namespace std;

void Build(){
    for(int i=p+n; i<p<<1; ++i) a[i]=2147483647;
    for(int i=p-1; i>0; --i) a[i]=a[i*2]&a[i*2+1];
    //for(int i=1; i<2*p; ++i) printf("%d ",a[i]);printf("\n");
}

int GetAnd(int v,int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return 2147483647;
    if(l==ll && r==rr) return a[v];
    int mm = (ll+rr)/2;
    return GetAnd(v*2,ll,mm,l,r)&GetAnd(v*2+1,mm+1,rr,l,r);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,k;
    int ans;
    scanf("%d",&t);
    for(int i=0; i<t; ++i){
        scanf("%d %d",&n,&k);
        p=1; for(; p<n; p*=2);
        for(int i=0; i<n; ++i)
            scanf("%d",a+p+i);
        Build();
        if(k>=n/2){
            //printf("easy\n");
            ans=a[p];
            for(int i=p+1; i<p+n; ++i)
                ans&=a[i];
            for(int i=1;i<n;++i) printf("%d ",ans); printf("%d\n",ans);
        }
        else{
            //printf("hard\n");
            for(int i=1;i<=n;++i){
                //printf("%d: ",i);
                if(i-k<1){
                    //printf("l");
                    ans=GetAnd(1,1,p,1,i+k);
                    ans&=GetAnd(1,1,p,n+i-k,n);
                } else if(i+k>n){
                    //printf("r");
                    ans=GetAnd(1,1,p,i-k,n);
                    ans&=GetAnd(1,1,p,1,k+i-n);
                } else ans=GetAnd(1,1,p,i-k,i+k);//,printf("n");
                if(i==n) printf("%d\n",ans);
                else printf("%d ",ans);
            }
        }
    }
    return 0;
}
