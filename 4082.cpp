#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX 100001
#define MAX2 131072

int n,p;
int a[2*MAX2];

using namespace std;

int GetMult(int v, int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return 1;
    if(l==ll && r==rr) return a[v];
    int mm=(ll+rr)/2;
    return GetMult(2*v,ll,mm,l,r)*GetMult(2*v+1,mm+1,rr,l,r);
}

void Set(int i, int v){
    if(v>0) v=1;
    else if(v<0) v=-1;
    else v=0;
    a[p+i-1]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        a[pr]=a[pr*2]*a[pr*2+1];
        pr/=2;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    int x,y;
    char c;
    while(scanf("%d %d",&n,&k)==2){
        p=1;for(;p<n;p*=2);
        for(int i=0; i<n; ++i) {
            scanf("%d",&x);
            if(x>0)
                a[i+p]=1;
            else if(x<0)
                a[i+p]=-1;
            else
                a[i+p]=0;
        }
        for(int i=p+n; i<2*p; ++i) a[i]=1;
        for(int i=p-1; i>0; --i) a[i]=a[2*i]*a[2*i+1];

        for(int i=0; i<k; ++i){
            scanf("%c",&c);
            if(c=='C'||c=='P'){
                scanf("%d %d",&x,&y);
                if(c=='C')
                    Set(x,y);
                else{
                    x=GetMult(1,1,p,x,y);
                    if(x>0) printf("+");
                    else if(x<0) printf("-");
                    else printf("0");
                }
            }else --i;
        }
        printf("\n");
    }

    return 0;
}
