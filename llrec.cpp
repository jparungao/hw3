#include "llrec.h"

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
