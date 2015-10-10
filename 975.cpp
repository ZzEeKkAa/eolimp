#include <fstream>
#include <limits>

#define MAX 100

using namespace std;

const static int INF = numeric_limits<int>::max()/2;

int n;
int m[MAX][MAX];

int floyd(){
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(m[i][k]+m[k][j]<m[i][j]) m[i][j]=m[i][k]+m[k][j];
            }
        }
    }
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>m[i][j];
            if(m[i][j]==-1) m[i][j]=INF;
        }
    }

    floyd();

    int mm=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j]>mm && m[i][j]<INF) mm = m[i][j];
        }
    }

    fout<<mm<<endl;

    fin.close();
    fout.close();
}
