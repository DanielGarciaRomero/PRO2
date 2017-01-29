/** @file Biblioteca.hpp
    @brief Especificacion de la clase Biblioteca
*/

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Revista.hpp"
#include "Jerarquiarea.hpp"

/** @class Biblioteca
    @brief Contiene revistas
*/

class Biblioteca {

public:

  /** @brief Creadora por defecto
      
      \pre Cierto

      \post El resultado es una biblioteca vacia cuyas revistas tienen
       indice de calidad maximo N

  */   

  Biblioteca(int N);

  /** @brief Alta de revista
      
      \pre La biblioteca no contiene la revista y el indice de calidad de
       esta esta entre 1 y N y sus palabras clave estan ordenadas
       alfabeticamente. La jerarquia no ha de estar vacia

      \post La biblioteca pasa a contener la revista y a esta se le asignan 
       dos areas tematicas, una para cada uno de los dos criterios de 
       clasificacion

  */  

  void anadir_revista(Revista &r, Jerarquiarea &j);

  /** @brief Consulta de revista por titulo
      
      \pre Cierto

      \post Si la revista esta en la biblioteca, se escribe su titulo, sus palabras 
       clave (en orden alfabetico), sus areas tematicas (criterio 1 y criterio 2, 
       respectivamente) y su indice de calidad. Si la revista no se encuentra en la
       biblioteca, se escribe el titulo y se indica que no existe

  */  

  void consultar_revista(string nombre);

   /** @brief Baja de revista
      
      \pre Existe una revista en la biblioteca con titulo = nombre

      \post La revista con dicho titulo desaparece de la biblioteca

  */  

  void eliminar_revista(string nombre);

   /** @brief Consulta de revistas por nivel de calidad y criterio
      
      \pre 1 <= calidad <= N; 1 <= criterio <= 2

      \post Se escribe el area (dependiendo del criterio solicitado sera
       uno u otro) y el titulo de las revistas de la biblioteca cuyo 
       indice de calidad sea igual al especificado. El orden de salida
       de los datos mencionados anteriormente sera alfabetico por area y,
       dentro de cada area, por nombre de la revista

  */  

  void listado(int calidad, int criterio);

  /** @brief Fusion de revistas
      
      \pre nombre1 != nombre2 y existen dos revistas r1 y r2 en la biblioteca
       tales que el titulo de r1 es nombre1 y el titulo de r2 es nombre2.
       La jerarquia no ha de estar vacia

      \post A la revista con titulo igual a nombre1 se le añaden las palabras
       clave de la revista con titulo igual a nombre2 y se le asignan dos
       nuevas areas tematicas, una para cada criterio, ya que ahora puede que
       esta tenga una palabra clave nueva. La revista con titulo igual a 
       nombre2 se elimina de la biblioteca

  */  

  void fusionar_revistas(string nombre1, string nombre2, Jerarquiarea &j);

private:

  vector< list<Revista> > biblio;

  vector< list< pair<string, string> > > biblio2;

   /** @brief Busca una revista en biblio sabiendo solo el titulo de esta
      
      \pre Cierto

      \post trobat indica si existe la revista en biblio y, en caso afirmativo,
       pos indica la posicion donde esta la revista en la lista de revistas
       y cal indica su indice de calidad

  */  

  void busca_biblio(string nombre, int &cal, bool &trobat, int &pos);

   /** @brief Busca una revista en biblio2 sabiendo titulo y calidad de esta
      
      \pre En biblio2 existe una revista (los pairs simbolizan revistas, de las 
       cuales solo almacenamos su titulo y su area segun el criterio 2) con el
       titulo y la calidad solicitados

      \post El resultado es la posicion donde se encuentra la revista en la lista
       de revistas de calidad cal

  */  

  int busca_biblio2(string nombre, int cal);

};

#endif
