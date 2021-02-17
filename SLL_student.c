#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char name[20];
    int regno;
    char branch[20];
    char sem[10];
    char phone[20];
    struct node *link;
}*StudentNODE;

StudentNODE create();
StudentNODE insert_front();
void display();
void count();
StudentNODE insert_end();
StudentNODE delete_front();
StudentNODE delete_end();
StudentNODE update(int reg);

StudentNODE start = NULL;
int countt=0;

int main()
{
    int choice;
    int i,n,reg;
    while(1)
    {
        printf("1:Create SLL of Student Nodes (using front insertion)\n");
        printf("2:Display the details of all students\n");
        printf("3:Count of all students\n");
        printf("4:Insertion at the end\n");
        printf("5:Deletion from the end\n");
        printf("6:Insertion at the front\n");
        printf("7:Deletion from the front\n");
        printf("8:Update student information based on regno\n");
        printf("9:Exit\n");
        printf("\nEnter your desired choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1 : printf("How many students you want to add: ");
                 scanf("%d",&n);
                 for(i=0;i<=n-1;i++)
                    start = insert_front();
                 break;

        case 2: display();
                break;

        case 3: count();
                break;

        case 4: start = insert_end();
                break;

        case 5: start = delete_end();
                break;

        case 6: start = insert_front();
                break;
        case 7: start = delete_front();
                break;
        case 8: printf("Enter the Registration no: ");
                scanf("%d",&reg);
                start = update(reg);
                break;

        case 9: exit(0);

        default:
            printf("Invalid choice\n");

        }
    }
return 0;
}
StudentNODE create()
{
    StudentNODE snode;
    snode = (StudentNODE)malloc(sizeof(struct node));
    printf("Enter student details:\n");
    printf("\nName: ");
    scanf("%s",snode->name);
    printf("\nReg No: ");
    scanf("%d",&snode->regno);
    printf("\nBranch: ");
    scanf("%s",snode->branch);
    printf("\nSemester: ");
    scanf("%s",snode->sem);
    printf("\nPhone no: ");
    scanf("%s",snode->phone);
    snode ->link = NULL;
    countt++;
    return snode;
}
StudentNODE insert_front()
{
    StudentNODE temp;
    temp = create();
    if(start == NULL)
    {
        return temp;
    }
    temp ->link = start;
    start = temp;
    return start;
}
void display()
{
    StudentNODE curr;
    if(start == NULL)
    {
        printf("No data found\n");
        return;
    }
    printf("Students Details: \n");
    curr = start;
    while(curr!=NULL)
    {
    printf("\nName: %s",curr->name);
    printf("\nReg No: %d",curr->regno);
    printf("\nBranch: %s",curr->branch);
    printf("\nSem: %s",curr->sem);
    printf("\nPhone: %s",curr->phone);
    printf("\n________________\n");
    curr = curr->link;
    }
}
void count(){
printf("Total no of records = %d\n",countt);
}
StudentNODE insert_end()
{
    StudentNODE curr,temp;
    temp = create();
    if(start == NULL)
    {
      return temp;
    }
    curr = start;
    while(curr->link !=NULL)
    {
         curr = curr->link;
    }
    curr->link = temp;
    return start;
}
StudentNODE delete_front()
{
    StudentNODE temp;
    if(start == NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }

    if(start->link == NULL) //for single node
    {
            printf("\nThe Student having Reg no:%d is deleted from record\n",start->regno);
            countt--;
            free(start);
            return NULL;
    }
    temp = start;
    start = start->link;
    printf("\nThe Student having Reg no:%d is deleted from record\n",temp->regno);
    countt--;
    free(temp);
    return start;
}
StudentNODE delete_end()
{
     StudentNODE curr,prev;
     if(start == NULL)
     {
        printf("List is empty\n");
        return NULL;
     }

     if(start->link == NULL)
     {
        printf("\nThe Student having Reg no:%d is deleted from record\n",start->regno);
        free(start);
        countt--;
        return NULL;
     }

     prev = NULL;
     curr = start;
     while(curr->link!=NULL)
     {
         prev = curr;
         curr = curr->link;
     }

      printf("\nThe Student having Reg no:%d is deleted from record\n",curr->regno);
      free(curr);
      prev->link = NULL;
      countt--;
      return start;
}
StudentNODE update(int reg)
{   int choice,flag = 0;
    StudentNODE current;
    if(start == NULL){
        printf("Empty list\n");
        return;
    }
    current = start;
    while(current!=NULL)
    {
      if(current->regno == reg){
        printf("\n");
        printf("1. Name\n");
        printf("2. Registration No\n");
        printf("3. Branch\n");
        printf("4. Semester\n");
        printf("5. Phone No\n");
        printf("\nWhich information you want to update?\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter new Name: ");
                scanf("%s",current->name);
                flag = 1;
                break;
        case 2: printf("Enter new Reg no: ");
                scanf("%d",&current->regno);
                flag = 1;
                break;
        case 3: printf("Enter new branch: ");
                scanf("%s",current->branch);
                flag = 1;
                break;
        case 4: printf("Enter semester: ");
                scanf("%s",current->sem);
                flag = 1;
                break;
        case 5: printf("Enter the new phone number: ");
                scanf("%s",current->phone);
                flag = 1;
                break;
        }
      }
        current = current->link;
    }
    if(flag == 0){
    printf("\nReg no %d is not in the record.\n\n",reg);
    }
    return start;
}
