#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define MAX 500 //Capacidad máxima de digitos para almacenar

class BigInt{
    //public:
    private:
        //Guardara los digitos del numero grande. 
        //numero[200] guardara el signo, -1 para negativo y 1 para positivo
        short int numero[MAX+1];
        //Cantidad de digitos que tiene numero
        short int numDigitos;
    public:
        BigInt(){numDigitos=1;numero[0]=0; numero[MAX]=1;}
        void imprimir(){
            if(numero[MAX]==-1)printf("-");
            for(short int i=numDigitos-1; i>=0; i--){
                printf("%hi", numero[i]);
            }
            printf("\n");
        }
        void imprimirError(short int n){
            if(numero[MAX]==-1)printf("-");
            short int i=numDigitos-1;
            if(numero[i]==n){
                if(i==0){
                    printf("0");
                    return;
                }
                i--;
                while(numero[i]==0 || numero[i]==n){
                    i--;
                    if(i==-1){
                        printf("0");
                        return;
                    }
                }
                
            }
            for(i; i>=0; i--){
                if(numero[i]==n)continue;
                printf("%hi", numero[i]);
            }
        }
        //Para igualar el valor del BigInt al de un entero regular
        void operator = (const long long &a){
            long long aux=a;
            numero[MAX]=1;
            if(aux<0){
                numero[MAX]=-1;
                aux=aux*(-1);
            }
            if(aux==0){numero[0]=0; numDigitos=1; return;}
            numDigitos=log10(aux)+1;
            for(short int i=0; i<numDigitos; i++){
                numero[i]=aux%10;
                aux=(aux-numero[i])/10;
            }
            return;
        }
        //Para asignarle el valor a un BigInt desde un string
        void operator = (const string &a){
            numDigitos=0;
            numero[MAX]=1;
            for(short int i=a.length(); i>=1; i--){
                if(i==1){
                    if(a[0]=='-'){
                        numero[MAX]=-1;
                        continue;
                    }
                }
                if( (a[i-1]-'0')<0 || 9<(a[i-1]-'0'))return;
                numero[a.length()-i]=a[i-1]-'0';
                numDigitos++;
            }
            return;
        }
        //Operador menor
        friend bool operator < (BigInt const &, BigInt const &);
        friend bool operator < (BigInt const &, long long const &);
        friend bool operator < (long long const &, BigInt const &);
        //Para sumar dos BigInt
        friend BigInt operator + (BigInt const &, BigInt const &);
        friend BigInt operator + (BigInt const &, long long const &);
        friend BigInt operator + (long long const &, BigInt const &);
        //Para restar dos BigInt
        friend BigInt operator - (BigInt const &, BigInt const &);
        friend BigInt operator - (BigInt const &, long long const &);
        friend BigInt operator - (long long const &, BigInt const &);
        //Para multiplicar dos BigInt
        friend BigInt operator * (BigInt const &, BigInt const &);
        friend BigInt operator * (BigInt const &, long long const &);
        friend BigInt operator * (long long const &, BigInt const &);
};

//Operador menor entre Big Ints
bool operator < (BigInt const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt b; b=y;
    //Regresara si a<b
    short int signoa=a.numero[MAX];short int signob=b.numero[MAX];
    //Casos segun los signos
    if( signoa==-1 && signob==1)return true;
    if( signoa==1 && signob==-1)return false;
    if( signoa==-1 && signob==-1){
        a.numero[MAX]=1; b.numero[MAX]=1;
        return b<a;
    }
    //En caso ambos sean positivos
    short int la=a.numDigitos;
    short int lb=b.numDigitos;
    if( la < lb )return true;
    if( la > lb )return false;
    //En caso ambos positivos y la misma cantidad de digitos
    for(short int i=la-1; i>=0; i--){
        if( a.numero[i] < b.numero[i] )return true;
        if( a.numero[i] > b.numero[i] )return false;
    }
    return false;
}
bool operator < (BigInt const &x, long long const &y){
    BigInt a; a=y;
    return x<a;
}
bool operator < (long long const &x, BigInt const &y){
    BigInt a; a=x;
    return a<y;
}

//Operacion resta entre Big Ints
BigInt operator - (BigInt const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt b; b=y;
    //Se restara a-b

    //El big int a devolver
    BigInt r;

    //Se obtienen los signos de los numeros
    short int signoa=a.numero[MAX];short int signob=b.numero[MAX];
    //Casos segun los signos
    if( signoa == 1 && signob == -1){
        //si es a-(-b) entonces es a+b
        b.numero[MAX]=1;
        return a+b;
    }
    if( signoa == -1 && signob == 1){
        //si es (-a)-b entonces es -(a+b)
        a.numero[MAX]=1;
        r=a+b;
        r.numero[MAX]=-1;
        return r;
    }
    if( signoa == -1 && signob == -1){
        //si es (-a)-(-b) entonces es b-a
        a.numero[MAX]=1;
        b.numero[MAX]=1;
        return b-a;
    }

    //En caso de ser una resta de dos numeros positivos a-b
    //Se le asigna el signo a la respuesta
    if( a < b ){
        r.numero[MAX]=-1;
        swap(a, b);
    }else{
        r.numero[MAX]=1;
    }

    short int l=b.numDigitos;
    short int L=a.numDigitos;

    //Se rellenan los digitos faltanes de b
    for(int i=l; i<L; i++)b.numero[i]=0;

    r.numDigitos=0;

    short int daux=0;//digito auxiliar
    short int dauxSig=0;//digito siguiente a daux, lleva si se presto algo del siguiente

    //Se suman los primeros L digitos
    for(short int i=0; i<L; i++){
        daux=dauxSig+a.numero[i]-b.numero[i];
        dauxSig=0;
        if(daux<0){
            dauxSig--;//Si se presto una unidad al siguiente
            daux=daux+10;
        }
        r.numero[i]=daux;
        r.numDigitos++;
    }
    //Ahora se checa que no hayan ceros a la izquierda en r
    short int cont=r.numDigitos;
    while(r.numero[cont-1]==0 && cont>1){
        cont--;
    }
    r.numDigitos=cont;

    return r;
}
BigInt operator - (BigInt const &x, long long const &y){
    BigInt a; a=y;
    BigInt r;
    r=x-a;
    return r;
}
BigInt operator - (long long const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt r;
    r=a-y;
    return r;
}

