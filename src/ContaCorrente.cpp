#include "ContaCorrente.h"
#include <iostream>
using namespace std;

ContaCorrente::ContaCorrente(Pessoa p, int s, double sal, double taxa)
    : Conta(p, s, sal), taxaSaque(taxa) {}

void ContaCorrente::exibirTipo() const {
    cout << "Conta Corrente\n";
}