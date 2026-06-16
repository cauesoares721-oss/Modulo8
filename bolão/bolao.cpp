#include <iostream>
#include <string>

using namespace std;

// Função para calcular a pontuação
int calcularPontuacao(int bolao1, int bolao2, int real1, int real2)
{
    if (bolao1 == real1 && bolao2 == real2)
        return 10;

    int vencedorBolao = 0;

    if (bolao1 > bolao2)
        vencedorBolao = 1;
    else if (bolao2 > bolao1)
        vencedorBolao = 2;

    int vencedorReal = 0;

    if (real1 > real2)
        vencedorReal = 1;
    else if (real2 > real1)
        vencedorReal = 2;

    if (vencedorBolao == vencedorReal)
        return 5;

    return 0;
}

int main()
{
    string nome1, nome2, nome3, nome4;
    int pontos1 = 0, pontos2 = 0, pontos3 = 0, pontos4 = 0;

    string time1[4] = {"BRA", "RSA", "FRA", "GER"};
    string time2[4] = {"EGT", "MAR", "ARG", "COS"};

    int palpite1, palpite2;
    int real1, real2;

    // Apostador 1
    cout << "Nome do apostador 1: ";
    cin >> nome1;

    for (int i = 0; i < 4; i++)
    {
        cout << "\nJogo " << i + 1 << ": " << time1[i] << " x " << time2[i] << endl;

        cout << "Palpite " << time1[i] << ": ";
        cin >> palpite1;
        cout << "Palpite " << time2[i] << ": ";
        cin >> palpite2;

        cout << "Resultado real " << time1[i] << ": ";
        cin >> real1;
        cout << "Resultado real " << time2[i] << ": ";
        cin >> real2;

        pontos1 += calcularPontuacao(palpite1, palpite2, real1, real2);
    }

    // Apostador 2
    cout << "\nNome do apostador 2: ";
    cin >> nome2;

    for (int i = 0; i < 4; i++)
    {
        cout << "\nJogo " << i + 1 << ": " << time1[i] << " x " << time2[i] << endl;

        cout << "Palpite " << time1[i] << ": ";
        cin >> palpite1;
        cout << "Palpite " << time2[i] << ": ";
        cin >> palpite2;

        cout << "Resultado real " << time1[i] << ": ";
        cin >> real1;
        cout << "Resultado real " << time2[i] << ": ";
        cin >> real2;

        pontos2 += calcularPontuacao(palpite1, palpite2, real1, real2);
    }

    // Apostador 3
    cout << "\nNome do apostador 3: ";
    cin >> nome3;

    for (int i = 0; i < 4; i++)
    {
        cout << "\nJogo " << i + 1 << ": " << time1[i] << " x " << time2[i] << endl;

        cout << "Palpite " << time1[i] << ": ";
        cin >> palpite1;
        cout << "Palpite " << time2[i] << ": ";
        cin >> palpite2;

        cout << "Resultado real " << time1[i] << ": ";
        cin >> real1;
        cout << "Resultado real " << time2[i] << ": ";
        cin >> real2;

        pontos3 += calcularPontuacao(palpite1, palpite2, real1, real2);
    }

    // Apostador 4
    cout << "\nNome do apostador 4: ";
    cin >> nome4;

    for (int i = 0; i < 4; i++)
    {
        cout << "\nJogo " << i + 1 << ": " << time1[i] << " x " << time2[i] << endl;

        cout << "Palpite " << time1[i] << ": ";
        cin >> palpite1;
        cout << "Palpite " << time2[i] << ": ";
        cin >> palpite2;

        cout << "Resultado real " << time1[i] << ": ";
        cin >> real1;
        cout << "Resultado real " << time2[i] << ": ";
        cin >> real2;

        pontos4 += calcularPontuacao(palpite1, palpite2, real1, real2);
    }

    // Ranking
    cout << "\n---------------------------------\n";
    cout << "     RANKING DOS APOSTADORES\n";
    cout << "---------------------------------\n";

    if (pontos1 >= pontos2 && pontos1 >= pontos3 && pontos1 >= pontos4)
    {
        cout << "1º Lugar: " << nome1 << " - " << pontos1 << " pontos\n";

        if (pontos2 >= pontos3 && pontos2 >= pontos4)
        {
            cout << "2º Lugar: " << nome2 << " - " << pontos2 << " pontos\n";

            if (pontos3 >= pontos4)
            {
                cout << "3º Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
                cout << "4º Lugar: " << nome4 << " - " << pontos4 << " pontos\n";
            }
            else
            {
                cout << "3º Lugar: " << nome4 << " - " << pontos4 << " pontos\n";
                cout << "4º Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
            }
        }
        else if (pontos3 >= pontos2 && pontos3 >= pontos4)
        {
            cout << "2º Lugar: " << nome3 << " - " << pontos3 << " pontos\n";

            if (pontos2 >= pontos4)
            {
                cout << "3º Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
                cout << "4º Lugar: " << nome4 << " - " << pontos4 << " pontos\n";
            }
            else
            {
                cout << "3º Lugar: " << nome4 << " - " << pontos4 << " pontos\n";
                cout << "4º Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
            }
        }
        else
        {
            cout << "2º Lugar: " << nome4 << " - " << pontos4 << " pontos\n";

            if (pontos2 >= pontos3)
            {
                cout << "3º Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
                cout << "4º Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
            }
            else
            {
                cout << "3º Lugar: " << nome3 << " - " << pontos3 << " pontos\n";
                cout << "4º Lugar: " << nome2 << " - " << pontos2 << " pontos\n";
            }
        }
    }

    return 0;
}