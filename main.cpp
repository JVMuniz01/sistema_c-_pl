#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Conta.h"
using namespace std;

int main() {
    vector<Conta> contas;
    int opcao;

    do {
        cout << "\n=== MENU BANCO ===\n";
        cout << "1 - Criar conta\n2 - Sacar\n3 - Depositar\n4 - Ver saldo\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        if(opcao == 1) {
            string nome, cpf;
            int senha;
            cout << "Nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "CPF: ";
            getline(cin, cpf);
            cout << "Escolha sua senha (4 dígitos): ";
            cin >> senha;

            Pessoa p(nome, cpf);
            Conta c(p, senha);
            contas.push_back(c);

            cout << "Conta criada com sucesso!\nNúmero da conta: " << c.getNumeroConta() << endl;

        } else if(opcao == 2) {
            int numero, senha;
            double valor;
            cout << "Número da conta: ";
            cin >> numero;
            cout << "Senha: ";
            cin >> senha;

            bool encontrado = false;
            for(auto &c : contas) {
                if(c.getNumeroConta() == numero && c.validarSenha(senha)) {
                    encontrado = true;
                    cout << "Valor para saque: ";
                    cin >> valor;
                    c.sacar(valor);
                    break;
                }
            }
            if(!encontrado) cout << "Conta não encontrada ou senha incorreta.\n";

        } else if(opcao == 3) {
            int numero;
            double valor;
            cout << "Número da conta: ";
            cin >> numero;

            bool encontrado = false;
            for(auto &c : contas) {
                if(c.getNumeroConta() == numero) {
                    encontrado = true;
                    cout << "Valor para depósito: ";
                    cin >> valor;
                    c.depositar(valor);
                    break;
                }
            }
            if(!encontrado) cout << "Conta não encontrada.\n";
        } else if(opcao == 4) {
            int numero, senha;
            cout << "Número da conta: ";
            cin >> numero;
            bool encontrado = false;
            Conta* contaEncontrada = nullptr;
            for(auto &c : contas) {
                if(c.getNumeroConta() == numero){
                    contaEncontrada = &c;
                    break;
                }
            }
            if(contaEncontrada == nullptr){
                cout << "Conta não encontrada.\n";
            }else{
                int senha;
                cout << "Senha: ";
                cin >> senha;
                if(contaEncontrada->validarSenha(senha)) {
                    cout << "Saldo atual: " << contaEncontrada->getSaldo() << endl;
            }else{
                cout << "Senha incorreta.\n";
            }
        }
    }

    } while(opcao != 0);

    cout << "Programa encerrado." << endl;
    return 0;
}
