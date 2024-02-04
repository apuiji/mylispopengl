opengl.so: main.o
	clang++ -o $@ $^ -lGL -shared -g

%.o: ../%.cc
	clang++ -o $@ $< -I ../.. -std=c++2b -fPIC -c -g

clean:
	echo > opengl.so
	del opengl.so

.PHONY: clean
