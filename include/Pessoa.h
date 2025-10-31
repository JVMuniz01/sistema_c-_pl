#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa {
private:
    string nome;
    string cpf;

public:
    Pessoa(string n, string c);
    string getNome();
    string getCpf();
};

#endif
