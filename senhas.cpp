#include <iostream>
#include <string>

using namespace std;

int main() {

    string login, loginCorreto = "admin";
    int senha, senhaCorreta = 1234;
    int tentativas = 0;
    bool acesso = false;

    do {
        try {
            cout << " SISTEMA DE LOGIN " << endl;

            cout << "Login: ";
            cin >> login;

            cout << "Senha: ";
            cin >> senha;

            if (cin.fail()) {
                throw "A senha deve ser um numero!";
            }

            if (login == loginCorreto && senha == senhaCorreta) {
                cout << "\nAcesso permitido!" << endl;
                acesso = true;
            } else {
                cout << "\nLogin ou senha incorretos!" << endl;
            }

        } catch (const char *erro) {
            cout << "\nErro: " << erro << endl;

            cin.clear();
            cin.ignore(1000, '\n');
        }

        tentativas++;

    } while (!acesso && tentativas < 3);

    if (!acesso) {
        cout << "\nNumero maximo de tentativas atingido!" << endl;
    }

    return 0;
}