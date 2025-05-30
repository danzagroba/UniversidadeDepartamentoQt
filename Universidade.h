#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

#include <iostream>
#include <vector>

#include "Departamento.h"

class Universidade
{
private:
    string nome;
    int id;
    //Lista<Departamento> ObjLDepartamentos;
    std::vector<Departamento*> ObjLDepartamentos;

public:
    Universidade(int idd, const char* n);
    ~Universidade();

    const string getNome();

    void setDepartamento(Departamento* d);
    void listeDepartamentos();

    vector<Departamento*>::iterator getDepartamentosBegin();
    vector<Departamento*>::iterator getDepartamentosEnd();
    int getId();

};

#endif
