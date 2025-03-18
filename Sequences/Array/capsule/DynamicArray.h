#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<class T>
class DynamicArray {
public:
    DynamicArray(DynamicArray &other);

    DynamicArray(const T *items, int count);

    explicit DynamicArray(int size);

    DynamicArray();

    ~DynamicArray();

    T &get(int index) const;

    T &operator[](int index) const;

    unsigned int getSize() const;

    void set(int index, T value);

    void resize(unsigned int newSize);

    void print();

private:
    T *items;
    unsigned int size{};
    unsigned int capacity{};

    void init(unsigned int size);

    void copy(const T *array, unsigned int count);

    bool check_index(int index) const;
};

#endif
