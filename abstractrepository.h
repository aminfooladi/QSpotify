#ifndef ABSTRACTREPOSITORY_H
#define ABSTRACTREPOSITORY_H

#include <optional>


template <typename T>
class AbstractRepository
{
public:
    AbstractRepository() {}

    virtual int save(const T& temp) = 0;
    virtual std::optional<T> search(int ID) = 0;
    virtual bool remove(int ID) = 0;

    virtual ~AbstractRepository() {}
};

#endif // ABSTRACTREPOSITORY_H