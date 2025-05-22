#pragma once

#include <iostream>
#include <string>


using namespace std;

template <class T>
class clsDblLinkedList{

protected:

   int __Size = 0 ;

public:

class Node
{
   public:

    T value;
    Node *next;
    Node *Prev;
};

Node *Head = NULL;

void InsertAtBegenning(T Value){

   Node *New_Node = new Node();

   New_Node->value = Value;
   New_Node->next = Head;
   New_Node->Prev = NULL;

   if (Head != NULL)
   {
      Head->Prev = New_Node;
   }
   Head = New_Node;

   __Size++;
}

void InsertAfter(Node* Current , T Value){

   Node * New_Node = new Node();

   New_Node->value = Value;
   New_Node->next = Head->next;
   New_Node->Prev = Head;

   if (Current->next != NULL)
   {
      Current->next->Prev = New_Node;
   }
   
   Current->next = New_Node;

   __Size++;
}

void InsertEnd(T Value){

   Node *New_Node = new Node();

   New_Node->value = Value;
   New_Node->next = NULL;

   if (Head == NULL)
   {
      New_Node->Prev = NULL;
      Head = New_Node;
   }
else{
   Node *Current = Head;
   while (Current->next != NULL)
   {
      Current = Current->next;
   }
   Current->next = New_Node;
   New_Node->Prev = Current;
}
   __Size++;
}

void DeleteNode(Node *&CurrentDelete){

   if (Head == CurrentDelete)
   {
      Head = CurrentDelete->next;
   }
   
   if (CurrentDelete->next != NULL)
   {
      CurrentDelete->next->Prev = CurrentDelete->Prev;
   }
   
   if (CurrentDelete->Prev != NULL)
   {
      CurrentDelete->Prev->next = CurrentDelete->next;
   }
   
   delete CurrentDelete;
   __Size--;
}

void DeleteFirstNode(){
   
   Node* Temp = Head;

   if (Head == NULL)
   {
      return;
   }
   
   Head = Head->next;

   if (Head != NULL)
   {
      Head->Prev = NULL;
   }
   delete Temp;
   __Size--;
}

void DeleteLastNode(){

   Node *Current = Head;

   if (Head == NULL)
   {
      return;
   }

   if (Current->next == NULL)
   {
      delete Current;
      Head = NULL;
      return;
   }

   while (Current->next->next != NULL)
   {
      Current = Current->next;
   }

   Node *Temp = Current->next;
   Current->next = NULL;
   delete Temp;
   __Size--;
}

void PrintList(){

   Node * Current = Head;

   while (Current != NULL)
   {
      cout<<Current->value<<"  ";
      Current = Current->next;
   }
   cout<<"\n";
}

Node* Find(T Value){

   Node *Current = Head;

   while (Current != NULL)
   {
      if (Current->value == Value)
      {
        return Current;
      }
      Current = Current->next;
   }
   return NULL;
}

int Size(){
  return __Size;
}

bool IsEmpty(){
   return (__Size == 0 ? true : false);
}

void Clear(){

   while (__Size > 0)
   {
      DeleteFirstNode();
   }
}

void Reverse(){

   Node * Current = Head;
   Node* Temp = nullptr;

   while (Current != nullptr)
   {
      Temp = Current->Prev;
      Current->Prev = Current->next;
      Current->next = Temp;
      Current = Current->Prev;
   }
   
   if (Temp != nullptr)
   {
      Head = Temp->Prev;
   }
   
}

Node *GetNode(int Index){

   int Count = 0 ;

   if (Index > __Size -1 || Index < 0)
      return nullptr;

   Node* Current = Head;

   while (Current != NULL && (Current->next != NULL))
   {
      if (Count == Index)
         break;
      
      Current = Current->next;
      Count++;
   }
   
  return Current;

}

T GetItem(int item){
   
   Node *Current = GetNode(item);

   if (Current == NULL)
      return 0 ;
   else
      return Current->value;
}

bool UpdateItem(int item , T NewValue){

   Node *Curr = GetNode(item);

   if (Curr != NULL)
   {
      Curr->value = NewValue;
      return true;
   }
   else
   {
      return false;
   }
}

bool InsertAfter(int item , T ValueOfNewNode){

   Node* Curr = GetNode(item);

   if (Curr != NULL)
   {
      InsertAfter(Curr,ValueOfNewNode);
      return true;
   }
   else
   {
      return false;
   }
}



};
