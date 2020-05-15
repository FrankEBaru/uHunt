#include <iostream>
#include <cmath>

using namespace std;

bool cabe(int a, int b, int r1, int r2){
    if(r2>r1){
        swap(r1, r2);//para que r1 siempre sea mayor que r2
    }
    //Si el circulo más grande (r1) no cabe
    if(r1>(double)a/2.0 || r1>(double)b/2.0){return false;}
    //A cera el circulo más grande, B el más pequeño
    //Coordenadas de sus centros pegandolos a esquinas opuestas
    //Se supone la esquina inferior izq es (0,0) y la sup derecha es (a,b)
    double Ax,Ay,Bx,By;
    Ax=Ay=r1;
    Bx=a-r2;By=b-r2;
    double distancia=sqrt( pow(Bx-Ax,2)+pow(By-Ay,2) );//distancia de los centros
    if(distancia<(double)(r1+r2))return false;
    return true;
}

int main(){
    int a, b, r1, r2;
    cin>>a>>b>>r1>>r2;
    while(a!=0 || b!=0 || r1!=0 || r2!=0){
        if(cabe(a, b, r1, r2)){
            cout<<"S"<<endl;
        }else{
            cout<<"N"<<endl;
        }
        cin>>a>>b>>r1>>r2;
    }
    return 0;
}