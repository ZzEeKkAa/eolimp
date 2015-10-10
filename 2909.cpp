#include <stdio.h>

#define MAX 131072

using namespace std;

int n,p;
struct Node{
    int add,n[3];
} a[MAX*2];

void Build(){
    for(int i=p-1; i>0; --i){
        a[i].n[0]=a[2*i].n[0]+a[2*i+1].n[0];
    }
}

int tmp;
int Push(int v){
    if(a[v].add){
        a[v*2].add+=a[v].add;
        a[v*2].add%=3;
        a[v*2+1].add+=a[v].add;
        a[v*2+1].add%=3;

        tmp=a[v*2].n[0];
        a[v*2].n[0]             =a[v*2].n[(2*a[v].add)%3];
        a[v*2].n[(2*a[v].add)%3]=a[v*2].n[a[v].add];
        a[v*2].n[a[v].add]      =tmp;

        tmp=a[v*2+1].n[0];
        a[v*2+1].n[0]             =a[v*2+1].n[(2*a[v].add)%3];
        a[v*2+1].n[(2*a[v].add)%3]=a[v*2+1].n[a[v].add];
        a[v*2+1].n[a[v].add]      =tmp;

        a[v].add=0;
    }
}

void Add(int v, int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return;
    if(ll==l && rr==r) {
        tmp=a[v].n[0];
        a[v].n[0]=a[v].n[2];
        a[v].n[2]=a[v].n[1];
        a[v].n[1]=tmp;
        a[v].add+=1;
        a[v].add%=3;
        return;
    }
    Push(v);
    int mm=(ll+rr)/2;
    Add(v*2,ll,mm,l,r);
    Add(v*2+1,mm+1,rr,l,r);
    a[v].n[0]=a[v*2].n[0]+a[v*2+1].n[0];
    a[v].n[1]=a[v*2].n[1]+a[v*2+1].n[1];
    a[v].n[2]=a[v*2].n[2]+a[v*2+1].n[2];
}

int GetNum(int v, int ll, int rr, int l, int r){
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return 0;
    if(ll==l && rr==r) return a[v].n[0];
    Push(v);
    int mm=(ll+rr)/2;
    return GetNum(v*2,ll,mm,l,r)+GetNum(v*2+1,mm+1,rr,l,r);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int c;
    scanf("%d %d",&n,&c);
    p=1; for(; p<n; p*=2);
    for(int i=1; i<p<<1;++i)
        a[i].n[1]=a[i].n[2]=a[i].add=0,a[i].n[0]=1;
    Build();

    int t,l,r;
    for(int i=0; i<c; ++i){
        scanf("%d %d %d",&t,&l,&r);
        if(t==0)
            Add(1,1,p,l+1,r+1);
        else
            printf("%d\n",GetNum(1,1,p,l+1,r+1));
    }
    return 0;
}

