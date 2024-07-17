#include <CircularBuffer.h>
#include <stdio.h>

#include <algorithm>
#include <cassert>

int main() {
    const int capacity = 10;
    CircularBuffer<int, capacity> cb;
    assert(cb.capacity() == capacity);
    for (int i = 0; i < 50; ++i) {
        cb.push(i);
        assert(cb.size() == std::min(capacity, (i + 1)));
        assert(cb[0] == std::max(0, i - capacity + 1));
        assert(cb[-1] == i);
    }
    return 0;
}
