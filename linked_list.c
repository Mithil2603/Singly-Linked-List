#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *ptr, *temp;

void create(int n);
void display();
int count();
void insert_at_beginning();
void insert_at_end();
void insert_before();
void insert_after();
void delete_first();
void delete_last();
void delete_before();
void delete_after();

int main()
{
    int choice, n;
    printf("\n********Select any one from the following options********\n");
    printf("Enter 1 to create a node.\n");
    printf("Enter 2 to display the nodes.\n");
    printf("Enter 3 to insert a node at the beginning.\n");
    printf("Enter 4 to insert a node at the end.\n");
    printf("Enter 5 to insert a node before a specific node.\n");
    printf("Enter 6 to insert a node after a specific node.\n");
    printf("Enter 7 to delete the first node.\n");
    printf("Enter 8 to delete the last node.\n");
    printf("Enter 9 to delete the node before a specific node.\n");
    printf("Enter 10 to delete the node after a specific node.\n");
    while(choice != 0)
    {
        printf("\nEnter Your Choice from above code: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Define how many nodes do you want?: ");
            scanf("%d", &n);
            create(n);
        break;
        case 2:
            display();
        break;
        case 3:
            insert_at_beginning();
        break;
        case 4:
            insert_at_end();
        break;
        case 5:
            insert_before();
        break;
        case 6:
            insert_after();
        break;
        case 7:
            delete_first();
        break; 
        case 8:
            delete_last();
        break;
        case 9:
            delete_before();
        break;
        case 10:
            delete_after();
        break;
        default:
            printf("Invalid Choice!\n");
        break;
        }
    }
    getch();
    return 0;
}

void create(int n)
{
    int num, i;
    head = (struct node *) malloc (sizeof(struct node));
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter data for the node 1: ");
        scanf("%d", &num);
        head->data = num;
        head->next = NULL;
        temp = head;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *) malloc (sizeof(struct node));
            if(newnode == NULL)
            {
                printf("Empty List!\n");
            }
            else
            {
                printf("Enter data for the node %d: ", i);
                scanf("%d", &num);
                newnode->data = num;
                newnode->next = NULL;

                temp->next = newnode;
                temp = temp->next;
            }
        }
        printf("Node Inserted!\n");
    }
}

void insert_at_beginning()
{
    int num;
    newnode = (struct node *) malloc (sizeof(struct node));
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        printf("Enter the data in newnode: ");
        scanf("%d", &num);
        newnode->data = num;
        newnode->next = head;

        head = newnode;
        printf("Node Inserted!\n");
    }
}

void display()
{
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        printf("List: Head->");
        ptr = head;
        while(ptr!=NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

void insert_at_end()
{
    int n;
    newnode = (struct node *) malloc(sizeof(struct node));
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Enter data in the last node: ");
        scanf("%d", &n);
        newnode->data = n;
        newnode->next = NULL;

        temp->next = newnode;
        printf("Node Inserted!\n");
    }
}

int count()
{
    int count=0;
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

void insert_before()
{
    int pos, i, num, c;
    c = count();
    printf("Enter The Position before which you want to insert the newnode: ");
    scanf("%d", &pos);
    newnode = (struct node *) malloc(sizeof(struct node));
    if(pos > c)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        if(pos == 1)
        {
            printf("Enter the data in the newnode: ");
            scanf("%d", &num);
            newnode->data = num;
            newnode->next = head;
            head = newnode;
            printf("Node Inserted!\n");
        }
        else
        {
            temp = head;
            for(i=1; i<pos; i++)
            {
                ptr = temp;
                temp = temp->next;
            }
            printf("Enter the data in the newnode: ");
            scanf("%d", &num);
            newnode->data = num;
            newnode->next = temp;
            ptr->next = newnode;
            printf("Node Inserted!\n");
        }
    }
}

void insert_after()
{
    int pos, i, num, c;
    c = count();
    printf("Enter The Position after which you want to insert the newnode: ");
    scanf("%d", &pos);
    newnode = (struct node *) malloc(sizeof(struct node));
    if(pos > c)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        if(pos == 0)
        {
            printf("Enter the data in the newnode: ");
            scanf("%d", &num);
            newnode->data = num;
            newnode->next = head;
            head = newnode;
            printf("Node Inserted!\n");
        }
        else
        {
            temp = head;
            for(i=1; i<pos+1 ; i++)
            {
                ptr = temp;
                temp = temp->next;
            }
            printf("Enter the data in the newnode: ");
            scanf("%d", &num);
            newnode->data = num;
            newnode->next = temp;
            ptr->next = newnode;
            printf("Node Inserted!\n");
        }
    }
}

void delete_first()
{
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        temp = head;
        head = head->next;
        ptr = temp;
        free(ptr);
        printf("First Node Deleted!\n");
    }
}

void delete_last()
{
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
        printf("Last Node Deleted!\n");
    }
}

void delete_before()
{
    int pos, i, c;
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        c = count();
        temp = head;
        printf("Enter the position before which you want to delete the node: ");
        scanf("%d", &pos);
        if(pos > c)
        {
            printf("Invalid Position!\n");
        }
        else
        {
            if(pos == 1)
            {
                printf("There is no node available before the first node.\n");
            }
            else if(pos == 2)
            {
                ptr = temp;
                temp = temp->next;
                head = ptr->next;
                free(ptr);
                printf("Node Deleted!\n");
            }
            else
            {
                for(i=1; i<pos-1; i++)
                {
                    ptr = temp;
                    temp = temp->next;
                }
                ptr->next = temp->next;
                free(temp);
                printf("Node Deleted!\n");
            }
        }
    }
}

void delete_after()
{
    int pos, i, c;
    if(head == NULL)
    {
        printf("Empty List!\n");
    }
    else
    {
        c = count();
        printf("Enter the position after which you want to delete the node: ");
        scanf("%d", &pos);
        if(pos > c)
        {
            printf("Invalid Position!\n");
        }
        else
        {
            temp = head;
            for(i=1; i<pos+1; i++)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = temp->next;
            free(temp);
            printf("Node Deleted!\n");
        }
    }
}