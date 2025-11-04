# Multithreading

Concurrency, threading, and synchronization problems.

## Key Concepts Covered
- Thread creation and management
- Mutex and locks
- Condition variables
- Race conditions
- Deadlock prevention
- Thread synchronization
- Producer-consumer problem
- Read-write locks

## Tips
- Always protect shared data with mutexes
- Use RAII (lock_guard, unique_lock) for exception safety
- Understand the difference between mutex, semaphore, and condition variable
- Watch out for deadlocks—acquire locks in consistent order
- atomic<T> for simple lock-free operations
