/** @file Biblioteca.cpp
    @brief Implementacion de la clase Biblioteca
*/

#include "Biblioteca.hpp"

Biblioteca::Biblioteca(int N)
{

    biblio = vector< list<Revista> >(N);

    biblio2 = vector< list< pair<string, string> > >(N);

}

void Biblioteca::busca_biblio(string nombre, int &cal, bool &trobat, int &pos)
{

    trobat = false;

    int i = 0; 

    while (i < biblio.size() and not trobat) {

        list<Revista>::iterator it = biblio[i].begin();

        pos = 0;

        while (it != biblio[i].end() and not trobat) {

            if ((*it).consultar_nombre() == nombre) {

	        trobat = true;

		cal = i+1;

	    }

            else {

	        ++it;

                ++pos;

	    }

	}

        ++i;

    }

}

int Biblioteca::busca_biblio2(string nombre, int cal)
{

    int pos = 0;

    bool trobat = false;

    list< pair<string, string> >::iterator it = biblio2[cal-1].begin();

    while (it != biblio2[cal-1].end() and not trobat) {

        if ((*it).second == nombre) trobat = true;

        else {

	    ++it;

            ++pos;

	}
	
    }
    
    return pos;
    
}

void Biblioteca::anadir_revista(Revista &r, Jerarquiarea &j)
{

    string a1 = j.calcular_area_c1(r);

    r.asignar_area_c1(a1);

    string a2 = j.calcular_area_c2(r);

    r.asignar_area_c2(a2);

    string nombre = r.consultar_nombre();

    int cal = r.consultar_calidad();

    list<Revista>::iterator it = biblio[cal-1].begin(); // Anadimos en biblio la revista

    if (biblio[cal-1].empty()) biblio[cal-1].insert(it, r);

    else {

        bool insertada = false;

        while (it != biblio[cal-1].end() and not insertada) {

            if ((*it).consultar_area_c1() > a1) {

                biblio[cal-1].insert(it, r);

                insertada = true;

	    }

	    else if ((*it).consultar_area_c1() == a1 and (*it).consultar_nombre() > nombre) {

	        biblio[cal-1].insert(it, r);

                insertada = true;

	    }

	    else ++it;

	}

        if (not insertada) biblio[cal-1].insert(it, r);

    } // Anadimos en biblio2 el pair con el area segun criterio 2 y el nombre

    list< pair<string, string> >::iterator it2 = biblio2[cal-1].begin();

    pair<string, string> p;
    
    p.first = r.consultar_area_c2();
    
    p.second = nombre;

    if (biblio2[cal-1].empty()) biblio2[cal-1].insert(it2, p);

    else {

        bool insertado = false;

        while (it2 != biblio2[cal-1].end() and not insertado) {

	    if ((*it2).first > p.first) {

                biblio2[cal-1].insert(it2, p);

                insertado = true;

	    }

	    else if ((*it2).first == p.first and (*it2).second > p.second) {

	        biblio2[cal-1].insert(it2, p);

                insertado = true;

	    }

	    else ++it2;

	}

        if (not insertado) biblio2[cal-1].insert(it2, p);

    }

}

void Biblioteca::consultar_revista(string nombre)
{

    cout << "Consulta de revista por titulo" << endl;

    int pos, cal;

    bool trobat;

    busca_biblio(nombre, cal, trobat, pos);

    if (trobat) {

        cout << nombre << endl;

        list<Revista>::iterator it = biblio[cal-1].begin();

        while (pos > 0) {

	    ++it;

            --pos;

	}

        int num_pal_clave = (*it).consultar_num_pal_clave();

        for (int i = 0; i < num_pal_clave; ++i) {

            string pal_clave = (*it).consultar_pal_clave(i);

            cout << pal_clave << " ";

	}

        cout << endl;

        string a1 = (*it).consultar_area_c1();

        string a2 = (*it).consultar_area_c2();

        cout << a1 << " " << a2 << endl;

        cout << cal << endl;

    }
 
    else cout << "La revista " << nombre << " no existe" << endl;

    cout << endl;

}

void Biblioteca::eliminar_revista(string nombre)
{

    int pos, cal;

    bool trobat;

    busca_biblio(nombre, cal, trobat, pos);

    list<Revista>::iterator it = biblio[cal-1].begin();

    while (pos > 0) {

        ++it;

        --pos;

    }

    biblio[cal-1].erase(it);

    pos = busca_biblio2(nombre, cal);

    list< pair<string, string> >::iterator it2 = biblio2[cal-1].begin();

    while (pos > 0) {

        ++it2;

        --pos;

    }

    biblio2[cal-1].erase(it2);

}

void Biblioteca::listado(int calidad, int criterio)
{

    cout << "Revistas de calidad " << calidad << " por criterio " << criterio << endl;

    if (criterio == 1) {

        list<Revista>::iterator it = biblio[calidad-1].begin();

        while (it != biblio[calidad-1].end()) {

            string area = (*it).consultar_area_c1();

	    string nombre = (*it).consultar_nombre();

	    cout << area << " " << nombre << endl;

            ++it;

	}

    }

    else { // criterio = 2

        list< pair<string, string> >::iterator it2 = biblio2[calidad-1].begin();
    
        while (it2 != biblio2[calidad-1].end()) {

	    string area = (*it2).first;

            string nombre = (*it2).second;

            cout << area << " " << nombre << endl;

            ++it2;

	}

    }

    cout << endl;

}

void Biblioteca::fusionar_revistas(string nombre, string nombre2, Jerarquiarea &j)
{

    int pos, pos2, cal, cal2;

    bool trobat;

    busca_biblio(nombre, cal, trobat, pos);

    busca_biblio(nombre2, cal2, trobat, pos2);

    list<Revista>::iterator it = biblio[cal-1].begin();

    list<Revista>::iterator it2 = biblio[cal2 - 1].begin();

    while (pos > 0) {

        ++it;

	--pos;

    }

    while (pos2 > 0) {

        ++it2;

        --pos2;

    }

    int num_pal_clave = (*it2).consultar_num_pal_clave();

    for (int i = 0; i < num_pal_clave; ++i) (*it).anadir_pal_clave((*it2).consultar_pal_clave(i));

    eliminar_revista(nombre2);
  
    Revista r = (*it);

    eliminar_revista(nombre);

    anadir_revista(r, j);

}
