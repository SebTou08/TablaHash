#include <iostream>
#include <string>
#include <functional>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef unsigned long long ul;

template <typename Clave, typename Valor>

class Hashtable
{
    struct Registro
    {
        Clave clave;
        Valor *valor; //valor podria ser todo un objeto o una estructura
        Registro(Clave clave, Valor *valor = new Valor)
        {
            this->clave = clave;
            this->valor = valor;
        }
    };

    Registro **tabla;
    ul capacidad;
    function<ul(Clave)> codificacion;

public:
    Hashtable(function<ul(Clave)> cod, ul cap)
    {
        capacidad = cap; //TODO PRIMO SIGUIENTE
        codificacion = cod;
        tabla = new Registro *[capacidad];
        for (ul i = 0; i <= capacidad; ++i)
        {
            this->tabla[i] = NULL;
        }
    }

    ul funcionHash(Clave clave)
    {
        ul codigo = codificacion(clave);
        for (ul i = 0; true; ++i)
        {
            ul indice = (codigo + i * i) % capacidad;
            if (tabla[indice] == NULL || clave == tabla[indice]->clave)
                return indice;
        }
    }

    Valor &operator[](Clave clave)
    {
        ul indice = funcionHash(clave);
        //operacion de escritura
        if (tabla[indice] == NULL) //no fue encontrado
            tabla[indice] = new Registro(clave);
        //operacion de lectura
        return *tabla[indice]->valor;
    }
};
//TODO: implementar la clase aparte
ul codificacionString(string clave)
{
    ul codigo = 0; //codigo me retornará la codificación
    for (ul i = 0; clave[i] != '\0'; ++i)
    {
        codigo += clave[i] * (ul)pow(27, 1);
    }

    return codigo;
}

ul codificacionInt(int clave)
{
    ul codigo = (ul)(clave * clave);
    return codigo;
}

int main()
{
    srand(time(NULL));
    string names[4] = {"pepe", "lucho", "rosa", "ariana"};
    Hashtable<string, double> objHT(codificacionString, 10);
    //objHT["Mara"] = 12.875;
    double d = objHT["Mara"];

    for (size_t i = 0; i < 15; i++)
    {
        objHT["Mara"] = 12.875 + i * 74.652;
        double d = objHT["Mara"];
        cout << endl;
        cout << d;
    }


cout<<endl<<endl;
   Hashtable<string, string> objHT2(codificacionString, 10);
   objHT2["sebas"]="Sebastian Toulier Funes";
    objHT2["ari"]="Ariana Carrasco";
     objHT2["ro"]="Rosa Pereda";
   string res = objHT2["sebas"];
   cout<<res;
   res = objHT2["ari"];
   cout<<endl<<res;
   res = objHT2["ro"];
   cout<<endl<<res;
    cin.get();
    return 0;
}