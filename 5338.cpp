#include <iostream>
#include <fstream>
#include <queue>
#define MAX 1000

using namespace std;

int n;

int used[MAX];
int dist[MAX];
int a[MAX][MAX];
queue<int> line;

int bfs(int start, int finish){
    int from,to;

    for(int i=0; i<n; i++){
        used[i]=0;
    }

    dist[start]=0;
    used[start]=1;
    line.push(start);

    while(!line.empty()){
        from=line.front();

        if(from==finish) return dist[from];

        for(to=0; to<n; to++){
            if(a[from][to]==1 && used[to]==0){
                used[to]=1;
                dist[to]=dist[from]+1;
                line.push(to);
            }
        }

        line.pop();
    }

    return -1;

}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int v1, v2;

    fin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>a[i][j];
        }
    }

    fin>>v1>>v2;
    v1--;
    v2--;

    fout<<bfs(v1,v2)<<endl;

    fin.close();
    fout.close();
}
