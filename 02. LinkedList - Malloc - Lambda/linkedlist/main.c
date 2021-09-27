#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
}*stnode;

void createNodeList(int n);     //function to create the list
void NodeInsertatEnd(int num);	//function to insert node at the end
void displayList();             //function to display the list
void pushHead(int val);
int popEnd();
int popHead();
void pushAtPos(int val, int pos);
int popAtPos(int pos);
int peekAtPos(int pos);

int main()
{
    int n,num;

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list are : \n");
    displayList();
    printf("\n Input data to insert at the end of the list : ");
    scanf("%d", &num);
    NodeInsertatEnd(num);
    printf("\n Data, after inserted in the list are : \n");
    displayList();
    printf("\n Insert data to add at the head of the list: ");
    scanf("%d", &num);
    pushHead(num);
    displayList();
    printf("\n Pop the last element from the list\n");
    printf(" The popped element was: %d\n", popEnd());
    displayList();
    printf(" Pop the head element from the list\n");
    printf(" Popped element from head of the list was: %d\n", popHead());
    displayList();
    pushAtPos(2,4);
    displayList();
    printf("\n Insert position of list to be popped: ");
    scanf("%d", &n);
    printf("Node at position %d with value %d was popped.\n", n, popAtPos(n));
    displayList();
    printf("Insert position on the list to peek at: ");
    scanf("%d", &n);
    printf("Node at position %d has value: %d\n", n, peekAtPos(n));
    displayList();
    return 0;
}

int peekAtPos(int pos) {
    int val;
    struct node *temp;
    if(stnode == NULL) {
        printf("The list is empty\n");
    }
    temp = stnode;
    for(int i = 2; i <= pos; i++) {
        temp = temp->nextptr;

        if(temp == NULL)
            break;
    }
    if (temp != NULL){
        val = temp->num;
    }
    return val;
}

int popAtPos(int pos) {
    struct node *preNode, *toDel;
    int val;

    if (stnode == NULL) {
        printf("The list is empty\n");
    }
    preNode = stnode;
    toDel = stnode;

    for (int i = 2; i <= pos; i++) {
        preNode = toDel;
        toDel = toDel->nextptr;

        if(preNode == NULL)
            break;
    }
    if (preNode != NULL){
        if(toDel == stnode)
            stnode = stnode->nextptr;

        preNode->nextptr = toDel->nextptr;
        val = toDel->num;
        toDel->nextptr = NULL;
        free(toDel);
    }
    else
        printf("Cannot delete node at that position");

    return val;
}

void pushAtPos(int val, int pos) {
    struct node *temp, *newNode;
    newNode = (struct node*) malloc(sizeof (struct node));
    newNode->num = val;
    newNode->nextptr = NULL;
    temp = stnode;
    for(int i = 2; i <= pos-1; i++){
        temp = temp->nextptr;

        if(temp == NULL)
            break;
    }
    if(temp != NULL){
        newNode->nextptr = temp->nextptr;
        temp->nextptr = newNode;
    }
    else {
        printf("Insert is not possible at given position\n");
    }
    printf(" Inserted new Node at position %d with value %d\n", pos, val);
}

int popHead() {
    int val;
    struct node *temp;
    if (stnode == NULL) {
        printf("The list is empty.\n");
    }

    temp = stnode->nextptr;
    val = stnode->num;
    stnode = temp;
    return val;
}

int popEnd(){
    int val;
    struct node *lastDel, *preLast;
    lastDel = stnode;
    preLast = stnode;
    while(lastDel->nextptr != NULL) {
        preLast = lastDel;
        lastDel = lastDel->nextptr;
    }
    if (lastDel == stnode) {
        stnode = NULL;
    }
    else {
        preLast->nextptr = NULL;
    }
    val = lastDel->num;
    free(lastDel);
    return val;
}

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &num);

        stnode-> num = num;
        stnode-> nextptr = NULL; //Links the address field to NULL
        tmp = stnode;
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
}

void NodeInsertatEnd(int num)
{
    struct node *fnNode, *tmp;
    fnNode = (struct node*)malloc(sizeof(struct node));
    if(fnNode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        fnNode->num = num;     //Links the data part
        fnNode->nextptr = NULL;
        tmp = stnode;
        while(tmp->nextptr != NULL)
            tmp = tmp->nextptr;
        tmp->nextptr = fnNode;  //Links the address part
    }
}

void pushHead(int val){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory not allocated");
    }
    else {
        newNode->num = val;
        newNode->nextptr = stnode;
        stnode = newNode;
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
}
