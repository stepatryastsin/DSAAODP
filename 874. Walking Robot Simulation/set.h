#ifndef SET_H
#define SET_H

#define STRUE   1
#define SFALSE  0

#define MAXSETSIZE 10

#define ERROR_ALLOW    -1
#define ERROR_CIRCULAR -3
#define ERROR_OCCUPIED -4
#define ALREADY_EXIST  -5

#define _PRIVATE static
#define _INLINE  inline


#include<inttypes.h>

typedef uint64_t (*hashfunction)(const char* key);

typedef struct nodedef {
	uint64_t hash;
	char* key;
}nodedef;
typedef struct set {
	nodedef** node;
	uint32_t nnode;
	uint32_t unode;
	hashfunction hfuntion;
}set;


int32_t set_init(set* set, int64_t elem);
int32_t set_clear(set* set);
int32_t set_destroy(set* set);
int32_t set_add(set* set, const char* key);
int32_t set_contains(set* set, const char* key);

#endif 

