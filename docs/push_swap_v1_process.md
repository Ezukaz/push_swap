# Push_swap Process

**Date Started**: 2026-02-11

**Goal**: *Print operations that logically sort a stack of numbers to ascending order while meeting the required efficiency*

## Start: Checklist
<details>
<summary>Proof-checking Manual</summary>

### Mandates from [en.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/192754/en.subject.pdf)

#### Musts

Common Instructions
- [x] Your project must be written in C.
- [ ] Your project must be written in accordance with the Norm.
- [ ] All heap-allocated memory must be properly freed when necessary.
- [ ] If the subject requires it, you must submit a Makefile that compiles your source files to the required output with the flags `-Wall, -Wextra, and -Werror`, using `cc`.
- [ ] Your Makefile must contain at least the rules `$(NAME), all, clean, fclean` and `re`.
- [ ] If your project allows you to use your libft, you must copy its sources and its associated Makefile into a libft folder. Your project’s Makefile must compile the library by using its Makefile, then compile the project.

Push_swap instructions
- [ ] Must submit `Makefile, *.h, *.c`
- [ ] You have to write a program named `push_swap`. The first argument should be at the top of the stack.
- [ ] You have to turn in a Makefile which will compile your source files.
- [ ] The program must display the shortest sequence of instructions needed to sort stack a with the smallest number at the top.
- [ ] Instructions must be separated by a `’\n’` and nothing else.
- [ ] The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated.
- [ ] You must be able to parse arguments and a string of arguments. *(**not directly written but shown as an example in the manual**)*
- [ ] External Functions: Read, write malloc, free, exit, ft_printf or any equivalent that YOU coded.

Bad input instructions
- [ ] If no parameters are specified, the program must not display anything and should return to the prompt.
- [ ] In case of error, it must display `"Error"` followed by an `’\n’` on the standard error.

Limits instructions
- [ ]  For maximum project validation (100%) and eligibility for bonuses, you must:
	- [ ] Sort 100 random numbers in fewer than 700 operations.
	- [ ] Sort 500 random numbers in no more than 5500 operations.
- [ ] For minimal project validation (which implies a minimum grade of 80%), you
can succeed with different averages:
  - 100 numbers in under 1100 operations and 500 numbers in under 8500 operations
  - 100 numbers in under 700 operations and 500 numbers in under 11500 operations
  - 100 numbers in under 1300 operations and 500 numbers in under 5500 operations

Readme instructions
- [ ] A README.md file must be provided at the root of your Git repository.
- [ ] The README.md must include at least:
   - [x] The very first line must be italicized and read: This project has been created as part of the 42 curriculum by `<login1>`[, `<login2>`[, `<login3>`[...]]].
   - [ ] A “Description” section that clearly presents the project, including its goal and a brief overview.
   - [ ] An “Instructions” section containing any relevant information about compilation, installation, and/or execution.
   - [ ] A “Resources” section listing classic references related to the topic (documentation, articles, tutorials, etc.)
   - [ ] as well as a description of how AI was used — specifying for which tasks and which parts of the project.

#### Must Nots

- [ ] Makefile must not relink.
- [ ] Must not have anything other than `'\n'` between instructions.
- [ ] If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- [ ] Errors include, for example: some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.

### Targets

- [ ] Writes instructions with a `'\n'` at the end of each instruction
- [ ] The program `push_swap` must display the shortest sequence of instructions needed to sort stack a with the smallest number at the top.
- [ ] Makefile
- [ ] The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- [ ] If no parameters are specified, the program must not display anything and should return to the prompt.
- [ ] In case of error, it must display `"Error"` followed by an `’\n’` on the standard error. Errors include, for example: some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.

### Forbidden

- [ ] Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) except for undefined behavior.
- [ ] Your Makefile must not relink.
- [ ] Global variables are forbidden.
</details>

## Initial Strategy

<details>
<summary>Brainstorm</summary>

-  **Restate**: Take integers -> sort stack A (smallest on top) -> print minimal operations
-  **Input**: `argv[1...n]` unique neg/pos integers
-  **Output**: operation + `\n` or nothing if no parameters or "Error`\n`" for standard errors:<br>(duplicates, non-integers, integer over/underflow)
- **Success**: <700 operations (100 nums), <5500 operations (500 nums)
- **Contraints**: Norm, no global vars, authorized funcs only (libft, ft_printf, read, write, malloc, free, exit)
- **Smallest case**: 2 nums -> 1 swap
- **Brute force**: Try all permutations -> ng
- **Invariants**: (if violated then error)
  - Stack always valid
  - Memory always freed
- **Assumptions**:
  - Radix, turk, 
</details>


## Structure

<details>
<summary>Tree</summary>

### File Structure

