#ifndef SET_H
#define SET_H

#include<inttypes.h>
//// ERRRO
#define ERROR -1


#define MAXSETSIZE 10

#define TRUE   1
#define FALSE -1

#define __PRIVATE static
#define __INLINE  inline

typedef uint64_t (*set_hashfun)(const char *key);


typedef struct{
    char* key;
    uint64_t hash;
}simplenode;

typedef struct{
  simplenode** node;
  uint64_t nnodes; 
  uint64_t unode;
  set_hashfun hashfun;
}set;

int set_int(set* set,uint64_t num_els);
int set_clear(set* set);
void set_add(set*set,uint64_t elem);



#endif 