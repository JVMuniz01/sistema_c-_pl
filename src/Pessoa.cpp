#include "Pessoa.h"

Pessoa::Pessoa(string n, string c) {
    nome = n;
    cpf = c;
}

string Pessoa::getNome() {
    return nome;
}

string Pessoa::getCpf() {
    return cpf;
}
