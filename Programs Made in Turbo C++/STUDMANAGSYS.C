/*Student managment system using dynamic memmory allocation */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int id;
    int grades[3];  // Assume we have 3 subjects
} Student;

int count = 0, capacity = 1, i, j;

void resizeStudentsArray(Student **students) {
    capacity += 1;
    *students = (Student*)realloc(*students, capacity * sizeof(Student));

    if (*students == NULL) {
	printf("Memory reallocation failed.\n");
	exit(1);
    }
    printf("Student array resized to capacity %d.\n", capacity);
}

Student* searchByID(Student *students, int id) {
    for (i = 0; i < count; i++) {
	if (students[i].id == id) {
	    return &students[i];
	}
    }
    return NULL;
}

void addStudent(Student **students) {
    if (count >= capacity) {
	resizeStudentsArray(students);
    }

    printf("Enter student name (use '_' instead of spaces): ");
    scanf("%s", (*students)[count].name);

    do{
    printf("Enter student ID: ");
    scanf("%d", &(*students)[count].id);
    i=(*students)[count].id;
    if(searchByID(*students, i)!=NULL){
	printf("A student with this id alredy exist in data.\n");
    }else{
	break;
    }}while(1);

    printf("Enter 3 grades(1-10): ");
    for (i = 0; i < 3; i++) {
	scanf("%d", &(*students)[count].grades[i]);
    }

    count++;
    printf("Student added successfully!\n");
}

void deleteStudent(Student *students, int id) {
    for (i = 0; i < count; i++) {
	if (students[i].id == id) {
	    for (j = i; j < count - 1; j++) {
		students[j] = students[j + 1];  // Shift elements
	    }
	    count--;
	    printf("Student deleted successfully.\n");
	    return;
	}
    }
    printf("Student not found.\n");
}

float calculateAverage(Student *student) {
    float sum = 0;
    for (i = 0; i < 3; i++) {
	sum += student->grades[i];
    }
    return sum / 3;
}

void displayStudent(Student *student) {
    printf("Student Name: %s\n", student->name);
    printf("Student ID: %d\n", student->id);
    printf("Grades: ");
    for (i = 0; i < 3; i++) {
	printf("%d ", student->grades[i]);
    }
    printf("\n");
}

int main() {
    int choice, id;
    Student *foundStudent;
    // Dynamically allocate memory for students
    Student *students = (Student*)malloc(capacity * sizeof(Student));
    if (students == NULL) {
	printf("Memory allocation failed.\n");
	return 1;
    }

clrscr();

    do {
	printf("\n--- Student Management System ---\n");
	printf("1. Add Student\n");
	printf("2. Delete Student\n");
	printf("3. Calculate Average Grades\n");
	printf("4. Search by ID\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		addStudent(&students);
		break;
	    case 2:
		printf("Enter Student ID to delete: ");
		scanf("%d", &id);
		deleteStudent(students, id);
		break;
	    case 3:
		printf("Enter Student ID to calculate average: ");
		scanf("%d", &id);
		foundStudent = searchByID(students, id);
		if (foundStudent != NULL) {
		    printf("Average grade for %s (ID: %d) is %.2f\n",
			   foundStudent->name, foundStudent->id, calculateAverage(foundStudent));
		} else {
		    printf("Student not found.\n");
		}
		break;
	    case 4:
		printf("Enter Student ID to search: ");
		scanf("%d", &id);
		foundStudent = searchByID(students, id);
		if (foundStudent != NULL) {
		    displayStudent(foundStudent);
		} else {
		    printf("Student not found.\n");
		}
		break;
	    case 5:
		free(students);  // Free the allocated memory
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice. Try again.\n");
	}
    } while (choice != 5);

getch();
return 0;
}
