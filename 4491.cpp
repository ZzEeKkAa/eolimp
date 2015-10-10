#include <stdio.h>
using namespace std;
typedef long long ll;

ll get_pairs(ll len){
    return (len*(len+1))>>1;
}

int main(){
    int n,k;
    int t,m_pos=0,pr_pos=0;
    ll ans=0;

    scanf("%d %d",&n,&k);

    for(int i=1; i<=n; ++i){
        scanf("%d",&t);
        if(t==k){
            ans-=get_pairs(i-pr_pos-1);
            pr_pos=i;
        } else
        if(t>k){
            if(pr_pos!=m_pos){
                ans-=get_pairs(i-pr_pos-1);
                ans+=get_pairs(i-m_pos-1);
            }
            pr_pos=i;
            m_pos=i;
        }
    }
    ans-=get_pairs(n+1-pr_pos-1);
    ans+=get_pairs(n+1-m_pos-1);

    printf("%lld\n",ans);
    return 0;
}
