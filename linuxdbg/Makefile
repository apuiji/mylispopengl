opengl.so: main.o
	clang++ -o $@ $^ -L ../../mylisp/linuxdbg -lGL -lglfw -lmylisp -shared -g

%.o: ../%.cc
	clang++ -o $@ $< -I ../.. -std=c++2b -fPIC -c -g

clean:
	touch opengl.so
	rm opengl.so *.o

.PHONY: clean
