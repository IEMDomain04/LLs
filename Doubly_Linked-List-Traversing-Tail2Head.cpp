// Function Traversing from Tail to Head

void Head2Tail(node* tail) {
	
    node* TravNode = tail;
    printf("\nDisplaying Doubly Linked List!!!");
    while (TravNode != NULL) {
        printf("\n%d ", TravNode->data);
        TravNode = TravNode->prev;
    }
}
