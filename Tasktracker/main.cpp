#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

struct Task{
    int id;
    string description;
    string status;
    string createdAt;
    string updatedAt;
};

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file("tasks.json");
    if (!file) return tasks;  // If file doesn’t exist, return empty list
    
    Task task;
    while (file >> task.id >> task.description >> task.status >> task.createdAt >> task.updatedAt) {
        tasks.push_back(task);
    }
    file.close();
    return tasks;
}

void saveTasks(vector<Task>& tasks) {
    ofstream file("tasks.json");
    for (Task t : tasks) {
        file << t.id << " " << t.description << " " << t.status << " " << t.createdAt << " " << t.updatedAt << endl;
    }
    file.close();
}

int generateID(vector<Task>& tasks) {
    int maxID = 0;
    for (Task t : tasks) maxID = max(maxID, t.id);
    return maxID + 1;
}

void addTask(string description) {
    vector<Task> tasks = loadTasks();
    Task newTask;
    newTask.id = generateID(tasks);
    newTask.description = description;
    newTask.status = "todo";

    time_t now = time(0);
    newTask.createdAt = ctime(&now);
    newTask.updatedAt = ctime(&now);

    tasks.push_back(newTask);
    saveTasks(tasks);

    cout << "Task added successfully (ID: " << newTask.id << ")\n";
}


void updateTask(int id, string newDescription) {
    vector<Task> tasks = loadTasks();
    for (Task &t : tasks) {
        if (t.id == id) {
            t.description = newDescription;
            
            time_t now = time(0);  // Get current time
            t.updatedAt = ctime(&now);  // Convert to string
            
            saveTasks(tasks);
            cout << "Task updated successfully.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask(int id) {
    vector<Task> tasks = loadTasks();
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [&](const Task &t) { return t.id == id; }), tasks.end());
    saveTasks(tasks);
    cout << "Task deleted successfully.\n";
}

void markTask(int id, string status) {
    vector<Task> tasks = loadTasks();
    for (Task &t : tasks) {
        if (t.id == id) {
            t.status = status;
            
            time_t now = time(0);
            t.updatedAt = ctime(&now);
            
            saveTasks(tasks);
            cout << "Task marked as " << status << ".\n";
            return;
        }
    }
    cout << "Task not found.\n";
}
void listTasks(string filter = "") {
    vector<Task> tasks = loadTasks();
    for (Task t : tasks) {
        if (filter.empty() || t.status == filter) {
            cout << "[" << t.id << "] " << t.description << " - " << t.status << " (Created: " << t.createdAt << ")\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: task-cli <command> [arguments]\n";
        return 1;
    }

    string command = argv[1];

    if (command == "add" && argc >= 3) {
        addTask(argv[2]);
    } else if (command == "update" && argc >= 4) {
        updateTask(stoi(argv[2]), argv[3]);
    } else if (command == "delete" && argc >= 3) {
        deleteTask(stoi(argv[2]));
    } else if (command == "mark-in-progress" && argc >= 3) {
        markTask(stoi(argv[2]), "in-progress");
    } else if (command == "mark-done" && argc >= 3) {
        markTask(stoi(argv[2]), "done");
    } else if (command == "list") {
        listTasks();
    } else if (command == "list" && argc >= 3) {
        listTasks(argv[2]);
    } else {
        cout << "Invalid command.\n";
    }

    return 0;
}

