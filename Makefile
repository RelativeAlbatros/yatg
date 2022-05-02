PREFIX := /usr/local

yatg: src/main.cpp 
	g++ -o bin/$@ $? -I include/

install: yatg 
	mv bin/yatg ${PREFIX}/bin/ 

clean: 
	rm -f bin/yatg 

run: yatg
	@./bin/yatg