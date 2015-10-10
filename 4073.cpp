#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<ll> t;

void init(int nn){
    n=nn;
    t.assign(n,0);
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


vector<int> a;
vector<int> pos;

bool comp(int i, int j){
    return a[i]<a[j];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n;

    scanf("%d",&t);

    ll res;
    vector<int> pr_pos;
    for(int i=0;i<t; ++i){
        scanf("%d",&n);
        init(n);
        a.assign(n,0);
        pos.assign(n,0);

        for(int i=0; i<n; ++i){
            scanf("%d",&a[i]);
            pos[i]=i;
        }
        sort(pos.begin(),pos.end(),comp);

        res=0;
        pr_pos.clear();
        for(int i=0; i<n; ++i){
            if(!pr_pos.empty() && a[pr_pos[0]]!=a[pos[i]]){
                for(int i=0; i<pr_pos.size(); ++i)
                add(pr_pos[i],a[pr_pos[i]]);
                pr_pos.clear();
            }
            pr_pos.push_back(pos[i]);
            res+=sum(pos[i]);
        }
        printf("%lld\n",res);
    }


}
