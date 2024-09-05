#include <stdlib.h>
#include <string.h>
#include "set.h"

#define DEFAULT_HASH_SEED 14695981039346656037ULL
#define FNV_PRIME 1099511628211ULL


_PRIVATE uint64_t _default_hash(const char* key);
_PRIVATE int32_t _free_elem(set* set, int32_t ind);
_PRIVATE int32_t _set_add(set* set, uint64_t hash, const char* key);
_PRIVATE int32_t _get_index(set* set, uint64_t hash, const char* key, int32_t* out);
_PRIVATE int32_t _set_contains(set* set, uint64_t hash, const char* key);
_PRIVATE int32_t _nominate_node(set* set, uint64_t hash, const char* key, int32_t index);


int32_t set_init(set* set, int64_t elem)
{
    if (elem <= 0) return ERROR_ALLOW; 

    set->node = (nodedef**)malloc(elem * sizeof(nodedef*));
    if (!set->node) {
        return ERROR_ALLOW;
    }

    set->nnode = elem;
    for (int32_t i = 0; i < set->nnode; ++i) {
        set->node[i] = NULL;
    }

    set->unode = 0;
    set->hfuntion =  &_default_hash;
    return STRUE;
}


int32_t set_clear(set* set)
{
    for (int32_t i = 0; i < set->nnode; i++) {
        if (set->node[i] != NULL) {
            _free_elem(set, i);
        }
    }
    set->unode = 0;
    return STRUE;
}


int32_t set_destroy(set* set)
{
    set_clear(set);
    free(set->node);
    set->node = NULL;
    set->nnode = 0;
    set->unode = 0;
    set->hfuntion = NULL;
    return STRUE;
}


int32_t set_add(set* set, const char* key)
{
    if (!key) return ERROR_ALLOW; 

    uint64_t hash = set->hfuntion(key);
    return _set_add(set, hash, key);
}


int32_t set_contains(set* set, const char* key)
{
    if (!key) return SFALSE; 

    uint64_t hash = set->hfuntion(key);
    return _set_contains(set, hash, key);
}


_PRIVATE uint64_t _default_hash(const char* key)
{
    uint64_t hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; 
    }

    return hash;
}

_PRIVATE int32_t _free_elem(set* set, int32_t ind)
{
    free(set->node[ind]->key);
    free(set->node[ind]);
    set->node[ind] = NULL;
    return STRUE;
}


_PRIVATE int32_t _set_add(set* set, uint64_t hash, const char* key)
{
    int32_t index;
    if (set->unode >= (set->nnode / MAXSETSIZE)) {
        uint64_t new_size = set->nnode * 2;
        nodedef** temp = (nodedef**)realloc(set->node, new_size * sizeof(nodedef*));
        if (!temp) {
            return ERROR_ALLOW;
        }

        set->node = temp;
        for (uint64_t i = set->nnode; i < new_size; i++) {
            set->node[i] = NULL;
        }
        set->nnode = new_size;
    }

    if (_get_index(set, hash, key, &index) == SFALSE) {
        _nominate_node(set, hash, key, index);
        ++set->unode;
    }
    return STRUE;
}

_PRIVATE int32_t _get_index(set* set, uint64_t hash, const char* key, int32_t* out)
{
    uint64_t i, idx;
    idx = hash % set->nnode;
    i = idx;
    size_t len = strlen(key);
    while (1) {
        if (set->node[i] == NULL) {
            *out = i;
            return SFALSE; 
        }
        else if (hash == set->node[i]->hash && len == strlen(set->node[i]->key) && strncmp(key, set->node[i]->key, len) == 0) {
            *out = i;
            return STRUE;
        }
        ++i;
        if (i == set->nnode)
            i = 0;
        if (i == idx) 
            return ERROR_CIRCULAR;
    }
}


_PRIVATE int32_t _set_contains(set* set, uint64_t hash, const char* key)
{
    int32_t index;
    return _get_index(set, hash, key, &index);
}


_PRIVATE int32_t _nominate_node(set* set, uint64_t hash, const char* key, int32_t index)
{
    int32_t sizekey = strlen(key);
    set->node[index] = (nodedef*)malloc(sizeof(nodedef));
    if (!set->node[index]) return ERROR_ALLOW;

    set->node[index]->key = (char*)calloc(sizekey + 1, sizeof(char));
    if (!set->node[index]->key) {
        free(set->node[index]);
        return ERROR_ALLOW;
    }

    memcpy(set->node[index]->key, key, sizekey);
    set->node[index]->hash = hash;
    return STRUE;
}
