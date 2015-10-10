#include <fstream>
#include <vector>
#include <queue>

#define INF 0x3F3F3F3F

using namespace std;

int n;
vector<vector<double> > g;
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
vector<int> exit;
vector<int> dist;
vector<double> time;

double dijkstra2(int v){
    vector<double> speed, dist2;
    int d;
    double v0, v1, mv;

    speed.assign(n+1,INF);
    dist2.assign(n+1,INF);

    pq.push(make_pair(0,v));
    dist2[v]=0;
    speed[v]=0;

    while(!pq.empty()){
        v0=pq.top().first; v=pq.top().second; pq.pop();

        //if(v0>speed[v]) continue;

        if(exit[v]) return v0;

        for(int i=1; i<=n; i++) if(g[v][i] && time[i]!=0){
            d=dist2[v]+g[v][i];
            v1=(double) d/(double) time[i];

            mv=v0;
            if(v1>v0) {
                mv=v1;
            }

            if(mv>speed[i] || mv==speed[i] && d>=dist2[i]) continue;

            dist2[i]=d;
            speed[i]=mv;
            pq.push(make_pair(mv,i));
        }

    }

    return -1;

}

int dijkstra1(int v){
    pq.push(make_pair(0,v));
    dist[v]=0;
    double d;

    while(!pq.empty()){
        d=pq.top().first; v=pq.top().second; pq.pop();

        if(dist[v]<d) continue;
        for(int i=1; i<=n; ++i) if(g[v][i]) {
            if(dist[i]>d+g[v][i]) {
                dist[i]=d+g[v][i];
                pq.push(make_pair(dist[i],i));
            }
        }

    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m, e, p;
    int a,b,l;

    fin>>n>>m>>e;
    g.assign(n+1,vector<double>(n+1,0));
    dist.assign(n+1, INF);
    time.assign(n+1, 0);
    exit.assign(n+1, 0);

    for(int i=0; i<m; i++){
        fin>>a>>b>>l;
        g[a][b]=l;
        g[b][a]=l;
    }

    for(int i=0; i<e; i++){
        fin>>a;
        exit[a]=1;
    }

    fin>>b>>p;

    // Getting time in which police be in vertex
    dijkstra1(p);
    for(int i=1; i<=n; i++)
        time[i]=dist[i]/(float)160.;

    // Getting minimal speed of brothers car
    double v = dijkstra2(b);
    if(v==-1){
        fout<<"IMPOSSIBLE"<<endl;
    } else {
        fout.precision(9);
        fout<<fixed<<v<<endl;
    }


    fin.close();
    fout.close();
}
