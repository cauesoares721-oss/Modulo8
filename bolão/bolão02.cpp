#include <iostream>
#include <string>
#include <algorithm> // sort
using namespace std;

// -------------------------------------------------------
// CLASSE Jogo - armazena placar real de um jogo
// Usa vetor ESTATICO (array fixo de 4 jogos em main)
// -------------------------------------------------------
class Jogo {
public:
    string timeA;
    string timeB;
    int golsA;
    int golsB;

    Jogo() : timeA(""), timeB(""), golsA(0), golsB(0) {}

    Jogo(string ta, string tb, int ga, int gb)
        : timeA(ta), timeB(tb), golsA(ga), golsB(gb) {}

    void exibir() const {
        cout << timeA << " " << golsA << " x " << golsB << " " << timeB << "\n";
    }
};


// CLASSE Apostador - armazena nome, palpites e pontuacao
// palpites: vetor DINAMICO alocado com new[]
class Apostador {
public:
    string nome;
    int pontuacao;
    int* palpitesA; // gols do time A em cada jogo
    int* palpitesB; // gols do time B em cada jogo
    int numJogos;

    Apostador() : nome(""), pontuacao(0), palpitesA(nullptr), palpitesB(nullptr), numJogos(0) {}

    // Aloca vetor dinamico para os palpites
    void alocar(int n) {
        numJogos = n;
        palpitesA = new int[n];
        palpitesB = new int[n];
        for (int i = 0; i < n; i++) palpitesA[i] = palpitesB[i] = 0;
    }

    // Libera memoria alocada com delete[]
    void liberar() {
        delete[] palpitesA;
        delete[] palpitesB;
        palpitesA = nullptr;
        palpitesB = nullptr;
    }

    ~Apostador() {
        liberar();
    }
};


// Calcula pontuacao de um palpite vs resultado real
//   10 pts - placar exato
//    5 pts - vencedor correto (ou empate certo)
//    2 pts - diferenca de gols correta
//    0 pts - nenhum acerto

int calcularPontuacao(int b1, int b2, int r1, int r2) {
    if (b1 == r1 && b2 == r2)
        return 10;

    int vB = (b1 > b2) ? 1 : (b2 > b1) ? 2 : 0;
    int vR = (r1 > r2) ? 1 : (r2 > r1) ? 2 : 0;

    if (vB == vR)
        return 5;

    if ((b1 - b2) == (r1 - r2))
        return 2;

    return 0;
}


// Exibe ranking ordenado por pontuacao (maior -> menor)

void exibirRanking(Apostador* apostadores, int total) {
    if (total == 0) {
        cout << "\nNenhuma aposta registrada!\n";
        return;
    }

    // Copia indices e ordena por pontuacao (bubble sort simples)
    int* ordem = new int[total];
    for (int i = 0; i < total; i++) ordem[i] = i;

    for (int i = 0; i < total - 1; i++)
        for (int j = i + 1; j < total; j++)
            if (apostadores[ordem[j]].pontuacao > apostadores[ordem[i]].pontuacao)
                swap(ordem[i], ordem[j]);

    cout << "\n=== RANKING DO BOLAO ===\n";
    for (int i = 0; i < total; i++) {
        Apostador& a = apostadores[ordem[i]];
        cout << (i + 1) << "o - " << a.nome << " - " << a.pontuacao << " pontos\n";
    }
    cout << "========================\n";

    delete[] ordem;
}

// MAIN

