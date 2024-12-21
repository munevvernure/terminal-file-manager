# Terminal-Based File Manager

## Overview
This project is a **Terminal-Based File Manager** designed to perform basic file management operations using Linux/Unix system calls. The program provides a command-line interface (CLI) to interact with the file system, enabling efficient file and folder operations.

### Features
- **File Operations**: Read, write, copy, and delete files.
- **Directory Operations**: List, create, and delete directories.
- **File/Folder Permissions**: Check and modify permissions.
- **File Search**: Search for files within a directory.
- **Logging**: Log all operations performed by the user.
- **Error Handling**: Displays meaningful error messages for failed operations.

### System Calls Used
- File and Directory Management: `opendir`, `readdir`, `creat`, `unlink`, `rmdir`
- File Operations: `open`, `read`, `write`, `rename`
- Permissions: `chmod`
- Logging: `open`, `write`

## Project Structure
The project is modular and consists of the following components:

```
project/
├── src/
│   ├── main.c              # Controls the program flow and command parsing
│   ├── file_operations.c   # Handles file read, write, copy, and move operations
│   ├── directory_ops.c     # Implements directory listing, creation, and deletion
│   ├── permissions.c       # Manages file and folder permissions
│   └──logger.c             # Logs all operations to a log file
│ 
├── include/                # Header files
└── bin/                    # Compiled executable
└── Makefile                # Builds the project

### Example Commands
- **List Files**:
  ```bash
  > slist /home/user/documents
  ```
- **Copy File**:
  ```bash
  > scopy /home/user/file.txt /home/user/documents/
  ```
- **Remove File**:
  ```bash
  > sremove /home/user/documents/oldfile.txt
  ```
- **Change Permissions**:
  ```bash
  > schmod 755 /home/user/documents
  ```

## Getting Started

### Prerequisites
- GCC Compiler
- Linux/Unix Operating System

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/munevvernure/terminal-file-manager.git
   ```
2. Navigate to the project directory:
   ```bash
   cd terminal-file-manager
   ```
3. Build the project using the Makefile:
   ```bash
   make
   ```
4. Run the executable:
   ```bash
   ./bin/file_manager
   ```

## Logging
All operations performed by the file manager are logged to a log file with details such as:
- Operation type
- Date and time
- Success or failure status

## Error Handling
The program validates user inputs and provides meaningful error messages for invalid commands or system call failures.

## Contributing
1. Fork the repository.
2. Create a new branch for your feature:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature description"
   ```
4. Push to your branch:
   ```bash
   git push origin feature-name
   ```
5. Create a Pull Request.


## Authors
- Münevvernur Eraslan
- Esra Çelik
- Sema İrem Kardaş
- Kerim Tunçer


