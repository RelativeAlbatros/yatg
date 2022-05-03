PREFIX := /usr/local

yatg: src/main.cpp 
	g++ -std=c++11 -I include/ -o bin/$@ $?

install: yatg 
	mv bin/yatg ${PREFIX}/bin/ 

clean: 
	rm -f bin/yatg 

run: yatg
	@./bin/yatg
