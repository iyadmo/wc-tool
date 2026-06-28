# ccwc

A custom implementation of the Unix `wc` (word count) command, built from scratch in C as part of the [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-wc) series by John Crickett.

## What it does

Counts lines, words, and bytes in a file or from standard input — just like the real `wc` command.

## Usage

```bash
ccwc [flag] [file]
```

### Flags

| Flag | Description         |
|------|---------------------|
| `-l` | Count lines         |
| `-w` | Count words         |
| `-c` | Count bytes         |
| `-m` | Count characters    |

### Examples

```bash
# Count lines, words, and bytes (no flag)
ccwc myfile.txt

# Count only lines
ccwc -l myfile.txt

# Count only words
ccwc -w myfile.txt

# Count bytes from stdin
cat myfile.txt | ccwc -c

# Read from stdin with no arguments
ccwc
```

## Building

```bash
gcc -o ccwc ccwc.c
```

## How it works

The program has four counting functions:

- `count_all()` — counts lines, words, and bytes in a single pass
- `count_lines()` — counts newline characters
- `count_words()` — tracks transitions between whitespace and non-whitespace
- `count_bytes()` — counts every character read

Input can come from a file or stdin. The flag and filename are both optional.

## Built with

- C (C99)
- Standard library only (`stdio.h`, `string.h`, `ctype.h`, `stdlib.h`)
