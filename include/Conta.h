#ifndef CONTA_H
#define CONTA_H

#include "Pessoa.h"
#include <string>

class Conta {
private:
    Pessoa cliente;
    int numeroConta;
    int senha;
    double saldo;

public:
    Conta(Pessoa p, int s);
    void sacar(double valor);
    void depositar(double valor);
    int getNumeroConta();
    bool validarSenha(int s);
    double getSaldo();
};

#endif
