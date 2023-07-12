// Example.h
#ifndef EXAMPLE_H
#define EXAMPLE_H

template<typename T>
struct Pair {
    T first;
    T second;
};

template<typename T>
class Example {
public:
    void printPair(const Pair<T>& p);
};

// Explicit instantiation for the int specialization


#endif