#ifndef  HASH_TABLE_H
#define HASH_TABLE_H

#define HT_PRIME_1 151
#define HT_PRIME_2 163

#define PRIVATE static

/// <summary>
/// Hash table for 53 elements for task
/// </summary>




struct ht_item {
	char* key;
	char* value;
};

struct hash_table {
	unsigned  int size;
	unsigned  int count;
	struct ht_item** items;
};

struct hash_table* ht_create();
void ht_delete_table(struct hash_table* htable);


void ht_insert(struct hash_table* ht, const char* k, const char* v);
const char* ht_serach(struct hash_table* ht, const char* k);
const int ht_delete(struct hash_table* ht, const char* k);


#endif