#include "llrec.h"

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  Node* cur = head;
  Node* rest = head->next;
  head = NULL;
  llpivot(rest, smaller, larger, pivot);
  if(cur->val <= pivot){
    cur->next = smaller;
    smaller = cur;
  }else{
    cur->next = larger;
    larger = cur;
  }
}
