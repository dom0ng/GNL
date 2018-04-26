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

### F.A.Q
* [What is GNL?](#what-is-GNL)
* [How does it work?](#how-does-it-work)
* [Example usage](#example-usage)

### What is GNL?
This project consist of writing a function get_next_line which get the next line in a file.


### How does it work?


To create that executable, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, then compile:

	git clone https://github.com/dom0ng/GNL
	cd GNL
