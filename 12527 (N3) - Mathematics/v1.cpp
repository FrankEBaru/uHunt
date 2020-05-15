#include <iostream>
#include <set>
#include <cmath>

using namespace std;

bool hasRepetedDigits(int a){
    int aux=a;
    int d;
    multiset<int> digits;
    for(int i=1; i<=log10(a)+1; i++){
        d=aux%10;
        digits.insert(d);
        aux=(aux-d)/10;
    }
    multiset<int>::iterator it;
    int sumaaux=100;
    for(it=digits.begin(); it!=digits.end(); ++it){
        if( (*it)-sumaaux == 0)return true;
        sumaaux=*it;
    }
    return false;
}


int main(){
    int arr[5001];
    arr[0]=0;
    for(int i=1; i<=5000; i++){
        if(hasRepetedDigits(i)){arr[i]=arr[i-1];}
        else{arr[i]=arr[i-1]+1;}
    }
    int N, M;
    while(cin>>N>>M){
        cout<<arr[M]-arr[N-1]<<endl;
    }
    return 0;
}