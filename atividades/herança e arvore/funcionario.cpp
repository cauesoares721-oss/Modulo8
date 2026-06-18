#include <iostream>
#include <string>

using namespace std;

class Funcionario {
protected:
    string nome;
    float salario;

public:
    Funcionario(string n, float s) : nome(n), salario(s) {}

    virtual void mostrarSalario() {
        cout << "Funcionario: " << nome << endl;
        cout << "Salario: R$ " << salario << endl;
    }
};

class Gerente : public Funcionario {
public:
    Gerente(string n, float s) : Funcionario(n, s) {}

    void mostrarSalario() override {
        float salarioComBonus = salario * 1.20;

        cout << "Gerente: " << nome << endl;
        cout << "Salario com bonus de 20%: R$ " << salarioComBonus << endl;
    }
};

int main() {
    Funcionario f("Joao", 3000);
    Gerente g("Maria", 5000);

    f.mostrarSalario();
    cout << endl;
    g.mostrarSalario();

    return 0;
};
