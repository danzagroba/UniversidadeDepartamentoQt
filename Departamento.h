#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_
using namespace std;

#include <string>

class Departamento
{
private:
    int id;
    string nome;

public:
    Departamento(int i, const char* n);
    ~Departamento();

    int getId();
    const string getNome() const;
};

#endif
