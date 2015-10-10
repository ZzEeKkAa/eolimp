#include <iostream>
#include <fstream>

#define MAXN 50

using namespace std;

int n;
int a[MAXN][MAXN];
long long used[MAXN];

long long dfn(int v){
  long long m = 0;
  bool isEmploer = false;
  //used[v]=1;

  for(int i=0; i<n; i++){
      if(a[v][i]==1){
          if(used[i]==0) dfn(i);
          m+=used[i];
          isEmploer = true;
      }
  }
  if(!isEmploer) m=1;

  used[v]=m;
  return m;
}

int main(){
  long long money;
  char ch;

  ifstream fin("input.txt");
  ofstream fout("output.txt");


  while(fin>>n){

      // Input + default
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              fin>>ch;
              if(ch=='Y')
                  a[i][j]=1;
              else
                  a[i][j]=0;
          }
          used[i]=0;
      }

      // Calculating
      for(int i=0; i<n; i++){
          if(used[i]==0) dfn(i);
      }

      money=0;
      for(int i=0; i<n; i++){
          money+=used[i];
      }

      fout<<money<<endl;

  }


  fin.close();
  fout.close();
  return 0;
}
