#include <fstream>
#include <vector>
#include <set>

using namespace std;

multiset<long long> q;

int main(){
   ifstream fin("input.txt");
   ofstream fout("output.txt");

   int n, k;
   long long tmp, t;
   fin>>n>>k;

   for(int i=0; i<n; ++i){
       fin>>tmp;

       if(q.size()==k){
           t=*q.begin(); q.erase(q.begin());
           q.insert(t+tmp);
       } else q.insert(tmp);
   }

   while(q.size()>1) q.erase(q.begin());

   fout<<*q.begin()<<endl;

   fin.close();
   fout.close();

   return 0;
}
