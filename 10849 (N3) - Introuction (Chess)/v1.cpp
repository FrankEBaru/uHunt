#include <iostream>

using namespace std;

bool sameColor(int Ix, int Iy, int Fx, int Fy){
    //Se supone que la casilla (1,1) es negra siempre
    bool inicio;//color del inicio 0 si blanco 1 si negro
    bool final;//color del final 0 si blanco 1 si negro
    //Color del inicio
    if(Iy%2==0){//Si la fila es par
        if(Ix%2==0){
            inicio=1;
        }else{
            inicio=0;
        }
    }else{//Si la fila es impar
        if(Ix%2==1){
            inicio=1;
        }else{
            inicio=0;
        }
    }
    //Color del final
    if(Fy%2==0){//Si la fila es par
        if(Fx%2==0){
            final=1;
        }else{
            final=0;
        }
    }else{//Si la fila es impar
        if(Fx%2==1){
            final=1;
        }else{
            final=0;
        }
    }

    if(inicio==1 && final==1)return true;
    if(inicio==0 && final==0)return true;
    return false;
}

void minima(int Ix, int Iy, int Fx, int Fy, int N){
    if(Ix>N || Iy>N || Fx>N || Fy>N){printf("no move\n");return;}//Si estan fuera del tablero
    if(!sameColor(Ix, Iy, Fx, Fy)){printf("no move\n");return;}//Si son de distinto color las posiciones
    if(Ix==Fx && Iy==Fy){printf("0\n");return;}//Si son la misma posicion
    if( (Ix-Iy)==(Fx-Fy) || (Ix+Iy)==(Fx+Fy) ){printf("1\n");return;}
    printf("2\n");
    return;
}

int main(){
    int C, T, N, Ix, Iy, Fx, Fy;
    scanf("%d", &C);
    for(int i=1; i<=C; i++){
        scanf("%d", &T);
        scanf("%d", &N);
        for(int j=1; j<=T; j++){
            scanf("%d", &Ix);
            scanf("%d", &Iy);
            scanf("%d", &Fx);
            scanf("%d", &Fy);
            minima(Ix, Iy, Fx, Fy, N);
        }
    }

    return 0;
}