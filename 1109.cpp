#include <fstream>
#include <vector>
#include <queue>

#define MAX 1001

using namespace std;

double g[MAX][MAX];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;
double prob[MAX];

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m,a,b; double p;

    fin>>n>>m;

    for(int i=0; i<m; i++){
        fin>>a>>b>>p;
        g[a][b]=p;
        g[b][a]=p;
    }
    for(int i=1; i<=n; i++) g[i][i]=0.0;
    for(int i=0; i<=n; i++) prob[i]=0.0;

    pq.push(make_pair(100,1));
    prob[1]=100;

    int from, to;
    double pf;
    while(!pq.empty()){
        from = pq.top().second; pf = pq.top().first; pq.pop();

        if(prob[from]>pf) continue;

        for(to=1; to<=n; ++to) {
            p=g[from][to];
            if(p==0.0) continue;

            p*=pf; p/=100;

            if(p>prob[to]){
                prob[to]=p;
                pq.push(make_pair(p,to));
            }

        }

    }

    fout.precision(6);
    fout<<fixed<<prob[n]<<" percent"<<endl;

    return 0;
}
