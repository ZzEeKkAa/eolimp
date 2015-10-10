#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> possible;

int main(){
    string n;
    int len;
    getline(cin,n);
    len=n.length();

    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            if(n[i]<n[j]){
                swap(n[i],n[j]);
                possible.push_back(n);
                swap(n[i],n[j]);
            }
        }
    }

    qsort(&possible[0],possible.size(),sizeof(string));

    cout<<possible[possible.size()-1]<<endl;

}
