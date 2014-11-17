#include"hash.h"
#include<iostream>

struct ListNode
{
    ElementType Element;
    Position Next;
};

using namespace std;


int main()
{
    char *str = "0";
    HashTable myHash;
    myHash = InitializeTable(1007);

    while(cin>>str)
    {
        if(*str == '#')
            break;
        Insert(str,myHash);
    }
    cout<<"we are fingding now"<<endl;
    while(cin>>str)
    {
        if(*str == '#')
            break;
        Position p = Find(str,myHash);
        cout<<(p->Element)<<endl;
    }
    DestroyTable(myHash);
    return 0;
}
