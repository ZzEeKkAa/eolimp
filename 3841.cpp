#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

#define MAX 10000

using namespace std;

int a[MAX];
int b[MAX];

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    stringstream ss;
    int n;
    int len;
    int pos;

    while(getline(fin,s)){
        ss<<s;
        n=0;
        while(ss>>a[n]) ++n;
        ss.clear();
        qsort(a,n,sizeof(int),compare);
        pos=0;
        len=0;

        while(pos<n){
            b[len]=a[pos];
        }
        len=a[0]+1;
        for(int i=0; i<len; ++i){
            b[i]=a[i];
        }

        for(int i=1; i<len; ++i){
            --b[i];
        }
        pop_heap(b,b+len);



    }


    fin.close();
    fout.close();
    return 0;
}
