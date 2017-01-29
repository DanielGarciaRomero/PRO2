/** @file Jerarquiarea.cpp
    @brief Implementacion de la clase Jerarquiarea
*/

#include "Jerarquiarea.hpp"

Jerarquiarea::Jerarquiarea()
{
}

void Jerarquiarea::leer_jerarquia()
{
    leer_arbol(a);

}

void Jerarquiarea::leer_arbol(Arbre<string> &a) 
{

    Arbre<string> a1;

    Arbre<string> a2;

    string s;

    cin >> s;

    if (s != ".") {

        leer_arbol(a1);

	leer_arbol(a2);

	a.plantar(s, a1, a2);

    }

}

void Jerarquiarea::insertar_ordenadamente(list<string> &l, string s) {

    list<string>::iterator it = l.begin();

    if (l.empty()) l.insert(it, s);

    else {
     
        bool insertada = false;
     
	bool repetida = false;
     
	while (it != l.end() and not insertada and not repetida) {
       
	    if ((*it) == s) repetida = true;
       
            else if ((*it) > s) {
	 
	        l.insert(it, s);
	 
	        insertada = true;
	 
	    }
       
	    else ++it;
       
	}
     
	if (not insertada and not repetida) l.insert(it, s);
     
    }
   
}

pair<string, int> Jerarquiarea::inmersion_c1(Arbre<string> &a, vector<string> &v, list<string> &l, int &prof) {

    pair <string, int> p("", prof);

    if (not a.es_buit()) { // caso base

        string raiz = a.arrel();

	Arbre<string> a1, a2;

	a.fills(a1, a2);

	if (a1.es_buit() and a2.es_buit()) { // si no tiene hijos, la revista solo tiene
	                                     // una palabra clave y la raiz es esa
                                             // palabra clave, la raiz es el area que buscamos

	    if (v.size() == 1 and raiz == v[0]) {

                p.first = raiz;

                list<string>::iterator it = l.begin();

                l.insert(it, raiz);

	    }

            else { // la raiz ya no puede ser el area porque no puede incluir al
                   // menos una aparicion de todas las palabras clave de la revista

                int i = 0;

		bool pal_clave = false;

		while (i < v.size() and not pal_clave) {

		    if (v[i] == raiz) {

	                pal_clave = true;

                        insertar_ordenadamente(l, raiz);

		    }

		    else ++i; 

		}

	    }

	}

	else { 

	    int prof_hijos = prof + 1;

	    list<string> l2;

	    pair<string, int> p1 = inmersion_c1(a1, v, l, prof_hijos);

	    pair<string, int> p2 = inmersion_c1(a2, v, l2, prof_hijos);

            if (l.size() != v.size() and l2.size() != v.size()) {

	        list<string>::iterator it = l2.begin();

                while (it != l2.end()) { // Concatenamos las listas

		    insertar_ordenadamente(l, (*it)); 

                    ++it;

		}

                if (l.size() == v.size()) p.first = raiz;

	    }

            else if (l.size() == v.size() and l2.size() != v.size()) {

	        p.first = p1.first;

                p.second = p1.second;

	    }

            else if (l.size() != v.size() and l2.size() == v.size()) {

	        p.first = p2.first;

                p.second = p2.second;

                l = l2;

	    }

            else if (l.size() == v.size() and l2.size() == v.size()) {

                if (p1.second > p2.second) {

		    p.first = p1.first;

		    p.second = p1.second;
		  
		}
		
		else if (p2.second > p1.second) {
		  
		    p.first = p2.first;
		  
		    p.second = p2.second;
		  
		} 
		
		else { // p1.second = p2.second
		  
	            if (p1.first < p2.first) {
		    
		        p.first = p1.first;
		    
		        p.second = p1.second;
		    
		    }
		  
		    else {
		    
		        p.first = p2.first;
		    
		        p.second = p2.second;
		    
		    }

		}

	    }

	}

        a.plantar(raiz, a1, a2);

	return p;

    }

}

pair <bool, string> Jerarquiarea::inmersion_c2(Arbre<string> &a, vector<string> &v)
{ // el bool indica si en algun subarbol de a hay una palabra clave y, en ese 
  // caso, el string es el area asociada a la revista para el arbol a

    pair<bool, string> p (false, "");

    if (not a.es_buit()) { // caso base

        string raiz = a.arrel();

        Arbre<string> a1, a2;

        a.fills(a1, a2);

        if (a1.es_buit() and a2.es_buit()) { // si no tiene hijos y la raiz es palabra
                                             // clave, la raiz es el area que buscamos

	    int i = 0;

            while (i < v.size() and not p.first) {

	        if (v[i] == raiz) {

                    p.first = true;

                    p.second = raiz;

		}

		else ++i;

	    }

	}

        else {

	    pair<bool, string> p1 = inmersion_c2(a1, v);

            pair<bool, string> p2 = inmersion_c2(a2, v);

            p.first = (p1.first or p2.first);

            if (p.first) {

	        if (p1.first and p2.first) p.second = raiz;

                else if (p1.first and not p2.first) p.second = p1.second;

                else if (not p1.first and p2.first) p.second = p2.second;

	    }

	}

        a.plantar(raiz, a1, a2);
 
        return p;

    }

}

string Jerarquiarea::calcular_area_c1(Revista &r)
{
    vector<string > v(r.consultar_num_pal_clave()); 

    int i = 0;

    while (i < v.size()) {

        v[i] = r.consultar_pal_clave(i);

        ++i;

    }

    int prof = 0;

    list<string> l;

    pair<string, int> p = inmersion_c1(a, v, l, prof);

    return p.first; 

}

string Jerarquiarea::calcular_area_c2(Revista &r)
{

    vector<string > v(r.consultar_num_pal_clave());

    int i = 0;

    while (i < v.size()) {

        v[i] = r.consultar_pal_clave(i);

        ++i;

    }

    pair<bool, string> p = inmersion_c2(a, v);

    return p.second;

}
