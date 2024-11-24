#include <iostream>
using namespace std;

int count = 0;
string tasks[10] = {""}; // Array to store tasks

void AddTask(string task) {
    if (count >= 10) {
        cout << "\n\nTask list is full! Cannot add more tasks." << endl;
        return;
    }
    tasks[count] = task;
    count++;
    cout << "\nTask added successfully!\n" << endl;
}

void DeleteTask(int position) {
    if (position < 1 || position > count) {
        cout << "Invalid task number! Please try again." << endl;
        return;
    }
    for (int i = position - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1]; // Shift tasks left
    }
    tasks[count - 1] = ""; // Clear the last task
    count--;
    cout << "\nTask deleted successfully!\n" << endl;
}

void ViewTask() {
    if (count == 0) {
        cout << "\nNo tasks available!\n" << endl;
        return;
    }
    cout << "\nTask List:\n" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

int main() {
    int choice, position;
    string task;

    do {
        cout << "\n\n----TO DO LIST-------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter task name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, task);
                AddTask(task);
                break;

            case 2:
                cout << "\nEnter task number to delete: ";
                cin >> position;
                DeleteTask(position);
                break;

            case 3:
                ViewTask();
                break;

            case 4:
                cout << "\n\nExiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n" << endl;
                break;
        }
    } while (true);

    return 0;
}
