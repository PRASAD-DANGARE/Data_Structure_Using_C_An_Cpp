///////////////////////////////////////////////////////////
//
// Description   :  SINGLY CIRCULAR LINKEDLIST USING C++ WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  14 May 2021
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
// Class Name  :  SinglyLL
// Description : This Class represents Singly linear linked list
//
//////////////////////////////////////////////////


class SinglyCL
{

    private :
        PNODE Head;
        PNODE Tail;
        int iSize;
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   SinglyLL
    // Function Date    :   14 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class SinglyLL
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

    public :
        SinglyCL()
        {
            Head = NULL;
            Tail = NULL;
            iSize = 0;
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertFirst()
  // Function Date    :   14 May 2021
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

            if((Head == NULL) && (Tail == NULL)) // LL is empty
            {
                Head = newn;
                Tail = newn;
                //iSize++;
                //Tail -> next = Head; // to maintain circular nature
            }
            else // ll contain atleast one node
            {
                newn -> next = Head;
                Head = newn;
                //iSize++;
                //Tail -> next = Head;
            }
            iSize++;
            Tail -> next = Head;
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertLast()
  // Function Date    :   14 May 2021
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

            if((Head == NULL) && (Tail == NULL))
            {
                Head = newn;
                Tail = newn;
                //iSize++;
                //Tail -> next = Head; // to maintain circular nature
            }
            else // ll contain atleast one node
            {
                Tail -> next = newn; 
                Tail = Tail -> next; // Tail = newn;
                //iSize++;
                //Tail -> next = Head;
            }
            iSize++;
            Tail -> next = Head;
        }
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Count()
    // Function Date    :   14 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   ----
    // Description      :   Count Function Count Number Of Nodes In LinkedList 
    //
    // Returns          :   int
    //                  :   Return Number Of Nodes In LinkedList
    //
    //
    ////////////////////////////////////////////////////////////


        int Count()
        {
            return iSize;
        }
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   14 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   PPNODE Head
    // Description      :   Display Function Display The Nodes In LinkedList 
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

        void Display()
        {
            PNODE temp = Head;
            int i = 0;
            for(i = 1; i <= iSize; i++)
            {
                cout << temp -> data << "\t";
                temp = temp -> next;
            }
            cout << "\n";

            /*
            do
            {
                cout << temp -> data;
                temp = temp -> next;
            } while(temp != Tail-> next);
            */
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteFirst()
  // Function Date    :   14 May 2021
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
            if(iSize == 0) // empty ll
            {
                return;
            }
            else if(iSize == 1) // single node, (Head == Tail)
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                iSize--;
            }
            else // more than one node
            {
                Head = Head -> next;
                delete(Tail -> next);
                Tail -> next = Head; 
                iSize--;
            }
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteLast()
  // Function Date    :   14 May 2021
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
            if(iSize == 0) // empty ll
            {
                return;
            }
            else if(iSize == 1) // single node
            {
                delete Head;
                Head = NULL;
                Tail = NULL;
                iSize--;
            }
            else // more than one node
            {
                PNODE temp = Head;
                int i = 0;
                for(i = 1; i < iSize - 1; i++)
                {
                    temp = temp -> next;
                }
                delete Tail;
                Tail = temp;
                Tail -> next = Head;
                iSize--;
            }
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertAtPos()
  // Function Date    :   14 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int, int
  // Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

        void InsertAtPos(int no, int iPos)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;
            PNODE Temp = Head;

            if((iPos < 1) || (iPos > iSize + 1)) // invalid position
            {
                return;
            }
            if(iPos == 1) // first position
            {
                InsertFirst(no);
            }
            else if(iPos == iSize + 1) // last position
            {
                InsertLast(no);
            }
            else // in between first and last position
            {
                for(int i = 1; i< iPos - 1 ; i++) // if we dont do iPos-1 it goes to 5 node
                {
                    Temp = Temp -> next;
                }
                newn -> next = Temp -> next;
                Temp -> next = newn;
                iSize++;
            }
        }
  
  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteAtPos()
  // Function Date    :   14 May 2021
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
// Function Date   :   14 May 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{

    SinglyCL obj;
    int iChoice = 1, iRet = 0, iPos = 0, iValue = 0;

    while(iChoice != 0)
    {
        cout << "Enter your choice : \n";
        cout << "1 : Insert First \n";
        cout << "2 : Insert Last \n";
        cout << "3 : Insert At Position \n";
        cout << "4 : Delete First \n";
        cout << "5 : Delete Last \n";
        cout << "6 : Delete At Position \n";
        cout << "7 : Display Linkedlist \n";
        cout << "8 : Count Nodes Of Linkedlist\n";
        cout << "0 : Exit the application \n";
        cin >> iChoice;

        switch (iChoice)
        {
            case 1 :
                cout << "Enter Number : \n";
                cin >> iValue;
                obj.InsertFirst(iValue);
                break;

            case 2 :
                cout << "Enter Number : \n";
                cin >> iValue;
                obj.InsertLast(iValue);
                break;
        
            case 3 :
                cout << "Enter Number : \n";
                cin >> iValue;
                cout << "Enter Position : \n";
                cin >> iPos;
                obj.InsertAtPos(iValue,iPos);
                break;

            case 4 :
                obj.DeleteFirst();
                break;

            case 5 :
                obj.DeleteLast();
                break;

            case 6 :
                cout << "Enter The Position : \n";
                cin >> iPos;
                obj.DeleteAtPos(iPos);
                break;

            case 7 :
                obj.Display();
                break;

            case 8 :
                iRet = obj.Count();
                cout << "Number Of Nodes Are : " << iRet << "\n";
                break;

            case 0 :
                cout << "Thankyou for using this application \n";
                break;

            default:
                cout << "Please Give Valid Option : \n";
                break;
        } // end ofswitch
    } // end of while
    return 0;
} // end of main
