#include <iostream>
#include <fstream>
#define MAXN 33

using namespace std;

int n;
int a[MAXN][MAXN];

int k=0;

int dfn(int r, int c){
   a[r][c]=2;

   if(r-1<0  || r-1>=0 && a[r-1][c]==1) k++;
   if(r+1==n || r+1<n  && a[r+1][c]==1) k++;
   if(c-1<0  || c-1>=0 && a[r][c-1]==1) k++;
   if(c+1==n || c+1<n  && a[r][c+1]==1) k++;

   if(r-1>=0 && a[r-1][c]==0) dfn(r-1,c);
   if(r+1<n  && a[r+1][c]==0) dfn(r+1,c);
   if(c-1>=0 && a[r][c-1]==0) dfn(r,c-1);
   if(c+1<n  && a[r][c+1]==0) dfn(r,c+1);
}

int main() {
   char ch;
   ifstream fin("input.txt");
   ofstream fout("output.txt");

   fin>>n;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           fin>>ch;
           if(ch=='#')
               a[i][j] = 1;
           else if(ch=='.')
               a[i][j] = 0;
           else j--;
       }
   }

   dfn(0,0);

   fout<<(k-4)*9<<endl;

   fin.close();
   fout.close();

   return 0;
}
