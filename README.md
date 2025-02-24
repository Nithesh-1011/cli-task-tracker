# Task Tracker CLI

A simple command-line task manager written in C++ that allows users to create, update, delete, and list tasks stored in a JSON-like text file.

Sample solution for the task-tracker challenge from roadmap.sh.

## Features
- Add new tasks
- Update task descriptions
- Delete tasks
- Mark tasks as "in-progress" or "done"
- List all tasks or filter by status

## Installation
### Prerequisites
- A C++ compiler (e.g., g++)
- Windows (MSYS2 MinGW) or Linux terminal

### Compilation
Run the following command to compile the program:
```sh
 g++ main.cpp -o task-cli
```

## Usage
Run the executable with the desired command:
```sh
./task-cli <command> [arguments]
```

### Commands
#### Add a Task
```sh
./task-cli add "Buy groceries"
```
**Output:**
```
Task added successfully (ID: 1)
```

#### Update a Task
```sh
./task-cli update 1 "Buy groceries and cook dinner"
```
**Output:**
```
Task updated successfully.
```

#### Delete a Task
```sh
./task-cli delete 1
```
**Output:**
```
Task deleted successfully.
```

#### Mark a Task as In-Progress
```sh
./task-cli mark-in-progress 1
```
**Output:**
```
Task marked as in-progress.
```

#### Mark a Task as Done
```sh
./task-cli mark-done 1
```
**Output:**
```
Task marked as done.
```

#### List All Tasks
```sh
./task-cli list
```
**Output:**
```
[1] Buy groceries - todo (Created: Sun Feb 24 12:34:56 2025)
[2] Complete assignment - in-progress (Created: Sun Feb 24 12:40:00 2025)
[3] Call the doctor - done (Created: Sun Feb 24 12:45:30 2025)
```

#### List Only Completed Tasks
```sh
./task-cli list done
```

#### List Only To-Do Tasks
```sh
./task-cli list todo
```

#### List Only In-Progress Tasks
```sh
./task-cli list in-progress
```

### Help Message
If an invalid command is provided, the following message will be displayed:
```
Usage: task-cli <command> [arguments]
Invalid command.
```

## Notes
- The tasks are stored in `tasks.json`. If the file does not exist, it will be created automatically.
- Ensure the `tasks.json` file is in the same directory as the executable.

## License
This project is open-source and available under the MIT License.

