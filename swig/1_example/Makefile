OS := $(shell uname)

CC=gcc
CXX=g++

ifeq ($(OS), Darwin)
	CFLAGS=-g -c
	LD=gcc
	LDFLAGS=-bundle -flat_namespace -undefined suppress
else
	CFLAGS=-g -c -fPIC
	LD=ld
	LDFLAGS=-shared
endif

all: 1_example

1_example: example.c
	swig -python example.i
	$(CC) $(CFLAGS) example.c example_wrap.c -I/usr/include/python2.6 -I/usr/lib/python2.6
	$(LD) $(LDFLAGS) -o _example.so example.o example_wrap.o

clean:
	rm -f *.o
	rm -f *.pyc
	rm -f *.so
	rm -f example_wrap.c
	rm -f example.py


# swig -python example.i
# gcc -c -fPIC example.c example_wrap.c -I/usr/include/python2.6 -I/usr/lib/python2.6
# ld -shared example.o example_wrap.o -o _example.so

# gcc -bundle -flat_namespace -undefined suppress -o example.so example.o example_wrap.o


# >>> import example
# >>> example.fact(5)
# 120
# >>> example.my_mod(7,3)
# 1
# >>> example.get_time()
# 'Sun Feb 11 23:01:07 1996'
# >>>
