#include <iostream>

using namespace std;

int main(){
    int A, C, h, cortes;
    int X_i, X_i_1;
    scanf("%d", &A); scanf("%d", &C);
    while(A!=0 && C!=0){
        scanf("%d",&h);
        X_i_1=h;
        cortes=A-X_i_1;
        for(int i=1; i<C; i++){
            scanf("%d",&h);
            X_i=h;
            if( X_i<X_i_1 )cortes=cortes+X_i_1-X_i;
            X_i_1=X_i;
        }
        printf("%d\n", cortes);
        scanf("%d", &A); scanf("%d", &C);
    }
    return 0;
}