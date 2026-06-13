# 101-crackme

A reverse-engineering exercise: analyzing a compiled C binary using `objdump`,
understanding its checksum-based password validation, and writing a keygen
that generates valid passwords.

## Files

- `101-crackme` — the compiled binary to crack
- `101-keygen.c` — generates random valid passwords for `101-crackme`

## How it works

The binary checks command-line input against a hidden algorithm:

```c
long checksum(char *s)
{
    long sum = 0;

    while (*s != '\0')
    {
        sum += *s;
        s++;
    }
    return (sum);
}
```

It sums the ASCII values of every character in the input and compares the
result to `0xad4` (2772). If they match, it prints `Tada! Congrats`.

This was reverse-engineered using:

- `strings` to locate key string literals
- `objdump -d -Mintel` to disassemble `main` and `checksum`
- Tracing register usage, stack frames, and the x86-64 calling convention

## Usage

Compile the keygen:

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 101-keygen.c -o 101-keygen
```

Generate a valid password and crack the binary:

```bash
./101-crackme "$(./101-keygen)"
```

Expected output on success:

```
Tada! Congrats
```

## Writeup

Full breakdown of the reverse-engineering process: [https://m0ng00s3-blog.hashnode.dev/solving-a-simple-crackme]

## Skills Demonstrated

- x86-64 assembly analysis
- Reverse engineering with `objdump` and `strings`
- C programming (low-level memory and pointer manipulation)
- Understanding stack frames and calling conventions
