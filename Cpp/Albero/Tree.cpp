#ifndef TREE_H
#define TREE_H

template <typename T> class Tree;

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

        bool check_ownership(Node<T> *u)
        {
            return u->owner == this;
        }
    
    public:
        Tree() : root(nullptr){};

        bool empty_tree()
        {
            return root == nullptr;
        }

        void set_root(Node<T> *new_root)
        {
            root = new_root;
            root->owner = this;
        }

        Node<T> *get_root()
        {
            return root;
        }

        bool is_leaf(Node<T> *u)
        {
            return u->first_son == nullptr;
        }

        Node<T> *get_first_son(Node<T> *u)
        {
            return u->first_son;
        }

        bool is_last_brother(Node<T> *u)
        {
            return u->next_brother == nullptr;
        }

        Node<T> *get_next_brother(Node<T> *u)
        {
            return u->next_brother;
        }

        void insert_first_subtree(Node<T> *u, Tree<T> *subtree)
        {
            Node<T> *subtree_root = subtree->get_root();
            Node<T> *old_first_son = u->first_son;
            u->first_son = subtree_root;
            subtree_root->next_brother = old_first_son;
            subtree_root->owner = this;
            subtree_root->father = u;

            delete subtree;
        }

        void insert_subtree(Node<T> *u, Tree<T> *subtree)
        {
            if(u == root)
            {
                throw "Impossibile aggiungere fratelli alla radice";
            }

            Node<T> *subtree_root = subtree->get_root();
            Node<T> *old_next_brother = u->next_brother;
            u->next_brother = subtree_root;
            subtree_root->next_brother = old_next_brother;
            subtree_root->father = u->father;

            delete subtree;
        }

        void delete_subtree(Node<T> *u)
        {
            if(u == nullptr)
            return;
            
            Node<T> *father = u->father;
            if(father->first_son == u)
            {
                father->first_son = u->next_brother;
            }
            else
            {
                Node<T> *curr = father->first_son;
                while(curr)
                {
                    if(curr->next_brother == u)
                    {
                        curr->next_brother = u->next_brother;
                        break;
                    }
                }
            }

            delete_subtree(u->first_son);
            delete_subtree(u->first_son->next_brother);

            delete u;
        }

};

#endif