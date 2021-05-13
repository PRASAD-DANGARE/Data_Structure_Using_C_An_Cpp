///////////////////////////////////////////////////////////
//
// Description   :  DOUBLY LINEAR LINKED LIST USING C WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  13 May 2021
//
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev; // +
};                   // total memory requird for one node is 20 bytes 8 byte for next pointer, 8 byte for prev pointer, 4 byte for data integer

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertFirst()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, int 
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////


void InsertFirst(PPNODE Head, int No) // this functions are called helper functions
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL; // +

    if(*Head == NULL) // linkedlist is empty, NULL == *Head , *Head madhe null ahei manje first madhe null ahei. 
    {
        *Head = newn; // so insert first node in First through Head pointer
    }
    else // linkedlist contain atleast one node
    {
        newn -> next = *Head; // navin mula la sang tuja hat juna mula war thev, right hand
        (*Head) -> prev = newn; // + juna paila node chaya previous madhe newn cha address takicha ahei
        *Head = newn;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertLast()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, int 
// Description      :   InsertLast Function Add New Node At End Of LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE Temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL; // +

    if(*Head == NULL) // linkedlist is empty
    {
        *Head = newn;
    }
    else // linkedlist contain atleast one node
    {
        while(Temp -> next != NULL)
        {
            Temp = Temp -> next;
        }
        Temp -> next = newn; // temp jaya node la thambla ahei taja next madhe newn cha address
        newn -> prev = Temp; // + newn cha previous madhe Temp jaya node la thambla ahei taja address
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   Display()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head
// Description      :   Display Function Display The Nodes In LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////


void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|<=>", Head -> data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   Count()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head
// Description      :   Count Function Count Number Of Nodes In LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Nodes In LinkedList
//
//
////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {   
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL) // empty linked list
    {
        return;
    }
    else if((*Head) -> next == NULL) // single node
    {
        free(*Head);
        *Head = NULL;
    }
    else // more than one node
    {
        *Head = (*Head) -> next;
        free((*Head) -> prev); // +
        (*Head) -> prev = NULL; // + if we dont do this Display function give segmentation fault
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteLast()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;

    if(*Head == NULL) // empty linked list
    {
        return;
    }
    else if((*Head) -> next == NULL) // single node
    {
        free(*Head);
        *Head = NULL;
    }
    else // more than one node
    {
        while(Temp -> next -> next != NULL)
        {
            Temp = Temp -> next;
        }
        free(Temp -> next);
        Temp -> next = NULL; // if we dont do this Display function give segmentation fault
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, int, int
// Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iSize = 0, i = 0;
    PNODE newn = NULL;
    PNODE Temp = *Head;

    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,No);
    }

    else if(iPos == iSize + 1)
    {
        InsertLast(Head, No);
    }
    
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(i = 1; i < iPos - 1; i++)
        {
            Temp = Temp -> next;
        }
        newn -> next = Temp -> next;
        Temp -> next -> prev = newn; // +
        Temp -> next = newn;
        newn -> prev = Temp; // +
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, int
// Description      :   DeleteAtPosition Function Remove Existing Node At Any Position In The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = 0, i = 0;

    // PNODE Target = NULL; using 2 pointer

    PNODE Temp = *Head;

    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }

    else if(iPos == iSize)
    {
        DeleteLast(Head);
    }

    else
    {
        for(i = 1; i < iPos - 1; i++)
        {
            Temp = Temp -> next;
        }
        Temp -> next = Temp -> next -> next;
        free(Temp -> next -> prev);
        Temp -> next -> prev = Temp;

        //Target = Temp -> next;
        //Temp -> next = Target -> next;
        //Temp -> next -> prev = Temp;
        //free(Target); 
    }
}

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   13 May 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{
    PNODE First = NULL; // first madhe paila node cha address

    int iOption = 1, iValue = 0, iRet = 0, iPos = 0;

    while(iOption != 0)
    {
        printf("\n**************************************\n");
        printf("Please Select The Option\n");
        printf("1 : Insert The Node At First Position \n");
        printf("2 : Insert The Node At Last Position \n");
        printf("3 : Insert The Node At Given Position \n");
        printf("4 : Delete The First Node \n");
        printf("5 : Delete The Last Node \n");
        printf("6 : Delete The Node At Given Position \n");
        printf("7 : Display The Contents Of Given Linked List\n");
        printf("8 : Count The Number Of Nodes In Linked List \n");
        printf("0 : Exit From The Application \n");
        scanf("%d", &iOption);
        printf("\n**************************************\n");

        switch (iOption)
        {
            case 1 :  
                printf("Enter Data To Insert : \n");
                scanf("%d", &iValue);
                InsertFirst(&First, iValue);
                break;

            case 2 :
                printf("Enter Data To Insert : \n");
                scanf("%d", &iValue);
                InsertLast(&First, iValue);  
                break;

            case 3 :  
                printf("Enter Data To Insert : \n");
                scanf("%d", &iValue);
                printf("Enter Position : \n");
                scanf("%d", &iPos);
                InsertAtPos(&First, iValue, iPos);  
                break;

            case 4 :  
                DeleteFirst(&First);
                break;

            case 5 :  
                DeleteLast(&First);
                break;

            case 6 :  
                printf("Enter the position\n");
                scanf("%d",&iPos);
                DeleteAtPos(&First,iPos);
                break;

            case 7 :  
                printf("Contents Of Linkedlist Are : ");
                Display(First);
                break;

            case 8 :  
                iRet = Count(First);
                printf("Number Of Nodes Are : %d\n", iRet);
                break;

            case 0 : 
                printf("Thankyou For Using Doubly Linear LinkedList\n"); 
                break;
        
            default:
                printf("Please Enter Valid Option\n");
                break;
        } // end of switch
    } // end of while

    return 0;

} // end of main
