#include <iostream>
#include <fstream>
#include <vector>

#define MAX 1000

using namespace std;

int n,m;
vector<vector<int> > a;
int used[MAX+1];

int dfs(int v, int p){
    used[v]=3-used[p];
    for(int i=0; i<a[v].size(); i++){
        if(used[a[v][i]]==used[v]) return 1;
        if(used[a[v][i]]==0)
            if(dfs(a[v][i],v)==1) return 1;
    }
    return 0;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int v1,v2;
    fin>>n;
    while(n!=0){
        for(int i=0; i<=n; i++){
            a.insert(a.end(),vector<int>());
            used[i]=0;
        }


        fin>>m;
        for(int i=0; i<m; i++){
            fin>>v1>>v2;
            a[v1].insert(a[v1].end(), v2);
            a[v2].insert(a[v2].end(), v1);
        }

        used[1]=1;
        if(dfs(1,1)==1)
            fout << "NOT BICOLOURABLE." << endl;
        else
            fout << "BICOLOURABLE." << endl;



        a.erase(a.begin(),a.end());
        fin>>n;
    }

}
