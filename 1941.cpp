#include <stdio.h>
#include <vector>

#define MAX 100001

using namespace std;

vector<int> a[MAX];
vector<int> ans;
int d[MAX];
int f[MAX];
int t=0;

int dfs(int v){
   d[v]=++t;

   for(vector<int>::iterator it=a[v].begin(); it<a[v].end(); it++){
       dfs(*it);
   }

   f[v]=++t;
}

int main(){
 int n,m,vp,vc;
 freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

 scanf("%d",&n);
 for(vc=1; vc<=n; vc++){
     scanf("%d",&vp);
     a[vp].push_back(vc);
 }
 dfs(0);

 scanf("%d",&m);
 for(int i=0; i<m; i++){
     scanf("%d %d",&vp,&vc);
     if(d[vp]<d[vc] && f[vc]<f[vp]) ans.push_back(1); else ans.push_back(0);
 }

 for(vector<int>::iterator it=ans.begin(); it<ans.end(); ++it){
    printf("%d\n",*it);
 }

 return 0;
}
