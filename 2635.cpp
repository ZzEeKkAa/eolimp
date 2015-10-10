#include <fstream>
#include <memory.h>

#define MAX 101
#define INF 0x3F3F3F3F

using namespace std;

int n;
int m[MAX][MAX];

void fyord(){
    for(int k=1; k<=n; ++k)
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
        if(m[i][k]+m[k][j]<m[i][j]) m[i][j] = m[i][k] + m[k][j];
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    memset(m,0x3F,sizeof(m));
    int m0,a,b,t;

    fin>>n>>m0;

    for(int i=0; i<m0; ++i){
        fin>>a>>b>>t;
        m[a][b]=t;
        m[b][a]=t;
    }
    for(int i=1; i<=n; i++) m[i][i]=0;

    fyord();

    int mint=INF,maxt,v;
    for(int i=1; i<=n; i++){
        maxt=0;
        for(int j=1; j<=n; j++){
            if(m[i][j]>maxt) maxt = m[i][j];
        }
        if(mint>maxt)
        //fout<<i<<" "<<maxt<<endl;
        { mint=maxt; v=i; }
    }

    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fout<<m[i][j]<<" ";
        }
        fout<<endl;
    }*/
    fout<<v<<" "<<mint<<endl;

    fin.close();
    fout.close();
}
