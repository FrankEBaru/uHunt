#include <iostream>
#include <cmath>

using namespace std;

void centers(double x1, double y1, double x2, double y2){
    if(y1==y2 && x1==x2){
        printf("%.10f %.10f %.10f %.10f\n", x1, x1, x1, x1);
        return;
    }
    bool sp=false;
    if(y1==y2){
        swap(x1,y1);
        swap(x2,y2);
        sp=true;
    }
    if(y1<y2){
        swap(x1, x2);
        swap(y1, y2);
    }

    double ax, ay, bx, by;
    double m=fabs(y1-y2)/2.0;
    double l=(y1+y2)/2.0;
    //Para el centro a
    double px=x1+m;
    double rx=x2+m;
    ax=(px+rx)/2.0;
    ay=l+(rx-px)/2.0;
    //Para el centro b
    double qx=x1-m;
    double sx=x2-m;
    bx=(qx+sx)/2.0;
    by=l+(qx-sx)/2.0;

    if(sp){
        swap(ax, ay);
        swap(bx, by);
    }

    printf("%.10f %.10f %.10f %.10f\n", ax, ay, bx, by);
    return;
}

int main(){
    double x1, y1, x2, y2;
    while(cin>>x1>>y1>>x2>>y2){
        centers(x1, y1, x2, y2);
    }
    return 0;
}