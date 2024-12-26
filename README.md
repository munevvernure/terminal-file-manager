# Terminal-Based File Manager

## Overview
This project is a **Terminal-Based File Manager** designed to perform basic file management operations using Linux/Unix system calls. The program provides a command-line interface (CLI) to interact with the file system, enabling efficient file and folder operations.

### Features
- **File Operations**: Create, Read, write, copy, move and delete files.
- **Directory Operations**: List, create, and delete directories.
- **File/Folder Permissions**: Check and modify permissions.
- **Logging**: Log all operations performed by the user.
- **Error Handling**: Displays meaningful error messages for failed operations.

### System Calls Used
- File and Directory Management: `opendir`, `readdir`, `creat`, `unlink`, `rmdir`
- File Operations: `open`, `read`, `write`, `delete`, `rename`
- Permissions: `chmod`
- Logging: `open`, `write`

## Project Structure
The project is modular and consists of the following components:

```
terminal-file-manager/
├── src/
│   ├── main.c
│   ├── file_operations.c
│   ├── directory_ops.c
│   ├── permissions.c
│   ├── logger.c
├── include/
│   ├── file_operations.h
│   ├── directory_ops.h
│   ├── permissions.h
│   ├── logger.h
├── bin/
│   └── file_manager  #executable file
├── Makefile


### Example Commands
- **List Directories**:
  ```bash
  > dlist /home/user/documents
  ```
- **Copy File**:
  ```bash
  > fcopy /home/user/file.txt /home/user/documents/
  ```
- **Remove File**:
  ```bash
  > fremove /home/user/documents/oldfile.txt
  ```
- **Change Permissions**:
  ```bash
  > pchange 755 /home/user/documents
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


