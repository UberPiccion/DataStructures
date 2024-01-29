#include "collections.h"

linked_list_node *list_get_tail(linked_list_node **head){
    linked_list_node *current_node = *head;
    linked_list_node *last_node = NULL;

    while (current_node){
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}

linked_list_node *list_append(linked_list_node **head, linked_list_node *item){
    linked_list_node *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

linked_list_node *list_pop(linked_list_node **head){
    linked_list_node *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;

    return current_head;
}

linked_list_node *list_remove_node(linked_list_node **head, linked_list_node *item){
    if(*head == item){
        list_pop(head);
        return *head;
    }
    linked_list_node *current_node = *head;
    while(current_node->next != NULL){
        if(current_node->next == item){
            linked_list_node *remove_node = current_node->next;
            current_node->next = current_node->next->next;
            list_delete_node(remove_node);
            return *head;
        }
        current_node = current_node->next;
    }
    return *head;
}

void list_delete_node(linked_list_node *item){
    free(item);
    return;
}

string_item *string_item_new(const char *string){
    string_item *item = malloc(sizeof(string_item));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;

}