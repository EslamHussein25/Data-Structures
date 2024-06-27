/******************* Stack from chat gpt pure *********************/

/*#include <iostream>
#include <cstdlib> // For malloc, free

class Stack1 
{
    int* items;
    int capacity;
    int top;

public:

    Stack1(int capacity) : capacity(capacity)
    {
        top = -1 ;
        items = (int*)std::malloc(capacity * sizeof(int));
        if (items == nullptr) 
        {
            std::cout << "Failed to allocate memory.\n";
            exit(EXIT_FAILURE);
        }
    }

    ~Stack1() 
    {
        std::free(items);
    }

    void push(int item) 
    {
        if (top >= capacity - 1) 
        {
            std::cout << "Stack overflow.\n";
            return;
        }
        items[++top] = item;
    }

    int pop() 
    {
        if (top < 0) 
        {
            std::cout << "Stack underflow.\n";
            return -1; // Or throw an exception
        }
       items[top--];
    }

    bool isEmpty()  
    {
        return top == -1;
    }

};

int main() 
{
    Stack1 stack(5);
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(3);

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

    return 0;
}*/


#include<iostream>

template <class T>
class StackNode
{
    public:
    T Data ;
    StackNode * Link ;
        
    StackNode(T D):Data(D)
    {
        Link = nullptr ;
    }
    StackNode()
    {
        Link = nullptr ;  
    }
};

template <class T>
class Stack
{
    public:
    StackNode<T> * Top ;

    Stack()
    {
     Top = nullptr ;
    }


    bool Push(T Data) // return 1 if error 0 if done 
    {
        StackNode<T> * newNode = new StackNode<T>(Data) ;
        if(!newNode)
        {
            std::cout<<"Stack overflow\n";
             return true ;
        }
        if(IsEmpty())
        {
            Top = newNode ;
            newNode->Link = nullptr ;
        }
        else 
        {
            newNode->Link = Top ;
            Top = newNode ;
        }
        return false ;
    }

    bool Pop(void)
    {
        if(!Top)
        {
            std::cout<<"Underflow\n";
             return true ;
        }
        else 
        {
            StackNode<T> * Temp = Top ;
            Top = Top->Link ;
            delete(Temp);
        }
        return false ;
    }

    void Display(void)
    {
       StackNode<T> * Temp = Top ;
       while(Temp != nullptr)
       {
        std::cout<<Temp->Data<<"\n";
        Temp = Temp->Link; 
       }
    }


    T Peer(void)
    {
        return Top->Data;
    }

    bool IsEmpty(void)
    {
        return (Top == nullptr);
    }

};

int main()
{
    Stack<int> S ;
    S.Push(1);
    S.Push(2);
    S.Pop();
    S.Push(3);
    S.Push(4);
    S.Pop();
    S.Display();
    std::cout<<"The top now is: "<<S.Peer()<<"\n";

    return 0 ;
}

