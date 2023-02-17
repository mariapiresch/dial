#include <iostream>
#include <stdio.h>
#include <time.h>


using namespace std ;


/*

    PRÁCTICA 1 (PARTE 2): ANÁLISIS DE LA EFICIENCIA DE ALGORITMOS DE
                          ORDENACIÓN Y DE BÚSQUEDA EN C/C++

    ASIGNATURA: DISEÑO DE ALGORITMOS
    CURSO:      2022-2023
    SUBGRUPO:   U1 / U2

    APELLIDOS:
    NOMBRE:

 
*/



/* ALGORITMOS DE ORDENACIÓN (SELECCIÓN E INSERCIÓN) */



/*
 
 EJERCICIO 1: Escribe el código en C++ de los algoritmos
 de ordenación por selección y de ordenación por inserción.
 (OPCIONAL) Escribe también el código en C++ de los algoritmos
 de ordenación quicksort y mergesort.
 
 */

 

void selectionSort(int v[], int N) ;



void insertionSort(int v[], int N) ;



/*

void quickSort(int v[], int inicio, int fin) ;

void mergeSort(int v[], int inicio, int fin) ;

 */



/* ALGORITMOS DE BÚSQUEDA (SECUENCIAL Y BINARIA) */



/*
 
 EJERCICIO 2: Escribe el código en C++ de los algoritmos
 de búsqueda secuencias y de búsqueda binaria.
 
 */



int busquedaSecuencial(int v[], int longitud, int item) ;



int busquedaBinaria(int v[], int item, int s1, int s2) ;



int main()
{
    
    
    /* DATOS DE ENTRADA */
    
    
    const int DIM = 50 ;
    int v[DIM] ;
    int N ;
   
    cout << "Introduce la longitud del vector: " ;
    cin >> N ;
    cout << endl ;
    
    cout << "Introduce las " << N << " componentes del vector: \n" ;
    for (int i = 0 ; i < N ; i++) cin >> v[i] ;
    cout << endl ;
    
    
    /* ALGORITMOS DE ORDENACIÓN (SELECCIÓN E INSERCIÓN) */
    
    
    int w[DIM] ;
    for (int i = 0 ; i < N ; i++) w[i] = v[i] ;
    
    cout << "Ordenar el vector (1.- Seleccion | 2.- Insercion): " ;
    int opcion ;
    cin >> opcion ;
    cout << endl ;
    
    if (opcion == 1) {
        
        cout << "Resultado de la funcion 'selectionSort': " ;
        selectionSort(w, N) ;
        for (int i = 0 ; i < N ; i++) cout << w[i] << " " ;
        cout << endl << endl ;
        
    }
        
    if (opcion == 2) {
        
        cout << "Resultado de la funcion 'insertionSort': " ;
        insertionSort(w, N) ;
        for (int i = 0 ; i < N ; i++) cout << w[i] << " " ;
        cout << endl << endl ;
        
    }
    
    
    /* ALGORITMOS DE BÚSQUEDA (SECUENCIAL Y BINARIA) */
        
    
    cout << "Introduce el elemento a buscar en el vector ordenado: " ;
    int item ;
    cin >> item ;
    cout << endl ;
    
    if (busquedaSecuencial(w, N, item) != -1) cout << "SI encontrado (busqueda secuencial)" << endl ;
    else cout << "NO encontrado (busqueda secuencial)" << endl ;
    cout << endl ;
    
    if (busquedaBinaria(w, item, 0, N) != -1) cout << "SI encontrado (busqueda binaria)" << endl ;
    else cout << "NO encontrado (busqueda binaria)" << endl ;
    cout << endl ;
        
    
    /* MEDIDAS DEL TIEMPO DE EJECUCION DE LOS PROGRAMAS */
  
    
    int repeticiones ;
    int tamanyos[DIM] ;
    double tiempos[DIM] ;
    clock_t t1, t2 ;
    
    cout << "Introduce el numero de repeticiones: " ;
    cin >> repeticiones ;
    cout << endl ;

    for (int i = 0 ; i < N ; i++) tamanyos[i] = i + 1 ;
    
    
    /* TIEMPOS DE EJECUCIÓN DE LOS ALGORITMOS DE ORDENACIÓN (SELECCIÓN E INSERCIÓN) */
    
    
    for (int i = 0 ; i < N ; i++) w[i] = v[i] ;
  
    cout << "Medidas del tiempo de ejecucion del programa 'selectionSort': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          selectionSort(w, tamanyos[k]) ;
          
       }
       //quiere que cambiemos w por una copia del vector, aunque implique cambiar la implementacion del algoritmo
       //la maxima calificacion de la practica tendra que ver con esto

       //le he preguntado y me ha dicho que hay qe meter el bucle de la linea 165 en el clock
       //de todas formas lo va a grabar ! sino me ha dicho que le pregunte por correo si no lo entiendo
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;
    
    
    for (int i = 0 ; i < N ; i++) w[i] = v[i] ;
    
    cout << "Medidas del tiempo de ejecucion del programa 'insertionSort': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          insertionSort(w, tamanyos[k]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;

    
    /* (OPCIONAL) TIEMPOS DE EJECUCIÓN DE LOS ALGORITMOS DE ORDENACIÓN (MERGESORT Y QUICKSORT) */
    
    
    /* TIEMPOS DE EJECUCIÓN DE LOS ALGORITMOS DE BÚSQUEDA (SECUENCIAL Y BINARIA) */
    
    
    cout << "Medidas del tiempo de ejecucion del programa 'busquedaSecuencial': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          busquedaSecuencial(v, tamanyos[k], tamanyos[0]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;
    
    
    cout << "Medidas del tiempo de ejecucion del programa 'busquedaBinaria': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          busquedaBinaria(v, 0, tamanyos[k], tamanyos[0]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;
    
    
}
