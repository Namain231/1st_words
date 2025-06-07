#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node* ll_end(Node* head, int data){
  Node* newNode = createNode(data);
  if(head==NULL){
    return newNode;
  }
  Node* temp = head;
  while(temp->next!= NULL){
    temp= temp->next;
  }
  temp->next = newNode;
  return head;
}

Node* rr_ll(Node* head1, Node* head2, Node* head3, int l1, int l2, int l3){
  Node* final_head = NULL;
  Node* temp1 = head1;
  Node* temp2 = head2; 
  Node* temp3 = head3;
  int i = 0, j = 0, k = 0;
  while(i < l1 || j < l2 || k < l3){
    if(i < l1){
      final_head = ll_end(final_head, temp1->data);
      temp1 = temp1->next;
      i++;
    }
    if(j < l2){
      final_head = ll_end(final_head, temp2->data);
      temp2 = temp2->next;
      j++;
    }
    if(k < l3){
      final_head = ll_end(final_head, temp3->data);
      temp3 = temp3->next;
      k++;
    }
  } 
  return final_head;
};

int main(){
  int l1, l2, l3;
  printf("Enter the lengths of the linked lists: ");
  scanf("%d %d %d", &l1, &l2, &l3); 

  Node* head1 = NULL;
  printf("Enter l1 data: ");
  for(int i=0; i<l1; i++){
    int temp;
    scanf("%d", &temp);
    head1 = ll_end(head1, temp);
  }

  Node* head2 = NULL;
  printf("Enter l2 data: ");
  for(int i=0; i<l2; i++){
    int temp;
    scanf("%d", &temp);
    head2 = ll_end(head2, temp);
  }

  Node* head3 = NULL;
  printf("Enter l3 data: ");
  for(int i=0; i<l3; i++){
    int temp;
    scanf("%d", &temp);
    head3 = ll_end(head3, temp);
  }

  Node* final_ll = NULL;
  final_ll = rr_ll(head1, head2, head3, l1, l2, l3);
  printf("Final linked list: ");
  Node* temp = final_ll;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}