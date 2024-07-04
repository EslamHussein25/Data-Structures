#include <iostream>

class Node
{
 public:
    Node * Right ;
    Node * Left ;
    int data ;

    Node(int Data):data(Data)
    {

    }
};


class Tree 
{

private:
    Node * Root ; // use this Root or global variable to pass some parameters between methods 

    Node * Add(int data , Node * root)
    {
        if(root == nullptr)
        {
            //add new node 
            root = new Node(data) ;
            root->Left = nullptr ;
            root->Right = nullptr ;
        }
        else if(data > root->data)
        {
            //add Right 
            root->Right = Add(data , root->Right);
        }
        else if(data < root->data)
        {
            //add Left 
            root->Left = Add(data , root->Left);
        }
        return  root ;
    }

    void show(Node * Root1)
    {
        if(!Root1)
        {
            return ;
        }

        show(Root1->Left) ;
        std::cout<<"Data : "<< Root1->data <<"\n";
        show(Root1->Right) ;
    }

public:

    void Insert(int data)
    {
        static Node * root = nullptr ;
        root = Add(data , root);
        Root = root ;
    }

    void Traverse()
    {
        show(Root);
    }

};



int main()
{
    Tree t;
    t.Insert(20);
    t.Insert(10);
    t.Insert(5);
    t.Insert(50);
    t.Insert(25);
    t.Insert(8);
    t.Insert(0);
    t.Insert(3);
    
    t.Traverse();
    return 0;
}