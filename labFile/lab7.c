#include <stdio.h>
#include <stdlib.h>

#define TRUE   1
#define FALSE  0

#define COUNT 10

typedef struct nodeStruct
{
 int elem;
 struct nodeStruct*  next;
} node;
 

/* returns the length of the list         */
/* written with a pass-by-value parameter */
/* calling code:                          */
/*     node* head = NULL;               */
/*      ...                               */
/*     int length = listLength (head);    */
int listLength (node* hd)
{
/*
 int length = 0;
 while (hd != NULL)
   {
    length++;
    hd = hd->next;
   }
 return length;
*/
/*
	if (hd->next != NULL){
		int length = listLength(hd->next)+1;
		return length;
	}else
	{
	return 1;
	}
*/
	if (hd == NULL){
		return 0;
	}else
	{
		return 1+listLength(hd->next);
	}
}

int getFirstValue (node* hd)
{
 if (hd != NULL)
   return hd->elem;
 else
   return -999;   /* returns -999 if list is empty */
}

int isEmpty (node* hd)
{
 if (hd == NULL)
   return TRUE;
 else
   return FALSE;
}


void show (node* hd)
{
 while (hd != NULL)
   {
    printf ("%d, ", hd->elem);
    hd = hd->next;
   }
 printf ("\n");
}

/*  code to dynamically allocate and initallize a struct of  */
/*   the type node                                         */
/*  the address of the newly created node is returned        */
node* newLinkedNode (int value, node* n)  {
      node* tmp = (node *) malloc ( sizeof(node) );
      tmp->elem = value;
      tmp->next = n;
      return tmp;
   }

/* code to insert values in increasing order		   */
/*   smaller values placed closer to the front of the list */
/*   larger values placed closer to the end of the list    */
/* function is written recursively                         */
node* insertInOrderR (node* h, int value)  {
    if (h == NULL || value < h->elem)
      h = newLinkedNode ( value, h );
    else
      h->next = insertInOrderR(h->next, value);
    return h;
  }


/* code to insert values in increasing order               */
/*   smaller values placed closer to the front of the list */
/*   larger values placed closer to the end of the list    */
void insertInOrder (node** hd, int val)
{
 node* curr = *hd;
 node* prev = NULL;

 /* set curr to refer to the node in the list that is >= val */
 /*   prev will be set to the node just before curr */
 while ((curr != NULL) && (curr->elem < val))
   {
    prev = curr;
    curr = curr->next;
   }

 /* create the node to add into the list */
 node* ptr = (node*) malloc (sizeof(node));
 ptr->elem = val;
 ptr->next = curr;

 /* if prev is null, insert at the front of the list */
 if (prev == NULL)
   {
    *hd = ptr;
   }
 else
   {  /* otherwise insert right after prev */
    prev->next = ptr;
   }
}

/* code to insert values in increasing order               */
/*   smaller values placed closer to the front of the list */
/*   larger values placed closer to the end of the list    */
node* insertInOrder2 (node* hd, int val)
{
 node* curr = hd;
 node* prev = NULL;

 /* set curr to refer to the node in the list that is >= val */
 /*   prev will be set to the node just before curr */
 while ((curr != NULL) && (curr->elem < val))
   {
    prev = curr;
    curr = curr->next;
   }

 /* create the node to add into the list */
 node* ptr = (node*) malloc (sizeof(node));
 ptr->elem = val;
 ptr->next = curr;

 /* if prev is null, insert at the front of the list */
 if (prev == NULL)
   {
    hd = ptr;
   }
 else
   {  /* otherwise insert right after prev */
    prev->next = ptr;
   }

 /* return the newly updated head of the list */
 return hd;
}


int main (int argc, char**argv)
{
  node* head = NULL;
  node* head2 = NULL;
  int i;
  int temp;

  /* adding values to the front of the list */
  for (i = 0 ; i < COUNT; ++i)
    {
     temp = rand() % 100;
     printf ("In main(): Inserting value: %6d\n", temp);

     /* head being sent as C pass-by-value */
     head = insertInOrder2 (head, temp);

     /* head2 being sent as C pass-by-value */
     head2 = insertInOrderR (head2, temp + 100);

     printf ("The list has %d nodes\n", listLength(head));
     show (head);
     printf ("List 2 has %d nodes\n", listLength(head2));
     show (head2);

     printf ("\n");
    }



}
