#include "ContaPoupanca.h"
#include <iostream>
using namespace std;

ContaPoupanca::ContaPoupanca(Pessoa p, int s, double sal, double bonus)
    : Conta(p, s, sal), bonusDeposito(bonus) {}

void ContaPoupanca::depositar(double valor) {
    double rendimento = valor * bonusDeposito;
    saldo += valor + rendimento;
    cout << "Depósito de R$" << valor << " com rendimento de R$" << rendimento
        << ". Saldo atual: R$" << saldo << endl;
}

void ContaPoupanca::exibirTipo() const {
    cout << "Conta Poupança\n";
}
