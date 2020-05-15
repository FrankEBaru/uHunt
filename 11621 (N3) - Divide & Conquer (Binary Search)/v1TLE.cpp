#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <long> C;

void crear(){
    long tres=1;
    long dos=1;
    //Se crean todos los posibles valores 2^i*3^j con i y j 0 inclusive
    for(int i=0; i<=31; i++){
        dos=pow(2,i);
        tres=1;
        do{
            C.push_back(dos*tres);
            tres=tres*3;
        }while(tres<=pow(2,31-i));
    }
    //Se ordena el vector C;
    sort(C.begin(), C.end());
}


int main(){
    crear();
    cout<<C.size()<<endl;
    vector<long>::iterator low;
    long n;
    scanf("%d", &n);
    while(n!=0){
        low=lower_bound(C.begin(), C.end(), n);
        cout<<*low<<"\n";
        scanf("%d", &n);
    }
    return 0;
}