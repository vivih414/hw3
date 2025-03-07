#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
//recursive function
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if(head == nullptr)
	{
		smaller = nullptr;
		larger = nullptr;
		return;
	}

	Node* curr = head;
	head = head->next;

	if(curr->val <= pivot)
	{
		if(smaller == nullptr)
		{
			smaller = curr;
		}
		else
		{
			Node* temp = smaller;
			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = curr;
		}
	}
	else
	{
		if(larger == nullptr)
		{
			larger = curr;
		}
		else
		{
			Node* temp = larger;
			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = curr;
		}
	}
	curr->next = nullptr;
	
	llpivot(head, smaller, larger, pivot);
}