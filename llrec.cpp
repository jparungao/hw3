#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

//Helper: processes the list rooted at 'curr' and appends each node to the end of either smaller or larger list.
//smallTail and largeTail point to the 'next' pointer (head pointer) where next node should be attatched
static void llpivotHelper(Node* curr, Node**& smallTail, Node**& largeTail, int pivot)
{
  if(curr == NULL){
    return;
  }
  Node* rest = curr->next;
  curr->next = NULL;

  if(curr->val <= pivot){
    *smallTail = curr;
    smallTail = &(curr->next);
  } else {
    *largeTail = curr;
    largeTail = &(curr->next);
  }
  llpivotHelper(rest, smallTail, largeTail, pivot);
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  smaller = NULL;
  larger = NULL;

  Node** smallTail = &smaller;
  Node** largeTail = &larger;

  llpivotHelper(head, smallTail, largeTail, pivot);
  head = NULL;
}
