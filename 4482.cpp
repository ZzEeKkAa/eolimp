#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX2 131072

int n,p;
int b[2*MAX2];

using namespace std;

int nod(int a, int b){
    if(a==0 || b==0) return a+b;
    if(a>b) return nod(a%b,b);
    return nod(a,b%a);
}

void Build(){
    for(int i=p+n; i<p<<1; ++i) b[i]=0;
    for(int i=p-1; i>0; --i)
        b[i]=nod(b[2*i],b[2*i+1]);
}

bool wins;
int GetNod(int v, int ll, int rr, int l, int r){
    if(l<ll) l = ll;
    if(rr<r) r = rr;
    if(ll==l && rr==r) return b[v];
    if(l>r) return 0;
    int m=(ll+rr)/2;
    int n1=GetNod(v*2,ll,m,l,r), n2=GetNod(v*2+1,m+1,rr,l,r);
    int n3=nod(n1,n2);
    if(n3<n1 || n3<n2) wins=true;
    return n3;
}

int Win(int v, int ll, int rr, int l, int r){
    wins=false;
    GetNod(v,ll,rr,l,r);
    return wins;
}


int Set(int i, int v){
    b[p+i-1]=v;
    int pr=(p+i-1)/2;
    while(pr!=0){
        b[pr]=nod(b[2*pr],b[2*pr+1]);
        pr/=2;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int k,x,y;
    char c;
    scanf("%d",&n);
    p=1; for(; p<n; p*=2);
    for(int i=0; i<n; ++i){
        scanf("%d",b+p+i);
    }
    Build();



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
            //printf("%d %d ",GetNod(1,1,p,x,y),GetNok(1,1,p,x,y));
            if(Win(1,1,p,x,y))
                printf("wins\n");
            else
                printf("draw\n");
        } else --i;
    }
}
