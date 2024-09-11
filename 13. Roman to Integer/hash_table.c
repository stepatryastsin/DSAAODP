#pragma warning(disable : 4996)
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Создание нового элемента хеш-таблицы
PRIVATE struct ht_item* _ht_create_item(const char* key, const char* value) {
    struct ht_item* item = (struct ht_item*)malloc(sizeof(struct ht_item));
    if (!item) {
        fprintf(stderr, "Error: Unable to allocate memory for item\n");
        return NULL;
    }
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}


// Удаление элемента хеш-таблицы
PRIVATE void _ht_delete_item(struct ht_item* item) {
    if (item) {
        free(item->key);
        free(item->value);
        free(item);
    }
}

// Простой хеш-функция (используем "double hashing")
PRIVATE int _ht_hash(const char* s, const int prime, const int num_buckets) {
    long hash = 0;
    const int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hash += (long)pow(prime, len - (i + 1)) * s[i];
        hash %= num_buckets;
    }
    return (int)hash;
}

// Комбинированная хеш-функция с двойным хешированием
PRIVATE int _ht_get_hash(const char* key, const int num_buckets, const int attempt) {
    const int hash_a = ht_hash(key, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(key, HT_PRIME_2, num_buckets);
    return (hash_a + attempt * (hash_b + 1)) % num_buckets;
}


// Функция для вставки ключа и значения в таблицу
PRIVATE void _ht_insert(struct hash_table* ht, const char* key, char* value) {
    int i = 0;
    struct ht_item* item = ht_create_item(key, value);
    int index = ht_get_hash(item->key, ht->count, i);
    struct ht_item* cur = ht->items[index];
    while (cur != NULL) {
        int index = ht_get_hash(item->key, ht->count, i);
        cur = ht->items[index];
        i++;
    }
    ht->items[index] = value;
    ht->count++;
    return 1;
}

// Функция для поиска значения по ключу в таблице
PRIVATE char* _ht_search(struct hash_table* ht, const char* k) {
    int i = 0;
    int index = ht_get_hash(k, ht->count, i);
    struct ht_item* cur = ht->items[index];
    while (cur != NULL) {
        if (strcmp(ht->items[index]->key, k) == 0) {
            return ht->items[index]->value;
        }
        index = ht_get_hash(k, ht->count, i);
        cur = ht->items[index];
        i++;
    }
    return NULL;
}

// Функция для удаления пары ключ и значение
static struct ht_item ht = { NULL,NULL };
PRIVATE int _ht_delete(struct hash_table* ht, const char* k) {
    int i = 0;
    int index = ht_get_hash(k, ht->count, i);
    struct ht_item* cur = ht->items[index];
    while (cur != NULL) {
        if (strcmp(ht->items[index]->key, k) == 0) {
            _ht_delete_item(cur);
            ht->items[index] = &ht;
        }
        index = ht_get_hash(k, ht->count, i);
        cur = ht->items[index];
        i++;
    }
    ht->count--;
}
PRIVATE char* _ht_get(struct hash_table* ht, const char* k) {

}

// Создание новой хеш-таблицы
struct hash_table* ht_create() {
    struct hash_table* table = malloc(sizeof(struct hash_table));
    if (!table) {
        fprintf(stderr, "Error: Unable to allocate memory for hash table\n");
        return NULL;
    }
    table->size = 53;  // Начальный размер хеш-таблицы
    table->count = 0;
    table->items = calloc(table->size, sizeof(struct ht_item*));
    if (!table->items) {
        fprintf(stderr, "Error: Unable to allocate memory for hash table items\n");
        free(table);
        return NULL;
    }
    return table;
}

// Удаление всей хеш-таблицы
void ht_delete_table(struct hash_table* table) {
    if (table) {
        for (size_t i = 0; i < table->size; i++) {
            struct ht_item* item = table->items[i];
            if (item) {
                _ht_delete_item(item);
            }
        }
        free(table->items);
        free(table);
    }
}

void ht_insert(struct hash_table* ht, const char* k, const char* v)
{
    _ht_insert(ht, k, v);
    return;
}

const char* ht_serach(struct hash_table* ht, const char* k)
{
    return  _ht_search(ht, k);
}

const int ht_delete(struct hash_table* ht, const char* k)
{
    return _ht_delete(ht, k);
}




