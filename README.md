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

--- MENU ---
 <img width="303" height="227" alt="Screenshot 2026-04-07 120757" src="https://github.com/user-attachments/assets/98235428-75fc-4e0d-85a9-054d833b72aa" />

1. Add Module
<img width="273" height="328" alt="Screenshot 2026-04-07 120838" src="https://github.com/user-attachments/assets/96b38b9f-b8a4-4276-b02c-1a552f156343" />

2. Add Lesson
<img width="308" height="641" alt="Screenshot 2026-04-07 120911" src="https://github.com/user-attachments/assets/215d7327-9b10-4740-b848-de004cf151ed" />

3. Display Course
<img width="308" height="641" alt="Screenshot 2026-04-07 120911" src="https://github.com/user-attachments/assets/237cf742-70b2-462f-8f5c-89154c861948" />
 
4. Delete Module
 <img width="227" height="357" alt="Screenshot 2026-04-07 120924" src="https://github.com/user-attachments/assets/81a1d113-a1cc-4286-9b53-34bd7cadaa3b" />
 
5. Delete Lesson
<img width="272" height="284" alt="Screenshot 2026-04-07 120934" src="https://github.com/user-attachments/assets/2d2a01fa-0524-4449-9d1c-8440109a5e5f" />
 
6. Update Module
<img width="302" height="317" alt="Screenshot 2026-04-07 120955" src="https://github.com/user-attachments/assets/82baf1b4-0a76-48ae-8d23-26a019cf86fb" />
   
7. Update Lesson
 <img width="377" height="314" alt="Screenshot 2026-04-07 121005" src="https://github.com/user-attachments/assets/7eb17344-ef6f-4970-9fe6-ecd64ff92a0d" />
   
8.Search Module
<img width="331" height="331" alt="Screenshot 2026-04-07 121016" src="https://github.com/user-attachments/assets/b0a28314-e80c-4a4f-bc4d-946e9ee86791" />

9.Exit
<img width="384" height="260" alt="Screenshot 2026-04-07 121044" src="https://github.com/user-attachments/assets/c0c97d07-d74b-4787-9945-a3fcd3df61f2" />

 


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
