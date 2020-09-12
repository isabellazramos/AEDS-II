typedef int KeyType;
typedef struct RegType{
    KeyType Key;
}RegType;

typedef struct NodeType *PointerType;
typedef struct NodeType{
    RegType Reg;
    PointerType Left, Right;
}NodeType;
