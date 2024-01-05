# Segment Tree

A C++ implementation of a Segment Tree, a data structure used for range queries and updates on an array.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Examples](#examples)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Segment Tree is a versatile data structure that efficiently handles range queries and updates in an array. This repository contains a C++ implementation of a Segment Tree.

## Features

- Efficiently supports range queries and updates on an array.
- Implemented with a dynamic programming approach.
- Provides wrapper functions for ease of use.

## Usage

To use this Segment Tree implementation in your C++ project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/MO-AM1R/segment_tree
   ```

2. Include the `SegmentTree.h` header in your C++ files.

3. Create a `SegmentTree` object with the desired array:

   ```cpp
   int arr[] = {1, 3, 5, 7, 9, 11};
   SegmentTree segmentTree(arr, 6);
   ```

4. Use the provided wrapper functions for range queries and updates:

   ```cpp
   cout << segmentTree.getSum(0, 3) << endl; // Example: Range Query
   segmentTree.update(1, 10);                 // Example: Update
   ```

## Examples

Here are some examples demonstrating the usage of the Segment Tree:

```cpp
// Example 1: Basic Usage
int arr[] = {1, 3, 5, 7, 9, 11};
SegmentTree segmentTree(arr, 6);
cout << segmentTree << endl; // Segment Tree: [36, 9, 27, 4, 5, 16]

// Example 2: Range Query
cout << segmentTree.getSum(0, 3) << endl; // 16

// Example 3: Update
segmentTree.update(1, 10); // {1, 10, 5, 7, 9, 11}
cout << segmentTree.getSum(0, 3) << endl; // 23
```

## Building and Running

This project is a C++ header-only library, so there is no separate build process required. Simply include the `SegmentTree.h` header in your C++ project.

## Contributing

Feel free to contribute to the project by opening issues or creating pull requests. Follow the [contribution guidelines](CONTRIBUTING.md) for more details.
