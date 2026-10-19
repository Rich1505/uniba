#include"Studente.h"
#include<iostream>

#define MIN_MATRICOLA 255312
#define MAX_MATRICOLA 499999

using namespace std;

void Studente::set_matricola(const int matricola)
{
    if(matricola < MIN_MATRICOLA || matricola > MAX_MATRICOLA)
    {
        throw "Numero di matricola non valido";
    }

    this->matricola = matricola;
}

void Studente::set_nome(const string &nome)
{
    if(nome.length() > 30)
    {
        cerr << "Nome piu' lungo di 30 caratteri, verra' troncato\n";
    }

    this->nome = nome;
}

void Studente::set_cognome(const string &cognome)
{
    if(cognome.length() > 30)
    {
        cerr << "Cognome piu' lungo di 30 caratteri, verra' troncato\n";
    }

    this->cognome = cognome;
}

void Studente::set_eta(const int eta)
{
    if(eta < 12 || eta > 105)
    {
        throw "Eta' non valida";
    }

    this->eta = eta;
}

void Studente::set_numeri_di_telefono(const string* numeri_di_telefono, const int n_numeri_telefono)
{
    if(!numeri_di_telefono)
        return;

    if(n_numeri_telefono <= 0)
    {
        throw "Quantità numeri di telefono non validi";
    }

    if(this->numeri_di_telefono != nullptr)
        delete[] this->numeri_di_telefono;

    this->numeri_di_telefono = new string[n_numeri_telefono];
    for(size_t i = 0;i < n_numeri_telefono; i++)
    {
        this->numeri_di_telefono[i] = numeri_di_telefono[i];
    }

    this->n_numeri_telefono = n_numeri_telefono;
}

void Studente::set_numero_di_telefono(const string& new_str, size_t index)
{
    if(index < 0 || index >= this->get_n_numeri_telefono())
    {
        throw "Indice non valido";
    }
    this->numeri_di_telefono[index] = new_str;
}

Studente::Studente(int matricola, const string &nome, const string &cognome, int eta, const string *numeri_di_telefono, int n_numeri_telefono)
{

    std::cout << "Costruttore di base" << std::endl;
    this->numeri_di_telefono = nullptr;
    set_matricola(matricola);
    set_nome(nome);
    set_cognome(cognome);
    set_eta(eta);
    set_numeri_di_telefono(numeri_di_telefono, n_numeri_telefono);
}

Studente::~Studente()
{
    if(this->numeri_di_telefono)
        delete[] this->numeri_di_telefono;
}

Studente::Studente(const Studente &copied_student) :
    Studente(copied_student.matricola, copied_student.nome, copied_student.cognome, copied_student.eta, copied_student.numeri_di_telefono, copied_student.n_numeri_telefono)
    {
        std::cout << "Costruttore di copia" << std::endl;
    }

Studente::Studente(Studente &&rhs) noexcept : 
    matricola(rhs.matricola),
    nome(std::move(rhs.nome)),
    cognome(std::move(rhs.cognome)),
    eta(rhs.eta),
    numeri_di_telefono(rhs.numeri_di_telefono),
    n_numeri_telefono(rhs.n_numeri_telefono)
{
    std::cout << "Move constructor" << std::endl;

    this->numeri_di_telefono = rhs.numeri_di_telefono;
    this->n_numeri_telefono = rhs.n_numeri_telefono;

    rhs.numeri_di_telefono = nullptr;
    rhs.n_numeri_telefono = 0;
}

int Studente::get_matricola() const
{
    return this->matricola;
}

string Studente::get_nome() const
{
    return this->nome;
}

string Studente::get_cognome() const
{
    return this->cognome;
}

int Studente::get_eta() const
{
    return this->eta;
}

string Studente::get_numero_di_telefono(size_t index) const
{
    if(index < 0 || index >= this->n_numeri_telefono)
    {
        throw "Indice non valido";
    }

    return this->numeri_di_telefono[index];
}

int Studente::get_n_numeri_telefono() const
{
    return this->n_numeri_telefono;
}

