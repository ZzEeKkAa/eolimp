#include <fstream>
#include <cmath>

using namespace std;

int main(){
    float x1,y1,x2,y2,l=0,v=1000/3.;
    int t;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin>>x1>>y1;

    while(fin>>x1>>y1>>x2>>y2){
        l+=sqrtf((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    l*=2;
    t=roundf(l/v);
    fout<<t/60<<":"<<t%60<<endl;

    fin.close();
    fout.close();
}
