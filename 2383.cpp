#include <iostream>
#include <fstream>

#define MAXN 50

using namespace std;

int n;
int a[MAXN][MAXN];

int m;
int p[MAXN];

int used[MAXN];

int _m;
int _n;
int dfs(int v){
    _n++;
    used[v]=1;
    for(int i=0; i<n; i++){
        if(a[i][v]==1){
            _m++;
            if(used[i]==0) dfs(i);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;
    int toAdd = 0;
    int maxVertexes = 0;

    while(fin>>n){
        // reading data
        for(int i=0; i<n; i++) {// row
            for(int j=0; j<n; j++){// column
                fin>>ch;
                if(ch == '0')
                    a[i][j]=0;
                else
                    a[i][j]=1;
            }
        }
        fin >> m;
        for(int i=0; i<m; i++){
            fin >> p[i];
        }

        // Default
        toAdd=0;
        maxVertexes=0;
        for(int i=0; i<n; i++){
            used[i]=0;
        }

        // Calculating
        for(int i=0; i<m; i++){
            _n=0;
            _m=0;
            dfs(p[i]);
            _m/=2;
            toAdd+=(_n-1)*_n/2 - _m;
            if(maxVertexes<_n) maxVertexes=_n;
        }

        _n=0;
        _m=0;
        for(int i=0; i<n; i++){
            if(used[i]==0){
                dfs(i);
            }
        }
        _m/=2;

        /*cout << "MAX: " << maxVertexes <<endl;
        cout<<_n<<" "<<_m<<endl;
        cout<<toAdd<< " -> ";/**/
        toAdd+=_n*(_n-1)/2-_m;
        toAdd+=_n*maxVertexes;
        //cout<<toAdd<<endl;
        fout<<toAdd<<endl;
    }


    fin.close();
    fout.close();
}
