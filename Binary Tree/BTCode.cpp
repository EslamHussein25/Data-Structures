#include <iostream>

enum Order
{
Preorder = 0 , Inorder = 2 , Postorder = 3
};

template<class T>
class Node
{
 public:
    Node<T> * Right ;
    Node<T> * Left ;
    T data ;

    Node(T Data):data(Data)
    {

    }
};

template<class T>
class Tree 
{

private:
    Node<T> * Root = nullptr; // use this Root or global variable to pass some parameters between methods 

    Node<T> * Add(int data , Node<T> * root)
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

    void Show_Preorder(Node<T> * Root1) // left->root->right
    {
        if(!Root1) // to make sure is not  empty 
        {
            return ;
        }
        Show_Preorder(Root1->Left);
        std::cout<< Root1->data<<"\n";
        Show_Preorder(Root1->Right) ;
    }

    void Show_Inorder(Node<T> * Root1) // root -> left -> right 
    {
        if(!Root1) // to make sure not  empty tree 
        {
            return ;
        }
        std::cout<<Root1->data<<"\n";
        Show_Inorder(Root1->Left) ;
        Show_Inorder(Root1->Right) ;
    }

    void Show_Postorder(Node<T> * Root1) // left ->right->root 
    {
        if(!Root1) // to make sure not empty tree 
        {
            return ;
        }
        Show_Inorder(Root1->Left) ;
        Show_Inorder(Root1->Right) ;
        std::cout<<Root1->data<<"\n";
    }

    Node<T> * Search_Element(Node<T> * Root1 , T Element)
    {
        if(Root1 == nullptr)
        {
            return nullptr;
        }
        else if (Root1->data > Element)
        {
            // serach in left elements 
            Root1 = Search_Element(Root1->Left , Element);
        }
        else if (Root1->data < Element)
        {
            // serach in right elements 
            Root1 = Search_Element(Root1->Right , Element);
        }
        return Root1 ;
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

    Node<T> * Search(T  Elememt)
    {
        Node<T> * root = nullptr;
        root = Search_Element(Root , Elememt);
        if(root != nullptr)
         std::cout<<"Found\n";  
         else 
         std::cout<<"Not Found\n";  
         return root ;
    }
};



int main()
{
    Tree<int> t;
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
    t.Search(10);

/*
    Tree<int> t2 ;
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
    t2.Traverse(Postorder);*/
    return 0;
}