# FAQ

## What is a C++ library?
Watch [this video](https://www.youtube.com/watch?v=a5kUr-u2UNo) to learn what libraries do before you get into this one.

## How do I provide input?
The code provided in `main.cpp` works in the standard competetive programming format.
The code is parsed from a input file stream (`std::ifstream`), and considers the file `input.txt`. You can change the name of the file to suit your needs by accordingly changing it when it is initialized.

Put the data you want to parse, each on a separate line.
Arrange the file parsing functions in whatever format you want each testcase to be parsed in.

Ex: Consider you want to parse a `1D vector<int>`, and then, a `1D vector<string>`. You have **2** such test cases.

The file `input.txt` should look like this:
```txt
[1,2,3,4,5]
["Hello","world"]
[6,7,8,9,0]
["Testing","123"]
```

The 1st line `[1,2,3,4,5]` represents the `1D vector<int>` to be parsed.\
The 2nd line `["Hello","world"]` represents the `1D vector<string>` to be parsed.\
The 3rd and 4th line contain the next test case.

The contents of your loop should look like this
```cpp
while (fin.eof() == false) {
    vector<int> vec1    = FileParse_Int1D(fin);
    vector<string> vec2 = FileParse_String1D(fin);
    // Any other code...
}
```

#### Passing data from the command line
If you don't want to use files for some reason, you can provide command line arguments as well by using the `ArgsParse_` functions instead, that take stuff from the command line. Pass the parameters correctly, reference comments to figure out what they need.

#### Parsing data from cin instead of the file
Simply pass `cin` as a parameter to the `FileParse_` functions instead.
```cpp
vector<int> vec = FileParse_Int1D(cin);
```

You can parse data from any `std::ifstream` object.

## How do I make data structures like trees, graphs, etc?
Functions like `CreateLinkedList()`, `CreateBinaryTree()`, `CreateGraph()`, etc. all expect their own format. Refer the comments to figure out what argument to pass, and what you as the return value.

You likely won't need to use `CreateGraph()`, since usually in Leetcode, graphs are represented as a list of edges (`vector<vector<int>>`), instead of giving you dynamically allocated nodes. However, there exist exceptions like `Q 133. Clone Graph` where you are given a dynamically allocated graph.

## How do I know what a function does?
~~Practice literacy~~ Each function has a detailed comment explaining what it does, either in the header file, or in the source file, but probably both.
Editors like VS Code also show you the comment if you hover your cursor over the function for a second.

## What file is "output.txt" in .gitignore?
You can send your output to a file instead of the console if you wish by adding this to `main.cpp`:
```cpp
ofstream fout("output.txt");
```
And then using `fout <<` instead of `cout <<`.

## What file is "expected.txt" in .gitignore?
That is where you can put your expected output, and parse it like you normally would parse your input, expect with its own file stream this time. `std::ifstream finExpected("")` is the one that points to the file.

Lets say you want to compare the output that your function returns, to the expected output for a testcase. You can do it like this example:\
`expected.txt:`
```
[1,2,3,4,5]  <--- Your expected output in the correct format
```

You can then use `AssertTestcase()` and pass the value you received, and your expected value that you parsed from `expected.txt`

main.cpp
```cpp
while (t--) {

    vector<int> vec = FileParse_Int1D(fin);
    vector<int> res = sol.SolveProblem(vec); // Result of your solution
    vector<int> expected = FileParse_Int1D(finExpected) // Expected solution

    // Use given assert function
    AssertTestcase(res, expected);

    // Manual assertion example
    cout << ((res == expected) ? "Passed\n" : "Failed\n")

    // Any other code...
}
```

## What does DeleteAllocatedNodes() do at the end of main.cpp?
During parsing, if you are making a linked list, a binary tree, or a graph, we need to dynamically allocate memory. This memory needs to be freed for 2 reasons:
- It is good practice.
- Address Sanitizer will scream in your console everytime you run the program because you are leaking memory (by not freeing dynamically allocated memory) (only on Linux).

The funciton will free all nodes that are allocated by the functions responsible for making the data structures. If you dynamically allocate outside of these functions, you'll need to keep track of them and free them separately.

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

## Why do I have to encase all strings/chars in ""?
Although support for single inverted commas, and nothing at all (ie. `'Hello'`, or `Hello`) is possible, it's not done in the event that a string input contains the characters " or ' at the beginning of the input.

ex: `"Hello`

It is not possible to determine in this case what pattern the user is following. Hence, it is safer to wrap all strings around 2 "s

ex: `""Hello"`

This format allows the functions to safely remove the starting and ending "s, leaving the string untouched

#### To change what character should encase a string (ex: ', ", `), simply change it in the innermost while loops, where they are removed
```cpp
// Remove starting and ending "s
if (item.size() && item[0] == '"')
    item.erase(item.begin());
if (item.back() == '"')
    item.pop_back();
```

Change it, recompile the library, and you're good to go!