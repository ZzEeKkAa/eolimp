#include <fstream>
#include <vector>

using namespace std;

int n, comp;
vector<vector<int> > g,gt;
vector<int> used, l, color;

int dfs1(int v){
    used[v]=1;

    for(vector<int>::iterator it = g[v].begin(); it < g[v].end(); ++it){
        if(!used[*it]) dfs1(*it);
    }

    l.push_back(v);
}

int dfs2(int v){
    color[v]=comp;

    for(vector<int>::iterator it = gt[v].begin(); it<gt[v].end(); ++it){
        if(color[*it]==-1) dfs2(*it);
    }
}

int main(){
    int m,a,b,c;
    string s;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n>>m;
    n*=2;

    g.assign(n, vector<int>());
    gt.assign(n, vector<int>());
    used.assign(n, 0);
    color.assign(n, -1);

    for(int i=0; i<m; ++i){
        fin>>a>>b>>c>>s;
        --a; --b;

        // Creating 2-SAT graph
        if(s=="AND"){
            if(c==1){
                g[a*2  ].push_back(b*2  ); gt[b*2  ].push_back(a*2  );  // !a v  b
                g[b*2+1].push_back(a*2+1); gt[a*2+1].push_back(b*2+1);

                g[b*2  ].push_back(a*2  ); gt[a*2  ].push_back(b*2  );  // !b v  a
                g[a*2+1].push_back(b*2+1); gt[b*2+1].push_back(a*2+1);

                g[a*2+1].push_back(b*2  ); gt[b*2  ].push_back(a*2+1);  //  a v  b
                g[b*2+1].push_back(a*2  ); gt[a*2  ].push_back(b*2+1);
            } else {
                g[a*2  ].push_back(b*2+1); gt[b*2+1].push_back(a*2  );  // !a v !b
                g[b*2  ].push_back(a*2+1); gt[a*2+1].push_back(b*2  );
            }
        }
        if(s=="OR"){
            if(c==1){
                g[a*2+1].push_back(b*2  ); gt[b*2  ].push_back(a*2+1);  //  a v  b
                g[b*2+1].push_back(a*2  ); gt[a*2  ].push_back(b*2+1);
            } else {
                g[a*2+1].push_back(b*2+1); gt[b*2+1].push_back(a*2+1);  //  a v !b
                g[b*2  ].push_back(a*2  ); gt[a*2  ].push_back(b*2  );

                g[b*2+1].push_back(a*2+1); gt[a*2+1].push_back(b*2+1);  //  b v !a
                g[a*2  ].push_back(b*2  ); gt[b*2  ].push_back(a*2  );

                g[a*2  ].push_back(b*2+1); gt[b*2+1].push_back(a*2  );  // !a v !b
                g[b*2  ].push_back(a*2+1); gt[a*2+1].push_back(b*2  );
            }
        }
        if(s=="XOR"){
            if(c==1){
                g[a*2+1].push_back(b*2  ); gt[b*2  ].push_back(a*2+1);  //  a v  b
                g[b*2+1].push_back(a*2  ); gt[a*2  ].push_back(b*2+1);

                g[a*2  ].push_back(b*2+1); gt[b*2+1].push_back(a*2  );  // !a v !b
                g[b*2  ].push_back(a*2+1); gt[a*2+1].push_back(b*2  );
            } else {
                g[a*2+1].push_back(b*2+1); gt[b*2+1].push_back(a*2+1);  //  a v !b
                g[b*2  ].push_back(a*2  ); gt[a*2  ].push_back(b*2  );

                g[b*2+1].push_back(a*2+1); gt[a*2+1].push_back(b*2+1);  // !a v  b
                g[a*2  ].push_back(b*2  ); gt[b*2  ].push_back(a*2  );
            }
        }
    }

    for(int i=0; i<n; ++i){
        /*fout<<i<<":";
        for(vector<int>::iterator it = g[i].begin(); it<g[i].end(); ++it )
            fout<<" "<<*it;
        fout<<endl;*/
        if(!used[i]) dfs1(i);
    }

    comp=0;
    for(int i=l.size()-1; i>=0; --i){
        if(color[l[i]]==-1) {
            dfs2(l[i]);
            ++comp;
        }
    }

    bool isSolution = true;
    for(int i=0; i<n; i+=2){
        if(color[i] == color[i+1]) isSolution = false;
    }

    if(isSolution) fout<<"YES"<<endl;
    else fout<<"NO"<<endl;/**/


    fin.close();
    fout.close();
}
