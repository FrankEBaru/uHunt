#include <iostream>
#include <cmath>

using namespace std;

#define TAM 10000000
bool Runaround[TAM];

bool isRunaroud(int a){
    int numero[7];
    int visitado[7];
    int dig[11];
    for(int i=1; i<=10; i++){
        dig[i]=0;
    }
    //Se guardan los digitos de a en numero
    int aux=a;
    int l=log10(a)+1;
    for(int i=l-1; i>=0; i--){
        visitado[i]=1;//No ha sido visitado
        numero[i]=aux%10;
        if(numero[i]==0)return false;//El numero no puede tener digito 0
        if(dig[numero[i]]==1)return false;//Si tiene algun digito repetido
        dig[numero[i]]=1;
        aux=(aux-numero[i])/10;
    }
    int id=0;
    int visitados=0;
    for(int i=1; i<=l; i++){
        visitados+=visitado[id];
        visitado[id]=0;
        id=(id+numero[id])%l;
    }



    /*int id=numero[0]%l;
    int visitados=visitado[0];
    visitado[0]=0;
    for(int i=1; i<l; i++){
        id=(id+numero[id])%l;
        visitados+=visitado[id];
        visitado[i]=0;
    }*/
    if(id==0 && visitados==l)return true;
    return false;
}

void calcular(){
    for(int i=1; i<TAM; i++){
        Runaround[i]=isRunaroud(i);
    }
}

int respuesta(int a){
    if(Runaround[a]==true)return a;
    int aux=a+1;
    while(Runaround[aux]==false && aux<TAM-1){aux++;}
    return aux;
}

int main(){
    calcular();
    int a;
    cin>>a;
    int caso=1;
    while(a!=0){
        /*if(isRunaroud(a)){
            cout<<"si"<<endl;
        }*/
        cout<<"Case "<<caso<<": "<<respuesta(a)<<endl;
        caso++;
        cin>>a;
    }
    
    

    return 0;
}