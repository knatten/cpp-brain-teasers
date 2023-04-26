struct Value
{
    Value(int i_) : i(i_) {}
    Value(const Value &other) : i(other.i) {}
    int i;
};