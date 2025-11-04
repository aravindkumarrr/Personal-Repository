struct Node{
    int data; 
    Node* next;
};

void insertBeg(Node** head, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head; 
    *head = newNode;
}

void insertEnd(Node**head, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(*head = NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head; 
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertPos(Node**head, int pos, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(pos==0){
        insertBeg(head, val);
        return;
    }
    Node* temp = *head; 
    for(int i=0;i<pos && temp!=NULL; i++){
        temp=temp->next;
    }
    if(temp==NULL) return;
    temp->next = newNode;
}

void deleteBeg(Node** head){
    if(*head==NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(Node** head){
    if(*head == NULL) return;
    if((*head)->next==NULL){
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head; 
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
