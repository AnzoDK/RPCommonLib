CXX:=g++
CXX_FLAGS:= -std=c++20
DEBUG:= -g3
X_LINK:= -lX11
WAYLAND_LINK:=
default:
	make test
	make ex_test
test:
	${CXX} ${CXX_FLAGS} ${DEBUG} test1.cpp -o test.out
ex_test:
	${CXX} ${CXX_FLAGS} ${DEBUG} test_experimental.cpp -o test_ex.out
