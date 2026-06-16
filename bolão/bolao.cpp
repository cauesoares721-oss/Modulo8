#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// Calcula pontuacao de uma aposta em relacao ao resultado real
// Regras:
//   10 pts - placar exato
//    5 pts - vencedor correto (ou empate certo)
//    2 pts - diferenca de gols correta
//    0 pts - nenhum acerto
// -------------------------------------------------------
int calcularPontuacao(int b1, int b2, int r1, int r2)
{
    // Placar exato
    if (b1 == r1 && b2 == r2)
        return 10;

    // Vencedor correto 
    int vencedorBolao = 0; 
    if (b1 > b2) vencedorBolao = 1;
    else if (b2 > b1) vencedorBolao = 2;

    int vencedorReal = 0;
    if (r1 > r2) vencedorReal = 1;
    else if (r2 > r1) vencedorReal = 2;

    if (vencedorBolao == vencedorReal)
        return 5;

    // Diferenca de gols correta
    if ((b1 - b2) == (r1 - r2))
        return 2;

    return 0;
}

int main()
{
    // Resultados oficiais dos 4 jogos
    int real_j1_a = 3, real_j1_b = 0; // BRA x EGT
    int real_j2_a = 1, real_j2_b = 1; // RSA x MAR
    int real_j3_a = 1, real_j3_b = 2; // FRA x ARG
    int real_j4_a = 4, real_j4_b = 2; // GER x COS

    
    string nome1 = "", nome2 = "", nome3 = "";
    int pontos1 = 0, pontos2 = 0, pontos3 = 0;
    bool apostou1 = false, apostou2 = false, apostou3 = false;

    int opcao = 0;
    int apostadorAtual = 0; // controla qual apostador vai apostar em seguida

    cout << "========================================\n";
    cout << "    BOLAO DA COPA DO MUNDO 2026\n";
    cout << "========================================\n";

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "(1) Fazer aposta\n";
        cout << "(2) Exibir ranking\n";
        cout << "(3) Sair do programa\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida!\n";
            continue;
        }

                
        // OPCAO 1 - FAZER APOSTA
        
        if (opcao == 1)
        {
            // Determina qual apostador vai inserir a aposta
            apostadorAtual++;

            if (apostadorAtual > 3)
            {
                cout << "\nTodos os 3 apostadores ja realizaram suas apostas!\n";
                apostadorAtual = 3; // nao avanca mais
            }
            else
            {
                string nomeApostador;
                int p1a, p1b, p2a, p2b, p3a, p3b, p4a, p4b;
                int pontosTotal = 0;

                cout << "\n--- APOSTADOR " << apostadorAtual << " ---\n";
                cout << "Nome: ";
                cin >> nomeApostador;

                // Jogo 1: BRA x EGT
                cout << "\nJogo 1: BRA x EGT\n";
                cout << "Palpite BRA: "; cin >> p1a;
                cout << "Palpite EGT: "; cin >> p1b;

                // Jogo 2: RSA x MAR
                cout << "\nJogo 1: RSA x Mar\n";
                cout << "Palpite RSA: "; cin >> p2a;
                cout << "Palpite MAR: "; cin >> p2b;

                // Jogo 3: FRA x ARG
                cout << "\nJogo 3: FRA x ARG  \n";
                cout << "Palpite FRA: "; cin >> p3a;
                cout << "Palpite ARG: "; cin >> p3b;

                // Jogo 4: GER x COS
                cout << "\nJogo 4: GER x COS  \n";
                cout << "Palpite GER: "; cin >> p4a;
                cout << "Palpite COS: "; cin >> p4b;

                // Calcula pontuacao total
                pontosTotal += calcularPontuacao(p1a, p1b, real_j1_a, real_j1_b);
                pontosTotal += calcularPontuacao(p2a, p2b, real_j2_a, real_j2_b);
                pontosTotal += calcularPontuacao(p3a, p3b, real_j3_a, real_j3_b);
                pontosTotal += calcularPontuacao(p4a, p4b, real_j4_a, real_j4_b);

                // Armazena nas variaveis do apostador correto
                if (apostadorAtual == 1)
                {
                    nome1 = nomeApostador;
                    pontos1 = pontosTotal;
                    apostou1 = true;
                }
                else if (apostadorAtual == 2)
                {
                    nome2 = nomeApostador;
                    pontos2 = pontosTotal;
                    apostou2 = true;
                }
                else // apostadorAtual == 3
                {
                    nome3 = nomeApostador;
                    pontos3 = pontosTotal;
                    apostou3 = true;
                }

                cout << "\nAposta de " << nomeApostador << " registrada! Pontuacao: " << pontosTotal << " pontos.\n";
            }
        }

        // OPCAO 2 - EXIBIR RANKING
        
       else if (opcao == 2)
{
    if (!apostou1 && !apostou2 && !apostou3)
    {
        cout << "\nNenhuma aposta registrada!\n";
    }
    else
    {
        cout << "\n===== RANKING =====\n";

        if (pontos1 >= pontos2 && pontos1 >= pontos3)
        {
            cout << "1 Lugar: " << nome1 << " - " << pontos1 << " pontos\n";

            if (pontos2 >= pontos3)
            {
                if (apostou2)
                    cout << "2 Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
                if (apostou3)
                    cout << "3 Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
            }
            else
            {
                if (apostou3)
                    cout << "2 Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
                if (apostou2)
                    cout << "3 Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
            }
        }
        else if (pontos2 >= pontos1 && pontos2 >= pontos3)
        {
            cout << "1 Lugar: " << nome2 << " - " << pontos2 << " pontos\n";

            if (pontos1 >= pontos3)
            {
                if (apostou1)
                    cout << "2 Lugar: " << nome1 << " - " << pontos1 << " pontos\n";
                if (apostou3)
                    cout << "3 Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
            }
            else
            {
                if (apostou3)
                    cout << "2 Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
                if (apostou1)
                    cout << "3 Lugar: " << nome1 << " - " << pontos1 << " pontos\n";
            }
        }
        else
        {
            cout << "1 Lugar: " << nome3 << " - " << pontos3 << " pontos\n";

            if (pontos1 >= pontos2)
            {
                if (apostou1)
                    cout << "2 Lugar: " << nome1 << " - " << pontos1 << " pontos\n";
                if (apostou2)
                    cout << "3 Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
            }
            else
            {
                if (apostou2)
                    cout << "2 Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
                if (apostou1)
                    cout << "3 Lugar: " << nome1 << " - " << pontos1 << " pontos\n";
            }
        }

        cout << "===================\n";
    }
}
        
        // OPCAO INVALIDA
        
        else if (opcao != 3)
        {
            cout << "\nOpcao invalida! Tente novamente.\n";
        }

    } while (opcao != 3);

    cout << "\nObrigado por participar do Bolao da Copa 2026! Ate mais!\n";

    return 0;
}