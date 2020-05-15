#include <iostream>
#include <cmath>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

double volumen(int l, int h, int w, int theta){
    double h1, h2;
    h1=sin( theta*M_PI/180.0 )*l;
    h2=sin( (90-theta)*M_PI/180.0 )*h;
    double v;
    if(h2>h1){
        v=l*h*w-(tan( theta*M_PI/180.0 )*l*l*w)/2;
    }else{
        v=(tan( (90-theta)*M_PI/180.0 )*h*h*w)/2;
    }
    return v;
}

int main(){
    int l, h, w, theta;
    while(cin>>l>>w>>h>>theta){
        printf("%.3f mL\n",volumen(l, h, w, theta));
    }
    return 0;
}