#include <iostream>

using namespace std;

int main()
{
    int n, aux, sum=0;

    cout << "Somatório de: ";
    cin >> n;

    for(aux=1 ; aux<=n ; aux++)
        sum += aux;

    cout << "Somatório: " << sum << endl;

    return 0;
}