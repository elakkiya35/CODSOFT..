#include <iostream>
using namespace std;
struct Task {
    char description[100];
    bool isCompleted;
};
void addTask(Task tasks[], int &taskCount) {
    if (taskCount < 10) {
        cout << "Enter task description: ";
        cin.ignore();  
        cin.getline(tasks[taskCount].description, 100); 
        tasks[taskCount].isCompleted = false;  // Initially, the task is not completed
        taskCount++;
        cout << "Task added successfully!" << endl;
    } else {
        cout << "Task list is full! Cannot add more tasks." << endl;
    }
}
void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available!" << endl;
    } else {
        cout << "\nTasks List:" << endl;
        for (int i = 0; i < taskCount; ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isCompleted) {
                cout << " (Completed)";
            } else {
                cout << " (Pending)";
            }
            cout << endl;
        }
    }
}
void markTaskAsCompleted(Task tasks[], int taskCount) {
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}
void removeTask(Task tasks[], int &taskCount) {
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;  // Decrease the task count
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}
int main() {
    Task tasks[10];  
    int taskCount = 0;  
    int choice;
    while (true) {
        // Display menu to the user
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskAsCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
