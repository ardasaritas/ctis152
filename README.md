# CTIS152 - Introduction to Programming II

This repository contains coursework and lab exercises for CTIS152 (Introduction to Programming II), focusing on C programming fundamentals and data structures implementation.

## 📚 Course Overview

This course covers essential C programming concepts, data structures, and algorithms through hands-on laboratory exercises and assignments.

### Topics Covered
- **Fundamentals**: Arrays, strings, file I/O operations
- **Data Structures**: Stacks, queues, linked lists, hash tables
- **Advanced Concepts**: Binary search trees, recursion
- **File Processing**: Text and binary file handling
- **Memory Management**: Dynamic memory allocation

## 📁 Repository Structure

### Laboratory Exercises (LG01-LG21)
Each lab directory contains:
- **Q1, Q2, Q3, Q4**: Practice questions with source code
- **AQ1, AQ2**: Assignment questions 
- **Data files**: Input files for testing (`.txt`, `.bin`)
- **Header files**: Custom libraries for data structures

### Special Directories
- **`FLab/`**: Final lab practice with Binary Search Tree implementation
- **`LGEQ/`**: Lab exam questions (EQ1-EQ7)
- **`RG01-RG03/`**: Review and group exercises

### Key Learning Progression
1. **LG01-LG10**: Basic programming concepts, arrays, file I/O
2. **LG11-LG14**: Advanced file operations, binary files, custom data types
3. **LG15-LG17**: Stack and queue implementations
4. **LG18-LG21**: Linked lists, hash tables, and advanced operations

## 🛠️ Data Structures Implemented

### Core Data Structures
- **Arrays**: Multi-dimensional arrays, matrix operations
- **Stacks**: LIFO operations, expression evaluation
- **Queues**: FIFO operations, simulation problems
- **Linked Lists**: Single linked lists with various operations
- **Hash Tables**: Collision resolution using chaining
- **Binary Search Trees**: Insertion, deletion, traversal

### Custom Libraries
- `stack_int.h`, `stack_string.h`, `stack_struct.h`
- `queue_int.h`, `queue_string.h`, `queue_struct.h`
- `linkedList_int.h`, `linkedList_str.h`, `linkedList_struct.h`
- `bstlib_int.h`

## 🔍 Notable Implementations

### Advanced Algorithms
- **Recursive List Reversal** (LG21/AQ1.cpp)
- **Merge Sorted Lists** (LG21/AQ2.cpp)
- **Car Wash Simulation** using stacks and queues (LG21/Q1.cpp)
- **Hash Table** with collision resolution (LG21/Q2.cpp)

### Real-World Applications
- Library monitoring system
- Car wash queue management
- Supply inventory with hash tables
- Student record management

## 💻 Compilation and Execution

Most programs can be compiled using:
```bash
gcc filename.cpp -o output
./output
```

Some programs require input files that are provided in their respective directories.

## 📋 File Naming Convention

- **Source Files**: `.cpp` extensions
- **Executables**: No extension (compiled binaries)
- **Input Data**: `.txt` for text files, `.bin` for binary files
- **Headers**: `.h` for custom library implementations

## 🎯 Learning Outcomes

By completing these exercises, students gain proficiency in:
- C programming language fundamentals
- Data structure design and implementation
- Algorithm analysis and optimization
- File handling and data persistence
- Memory management and pointer operations
- Problem-solving through programming

## 📖 Usage

Each lab directory is self-contained with its own source files and data. Navigate to the specific lab directory and refer to the source code comments for detailed functionality descriptions.

---

*This repository represents academic coursework for CTIS152 at [University Name]. All implementations follow course guidelines and demonstrate progressive learning in C programming and data structures.*