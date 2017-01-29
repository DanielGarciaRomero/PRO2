/**
 @mainpage Documentacion de la practica de PRO2: Gestion de revistas
 
En esta practica se pide diseñar un programa modular razonablemente eficiente que permita
gestionar una biblioteca de revistas mediante la simulacion de altas, bajas, fusiones, 
listados y consultas de las mismas. Para este cometido, utilizaremos las clases  
<em>Revista</em>, <em>Biblioteca</em> y <em>Jerarquiarea</em>.

*/

/** @file main.cpp
    @brief Programa principal
*/

#include "Biblioteca.hpp"

int main() {

    // En primer lugar, leemos N, el valor maximo del indice de calidad de
    // las revistas, que sera un entero mayor que 0

    int N = readint();

    Biblioteca B(N);

    // Seguidamente leemos el esquema de clasificacion de revistas, que incluye 
    // las relaciones jerarquicas entre areas. Dicho esquema contendra al menos 
    // un area

    Jerarquiarea J;

    J.leer_jerarquia();

    // Procedemos a procesar las diversas tareas que nos pidan

    int tarea, calidad, criterio;

    string nombre, nombre2;

    while (cin >> tarea and tarea != -6) {

        if (tarea == -1) { // Alta de revista

            Revista R;

            R.leer_revista();

	    B.anadir_revista(R, J);

	}

        else if (tarea == -2) { // Baja de revista

	    nombre = readstring();

	    B.eliminar_revista(nombre);
	    
	}

        else if (tarea == -3) { // Fusion de revistas

	    nombre = readstring();

	    nombre2 = readstring();

	    B.fusionar_revistas(nombre, nombre2, J);

	}

	else if (tarea == -4) { // Listado de revistas

	    calidad = readint();

            criterio = readint();

            B.listado(calidad, criterio); 

	}

        else if (tarea == -5) { // Consultar revista

	    nombre = readstring();    

            B.consultar_revista(nombre);

	}

    }

}
