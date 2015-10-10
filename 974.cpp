#include <fstream>

#define MAX 100

using namespace std;

int n;
int m[MAX][MAX];

void floyd(void){
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(m[i][k]+m[k][j]<m[i][j]) m[i][j]=m[i][k]+m[k][j];
            }
        }
    }
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n;


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>m[i][j];
        }
    }

    floyd();

    for(int i=0; i<n; i++){
        fout<<m[i][0];
        for(int j=1; j<n; j++){
            fout<<" "<<m[i][j];
        }
        fout<<endl;
    }

    fin.close();
    fout.close();
}

