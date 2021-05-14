///////////////////////////////////////////////////////////
//
// Description   :  SINGLY CIRCULAR LINKEDLIST USING C WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  14 May 2021
//
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
 
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int iSize = 0,i = 0;

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertFirst()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail, int 
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////


void InsertFirst (PPNODE Head, PPNODE Tail, int iNo)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = iNo;
    newn -> next = NULL;
    
    if((*Head == NULL)&&(*Tail==NULL))
    {
        *Head = newn;
        *Tail = newn;
        (*Tail) -> next = *Head;
    }

    else
    {
        newn -> next = *Head;
        *Head = newn;
        (*Tail) -> next = newn;
    } 
    iSize++;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertLast()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail, int 
// Description      :   InsertLast Function Add New Node At End Of LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void InsertLast (PPNODE Head, PPNODE Tail, int iNo)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = iNo;
    newn -> next = NULL;
    
    if((*Head == NULL)&&(*Tail==NULL))
    {
        *Head = newn;
        *Tail = newn;
    }

    else
    {
    	(*Tail) -> next = newn;
    	*Tail = newn;
    }
    (*Tail) -> next = *Head; 
    iSize++;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertatPos()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail, int, int
// Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void InsertatPos (PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
	if((iPos<1) || (iPos>iSize+1))
	{
		return;
	}

	else if(iPos == 1)
	{
		InsertFirst (Head, Tail, iNo);
	}

	else if(iPos == iSize + 1)
	{
		InsertLast (Head, Tail, iNo);
	}

	else
	{
		PNODE temp = *Head;
		PNODE newn = NULL;
		newn = (PNODE)malloc(sizeof(NODE));
		newn -> data = iNo;
		newn -> next = NULL;

		for(i = 1; i <= iPos - 1; i++)
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
// Function Name    :   Display()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PNODE Head, PNODE Tail
// Description      :   Display Function Display The Nodes In LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void Display (PNODE Head, PNODE Tail)
{ 
	int i = 0;
    for(i = 1; i <= iSize; i++)
    {
        printf("|%d| => ", Head -> data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   Count()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PNODE Head, PNODE Tail
// Description      :   Count Function Count Number Of Nodes In LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Nodes In LinkedList
//
//
////////////////////////////////////////////////////////////

int Count (PNODE Head, PNODE Tail)
{
    return iSize;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   SearchFirstOccurance()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PNODE Head, PNODE Tail, int
// Description      :   SearchFirstOccurance Function Count First Occurance Of Given Number In LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Nodes In LinkedList
//
//
////////////////////////////////////////////////////////////

int SearchFirstOccurance (PNODE Head, PNODE Tail, int iNo)
{
    int Count = 0;
    do
    {
        Count++;
        if(Head -> data == iNo)
        {
            break;
        }
        Head = Head -> next;
    }
    
    while(Head != Tail -> next);
    return Count;     
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   SearchAllOccurance()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PNODE Head, PNODE Tail, int
// Description      :   SearchAllOccurance Function Count All Occurance Of Given Number In LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Nodes In LinkedList
//
//
////////////////////////////////////////////////////////////

int SearchAllOccurance (PNODE Head, PNODE Tail, int iNo)
{
    int Count = 0;
    do
    {
        if(Head -> data == iNo)
        {
            Count++;
        }
        Head = Head -> next;
    }
    while(Head != Tail -> next);
    return Count;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   14 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteFirst (PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    } 

    else
    {
        (*Head) = temp -> next;
        free(temp);
        iSize--;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteLast()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteLast (PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;
    PNODE target = *Tail;

    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }

    else
    {
        while(temp -> next != target)
        {
            temp = temp -> next;
        }
        free(target);
        *Tail = temp;
        temp -> next = *Head;
        iSize--;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   13 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail, int
// Description      :   DeleteAtPosition Function Remove Existing Node At Any Position In The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void DeleteAtPos (PPNODE Head, PPNODE Tail, int iPos)
{ 
    int i = 0;
    PNODE temp = *Head;
    PNODE target = NULL;

    if((iPos < 1) || (iPos > iSize))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head, Tail);
    }
    
    else if(iPos == iSize)
    {
        DeleteLast(Head, Tail);
    }
    
    else
    {
        for(i = 0; i < iPos - 1; i++)
        {
            target = temp;
            temp = temp -> next;
        }
        target -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
        iSize--;
    }
}

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
	PNODE First = NULL;
	PNODE Last = NULL;
    int iOption = 1, iNo = 0, iRet = 0, iPos = 0;
    
    while(iOption != 0)
    {
        printf("\n______________________________\n");
        printf("1.Insert Node At First Position \n");
        printf("2.Insert Node At Last Position \n");
        printf("3.Insert Node At Given Position\n");
        printf("4.Delete First Node \n");
        printf("5.Delete Last Node \n");
        printf("6.Delete Node At Given Position \n");
        printf("7.Display The Nodes Of Linkedlist \n");
        printf("8.Count The number of Nodes \n");
        printf("9 : Search First Occurance Of A Node \n");
        printf("10 : Search And Count All Occurance Of A Node \n");
        printf("0.Exit the Applications\n");
        printf("\n______________________________\n");
        scanf("%d", &iOption);
    
        switch(iOption)    
        {
    	    case 1 :
    	        printf("Enter the number\n");
    	        scanf("%d", &iNo);
    	        InsertFirst(&First, &Last, iNo);
    	        break;

    	    case 2 :
    	        printf("Enter the number\n");
    	        scanf("%d", &iNo);
    	        InsertLast(&First, &Last, iNo);
    	        break;


            case 3 :
    	        printf("Enter the number\n");
    	        scanf("%d", &iNo);
    	        printf("Enter the Position\n");
    	        scanf("%d", &iPos);
                InsertatPos(&First, &Last, iNo, iPos);
    	        break;

    	    case 4 :
    	        DeleteFirst(&First, &Last);
    	        break;

            case 5 :
    	        DeleteLast(&First, &Last);
    	        break;
        
            case 6 :
    	        printf("Enter the Position\n");
    	        scanf("%d", &iPos);
    	        DeleteAtPos(&First, &Last, iPos);
    	        break;
        
            case 7 :
    	        printf("Contents of Nodes are:\n");
    	        Display(First, Last);
    	        break;
        
            case 8 :
                iRet=Count(First, Last);
    	        printf("Number of Nodes Are :%d", iRet);
    	        break;

            case 9 :
                printf("Enter The Number To Search First Occurance : \n");
                scanf("%d", &iPos);
                iRet = SearchFirstOccurance(First, Last, iPos);
                printf("Found At Position : %d ", iRet);
                break;

            case 10 :
                printf("Enter The Number To Search All Occurance : \n");
                scanf("%d", &iPos);
                iRet = SearchAllOccurance(First, Last, iPos);
                printf("Count Of This Number In LinkedList Is : %d ", iRet);
                break;
        
            case 0 :
    	        printf("Thanks for Using Singly Circular Linklist Applications\n");
    	        break;

    	    default :
    	        printf("You Entered Wrong Option");
    	        break;
        } // end of switch
    } // end of while

    return 0;
} // end of main
