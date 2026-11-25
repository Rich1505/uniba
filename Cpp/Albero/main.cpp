#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Tree<int> *t = new Tree<int>();

        t->set_root(5);

        Tree<int> *t1 = new Tree<int>();
        t1->set_root(10);

        t->insert_first_subtree(t->get_root(), t1);

        cout << t->get_root()->get_value() << " " << t->get_first_son(t->get_root())->get_value();
    }
    catch (char const* e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}