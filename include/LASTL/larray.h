#pragma once

#include <cstdio>

namespace lastl
{

template <typename T, size_t N>
class larray final
{
public:
    typedef     larray<T, N>        this_type;
    typedef     T*                  iterator;
    typedef     const T*            const_iterator;

    larray() = default;
    larray(const this_type& copy) = delete;

~larray() = default;

    T& operator [](const size_t index);

    size_t          size() const;

    iterator        begin();
    const_iterator  begin() const;
    iterator        end();
    const_iterator  end() const;

private:
    T mArray[N];
};

template <typename T, size_t N>
size_t larray<T, N>::size() const
{
    return N;
}

template <typename T, size_t N>
T& larray<T, N>::operator [](const size_t index)
{
    assert(index < N);

    return mArray[index];
}

template <typename T, size_t N>
typename larray<T, N>::iterator
larray<T, N>::begin()
{
    return &mArray[0];
}

template <typename T, size_t N>
typename larray<T, N>::const_iterator
larray<T, N>::begin() const
{
    return &mArray[0];
}

template <typename T, size_t N>
typename larray<T, N>::iterator
larray<T, N>::end()
{
    return &mArray[N];
}

template <typename T, size_t N>
typename larray<T, N>::const_iterator
larray<T, N>::end() const
{
    return &mArray[N];
}

} // namespace lastl