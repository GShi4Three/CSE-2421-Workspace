BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
 
THIS IS THE README FILE FOR LAB 1.
 
Name: Gavin Shi
                                                      
1. 	UNIX is a proprietary system (i.e., you must purchase a license) while Linux is an Open-Source system.  An Open-Source system, however, is not always “free”. Why? 

While Open Source systems are sometimes free, there can be variations in pricing based on support, services, or additional features.
 
2. 	Name another difference between Unix/Linux from your required reading.

Comparing the security between Linux/Unix, Linux has had about 60-100 viruses to date, but none of them are spreading nowadays, while UNIX has roughly 85-120 viruses.
 
3. 	What made UNIX different from all other commercially available software systems when it was initially developed?

Unix operating systems were developed mainly for mainframes, servers, and workstations. The Unix environment and the client-server program model were essential elements in the development of the Internet. Also, ​​UNIX could run on any computer, unlike other commercial software, since it was written in C instead of assembly.
 
4. 	What operating system covers the widest range of hardware in the world?

Linux
 
5. 	Why was the C programming language initially created?
 
The C programming language was initially developed for creating the UNIX system. They created this programming language by building it around a kernel, which is the only piece of code that needs to be adapted for every specific system, and saves programmers a lot of time by recycling code. Using this new technique, it was much easier to develop an operating system that could run on many different types of hardware.

6. 	How is white space (tabs/newlines/returns, spaces, etc.) handled within a C program file?

White space is mostly ignored by the compiler.
 
7. 	What did you learn when you “mistyped” (e.g. “fat fingered”) the compile command?

When entering the command 
[shi.1742@coe-dnc268474s lab1]$ gcc -std=c99 -pedantic -g -o lab1.c lab1.c
I get the error:

gcc: fatal error: input file ‘lab1.c’ is the same as output file
compilation terminated.
 
8. 	When a line of code is printed out after the next command in gdb, that line of code has just finished executing.  True or False?

False, gdb prints out the line of code that will be executed next, so it has not executed yet.
 
9. 	What is the value of maxEntries variable at GDB item #3?

The value of maxEntries is 6.
 
10.   What is the value of getchar_return_value at GDB item #4?  Is this what you expected to see?

The value of getchar_return_value is 49. This is expected since 49 on the ASCII table represents 1, which corresponds with the input we entered.
 
11.   What is the value of keyboard_value[0] at GDB item #5?  Did gdb give you additional information this time?  What did you find out when you referred to the Extended ASCII table? 

The value of keyboard_value[0] is 49; gdb also included ‘1’ afterward. 49 on the Extended ASCII table represents 1, which corresponds with the input we entered.

12.   What are the values in the first 6 keyboard_value elements?
 
keyboard_value[0]= 49 ‘1’
keyboard_value[1]= 50 ‘2’
keyboard_value[2]= 51 ‘3’
keyboard_value[3]= 52 ‘4’
keyboard_value[4]= 53 ‘5’
keyboard_value[5]= 54 ‘6’
 
13.   How is the output different when the print keyboard_value instruction is used?

print keyboard_value returns the entire string of numbers “123456” along with additional information: '\000' <repeats 11 times>, "\b@\000\000\000\000", <incomplete sequence \360>.
 
14.   How does the output of the program change at GDB item #6 from the output seen prior?

The output after running the command  set keyboard_value[0] = 64 at the breakpoint results in the output returning:

	@
	2
	3
	4
	5
	6

This is because we directly modified the first value in keyboard_value with the ASCII value corresponding to the ‘@’ symbol.
 





15.   How does the output of the program change at GDB item #7 from the output seen prior?

The output after running the command  set keyboard_value[3] = ‘%’  at the breakpoint results in the output returning:

	1
	2
	3
	%
	5
	6

This is because we directly modified the 4th value in keyboard_value by changing it to the ‘%’ symbol.
 
16.   How does the output of the program change at GDB item #9 from the output seen prior? What are the values in the first 11 keyboard_value elements?
 
keyboard_value[0]= 49 ‘1’
keyboard_value[1]= 50 ‘2’
keyboard_value[2]= 51 ‘3’
keyboard_value[3]= 52 ‘4’
keyboard_value[4]= 53 ‘5’
keyboard_value[5]= 10 ‘\n’
keyboard_value[6]= 65 ‘A’
keyboard_value[7]= 66 ‘B’
keyboard_value[8]= 67 ‘C’
keyboard_value[9]= 68 ‘D’
keyboard_value[10]= 0 ‘\000’
 
Are these values what you expected to see?  If so, why?  If not, what did you observe/learn?

The output is now 10 characters long and includes the characters from lab1.input1. These are the values I expected because it includes all the characters in the lab1.input1 file, including the new line between 12345 and ABCDE, and also excludes the 11th character  ‘E’.


 
17.   How does the output of the program change at GDB item #10 from the output seen prior? What are the values in the first 11 keyboard_value elements?
 
keyboard_value[0]= 98 ‘b’
keyboard_value[1]= 97 ‘a’
keyboard_value[2]= 110 ‘n’
keyboard_value[3]= 97 ‘a’
keyboard_value[4]= 110 ‘n’
keyboard_value[5]= 97 ‘a’
keyboard_value[6]= 10 ‘\n’
keyboard_value[7]= 0 ‘\000’
keyboard_value[8]= 0 ‘\000’
keyboard_value[9]= 0 ‘\000’
keyboard_value[10]= 0 ‘\000’
 
Are these values what you expected to see?  If so, why?  If not, what did you observe/learn?

The output is now 7 characters long, even though we initially specified that 10 characters would be given. These are the values I expected because it includes all the characters in the lab1.input2 file, however, I didn’t expect a new line character at the end because I didn’t add a new line after banana.
 
18.   What is the value of maxEntries in GDB item #10?  Why is this the correct value?

The initial value for maxEntries is 10 when first inputted, but after ‘banana’ is inputted into the program, the value changes to 7 because it counts ‘banana’ as well as the new line from pressing the enter/return key.
 
19.   Run lab1 through gdb using lab1.input2 a second time but set a breakpoint at Line 29 and check the value in getchar_return_value each time through the loop.  What value does it have the last time through the loop? The value in the extended ASCII table says 255 represents “Latin small letter y with diaeresis” is that what we got?  Might -1 mean something else in this case?  Might the value not be a char?  Use the linux command man getchar to help you answer this question.

The values are 98, 97, 110, 97, 110, 97, 10, and -1. The value it has at the last time through the loop is -1. We did not get 255, instead getchar returns -1 because we’ve reached the end of the file (EOF). The int ‘-1’ represents EOF.
 
20.   Have you ever used the gdb debugger before?  If so, for what class(es)?
 
 	No, I haven’t used the gdb debugger before.
 