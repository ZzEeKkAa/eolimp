#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

#define MAX 366
#define INF numeric_limits<int>::max()

using namespace std;

int n,m,k,s;

vector<vector<int> > g;
int dist[MAX];
int e[MAX][MAX];
priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

vector<int> w;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int a,b,t;

    fin>>n>>m>>k;

    g.assign(n+1,vector<int>());
    for(int i=0; i<=n; i++) dist[i]=INF;

    for(int i=0; i<m; i++){
        fin>>a;
        w.push_back(a);
    }

    for(int i=0; i<k; i++){
        fin>>a>>b>>t;
        g[a].push_back(b);
        g[b].push_back(a);
        e[a][b]=t;
        e[b][a]=t;
    }

    fin>>s;

    dist[s]=0;
    pq.push(make_pair(0,s));

    int from, to, df, d;
    vector<int>::iterator finish;
    while(!pq.empty()){
        from = pq.top().second; df = pq.top().first; pq.pop();

        if(df>dist[from]) continue;

        finish= g[from].end();
        for(vector<int>::iterator it = g[from].begin(); it<finish; it++){
            to=*it;
            d = e[from][to]+df;

            if(dist[to]>d) {
                dist[to]=d;
                pq.push(make_pair(d, to));
            }
        }
    }

    int md=0;
    for(vector<int>::iterator it=w.begin(); it<w.end(); it++){
        if(dist[*it]==INF) {md=-1; break;}
        if(dist[*it]>md) md=dist[*it];
    }

    if(md==-1)
        fout<<"It is not fault of sponsor..."<<endl;
    else
        fout<<"The good sponsor!"<<endl<<md<<endl;

    fin.close();
    fout.close();
}
