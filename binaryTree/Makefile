Binary:main.o BinaryTree.o
	g++ -std=c++11 main.o BinaryTree.o -o Binary
	@echo "### Build success! ###"
main.o:main.cpp ./include/BinaryTree.h
	g++ -std=c++11 -c main.cpp  -o main.o
BinaryTree.o:./include/BinaryTree.h ./src/BinaryTree.cpp
	g++ -std=c++11 -c  ./src/BinaryTree.cpp -o BinaryTree.o
clean:
	-rm *.o Binary
	@echo "### clean success ###" 
