/*
Prática 10: Implemente um programa para obter do usuário um número inteiro maior que zero que representa
 o número de linhas de uma pirâmide. O programa deverá gerar e exibir uma pirâmide de números segundo o exemplo abaixo.
Exemplo: Caso o usuário digite o número 5, o programa deverá exibir a seguinte pirâmide:
1234
123
12

OBS 1: Para exibir a pirâmide, implemente um procedimento chamado exibePiramide que recebe como parâmetro
 o número de linhas da pirâmide (informado pelo usuário).
Dica: Para exibir cada linha da pirâmide, o procedimento exibePiramide deverá executar um outro 
procedimento chamado exibeLinha que exibe os números inteiros de 1 até N, onde N é o tamanho da linha.
OBS 2: O método main deve FORÇAR que o número de linhas da pirâmide que será fornecido pelo
usuário seja maior que um.
*/

#include <iostream>
using namespace std;

void exibeLinha(int a) {
    for (int i = 1; i <= a; i++) {
        cout << i;
    }
    cout << endl;
}

void exibePiramide(int b) {
    for (int i = b; i > 0; i--) {
        exibeLinha(i);
    }
}

int main() {
    int numero;
    do {
        cout << "Informe um número inteiro maior que zero: ";
        cin >> numero;
    } while (numero <= 0); 

    exibePiramide(numero);

    return 0;
}

