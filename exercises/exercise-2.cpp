/*
Prática 2: Implemente um programa que, dado um raio R, informado pelo usuário, calcule e exiba:
(a) O comprimento da circunferência de raio R: C = 2 m R
(b) A área do círculo de raio R: A = R2
(c) O volume da esfera de raio R: V = ¾R3
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float raio, comprimento, area, volume;
    cout << "Informe o raio da esfera em m: ";
    cin >> raio;

    comprimento = 2 * 3.1415 * raio;
    area = 3.1415 * pow(raio, 2);
    volume = (4 * 3.1415 * pow(raio, 3))/3;

    cout << fixed << setprecision(2);
    cout << "O comprimento da circunferência de um círculo de raio " << raio << "m é de " << comprimento << "m" << endl;
    cout << "A área da circunferência de um círculo de raio " << raio << "m é de " << area << "m2" << endl;
    cout << "O volume da circunferência de um círculo de raio " << raio << "m é de " << volume << "m3" << endl;

    return 0;
}
