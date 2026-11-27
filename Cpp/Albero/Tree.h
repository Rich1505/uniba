#ifndef TREE_H
#define TREE_H

template <typename T>
class Tree;

template <typename T>
class Node
{
private:
    T value;
    Node *father;
    Node *first_son;
    Node *next_brother;
    Tree<T> *owner;
    friend class Tree<T>;

public:
    Node() : father(nullptr), first_son(nullptr), next_brother(nullptr), owner(nullptr) {};
    Node(T val) : value(val), father(nullptr), first_son(nullptr), next_brother(nullptr), owner(nullptr) {};

    void set_value(T val)
    {
        value = val;
    }

    T get_value()
    {
        return value;
    }
};

template <typename T>
class Tree
{
private:
    Node<T> *root;

    void check_ownership(Node<T> *u)
    {
        if(u->owner != this)
            throw "Il nodo non appartiene all'albero";
    }

    void set_subtree_owner(Node<T> *u)
    {
        if (u == nullptr)
            return;

        u->owner = this;
        set_subtree_owner(u->first_son);
        set_subtree_owner(u->next_brother);
    }

    void destroy_nodes(Node<T> *node)
    {
        if (node == nullptr)
            return;

        Node<T> *child = node->first_son;
        while (child != nullptr)
        {
            Node<T> *next = child->next_brother;
            destroy_nodes(child);
            child = next;
        }
        delete node;
    }

public:
    Tree() : root(nullptr) {};

    ~Tree()
    {
        destroy_nodes(root);
    }

    bool empty_tree()
    {
        return root == nullptr;
    }

    void set_root(T value)
    {
        if(root != nullptr)
        {
            throw "La radice e' gia' presente nell'albero"
        }

        Node<T> *new_root = new Node<T>(value);
        root = new_root;
        root->owner = this;
        
    }

    Node<T> *get_root()
    {
        return root;
    }

    bool is_leaf(Node<T> *u)
    {
        if (u == nullptr)
            throw "Null ptr (is_leaf)";

        check_ownership(u);
        return u->first_son == nullptr;
    }

    Node<T> *get_father(Node<T> *u)
    {
        if(u == nullptr)
            throw "Null ptr (get_father)";

        check_ownership(u);
        return u->father;
    }

    Node<T> *get_first_son(Node<T> *u)
    {
        if (u == nullptr)
            throw "Null ptr (get_first_son)";

        check_ownership(u);
        return u->first_son;
    }

    bool is_last_brother(Node<T> *u)
    {
        if (u == nullptr)
            throw "Null ptr (is_last_brother)";

        check_ownership(u);
        return u->next_brother == nullptr;
    }

    Node<T> *get_next_brother(Node<T> *u)
    {
        if (u == nullptr)
            throw "Null ptr (get_next_brother)";

        check_ownership(u);
        return u->next_brother;
    }

    void insert_first_subtree(Node<T> *u, Tree<T> *subtree)
    {
        if (u == nullptr || subtree == nullptr)
            throw "Nullptr insert_first_subtree";

        check_ownership(u);

        if (subtree->empty_tree())
            return;

        Node<T> *subtree_root = subtree->get_root();
        Node<T> *old_first_son = u->first_son;
        u->first_son = subtree_root;
        subtree_root->next_brother = old_first_son;
        subtree_root->owner = this;
        subtree_root->father = u;
        set_subtree_owner(subtree_root);

        subtree->root = nullptr;
    }

    void insert_subtree(Node<T> *u, Tree<T> *subtree)
    {
        if (u == nullptr || subtree == nullptr)
            throw "Null ptr (insert_subtree)";

        check_ownership(u);

        if (u == root)
        {
            throw "Impossibile aggiungere fratelli alla radice";
        }

        if (subtree->empty_tree())
            return;

        Node<T> *subtree_root = subtree->get_root();
        Node<T> *old_next_brother = u->next_brother;
        u->next_brother = subtree_root;
        subtree_root->next_brother = old_next_brother;
        subtree_root->father = u->father;
        set_subtree_owner(subtree_root);

        subtree->root = nullptr;
    }

    void delete_subtree(Node<T> *u)
    {
        if (u == nullptr)
            return;

        check_ownership(u);

        Node<T> *father = u->father;

        if (father != nullptr)
        {
            if (father->first_son == u)
            {
                father->first_son = u->next_brother;
            }
            else
            {
                Node<T> *curr = father->first_son;
                while (curr)
                {
                    if (curr->next_brother == u)
                    {
                        curr->next_brother = u->next_brother;
                        break;
                    }
                    curr = curr->next_brother;
                }
            }
        }
        
        if (u == this->root)
            this->root = nullptr;

        destroy_nodes(u);
    }
};

#endif