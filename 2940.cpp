#include <stdio.h>
#include <vector>

#define MAX 1000001

using namespace std;

int n;
vector<int> t;

void init(int nn){
    n=nn;
    t.assign(n,0);
    //for(int i=0; i<n; ++i) t[i]=0;
}

int sum(int i){
    int res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t[i];
    return res;
}

void add(int i, int d){
    for(;i<n;i=(i|(i+1)))
        t[i]+=d;
}

int sum(int l, int r){
    return sum(r)-sum(l-1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    scanf("%d %d",&n,&k);

    init(n);
    int t;
    for(int i=0; i<n; ++i) { scanf("%d", &t); add(i,t);}

    char c;
    int l, r, d;
    for(int i=0; i<k && scanf("%c",&c)==1; ++i){
        if(c=='+'){
            scanf("%d %d",&l,&d);
            add(l-1,d);
        }else if(c=='?'){
            scanf("%d %d",&l,&r);
            printf("%d\n",sum(l-1,r-1));
        }else --i;
    }

}