int main() {
    const int NUM_JOGOS = 4;
    const int MAX_APOSTADORES = 3;

    // Vetor ESTATICO com os 4 jogos e resultados reais
    Jogo jogos[NUM_JOGOS] = {
        Jogo("BRA", "EGT", 3, 0),
        Jogo("RSA", "MAR", 1, 1),
        Jogo("FRA", "ARG", 1, 2),
        Jogo("GER", "COS", 4, 2)
    };

 
    Apostador* apostadores = new Apostador[MAX_APOSTADORES];
    int totalApostadores = 0;

    int opcao = 0;

    cout << "========================================\n";
    cout << "    BOLAO DA COPA DO MUNDO 2026\n";
    cout << "========================================\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "(1) Cadastrar resultado dos jogos (ver atuais)\n";
        cout << "(2) Cadastrar palpites de apostador\n";
        cout << "(3) Calcular pontuacoes\n";
        cout << "(4) Exibir ranking\n";
        cout << "(5) Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida!\n";
            continue;
        }

        // OPCAO 1 - VER / ALTERAR RESULTADOS
        if (opcao == 1) {
            cout << "\n--- RESULTADOS ATUAIS DOS JOGOS ---\n";
            for (int i = 0; i < NUM_JOGOS; i++) {
                cout << "Jogo " << (i + 1) << ": ";
                jogos[i].exibir();
            }
            cout << "\nDeseja alterar algum resultado? (1=Sim / 0=Nao): ";
            int alt; cin >> alt;
            if (alt == 1) {
                cout << "Numero do jogo (1-4): ";
                int j; cin >> j;
                if (j >= 1 && j <= NUM_JOGOS) {
                    cout << "Novo placar " << jogos[j-1].timeA << ": "; cin >> jogos[j-1].golsA;
                    cout << "Novo placar " << jogos[j-1].timeB << ": "; cin >> jogos[j-1].golsB;
                    cout << "Resultado atualizado!\n";
                } else {
                    cout << "Numero de jogo invalido.\n";
                }
            }
        }

        // OPCAO 2 - CADASTRAR PALPITES
        else if (opcao == 2) {
            if (totalApostadores >= MAX_APOSTADORES) {
                cout << "\nLimite de " << MAX_APOSTADORES << " apostadores atingido!\n";
            } else {
                Apostador& a = apostadores[totalApostadores];
                a.alocar(NUM_JOGOS); // aloca vetor dinamico

                cout << "\n--- APOSTADOR " << (totalApostadores + 1) << " ---\n";
                cout << "Nome: ";
                cin >> a.nome;

                for (int i = 0; i < NUM_JOGOS; i++) {
                    cout << "\nJogo " << (i + 1) << ": " << jogos[i].timeA << " x " << jogos[i].timeB << "\n";
                    cout << "Palpite " << jogos[i].timeA << ": "; cin >> a.palpitesA[i];
                    cout << "Palpite " << jogos[i].timeB << ": "; cin >> a.palpitesB[i];
                }

                totalApostadores++;
                cout << "\nPalpites de " << a.nome << " registrados!\n";
            }
        }

        // OPCAO 3 - CALCULAR PONTUACOES
        else if (opcao == 3) {
            if (totalApostadores == 0) {
                cout << "\nNenhum apostador cadastrado!\n";
            } else {
                for (int i = 0; i < totalApostadores; i++) {
                    apostadores[i].pontuacao = 0;
                    for (int j = 0; j < NUM_JOGOS; j++) {
                        apostadores[i].pontuacao += calcularPontuacao(
                            apostadores[i].palpitesA[j],
                            apostadores[i].palpitesB[j],
                            jogos[j].golsA,
                            jogos[j].golsB
                        );
                    }
                }
                cout << "\nPontuacoes calculadas!\n";
                for (int i = 0; i < totalApostadores; i++)
                    cout << apostadores[i].nome << ": " << apostadores[i].pontuacao << " pontos\n";
            }
        }

        // OPCAO 4 - EXIBIR RANKING
        else if (opcao == 4) {
            exibirRanking(apostadores, totalApostadores);
        }

        // OPCAO INVALIDA
        else if (opcao != 5) {
            cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 5);

    // Libera vetor dinamico de apostadores
    delete[] apostadores;

    cout << "\nObrigado por participar do Bolao da Copa 2026! Ate mais!\n";
    return 0;
}