# ⚙️ Custom C Preprocessor

## 📖 Overview
This project implements a custom C preprocessor tool named **mypreprocessor**.  
The program reads a C source file, performs preprocessing operations, and generates an extended source file with a **.i** extension.

The preprocessor performs:
- Comments removal
- Header file inclusion
- Macro substitution

---


## ✨ Features
✅ Removes single-line comments (`//`)  
✅ Removes multi-line comments (`/* ... */`)  
✅ Processes `#include <filename>` directives  
✅ Stores and replaces macros defined using `#define`  
✅ Generates extended source file (`.i`)  
✅ Accepts input file through command-line arguments  

---

## 💻 Technologies Used
- C Programming
- File Handling
- String Manipulation
- Command-Line Arguments

---

## 📂 Project Files

| File Name | Description |
|-----------|-------------|
| `preprocessor.c` | Main source code |
| `inputfile.c` | Sample input file |
| `myheader.h` | Header file for include testing |
| `inputfile.i` | Generated output file |

---

## 🔄 Project Workflow

```text
Input C File
    ↓
Comment Removal
    ↓
Header File Inclusion
    ↓
Macro Storage & Replacement
    ↓
Generate .i File
```

---

## ⚙️ Compilation

```bash
gcc preprocessor.c -o mypreprocessor
```

---

## ▶️ Execution

```bash
./mypreprocessor inputfile.c
```

---

## Sample Input (`inputfile.c`)

```c
#include <myheader.h>

#define MESSAGE "HELLO"
#define PI 3.14

int main()
{
    int r = 5;

    // This is radius

    float area;

    /*
       Area Formula:
       PI * r * r
    */

    area = PI * r * r;

    printf(MESSAGE);

    return 0;
}
```

---

## Sample Header File (`myheader.h`)

```c
int x = 18;
float y = 22.5;
```

---

## Sample Output (`inputfile.i`)

```c
int x = 18;
float y = 22.5;

int main()
{
    int r = 5;

    float area;

    area = 3.14 * r * r;

    printf("HELLO");

    return 0;
}
```

---

## 🎯 Learning Outcomes
- Understanding of C preprocessing concepts
- File handling in C
- String parsing and manipulation
- Macro processing
- Command-line argument handling

---

## 🚀 Future Enhancements
- Support function-like macros
- Support nested header files
- Support conditional compilation directives
- Improved formatting and indentation

---
