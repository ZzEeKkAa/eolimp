#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > g;
vector<int> used;
vector<int> inDegree;
vector<int> top;
queue<int> q;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m,a,b;
    int from,to;
    vector<int>::iterator finish;


    fin>>n>>m;
    inDegree.assign(n+1,0);
    used.assign(n+1,0);
    g.assign(n+1, vector<int>());

    for(int i=0; i<m; ++i){
        fin>>a>>b;
        g[a].push_back(b);
        ++inDegree[b];
    }

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        from=q.front();

        finish = g[from].end();
        for(vector<int>::iterator it = g[from].begin(); it<finish; it++){
            to = *it;
            --inDegree[to];
            if(inDegree[to]==0) q.push(to);
        }

        top.push_back(from);
        q.pop();
    }
    if(top.size()!=n) {top.clear(); top.push_back(-1);}

    vector<int>::iterator it = top.begin();
    finish = top.end();
    fout<<*it; it++;
    for(; it<finish; it++){
        fout<<" "<<*it;
    }
    fout<<endl;
    fin.close();
    fout.close();
}
