#ifndef CONTA_H
#define CONTA_H

#include "Pessoa.h"
#include <string>
class Conta{
protected:
    Pessoa cliente;
    static int contador;
    int numeroConta;
    int senha;
    double saldo;

public:
    Conta(Pessoa p, int s);
    virtual void sacar(double valor);
    virtual void depositar(double valor);
    void depositarSimples(double valor);
    virtual void exibirTipo() const;
    int getNumeroConta();
    bool validarSenha(int s);
    double getSaldo();

    virtual ~Conta() = default;

    bool transferir(Conta &destino, double valor, int s);

    Conta(Pessoa p, int s, double sal = 0)
        : cliente(p), senha(s), saldo(sal)
    {
        numeroConta = 100000 + rand() % 900000;
    }

    int getNumeroConta() const { return numeroConta; }
};


#endif
