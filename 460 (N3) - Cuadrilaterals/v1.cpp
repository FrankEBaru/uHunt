#include <iostream>

using namespace std;

void overlap(int Alx, int Aly, int Aux, int Auy, int Blx, int Bly, int Bux, int Buy){
    //Los rectangulos se llamaran A y B

    //Para asegurar que el rectangulo A siempre esta a la izquierda de B
    if(Blx<Alx){
        swap(Alx, Blx);
        swap(Aly, Bly);
        swap(Aux, Bux);
        swap(Auy, Buy);
    }
    //Se quita el caso en que no hay overlap en x
    if(Aux<=Blx){printf("No Overlap\n");return;}

    //Hay 2 casos para y
    if(Bly<=Aly){
        if(Buy<=Aly){printf("No Overlap\n");return;}
        //De lo contrario, hay overlap y es
        printf("%d %d %d %d\n",Blx, Aly, min(Aux,Bux), min(Auy,Buy));
    }else{//Aly<Bly
        if(Auy<=Bly){printf("No Overlap\n");return;}
        //De lo contrario, hay overlap y es
        printf("%d %d %d %d\n",Blx, Bly, min(Aux,Bux), min(Auy,Buy));
    }
}

int main(){
    int Alx, Aly, Aux, Auy, Blx, Bly, Bux, Buy;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&Alx);
        scanf("%d",&Aly);
        scanf("%d",&Aux);
        scanf("%d",&Auy);
        scanf("%d",&Blx);
        scanf("%d",&Bly);
        scanf("%d",&Bux);
        scanf("%d",&Buy);
        overlap( Alx, Aly, Aux, Auy, Blx, Bly, Bux, Buy);
        if(i!=n){
            printf("\n");
        }
    }
    return 0;
}