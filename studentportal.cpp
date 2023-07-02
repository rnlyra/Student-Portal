//Linked List
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int srCode;
    string name;
    string subjectCode;
    string instructorName;
    string scheduleTime;
};

struct Node {
    Student* data;
    Node* next;
};

class StudentList {
private:
    Node* head;

public:
    StudentList() : head(nullptr) {}

    void addStudent(Student* student) {
        Node* newNode = new Node();
        newNode->data = student;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayStudent(int studentId) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data->srCode == studentId) {
                cout << "Name: " << temp->data->name << endl;
                cout << "Subject Code: " << temp->data->subjectCode << endl;
                cout << "Instructor's Name: " << temp->data->instructorName << endl;
                cout << "Schedule Time: " << temp->data->scheduleTime << endl <<endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Student not found." << endl;
        }
    }

    void editStudent(int studentId) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data->srCode == studentId) {
                cout << "Enter new data for student with ID " << studentId << endl;
                cout << "Name: ";
                cin >> temp->data->name;
                cout << "Subject Code: ";
                cin >> temp->data->subjectCode;
                cout << "Instructor's Name: ";
                cin >> temp->data->instructorName;
                cout << "Schedule Time: ";
                cin >> temp->data->scheduleTime;
                cout << "Data updated successfully." << endl <<endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Student not found." << endl;
        }
    }

    void deleteStudent(int studentId) {
        if (head == nullptr) {
            cout << "Student list is empty." << endl;
            return;
        }

        if (head->data->srCode == studentId) {
            Node* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
            cout << "Student deleted successfully." << endl <<endl;
            return;
        }

        Node* curr = head->next;
        Node* prev = head;

        while (curr != nullptr) {
            if (curr->data->srCode == studentId) {
                prev->next = curr->next;
                delete curr->data;
                delete curr;
                cout << "Student deleted successfully." << endl <<endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Student not found." << endl;
    }

    void displayAllStudents() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Student list is empty." << endl;
        } else {
            cout << "-----All Students Data-----" << endl;
            while (temp != nullptr) {
                cout << "SR-CODE: " << temp->data->srCode << endl;
                cout << "Name: " << temp->data->name << endl;
                cout << "Subject Code: " << temp->data->subjectCode << endl;
                cout << "Instructor's Name: " << temp->data->instructorName << endl;
                cout << "Schedule Time: " << temp->data->scheduleTime << endl <<endl;
                temp = temp->next;
            }
        }
    }

    int countStudents() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp->data;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    ~StudentList() {
        deleteLinkedList();
    }
};

int main() {
    
    cout << "-----------STUDENT PORTAL-----------" <<endl <<endl;
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cout <<endl;

    StudentList studentList;

    for (int i = 0; i < numStudents; i++) {
        cout << "-----Enter the data for student no." << i + 1 << "-----" << endl;
        Student* student = new Student();
        cout << "SR-CODE: ";
        cin >> student->srCode;
        cin.ignore(); // Discard the newline character
        cout << "Name of student: ";
        getline(cin, student->name);
        cout << "Subject code: ";
        getline(cin, student->subjectCode);
        cout << "Instructor's name: ";
        getline(cin, student->instructorName);
        cout << "Schedule time: ";
        cin >> student->scheduleTime;
        cin.ignore(); // Discard the newline character
        cout << endl;

        studentList.addStudent(student);
    }

    char choice;
    do {
        cout << "-----------Menu-----------" << endl;
        cout << "1. Display Student's Data" << endl;
        cout << "2. Edit Student Data" << endl;
        cout << "3. Delete Student Data" << endl;
        cout << "4. Display All Students Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case '1': {
                int studentId;
                cout << "Enter the student SR-CODE to display the data: ";
                cin >> studentId;
                cout <<endl;
                studentList.displayStudent(studentId);
                break;
            }
            case '2': {
                int studentId;
                cout << "Enter the student SR-CODE to edit the data: ";
                cin >> studentId;
                cout <<endl;
                studentList.editStudent(studentId);
                break;
            }
            case '3': {
                int studentId;
                cout << "Enter the student SR-CODE to delete: ";
                cin >> studentId;
                cout <<endl;
                studentList.deleteStudent(studentId);
                break;
            }
            case '4':
                studentList.displayAllStudents();
                cout <<endl;
                break;
            
            case '5':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.";
                break;
        }

        cout << "--------------------------" << endl;
    } while (choice != '5');

    return 0;
}



