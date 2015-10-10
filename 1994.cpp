#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>

#define MAX 131072
#define INF 100000010

int n,p;
struct Node{
    int add;
    int m;
} a[2*MAX];

char ch[MAX];

using namespace std;

void Build(){
    for(int i=p+n; i<p<<1; ++i){
        a[i].add=0;
        a[i].m=INF;
    }

    for(int i=p-1; i>0; --i){
        a[i].m=min(a[i<<1].m, a[(i<<1)+1].m);
        a[i].add=0;
    }
}

void Push(int v){
    a[v*2].add+=a[v].add;
    a[v*2].m+=a[v].add;
    a[v*2+1].add+=a[v].add;
    a[v*2+1].m+=a[v].add;
    a[v].add=0;
}

void Add(int v, int ll, int rr, int l, int r, int val){
    //printf("   %d %d\n",ll,rr);
    if(l<ll) l=ll;
    if(rr<r) r=rr;
    if(l>r) return;
    if(ll==l && rr==r){
        a[v].add+=val;
        a[v].m+=val;
        return;
    }
    if(a[v].add)
        Push(v);
    int mm=(ll+rr)/2;
    Add(v*2,ll,mm,l,r,val);
    Add(v*2+1,mm+1,rr,l,r,val);
    //printf("  %d %d\n",ll,rr);
    a[v].m=min(a[v*2].m,a[v*2+1].m);
}


int main(){
    int last=0;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%s",ch);

    n = strlen(ch);
    //printf("%d\n",n);
    p=1; for(;p<n;p*=2); a[p-1].m=0;
    for(int i=0; i<n; ++i){
        if(ch[i]=='('){
            a[p+i].m=a[p+i-1].m+1;
        } else if(ch[i]==')'){
            a[p+i].m=a[p+i-1].m-1;
        } else{
            a[p+i].m=a[p+i-1].m;
        }
        a[p+i].add=0;
    }
    Build();
    last=a[p+n-1].m;

    //printf("%d\n",p);
    //for(int i=1; i<(p<<1); ++i) printf("%d ",a[i].m); printf("\n");

    int k,t;
    scanf("%d",&k);
    for(int i=0; i<k; ++i){
        scanf("%d",&t);
        if(ch[t]=='('){
            ch[t]=')';
            Add(1,1,p,t+1,n,-2);
            last-=2;
        } else {
            ch[t]='(';
            Add(1,1,p,t+1,n,2);
            last+=2;
        }
        //printf("%s\n",ch);
        //for(int i=1; i<(p<<1); ++i) printf("%d ",a[i].m); printf("\n");
        if(a[1].m>=0 && last==0) printf("+\n");
        else printf("-\n");
    }
}
