#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
//recursive function
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if(head == NULL)
	{
		return;
	}

	Node* curr = head;
	head = head->next;

	if(curr->val <= pivot)
	{
		curr->next = smaller;
		smaller = curr;
	}
	else
	{
		curr->next = larger;
		larger = curr;
	}
	
	llpivot(head, smaller, larger, pivot);
}