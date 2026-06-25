#include <iostream>
#include <array>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n, m, i, j;
    
    cout << "Informe quantas linhas haverá na matriz: ";
    cin >> n;
    cout << "Informe quantas colunas haverá na matriz: ";
    cin >> m;

    int arr[n][m];
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << "Informe o valor na posição [" << i + 1 << "][" << j + 1 << "] = ";
            cin >> arr[i][j];
            cout << endl;
        }
    }
    cout << endl;
    cout << "MATRIZ VALORES CRIADA: " << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;

    // Busca tradicional (Passar por cada valor da matriz) 
    int x;
    bool encontrado;
    encontrado = false;
    cout << "Qual valor você quer buscar na matriz: ";
    cin >> x;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(arr[i][j] == x) {
                cout << "Valor encontrado na posição [" << i + 1 << "][" << j + 1 << "]" << endl;
                encontrado = true;
            }
        }
    }
    if(encontrado != true) {
        cout << "Valor: "<< x << " não exite na matriz" << endl;
    }

    return 0;
}