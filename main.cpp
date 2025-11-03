#include <iostream>
#include <vector>
#include <string>
#include "Pessoa.h"
#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

using namespace std;

int main() {
    vector<Conta*> contas;

    // Contas pré-criadas
    contas.push_back(new ContaCorrente(Pessoa("Sergio", "12345678900"), 1004, 500.0));
    contas.push_back(new ContaCorrente(Pessoa("Ivo", "98765432100"), 1002, 1000.0));
    contas.push_back(new ContaCorrente(Pessoa("J.Carlos", "98765432100"), 1003, 1000.0));
    contas.push_back(new ContaCorrente(Pessoa("J.Xavier", "98765432100"), 1005, 1000.0));
    contas.push_back(new ContaCorrente(Pessoa("Muniz", "98765432100"), 1006, 1000.0));
    contas.push_back(new ContaCorrente(Pessoa("Pimenta", "55566677788"), 1009, 250.0));

    cout << "Contas pré-criadas:\n";
    for (auto c : contas) {
        cout << "Conta " << c->getNumeroConta()
            << ", Saldo: " << c->getSaldo()
            << ", Tipo: ";
        c->exibirTipo();
    }

    int opcao;
    do {
        cout << "\n=== MENU BANCO ===\n";
        cout << "1 - Criar conta\n2 - Sacar\n3 - Depositar\n4 - Ver saldo\n5 - Transferir\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            string nome, cpf;
            int senha, tipo;
            cout << "Nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "CPF: ";
            getline(cin, cpf);
            cout << "Escolha sua senha (4 dígitos): ";
            cin >> senha;
            cout << "Tipo de conta (1-Corrente, 2-Poupança): ";
            cin >> tipo;

            Pessoa p(nome, cpf);
            Conta* c = nullptr;

            if (tipo == 1)
                c = new ContaCorrente(p, senha, 0.0);
            else if (tipo == 2)
                c = new ContaPoupanca(p, senha, 0.0);
            else {
                cout << "Tipo de conta inválido.\n";
                continue;
            }

            contas.push_back(c);
            cout << "Conta criada com sucesso! Número: " << c->getNumeroConta() << endl;
        }
        else if (opcao == 2) {
            int numero, senha;
            double valor;
            cout << "Número da conta: ";
            cin >> numero;
            cout << "Senha: ";
            cin >> senha;

            Conta* contaEncontrada = nullptr;
            for (auto c : contas) {
                if (c->getNumeroConta() == numero && c->validarSenha(senha)) {
                    contaEncontrada = c;
                    break;
                }
            }

            if (!contaEncontrada)
                cout << "Conta não encontrada ou senha incorreta.\n";
            else {
                cout << "Valor para saque: ";
                cin >> valor;
                contaEncontrada->sacar(valor);
            }
        }
        else if (opcao == 3) {
            int numero;
            double valor;
            cout << "Número da conta: ";
            cin >> numero;

            Conta* contaEncontrada = nullptr;
            for (auto c : contas) {
                if (c->getNumeroConta() == numero) {
                    contaEncontrada = c;
                    break;
                }
            }

            if (!contaEncontrada)
                cout << "Conta não encontrada.\n";
            else {
                cout << "Valor para depósito: ";
                cin >> valor;
                contaEncontrada->depositar(valor);
            }
        }
        else if (opcao == 4) {
            int numero, senha;
            cout << "Número da conta: ";
            cin >> numero;

            Conta* contaEncontrada = nullptr;
            for (auto c : contas) {
                if (c->getNumeroConta() == numero) {
                    contaEncontrada = c;
                    break;
                }
            }

            if (!contaEncontrada)
                cout << "Conta não encontrada.\n";
            else {
                cout << "Senha: ";
                cin >> senha;
                if (contaEncontrada->validarSenha(senha))
                    cout << "Saldo atual: " << contaEncontrada->getSaldo() << endl;
                else
                    cout << "Senha incorreta.\n";
            }
        }
        else if (opcao == 5) {
            int numOrigem, numDestino, senha;
            double valor;

            cout << "Número da conta de origem: ";
            cin >> numOrigem;

            Conta* origem = nullptr;
            for (auto c : contas) {
                if (c->getNumeroConta() == numOrigem) {
                    origem = c;
                    break;
                }
            }

            if (!origem) {
                cout << "Conta de origem não encontrada.\n";
                continue;
            }

            cout << "Número da conta de destino: ";
            cin >> numDestino;

            Conta* destino = nullptr;
            for (auto c : contas) {
                if (c->getNumeroConta() == numDestino) {
                    destino = c;
                    break;
                }
            }

            if (!destino) {
                cout << "Conta de destino não encontrada.\n";
                continue;
            }

            cout << "Valor a transferir: ";
            cin >> valor;
            cout << "Confirme sua senha: ";
            cin >> senha;

            if (origem->transferir(*destino, valor, senha))
                cout << "Transferência realizada com sucesso!\n";
            else
                cout << "Senha incorreta ou saldo insuficiente.\n";
        }

    } while (opcao != 0);

    for (auto c : contas)
        delete c;

    cout << "Programa encerrado." << endl;
    return 0;
}
