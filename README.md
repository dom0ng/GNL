# GNL

This project consist of writing a function get_next_line which get the next line in a file.

There are some features this function must implement:

we only use libft.
we need to implement a buffer. We can't come back in the file descriptor. We can't move in the file descriptor. We can only use read, free, malloc. No call to lseek.
we can't use global variable.
we can't use FILE structure. We need to create one.
we can read multiple file descriptors at the same time (which implies a buffer).
we can't have memory leaks: every malloc must be freed.
the buffer size (use by read) can be changed.
# GNL 42School
This project consist of writing a function get_next_line which get the next line in a file.

### F.A.Q
* [What is GNL?](#what-is-GNL)
* [What's in it?](#whats-in-it)
* [How does it work?](#how-does-it-work)
* [Example usage](#example-usage)

### What is GNL?
This project consist of writing a function get_next_line which get the next line in a file.
### What's in it?


### How does it work?

The goal is to create a library called libft.a from the source files so I can later use that library from other projects at [42][2].

To create that library, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, call make:

	git clone https://github.com/dom0ng/GNL
	cd GNL
