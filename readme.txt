1. How to compile
- Open the terminal at the source code folder (folder 03).
- Execute the following command:
- For Windows:
  > g++ *.cpp -std=c++17 -o 03.exe
- For Linux/macOS:
  > g++ *.cpp -std=c++17 -o 03

2. Usage instructions (for Windows)
2.1 Algorithm Mode
- Command 1: Run a sorting algorithm on the given input data.
# Prototype:
> 03.exe -a [Algorithm] [Input_file] [Output_parameter]
# Example:
> 03.exe -a radix-sort input.txt -both

- Command 2: Run a sorting algorithm on automatically generated data with a specified size and order.
# Prototype:
> 03.exe -a [Algorithm] [Input_size] [Input_order] [Output_parameter]
# Example:
> 03.exe -a selection-sort 100 -rand -time

- Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
# Prototype:
> 03.exe -a [Algorithm] [Input_size] [Output_parameter]
# Example:
> 03.exe -a quick-sort 10000 -both

2.2 Comparison Mode
- Command 4: Run two sorting algorithms on the given input data.
# Prototype:
> 03.exe -c [Algorithm_1] [Algorithm_2] [Input_file]
# Example:
> 03.exe -c heap-sort merge-sort input.txt

- Command 5: Run two sorting algorithms on automatically generated data.
# Prototype:
> 03.exe -c [Algorithm_1] [Algorithm_2] [Input_size] [Input_order]
# Example:
> 03.exe -c quick-sort merge-sort 100000 -nsorted

3. Options
- Mode: -a (algorithm mode), -c (comparison mode)
- Algorithm: selection-sort, insertion-sort, binary-insertion-sort, bubble-sort, shaker-sort, shell-sort, heap-sort, merge-sort, quick-sort, counting-sort, radix-sort, flash-sort
- Input_file: Path to user-provided data file with the following format:
    + 1st line: An integer n (number of elements)
    + 2nd line: n integers, separated by a single space
- Input_size: A positive integer (<= 1,000,000)
- Input_order: -sorted, -nsorted, -rev, -rand
- Output_parameter: -time, -comp, -both

4. Notes on Output Files
- For Commands 1 & 2: The sorted array is written to "output.txt".
- For Commands 2 & 5: The generated input is written to "input.txt".
- For Command 3: All four generated arrangements are written to:
    + "input_1.txt": Random order data
    + "input_2.txt": Nearly sorted data
    + "input_3.txt": Sorted data
    + "input_4.txt": Reversed data

5. Some other notes
- On Linux/macOS, run the program using: ./03 [arguments] instead of 03.exe [arguments]
- The source code strictly adheres to the GNU standard library; no external libraries are required.