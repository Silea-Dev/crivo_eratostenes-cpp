#include <iostream>
#include <vector>
#include <cmath>

class Crivo
{
private:
    std::vector<bool> _primos;
    unsigned long long int _limite, raiz_i;

public:
    Crivo(unsigned long long int lim);
    ~Crivo();
    void teste();
    void calc_raiz();
    void imprimirPrimos();
};

Crivo::Crivo(unsigned long long int lim) : _primos(lim + 1, true), _limite(lim)
{
    _primos[0] = false;
    _primos[1] = false;
    this->calc_raiz();
    this->teste();
}

Crivo::~Crivo() {}

void Crivo::calc_raiz()
{
    double raiz_d = std::sqrt(this->_limite);
    this->raiz_i = (unsigned long long int)(raiz_d);
}

void Crivo::teste()
{
    unsigned long long int raiz = this->raiz_i;

    for (unsigned long long int i = 2; i < raiz + 1; i++)
    {
        if (this->_primos[i])
        {
            for (unsigned long long int j = (unsigned long long int)i * i; j <= this->_limite; j += i)
            {
                this->_primos[j] = false;
            }
        }
    }
}

void Crivo::imprimirPrimos()
{
    std::cout << "Numeros primos encontrados ate " << this->_limite << ":" << std::endl;

    for (unsigned long long int i = 0; i <= this->_limite; i++)
    {
        if (this->_primos[i])
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

int _iniciar()
{
    while (true)
    {
        unsigned long long int limite;
        std::cout << "\nDigite o limite de numeros | sair[0]: ";
        std::cin >> limite;

        if (limite == 0)
        {
            std::cout << "Bye!";
            break;
        }
        if (limite > 100000000)
        {
            std::cout << "[ALERT] Segurança extra! So procure itens com menos de 7 digitos!";
            continue;
        }
        else if (limite > 0)
        {
            Crivo objeto(limite);
            objeto.imprimirPrimos();
        }
    }

    return 0;
}

int main()
{
    std::cout << "[ALERT] Exemplo de uso:\nSe digita 100, ele gera os primos de 2 ate 100.\n";
    _iniciar();
    return 0;
}