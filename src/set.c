#include "collections.h"
size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;

    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }

    return hash;
}

set_table *set_table_new (const size_t hashmap_size){
    set_table *table = malloc(sizeof(set_table));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size ;
    table->nodes = calloc(table->hashmap_size , sizeof(struct set_node *));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

set_node *set_insert(set_table *table, const char *key){
    const size_t key_len = strlen(key);
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node *head = table->nodes[index];
    if (!head)
    {
        table->nodes[index] = malloc(sizeof(set_node));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;
        return table->nodes[index];
    }
    set_node *new_item = malloc(sizeof(set_node));
    if (!new_item)
    {
        return NULL;
    }
    set_table *newtable = set_table_new(table->hashmap_size*2);
    for(size_t i = 0; i < table->hashmap_size;i++){
        set_insert(newtable, table->nodes[index]->key);
    }
    table = newtable;
    return set_insert(newtable, key);
    /*new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;
    set_node *tail = head;
    while (head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;*/
}
set_node *set_find(set_table *table, const char *key){
    const size_t key_len = strlen(key);
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    for(size_t i = 0; i < table->hashmap_size;i++){
        if(table->nodes[index]->key == key){
            return table->nodes[index];
        }
    }
    return NULL;
}
void set_remove(set_table *table, const char *key){
    free(set_find(table, key));
}

