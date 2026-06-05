/* Tanvir Ahmed
This code implements some basic operation of singly linked list like inserting in the beginning and end, delete operation, and display operation
*/

#include "main.h"

//this function takes an item and insert it in the linked list pointed by root.
node*  insert_front(node *root, int item)
{
	node *temp;
	//create a new node and fill-up the node
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL) //if there is no node in the linked list
        root=temp;
    else //there is an existing linked list, so put existing root after temp
    {
        temp->next = root; //put the existing root after temp
        root = temp; //make the temp as the root!
    }
  	return root;

}

node* reverse(node* root)
{	
	node* main_list = root;
	node* reverse_list = NULL;
	node* temp = NULL;
	//going through the list passed in 
	while(main_list != NULL){
		//temp will store the un reversed list as we move through it
		temp = main_list->next;
		//move first reverse node will be null then move backward thorugh root list
		main_list->next = reverse_list;
		reverse_list = main_list;
		//move to next node in root 
		main_list = temp;
	}
	
	return reverse_list;
}

void insertToPlace(node* head, int val, int place)
{
	//create node to insert
	node *temp = (node*)malloc(sizeof(node));
	temp->data = val;
	temp->next = NULL;

	//use counter variable to move to insertion point
	int counter = 0;
	while(head->next!=NULL && counter<place-2){
		head = head->next;
		counter++;
	}
	

	//insert temp node into list
	temp->next = head->next;
	head->next = temp;
	
	
	
}

void display(node* t)
{
  printf("\nPrinting your linked list.......");

	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}

}
int main()
{
	node *root=NULL; //very important line. Otherwise all function will fail
	node *t;
	int ch, ele, val, place;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
	    scanf("%d",&ch);
		if(ch==0)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter data(an integer): ");
			scanf("%d",&ele);
			root = insert_front(root, ele);

      display(root);

		}
		if(ch==2)
		{
			printf("\nList reversed.");
			root = reverse(root);
      display(root);

		}
	  if(ch==3)
	  {
		  printf("\nEnter data (an integer) and place (>1) separated by space: ");
		  scanf("%d %d", &val, &place);
		  insertToPlace(root, val, place);
      display(root);

		}
	}
  return 0;
}
