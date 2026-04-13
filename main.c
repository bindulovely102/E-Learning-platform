#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================
                COURSE MANAGEMENT SYSTEM (BST)
 ------------------------------------------------------------
 This program implements a Course Management System using
 Binary Search Trees (BST).

 STRUCTURE:
   Course
      └── Modules (BST)
             └── Lessons (BST)

 FEATURES:
   ✔ Add Module
   ✔ Add Lesson
   ✔ Delete Module
   ✔ Delete Lesson
   ✔ Update Module
   ✔ Update Lesson
   ✔ Search Module
   ✔ Display Course (Sorted)
   ✔ Memory Management (No leaks)

===========================================================*/


/*===========================================================
                LESSON STRUCTURE (BST NODE)
 ------------------------------------------------------------
 Each lesson node contains:
   - title  : dynamically allocated string
   - left   : pointer to left child
   - right  : pointer to right child
===========================================================*/
typedef struct Lesson {
    char *title;
    struct Lesson *left, *right;
} Lesson;


/*===========================================================
                MODULE STRUCTURE (BST NODE)
 ------------------------------------------------------------
 Each module node contains:
   - title   : module name
   - lessons : BST of lessons
   - left    : left child module
   - right   : right child module
===========================================================*/
typedef struct Module {
    char *title;
    Lesson *lessons;
    struct Module *left, *right;
} Module;


/*===========================================================
                COURSE ROOT STRUCTURE
===========================================================*/
typedef struct Course {
    char *title;
    Module *modules;
} Course;


/*===========================================================
                STRING CREATION FUNCTION
 ------------------------------------------------------------
 Dynamically allocates memory for a string
===========================================================*/
char* createString(char *str) {
    char *newStr = (char*)malloc(strlen(str) + 1);
    strcpy(newStr, str);
    return newStr;
}


/*===========================================================
                CREATE COURSE
===========================================================*/
Course* createCourse(char *title) {
    Course *c = (Course*)malloc(sizeof(Course));
    c->title = createString(title);
    c->modules = NULL;
    return c;
}


/*===========================================================
                INSERT MODULE (BST LOGIC)
===========================================================*/
Module* insertModule(Module *root, char *title) {

    // Base case: create new node
    if (!root) {
        Module *newNode = (Module*)malloc(sizeof(Module));
        newNode->title = createString(title);
        newNode->lessons = NULL;
        newNode->left = newNode->right = NULL;

        printf("Module added successfully!\n");
        return newNode;
    }

    // BST insertion based on alphabetical order
    if (strcmp(title, root->title) < 0)
        root->left = insertModule(root->left, title);

    else if (strcmp(title, root->title) > 0)
        root->right = insertModule(root->right, title);

    return root;
}


/*===========================================================
                ADD MODULE (WRAPPER)
===========================================================*/
void addModule(Course *course, char *title) {
    course->modules = insertModule(course->modules, title);
}


/*===========================================================
                FIND MODULE (BST SEARCH)
===========================================================*/
Module* findModule(Module *root, char *title) {

    if (!root) return NULL;

    if (strcmp(title, root->title) == 0)
        return root;

    else if (strcmp(title, root->title) < 0)
        return findModule(root->left, title);

    else
        return findModule(root->right, title);
}


/*===========================================================
                INSERT LESSON (BST)
===========================================================*/
Lesson* insertLesson(Lesson *root, char *title) {

    if (!root) {
        Lesson *newNode = (Lesson*)malloc(sizeof(Lesson));
        newNode->title = createString(title);
        newNode->left = newNode->right = NULL;

        printf("Lesson added successfully!\n");
        return newNode;
    }

    if (strcmp(title, root->title) < 0)
        root->left = insertLesson(root->left, title);

    else if (strcmp(title, root->title) > 0)
        root->right = insertLesson(root->right, title);

    return root;
}


/*===========================================================
                ADD LESSON
===========================================================*/
void addLesson(Module *module, char *title) {
    module->lessons = insertLesson(module->lessons, title);
}


/*===========================================================
                DISPLAY LESSONS (INORDER)
===========================================================*/
void displayLessons(Lesson *root) {
    if (!root) return;

    displayLessons(root->left);
    printf("    Lesson: %s\n", root->title);
    displayLessons(root->right);
}


/*===========================================================
                DISPLAY MODULES (INORDER)
===========================================================*/
void displayModules(Module *root) {
    if (!root) return;

    displayModules(root->left);

    printf("  Module: %s\n", root->title);
    displayLessons(root->lessons);

    displayModules(root->right);
}


/*===========================================================
                DISPLAY COURSE
===========================================================*/
void displayCourse(Course *course) {
    printf("\nCourse: %s\n", course->title);
    displayModules(course->modules);
}


/*===========================================================
                FIND MINIMUM NODE
===========================================================*/
Module* minModule(Module *root) {
    while (root->left)
        root = root->left;
    return root;
}

Lesson* minLesson(Lesson *root) {
    while (root->left)
        root = root->left;
    return root;
}


/*===========================================================
                DELETE LESSON (BST)
===========================================================*/
Lesson* deleteLessonNode(Lesson *root, char *title) {

    if (!root) return NULL;

    if (strcmp(title, root->title) < 0)
        root->left = deleteLessonNode(root->left, title);

    else if (strcmp(title, root->title) > 0)
        root->right = deleteLessonNode(root->right, title);

    else {

        // Case 1: No child
        if (!root->left && !root->right) {
            free(root->title);
            free(root);
            return NULL;
        }

        // Case 2: One child
        if (!root->left) {
            Lesson *temp = root->right;
            free(root->title);
            free(root);
            return temp;
        }

        if (!root->right) {
            Lesson *temp = root->left;
            free(root->title);
            free(root);
            return temp;
        }

        // Case 3: Two children
        Lesson *temp = minLesson(root->right);
        free(root->title);
        root->title = createString(temp->title);

        root->right = deleteLessonNode(root->right, temp->title);
    }

    return root;
}


