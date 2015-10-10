#include <iostream>
#include <fstream>
#include <cmath>

#define MAXV 102
#define MAX MAXV*2+1

using namespace std;

int a[MAX][MAX];

int main(){
    int n;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>n;
    int x,y,k=0;
    int maxx=-MAXV,minx=MAXV,maxy=-MAXV,miny=MAXV;

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            a[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        fin>>x>>y;
        if(maxx<x) maxx=x;
        if(maxy<y) maxy=y;
        if(minx>x) minx=x;
        if(miny>y) miny=y;
        x+=MAXV;
        y+=MAXV;
        a[x][y]=1;
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(a[i][j]==1){
                if(a[i-1][j]==0) ++k;
                if(a[i+1][j]==0) ++k;
                if(a[i][j-1]==0) ++k;
                if(a[i][j+1]==0) ++k;
            }
        }
    }

    int s=sqrt(k);
    int nx=s,ny=s;
    x=maxx-minx+1; y=maxy-miny+1;
    //cout<<x<<" "<<y<<" "<<k<<" "<<s;
    while( !(2*(nx+ny)==k && (nx>=x && ny>=y || nx>=y && ny>=x) ) ){
        nx-=1;
        ny=k/nx;
    }


    fout<<(nx*ny-n)<<endl;


    fin.close();
    fout.close();
}
