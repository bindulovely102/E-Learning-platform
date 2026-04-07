# 📚 E-Learning Platform using Tree (C Language)

---

## 👩‍💻 Team Members

* **P. Bindu Lovely**
* **J. Muni Bhargav Reddy**

---

## 📌 Project Title

**E-Learning Platform with Course Content Tree (Modules & Lessons) using C**

---

## ❓ Problem Statement

To design and implement an **E-Learning Platform** in C that organizes course content in a **tree-like structure**.
The system should support **CRUD operations** (Create, Read, Update, Delete) for:

* Modules
* Lessons

It should also efficiently manage memory using **dynamic allocation**.

---

## 🌳 Data Structure Used

We used a **Tree Structure (Hierarchical Linked List)**:

* 📘 **Course (Root Node)**

 * 📂 **Modules (Linked List)**

 * 📄 **Lessons (Linked List)**

### Structure Design:

* `Course → Module → Lesson`
* Each module contains multiple lessons
* Implemented using `typedef struct`

---

## ⚙️ Algorithm Explanation

### 🟢 1. Create Course

* Allocate memory for course
* Initialize module list as NULL

### 🟢 2. Add Module

* Create new module node
* Insert at beginning of module list

### 🟢 3. Add Lesson

* Find module
* Insert lesson at beginning of lesson list

### 🟢 4. Display Course

* Traverse modules
* For each module, traverse lessons

### 🟢 5. Delete Module

* Find module
* Delete all its lessons
* Remove module node

### 🟢 6. Delete Lesson

* Find lesson inside module
* Remove and free memory

### 🟢 7. Update Module/Lesson

* Search by name
* Replace with new name

### 🟢 8. Search Module

* Traverse module list
* Compare using `strcmp()`

### 🟢 9. Free Memory

* Free all lessons
* Free all modules
* Free course node

---

## 🛠️ Compilation Instructions

### ▶️ Compile

```
gcc main.c
```

### ▶️ Run

```
./a.exe
```

---

## 🧪 Sample Output




---

## ✨ Features

✔ Tree-based structure
✔ Dynamic memory allocation (`malloc`, `free`)
✔ CRUD operations
✔ Menu-driven program
✔ Memory leak prevention
✔ Easy to understand design

---

## 📌 Conclusion

This project successfully demonstrates how an **E-Learning system** can be implemented using a **tree structure in C**.
It efficiently manages course content using **modules and lessons**, while supporting full **CRUD operations**.

The use of **dynamic memory allocation** ensures flexibility, and proper memory deallocation avoids memory leaks.
Overall, this project provides a strong foundation for building real-world learning management systems.

⭐ *Through this project, we learned how to implement tree data structures, manage dynamic memory, and build a complete CRUD-based application in C.*

---
