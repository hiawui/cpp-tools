#ifndef __HIAWUI_CIRCULAR_BUFFER_H__
#define __HIAWUI_CIRCULAR_BUFFER_H__

template <typename DataType, int Capacity>
class CircularBuffer {
   public:
    CircularBuffer() : internalCapacity(Capacity + 1), start(0), end(0) {}
    inline int capacity() { return Capacity; }
    inline int size() {
        return (end + internalCapacity - start) % internalCapacity;
    }
    inline bool isEmpty() { return start == end; }
    void push(DataType value) {
        if (size() >= Capacity) {
            start = (start + 1) % internalCapacity;
        }
        buffer[end] = value;
        end = (end + 1) % internalCapacity;
    }

    const DataType& operator[](int index) {
        if (isEmpty()) {
            throw "empty buffer";
        }
        int s = size();
        index = (index + s) % s;
        auto realIndex = (start + index) % internalCapacity;
        return buffer[realIndex];
    }

   private:
    DataType buffer[Capacity + 1];
    const int internalCapacity;
    int start;
    int end;
};

#endif