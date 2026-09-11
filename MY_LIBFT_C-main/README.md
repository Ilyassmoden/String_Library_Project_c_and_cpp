# 🚀 Custom Pure C Standard Library Core (C-Suite)

A collection of custom-built, lightweight, and highly optimized standard libraries implemented in pure C from scratch. This project demonstrates low-level memory management, dynamic data structures, robust file serialization, and complex algorithmic implementations without relying on high-level abstractions.

---

## 🛠️ Key Modules & Architecture

### 1. Dynamic Memory Management (`VECTOR_VOID.h` & `VECTOR_MACRO.h`)
*   **Generic Dynamic Vectors:** Implemented a type-safe `VECTOR_PUSH_BACK` macro that automatically doubles the internal buffer capacity upon reaching limits.
*   **Void Pointer Arrays:** Features structural support for dynamic allocation tracking (`void **arr`) ensuring generic storage capabilities.

### 2. Advanced String Manipulation (`LIBFT_STRING.h`)
*   **Tokenization & Splitting:** Custom string division using dynamic delimiters (e.g., `#//#`) without memory leaks.
*   **Text Processing:** Native implementation for string trimming (left, right, and full), word replacement (case-sensitive and insensitive), text casing adjustments, and vowel analysis.

### 3. Chronos Algorithm Hub (`LIBFT_TIME.h` & `DATA_STRUCTER.h`)
*   **Calendar & Period Utilities:** Complete pipeline to calculate leap years, precise gaps between dual dates, overlapping intervals, and direct console calendar rendering.
*   **Business Logistics:** Logic-based calculation for vacation return thresholds by skipping weekends or official holidays automatically.

### 4. Minimalist Financial Core (`CONVERT.h`, `DATA_FILE.h` & `READ_INPUT.h`)
*   **Binary Serialization:** Direct streaming of relational structured objects into encrypted or binary states (`student_data.bin`) using secure low-level `fwrite` operations.
*   **Safe Data Entry:** Buffering console entries dynamically with pointer adjustments and safe data parsing to prevent buffer overflows.

---

## 🏗️ Technical Highlights

*   **Zero Leak Policy:** Strict memory management utilizing manual `malloc`, `realloc`, and `free` routines across multi-dimensional matrices and pointer arrays.
*   **Macro-Driven Type Safety:** Leverage of the C preprocessor to encapsulate data structures safely.
*   **ANSI Terminal UI:** Colorful debugging outputs via integrated ANSI macros (`RED`, `GREEN`, `YELLOW`, `BLUE`).

---

## 💻 Compilation & Quick Start

Since this is a header-only utility ecosystem, you can include any desired module directly into your setup:

```c
#include "VECTOR_VOID.h"
#include "LIBFT_STRING.h"

int main() {
    // Example of using the custom library string split feature
    int count = 0;
    name tokens = split_string("Ilyas#//#Ait#//#Elmouden", "#//#", &count);
    
    // Process tokens ...
    
    return 0;
}