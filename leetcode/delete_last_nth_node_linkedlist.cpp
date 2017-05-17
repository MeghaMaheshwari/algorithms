//Question : Given a linked list, remove the nth node from the end of list and return its head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
      int data;
      ListNode *next;
      ListNode(int x) : data(x), next(nullptr) {}
  };

class LinkedList {

public:
	ListNode* head;

	LinkedList():head(nullptr){};
	
	void AddElem(int data)
	{
		ListNode* NewNode = new ListNode(data);

	    
		if(head == nullptr)
		{
			head = NewNode;
		}
		else
		{
			ListNode* temp = head;
			
			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
		}
	}

	void PrintList()
	{
		ListNode* temp = head;

		while(temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

    ListNode* removeNthFromEnd(int n) {
    
      int length = 1;
      ListNode* temp = head;
          
      if(n == 0)
      {
          return head;
      }
      else if(head->next == nullptr && n == 1)
      {
          head = nullptr;
          return head;
      }
      else
      {
       
           while(temp->next != nullptr)
           {
               temp = temp->next;
               length++;
           }
           
           temp = head;
           
           int before_to_be_removed = (length - n);
           
           if(before_to_be_removed == 0)
		   {
			   //remove head node;
			   head = head->next;
		   }
		   else
		   {
			   while(temp->next != NULL)
			   {
				   if(i == before_to_be_removed)
				   {
					   ListNode* cur = temp;
					   cur->next = cur->next->next;
					   break;
				   }
				   temp = temp->next;
				   i++;
			   }
		   }
      
      }
        
       return head;
    }
};

int main()
{
	LinkedList lst;
	lst.AddElem(1);
	lst.AddElem(2);
	lst.PrintList();
	lst.removeNthFromEnd(2);
    lst.PrintList();
	return 0;
}