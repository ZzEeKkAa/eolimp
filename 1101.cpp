#include <fstream>

#define MAX 30

using namespace std;

int n=MAX;
int m[MAX][MAX];

void floyd(){
   for(int k=0; k<n; k++){
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               m[i][j]+=m[i][k]*m[k][j];
           }
       }
   }
}

int main(){
   ifstream fin("input.txt");
   ofstream fout("output.txt");

   int m0,a,b;
   fin>>m0;

   for(int i=0; i<n; i++){
       for(int j = 0; j<n; j++){
           m[i][j]=0;
       }
   }

   n=0;
   for(int i=0; i<m0; i++){
       fin>>a>>b;
       m[a][b]=1;
       if(a>n) n=a;
       if(b>n) n=b;
   }
   n++;

   floyd();
   //floyd();
   for(int k=0; k<n; k++){
       if(m[k][k]!=0){
           for(int i=0; i<n; i++)
           for(int j=0; j<n; j++){
               if(m[i][k] && m[k][j]) m[i][j]=-1;
           }
       }
   }

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
