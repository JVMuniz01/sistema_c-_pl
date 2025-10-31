#include "Conta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Construtor
Conta::Conta(Pessoa p, int s) : cliente(p), saldo(0.0) {
    srand(time(0));
    numeroConta = 100000 + rand() % 900000;
    senha = s;
}

// Sacar dinheiro
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

int Conta::getNumeroConta() {
    return numeroConta;
}

bool Conta::validarSenha(int s) {
    return s == senha;
}

double Conta::getSaldo() {
    return saldo;
}
