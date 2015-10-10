#include <fstream>

#define MAX 1001

using namespace std;

int n;
int g[MAX][MAX];
int used[MAX];

int dfs(int v){
    used[v]=1;

    for(int i=0; i<n; ++i) if(!used[i] && g[v][i]){
        dfs(i);
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int comp=0;

    fin>>n;

    for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j){
        fin>>g[i][j];
    }

    for(int i=0; i<n; ++i){
        if(!used[i]){
            dfs(i);
            ++comp;
        }
    }

    fout<<comp<<endl;

    fin.close();
    fout.close();
}
