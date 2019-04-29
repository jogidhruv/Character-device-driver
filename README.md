# Character-device-driver
Implements a character device driver that reverses a string written to it

Every device in UNIX is represented by a device file. So reading and
writing to a device is equivalent to performing file operations on
respective files.

Execute following commands in terminal to check working of device driver:

1) make               
2) make test          
3) sh test_script     
4) Insert a string that is supposed to be reversed
