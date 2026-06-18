#include <iostream>
#include <string>

using namespace std;

// Classe base
class Produto {
protected:
    string nome;
    float preco;

public:
    Produto(string n, float p) {
        nome = n;
        preco = p;
    }

    void mostrarProduto() {
        cout << "Nome: " << nome << endl;
        cout << "Preco: R$ " << preco << endl;
    }
};

// Subclasse Livro
class Livro : public Produto {
private:
    string autor;

public:
    Livro(string n, float p, string a) : Produto(n, p) {
        autor = a;
    }

    void mostrarLivro() {
        mostrarProduto();
        cout << "Autor: " << autor << endl;
    }
};

// Subclasse Eletronico
class Eletronico : public Produto {
private:
    string marca;

public:
    Eletronico(string n, float p, string m) : Produto(n, p) {
        marca = m;
    }

    void mostrarEletronico() {
        mostrarProduto();
        cout << "Marca: " << marca << endl;
    }
};

int main() {

    // Objetos da classe Livro
    Livro livro1("Dom Casmurro", 45.90, "Machado de Assis");
    Livro livro2("O Pequeno Principe", 30.00, "Antoine de Saint-Exupery");

    // Objetos da classe Eletronico
    Eletronico eletronico1("Notebook", 3500.00, "Dell");
    Eletronico eletronico2("Celular", 2500.00, "Samsung");

    cout << "=== Livros ===" << endl;
    livro1.mostrarLivro();
    cout << endl;
    livro2.mostrarLivro();

    cout << "\n=== Eletronicos ===" << endl;
    eletronico1.mostrarEletronico();
    cout << endl;
    eletronico2.mostrarEletronico();

    return 0;
}