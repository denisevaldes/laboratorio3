#include<iostream>
#include<string>

using namespace std;

struct NodoArbol {

        float dato;
        string matricula;
        //string para guardar los datos de matricula, tambien podria servir long int

        NodoArbol *izquierdo;

        NodoArbol *derecho;

};


class ArbolBinario {
    private:
    NodoArbol *crearnodo(float dato,string matricula);
    

    public:

    NodoArbol *raiz = nullptr; 
    NodoArbol *insertarNodo(NodoArbol *&nodo, float dato,string matricula); 

};
NodoArbol* ArbolBinario::crearnodo(float x,string y){
     NodoArbol *nuevoNodo = new NodoArbol;
     nuevoNodo->dato = x ;
     nuevoNodo->matricula = y ;
     nuevoNodo->izquierdo = NULL;
     nuevoNodo->derecho = NULL;

     return nuevoNodo;
}
// la opcion *& es importante en este programa para entregar los datos correctamente
NodoArbol* ArbolBinario::insertarNodo(NodoArbol *&nodo, float dato, string matricula){
        if(nodo == NULL){

            cout << "Insertando " << dato << endl;  
            nodo = crearnodo(dato,matricula);
            //se igualan para que haya interacion directa

        }else if (dato > nodo->dato){//si dato es mayor al nodo
            insertarNodo(nodo-> izquierdo,dato,matricula); //se inserta a la izquierda
        }else if (dato < nodo->dato){
            insertarNodo(nodo->derecho,dato,matricula);//se inserta a la derecha
        }else{
            cout<<"el numero ingresado ya existe"<<endl;
        }
        return nodo;
}


void inOrden(NodoArbol *raizarbol){
    if(raizarbol!=NULL){

        inOrden(raizarbol->izquierdo);
        cout <<"Promedio: "<< raizarbol->dato << "\tN.M: " <<raizarbol->matricula<< " <---|\n";
        
        inOrden(raizarbol->derecho);
    }

}
void preOrden(NodoArbol *raizarbol){
    if(raizarbol!=NULL){

        cout <<"Promedio: "<< raizarbol->dato << "\tN.M: " <<raizarbol->matricula<< " <---|\n";
        preOrden(raizarbol->izquierdo);
        preOrden(raizarbol->derecho);
    }

}
void postOrden(NodoArbol *raizarbol){
    if(raizarbol!=NULL){

            
        postOrden(raizarbol->izquierdo);
        postOrden(raizarbol->derecho);
        cout <<"Promedio: "<< raizarbol->dato << "\tN.M: " <<raizarbol->matricula<< " <---|\n";
    }

}


int main(){

    ArbolBinario *nuevoarbol = new ArbolBinario;
    NodoArbol *nuevaraiz = new NodoArbol;    
    int contador = 0;
    int opcion;
    string opcion2;   
    bool repetir = true;
    float n = 0;
    string matricula;
    bool existencia = false;


    do{

        
        cout<<"\nMenu de opciones"<<endl;
        cout<<"\t1 ingresar datos"<<endl;
        cout<<"\t2 inOrden "<<endl;
        cout<<"\t3 preOrden"<<endl;
        cout<<"\t4 postOrden"<<endl;
        cout<<"\t0 Salir"<<endl;

        cout<<"\n\t ingrese una opcion:\t";
        cin >> opcion;

        switch (opcion){

            case 1:
                cout<<"\n\t ingrese un promedio, el primero que ingrese sera su raiz: ";
                cin >> n;
                cout<<"\n\t ingrese la matricula correspondiente: ";
                cin >> matricula;
                if(!existencia){
                    NodoArbol *nodoarbol = new NodoArbol;
                    nuevoarbol->raiz = nodoarbol;
                    nuevaraiz = nodoarbol;
                    nuevaraiz->dato = n;
                    nuevaraiz->matricula = matricula;
                    existencia = true;

                }else{
                    nuevoarbol->insertarNodo(nuevaraiz,n,matricula);
                }

                break;
            case 2:
                cout<<"->--imprimiendo inOrden--<-"<<endl;
                cout<<"----...................----"<<endl;
               
                inOrden(nuevaraiz);
               
                break;
            case 3:
                cout<<"->--imprimiendo preOrden--<-"<<endl;
                cout<<"----...................----"<<endl;
                preOrden(nuevaraiz);
               
                break;
            case 4:
                cout<<"->--imprimiendo postOrden--<-"<<endl;
                cout<<"----...................----"<<endl;
                postOrden(nuevaraiz);
               
                break;
            case 0:

                repetir = false;
                cout<<"\n\n\t programa finalizado\n\n\n"<<endl;
                break; 
            
            default:

                cout<<"la opcion que ingreso es incorrecta"<<endl;
                break;
            }
            
        }while(repetir);
return 0;
};