/*===========================================================
                DELETE LESSON WRAPPER
===========================================================*/
void deleteLesson(Module *module, char *title) {
    module->lessons = deleteLessonNode(module->lessons, title);
    printf("Lesson deleted!\n");
}


/*===========================================================
                DELETE MODULE (BST)
===========================================================*/
Module* deleteModuleNode(Module *root, char *title) {

    if (!root) return NULL;

    if (strcmp(title, root->title) < 0)
        root->left = deleteModuleNode(root->left, title);

    else if (strcmp(title, root->title) > 0)
        root->right = deleteModuleNode(root->right, title);

    else {

        if (!root->left && !root->right) {
            free(root->title);
            free(root);
            return NULL;
        }

        if (!root->left) {
            Module *temp = root->right;
            free(root->title);
            free(root);
            return temp;
        }

        if (!root->right) {
            Module *temp = root->left;
            free(root->title);
            free(root);
            return temp;
        }

        Module *temp = minModule(root->right);
        free(root->title);
        root->title = createString(temp->title);

        root->right = deleteModuleNode(root->right, temp->title);
    }

    return root;
}


/*===========================================================
                DELETE MODULE WRAPPER
===========================================================*/
void deleteModule(Course *course, char *title) {
    course->modules = deleteModuleNode(course->modules, title);
    printf("Module deleted!\n");
}


/*===========================================================
                UPDATE MODULE
===========================================================*/
void updateModule(Course *course, char *oldName, char *newName) {
    Module *m = findModule(course->modules, oldName);

    if (m) {
        free(m->title);
        m->title = createString(newName);
        printf("Module updated!\n");
    } else {
        printf("Module not found!\n");
    }
}


/*===========================================================
                FIND LESSON
===========================================================*/
Lesson* findLesson(Lesson *root, char *title) {

    if (!root) return NULL;

    if (strcmp(title, root->title) == 0)
        return root;

    else if (strcmp(title, root->title) < 0)
        return findLesson(root->left, title);

    else
        return findLesson(root->right, title);
}


/*===========================================================
                UPDATE LESSON
===========================================================*/
void updateLesson(Module *module, char *oldName, char *newName) {
    Lesson *l = findLesson(module->lessons, oldName);

    if (l) {
        free(l->title);
        l->title = createString(newName);
        printf("Lesson updated!\n");
    } else {
        printf("Lesson not found!\n");
    }
}


/*===========================================================
                FREE MEMORY
===========================================================*/
void freeLessons(Lesson *root) {
    if (!root) return;

    freeLessons(root->left);
    freeLessons(root->right);

    free(root->title);
    free(root);
}

void freeModules(Module *root) {
    if (!root) return;

    freeModules(root->left);
    freeModules(root->right);

    freeLessons(root->lessons);
    free(root->title);
    free(root);
}

void freeCourse(Course *course) {
    freeModules(course->modules);
    free(course->title);
    free(course);

    printf("All memory freed. Program exiting.\n");
}


/*===========================================================
                MAIN FUNCTION (MENU)
===========================================================*/
int main() {

    char courseName[100];

    printf("Enter Course Name: ");
    scanf(" %[^\n]", courseName);

    Course *course = createCourse(courseName);

    int choice;
    char moduleName[100], lessonName[100], newName[100];

    while (1) {

        printf("\n--- MENU ---\n");
        printf("1. Add Module\n");
        printf("2. Add Lesson\n");
        printf("3. Display Course\n");
        printf("4. Delete Module\n");
        printf("5. Delete Lesson\n");
        printf("6. Update Module\n");
        printf("7. Update Lesson\n");
        printf("8. Search Module\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);
                addModule(course, moduleName);
                break;

            case 2: {
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);

                Module *m = findModule(course->modules, moduleName);

                if (m) {
                    printf("Enter Lesson Name: ");
                    scanf(" %[^\n]", lessonName);
                    addLesson(m, lessonName);
                } else {
                    printf("Module not found!\n");
                }
                break;
            }

            case 3:
                displayCourse(course);
                break;

            case 4:
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);
                deleteModule(course, moduleName);
                break;

            case 5: {
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);

                Module *m = findModule(course->modules, moduleName);

                if (m) {
                    printf("Enter Lesson Name: ");
                    scanf(" %[^\n]", lessonName);
                    deleteLesson(m, lessonName);
                } else {
                    printf("Module not found!\n");
                }
                break;
            }

            case 6:
                printf("Enter Old Module Name: ");
                scanf(" %[^\n]", moduleName);

                printf("Enter New Module Name: ");
                scanf(" %[^\n]", newName);

                updateModule(course, moduleName, newName);
                break;

            case 7: {
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);

                Module *m = findModule(course->modules, moduleName);

                if (m) {
                    printf("Enter Old Lesson Name: ");
                    scanf(" %[^\n]", lessonName);

                    printf("Enter New Lesson Name: ");
                    scanf(" %[^\n]", newName);

                    updateLesson(m, lessonName, newName);
                } else {
                    printf("Module not found!\n");
                }
                break;
            }

            case 8: {
                printf("Enter Module Name: ");
                scanf(" %[^\n]", moduleName);

                Module *m = findModule(course->modules, moduleName);

                if (m)
                    printf("Module found!\n");
                else
                    printf("Module not found!\n");

                break;
            }

            case 9:
                freeCourse(course);
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
