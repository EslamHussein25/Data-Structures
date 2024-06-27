#include <iostream>

class Node
{
    public:
    int ID ;
    std::string Name ;
    Node * Next = NULL ;
};

class LinkedList
{
    public:
    
    Node * Head ;
    LinkedList()
    {
        Head = NULL ;
    }

    void PushData(std::string Name)
    {
        Node * newNode = new Node ;
        newNode->Name = Name ;

        if(IsEmbyt()) // if there are now data in the list 
        {
            Head = newNode ; // point to the first node in the list             
            newNode->Next = NULL ;
        }
        else 
        {
            Node * Temp = Head; 
            while(Temp->Next != NULL)
            {
                Temp = Temp->Next;
            }       
            Temp->Next = newNode ;
            newNode->Next = NULL;
        }
    }

    void PushDataFirst(std::string Name)
    {
        Node * newNode = new Node ;
        newNode->Name = Name ;

        if(IsEmbyt()) // if there are now data in the list 
        {
            Head = newNode ; // point to the first node in the list             
            newNode->Next = NULL ;
        }
        else 
        {
            newNode->Next = Head;
            Head = newNode ;
        }
    }

    void PushDataBefore(std::string Key , std::string Name)
    {
        Node * newNode = new Node ;
        newNode->Name = Name ;
        Node * Temp = Head ;
        while(Temp != NULL)
        {        
            if(Temp->Next->Name == Key)
            {
                newNode->Next = Temp->Next ;
                Temp->Next = newNode ;               
                break;
            }
            Temp = Temp->Next ;
        }
    }

    void Display(void)
    {
        Node * Temp = Head ;

        while(Temp != NULL)
        {
            std::cout<<Temp->Name<<"\n" ;
            Temp = Temp->Next ;
        }

    }

    bool IsFound(std::string Key)
    {
        Node * Temp = Head ;
        bool found = false ;
        while(Temp != NULL)
        {
           if(Temp->Name == Key)
           {
            found = true ;
           break; 
           }
           else 
           {
             Temp = Temp->Next ;
           }
        }

        return found ;
    }

    bool IsEmbyt(void)
    {
        return (Head == NULL); // if this true return true directly else return flase ansd this short code 
    }

};

/*********************************************************/
class DoubleNode  
{
    public:
    std::string Name ;
    DoubleNode * Next = NULL ;
    DoubleNode * Prev = NULL;
};

class DoubleLinkedList 
{
    public:
    DoubleNode * Head ;

    DoubleLinkedList()
    {
        Head = NULL ;
    }

    void AppendNodeinTail(std::string Name)
    {
        DoubleNode * newNode = new DoubleNode ;
        newNode->Name = Name ;
        if(IsEmpty())
        {
            Head = newNode ;
            newNode->Prev = NULL ;
            newNode->Next = NULL ;
        }
        else 
        {
            DoubleNode * Temp = Head ;
            while(Temp->Next != NULL)
            {
                Temp = Temp->Next ;
            }
            Temp->Next = newNode ;
            newNode->Prev = Temp ;
            newNode->Next = NULL ;
        }
    }

    void AppendinMiddle(std::string Key , std::string Name)
    {
        DoubleNode * newNode = new DoubleNode ;
        newNode->Name = Name ;
        if(IsEmpty())
        {
            Head = newNode ;
            newNode->Prev = NULL ;
            newNode->Next = NULL ;
        }        
        else 
        {
            DoubleNode * Temp = Head ;
            while(Temp->Next->Name != Key)
            {
                Temp = Temp->Next ;
            }
            newNode->Next = Temp->Next ;
            newNode->Prev = Temp ;
            Temp->Next->Prev = newNode ;
            Temp->Next = newNode;
            

        }
    }

    void Display(void)
    {
        DoubleNode * Temp = Head ;
        while(Temp != NULL)
        {
            std::cout<<Temp->Name <<"\n";
            Temp = Temp->Next ;
        }
    }

    void DeleteElement(std::string Key)
    {
        DoubleNode * Temp = Head ;
        while(Temp->Next->Name != Key)
        {
            Temp = Temp->Next ;
        }
        delete Temp->Next ;
        Temp->Next = Temp->Next->Next ;
        Temp->Next->Prev = Temp ;

        std::cout<<"\nthe name of currrent node "<<Temp->Next->Prev->Name <<"\n";
        std::cout<<"the name of prev node "<<Temp->Prev->Name <<"\n";
    }

    bool IsEmpty()
    {
        return (Head == NULL);
    }

    ~DoubleLinkedList()
    {
        DoubleNode * Temp = Head ;
        DoubleNode * Del = Head ;
        while(Temp != NULL)
        {
            delete Del ;
            Temp = Temp->Next ;
            Del = Temp ;
            
        }
        delete Del ;
        delete Temp ;
    }

};



int main()
{


DoubleLinkedList L2;
L2.AppendNodeinTail("Omar");
L2.AppendNodeinTail("Emad");
L2.AppendNodeinTail("Yaser");
L2.AppendNodeinTail("Maged");
L2.AppendNodeinTail("Soha");
L2.AppendNodeinTail("Rabiaa");
L2.AppendNodeinTail("Alaa");
L2.AppendNodeinTail("Soaad");

L2.AppendinMiddle("Maged" , "Fares");

L2.Display();
L2.DeleteElement("Soha");
std::cout<<"After Delete: "<<"\n";
L2.Display();

/*
LinkedList L;
L.PushData("Eslam");
L.PushData("Ahmed");
L.PushData("Ali");
std::cout<<L.IsFound("ff");
std::cout<<"\n";
L.PushDataBefore("Ahmed" , "Samir");
L.Display();*/

    return 0 ;
}