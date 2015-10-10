#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char ch;
    int r,c;

    fin>>ch;
    fin>>r;
    switch(ch){
    case('a'):
        c=1;
        break;
    case('b'):
        c=2;
        break;
    case('c'):
        c=3;
        break;
    case('d'):
        c=4;
        break;
    case('e'):
        c=5;
        break;
    case('f'):
        c=6;
        break;
    case('g'):
        c=7;
        break;
    case('h'):
        c=8;
        break;
    }

    r--;
    c--;

    int r1,c1;
    int r2,c2;
    for(r1=0; r1<8; r1++) if(r1!=r){
        c1=c+(r1-r);
        for(c1=c+(r1-r), int i = 0; i<2; c1=c-(r1-r), i++) if(c1!=c){
            for(r2=0; r2<8; r2++) if(r2!=r && r2!=r1){
                c2=c;

            }

        }
    }


    fout<<c<<r<<endl;
    fin.close();
    fout.close();
}
