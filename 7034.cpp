#include <iostream>
#include <fstream>
#include <vector>

#define MAXN 1000

using namespace std;

int n;
vector<vector<int> > a;
int p[MAXN];
int used[MAXN];
int kp[MAXN];
int kl=0;

int dfs(int v){
    used[v]=1;

    if(kp[kl]>p[v]) kp[kl]=p[v];

    for(int i=0; i<a[v].size(); i++){
        if(used[a[v][i]]==0){
            dfs(a[v][i]);
        }
    }

}

int main() {
    ofstream fout("output.txt");
    ifstream fin("input.txt");
    int m;
    int v1, v2;
    int sum=0;
    int lowestPrice=0;
    fin>>n>>m;
    for(int i=0; i<n; i++){
        fin>>p[i];
        a.insert(a.end(), vector<int>());
        used[i]=0;
    }
    for(int i=0; i<m; i++){
        fin>>v1>>v2;
        v1--;
        v2--;
        a[v1].insert(a[v1].end(), v2);
        a[v2].insert(a[v2].end(), v1);
    }

    // Calculating
    for(int i=0; i<n; i++){
        if(used[i]==0){
            kp[kl]=p[i];
            dfs(i);
            kl++;
        }
    }

    // Searching the least
    lowestPrice=kp[0];
    for(int i=0; i<kl; i++){
        sum+=kp[i];
        if(lowestPrice>kp[i]) lowestPrice=kp[i];
    }
    sum+=lowestPrice*(kl-2);

    fout<<sum<<endl;

    fin.close();
    fout.close();

}
