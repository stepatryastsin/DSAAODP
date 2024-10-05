#ifndef  HASH_TABLE_H
#define HASH_TABLE_H

#define HT_PRIME_1 151
#define HT_PRIME_2 163

#define PRIVATE static


struct ht_item {
	char* key;
	char* value;
};

//Table
struct hash_table {
	unsigned  int size;
	unsigned  int count;
	struct ht_item** items;
};

// Create new hash table
struct hash_table* ht_create();

// Delete all hash table
void ht_delete_table(struct hash_table* htable);

// Insert element in hash table
void ht_insert(struct hash_table* ht, const char* k, const char* v);

// Search element in hash table
const char* ht_serach(struct hash_table* ht, const char* k);

// Delete element in hash table
const int ht_delete(struct hash_table* ht, const char* k);


#endif