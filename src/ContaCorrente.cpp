#include "ContaCorrente.h"
#include <iostream>
using namespace std;

ContaCorrente::ContaCorrente(Pessoa p, int s, double sal, double taxa)
    : Conta(p, s, sal), taxaSaque(taxa) {}

void ContaCorrente::sacar(double valor) {
    double total = valor + taxaSaque;
    if (total > saldo)
        cout << "Saldo insuficiente para saque + taxa.\n";
    else {
        saldo -= total;
        cout << "Saque de R$" << valor << " realizado com taxa de R$" << taxaSaque
            << ". Saldo atual: R$" << saldo << endl;
    }
}

void ContaCorrente::exibirTipo() const {
    cout << "Conta Corrente\n";
}
