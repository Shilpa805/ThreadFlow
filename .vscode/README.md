# ThreadFlow

ThreadFlow is a C++ console application that demonstrates a **Producer-Consumer problem** using multithreading.  
It allows multiple producers and consumers to work with a shared buffer in a **thread-safe** manner using mutexes and condition variables.

---

## Features

- Dynamic buffer size
- Multiple producers and consumers
- Thread-safe buffer using `std::mutex` and `std::condition_variable`
- Real-time logging of produced and consumed items
- Configurable number of items per producer

---

## How to Run

### 1. Compile the program

Open your terminal/PowerShell in the project folder and run:

```bash
g++ -std=c++17 main.cpp -o ThreadFlow.exe
```

### 2. Run the program

```bash
./ThreadFlow.exe
```

### 3. Input prompts

The program will ask for:

1. Buffer size – Maximum number of items the buffer can hold

2. Number of producers – How many producer threads you want

3. Number of consumers – How many consumer threads you want

4. Items per producer – How many items each producer should produce


### Example:

```yaml
Enter buffer size: 5
Enter number of producers: 2
Enter number of consumers: 2
Enter number of items per producer: 10
```


### Sample Output

```less
[Producer 1] produced item: 1
[Consumer 1] consumed item: 1
[Producer 2] produced item: 1
[Consumer 2] consumed item: 1
...
All tasks completed. Exiting program.
```


## Skills Demonstrated
- C++ programming (OOP, STL, templates)

- Multithreading with `std::thread`

- Synchronization using `std::mutex` and `std::condition_variable`

- Basic console I/O and dynamic program configuration


## AUTHOR
Shilpa Kumari
B.Tech CSE Student
