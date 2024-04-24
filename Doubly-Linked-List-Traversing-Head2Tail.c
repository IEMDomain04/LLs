//function to traverse a doubly link list from top to bottom


void print_data(head); //function declaration


void print_data(node *head) { // function
    node *TravNode = head;
    printf("Displaying the Contents of the Doubly Link List \n\n");
    while(TravNode != NULL) {
        printf("%d\n", TravNode->data);
        TravNode = TravNode->next;
    }
}
