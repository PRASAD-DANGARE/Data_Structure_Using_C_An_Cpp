///////////////////////////////////////////////////////////
//
// Description   :  DOUBLY CIRCULAR LINKEDLIST USING C WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  17 May 2021
//
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
int iSize = 0,i = 0;

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertFirst()
// Function Date    :   17 May 2021
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
	newn -> prev = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
   
    else
    {
        newn -> next = *Head;
    	(*Head) -> prev = newn;
    	*Head = newn;
    }
    (*Head) -> prev = *Tail;
    (*Tail) -> next = *Head;
    iSize++;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertLast()
// Function Date    :   17 May 2021
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
	newn -> prev = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
   
    else
    {
    	(*Tail) -> next = newn;
    	newn -> prev = (*Tail);
    	*Tail = newn;
    }
    (*Head) -> prev = *Tail;
    (*Tail) -> next = *Head;
    iSize++;
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   InsertAtPos()
// Function Date    :   17 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail, int, int
// Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void InsertAtPos (PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = iNo;
	newn -> next = NULL;
	newn -> prev = NULL;
	PNODE temp = *Head;

	if((iPos < 1) || (iPos > iSize + 1))
	{
		return;
	}

	else if(iPos == 1)
	{
		InsertFirst(Head,Tail,iNo);
	}

	else if(iPos == iSize + 1)
	{
		InsertLast(Head,Tail,iNo);
	}

	else
	{
		for(i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}

		newn -> next = temp -> next;
		temp -> next -> prev = newn;
		newn -> prev = temp;
		temp -> next = newn;
		iSize++;
	}
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   17 May 2021
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
	if((*Head == NULL) || (*Tail == NULL))
	{
		return;
	}

	else if(iSize == 1)
	{
		free(Head);
		*Head = NULL;
		*Tail = NULL;
		iSize--;
	}

	else
	{
		*Head = (*Head) -> next;
		free((*Head) -> prev);
	    (*Head) -> prev = *Tail;
        (*Tail) -> next = *Head;
        iSize--;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteLast()
// Function Date    :   17 May 2021
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
	if((*Head == NULL) || (*Tail == NULL))
	{
		return;
	}

	else if(iSize == 1)
	{
		free(Head);
		*Head = NULL;
		*Tail = NULL;
		iSize--;
	}

	else
	{
		*Tail = (*Tail) -> prev;
		free((*Tail) -> next);
	
	    (*Head) -> prev = *Tail;
        (*Tail) -> next = *Head;
        iSize--;
    }
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   DeleteAtPos()
// Function Date    :   17 May 2021
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
	
	PNODE temp = *Head;
	PNODE Target = NULL;
	
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	else if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}

	else if(iPos == iSize)
	{
		DeleteLast(Head,Tail);
	}

	else
	{
		for(i = 1; i < iPos - 1; i++)
		{
			temp = temp -> next;
		}
		Target = temp -> next;
		temp -> next = Target -> next;
		free(Target);
		temp -> next -> prev = temp;
		iSize--;
	}
}

////////////////////////////////////////////////////////////
//
//
// Function Name    :   Display()
// Function Date    :   17 May 2021
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, PPNODE Tail
// Description      :   Display Function Display The Nodes In LinkedList 
//
// Returns          :   NONE
//
//
////////////////////////////////////////////////////////////

void Display (PNODE Head, PNODE Tail)
{
	for(i = 1; i <= iSize; i++)
	{
		printf("|%d| <=> ", Head -> data);
		Head = Head -> next;
	}
    printf("NULL\n");
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

int Count()
{
	return iSize;
}

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
	PNODE First = NULL;
	PNODE Last = NULL;
    int iOption = 1, iNo = 0, iRet = 0, iPos = 0;
    
    while(iOption != 0)
    {
        printf("\n______________________________\n");
        printf("\n1.Insert Node At First Position \n");
        printf("2.Insert Node At Last Position \n");
        printf("3.Insert Node At Given Position\n");
        printf("4.Delete First Node \n");
        printf("5.Delete Last Node \n");
        printf("6.Delete Node At Given Position \n");
        printf("7.Display The Nodes Of Linkedlist \n");
        printf("8.Count The number of Nodes \n");
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
                InsertAtPos(&First, &Last, iNo, iPos);
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
                iRet=Count();
    	        printf("Number of Nodes Are : %d", iRet);
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
