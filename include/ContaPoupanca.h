#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta
{
private:
    double bonusDeposito;
protected:
double saldo;

public:
    ContaPoupanca(Pessoa p, int s, double sal = 0.0, double bonus = 0.02);
    void depositar(double valor) override;
    void exibirTipo() const override;
};

#endif
