#include <fstream>
#include <iostream>

#define MAX 30

using namespace std;

int l,r,c;

int a[MAX][MAX][MAX];
int used[MAX][MAX][MAX];

int lineL[MAX*MAX*MAX];
int lineR[MAX*MAX*MAX];
int lineC[MAX*MAX*MAX];
int pos;
int length;
int level;
int last;

int bfs(){
    int _l,_r,_c;
    int lvl=0;

    while(pos<length){

        if(pos-1==last) {lvl++; last=length-1;}
        _l=lineL[pos];
        _r=lineR[pos];
        _c=lineC[pos];

        if(a[_l][_r][_c]==1) {pos++; continue;}
        if(a[_l][_r][_c]==2) {return lvl;}
        cout<<lvl<<": "<<_l<<" "<<_r<<" "<<_c<<endl;


        //Add to order
        if(_l-1>=0 && used[_l-1][_r][_c]==0) {
            lineL[length]=_l-1;
            lineR[length]=_r;
            lineC[length]=_c;
            length++;

            used[_l-1][_r][_c]==1;
        }
        if(_r-1>=0 && used[_l][_r-1][_c]==0) {
            lineL[length]=_l;
            lineR[length]=_r-1;
            lineC[length]=_c;
            length++;

            used[_l][_r-1][_c]=1;
        }
        if(_c-1>=0 && used[_l][_r][_c-1]==0) {
            lineL[length]=_l;
            lineR[length]=_r;
            lineC[length]=_c-1;
            length++;

            used[_l][_r][_c-1]=1;
        }
        if(_l+1<l && used[_l+1][_r][_c]==0) {
            lineL[length]=_l+1;
            lineR[length]=_r;
            lineC[length]=_c;
            length++;

            used[_l+1][_r][_c]=1;
        }
        if(_r+1<r && used[_l][_r+1][_c]==0) {
            lineL[length]=_l;
            lineR[length]=_r+1;
            lineC[length]=_c;
            length++;


            used[_l][_r+1][_c]=1;
        }
        if(_c+1<c && used[_l][_r][_c+1]==0) {
            lineL[length]=_l;
            lineR[length]=_r;
            lineC[length]=_c+1;
            length++;

            used[_l][_r][_c+1]=1;
        }

        pos++;
    }

    return -1;
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char ch;


    fin>>l>>r>>c;
    while(l!=0 || r!=0 || c!=0){
        pos=0;
        length=1;
        last=0;

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    used[i][j][k]=0;

                    fin>>ch;
                    if(ch=='#')
                        a[i][j][k]=1;
                    else if(ch=='.')
                        a[i][j][k]=0;
                    else if(ch=='S'){
                        lineL[0]=i;
                        lineR[0]=j;
                        lineC[0]=k;
                        a[i][j][k]=0;
                        used[i][j][k]=1;
                    }
                    else if(ch=='E')
                        a[i][j][k]=2;
                    else
                        k--;
                }
            }
        }

        level = bfs();

        if(level==-1) {
            fout<<"Trapped!"<<endl;
        } else {
            fout<<"Escaped in "<<level<<" minute(s)."<<endl;
        }
        fin>>l>>r>>c;
    }


    fin.close();
    fout.close();

}
