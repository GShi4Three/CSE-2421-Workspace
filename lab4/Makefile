# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
# WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
# FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
# OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
# OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.

# Author: Gavin Shi

# target all means all targets currently defined in this file
all: lab4.zip lab4

# this target is the .zip file that must be submitted to Carmen
lab4.zip: Makefile lab4Readme lab4main.c printLine.c printLineLastName.c printHeader.c ID_isduplicate.c read_data.c insert_node.c get_NodeforID.c printStudent.c printRecords.c lab4.h
	zip lab4.zip Makefile lab4Readme *.c lab4.h

# this target is the lab4 executable
lab4: lab4main.o printLine.o printLineLastName.o printHeader.o ID_isduplicate.o read_data.o insert_node.o get_NodeforID.o printStudent.o printRecords.o
	gcc lab4main.o printLine.o printLineLastName.o printHeader.o ID_isduplicate.o read_data.o insert_node.o get_NodeforID.o printStudent.o printRecords.o -o lab4

# this target is the dependency for compiling .c files to .o files
%.o: %.c lab4.h
	gcc -ansi -pedantic -g -c $< -o $@

# target to clean up the directory
clean:
	rm -f *.o lab4 lab4.zip