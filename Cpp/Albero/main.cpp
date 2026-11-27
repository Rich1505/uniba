#include "Tree.h"
#include <iostream>

using namespace std;

/*
         1
      /  |  \
     2   3   4
    / \     / \
   5   6   7   8
*/


int main()
{
    Tree<int> t;
    t.set_root(1);
    Node<int> *n1 = t.get_root();

    // Inserisco i figli di 1: prima 2, poi 3, poi 4
    Tree<int> sub2, sub3, sub4;
    sub2.set_root(2);
    sub3.set_root(3);
    sub4.set_root(4);

    t.insert_first_subtree(n1, &sub2);
    Node<int> *n2 = t.get_first_son(n1);

    t.insert_subtree(n2, &sub3);
    Node<int> *n3 = t.get_next_brother(n2);

    t.insert_subtree(n3, &sub4);
    Node<int> *n4 = t.get_next_brother(n3);

    // Inserisco i figli di 2: 5 e 6
    Tree<int> sub5, sub6;
    sub5.set_root(5);
    sub6.set_root(6);

    t.insert_first_subtree(n2, &sub5);
    Node<int> *n5 = t.get_first_son(n2);
    t.insert_subtree(n5, &sub6);

    // Inserisco i figli di 4: 7 e 8
    Tree<int> sub7, sub8;
    sub7.set_root(7);
    sub8.set_root(8);

    t.insert_first_subtree(n4, &sub7);
    Node<int> *n7 = t.get_first_son(n4);
    t.insert_subtree(n7, &sub8);

    // Post-visita (atteso: 5 6 2 3 7 8 4 1)
    cout << "Post-visita: ";
    t.post_visita_print();
    cout << endl;

    // Test dei metodi di interrogazione
    cout << "Padre di 7: " << t.get_father(n7)->get_value() << endl;
    cout << "3 e' foglia? " << t.is_leaf(n3) << endl;
    cout << "4 e' ultimo fratello? " << t.is_last_brother(n4) << endl;

    // Cancello il sottoalbero radicato in 4 (elimina 4, 7, 8)
    t.delete_subtree(n4);

    // Post-visita dopo la cancellazione (atteso: 5 6 2 3 1)
    cout << "Post-visita dopo delete_subtree(4): ";
    t.post_visita_print();
    cout << endl;

    cout << "Albero vuoto? " << t.empty_tree() << endl;

    // Cancello tutto l'albero dalla radice
    t.delete_subtree(t.get_root());
    cout << "Albero vuoto dopo cancellazione totale? " << t.empty_tree() << endl;

    return 0;
}