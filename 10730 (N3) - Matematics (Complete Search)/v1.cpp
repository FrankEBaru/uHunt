#include <iostream>
#include <string>

using namespace std;

bool isAntiarithmetic(int n, int perm[], int posicion[]){
    //n es el numero de permutacion
    //perm contiene la permutacion
    //posicion la posicion de cada numero en la permutacion
    int a0, a3, d;
    for(int ind1=0; ind1<=n-2; ind1++){
        for(int ind2=ind1+1; ind2<=n-1; ind2++){
            d=perm[ind2]-perm[ind1];//d=a2-a1
            a0=perm[ind1]-d;//a0=a1-d
            a3=perm[ind2]+d;//a3=a2+d
            if( 0<=a0 && a0<=n-1 ){
                //Si se encuenrtra una progresion aritm. a0, a1, a2
                if( posicion[a0]<ind1 )return false;
            }
            if( 0<=a3 && a3<=n-1 ){
                //Si se encuenrtra una progresion aritm. a1, a2, a3
                if( ind2<posicion[a3] )return false;
            }
        }
    }
    return true;
}


int main(){
    int perm[10000];
    int posi[10000];

    int n, ai;
    char b;
    cin>>n>>b;
    while(n!=0){
        for(int i=0; i<n; i++){
            scanf("%d", &ai);
            perm[i]=ai;
            posi[ai]=i;
        }
        if(isAntiarithmetic(n, perm, posi)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        cin>>n>>b;
    }

    /*string a;
    cin>>a;
    int m=a[0]-'0';
    cout<<m<<endl;
    */

    /*int perm[6]={1,2,4,0,3,5};
    int posi[6]={3,0,1,4,2,5};
    if(isAntiarithmetic(6, perm, posi)){
        cout<<"si"<<endl;
    }else
    {
        cout<<"no"<<endl;
    }
    cout<<"fin"<<endl;
    */
    return 0;
}