# Print all even positve integers

## Ergo code

```
even_numbers<void> () {
    with(i<int> = 0) loop update(i += 2) {
        print("$i\n");
    }
}
```

## C++ equivalent

```C++
void even_numbers() {
    for(int i = 0 ;; i += 2)
        cout << i << "\n";
}
```

# Fibonacci

## Ergo code

```
fib<int>(n<int>) {
    a,b<int> = 0,1;
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    with(i<int> = 2) loop until(i <= n) update(i++) {
        temp<int> = a+b;
        a = b;
        b = temp;
    }
    return b;
}
```


## C++ equivalent

```C++
int fib(int n) {
    int a = 0, b = 1;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    for(int i = 2; i <= n; ++i) {
        int temp = a+b;
        a = b;
        b = temp;
    }
    return b;
}
```

# Class Definition

## Ergo code

```
node<datatype>(newData<int>) {
    data<int> = newData;
    .next<node> = null;
}
```

## C++ equivalent

```C++
class node {
public:
    int data;
    node *next;
    node(int newData) : data(newData), next(NULL) {}  
};
```
