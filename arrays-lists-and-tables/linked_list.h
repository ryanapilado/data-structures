typedef struct ll_node {
    int value;
    struct ll_node *next;
} ll_node;

typedef struct linked_list {
    ll_node *head;
} linked_list;

void ll_add(linked_list *l, int value) {
    ll_node *new_node = malloc(sizeof(ll_node));
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}

void ll_delete(linked_list *l, int index) {
    if (index == 0) {
        l->head = l->head->next;
        return;
    }

    ll_node *curr = l->head;
    while (index > 1) {
        if (!curr->next) {
            return;
        }
        curr = curr->next;
        index--;
    }
    curr->next = curr->next->next;

}

int ll_search(linked_list *l, int value) {
    ll_node *curr = l->head;
    int i = 0;
    while (curr) {
        if (curr->value == value) {
            return i;
        }
        i++;
    }
    return -1;
}

void ll_print(linked_list *l) {
    ll_node *curr = l->head;
    while (curr) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

void ll_init(linked_list *l) {
    l->head = NULL;
}