#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


long C[329];

void crear(){
    long tres=1;
    long dos=1;
    int k=0;
    //Se crean todos los posibles valores 2^i*3^j con i y j 0 inclusive
    for(int i=0; i<=31; i++){
        dos=pow(2,i);
        tres=1;
        do{
            C[k]=dos*tres;
            k++;
            tres=tres*3;
        }while(tres<=pow(2,31-i));
    }
    //Se ordena el vector C;
    sort(C, C+329); 
}


long buscar(long arr[], long objetivo, int L, int R){
    if(objetivo==1)return 1;
    int M=(L+R)/2;
    if( arr[M-1]<objetivo && objetivo<=arr[M] )return arr[M];

    if( arr[M] > objetivo) return buscar(arr, objetivo, L, M);
    return buscar(arr, objetivo, M+1, R);
}


int main(){
    crear();
    for(int i=0; i<329; i++){
        cout<<C[i]<<",";
    }
    cout<<endl;
    long n;
    long a;
    scanf("%ld", &n);
    while(n!=0){
        a=buscar(C, n, 0, 329);
        printf("%ld\n", a);
        scanf("%ld", &n);
    }
    return 0;
}