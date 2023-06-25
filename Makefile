PREFIX := /usr/local

yatg: src/main.cpp src/include/Board.cpp src/include/Cell.cpp
	g++ -std=c++11 -Iinclude/ -o $@ $?

install: yatg 
	mv bin/yatg ${PREFIX}/bin/ 

clean: 
	rm -f bin/yatg 

run: yatg
	@./bin/yatg
