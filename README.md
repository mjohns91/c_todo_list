# C Todo List

A simple, terminal-based todo list application written in C. This application supports both interactive and command-line modes, allowing users to manage their tasks efficiently with persistent storage.
***
## Features

- Interactive menu-driven interface
- Command-line interface for quick actions
- Colored task display (green for completed, yellow for pending)
- Persistent storage using CSV file format
- Basic task management operations:
  - List all tasks
  - Add new tasks
  - Mark tasks as completed
  - Delete tasks
***
## Building the Project

### Prerequisites

- C compiler (GCC recommended)
- CMake (version 3.10 or higher)
- Make

### Build Instructions

#### Clone the Repo
- `git clone [https://github.com/yourusername/c_todo_list.git]`
- `cd c_todo_list`

#### Create build directory
- `mkdir build && cd build`

#### Generate build files
- `cmake ..`

#### Build the project
- `make`

***

## Usage

### Interactive Mode

Run the program without arguments to enter interactive mode:
- `bash ./todo`

This will display a menu with the following options:
1. List tasks
2. Add task
3. Mark task as done
4. Delete task
5. Save and exit

### Command Line Mode

The program supports the following command-line arguments:
- `bash ./todo [command] [argument]`

Available commands:
- `list` - Show all tasks
- `add "task text"` - Add a new task
- `done task_id` - Mark a task as completed
- `delete task_id` - Delete a task

Examples:
- `./todo add "Buy groceries"`
- `./todo list`
- `./todo done 1`
- `./todo delete 2`

***
## Contributing

1. Fork the repository
2. Create a new branch for your feature
3. Commit your changes
4. Push to the branch
5. Submit a pull request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

Matthew Johnson
