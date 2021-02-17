#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		struct node *link;
	}*Node;
Node top = NULL;
void push(int item);
void display();
void pop();
int main()
{
    int choice,item;
while(1)
{
    printf("\n");
	printf("1.Push in the stack\n");
	printf("2.Pop from the stack\n");
	printf("3.Display elements of stack\n");
	printf("4.Quit\n");
	printf("\nEnter desired option: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the value: \n");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
        default:
            printf("Invalid choice.\n");
	}
}
	return 0;
}
void push(int item)
{
	Node newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = item;
	newNode -> link = top;
	top = newNode;
}
void display()
{
    Node ptr;
    if(top == NULL){
        printf("Stack is empty\n");
    }
    else
    {
        ptr = top;
    printf("Stack elements are: \n");
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    }
}
void pop()
{
    if(top == NULL){
        printf("Stack underflow\n");
    }
    else{
        printf("Popped element is %d \n",top->data);
        top = top->link;
    }

}
