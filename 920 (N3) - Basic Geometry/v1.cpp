#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct punto{
    int x, y;
};

double distancia(punto p, punto q){
    double r2=(p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
    return sqrt(r2);
}

double superficie2(punto p, punto q, int altura){
    //Se asume p es mas alto que q y altura esta entre p.y y q.y
    punto aux;
    aux.y=0;
    aux.x=q.x + (((q.x-p.x)*q.y)/(p.y-q.y));
    double D=distancia(p, aux);
    return D-((altura*D)/(p.y));
}

double superficie(punto p, punto q, int altura){
    //Se asume p es mas alto que q y altura esta entre p.y y q.y
    double D=sqrt( ( pow(q.x-p.x,2)+pow(p.y-q.y,2 ))/(pow(p.y-q.y,2)));
    return D*p.y-altura*D;
}

double superficie1(punto p, punto q, int altura){
    //Se asume p es mas alto que q y altura esta entre p.y y q.y
    double deltax;
    double a=(altura*(p.x-q.x)+p.y*q.x-p.x*p.y);
    a=a*a;
    double b=(p.y-q.y);
    b=b*b;
    deltax=a/b;

    double deltay=p.y-q.y;
    deltay=deltay*deltay;
    double D=sqrt(deltax + deltay);
    return D;
}

bool orderByx(punto a, punto b){
    return (a.x < b.x);
}

double puestaSol(punto arr[], int n){
    sort(arr, arr+n, orderByx);
    double puesta=distancia(arr[n-1], arr[n-2]);
    int alturamax=arr[n-2].y;
    for(int i=n-3; i>=0; i--){
        if(arr[i].y>alturamax){
            puesta=puesta+superficie(arr[i], arr[i+1], alturamax);
            alturamax=arr[i].y;
        }
    }
    return puesta;
}



int main(){
    int C, N, x, y;
    punto arr[110];
    scanf("%d", &C);
    for(int i=1; i<=C; i++){
        scanf("%d", &N);
        for(int j=0; j<N; j++){
            scanf("%d", &x);
            scanf("%d", &y);
            arr[j].x=x; arr[j].y=y;
        }
        printf("%.2f\n", puestaSol(arr, N));
    }

    return 0;
}