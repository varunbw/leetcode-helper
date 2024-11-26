# FAQ

## What is a C++ library?
Watch [this video](https://www.youtube.com/watch?v=a5kUr-u2UNo) to learn what libraries do before you get into this one.

## How do I provide input?
The code provided in `main.cpp` works in the standard competetive programming format.
The code is parsed from a input file stream (`std::ifstream`), and considers the file `input.txt`. You can change the name of the file to suit your needs by accordingly changing it when it is initialized.

The first line of the file should contain the number of testcases you want to run. Lines following it should contain the data to parse (each one on a new line).
Arrange the file parsing functions in whatever format you want each testcase to be parsed in.

Ex: Consider you want to parse a `1D vector<int>`, and then, a `1D vector<string>`. You have **2** such test cases.

The file `input.txt` should look like this:
```txt
2
[1,2,3,4,5]
["Hello","world"]
[6,7,8,9,0]
["Testing","123"]
```

The 1st line `2` states that there are 2 testcases.\
The 2nd line `[1,2,3,4,5]` represents the `1D vector<int>` to be parsed.\
The 3rd line `["Hello","world"]` represents the `1D vector<string>` to be parsed.\
The 4th and 5th line contain the next test case.

The contents of your loop should look like this
```cpp
while (t--) {
    vector<int> vec1    = FileParse_Int1D(fin);
    vector<string> vec2 = FileParse_String1D(fin);
    // Any other code...
}
```

This works because file streams work the same way as `cin` does.

#### Passing data from the command line
If you don't want to use files for some reason, you can provide command line arguments as well by using the `ArgsParse_` functions instead, that take stuff from the command line. Pass the parameters correctly, reference comments to figure out what they need.

#### Parsing data from cin instead of the file
Simply pass `cin` as a parameter to the `FileParse_` functions instead.

## How do I make data structures like trees, graphs, etc?
Functions like `CreateLinkedList`, `CreateBinaryTree`, `CreateGraph`, etc. all expect their own format. Refer the comments to figure out what argument to pass, and what you as the return value.

## How do I know what a function does?
~~Practice literacy~~ You can hover over a function in VS Code or other editors like it, and it'll show you the comment explaining what the function does. Alternatively, you can directly go to either the header file [lch.h](include/lch.h), or the functions respective source file in `src/`.

## What file is "output.txt" in .gitignore?
You can send your output to a file instead of the console if you wish by adding this to `main.cpp`:
```cpp
ofstream fout("output.txt");
```
And then using `fout <<` instead of `cout <<`.

## What file is "expected.txt" in .gitignore?
That is where you can put your expected output, and parse it like you normally would parse your input, expect with its own file stream this time. `std::ifstream finExpected("")` is the one that points to the file.

Lets say you want to compare the output that your function returns, to the expected output for a testcase. You can do it like this example:\
expected.txt
```
[1,2,3,4,5]  <--- Your expected output in the correct format
```

main.cpp
```cpp
while (t--) {

    vector<int> vec = FileParse_Int1D(fin);
    vector<int> res = sol.SolveProblem(vec); // Result of your solution
    vector<int> expected = FileParse_Int1D(finExpected) // Expected solution

    // Compare the two down here
    cout << ((res == expected) ? "Passed\n" : "Failed\n") // Example

    // Any other code...
}
```

## What does DeleteAllocatedNodes() do at the end of main.cpp?
During parsing, if you are making a linked list, a binary tree, or a graph, we need to dynamically allocate memory. This memory needs to be freed for 2 reasons:
- It is good practice.
- Address Sanitizer will scream in your console everytime you run the program because you are leaking memory (by not freeing dynamically allocated memory).

The funciton will free all nodes that are alloaced by the functions responsible for making the data structures. If you dynamically allocate outside of these functions, you'll need to keep track of them and free them separately.

## What is the fastIO thingy at the start?

This is a lambda function for I/O optimization, commonly used in competitive programming, or situations where fast I/O is essential.

`ios::sync_with_stdio(false)`\
The C standard streams (`stdin`, `stdout`) are synchronized with their C++ counterparts (`cin`, `cout`). The above line disables the sync, and speeds up I/O operations. You might not notice it when executing locally; try putting it in your Leetcode submissions and see the runtime change.

`cin.tie(nullptr)`\
Before accepting input, `cin` will print everything in `cout` to the console. This line detaches them, and prevents unnecessary flushing that further improves performance.

`cout.tie(nullptr)`\
Redundant, its here because I copy pasted the snippet from some LC submission, not because I came up with the fastIO myself.

## When passing input through the console, I don't get an output immediately like I normally would.
This is due to the line `cin.tie(nullptr)`. When you write this, anything stored in `cout` will be printed only after the `cin` opeartions are over.
If you have commented this line, or expect no more input, your code is still executing.

## I made changes to the library, but its not reflecting in execution.
Did you compile it?