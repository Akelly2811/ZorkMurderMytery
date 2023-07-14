#ifndef ARRAY_H
#define ARRAY_H

template <typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    T getSize() const {return N;}
};

#endif // ARRAY_H
