all: libacme.so test

libacme.so: acme.c
	gcc -fPIC -shared -I /usr/include/python2.7 -o libacme.so acme.c -lpython2.7

test: test.c libacme.so
	gcc -o test test.c -L. -lacme

run: test
	LD_LIBRARY_PATH=.:$LD_LIBRARYPATH ./test

cleanrun: clean run

clean:
	rm -rf libacme.so test *.o *.pyc
