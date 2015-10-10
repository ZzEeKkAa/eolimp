#include <iostream>
#include <fstream>
#include <queue>

#define MAX 1000

using namespace std;

int parent[MAX];
int dist[MAX];
int used[MAX];
queue<int> line;
int a[MAX][MAX];

int n;

int bfs(){
    int from;

    while(!line.empty()){
        from = line.front();

        // Calculating
        for(int to=0; to<n; to++){
            if(a[from][to]==1 && used[to]==0){
                dist[to]=dist[from]+1;
                parent[to]=from;
                used[to]=1;
                line.push(to);
            }
        }

        line.pop();
    }

}

int main(){
    int x;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n>>x;
    x--;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>a[i][j];
        }
        used[i]=0;
        dist[i]=-1;
    }

    dist[x]=0;
    used[x]=1;
    parent[x]=-1;
    line.push(x);

    bfs();

    fout<<dist[0];
    for(int i=1; i<n; i++) fout<<" "<<dist[i];
    fout<<endl;

    fin.close();
    fout.close();
    return 0;
}
