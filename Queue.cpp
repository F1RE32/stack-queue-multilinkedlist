#include <iostream>
#include <stdlib.h>
using namespace std;

struct studentRecord
{
    int rollnumber;
    float gpa;
    studentRecord* next;
};

void enqueue(studentRecord** front, studentRecord** rear)
{
    studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = *rear = ptr;
    }
    else
    {
        studentRecord* curr = *rear;
        *rear = ptr;
        curr->next = *rear;
    }
}

void dequeue(studentRecord** front, studentRecord** rear)
{
    studentRecord* curr = *front;
    if(curr != NULL)
    {
        *front = (*front)->next;
        free(curr);
        
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
}

void print(studentRecord** front, studentRecord** rear)
{
    studentRecord* curr = *front;
    while (curr != NULL)
    {
        cout << "Roll Number: " << curr->rollnumber << endl;
        cout << "GPA: " << curr->gpa << endl;
        cout << "" << endl;
        curr = curr->next;
    }
}

int main()
{
    studentRecord* front = NULL;
    studentRecord* rear = NULL;
    cout << "List is currently empty" << endl;
    enqueue(&front, &rear);
    cout << "Press 1 to push" << endl;
    cout << "Press 2 to pop" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    int select = 1;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            enqueue(&front, &rear);
        }
        if (select == 2)
        {
            dequeue(&front, &rear);
        }
        if (select == 3)
        {
            print(&front, &rear);
        }
        cout << "Enter your choice again: "<< "";
        cin >> select;
    }
}