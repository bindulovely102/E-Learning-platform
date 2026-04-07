#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------
   LESSON STRUCTURE
   Each lesson has:
   - title (dynamic string)
   - pointer to next lesson (linked list)
---------------------------------------------------------*/
typedef struct Lesson {
    char *title;
    struct Lesson *next;
} Lesson;

/*---------------------------------------------------------
   MODULE STRUCTURE
   Each module has:
   - title
   - list of lessons
   - pointer to next module
---------------------------------------------------------*/
typedef struct Module {
    char *title;
    Lesson *lessons;
    struct Module *next;
} Module;

/*---------------------------------------------------------
   COURSE STRUCTURE (ROOT NODE)
   - title
   - list of modules
---------------------------------------------------------*/
typedef struct Course {
    char *title;
    Module *modules;
} Course;

/*---------------------------------------------------------
   FUNCTION: createString
   PURPOSE: Allocate memory and copy string dynamically
---------------------------------------------------------*/
char* createString(char *str) {
    char *newStr = (char*)malloc(strlen(str) + 1);
    strcpy(newStr, str);
    return newStr;
}

/*---------------------------------------------------------
   FUNCTION: createCourse
   PURPOSE: Create root node (course)
---------------------------------------------------------*/
Course* createCourse(char *title) {
    Course *c = (Course*)malloc(sizeof(Course));
    c->title = createString(title);
    c->modules = NULL;   // initially no modules
    return c;
}

/*---------------------------------------------------------
   FUNCTION: addModule
   PURPOSE: Add a module to the course
---------------------------------------------------------*/
void addModule(Course *course, char *title) {
    Module *newModule = (Module*)malloc(sizeof(Module));

    newModule->title = createString(title);
    newModule->lessons = NULL;

    // Insert at beginning of module list
    newModule->next = course->modules;
    course->modules = newModule;

    printf("Module added successfully!\n");
}

/*---------------------------------------------------------
   FUNCTION: addLesson
   PURPOSE: Add lesson inside a module
---------------------------------------------------------*/
void addLesson(Module *module, char *title) {
    Lesson *newLesson = (Lesson*)malloc(sizeof(Lesson));

    newLesson->title = createString(title);

    // Insert at beginning of lesson list
    newLesson->next = module->lessons;
    module->lessons = newLesson;

    printf("Lesson added successfully!\n");
}

/*---------------------------------------------------------
   FUNCTION: findModule
   PURPOSE: Search module by name
---------------------------------------------------------*/
Module* findModule(Course *course, char *title) {
    Module *temp = course->modules;

    while (temp) {
        if (strcmp(temp->title, title) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;   // not found
}

/*---------------------------------------------------------
   FUNCTION: displayCourse
   PURPOSE: Display full course structure
---------------------------------------------------------*/
void displayCourse(Course *course) {
    printf("\nCourse: %s\n", course->title);

    Module *m = course->modules;

    while (m) {
        printf("  Module: %s\n", m->title);

        Lesson *l = m->lessons;

        while (l) {
            printf("    Lesson: %s\n", l->title);
            l = l->next;
        }
        m = m->next;
    }
}

/*---------------------------------------------------------
   FUNCTION: deleteLesson
   PURPOSE: Delete a lesson from a module
---------------------------------------------------------*/
void deleteLesson(Module *module, char *title) {
    Lesson *temp = module->lessons, *prev = NULL;

    while (temp) {
        if (strcmp(temp->title, title) == 0) {

            // Adjust links
            if (prev)
                prev->next = temp->next;
            else
                module->lessons = temp->next;

            // Free memory
            free(temp->title);
            free(temp);

            printf("Lesson deleted!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Lesson not found!\n");
}

/*---------------------------------------------------------
   FUNCTION: deleteModule
   PURPOSE: Delete a module and all its lessons
---------------------------------------------------------*/
void deleteModule(Course *course, char *title) {
    Module *temp = course->modules, *prev = NULL;

    while (temp) {
        if (strcmp(temp->title, title) == 0) {

            // Adjust links
            if (prev)
                prev->next = temp->next;
            else
                course->modules = temp->next;

            // Free all lessons inside module
            Lesson *l = temp->lessons;
            while (l) {
                Lesson *t = l;
                l = l->next;
                free(t->title);
                free(t);
            }

            // Free module
            free(temp->title);
            free(temp);

            printf("Module deleted!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Module not found!\n");
}

/*---------------------------------------------------------
   FUNCTION: updateModule
   PURPOSE: Rename a module
---------------------------------------------------------*/
void updateModule(Course *course, char *oldName, char *newName) {
    Module *m = findModule(course, oldName);

    if (m) {
        free(m->title);
        m->title = createString(newName);
        printf("Module updated!\n");
    } else {
        printf("Module not found!\n");
    }
}

/*---------------------------------------------------------
   FUNCTION: updateLesson
   PURPOSE: Rename a lesson
---------------------------------------------------------*/
void updateLesson(Module *module, char *oldName, char *newName) {
    Lesson *l = module->lessons;

    while (l) {
        if (strcmp(l->title, oldName) == 0) {
            free(l->title);
            l->title = createString(newName);
            printf("Lesson updated!\n");
            return;
        }
        l = l->next;
    }
    printf("Lesson not found!\n");
}

/*---------------------------------------------------------
   FUNCTION: freeCourse
   PURPOSE: Free entire tree (avoid memory leaks)
---------------------------------------------------------*/
void freeCourse(Course *course) {
    Module *m = course->modules;

    while (m) {
        Lesson *l = m->lessons;

        // Free all lessons
        while (l) {
            Lesson *lt = l;
            l = l->next;
            free(lt->title);
            free(lt);
        }

        // Free module
        Module *mt = m;
        m = m->next;
        free(mt->title);
        free(mt);
    }

    // Free course
    free(course->title);
    free(course);

    printf("All memory freed. Program exiting.\n");
}

/*---------------------------------------------------------
   MAIN FUNCTION (MENU DRIVEN)
---------------------------------------------------------*/
int main() {
    char courseName[100];

    printf("Enter Course Name: ");
    scanf(" %[^\n]", courseName);

    // Create course
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

                Module *m = findModule(course, moduleName);

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

                Module *m = findModule(course, moduleName);

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

                Module *m = findModule(course, moduleName);

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

                Module *m = findModule(course, moduleName);

                if (m)
                    printf("Module found!\n");
                else
                    printf("Module not found!\n");

                break;
            }

            case 9:
                freeCourse(course);   // free entire tree
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}