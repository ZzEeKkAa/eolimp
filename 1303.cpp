#include <stdio.h>
#include <algorithm>

#define MAX 500000

using namespace std;

int n;
int t[MAX];

void init(int _n){
    //n=_n;
    for(int i=0; i<n; ++i) t[i]=0;
}

int sum(int i){
    int res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

int add(int i, int d){
    for(; i<n; i=(i|(i+1)))
        t[i]+=d;
}
/*
int sum(int l, int r){
    return sum(r)-sum(l-1);
}*/


int a[MAX],na[MAX];

bool comp(int i, int j){
    return a[i]<a[j];
}

int main(){
    long long ans;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(int i=0; i<n; ++i) a[i]=0;
        for(int i=0; i<n; ++i) na[i]=0;

        for(int i=0; i<n; ++i) {
            scanf("%d",&a[i]);
            na[i]=i;
        }

        sort(na, na+n,comp);
        for(int i=0; i<n; ++i) a[na[i]]=i;


        init(n);

        ans=0;
        for(int i=n-1; i>=0; --i){
            ans+=sum(a[i]);
            add(a[i],1);
        }

        printf("%lld\n",ans);
    }


}
