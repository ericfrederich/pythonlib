all: libacme.so test

libacme.so: acme.c
	gcc -fPIC -shared -I /usr/include/python2.7 -o libacme.so acme.c

test: test.c libacme.so
	gcc -o test test.c -L. -lacme -lpython2.7

run: test
	PYTHONPATH="." LD_LIBRARY_PATH=.:$LD_LIBRARYPATH ./test

clean:
	rm -rf libacme.so test *.o *.pyc