TSRC_DIR := testSrc
TEST_DIR := tests
TSRC_FILES := $(wildcard $(TSRC_DIR)/*.cpp)
TEST_FILES := $(patsubst $(TSRC_DIR)/%.cpp,$(TEST_DIR)/%.exe,$(TSRC_FILES))


shortTests:	$(TEST_FILES)
	for f in $^ ; \
	do \
		echo "\n $${f} \n" ; \
		./$${f} ; \
	done

allTests: $(TEST_FILES)
	for f in $^ ; \
	do \
		echo "\n $${f} \n" ; \
		./$${f} y ; \
	done

$(TEST_DIR)/%.exe: $(TSRC_DIR)/%.cpp
	mkdir -p $(TEST_DIR) ; \
	echo "Compiling $@" ; \
	g++ -g -I . $^ -o $@ ;
		

clean:
	rm -f tests/* \
	rm -f *.exe


.PHONY: main test clean