#include<stdlib.h>
typedef struct QueueNode{
    int info;
    struct node *link;
}*NODE;
NODE ptr = NULL;
NODE front = NULL;
NODE rear = NULL;
int main(){
    int data,choice;
    while(1)
    {
        printf("\n");
        printf("1.Insert Data (Front)\n");
        printf("2.Insert Data (Rear)\n");
        printf("3.Delete Data (Front)\n");
        printf("4.Delete Data (Rear)\n");
        printf("5.Display Data\n");
        printf("6.Quit\n");
        printf("Enter your desired choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: printf("Enter the data to insert: ");
                scanf("%d",&data);
                insert_front(data);
                break;
        case 2: printf("Enter the data to insert: ");
                scanf("%d",&data);
                insert_rear(data);
                break;
        case 3: delete_front();
                break;
        case 4: delete_rear();
                break;
        case 5: printf("The Data in the Double Ended Queue is:\n");
                display();
                break;
        case 6: exit(0);
        default:
                printf("Invalid choice.\n");
                break;
        }
    }
return 0;
}
NODE createNode(int d){
    NODE node;
    node = (NODE*)malloc(sizeof(struct QueueNode));
    node->info = d;
    node->link = NULL;
    return node;
}
void insert_front(int d){
    NODE node = createNode(d);
    if(front == NULL){
        front = node;
        rear = node;
        return;
    }
    node->link = front;
    front = node;
}
void display(){
	if(front==NULL){
		printf("Queue is empty\n");
		return;
	}
	ptr = front;
	while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    return;
}
void insert_rear(int d){
    NODE node = createNode(d);
    if(front == NULL){
        front = node;
        rear = node;
    }
    else{
        rear->link = node;
        rear = node;
    }
    return;
}
void delete_front(){
    NODE temp;
	if(front==NULL){
		printf("Queue Underflow\n");
	}
	else{
	temp = front;
	printf("Data to be deleted is %d",temp->info);
	front = front->link;
	free(temp);
	}
}
void delete_rear(){
    NODE temp;
    ptr = front;
    if(front == NULL){
		printf("Queue Underflow\n");
    }
    if(front == rear){
        free(front);
        front = NULL;
        rear = NULL;
        return;
    }
    while(ptr->link!=rear){
       ptr = ptr->link;
    }
    temp = rear;
    rear = ptr;
	printf("Data to be deleted is %d",temp->info);
    ptr->link = NULL;
    free(temp);
}
