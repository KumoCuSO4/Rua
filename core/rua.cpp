// 类型枚举
enum ValueType {
    NIL,
    BOOL,
    INT,
    FLOAT,
    DOUBLE,
    STRING,
    TABLE,
    FUNCTION,
};

// 需要GC的数值类型  
union GCObject
{
    
};

// 所有数据类型的union
typedef union {
  GCObject *gc;
  void *pPointer;
  bool bBool;
  int nInt;
  double nDouble;
} Value;

class GCBase {
    GCObject *next; 
    ValueType tt;
    bool marked;
};

// 类型和数据
class RuaValue {
private:
    Value value;
    ValueType valueType;
public:
    RuaValue() {
    
    }
};

class RuaState {
private:
    int stackTop;
    int stackBase;
    int stackSize;
public:
    RuaState() {
        stackBase = 0;
        stackTop = 0;
        stackSize = 0;
    }

};