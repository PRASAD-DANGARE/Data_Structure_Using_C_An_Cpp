///////////////////////////////////////////////////////////
//
// Description   :  STACK USING ARRAY IN C++ WITH Constructor And Distructor
// Input         :  Int
// Output        :  Int
// Author        :  Prasad Dangare
// Date          :  18 May 2021
//
///////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//////////////////////////////////////////////////
//
// Class Name  : Stack
// Description : This Class represents User Defined Stack Creation Using Linkedlist
//
//////////////////////////////////////////////////

class Stack
{
    private :
        int * Arr;
        int iSize;
        int Top;

    public : 
        Stack(int);
        ~Stack();
        void Push(int);
        int Pop();
        void Display();
};

    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   Stack
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class Stack
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

Stack :: Stack(int iNo)
{
    iSize = iNo;
    Top = -1;
    Arr = new int[iSize];
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   ~Stack
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   NONE
    // Description      :   This Is Distructor Of Class Stack
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

Stack :: ~Stack()
{
    delete [] Arr;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Push()
  // Function Date    :   18 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   int 
  // Description      :   Push Function Add New Node / Element At Top Of A Stack 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void Stack :: Push(int iNo)
{
    if(Top == iSize -1)
    {
        cout << "Stack Is Full \n";
        return;
    }
    else
    {
        Top++;
        Arr[Top] = iNo;
    }
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Pop()
  // Function Date    :   18 May 2021
  // Function Author  :   Prasad Dangare
  // Parameters       :   -- 
  // Description      :   Pop Function Remove Node / Element From Top Of A Stack 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

int Stack :: Pop()
{
    if(Top == -1)
    {
        cout << "Stack Is Empty ";
        return -1;
    }
    else
    {
        int iNo = Arr[Top];
        Top--;
        return iNo;
    }
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   18 May 2021
    // Function Author  :   Prasad Dangare
    // Parameters       :   ----
    // Description      :   Display Function Display The Nodes / Elements In Stack 
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

void Stack :: Display()
{
    if(Top == -1)
    {
        cout << "Stack Is Empty \n";
    }
    else
    {
        for(int i = 0; i <= Top; i++)
        {
            cout << Arr[i] << "\t";
        }
        cout << "\n";
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
    int iNo = 0, iRet = 0;

    cout << "Enter The Size Of Array : \n";
    cin >> iNo;

    Stack obj(iNo);
    obj.Push(11);
    obj.Push(21);
    obj.Push(51);

    obj.Display();

    iRet = obj.Pop();
    cout << "Poped Element is : " << iRet << "\n";
    iRet = obj.Pop();
    cout << "Poped Element is : " << iRet << "\n";

    return 0;
}
