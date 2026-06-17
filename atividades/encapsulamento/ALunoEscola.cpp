#include <iostream>
#include <vector>

using namespace std;

// Classe Aluno
class Aluno {
private:
    string nome;
    int idade;
    string curso;

public:
    // Getters
    string getNome() {
        return nome;
    }

    int getIdade() {
        return idade;
    }

    string getCurso() {
        return curso;
    }

    // Setters
    void setNome(string n) {
        nome = n;
    }

    void setIdade(int i) {
        idade = i;
    }

    void setCurso(string c) {
        curso = c;
    }

    // Método para apresentar os dados
    void apresentar() {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Curso: " << curso << endl;
        cout << "------------------------" << endl;
    }
};

// Classe Escola
class Escola {
private:
    string nome;
    vector<Aluno> alunos;

public:
    // Getter
    string getNome() {
        return nome;
    }

    // Setter
    void setNome(string n) {
        nome = n;
    }

    // Adiciona um aluno à lista
    void adicionarAluno(Aluno aluno) {
        alunos.push_back(aluno);
    }

    // Lista todos os alunos
    void listarAlunos() {
        if (alunos.empty()) {
            cout << "Nenhum aluno matriculado." << endl;
        } else {
            cout << "Escola: " << nome << endl;
            cout << "Lista de Alunos:" << endl;

            for (int i = 0; i < alunos.size(); i++) {
                alunos[i].apresentar();
            }
        }
    }
};

int main() {

    // Criando a escola
    Escola escola;
    escola.setNome("Escola Futuro");

    // Criando o primeiro aluno
    Aluno aluno1;
    aluno1.setNome("Joao");
    aluno1.setIdade(18);
    aluno1.setCurso("Informatica");

    // Criando o segundo aluno
    Aluno aluno2;
    aluno2.setNome("Maria");
    aluno2.setIdade(19);
    aluno2.setCurso("Eletrotecnica");

    // Adicionando os alunos à escola
    escola.adicionarAluno(aluno1);
    escola.adicionarAluno(aluno2);

    // Exibindo a lista de alunos
    escola.listarAlunos();

    // Testando alteração com setters
    aluno1.setNome("Joao Pedro");
    aluno1.setIdade(20);

    cout << "\nDados atualizados do primeiro aluno:" << endl;
    aluno1.apresentar();

    return 0;
}