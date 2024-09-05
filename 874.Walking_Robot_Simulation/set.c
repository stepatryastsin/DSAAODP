#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"set.h"

int set_int(set* set,uint64_t num_els){
    set->node = (simplenode**) malloc(num_els*sizeof(simplenode*));
    if(set->node == NULL){
        return ERROR;
    }
    set->nnodes = num_els;
    uint64_t i;
    for(i = 0;i < set->nnodes;++i){
        set->node[i] = NULL;
    }
    set->unode = 0;
    return TRUE;
}
int set_clear(set* set){
    uint64_t i;
    for(i = 0; i < set->nnodes;++i){
        if(set->node[i] != NULL){
            __free_index(set, i);
        }
    }
    set->unode = 0;
    return TRUE;
}
void set_add(set* set, const char *key){
    uint64_t hash = set->hashfun(key);
    set->node[hash] = key;
}
__PRIVATE void __free_index(set* set, uint64_t ind){
    free(set->node[ind]->key);
    free(set->node[ind]);
    set->node[ind] = NULL;
}
__PRIVATE uint64_t __defhash(const char *key){
   uint64_t i,len = strlen(key);
   uint64_t offset = 14621867960236790921ULL;
   for(i = 0; i < len;++i){
    offset = offset ^ (unsigned char) key[i];
    offset = offset * 82058928190ULL; 
   }
   return offset;
}
__PRIVATE int __set_add(set* set, const char *key,uint64_t hash){
   if(set->nnodes / set->unode >= MAXSETSIZE){
    uint64_t set_elems = set->nnodes * 2;
    simplenode** temp = (simplenode**)realloc(set->node,set_elems * sizeof(simplenode*));
    if(temp == NULL){
        return ERROR;
    }
    set->node = temp;
    uint64_t i,previus_elem = set->nnodes;
    for ( i = previus_elem ; i < set_elems; i++)
    {
        set->node[i] = NULL;
    }
    set->nnodes = set_elems;
    
   }
}