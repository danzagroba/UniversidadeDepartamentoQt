#include "Universidade.h"

Universidade::Universidade(int idd, const char* n):
    nome(n),
    id(idd),
    ObjLDepartamentos()
{
}

Universidade::~Universidade()
{
    while (!ObjLDepartamentos.empty()) {
        delete ObjLDepartamentos.back();
        ObjLDepartamentos.pop_back();
    }
}

const string Universidade::getNome()
{
    return nome;
}

void Universidade::setDepartamento (Departamento* d)
{
    ObjLDepartamentos.push_back(d);
}

void Universidade::listeDepartamentos()
{
    int tam = (int)ObjLDepartamentos.size();
    for (int i = 0; i < tam; i++)
    {
        cout << (ObjLDepartamentos[i])->getNome() << endl;
    }
}

vector<Departamento*>::iterator Universidade::getDepartamentosBegin()
{
    return ObjLDepartamentos.begin();
}

vector<Departamento*>::iterator Universidade::getDepartamentosEnd()
{
    return ObjLDepartamentos.end();
}

int Universidade::getId()
{
    return id;
}
