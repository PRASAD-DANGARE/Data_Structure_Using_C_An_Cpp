///////////////////////////////////////////////////////////
//
// Description   :  SINGLY LINEAR LINKED LIST USING C
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  13 May 2021
//
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)

struct node
{
    int Data; 
    struct node *Next; 
};

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

void InsertFirst(PPNODE Head,  int No) 
{
    PNODE newn = NULL; 
    
    newn = (PNODE)malloc(sizeof(NODE)); 
    newn->Data = No; 
    newn->Next = NULL; 
    
    if(*Head == NULL) 
    {
        *Head = newn; 
    }
    else  
    {
        newn->Next = *Head; 
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

void InsertLast(PPNODE Head,  int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head; 
    
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Data = No;
    newn->Next = NULL;
    
    if(*Head == NULL)  // LL is empty
    {
        *Head = newn;
    }
    else  // LL contains atleast one node
    {
        while(temp->Next != NULL) 
        {
            temp = temp->Next; 
        }
        temp->Next = newn; 
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
        printf("|%d|->\t",Head->Data); 
        Head = Head -> Next;
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
        Head = Head -> Next; 
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
        PNODE Temp = *Head; 
        if(*Head == NULL) 
        {   
            return; 
        }
        else if ((*Head) -> Next == NULL)   
        {
            free(*Head);        
            *Head = NULL;      
        }
        else    
        {
            (*Head) = (*Head)->Next; 
            free(Temp); 
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
    if(*Head == NULL)   
    {   
        return; 
    }
    else if((*Head)->Next == NULL)  
    {
        free(*Head);        
        *Head = NULL;     
    }
    else    
    {
        while(Temp->Next->Next != NULL) 
        {
            Temp = Temp -> Next; 
        }
        free(Temp->Next); 
        Temp -> Next = NULL; 
    }
}

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   13 May 2021
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions
//
//
//////////////////////////////////////////////////////////////

int main() 
{
    int iRet = 0; 
    PNODE First = NULL;
    InsertFirst(&First,51);  
    InsertFirst(&First,21);
    InsertFirst(&First,11);
    InsertLast(&First,111);
    printf("Actual nodes\n");
    Display(First);                 
    DeleteFirst(&First);
    printf("Nodes after delete first\n");
    Display(First);
    DeleteLast(&First);
    printf("Nodes after delete last\n");
    Display(First);
    
    //printf("%d\n", sizeof(NODE)); // 8 size of (structure)
    //printf("%d\n", sizeof(PNODE)); // 4
    //printf("%d\n", sizeof(PPNODE)); // 4

    return 0;
}
