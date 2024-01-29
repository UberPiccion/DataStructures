#include "collections.h"

dictionary_item *dict_insert_item(dictionary *dic,char* key, char* value){
    if(dic == NULL) create_dictionary((size_t)64);
    dictionary_item *new_item = malloc(sizeof(dictionary_item));
    new_item->key = set_insert(dic->keyset, key);
    new_item->value = value;
    return new_item;
}

dictionary *create_dictionary(const size_t hashmap_size){
    dictionary *dict = malloc(sizeof(dictionary));
    dict->keyset = set_table_new(hashmap_size);
    dict->items = calloc(hashmap_size,sizeof(dictionary_item));
    return dict;
}
