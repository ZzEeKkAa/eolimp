#include <iostream>
#include <algorithm>
#include <fstream>

#define HEIGHT 400
#define WIDTH 600

using namespace std;

/* сравнение целых */
int comp(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}

int m=0;
int s;
int screen[HEIGHT][WIDTH];
    int dfs(int _h, int _w){
    int length=1;
    int pos=0;
    int lineH[HEIGHT*WIDTH];
    int lineW[HEIGHT*WIDTH];
    int h,w;

    lineH[pos]=_h;
    lineW[pos]=_w;

    while(pos<length){
        h=lineH[pos];
        w=lineW[pos];
        //cout << h << " " << w << endl;
        screen[h][w]=m;
        if(h-1>=0 && screen[h-1][w]==0)     { screen[h-1][w]=m; lineH[length]=h-1; lineW[length]=w; length++; }
        if(h+1<HEIGHT && screen[h+1][w]==0) { screen[h+1][w]=m; lineH[length]=h+1; lineW[length]=w; length++; }
        if(w-1>=0 && screen[h][w-1]==0)     { screen[h][w-1]=m; lineH[length]=h; lineW[length]=w-1; length++; }
        if(w+1<WIDTH && screen[h][w+1]==0)  { screen[h][w+1]=m; lineH[length]=h; lineW[length]=w+1; length++; }
        pos++;
    }

    return length;
}



int a[WIDTH*HEIGHT],l;
int main(){
    int n;
    int x1,x2,y1,y2;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    while(fin>>n){
        m=0;
        // Setting default
        for(int i=0; i<HEIGHT; i++){
            for(int j=0; j<WIDTH; j++){
                screen[i][j]=0;
            }
        }

        // Reading data
        for(int i=0; i<n; i++){
            fin>>x1>>y1>>x2>>y2;
            for(int j=x1; j<=x2; j++){
                for(int k=y1; k<=y2; k++){
                    screen[j][k]=-1;
                }
            }
        }

        // Calculating
        l=0;
        for(int i=0; i<HEIGHT; i++){
            for(int j=0; j<WIDTH; j++){
                if(screen[i][j]==0){
                    m++;
                    s = dfs(i,j);
                    a[l] = s; l++;
                }
            }
        }
        qsort(a,l,sizeof(int),comp);
        if(l>0) fout<<a[0];
        for(int i=1; i<l; i++) fout<<" "<<a[i];
        fout<<endl;
    }

    fin.close();
    fout.close();
}
