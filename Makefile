CC = g++
CFLAGS = -g -c
LIBS = -lm
INCLUDE = -I/usr/include

all: clean my 

my:	random.o e_list.o event.o random.o main.o
	$(CC) -o $@ $? $(LIBS) 	

my.o:	main.cc event.h e_list.h mydef.h
	$(CC) $(CFLAGS) -o $@ my.cpp $(INCLUDE) 
 
random.o:	random.cc random.h
	$(CC) $(CFLAGS) -o $@ random.cc $(INCLUDE)
                                    
e_list.o:	e_list.cc e_list.h event.h
	$(CC) $(CFLAGS) -o $@ e_list.cc $(INCLUDE)

event.o:	event.cc event.h mydef.h
	$(CC) $(CFLAGS) -o $@ event.cc $(INCLUDE)
clean:
	rm -f *.o
	rm -f my

