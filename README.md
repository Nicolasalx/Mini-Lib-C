# ASM C Library Recreation
This project is a recreation of standard C library functions using Assembly (ASM). The following functions have been recoded from scratch to closely replicate their behavior in C, focusing on low-level optimization and efficient memory manipulation.

## Functions Implemented
The following functions from the standard C library have been implemented in assembly:

- ffs.asm - Find the first bit set
- memcpy.asm - Copy memory block
- memmove.asm - Move memory block (handles overlapping areas)
- memset.asm - Fill memory with a constant byte
- strcasecmp.asm - Compare two strings, ignoring case
- strchr.asm - Locate the first occurrence of a character in a string
- strcmp.asm - Compare two strings
- strcspn.asm - Get the length of a segment not containing certain characters
- strlen.asm - Get the length of a string
- strncmp.asm - Compare two strings with a limit on the number of characters
- strpbrk.asm - Locate any of a set of characters in a string
- strrchr.asm - Locate the last occurrence of a character in a string
- strstr.asm - Locate a substring

## Grade: A
I achieved a grade of A for this project, demonstrating a solid understanding of assembly language, memory operations, and low-level C library functionality. Each function was carefully tested for correctness and performance.

## Prerequisites

To assemble and test the functions, you will need:

An x86 or x86_64 assembler (such as nasm or gas)
A C compiler for integration and testing (such as gcc or clang)
