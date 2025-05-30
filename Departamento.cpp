#include "Departamento.h"


Departamento::Departamento(int i, const char* n):
    id(i),
    nome(n)
{
}

Departamento::~Departamento()
{
}

int Departamento::getId()
{
    return id;
}

const string Departamento::getNome() const
{
    return nome;
}
