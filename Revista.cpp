/** @file Revista.cpp
    @brief Implementacion de la clase Revista
*/

#include "Revista.hpp"

Revista::Revista()
{  
}

void Revista::leer_revista()
{

    cin >> name;

    string palabra;

    list<string>::iterator it = keywords.begin();

    while (cin >> palabra and palabra != ".") {

        keywords.insert(it, palabra);

    }

    quality  = readint();

}

void Revista::anadir_pal_clave(string s)
{

    list<string>::iterator it = keywords.begin();

    bool insertada = false;

    bool repetida = false;

    while (it != keywords.end() and not insertada and not repetida) {

        if ((*it) > s) {

            keywords.insert(it, s);

	    insertada = true;

	}

        else if ((*it) == s) repetida = true;

        else ++it;

    }

    if (not insertada and not repetida) keywords.insert(it, s);

}   

void Revista::asignar_area_c1(string s)
{

    area_c1 = s;

}

void Revista::asignar_area_c2(string s)
{


    area_c2 = s;

}

int Revista::consultar_num_pal_clave() const
{

    return keywords.size();

}

string Revista::consultar_pal_clave(int id) const
{

    list<string>::const_iterator it = keywords.begin();

    while (id > 0) {

        ++it;

        --id;

    }

    return *it;

}

string Revista::consultar_nombre() const
{

    return name;

}

int Revista::consultar_calidad() const
{

  return quality;

}

string Revista::consultar_area_c1() const
{

    return area_c1;

}

string Revista::consultar_area_c2() const
{

    return area_c2;

}
