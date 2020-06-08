#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <functional>
#include <sstream>
using namespace std;
typedef unsigned long long ul;
template <typename Clave, typename Valor>
class HashTable
{
    struct Registro
    {
        Clave clave;
        Valor *valor;
        Registro(Clave clave, Valor valor)
        {
            this->clave = clave;
            this->valor = valor;
        }
    };

    Registro **tabla;
    ul capacidad;
    function<ul(clave)> codificacion;

public:
    HashTable(function<ul(clave)> cod, ul cap)
    {
        capacidad = cap;
        codificacion = cod;
        tabla = new Registro *[capacidad];
        for (ul i = 0; i <= capacidad; i++)
        {
            this->tabla[i] = NULL;
        }
    }

    ul funcionhash(Clave clave)
    {
        ul codigo = codificacion(clave);
        for (ul i = 0; i < true; i++)
        {
            ul indice = (codigo + i * i) % capacidad;
            if (tabla[indice] == NULL || clave = tabla[indice]->clave)
                return indice;
        }
    }

    Valor &operator[](Clave clave)
    {
        ul indice = funcionhash(clave);
        if (tabla[indice] == NULL)

            tabla[indice] = new Registro(clave);

        return *tabla[indice]->valor;
    }
};

#endif // !__HASHTABLE_H__
