*This project has been created as part of the 42 curriculum by anacharp.*

# get_next_line

## Description
get_next_line is a function that reads a file descriptor and returns one
line at each call, until the end of the file. It relies on a static
variable to keep the remaining data between calls, and works with any
buffer size. The project teaches file descriptors, static variables and
dynamic memory management.

## Instructions
Compile with a chosen buffer size:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Usage:
```bash
char *line = get_next_line(fd);
```
Each call returns the next line (including the `\n`), or `NULL` at the
end of the file or on error. Free each returned line.

## Resources
- `man 2 read`, `man 2 open`
