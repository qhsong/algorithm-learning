template <class T>
class Iterable {
public:
    virtual bool hasNext() = 0;
    virtual T& next() = 0;
    virtual void remove() = 0;
}
