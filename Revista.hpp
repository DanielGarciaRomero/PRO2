/** @file Revista.hpp
    @brief Especificacion de la clase Revista
*/

#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "list"
#include "utils.PRO2"

/** @class Revista
    @brief Representa las revistas que conforman una biblioteca
*/

class Revista {

public:
  
  /** @brief Creadora por defecto
      
      \pre Cierto

      \post El resultado es una revista sin nombre, sin areas tematicas
       asignadas segun criterio, sin un indice de calidad y sin palabras
       clave
  */   
  
  Revista();

   /** @brief Inicializa las caracteristicas de la revista
      
      \pre Por el canal estandar de entrada se leera un string que
       representa el nombre de la revista, una secuencia de strings
       en orden alfabetico que representa las palabras clave y un 
       entero de valor entre 1 y N (donde N es el valor maximo del
       indice de calidad de las revistas) que representa su calidad

      \post El resultado es una revista con un determinado nombre 
       y unas concretas palabras clave y calidad asociadas a esta 

  */   

  void leer_revista();

  /** @brief Asocia otra palabra clave a la revista
      
      \pre Cierto

      \post La palabra clave pasa a formar parte del parametro implicito 
       si no formaba ya parte de el. Las palabras clave siguen ordenadas
       alfabeticamente
  */  

  void anadir_pal_clave(string s);

  /** @brief Asigna un area tematica a una revista segun el criterio 1
      
      \pre Cierto

      \post El parametro implicito tiene como area tematica segun
       el criterio 1 el string que le llega por parametro explicito
  */  

  void asignar_area_c1(string s);

  /** @brief Asigna un area tematica a una revista segun el criterio 2
    
      \pre Cierto

      \post El parametro implicito tiene como area tematica segun
       el criterio 2 el string que le llega por parametro explicito
  */

  void asignar_area_c2(string s);


  /** @brief Consultora del numero de palabras clave de la revista
      
      \pre Cierto

      \post El resultado es el numero de palabras clave de la revista
  */  

  int consultar_num_pal_clave() const;

  /** @brief Consultora de una palabra clave segun su identificador
      
      \pre Cada palabra clave tiene su identificador (la palabra clave 1 tiene
      id 0, la palabra clave 2 tiene id 1, etc). Este identificador ha de estar
      entre 0 y el numero de palabras clave. Ademas, la revista ha de haber
      sido inicializada previamente (a esta se le ha asignado un nombre, unas
      palabras clave y una calidad)

      \post El resultado es la palabra clave con identificador id
  */  

  string consultar_pal_clave(int id) const;

  /** @brief Consultora del nombre de la revista
      
      \pre La revista ha sido inicializada (a esta se le ha asignado
       un nombre, unas palabras clave y una calidad)

      \post El resultado es el nombre de la revista
  */  

  string consultar_nombre() const;

  /** @brief Consultora del indice de calidad de la revista
      
      \pre La revista ha sido inicializada (a esta se le ha asignado
       un nombre, unas palabras clave y una calidad)

      \post El resultado es el indice de calidad de la revista
  */  
  
  int consultar_calidad() const;

  /** @brief Consultora del area tematica segun el criterio de clasificacion 1
      
      \pre A la revista se le ha asignado previamente un area

      \post El resultado es el area segun el criterio de clasificacion 1
  */  

  string consultar_area_c1() const;

  /** @brief Consultora del area tematica segun el criterio de clasificacion 2
      
      \pre A la revista se le ha asignado previamente un area

      \post El resultado es el area segun el criterio de clasificacion 2
  */  

  string consultar_area_c2() const;

private:

  string name;

  string area_c1;

  string area_c2;

  int quality;

  list<string> keywords;

};

#endif
