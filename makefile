CXX:=g++
CXX_FLAGS:= -std=c++17
DEBUG:= -g3
default:
	make test
test:
	${CXX} ${CXX_FLAGS} ${DEBUG} test1.cpp -o test.out
