///////////
//EL PROBLEMA SE RESOLVIO A ATRAVES DE UN SEGMENT TREE CON LAZY
//** la idea es guardar la altura del edificio que va de l a r en el o los nodos del arbol relativos al segmento
//** [l,r] si algun edificio se sobrepone a este y es mas alto se actualiza el nodo o bien si solo es una parte 
//** en la que es mas alto que el anterior se actualizan los hijos y se pone en el arbol auxiliar homogeneo que
//** el segmento [l,r] no es homogeneo ya que no se posee la misma altura para cada i en todo este intervalo.
//** De esta forma podemos encontrar la interseccion de un edificio con los insertados anteriormente, donde 
//** el edificio A intersecta a uno B si comparten intervalo y en ese intervalo A tiene altura menor que B.
//** En base a esto se calcula el overlap pedido.

#include <iostream>
#include <string>
#include <cmath>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
struct STLazy{
    // NOTACION GENERAL
    // pos indica una posicion en el arreglo tree
    // segI es el inicio del segmento asociado al nodo en pos
    // segF es el final del segmento asociado al nodo en pos
    //bldI es el inicio del edificio a insertar
    //bldF es el final del edificio a insertar

    private:
        int *tree;//segment tree, guarda la maxima altura de los edificios
        int *homogeneo;//guarda si las alturas de el intervalo asociado a homogeneo [pos] es la misma en cada metro
                        //0 si todas son iguales o 1 de lo contrario
        int *lazy;//guarda las actualizaciones pendientes
        int maxT;//longitud real de los arreglos

        int left(int position){return 2*position+1;}//devuelve el hijo izquierdo
        int right(int position){return 2*position+2;}//devuelve el hijo derecho
        int parent(int position){return floor((position+1)/2 )-1;}//devuelve el padre

        int middle(int p1, int p2){return floor((p1+p2)/2);}//devuelve el valor medio de un intervalo

        //Inserta un nuevo edificio y devuelve la longitud de su intersección con edificios igual o mas altos
        //ya insertados
        int insertBuildingUtil(int pos, int segI, int segF, int bldI, int bldF, int h){
            //Si el nodo tiene alguna actualización pendiente, realizarla.
            if(lazy[pos]>0){
                tree[pos]=lazy[pos];
                if(segI!=segF){
                    lazy[left(pos)]=lazy[pos];
                    lazy[right(pos)]=lazy[pos];
                }
                lazy[pos]=0;
                homogeneo[pos]=0;
            }

            //Si el segmento de pos esta fuera del edificio, regresar 0
            if (segI>segF || segI>bldF || segF<bldI)return 0;
            //Si el segmento de pos esta completamente contenido en el edificio
            if( bldI<=segI && segF<=bldF){
                //Si todas las alturas en este intervalo son iguales
                if(homogeneo[pos]==0){
                    if(h<tree[pos]){
                        return segF-segI+1;
                    }
                    //Si el nuevo edificio es mas alto, actualizar
                    tree[pos]=h;
                    //Si no es un nodo hoja, pasar la actualizacion a sus hijos como pendiente
                    if(segI!=segF){
                        lazy[left(pos)]=h;
                        lazy[right(pos)]=h;
                    }
                    return 0;
                }
            }
            //Si no todas las  aturas en este intervalo son iguales o si el segmento no esta completamente 
            //contenido pero tiene traslape, insertar y preguntar en sus hijos
            int mid = middle(segI , segF);
            int a=insertBuildingUtil(left(pos), segI, mid, bldI, bldF, h);
            int b=insertBuildingUtil(right(pos), mid+1, segF, bldI, bldF, h);
            //Ahora se actualiza el valor en pos, tomando a sus hijos
            if(homogeneo[left(pos)]==0 && homogeneo[right(pos)]==0 && (tree[left(pos)]==tree[right(pos)]) ){
                tree[pos]=tree[left(pos)];
                homogeneo[pos]=0;
            }else{
                homogeneo[pos]=1;
            }
            //Se regresa el valor de la interseccion
            return a+b;
        }

    public:
        STLazy(int n){//n es el tamano del segmento maximo
            maxT=pow(2, ceil(log2(n))+1);
            tree=new int[maxT];
            homogeneo=new int[maxT];
            lazy=new int[maxT];
        }
        ~STLazy(){delete(tree);delete(homogeneo);delete(lazy);}//destructor

        //Inserta un edificio y calcula su interseccion con los ya insertados
        void insertBuilding(int longMax, int bldI, int bldF, int h, int *interseccion){
            int r=insertBuildingUtil(0, 0, longMax-1, bldI, bldF, h);
            *interseccion=r;
        }
        void inicializar(){
            for(int i=0; i<maxT-1; i++){
                tree[i]=0;
                lazy[i]=0;
                homogeneo[i]=0;
            }
        }
};

int main(){
    optimizar_io;
    int longMax=100005;
    int c;//nunero de casos
    int n;//tamano de cada caso
    int l, r, h;//dimensiones de cada edificio
    int interseccion;
    int traslape;
    STLazy *segment=new STLazy(longMax);//Segment tree basico a utilizar;
    scanf("%d", &c);
    for(int i=1; i<=c; i++){
        traslape=0;
        interseccion=0;
        scanf("%d", &n);
        for(int j=1; j<=n; j++){
            scanf("%d", &l);
            scanf("%d", &r);
            scanf("%d", &h);
            segment->insertBuilding(longMax, l, r-1, h, &interseccion);
            traslape=traslape + (r-l - interseccion);
        }
        printf("%d\n",traslape);
        segment->inicializar();
    }
    delete(segment);
    return 0;
}
