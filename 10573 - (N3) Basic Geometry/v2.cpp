#include <iostream>
#include <string>
#include <cmath>
using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

int main(){
    int N, j, aux, t, r1, r2;
    string input;
    cin>>N;
    getline(cin, input);
    //cout<<"primlin: "<<input<<endl;
    for(int i=1; i<=N; i++){
        cin>>r1;
        getline(cin, input);
        //cout<<"l: "<<input.length()<<endl;
        if(input.length()<=1){
            t=r1;
            //printf("t: %d y %.4f\n",t, (M_PI*t*t)/8.0);
            printf("%.4f\n",(M_PI*t*t)/8.0);
        }else{
            aux=0;
            j=1;
            while(j<input.length()){//checar si lleva o no el +1
                aux=aux*10;
                aux=aux+input[j]-'0';
                j++;
            }
            r2=aux;
            //printf("r1: %d r2: %d y %.4f\n",r1, r2 ,M_PI*( (r1+r2)*(r1+r2) - r1*r1 - r2*r2 ));
            printf("%.4f\n",M_PI*( (r1+r2)*(r1+r2) - r1*r1 - r2*r2 ));
        }
        
        
        /*
        j=0;
        aux=0;
        //cout<<input<<endl;
        //cout<<input.length()<<endl;
        while(j<input.length() && input[j]!=" "){//32 es el ascii de espacio en blanco
            aux=aux*10;
            aux=aux+input[j]-'0';
            j++;
        }
        cout<<aux<<endl;
        if(j==input.length()){
            t=aux;
            printf("t: %d y %.4f\n",t, (M_PI*t*t)/8.0);
            //printf("%.4f\n",(M_PI*t*t)/8.0);
        }else{
            r1=aux;
            aux=0;
            j++;
            while(j<input.length()){
                aux=aux*10;
                aux=aux+input[j]-'0';
                j++;
            }
            r2=aux;
            printf("r1: %d r2: %d y %.4f\n",r1, r2 ,M_PI*( (r1+r2)*(r1+r2) - r1*r1 - r2*r2 ));
            //printf("%.4f\n",M_PI*( (r1+r2)*(r1+r2) - r1*r1 - r2*r2 ));
        }
        */
    }
}