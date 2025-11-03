#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta
{
private:
    double taxaSaque;

protected:
double saldo;

public:
    ContaCorrente(Pessoa p, int s, double sal = 0.0, double taxa = 2.5);
    void exibirTipo() const override;
};

#endif
