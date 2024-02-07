#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node1
{
    struct linked_list_node1 *next;
}linked_list_node;
typedef struct string_item1
{
    linked_list_node node;
    const char *string;
}string_item;

linked_list_node *list_get_tail(linked_list_node **head);
linked_list_node *list_append(linked_list_node **head, linked_list_node *item);
linked_list_node *list_pop(linked_list_node **head);
linked_list_node *list_remove_node(linked_list_node **head, linked_list_node *item);
void list_delete_node(linked_list_node *item);

string_item *string_item_new(const char *string);
#endif //LINKED_H

#ifndef DOUBLY_LINKED_H
#define DOUBLY_LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_list_node1
{
    struct doubly_list_node1 *prev;
    struct doubly_list_node1 *next;
}doubly_list_node;

doubly_list_node *doubly_get_tail(doubly_list_node **head);
doubly_list_node *doubly_append(doubly_list_node **head, doubly_list_node *item);
doubly_list_node *doubly_pop(doubly_list_node **head);
void doubly_delete_item(doubly_list_node *item);
doubly_list_node *doubly_remove_item(doubly_list_node **head, doubly_list_node *item);
doubly_list_node *doubly_insert_after_item(doubly_list_node **head, doubly_list_node *item, doubly_list_node *after_item);
doubly_list_node *doubly_insert_before_item(doubly_list_node **head, doubly_list_node *item, doubly_list_node *before_item);

#endif //DOUBLY_LINKED_H

#ifndef SET_H
#define SET_H
#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef struct set_node1{
    const char *key;
    size_t key_len;
    struct set_node1 *next;
}set_node;

typedef struct set_table1
{
    set_node **nodes;
    size_t hashmap_size ;
}set_table;

size_t djb33x_hash(const char *key, const size_t keylen);
set_table *set_table_new (const size_t hashmap_size);
set_node *set_insert(set_table *table, const char *key);
set_node *set_find(set_table *table, const char *key);
void set_remove(set_table *table, const char *key);

#endif //SET_H

#ifndef DICTIONARY_H
#define DICTIONARY_H
typedef struct dictionary_item1{
    set_node *key;
    char *value;
}dictionary_item;
typedef struct dictionary1
{
    set_table *keyset;
    dictionary_item **items;
}dictionary;

dictionary *create_dictionary(const size_t hashmap_size);
dictionary_item *dict_insert_item(dictionary *dic,char* key, char* value);
dictionary_item *dict_find_item(dictionary *dic,char* key);
void dict_remove_item(dictionary *dic,char* key);

#endif //DICTIONARY_H