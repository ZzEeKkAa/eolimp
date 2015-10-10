#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n1;
vector<ll> t1;

void init1(int nn){
    n1=nn;
    t1.assign(n1,0);
}
ll sum1(int i){
    ll res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t1[i];
    return res;
}
void add1(int i, int d){
    for(;i<n1;i=(i|(i+1)))
        t1[i]+=d;
}

int n2;
vector<ll> t2;

void init2(int nn){
    n2=nn;
    t2.assign(n2,0);
    //for(int i=0; i<n; ++i) t[i]=0;
}
ll sum2(int i){
    ll res=0;
    for(; i>=0; i=(i&(i+1))-1)
        res+=t2[i];
    return res;
}
void add2(int i, ll d){
    for(;i<n2;i=(i|(i+1)))
        t2[i]+=d;
}

vector<int> a,pos;

bool comp(int i, int j){
    if(a[i]==a[j]) return i>j;
    return a[i]>a[j];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;

    scanf("%d",&n);
    init1(n);
    init2(n);
    a.assign(n,0);
    pos.assign(n,0);

    for(int i=0; i<n; ++i){
        scanf("%d",&a[i]);
        pos[i]=i;
    }

    sort(pos.begin(),pos.end(),comp);

    ll res=0;
    for(int i=0; i<n; ++i){
        res+=sum2(pos[i]);
        //printf("%d: %d\n",pos[i],sum2(pos[i]));
        add2(pos[i],sum1(pos[i]));
        add1(pos[i],1);
    }

    /*for(int i=0; i<n; ++i) printf("%lld ",sum1(i)-sum1(i-1)); printf("\n");
    for(int i=0; i<n; ++i) printf("%lld ",sum2(i)-sum2(i-1)); printf("\n");*/
    printf("%lld\n",res);

}

