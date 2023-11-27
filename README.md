# Push_swap

1. [Overview](#overview)
2. [Project Goals](#project-goals)
3. [Game Rules](#game-rules)
    - [Operations](#operations)
4. [The `push_swap` Program](#the-push_swap-program)
    - [Usage](#usage)
5. [Getting Started](#getting-started)
    1. [Clone the Repository](#1-clone-the-repository)
    2. [Compile the Program](#2-compile-the-program)
    3. [Run the Program](#3-run-the-program)
    4. [Example](#4-example)

## Overview

Push_swap is a sorting algorithm project that challenges your ability to manipulate data on two stacks, 'a' and 'b,' using a limited set of instructions. The goal is to achieve the lowest number of actions possible by implementing and optimizing various sorting algorithms.

## Project Goals

- Implement a sorting algorithm in C.
- Understand algorithmic complexity.
- Develop coding rigor.

## Game Rules

- Two stacks: 'a' and 'b.'
- 'a' contains random positive/negative integers without duplicates.
- 'b' starts empty.
- Sort 'a' in ascending order.

### Operations:

- `sa`: Swap the first 2 elements at the top of 'a.'
- `sb`: Swap the first 2 elements at the top of 'b.'
- `ss`: Simultaneous 'sa' and 'sb.'
- `pa`: Push the first element at the top of 'b' to 'a.'
- `pb`: Push the first element at the top of 'a' to 'b.'
- `ra`: Rotate all elements of 'a' up by 1.
- `rb`: Rotate all elements of 'b' up by 1.
- `rr`: Simultaneous 'ra' and 'rb.'
- `rra`: Reverse rotate all elements of 'a' down by 1.
- `rrb`: Reverse rotate all elements of 'b' down by 1.
- `rrr`: Simultaneous 'rra' and 'rrb.'

## The `push_swap` Program

### Usage:

- **Usage:** `./push_swap [list of integers]`
- The program takes a formatted list of integers as input.
- The first element in the list will be at the top of stack 'a.'
- Displays the smallest list of instructions to sort 'a.'
- In case of an error (e.g., non-integer arguments, out-of-range arguments, duplicates), display "Error" followed by a newline on the standard error.

## Getting Started

### 1. Clone the Repository:

   ```bash
   git clone [repository_url]
   cd push_swap
   ```

### 2. Compile the Program:

   ```bash
   make
   ```

### 3. Run the Program:

   ```bash
   ./push_swap [list of integers]
   ```

### 4. Example:

   ```bash
   ./push_swap 3 1 4 2
   ```

**Happy Sorting!**
