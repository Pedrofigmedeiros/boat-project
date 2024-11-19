/*
Prática 3: Num determinado estado, para transferências de um veículo do antigo para o novo dono, o 
DETRAN cobra uma taxa de:
- 1% sobre o valor do carro se o carro for fabricado antes de 2000 
- 1,5% sobre o valor do carro para aqueles fabricados de 2000 em diante.

Implemente um programa que calcule e exiba o valor da taxa a ser paga no momento da transferência 
de um carro do antigo para o novo dono. O usuário deverá informar ao programa o ano de fabricação e o valor de tabela do carro.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int ano_fabricacao;
    float taxa_percentual, valor_carro, valor_taxa;
    cout << "Informe o ano de fabricação do carro: ";
    cin >> ano_fabricacao;
    cout << "Informe o valor de tabela do carro: ";
    cin >> valor_carro;

    if (ano_fabricacao < 2000){
        taxa_percentual = 1;
    } else {
        taxa_percentual = 1.5;
    }

    valor_taxa = taxa_percentual/100 * valor_carro;
    cout << "A taxa a ser paga será de " << valor_taxa << endl;

    return 0;
}