```
push_swap/
├── push_swap.c
├── docs/
|  ├── push_swap_v1_process.md
├── ops/
|  ├── swap.c
|  ├── push.c
|  ├── rotate.c
├── sort/
|  ├── small_sort.c
|  ├── radix.c
├── push_swap.h
├── Makefile
└── README.md
```

### Flow Chart




</details>

## Logs

<details>
<summary>Decisions/Bugs/Tests</summary>

### Decision Log

|      | When | Category | Choice | Why | Trade-offs | How works | Where |
|------|------|----------|--------|-----|------------|-----------|-------|
| Ex | ~~2026-02-11~~ | ~~Parsing~~ | ~~Array~~ | ~~Speed tests 2x faster~~ | ~~Scale risk~~ | ~~Token array~~ | ~~parse_input()~~ |
| | 2026-2-13 | Parsing | list | Array is impossible as  it needs to store INT_MAX amount of values | Slightly slower check | check list from start till end or found | ps_parse() |
|| 2026-02-19 | Parsing | array | Array is possible with memmove | None at the moment. This is what memmove was made for | Save the head or tail, shift everything else to the side, place the saved value in the vacant space | rotation |
|| 2026-02-22 | Operations | Three op funcs and one controller | Scalability | Might be a little tricky to read | Controller uses ifs to decide what string literal uses what function | operations.c |
|| 2026-02-25 | Sort | Sniffer->Calculator->Brain->Operator | It clicked | Swap_b and Swap_both are useless | Do math to figure out the least costly move | sort()?maybe |
|||||||||

### Fixed Bugs Log

|      | Date | Symptom | Fix |
|------|------|---------|-----|
| Ex | 2026-02-12 | Valgrind "invalid read" on spaces | `while (isspace((unsigned char)*str)) str++;` |
|| 2026-02-19 | int overflow not detected | my_atol to return long |
|| 2026-02-19 | non numbers did not return NULL | changed is_int to !is_int check |
|| 2026-02-23 | middle of array was a totally different number from input | memmove processes in bytes. if int is small then no problem but if it goes over one byte then we start to see something strange |
|| 2026-02-23 | arg_format was returning t_stack which is for ints but arg_format isn't handling ints but strings | made a new static array for strings |
|| 2026-02-24 | no path for caller of ft_split returning NULL | error check added |
|||||

### Tests Log *(Be specific)*

| Name | Date | Basic | Full-scale | Edge case | Commands |
|------|------|-------|------------|-----------|----------|
| Ex | 2026-02-12 | ✅ | ✅ | ❌ | `make ftest && valgrind ./a.out "$(cat tests/big.txt)"` |
| Validator | 2026-02-19 | ✅ A good case | ✅ Dups & int limits | ✅ Non int | `ccw validator.c utils.c ./libs/libft/ft_isdigit.c -o test && ./test` |
| Parser | 2026-02-23 | ✅ Just numbers | ❌ Strings with spaces | ✅ No input | `ccw validate_parse.c utils.c ./libs/libft/ft_isdigit.c -o test` |
| Operator | 2026-02-24 | ✅swap ✅push ❌rotate(i was giving memmove number of elements and not number of bytes) | ❌ Operator(op == "sa" is comparing pointers which will always be false) |  | `ccg operations.c validate_parse.c utils.c libs/libft/libft.a` |
||||||||

### Completed Files

| Name | Date | Comments |
|------|------|-------|
| Ex | 2026-02-12 | Was a long struggle |
| Validator | 2026-02-19 | Test passed smoothly |
| validate_parse | 2026-02-22 | parsing tests complete |
||||

### AI Usage

| Date | How used | Ex.Q |
|------|------|-------|
| ~~2026-02-12~~ | ~~Ex.Confirmation~~ | ~~How large is INT_MAX?~~ |
| 2026-02-19 | Good practice habits | Should I add const before ints? |
| 2026-02-19 | Word meaning | What is standard error? |
| 2026-02-22 | Int / size_t / unsigned char | When should variables or parameters be int, unsigned char, or size_t? |
| 2026-02-24 | Sorting strategy | Should I research sorting methods or make one myself? |
| 2026-02-25 | Sorting strategy | Is the worst case n factorial? ~ Is sort like a math possibility thing? ~ Does the overall logic change from small inputs to larger ones? |
||||
</details>

## Finish: Review Prep Checklist

<details>
<summary>Checklist</summary>

- [ ]  Explain the strengths of your project (what you’d brag about)
- [ ]  Explain the weaknesses of your project
- [ ]  Predict questions you might get (2-3 + your answer to each)
</details>
  
## Post-Mortem

<details>
<summary>Ending thoughts</summary>

- Wrong assumption
  - Placeholder
- Biggest Win
  - Placeholder
</details>
