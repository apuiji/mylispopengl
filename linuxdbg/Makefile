opengl.so: ../main.cc
	clang++ -o $@ $^ -I ../.. -std=c++2b -fPIC -shared -g

clean:
	touch opengl.so
	rm opengl.so

.PHONY: clean
