// stack abstract class

template <typename E>
class Stack
{
public:
    Stack() {} // constructor
    virtual ~Stack() {} // destructor


    // reinitializes the stack
    virtual void clear() = 0;


    // push an element onto the top of the stack
    // @param item: element being pushed
    virtual void push(const E& item) = 0;

    // remove the element from the top of the stack
    // return: the element at the top
    virtual E pop() = 0;

    // return: the element at the top
    virtual E topValue() = 0;

    // return: the size of the stack
    virtual int length() = 0;


};