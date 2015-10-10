#include <fstream>
#include <vector>

using namespace std;

vector<vector<int > > a,b;
vector<char> way;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m;

    fin>>n>>m;

    a.assign(n+1,vector<int>(m+1,0));
    b.assign(n+1,vector<int>(m+1,0));

    for(int i=0; i<n; ++i){
        for(int j=1; j<=m; ++j){
            fin>>a[i][j];
        }
    }


    int i,j,c;

    for(i=n-1; i>=0; --i){
        for(j=1; j<=m; ++j){
            b[i][j]=max(b[i+1][j],b[i][j-1]);
            b[i][j]+=a[i][j];
        }
    } ++i; --j;

    while(i!=n-1 || j!=1){
        c=b[i][j]-a[i][j];
        if(i+1<n && c==b[i+1][j]) { way.push_back('F'); ++i; }
        else { way.push_back('R'); --j; }
    }

    for(int i=way.size()-1; i>=0; --i){
        fout<<way[i];
    } fout<<endl;

    fin.close();
    fout.close();
    return 0;
}
