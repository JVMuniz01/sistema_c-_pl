#include "Conta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Conta::sacar(double valor) {
    if(valor > saldo) {
        cout << "Saldo insuficiente. Sacando todo o saldo disponível: " << saldo << endl;
        saldo = 0;
    } else {
        saldo -= valor;
        cout << "Saque realizado com sucesso. Novo saldo: " << saldo << endl;
    }
}
void Conta::depositar(double valor) {
    saldo += valor;
    cout << "Depósito realizado com sucesso. Novo saldo: " << saldo << endl;
}
void Conta::depositarSimples(double valor) {
    saldo += valor;
    cout << "Depósito realizado com sucesso. Novo saldo: " << saldo << endl;
}

bool Conta::transferir(Conta &destino, double valor, int s) {
    if(!validarSenha(s)) {
        return false;
    }
    
    if(valor > saldo) {
        return false;
    }

    saldo -= valor;
    destino.depositarSimples(valor);
    return true;
}

void Conta::exibirTipo() const {
    std::cout << "Conta genérica" << std::endl;
}

int Conta::getNumeroConta() {
    return numeroConta;
}

bool Conta::validarSenha(int s) {
    return s == senha;
}

double Conta::getSaldo() {
    return saldo;
}
