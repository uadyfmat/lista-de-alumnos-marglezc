#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{

    char *nombre; //cadena es puntero
    int creditos;
    int semestre;

};

typedef struct alumno Alumno;
typedef Alumno *AlumnoPtr;

struct nodo
{
    AlumnoPtr alum; //estructura que contiene estructura alumno
    struct nodo *enlace; //apuntar a siguiente nodo
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

NodoPtr crearNodo(AlumnoPtr);
AlumnoPtr crearAlumno(char*, int, int);
void insertarNodoOrdenadoCred(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);

int main(){

    NodoPtr cabecera = NULL;

    insertarNodoOrdenadoCred(&cabecera, crearNodo(crearAlumno("Mariana González Canul", 94, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCred(&cabecera, crearNodo(crearAlumno("Jaqueline Góngora Tun", 88, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCred(&cabecera, crearNodo(crearAlumno("José Luis Lara Rubio", 92, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCred(&cabecera, crearNodo(crearAlumno("Mauro Arif Kuh Esquivel", 90, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCred(&cabecera, crearNodo(crearAlumno("Isaías Rodriguez Couoh", 86, 3)));
    imprimirLista(cabecera);

    return 0;
}

AlumnoPtr crearAlumno(char *nombre, int creditos, int semestre){

    AlumnoPtr nuevoAlumno = (AlumnoPtr)malloc(sizeof(Alumno));

    nuevoAlumno -> nombre = strdup(nombre);
    nuevoAlumno -> creditos = creditos;
    nuevoAlumno -> semestre = semestre;

    return nuevoAlumno;
}

NodoPtr crearNodo(AlumnoPtr nuevoAlumno){

    NodoPtr nuevoNodo = (NodoPtr)malloc(sizeof(Nodo));

    nuevoNodo -> alum = nuevoAlumno;
    nuevoNodo -> enlace = NULL;

    return nuevoNodo;
}

void insertarNodoOrdenadoCred(NodoPtr* cabecera, NodoPtr nuevoNodo){

    if(*cabecera == NULL){
        *cabecera = nuevoNodo;
    }
    else{
        NodoPtr actualNodo = *cabecera, anteriorNodo = NULL;
        while(actualNodo != NULL && nuevoNodo -> alum-> creditos < actualNodo -> alum -> creditos){
            anteriorNodo = actualNodo;
            actualNodo = actualNodo -> enlace;
        }

        if(anteriorNodo == NULL){
            nuevoNodo -> enlace == actualNodo;
            *cabecera = nuevoNodo;
        }
        else{
            nuevoNodo -> enlace = anteriorNodo -> enlace;
            anteriorNodo -> enlace = nuevoNodo;
        }
        
        }
}

void imprimirLista(NodoPtr cabecera){

    int i = 1;
    if(cabecera == NULL){
        printf("\nLista vacia\n");
        return;

    }
    else{

        printf("\nLista de alumnos: \n");

        while(cabecera != NULL){

            printf("%d) %s - %d - %d\n", i, cabecera-> alum -> nombre, cabecera-> alum -> creditos, cabecera-> alum -> semestre );
            cabecera = cabecera -> enlace;
            i++;
        }
        printf("\n");
    }
}


