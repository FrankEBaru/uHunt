#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void sumDireccion(double &actualx, double &actualy, int paso, string direccion){
    double unitarix, unitariy;
    if(direccion=="N"){
        unitarix=0;
        unitariy=1;
    }else if(direccion=="NE"){
        unitarix=1.0/sqrt(2);
        unitariy=1.0/sqrt(2);
    }else if(direccion=="E"){
        unitarix=1;
        unitariy=0;
    }else if(direccion=="SE"){
        unitarix=1.0/sqrt(2);
        unitariy=-1.0/sqrt(2);
    }else if(direccion=="S"){
        unitarix=0;
        unitariy=-1;
    }else if(direccion=="SW"){
        unitarix=-1.0/sqrt(2);
        unitariy=-1.0/sqrt(2);
    }else if(direccion=="W"){
        unitarix=-1;
        unitariy=0;
    }else if(direccion=="NW"){
        unitarix=-1.0/sqrt(2);
        unitariy=1.0/sqrt(2);
    }else{
        return;
    }
    actualx=actualx+(double)paso*unitarix;
    actualy=actualy+(double)paso*unitariy;
}

void tesoro(string mapa){
    int i=0;
    double posx, posy;
    posx=0;posy=0;
    int paso;
    int aux;
    string direccion;
    while(i+1<mapa.length()){
        paso=0;
        direccion.clear();
        while(48<=(int)mapa[i] && (int)mapa[i]<=57){//mientras sea un numero
            aux=mapa[i]-'0';
            paso=paso*10;
            paso=paso+aux;
            i++;
        }
        //cout<<"paso: "<<paso<<endl;
        while((int)mapa[i]!=44 && (int)mapa[i]!=46){
            direccion.push_back(mapa[i]);
            i++;
        }
        i++;
        //cout<<"direccion: "<<direccion<<endl;
        sumDireccion(posx, posy, paso, direccion);
    }
    printf("The treasure is located at (%.3f,%.3f).\n", posx, posy);
    printf("The distance to the treasure is %.3f.\n\n", sqrt(posx*posx+posy*posy));
}


int main(){
    string map;
    int caso=0;
    cin>>map;
    while(map!="END"){
        caso++;
        printf("Map #%d\n", caso);
        tesoro(map);
        cin>>map;
    }
    return 0;
}