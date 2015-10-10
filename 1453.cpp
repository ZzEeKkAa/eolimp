#include <fstream>

#define INF 30000
#define MAXN 101
#define MAXM 10000

using namespace std;

struct Edge{
    int u,v,dist;
};

int n,m;

int dist[MAXN];
Edge e[MAXM];

void Bellman_Ford(int s){
    Edge tmp;
    int change=1;

    for(int i=1; i<=n; i++) dist[i]=INF;
    dist[s]=0;

    while(change){
        change=0;

        for(int j=0; j<m; j++) {
            tmp=e[j];

            if(dist[tmp.u]==INF) continue;

            if(dist[tmp.v]>dist[tmp.u]+tmp.dist){
                dist[tmp.v]=dist[tmp.u]+tmp.dist;
                change=1;
            }
        }
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n>>m;

    for(int i=0; i<m; i++){
        fin>>e[i].u>>e[i].v>>e[i].dist;
    }

    Bellman_Ford(1);

    fout<<dist[1];
    for(int i=2; i<=n; i++){
        fout<<" "<<dist[i];
    }
    fout<<endl;

    fin.close();
    fout.close();
}
