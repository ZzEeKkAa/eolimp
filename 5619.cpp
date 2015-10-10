#include <stdio.h>
#include <vector>

#define MAX 32001

using namespace std;

int n;
vector<int> t;
vector<int> lvl;

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

    int n;
    scanf("%d",&n);

    init(MAX);
    lvl.assign(n,0);

    char c;
    int x,y;
    for(int i=0; i<n; ++i){
        scanf("%d %d",&x,&y);
        ++lvl[sum(x)];
        add(x,1);
    }

    for(int i=0; i<n; ++i) printf("%d\n",lvl[i]);

}

