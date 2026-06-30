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
    /*
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
    */

    // Para não ocorrer x², preciso tornar o algortimo de pesquisa em log(linha) + log(coluna) da matrix
    // Sistema de busca binária em uma matriz n x n ou matriz n x m
   
    // Organizar a matriz

    int x;
    int linha = n;
    int coluna = m;
    int tamanho = linha * coluna;
    // deixar a matriz 2D plana (1D)
    int vet[tamanho];
    int index = 0;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            vet[index] = arr[i][j];
            index++;
        }
    } 
    // método de inserção em vetor
    for(i = 1; i < tamanho; i++) {
        int chave = vet[i];
        j = i - 1;

        while((j >= 0) && (vet[j] > chave)) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = chave;  
    }
    // Colocar os valores novamente na matriz 2D 
    index = 0;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            arr[i][j] = vet[index];
            index++;
        }
    }
    cout << endl;
    cout << "MATRIZ COM VALORES ORGANIZADOS: " << endl;
    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Preparada para busca binária" << endl;
/*
bool encontrado;
encontrado = false;
cout << "Qual valor você quer buscar na matriz: ";
cin >> x;

int inicio = 0;
int fim = linha * coluna - 1;
int meio = inicio + (fim - inicio) / 2;

while(inicio <= fim) {

} 
*/

    return 0;
}