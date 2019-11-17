#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct cajita {
    int num;
    struct cajita *n;
    struct cajita *p;
}*inicio, *final;
int count = 0;
class circulardoublylist {
public:
    cajita *crearNodo(int);
    void insertarNodoPrincipio();
    void insertarNodoFinal();
    void insertarPosicion();
    void borrarPosicion();
    void buscar();
    void cambiar();
    void mostrar();
    void darVuelta();
    circulardoublylist() {
        inicio = NULL;
        final = NULL;
    }
};
int main() {
    int c;
    circulardoublylist cdl;
    while (1) {
        cout<<"1.Insertar nodo al principio"<<endl;
        cout<<"2.Insertar nodo al final"<<endl;
        cout<<"3.Insertar nodo en la posicion elegida"<<endl;
        cout<<"4.Borrar nodo por posicion elegida"<<endl;
        cout<<"5.Cambiar nodo elegido"<<endl;
        cout<<"6.Buscar elemento"<<endl;
        cout<<"7.Mostrar Lista Linqueada Circular"<<endl;
        cout<<"8.Dar la vuelta a la Lista"<<endl;
        cout<<"9.Salir"<<endl;
        cout<<"Elige la opcion : ";
        cin>>c;
        switch(c) {
            case 1:
                cdl.insertarNodoPrincipio();
                break;
            case 2:
                cdl.insertarNodoFinal();
                break;
            case 3:
                cdl.insertarPosicion();
                break;
            case 4:
                cdl.borrarPosicion();
                break;
            case 5:
                cdl.cambiar();
                break;
            case 6:
                cdl.buscar();
                break;
            case 7:
                cdl.mostrar();
                break;
            case 8:
                cdl.darVuelta();
                break;
            case 9:
                exit(1);
            default:
                cout<<"Elija una de las opciones indicadas"<<endl;
        }
    }
    return 0;
}
cajita* circulardoublylist::crearNodo(int v) {
    count++;
    struct cajita *t;
    t = new(struct cajita);
    t->num = v;
    t->n = NULL;
    t->p = NULL;
    return t;
}
void circulardoublylist::insertarNodoPrincipio() {
    int v;
    cout<<endl<<"Inserte el nodo que desee: ";
    cin>>v;
    struct cajita *t;
    t = crearNodo(v);
    if (inicio == final && inicio == NULL) {
        cout<<"nodo insertado en lista vacia"<<endl;
        inicio = final = t;
        inicio->n = final->n = NULL;
        inicio->p = final->p = NULL;
    } else {
        t->n = inicio;
        inicio->p = t;
        inicio = t;
        inicio->p = final;
        final->n = inicio;
        cout<<"nodo insertado con exito"<<endl;
    }
}
void circulardoublylist::insertarNodoFinal() {
    int v;
    cout<<endl<<"Inserte el nodo que desee: ";
    cin>>v;
    struct cajita *t;
    t = crearNodo(v);
    if (inicio == final && inicio == NULL) {
        cout<<"nodo insertado en lista vacia"<<endl;
        inicio = final = t;
        inicio->n= final->n = NULL;
        inicio->p = final->p= NULL;
    } else {
        final->n= t;
        t->p= final;
        final = t;
        inicio->p = final;
        final->n= inicio;
    }
}
void circulardoublylist::insertarPosicion() {
    int v, pos, i;
    cout<<endl<<"Inserte el nodo que desee: ";
    cin>>v;
    cout<<endl<<"¿Que posicion elige?: ";
    cin>>pos;
    struct cajita *t, *s, *ptr;
    t = crearNodo(v);
    if (inicio == final && inicio == NULL) {
        if (pos == 1) {
            inicio = final = t;
            inicio->n = final->n = NULL;
            inicio->p = final->p = NULL;
        } else {
            cout<<"Dicha posicion no existe"<<endl;
            count--;
            return;
        }
    } else {
        if (count < pos) {
            cout<<"Dicha posicion no existe"<<endl;
            count--;
            return;
        }
        s = inicio;
        for (i = 1;i <= count;i++) {
            ptr = s;
            s = s->n;
            if (i == pos - 1) {
                ptr->n = t;
                t->p= ptr;
                t->n= s;
                s->p = t;
                cout<<"nodo insertado con exito"<<endl;
                break;
            }
        }
    }
}
void circulardoublylist::borrarPosicion() {
    int pos, i;
    cajita *ptr, *s;
    if (inicio == final && inicio == NULL) {
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    cout<<endl<<"¿Que posicion elige? ";
    cin>>pos;
    if (count < pos) {
        cout<<"La posicion no existe"<<endl;
        return;
    }
    s = inicio;
    if(pos == 1) {
        count--;
        final->n = s->n;
        s->n->p = final;
        inicio = s->n;
        free(s);
        cout<<"nodo eliminado con exito"<<endl;
        return;
    }
    for (i = 0;i < pos - 1;i++ ) {
        s = s->n;
        ptr = s->p;
    }
    ptr->n = s->n;
    s->n->p = ptr;
    if (pos == count) {
        final = ptr;
    }
    count--;
    free(s);
    cout<<"nodo eliminado con exito"<<endl;
}
void circulardoublylist::cambiar() {
    int v, i, pos;
    if (inicio == final && inicio == NULL) {
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    cout<<endl<<"¿Que posicion elige? ";
    cin>>pos;
    cout<<"Inserte el nuevo nodo: ";
    cin>>v;
    struct cajita *s;
    if (count < pos) {
        cout<<"Dicha posicion no existe"<<endl;
        return;
    }
    s = inicio;
    if (pos == 1) {
        s->num = v;
        cout<<"nodo cambiado con exito"<<endl;
        return;
    }
    for (i=0;i < pos - 1;i++) {
        s = s->n;
    }
    s->num = v;
    cout<<"nodo cambiado con exito"<<endl;
}
void circulardoublylist::buscar() {
    int pos = 0, v, i;
    bool flag = false;
    struct cajita *s;
    if (inicio == final && inicio == NULL) {
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    cout<<endl<<"Inserte el nodo que quiere que sea buscado ";
    cin>>v;
    s = inicio;
    for (i = 0;i < count;i++) {
        pos++;
        if (s->num == v) {
            cout<<"El nodo "<<v<<" Se encuentra en la posicion: "<<pos<<endl;
            flag = true;
        }
        s = s->n;
    }
    if (!flag)
        cout<<"Dicho elemento no se encuentra en la lista"<<endl;
}
void circulardoublylist::mostrar() {
    int i;
    struct cajita *s;
    if (inicio == final && inicio == NULL) {
        cout<<"La lista esta vacia, nada que mostrar"<<endl;
        return;
    }
    s = inicio;
    for (i = 0;i < count-1;i++) {
        cout<<s->num<<"<->";
        s = s->n;
    }
    cout<<s->num<<endl;
}
void circulardoublylist::darVuelta() {
    if (inicio == final && inicio == NULL) {
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    struct cajita *p1, *p2;
    p1 = inicio;
    p2 = p1->n;
    p1->n = NULL;
    p1->p= p2;
    while (p2 != inicio) {
        p2->p = p2->n;
        p2->n = p1;
        p1 = p2;
        p2 = p2->p;
    }
    final = inicio;
    inicio = p1;
    cout<<"Lista dada la vuelta con exito"<<endl;
}