BIN = dss

s_test:	$(BIN)
	./$(BIN)

$(BIN):	main.cpp double_selection_sort.h
	g++ -g main.cpp double_selection_sort.h -o $(BIN)

.PHONY: s_test