//Operacion suma entre Big Ints
BigInt operator + (BigInt const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt b; b=y;
    
    //Se obtienen los signos de los numeros
    short int signoa=a.numero[MAX];short int signob=b.numero[MAX];
    short int signor=1;
    //Casos segun los signos
    if( signoa == -1 && signob == -1){
        signor=-1;
    }
    if( signob == -1 && signoa == 1){
        b.numero[MAX]=1;
        return a-b;
    }
    if( signob == 1 && signoa == -1){
        a.numero[MAX]=1;
        return b-a;
    }

    //En caso de ser una suma de numeros del mismo signo

    //El big int a devolver
    BigInt r;
    r.numDigitos=0;

    if( b.numDigitos < a.numDigitos){swap(a, b);}//a sera el que tenga la menor cantida de digitos
    short int l=a.numDigitos;
    short int L=b.numDigitos;

    //Se rellenan los digitos faltanes de a
    for(int i=l; i<L; i++)a.numero[i]=0;

    short int daux=0;//digito auxiliar
    short int dauxSig=0;//digito siguiente a daux

    //Se suman los primeros L digitos
    for(short int i=0; i<L; i++){
        daux=dauxSig+a.numero[i]+b.numero[i];
        dauxSig=0;
        if(daux>9)dauxSig++;//si se lleva una unidad
        r.numero[i]=daux%10;
        r.numDigitos++;
    }
    //Si habia alguna unidad pendiente cargada
    if(dauxSig==1){
        r.numero[L]=dauxSig;
        dauxSig=0;
        r.numDigitos++;
    }
    r.numero[MAX]=signor;
    return r;
}
BigInt operator + (BigInt const &x, long long const &y){
    BigInt a; a=y;
    BigInt r;
    r=x+a;
    return r;
}
BigInt operator + (long long const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt r;
    r=a+y;
    return r;
}

//Operaciones de multiplicacion
BigInt operator * (BigInt const &x, BigInt const &y){
    BigInt a; a=x;
    BigInt b; b=y;

    //Big int a regresar
    BigInt r;
    r.numDigitos=0;

    //Cantidad de digitos de a y b
    short int la=a.numDigitos;
    short int lb=b.numDigitos;
    short int daux=0;//digito auxiliar
    short int dauxSig=0;//Llevara las unidades cargadas del digito siguiente
    BigInt sumaAux; sumaAux=0;
    BigInt aux;
    for(short int i=0; i<la; i++){
        aux.numDigitos=0;
        for(short int k=0; k<i; k++){
            aux.numero[k]=0;
            aux.numDigitos++;
        }
        for(short int j=0; j<lb; j++){
            daux=a.numero[i]*b.numero[j]+dauxSig;
            dauxSig=0;
            if(daux>9){dauxSig = (daux-(daux%10))/10;}
            aux.numero[i+j]=daux%10;
            aux.numDigitos++;
            if(j==lb-1 && dauxSig!=0){
                aux.numero[i+lb]=dauxSig;
                dauxSig=0;
                aux.numDigitos++;
            }
        }
        //Ahora se checa que no hayan ceros a la izquierda en r
        short int cont=aux.numDigitos;
        while(aux.numero[cont-1]==0 && cont>1){
            cont--;
        }
        aux.numDigitos=cont;
        sumaAux=sumaAux+aux;
    }
    r=sumaAux;
    //Se obtiene el signo del resultado
    r.numero[MAX]=a.numero[MAX]*b.numero[MAX];
    if(r.numero[0]==0 && r.numDigitos==1){
        r.numero[MAX]=1;
    }
    return r;
}
BigInt operator * (BigInt const &x, long long const &y){
    BigInt r;
    BigInt b; b=y;
    r=x*b;
    return r;
}
BigInt operator * (long long const &x, BigInt const &y){
    BigInt r;
    BigInt b; b=x;
    r=b*y;
    return r;
}

BigInt subsecuencia(int arr[], int n){
    //arr secuencia de nuemeros
    //n numeros en la secuencia
    BigInt positivo;
    BigInt negativo;
    BigInt aux;
    BigInt maximo;
    maximo=arr[0];
    positivo=1;
    negativo=1;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            aux=positivo;
            if(negativo<0){
                positivo=negativo*arr[i];
                if(maximo<positivo)maximo=positivo;
            }else{//negativo == 1
                positivo=1;
                if(maximo<arr[i])maximo=arr[i];
            }
            negativo=aux*arr[i];
        }else{
            if(arr[i]<1){//si arr[i]==0
                positivo=1;
                negativo=1;
                if(maximo<arr[i])maximo=arr[i];
            }else{
                positivo=positivo*arr[i];
                negativo=negativo*arr[i];
                if(maximo<positivo)maximo=positivo;
            }
        }
    }
    return maximo;
}

int main(){
    BigInt r;
    int a;
    int arr[101];
    int i=0;
    while(cin>>a){
        if(a!=-999999){
            arr[i]=a;
            i++;
        }else{
            r=subsecuencia(arr, i);
            r.imprimir();
            i=0;
        }
    }
    return 0;
}