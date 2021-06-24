libblast: ./src/blast.c ./include/blast.h
	cc -shared -o ./build/lib/libblast.so ./lib/blast.c -I./include

blast: ./src/blast.c ./include/blast.h libblast
	cc -o ./build/bin/blast ./src/blast.c -I./include -l:./build/lib/libblast.so

test: ./build/bin/blast
	./build/bin/blast < ./tests/test.pk | cmp - ./tests/test.txt

clean:
	rm -f ./build/blast ./build/blast.o
