#include <iostream>

enum Order{
Preorder = 0 , Inorder = 2 , Postorder = 3
};

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
    Node * Root = nullptr; // use this Root or global variable to pass some parameters between methods 

    Node * Add(int data , Node * root)
    {
        if(root == nullptr)  //empty tree only  will enter here 
        {
            //add new node 
            root = new Node(data) ;
            root->Left = nullptr ;
            root->Right = nullptr ;
        }
        else if(data > root->data)
        {
            //add Right the beagest orders 
            root->Right = Add(data , root->Right);
        }
        else if(data < root->data)
        {
            //add Left the leatest order 
            root->Left = Add(data , root->Left);
        }
        return  root ; // return the main root every time to pass to another methods to work with the same tree 
    }


    void Show_Preorder(Node * Root1) // left->root->right
    {
        if(!Root1) // to make sure is not  empty 
        {
            return ;
        }
        Show_Preorder(Root1->Left);
        std::cout<< Root1->data<<"\n";
        Show_Preorder(Root1->Right) ;
    }

    void Show_Inorder(Node * Root1) // root -> left -> right 
    {
        if(!Root1) // to make sure not  empty tree 
        {
            return ;
        }
        std::cout<<Root1->data<<"\n";
        Show_Inorder(Root1->Left) ;
        Show_Inorder(Root1->Right) ;
    }

    void Show_Postorder(Node * Root1) // left ->right->root 
    {
        if(!Root1) // to make sure not empty tree 
        {
            return ;
        }
        Show_Inorder(Root1->Left) ;
        Show_Inorder(Root1->Right) ;
        std::cout<<Root1->data<<"\n";
    }

public:
    void Insert(int data)
    {
        Root = Add(data , Root);  
    }

    void Traverse(Order order)
    {
        switch (order)
        {
        case Preorder:
        Show_Preorder(Root);
            break;
        
        case Inorder:
        Show_Inorder(Root);
            break;

        case Postorder:
        Show_Postorder(Root);
            break;
        
        default:
            break;
        }
    }

};



int main()
{
    Tree t;
    std::cout<<"Tree 1: \n";
    t.Insert(20);
    t.Insert(50);
    t.Insert(30);
    t.Insert(10);
    std::cout<<"Preorder\n";
    t.Traverse(Preorder);
    std::cout<<"Inorder\n";
    t.Traverse(Inorder);
    std::cout<<"Postorder\n";
    t.Traverse(Postorder);

    Tree t2 ;
    std::cout<<"\nTree 2: \n";
    t2.Insert(200);
    t2.Insert(500);
    t2.Insert(300);
    t2.Insert(100);
    std::cout<<"Preorder\n";
    t2.Traverse(Preorder);
    std::cout<<"Inorder\n";
    t2.Traverse(Inorder);
    std::cout<<"Postorder\n";
    t2.Traverse(Postorder);
    return 0;
}