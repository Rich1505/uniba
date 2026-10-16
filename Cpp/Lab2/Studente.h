#include<string>

using namespace std;

class Studente{
    private:
        int matricola;
        string nome;
        string cognome;
        int eta;
        string *numeri_di_telefono;
        int n_numeri_telefono;
    
    public:
        Studente(int matricola, const string &nome, const string &cognome, int eta, const string *numeri_di_telefono, int n_numeri_telefono);
        ~Studente();
        Studente(Studente &copied_student);

        void set_matricola(const int matricola);
        void set_nome(const string &nome);
        void set_cognome(const string &cognome);
        void set_eta(const int eta);
        void set_numeri_di_telefono(const string* numeri_di_telefono, const int n_numeri_telefono);
        void set_numero_di_telefono(const string& new_str, size_t index);

        int get_matricola() const;
        string get_nome() const;
        string get_cognome() const;
        int get_eta() const;
        string get_numero_di_telefono(size_t index) const;
        int get_n_numeri_telefono() const;
};