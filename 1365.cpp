#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#define INF numeric_limits<int>::max()

#define MAX 1000

using namespace std;

int g[MAX][MAX];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
int dist[MAX];

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, s, f;

    fin>>n>>s>>f;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fin>>g[i][j];
        }
        dist[i]=INF;
    }

    pq.push(make_pair(0,s));
    dist[s]=0;

    int to,from,df,d;
    while(!pq.empty()){
        from=pq.top().second; df=pq.top().first; pq.pop();

        if(df>dist[from]) continue;

        for(to=1; to<=n; ++to) if(from!=to && g[from][to]!=-1) {
            d=g[from][to]+df;
            if(dist[to]>d) {
                dist[to]=d;
                pq.push(make_pair(d,to));
            }
        }
    }

    if(dist[f]==INF) fout<<-1<<endl;
    else fout<<dist[f]<<endl;

    fin.close();
    fout.close();

}
