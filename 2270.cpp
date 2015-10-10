#include <fstream>
#include <vector>
#include <stack>
#define MAX 100000

using namespace std;

vector<int> a[MAX+1];
int used[MAX+1];

int first;

vector<int> cycle;

int dfs(int v){
   used[v]=1;
   cycle.push_back(v);
   for(vector<int>::iterator it=a[v].begin(); it<a[v].end(); it++) {
       if(used[*it]==1) { first=*it; return 1;}
       else {
           if(dfs(*it)==1) return 1;
       }
   }

   cycle.pop_back();
   used[v]=2;
   return 0;
}

int main(){
   int n,m;
   int v1,v2;
   bool isCycle=false;

   ifstream fin("input.txt");
   ofstream fout("output.txt");
   fin>>n>>m;

   for(int i=0; i<m; ++i){
       fin>>v1>>v2;
       a[v1].push_back(v2);
   }

   for(int i=0; i<n; ++i){
       used[i]=0;
   }

   for(int i=1; i<=n; ++i){
       if(used[i]==0){
           if(dfs(i)==1) {
               isCycle=true;
               break;
           }
       }
   }

   if(isCycle ){
       fout<<"YES"<<endl;
       int i=0;
       while(cycle[i]!=first) ++i;
       fout<<cycle[i]; ++i;
       for(; i<cycle.size(); ++i) fout<<" "<<cycle[i]; fout<<endl;
   } else fout<<"NO"<<endl;

   fin.close();
   fout.close();

}
