

typedef char* ElementType;
typedef unsigned int Index;


#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

struct ListNode;
typedef ListNode* Position;
struct HashTbl;
typedef HashTbl* HashTable;


HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);


#endif // HASH_H_INCLUDED
