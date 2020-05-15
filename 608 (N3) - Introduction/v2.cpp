#include <iostream>
#include <string>

using namespace std;

void respuesta(string caso[]){
    int monedas[12]={};
    int checado[4]={};
    //Se inicializan todas las monedas a 1 significando que cualquiera puede ser la moneda falsa
    for(int i=0; i<12; i++)monedas[i]=1;

    int l;
    for(int i=1; i<=3; i++){
        if(caso[3*i]=="even"){
            checado[i]=1;//Esto significa que ya se reviso la i-esima balanceada
            l=caso[3*i-2].length();
            for(int j=0; j<l; j++){
                monedas[ caso[3*i-2][j]-'A' ]=0;
                monedas[ caso[3*i-1][j]-'A' ]=0;
            }
        }
    }

    //Ahora se checaran las posibes 24 respuestas
    int sumL, sumR, sumChecado;
    string raux;
    //Checaremos cada moneda
    for(int m=0; m<12; m++){
        if(monedas[m]==0)continue;//Si se sabe que esta moneda es legitima
        //En cada posible estado -1 es mas ligera y 1 es mas pesada que las legitimas
        for(int p=-1; p<=1; p+=2){           
            sumChecado=0;
            //Veremos si suponiendo esta moneda como la falsa, cada una de las 3 balanceadas se cumple o no
            for(int b=1; b<=3; b++){
                if(checado[b]==1){sumChecado++; continue;}
                sumL=sumR=0;
                l=caso[3*b-2].length();
                for(int c=0; c<l; c++){
                    if( caso[3*b-2][c]-'A'==m )sumL=sumL+p;
                    if( caso[3*b-1][c]-'A'==m )sumR=sumR+p;
                }
                if( sumL==sumR ){ raux="even"; }
                else if( sumL<sumR){ raux="down"; }
                else{ raux="up"; }
                if( caso[3*b]==raux ) sumChecado++;
            }
            if(sumChecado==3){
                char r=m+'A';
                if(p==-1){
                    cout<<r<<" is the counterfeit coin and it is light."<<endl; 
                    return;
                }
                if(p==1){
                    cout<<r<<" is the counterfeit coin and it is heavy."<<endl; 
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main(){
    int n;
    string caso[10];
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=9; j++){
            cin>>caso[j];
        }
        respuesta(caso);
    }
    
    //cout<<"fin"<<endl;
    return 0;
}