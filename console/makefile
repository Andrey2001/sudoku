all: sudoku
sudoku: sudoku.cpp
	g++ sudoku.cpp -o sudoku -lm
sudoku.cpp: $(name)
	rm -rf *.o sudoku*
	cat $(name) > sudoku.cpp
	ls
clean:
	rm -rf *.o sudoku*
	ls
c: clean