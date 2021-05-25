///////////////////////////////////////////////////////////
//
// Description   :  SINGLY LINEAR LINKED LIST USING C++ WITH Constructor, Distructor
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  17 May 2021
//
///////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

typedef struct node // create structure and give new name 
{
    int data;
    struct node * next;
} NODE, *PNODE;

//////////////////////////////////////////////////
//
// Class Name  :  SinglyLL
// Description : This Class represents Singly linear linked list
//
//////////////////////////////////////////////////

class SinglyLL // create class
{
    private:  // access specifier
        PNODE Head; // main madla first la replace kala with Head
        int iSize; // characteristics dont initilize it, per object aak linkedlist asel tar taya object madhe taja head and size asel

    public:
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   SinglyLL
    // Function Date    :   17 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class SinglyLL
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////
  
        SinglyLL() // default constructor, Behaviours
        {
            cout << "Inside Constructor \n";
            Head = NULL;
            iSize = 0;
        }
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   ~SinglyLL
    // Function Date    :   17 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Distructor Of Class ~SinglyLL
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

        ~SinglyLL()
        {
            cout << "Inside Destructor \n";
            PNODE temp = NULL;
            while(Head != NULL)
            {
                temp = Head;
                Head = Head -> next;
                delete temp;
            }
        }
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Count()
    // Function Date    :   17 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   ----
    // Description      :   Count Function Count Number Of Nodes In LinkedList 
    //
    // Returns          :   int
    //                  :   Return Number Of Nodes In LinkedList
    //
    //
    ////////////////////////////////////////////////////////////

        int Count() // time compilxcity is 0
        {
            return iSize; // there is no need to travel the linkedlist (head pointer) 
            // because we have iSize variable which automatically incremented when we add the node so we just return the iSize
        }
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   17 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   PPNODE Head
    // Description      :   Display Function Display The Nodes In LinkedList 
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

        void Display() // Behaviours
        {
            PNODE temp = Head; // Head madhe first node cha address ahei so head la nehi move karaicha manun temp variable gatla
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
  // Function Name    :   InsertFirst()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int 
  // Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

  
        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn -> data = iNo;
            newn -> next = NULL;

            if(Head == NULL) // ll is empty
            {   
                Head = newn;
            }   
            else // ll contain atleast one node
            {
                newn -> next = Head;
                Head = newn;
            }
            iSize++;   // jar node add hoat asel tar size ++ kara 
        }

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertLast()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int 
  // Description      :   InsertLast Function Add New Node At End Of LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////
  
        void InsertLast(int iNo)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn -> data = iNo;
            newn -> next = NULL;
            PNODE temp = Head; // create temperary variables because if we travel the head then inside object the value get changed

            if(Head == NULL) // ll is empty
            {   
                Head = newn;
            }   
            else // ll contain atleast one node
            {
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
  // Function Name    :   DeleteFirst()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   ----
  // Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

        void DeleteFirst()
        {
            if(Head != NULL)
            {
                PNODE temp = Head;
                Head = Head -> next;
                delete temp;
                iSize--; // if we write below if the 0 will become -1
            }   
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteLast()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   ----
  // Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

        void DeleteLast()
        {
            if(Head == NULL) // ll is empty
            {
                return;
            }
            else if(Head -> next == NULL) // ll contain 1 node
            {
                delete Head;
                Head = NULL;
            }
            else // ll contain more than 1 node
            {
                PNODE temp = Head;
                while(temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete (temp -> next);
                temp -> next = NULL;
                iSize--;
            }
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertAtPos()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int, int
  // Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

        void InsertAtPos(int iNo, int iPos)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn -> data = iNo;
            newn -> next = NULL;
            PNODE temp = Head;
            
            if((iPos < 1) || (iPos > iSize + 1))
            {
                return;
            }

            if(iPos == 1)
            {
                InsertFirst(iNo);
            }
            else if(iPos == iSize + 1)
            {
                InsertLast(iNo);
            }
            else
            {
                for(int i = 1; i < iPos-1; i++)
                {
                    temp = temp -> next;
                }
                newn -> next = temp -> next;
                temp -> next = newn;
                iSize++;
            }
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteAtPos()
  // Function Date    :   17 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int
  // Description      :   DeleteAtPosition Function Remove Existing Node At Any Position In The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

        void DeleteAtPos(int iPos)
        {
            PNODE temp = Head;
            PNODE Target = NULL;

            if((iPos < 1) || (iPos > iSize))
            {
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }

            else if(iPos == iSize)
            {
                DeleteLast();
            }

            else
            {
                for(int i = 1; i < iPos - 1; i++)
                {
                    temp = temp -> next;
                }
                Target = temp -> next;
                temp -> next = Target -> next;
                delete Target;
                iSize--;
            }
        }
};

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   17 May 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{
    int iChoice = 1, iNo = 0, iValue = 0;

    SinglyLL * obj1 = new SinglyLL; // create object of SinglyLL Class

    while(iChoice != 0)
    {
        cout << "Enter Your Choice : " << "\n";
        cout << "1 : Insert at first position " << "\n";
        cout << "2 : Insert at last position " << "\n";
        cout << "3 : Insert at given position " << "\n";
        cout << "4 : Delete first Node" << "\n";
        cout << "5 : Delete last Node" << "\n";
        cout << "6 : Delete at given position " << "\n";
        cout << "7 : Display The LinkedList " << "\n";
        cout << "8 : Count The Number Of Nodes " << "\n";
        cout << "0 : Exit the application " << "\n";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1 :
                cout << "Enter Number \n";
                cin >> iNo;
                obj1 -> InsertFirst(iNo);
                break;

            case 2 :
                cout << "Enter Number \n";
                cin >> iNo;
                obj1 -> InsertLast(iNo);
                break;

            case 3 :
                cout << "Enter Number \n";
                cin >> iNo;
                cout << "Enter Position \n";
                cin >> iValue;
                obj1 -> InsertAtPos(iNo,iValue);
                break;

            case 4 :
                obj1 -> DeleteFirst();
                break;

            case 5 :
                obj1 -> DeleteLast();
                break;

            case 6 :
                cout << "Enter The Position \n";
                cin >> iNo;
                obj1 -> DeleteAtPos(iNo);
                break;

            case 7 :
                obj1 -> Display();
                break;

            case 8 :
                iNo = obj1 -> Count();
                cout << "Number Of Elements Are : " << iNo << "\n";
                break;

            case 0 :
                cout << "Thankyou for using the application \n";
                delete obj1;
                break;

            default : 
                cout << "Please Give Valid Input " << "\n";
        } // end of switch
    } // end of while
    return 0;
} // end of main
