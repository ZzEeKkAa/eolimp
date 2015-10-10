#include <fstream>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

struct Edge{
    int u,v,dist;
};

int n, m;
int vc;
vector<Edge> e;
vector<int> dist;

void Bellman_Ford(int s){
    Edge tmp;
    dist.assign(n,INF);
    dist[s]=0;

    for(int i=0; i<n; i++){
        vc=-1;
        for(vector<Edge>::iterator it = e.begin(); it<e.end(); it++){
            tmp=*it;
            if(dist[tmp.u]<INF){
                if(dist[tmp.u]+tmp.dist<dist[tmp.v]){
                    dist[tmp.v] = dist[tmp.u]+tmp.dist;
                    vc=tmp.u;
                }
            }
        }
    }


}

int main(){
    Edge tmp;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n>>m;
    for(int i = 0; i<m; i++){
        fin>>tmp.u>>tmp.v>>tmp.dist;
        e.push_back(tmp);
    }

    Bellman_Ford(0);

    if(vc==-1)
        fout<<"not possible"<<endl;
    else
        fout<<"possible"<<endl;

    fin.close();
    fout.close();
}
