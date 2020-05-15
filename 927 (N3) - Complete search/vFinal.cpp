#include <iostream>
#include <cmath>

using namespace std;

long long power(long x, long pot){
    if(pot == 0)return 1;
    long long r=1;
    for(long i=1; i<=pot; i++){
        r=r*x;
    } 
    return r;
}

long long polinomio( long coef[], long grado, long x){
    long long suma=0;
    for(long i=0; i<=grado; i++){
        suma+=power(x,i)*coef[i];
    }
    return suma;
}

long kthTermRecursivo(long k, long d, long L, long R){
    long M=(L+R)/2;
    long a=d*((M-1)*(M))/2;
    long b=d*((M)*(M+1))/2;
    if( a<k && k<=b) return M;

    if( b<k ) return kthTermRecursivo(k, d, M+1, R);
    return kthTermRecursivo(k, d, L, M);
}

//Dado un d buscamos el indice j tal que b_j contiene el k esimo numero de la secuencia
long kthTerm(long k, long d){
    return kthTermRecursivo(k, d, 0, k);
}

int main(){
    int C;
    long arr[25];
    cin>>C;
    long i, j, d, k;
    for(int caso=1; caso<=C; caso++){
        cin>>i;
        for(long exp=0; exp<=i; exp++){
            cin>>j;
            arr[exp]=j;
        }
        cin>>d;
        cin>>k;
        cout<<polinomio( arr, i, kthTerm(k, d))<<endl;
    }
    return 0;
}