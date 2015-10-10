#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
#define MAX 51

using namespace std;

int n,d;
int num=0;
int used[MAX];
vector<vector<int> > g;

int dfs(int s, int f){
    static int day = 0;
    if(day>d) return 0;
    if(s==f){++num; return 0;}
    used[s]=1; ++day;

    for(vector<int>::iterator it = g[s].begin(); it<g[s].end(); it++){
        if(used[*it]!=1) dfs(*it,f);
    }

    used[s]=2; --day;
}
int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k,a,b,v1,v2;

    fin>>n>>k>>a>>b>>d;
    g.assign(n+1,vector<int>());
    memset(used,0,sizeof(used));
    for(int i=0; i<k; i++){
        fin>>v1>>v2;
        g[v1].push_back(v2);
    }

    dfs(a,b);

    fout<<num<<endl;

    fin.close();
    fout.close();
}
