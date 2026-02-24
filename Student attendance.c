#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    int attendance;   // 1 = Present, 0 = Absent
};

int main() {
    struct Student s[MAX];
    int totalStudents;
    int presentCount = 0, absentCount = 0;

    printf("========================================\n");
    printf("        STUDENT ATTENDANCE SYSTEM       \n");
    printf("========================================\n");

    printf("\nEnter total number of students: ");
    scanf("%d", &totalStudents);

    // Input student details
    printf("\n------ Enter Student Details ------\n");

    for (int i = 0; i < totalStudents; i++) {

        printf("\nStudent %d Details\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        // Attendance input with validation
        while (1) {
            printf("Enter Attendance (1 = Present, 0 = Absent): ");
            scanf("%d", &s[i].attendance);

            if (s[i].attendance == 1 || s[i].attendance == 0) {
                break;
            } else {
                printf("Invalid input! Please enter 1 or 0.\n");
            }
        }

        // Counting logic
        if (s[i].attendance == 1)
            presentCount++;
        else
            absentCount++;
    }

    // Display individual attendance
    printf("\n\n========================================\n");
    printf("          DAILY ATTENDANCE REPORT       \n");
    printf("========================================\n");

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Status");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < totalStudents; i++) {
        if (s[i].attendance == 1)
            printf("%-10d %-20s %-10s\n", s[i].rollNo, s[i].name, "Present");
        else
            printf("%-10d %-20s %-10s\n", s[i].rollNo, s[i].name, "Absent");
    }

    // Summary section
    printf("\n-----------------------------------------------\n");
    printf("Total Students : %d\n", totalStudents);
    printf("Present        : %d\n", presentCount);
    printf("Absent         : %d\n", absentCount);

    // Percentage calculation
    float presentPercentage = ((float)presentCount / totalStudents) * 100;
    float absentPercentage = ((float)absentCount / totalStudents) * 100;

    printf("\nAttendance Statistics:\n");
    printf("Present Percentage : %.2f%%\n", presentPercentage);
    printf("Absent Percentage  : %.2f%%\n", absentPercentage);

    // Performance indicator
    printf("\nClass Attendance Performance: ");

    if (presentPercentage >= 75)
        printf("Good Attendance 👍\n");
    else if (presentPercentage >= 50)
        printf("Average Attendance ⚠️\n");
    else
        printf("Poor Attendance ❌\n");

    printf("\n========================================\n");
    printf("      Program Executed Successfully     \n");
    printf("========================================\n");

    return 0;
}