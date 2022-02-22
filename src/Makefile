# CFLAGS=-Wall -Werror -Wextra

# cipher: logger.o cipher.o
# 	gcc cipher.o logger.o -o ../build/cipher

# logger.o: logger.c logger.h
# 	gcc $(CFLAGS) logger.c -o logger.o

# cipher.o:
# 	gcc $(CFLAGS) cipher.c -o logger.o



BUILDDIR = ../build/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: cipher loggin_cipher

cipher: cipher.o logger.o
	$(CC) $(CFLAGS) cipher.o logger.o -o $(BUILDDIR)cipher

loggin_cipher:  cipher.o logger.o
	$(CC) $(CFLAGS) cipher.o logger.o -o $(BUILDDIR)loggin_cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c -D CIPHER

logger.o: logger.c logger.h
	gcc $(CFLAGS) -c logger.c -o logger.o

rebuild:
	clean cipher

clean: 
	rm -rf *.o
	rm -f $(BUILDDIR)cipher
	rm -f $(BUILDDIR)loggin_cipher