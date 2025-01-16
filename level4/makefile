
CXX = g++
CXXFLAGS = -g -O0 -fprofile-arcs -ftest-coverage -pg -Wall
LDFLAGS = --coverage
TARGET = graph_program

$(TARGET): Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) Graph.cpp $(LDFLAGS)

create_dirs:
	mkdir -p reports/coverage
	mkdir -p reports/profiling
	mkdir -p reports/memcheck
	mkdir -p reports/callgraph

coverage: create_dirs $(TARGET)
	./$(TARGET) -v 5 -e 10 -s 42
	cp graph_program-Graph.gcno Graph.gcno || true
	cp graph_program-Graph.gcda Graph.gcda || true
	gcov Graph.cpp > reports/coverage/Graph.cpp.gcov
	mv *.gcov reports/coverage/ || true
	@echo "Coverage report generated: reports/coverage/Graph.cpp.gcov"

profiling: create_dirs $(TARGET)
	./$(TARGET) -v 5 -e 10 -s 42
	gprof $(TARGET) > reports/profiling/gprof_report.txt
	@echo "Profiling report generated: reports/profiling/gprof_report.txt"


memcheck: create_dirs $(TARGET)
	valgrind --tool=memcheck --leak-check=full \
	--show-leak-kinds=all --track-origins=yes \
	--log-file=reports/memcheck/memcheck_report.txt \
	./$(TARGET) -v 5 -e 10 -s 42
	@echo "Memcheck report generated: reports/memcheck/memcheck_report.txt"


callgraph: create_dirs $(TARGET)
	valgrind --tool=callgrind \
	--callgrind-out-file=reports/callgraph/callgrind.out \
	./$(TARGET) -v 5 -e 10 -s 42
	@echo "Callgraph report generated: reports/callgraph/callgrind.out"


all_reports:
	@echo "Generating coverage report..."
	@make coverage
	@echo "Generating profiling report..."
	@make profiling
	@echo "Generating memcheck report..."
	@make memcheck
	@echo "Generating callgraph report..."
	@make callgraph
	@echo "All reports generated in reports/ directory"


clean:
	rm -f $(TARGET) *.o *.gcno *.gcda *.gcov gmon.out callgrind.out.*
	rm -rf reports

.PHONY: all coverage profiling memcheck callgraph clean

#how to run:
#cd level4
#make coverage - to generate coverage report
#make profiling - to generate profiling report
#make memcheck - to generate memcheck report
#make callgraph - to generate callgraph report
#make all_reports - to generate all reports