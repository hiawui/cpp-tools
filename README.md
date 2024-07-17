# cpp-tools

## CircularBuffer

### constructor

```cpp
// A circular buffer containing maximum 5 int values
CircularBuffer<int, 5> cb;
```

### capacity / size / isEmpty

```cpp
CircularBuffer<int, 5> cb;
// Return 5
cb.capacity();
// Return true if empty
cb.isEmpty();
// Return the count of elements
cb.size();
```

### push

```cpp
CircularBuffer<int, 5> cb;
// Push value to the tail. The head value will be discard if reaches the maximum size
cb.push(0); 
```

### operator[]

```cpp
CircularBuffer<int, 5> cb;
for (int i=0; i<5; ++i) {
	cb.push(i);
}
// Read the first element
cb[0];
// Read the last element
cb[-1] == cb[4];
// Error. Returned value is readonly
cb[2] = 22;
```
