#ifndef __CHAPTER1_ITERABLE_H
#define __CHAPTER1_ITERABLE_H
template <class T>
class Iterable {
public:
    virtual bool hasNext() = 0;
    virtual T& next() = 0;
    virtual void remove() = 0;
};

#endif
