#include <iostream>

using namespace std;


const int l=75;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//SOLO HACE FALTA HACER QUE ESTA FUNCION NO SEA CUADRATICA SINO LINEAL O MENOR
//Recordatorio: esta funcion debe buscar la maxima suma de un subarreglo de tamaño a lo mas longitud
//en este caso el arreglo en el que se busca ese maximo es la concatenacion de arr dos veces, para 
//simular un toro
int maxSuma1D(const int longitud, int arr[]){
    int Max=arr[0];
    int aux;
    int sumas[longitud];
    sumas[0]=arr[0];
    for(int i=1; i<longitud; i++)sumas[i]=sumas[i-1]+arr[i];
    for(int i=0; i<longitud; i++){
        for(int lo=0; lo<longitud; lo++){
            if(i==0){
                aux=sumas[lo];
            }else{
                if(i+lo>=longitud){
                    int s= (i+lo)%longitud;
                    aux=(sumas[longitud-1]-sumas[i-1])+sumas[ s ];
                }else{
                    aux=sumas[i+lo]-sumas[i-1];
                }
            }
            if(aux>Max)Max=aux;
        }
    }
    return Max;
}

int maxima(int toro[l][l], const int longitud){
    int sAcumuladas[longitud][longitud];
    for(int i=0; i<longitud; i++){
        for(int j=0; j<longitud; j++){
            if(j==0){sAcumuladas[i][j]=toro[i][j];continue;}
            sAcumuladas[i][j]=sAcumuladas[i][j-1]+toro[i][j];
        }
    }
    int interior[longitud];
    int exterior[longitud];
    int MaximaSuma;
    for(int i=0; i<longitud; i++){
        for(int j=i; j<longitud; j++){
            //Se definen los arreglos de sumas comprimidas
            for(int k=0; k<longitud; k++){
                if(i==0){
                    interior[k]=sAcumuladas[k][j];
                    //exterior[k]=sAcumuladas[k][longitud-1]-sAcumuladas[k][j];
                }else{
                    interior[k]=sAcumuladas[k][j]-sAcumuladas[k][i-1];
                    //exterior[k]=sAcumuladas[k][longitud-1]-sAcumuladas[k][j]+sAcumuladas[k][i-1];
                }
                exterior[k]=sAcumuladas[k][longitud-1]-sAcumuladas[k][j]+sAcumuladas[k][i];
            }
            int mi=maxSuma1D(longitud, interior);
            int me=maxSuma1D(longitud, exterior);
            if(i==0 && j==0){ 
                MaximaSuma=max(mi,me);
            }else{
                MaximaSuma=max(MaximaSuma, max(mi, me));
            }
        }
    }
    return MaximaSuma;
}

int main(){
    /*
    int arr[4]={-2,-4};
    cout<<maxSuma1D(2, arr)<<"\n";

    */
    int toro[l][l];
    int casos,n;
    cin>>casos;
    for(int c=1; c<=casos; c++){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>toro[i][j];
            }
        }
        cout<<maxima(toro, n)<<"\n";
    }
    //cout<<"fin\n";

    return 0;
}