#include<iostream>
#include"Studente.h"

int main()
{
    int matricola = 499999;
    string nome = "Riccardo";
    string cognome = "Pistillo";
    int eta = 20;
    string numeri_telefono[] = {"346", "345"};
    int n_numeri_telefono = 2;

    Studente *a;

    try
    {
        a = new Studente(matricola, nome, cognome, eta, numeri_telefono, n_numeri_telefono);
    }
    catch(const char *exception)
    {
        std::cerr << exception << endl;
        return 0;
    }

    std::cout << a->get_matricola() << " " << a->get_nome() << " " << a->get_cognome() << " " << a->get_eta() << " " << a->get_n_numeri_telefono() << endl;
    for(int i = 0;i < a->get_n_numeri_telefono();i++)
    {
        std::cout << a->get_numero_di_telefono(i) << " ";
    }
    cout << std::endl;

    Studente b = *a;

    b.set_nome("Giorgio");
    b.set_numero_di_telefono("333",0);

    std::cout << a->get_nome() << " " << a->get_numero_di_telefono(0) << endl;
}