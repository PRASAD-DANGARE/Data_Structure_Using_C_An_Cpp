///////////////////////////////////////////////////////////
//
// Description   :  QUEUE USING LINKEDLIST IN C++ WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  18 May 2021
//
///////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} NODE, *PNODE;

//////////////////////////////////////////////////
//
// Class Name  : Queue
// Description : This Class represents Queue Using Linkedlist
//
//////////////////////////////////////////////////

class Queue
{
    private : 
        PNODE Head;
        int iSize;

    public : 
        Queue();
        void Display();
        int Count();
        void Enqueue(int);
        int Dequeue();
};

    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   Queue
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class Queue
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

Queue :: Queue()
{
    Head = NULL;
    iSize = 0;
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   ----
    // Description      :   Display Function Display The Elements In Queue
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

void Queue :: Display()
{
    PNODE temp = Head;
    cout << "Elements of queue are : \n";

    while(temp != NULL)
    {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }
    cout << "\n";
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Count()
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   ----
    // Description      :   Count Function Count Number Of Elements In The Queue 
    //
    // Returns          :   int
    //                  :   Return Number Of Elements In The Queue
    //
    //
    ////////////////////////////////////////////////////////////

int Queue :: Count()
{
    return iSize;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Enqueue()
  // Function Date    :   18 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int 
  // Description      :   Enqueue Function Add New Element At Last Of The Queue 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void Queue :: Enqueue(int iNo) // insertlast
{
    PNODE newn = new NODE;
    newn -> data = iNo;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iSize++;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Dequeue()
  // Function Date    :   18 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int 
  // Description      :   Dequeue Function Delete Element From Beginning Of The Queue 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

int Queue :: Dequeue() // deletefirst
{
    if(Head == NULL)
    {
        cout << "Queue is empty \n";
        return -1;
    }
    else
    {
        int iNo = Head -> data;
        PNODE temp = Head;
        Head = Head -> next;
        delete temp;
        iSize--;

        return iNo;
    }
}

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   18 May 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{
    Queue obj;

    int iChoice = 1, iNo = 0, iRet = 0;

    while(iChoice != 0)
    {
        cout << "Please enter the option : \n";
        cout << "1 : Insert The Elements : \n";
        cout << "2 : Delete The Elements : \n";
        cout << "3 : Display The Elements : \n";
        cout << "4 : Count The Number Of Elements : \n";
        cout << "0 : Terminate The Application \n";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1 :
                cout << "Enter The Elements : \n";
                cin >> iNo;
                obj.Enqueue(iNo);
                break;

            case 2 :
                iRet = obj.Dequeue();
                cout << "Removed Elements is : " << iRet << "\n";
                break;

            case 3 :
                obj.Display();
                break;

            case 4 :
                iRet = obj.Count();
                cout << "Number Of Elements in Queue are " << iRet << "\n";
                break;

            case 0 : 
                cout << "Thankyou For Using This Application \n";
                break;

            default : 
                cout << "Enter Valid Option \n";
                break;
        }
    }
    return 0;
}
