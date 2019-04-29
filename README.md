# Character-device-driver
Implements a character device driver that reverses a string written to it

Execute following commands in terminal to check working of device driver:

1) make               
2) make test          //will create executable test file.
3) sh test_script     //will create device folder in /dev , inserts
                        device driver module using insmod command and 
                        executes test file.
4) Insert a string    //after entering the string, reversed string will be shown 
                        in the output.
