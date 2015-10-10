#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX 100100
#define LOGMAX 20

using namespace std;

int m[MAX][LOGMAX];

int n,q;

void build(){
    for(int j=1,p=2; p<=n; ++j,p*=2){
        for(int i=1; i<=n-p+1; ++i){
            m[i][j]=max(m[i][j-1],m[i+p/2][j-1]);
        }
    }
}

int rmq(int l, int r){
    if(l>r) swap(l,r);
    int length=r-l+1;
    int st=0;
    int p=1;
    for(;p<=length;++st,p*=2); --st,p/=2;

    return(max(m[l][st],m[r-p+1][st]));
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",&m[i][0]);
    build();

    int l,r;
    scanf("%d",&q);
    for(int i=0; i<q; ++i){
        scanf("%d %d",&l,&r);
        printf("%d\n",rmq(l,r));
    }
    return 0;
}

