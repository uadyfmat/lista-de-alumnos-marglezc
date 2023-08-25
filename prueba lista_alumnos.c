#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{

    char *nombre;
    int creditos;
    int semestre;

};

typedef struct alumno Alumno;
typedef Alumno *AlumnoPtr;

struct nodo
{
    Alumno alum;
    struct nodo *enlace;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

NodoPtr crearNodo(AlumnoPtr);
AlumnoPtr crearAlumno(char*, int, int);
void insertarNodoOrdenadoCreditos(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);

int main(){

    NodoPtr cabecera = NULL;

    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Mariana", 94, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Jaqui", 80, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("José Luis", 92, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Mauro", 90, 3)));
    imprimirLista(cabecera);
    insertarNodoOrdenadoCreditos(&cabecera, crearNodo(crearAlumno("Isaías", 86, 3)));
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

    nuevoNodo -> alum.nombre = strdup(nuevoAlumno -> nombre);
    nuevoNodo -> alum.creditos = nuevoAlumno -> creditos;
    nuevoNodo -> alum.semestre = nuevoAlumno-> semestre;
    nuevoNodo -> enlace = NULL;

    return nuevoNodo;
}
