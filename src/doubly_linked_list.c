#include "collections.h"

doubly_list_node *doubly_get_tail(doubly_list_node **head){
    doubly_list_node *current_node = *head;
    doubly_list_node *last_node = NULL;

    while (current_node){
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
}
doubly_list_node *doubly_pop(doubly_list_node **head){
    doubly_list_node *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    current_head->next = NULL;

    return current_head;
}
doubly_list_node *doubly_append(doubly_list_node **head, doubly_list_node *item){
    doubly_list_node *tail = doubly_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}
doubly_list_node *doubly_remove_item(doubly_list_node **head, doubly_list_node *item){
    if(*head == item){
        doubly_pop(head);
        return *head;
    }
    doubly_list_node *current_node = *head;
    while(current_node->next == NULL){
        if(current_node->next == item){
            doubly_list_node *remove_node = current_node->next;
            current_node->next = current_node->next->next;
            current_node->next->prev = current_node;
            doubly_delete_item(remove_node);
            return *head;
        }
        current_node = current_node->next;
    }
    return *head;
}
void doubly_delete_item(doubly_list_node *item){
    free(item);
    return;
}
doubly_list_node *doubly_insert_after_item(doubly_list_node **head, doubly_list_node *item, doubly_list_node *after_item){
    doubly_list_node *current_node = *head;
    while(current_node->next != NULL){
        if(current_node == after_item){
            current_node->next->prev = item;
            item->next = current_node->next;
            current_node->next = item;
            item->prev = current_node;
            return *head;
        }
        current_node = current_node->next;
    }
    return *head;
}
doubly_list_node *doubly_insert_before_item(doubly_list_node **head, doubly_list_node *item, doubly_list_node *before_item){
    doubly_list_node *current_node = doubly_get_tail(head);
    while(current_node->prev != NULL){
        if(current_node == before_item){
            current_node->prev->next = item;
            item->prev = current_node->prev;
            current_node->prev = item;
            item->next = current_node;
            return *head;
        }
        current_node = current_node->prev;
    }
    return *head;
}