
#include<stdio.h>

typedef struct State State;
struct State {
	int ch;
	State* out1;
	State* out2;
};
typedef union PtrList PtrList;
union PtrList {
	PtrList* next;
	State* s;
};
typedef struct Fragment Fragment;
struct Fragment {
	State* start;
	Fragment* out;
};
State* state(int ch, State* out1, State* out2) {
	State* ret;
	ret->out1 = out1;
	ret->out2 = out2;
	ret->ch = ch;
	return ret;
}
Fragment frag(State* state, PtrList* ptr) {
	Fragment frag = { state,ptr };
	return frag;
}

PtrList* append(PtrList* l1, PtrList* l2) {
	PtrList* ret = l1;
	while (l1 != NULL) {
		l1 = l1->next;
	}
	l1->next = l2;
	return ret;
}
PtrList* list(State** out) {
	PtrList* ret;
	ret = (PtrList*)out;
	ret->next = NULL;
	return ret;

}
void patch(State* st, PtrList* lt) {
	PtrList* nl = lt;
	while (lt != NULL)
		nl = nl->next;
	nl->s = st;

}
State* post2nfa(char* prfx) {
	Fragment stack[1000];
	Fragment* stackpointer = stack;
	Fragment e1, e2, e;
	State* st;
	if (prfx == NULL) {
		return NULL;
	}
	char* i;
	for (i = prfx; *prfx; i++) {
		switch (*i)
		{
		default:
			st = state(i, NULL, NULL);
			*stackpointer++ = frag(st, list(st->out1));
			break;
		case '*':
			e = *--(stackpointer);
			st = state(256, e1.start, NULL);
			*stackpointer++ = frag(st, list(st->out1));
			break;
		case '.':
			e2 = *--(stackpointer);
			e1 = *--(stackpointer);
			patch(e1.start, e2.out);
			*stackpointer++ = frag(e1.start, e2.out);
			break;
		}

	}
	e = *--(stackpointer);
	return e.start;
}


int isMatch(char* s, char* p) {

}