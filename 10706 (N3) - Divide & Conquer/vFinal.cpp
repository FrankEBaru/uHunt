#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 31268

//Numero de digitos al concatenar los numeros de 1  a n
long numDigitos(long n){
    if(n==0) return 0;
    long numDigitos=0;
    long naux=n;
    long i=log10(n);
    for(i; i>=0; i--){
        long aux=naux-pow(10,i)+1;
        numDigitos=numDigitos+aux*(i+1);
        naux=naux-aux;
    }
    return numDigitos;
}

//Busca el indice i tal que arr[i-1]<numero<=arr[i]
long busqueda(long arr[], long numero, long L, long R){
    long M=(L+R)/2;
    if( arr[M-1]<numero && numero<=arr[M] ) return M;
    //Si M no es el indice buscado entonces buscar en la mitad derecha o izquierda
    if( arr[M]<numero ) return busqueda(arr, numero, M+1, R);
    else return busqueda(arr, numero, L, M);
}

//Regresa el i esimo digito de izq a der del numero n
long iesimo(long i, long n){
    long j=log10(n)+1;
    long naux=n;
    long digito;
    for(j; j>=i; j--){
        digito=naux%10;
        naux=(naux-digito)/10;
    }
    return digito;
}

long kthdigitoUtil(long kthBuscado, long L, long R){
    long M=(L+R)/2;
    long a=numDigitos(M-1);
    long b=numDigitos(M);
    if ( a<kthBuscado && kthBuscado<=b ) return M;
    if ( b<kthBuscado ) return kthdigitoUtil(kthBuscado, M+1, R);
    return kthdigitoUtil(kthBuscado, L, M);
}

//devuelve el k esimo digito en la secuencia obtenida al concatenar los numeros de 1 hasta n
long kthdigito(long kthBuscado, long n){
    if(kthBuscado<=9) return kthBuscado;
    long naux=kthdigitoUtil(kthBuscado, 0, n);

    long i=kthBuscado-numDigitos(naux-1);

    //con esto, ahora buscamos el i esimo digito de naux
    return iesimo(i, naux);
}

int main(){
    
    //arr[i] contiene la cantidad de digitos al hacer la concatenacion hasta S_i (ver pdf)
    long arr[MAXN+1];
    arr[0]=0;
    long suma=0;
    for(long i=1; i<MAXN+1; i++){
        suma+=numDigitos(i);
        arr[i]=suma;
    }

    long nbuscar;
    long t;
    cin>>t;
    for(long i=1; i<=t; i++){
        cin>>nbuscar;
        //Reducion del problema a buscar un digito en S_i (ver pdf)
        long numero=busqueda(arr, nbuscar, 0, MAXN);
        long indReducido=nbuscar-arr[numero-1];
        //Ahora buscamos el digito en la posicion indReducido en la secuencia obtenida
        //al concatenar los numeros de 1 hasta numero
        cout<<kthdigito(indReducido, numero)<<endl;
    }
    return 0;
}