# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
# WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
# FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
# OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
# OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

# Author: Gavin Shi

# target all means all targets currently defined in this file
all: lab3.zip lab3

# this target is the .zip file that must be submitted to Carmen
lab3.zip: Makefile lab3Readme lab3.c lab3.h
	zip lab3.zip Makefile lab3Readme lab3.c lab3.h

# this target is the lab3 executable
lab3: lab3.o
	gcc lab3.o -o lab3

# this target is the dependency for lab3
lab3.o: lab3.c lab3.h
	gcc -std=c99 -pedantic -g -c lab3.c -o lab3.o

# target to clean up the directory
clean:
	rm -f lab3.o lab3 lab3.zip