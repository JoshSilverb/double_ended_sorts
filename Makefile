BIN = dss


main:	$(BIN)
	./$(BIN)

$(BIN):	main.cpp double_selection_sort.h
	g++ -g main.cpp double_selection_sort.h -o $(BIN)

%Tests:	testSrc/$@.cpp
	g++ -g -I . testSrc/$@.cpp -o tests/$@

allTests:
	./runTests.sh

.PHONY: main