#include <stdio.h>
#include <math.h>
#include <algorithm>

#define MAX 100010
#define LOGMAX 17

using namespace std;

int n,q;
int a[MAX][LOGMAX];

void build(){
    int st=1,p=2;
    for(;p<=n; ++st,p*=2){
        for(int i=1; i<=n-p+1; ++i){
            a[i][st]=min(a[i][st-1],a[i+p/2][st-1]);
        }
    }
}

int rmq(int l, int r){
    if(l>r) swap(l,r);
    int length = r-l+1;
    int st=0,p=1;
    for(;p<=length; ++st,p*=2); --st; p/=2;
    return min(a[l][st],a[r-p+1][st]);
}

int main(){
    int tmp,l,r;
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; ++i){
        scanf("%d",&tmp);
        a[tmp][0]=i;
    }
    build();
    for(int i=0; i<q; ++i){
        scanf("%d %d",&l,&r);
        printf("%d\n",rmq(l,r));
    }
    return 0;
}
