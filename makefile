CXXFLAGS=-g -std=c++14 -Wall -pedantic
CC=$(CXX)

STUDENT_DIR=my_code
TEST_DIR=tests



test_tvector: $(TEST_DIR)/test_tvector

$(TEST_DIR)/test_tvector: $(TEST_DIR)/test_tvector.cpp


tests: test_tvector
	
	tests/test_tvector

prod: tests
	- git commit -a -m "new assignment done"
	git push origin master
