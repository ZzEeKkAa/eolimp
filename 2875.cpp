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
            scanf("%d %d %d",&l,&r,&d);
            add(l,d);
            add(r+1,-d);
        }else if(c=='Q'){
            scanf("%d",&d);
            printf("%d\n",sum(d));
        }else --i;
    }

}
