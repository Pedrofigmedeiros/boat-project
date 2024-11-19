#include <iostream>
using namespace std;

int main() {
    float preco, desconto_percentual, desconto_valor;
    cout << "Informe o preço do produto: R$";
    cin >> preco;
    cout << "Informe o desconto em %:";
    cin >> desconto_percentual;
    desconto_valor = preco*(desconto_percentual/100);
    cout << "O preço real do produto é de R$" << preco << endl;
    cout << "O valor que será pago é de R$" << preco - desconto_valor << endl;
    cout << "Você está economizando R$" << desconto_valor << endl;

    return 0;
}
