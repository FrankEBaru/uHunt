#include <iostream>
#include <utility> 
#include <algorithm>

using namespace std;

struct carro{
    int numero, pOrig;
    carro(){numero=pOrig=0;}
};

bool sortBypOrig(carro a, carro b){
    return (a.pOrig < b.pOrig);
}

bool isValidGrid(carro carros[], int N){
    int aux=carros[1].pOrig;
    for(int i=2; i<=N; i++){
        if(carros[i].pOrig-aux==0)return false;
        aux=carros[i].pOrig;
    }
    return true;
}

int main(){
    carro carros[10001];
    int N, C, P;
    bool outRange;
    scanf("%d", &N);
    while(N!=0){
        outRange=false;
        for(int i=1; i<=N; i++){
            scanf("%d", &C);
            scanf("%d", &P);
            if(i+P<1 || i+P>N){
                printf("-1\n");
                outRange=true;
                //break;
            }
            carros[i].numero=C; carros[i].pOrig=i+P;
        }
        if(outRange==false){
            sort(carros+1, carros+N+1, sortBypOrig);
            if(isValidGrid(carros, N)){
                for(int i=1; i<N; i++){
                    printf("%d ", carros[i].numero);
                }
                printf("%d\n", carros[N].numero);
            }else{
                printf("-1\n");
            }     
        }         
        scanf("%d", &N);
    }

    return 0;
}