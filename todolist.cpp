#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoItem {
public:
    TodoItem(const string& title) : title(title), status("Pending") {}

    void markCompleted() {
        status = "Completed";
    }

    bool isCompleted() const {
        return status == "Completed";
    }

    const string& getTitle() const {
        return title;
    }

    const string& getStatus() const {
        return status;
    }

private:
    string title;
    string status;
};

class TodoList {
public:
    void addItem(const string& title) {
        TodoItem item(title);
        items.push_back(item);
    }

    void displayList() const {
        if (items.empty()) {
            cout << "To-Do List is empty." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < items.size(); ++i) {
                const TodoItem& item = items[i];
                cout << "[" << (i + 1) << "] ";
                cout << (item.isCompleted() ? "[X] " : "[ ] ");
                cout << "Title: " << item.getTitle() << " (Status: " << item.getStatus() << ")" << endl;
            }
        }
    }

    void markCompleted(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].markCompleted();
        }
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

private:
    vector<TodoItem> items;
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "To-Do List Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Mark as Completed" << endl;
        cout << "4. Remove Item" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title;
                cout << "Enter task title: ";
                cin.ignore(); 
                getline(cin, title);
                todoList.addItem(title);
                cout << "Task added successfully." << endl;
                break;
            }
            case 2:
                todoList.displayList();
                break;
            case 3: {
                int index;
                cout << "Enter the task number to mark as completed: ";
                cin >> index;
                todoList.markCompleted(index - 1); 
                break;
            }
            case 4: {
                int index;
                cout << "Enter the task number to remove: ";
                cin >> index;
                todoList.removeItem(index - 1); 
                cout << "Task removed successfully." << endl;
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
