/********************************************************************
          Program: daily6 reverse a linked list
          Author: Mark Priscella
          Date: 2/7/18
          Purpose: The purpose of this program is to reverse a linked
          list.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
  int data;
  Node* next;
};

Node* reverse( Node* head );

int main( int argc, char* argv[] )
{
  Node* head = NULL;
  int i = 0;
  Node* temp;

  /* set up a list with values 9->8->7....->0 */
  for( i = 0; i < 10; i++ )
    {
      temp = (Node*)malloc( sizeof(Node) );
      if( temp == NULL )
	{
	  printf( "Out of memory?\n" );
	  exit(1);
	}
      temp->data = i;
      temp->next = head;
      head = temp;
    }

  /* call your function to reverse the list (should work for any list givin the head node). */
  head =  reverse( head );

  /* print the reversed list. */
  temp = head;
  while( temp != NULL )
    {
      printf( "%d\n", temp->data );
      temp = temp->next;
    }

  return 0;
}

/*define your function here */
/* this function will reverse a linked list */
Node* reverse( Node* head )
{
  /* three nodes to keep places */
  Node* prev_node = NULL;
  Node* curr_node = NULL;
  Node* next_node = NULL;

  /* make current node equal to head node */
  curr_node = head;

  /* make sure current node doesn't equal NULL */
  while( curr_node != NULL )
    {
      /* next node equal to node after current */
      next_node = curr_node->next;
      /* link current node to previous node */
      curr_node->next = prev_node;
      /* make previous node current node */
      prev_node = curr_node;
      /* make current node next node */
      curr_node = next_node;
    }

  /* make head previous node */
  head = prev_node;

  return head;
}