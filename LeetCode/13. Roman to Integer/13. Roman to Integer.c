#include "13. Roman to Integer.h"
#include "hash_table.h"
#include<stdio.h>
#include<string.h>
int romanToInt(char* s)
{
	struct hash_table* ht = ht_create();
	ht_insert(ht, "I",    "1");
	ht_insert(ht, "V",    "5");
	ht_insert(ht, "X",   "10");
	ht_insert(ht, "L",   "50");
	ht_insert(ht, "C",  "100");
	ht_insert(ht, "D",  "500"); //MCMXCIV
	ht_insert(ht, "M", "1000");
	int i;
	int res;
	for (i = 0; s[i] != NULL; ++i) {
		if (ht_serach(ht, s[i]) - "0" >= ht_serach(ht, s[i + 1]) - "0") {
			res += (int)ht_serach(ht, s[i]);
		}
		else if(ht_serach(ht, s[i]) - "0" < ht_serach(ht, s[i + 1]) - "0"){
			res += (int)(ht_serach(ht, s[i + 1])) - (int)(ht_serach(ht, s[i]));
		}
	}
	return res;
}
