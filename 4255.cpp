#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

int n;
vector<ll> t,a;

void init(int nn){
    n=nn;
    t.assign(n,0);
    a.assign(n,0);
    //for(int i=0; i<n; ++i) t[i]=0;
}

ll sum(int i){
    ll res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

void add(int i, int d){
    for(;i<n;i=(i|(i+1)))
        t[i]+=d;
}

ll sum(int l, int r){
    return sum(r)-sum(l-1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    scanf("%d %d",&n,&k);

    init(n);

    char c;
    int l, r, d;
    for(int i=0; i<k && scanf("%c",&c)==1; ++i){
        if(c=='A'){
            scanf("%d %d",&l,&r); --l;
            add(l,r-a[l]);
            a[l]=r;
        }else if(c=='Q'){
            scanf("%d %d",&l,&r);
            printf("%lld\n",sum(l-1,r-1));
        }else --i;
    }

}

