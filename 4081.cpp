#include <stdio.h>
#include <cmath>
#include <algorithm>

#define MAX 500001
#define LOGMAX 19

using namespace std;

int a[MAX], f[MAX], m[MAX][LOGMAX];
double lg[MAX];

int n,q;

void build(){
    for(int i=1; i<=n; ++i){
        m[i][0]=a[i];
    }

    for(int j=1,p=2; p<=n; ++j,p*=2){
        for(int i=1; i<=n-p+1; ++i){
            m[i][j]=max(m[i][j-1],m[i+p/2][j-1]);
        }
    }
}

int rmq(int l, int r){
    if(l>r) return -1; //swap(l,r);
    //int length=r-l+1;
    int st=lg[r-l+1]/lg[2];
    int p=1<<st;
    //for(;p<=length;++st,p*=2); --st,p/=2;

    return(max(m[l][st],m[r-p+1][st]));
}

int num(int l, int r){
    if(l>r) swap(l,r);
    int first_one = min(f[l],r+1);
    return max(first_one-l, rmq(first_one,r));
}



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int l,r;
    do{
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&q);

        int pr=500009,tmp;
        int from=1;

        for(int i=1; i<=n; ++i){
            scanf("%d",&tmp);
            if(tmp==pr){
                a[i]=a[i-1]+1;
            } else{
                a[i]=1;
                pr=tmp;
                for(int j=from; j<=i; ++j) f[j]=i;
                from=i+1;
            }
        }
        for(int j=from; j<=n; ++j) f[j]=n+1;

        /*for(int i=1; i<=n; ++i) printf("%d ",i); printf("\n");
        for(int i=1; i<=n; ++i) printf("%d ",a[i]); printf("\n");
        for(int i=1; i<=n; ++i) printf("%d ",f[i]); printf("\n");/**/

        build();
        for(int i=1; i<=n; ++i) lg[i]=log(i+0.0);
        for(int i=0; i<q; ++i){
            scanf("%d %d",&l,&r);
            printf("%d\n",num(l,r));
        }
    }while(true);

    return 0;
}
