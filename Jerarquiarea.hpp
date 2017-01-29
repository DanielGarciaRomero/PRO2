/** @file Jerarquiarea.hpp
    @brief Especificacion de la clase Jerarquiarea
*/

#ifndef JERARQUIAREA_HPP
#define JERARQUIAREA_HPP

#include "Arbre.hpp"
#include "Revista.hpp"
#include <vector>

/** @class Jerarquiarea
    @brief Contiene las relaciones jerarquicas entre areas tematicas  
*/

class Jerarquiarea {

public:

  /** @brief Creadora por defecto

      \pre Cierto

      \post El resultado es una jerarquia vacia
  */

  Jerarquiarea();

  /** @brief Inicializa la jerarquia
    
      \pre Cierto

      \post El parametro implicito contiene las relaciones jerarquicas 
       entre areas tematicas  
  */

  void leer_jerarquia();

  /** @brief Obtencion del area tematica asociada a una revista segun el criterio 1
    
      \pre La revista r ha sido inicializada (a esta se le ha asignado
       un nombre, unas palabras clave y una calidad) y la jerarquia
       tambien

      \post El resultado es el area tematica que corresponde a la revista r
       segun el criterio 1
  */

  string calcular_area_c1(Revista &r);

  /** @brief Obtencion del area tematica asociada a una revista segun el criterio 2
    
      \pre La revista r ha sido inicializada (a esta se le ha asignado
       un nombre, unas palabras clave y una calidad) y la jerarquia
       tambien

      \post El resultado es el area tematica que corresponde a la revista r
       segun el criterio 2
  */

  string calcular_area_c2(Revista &r);

private:

  /** @brief Lectura
    
      \pre a es un arbol vacio y por el canal estandar de entrada nos llegara
       el recorrido en preorden de un arbol binario de strings A cuya marca
       de arbol vacio sera el string "."

      \post a = A

  */

  static void leer_arbol(Arbre<string> &a);

  /** @brief Inserta un string de manera ordenada en una lista de strings,
             donde cada string representa una palabra clave
    
      \pre Cierto

      \post El string pasa a formar parte de la lista si no formaba ya parte de 
       la misma. Los strings siguen ordenados alfabeticamente

  */

  static void insertar_ordenadamente(list<string> &l, string s);

  /** @brief Obtencion del area tematica asociada a una revista segun el criterio 1
    
      \pre a = A; v no es vacio (una revista tiene asociada una palabra clave
       como minimo)

      \post l contendra las palabras clave de la revista que hay en A. 
       Si l.size() == v.size() (en A aparecen al menos una vez todas las
       palabras clave), el pair que devuelve la funcion estara formado por el
       area segun criterio 1 asociada a la revista para el arbol A y por la 
       profundidad de la misma

  */

  static pair<string, int> inmersion_c1(Arbre<string> &a, vector<string> &v, list<string> &l, int &prof);

  /** @brief Obtencion del area tematica asociada a una revista segun el criterio 2
    
       \pre a = A; v no es vacio (una revista tiene asociada una palabra clave
       como minimo)

      \post El pair que devuelve la funcion indica si en A tenemos una palabra
       clave y, en ese caso, el area asociada a la revista para el arbol A
       segun el criterio 2

  */

  static pair <bool, string> inmersion_c2(Arbre<string> &a, vector<string> &v);

  Arbre<string> a;

};

#endif
