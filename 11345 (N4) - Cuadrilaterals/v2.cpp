#include <iostream>

using namespace std;

struct rectangulo{
    int lx, ly, ux, uy;
    int area(){
        return (ux-lx)*(uy-ly);
    }
};

int overlap(rectangulo A, rectangulo B, rectangulo &I){
    //Los rectangulos se llamaran A y B
    //I sera el rectangulo de interseccion
    I.lx=max(A.lx, B.lx); I.ly=max(A.ly, B.ly);
    I.ux=min(A.ux, B.ux); I.uy=min(A.uy, B.uy);
    if(I.lx>=I.ux || I.ly>=I.uy){return -1;}
    return 0;
}

int area(rectangulo arr[], int M){
    rectangulo final;
    int hayarea;
    final=arr[0];
    for(int i=1; i<M; i++){
        hayarea=overlap(final, arr[i], final);
        if(hayarea==-1)return 0;
    }
    return final.area();
}

int main(){
    rectangulo A[35];
    int Alx, Aly, Aux, Auy;
    int N, M;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d", &M);
        for(int j=0; j<M; j++){
            scanf("%d", &A[j].lx);//x1
            scanf("%d", &A[j].ly);//y1
            scanf("%d", &A[j].ux);//x2
            scanf("%d", &A[j].uy);//y2
        }
        printf("Case %d: %d\n", i, area(A, M));
    }
    return 0;
}