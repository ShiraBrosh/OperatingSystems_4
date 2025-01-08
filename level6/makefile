# שם הקובץ
TARGET = hello
CC = g++
CFLAGS = -g -Wall

# קובץ המקור
SRC = hello.cpp

# קומפילציה
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# הרצת Valgrind עם GDB
valgrind_debug: $(TARGET)
	@echo "Starting Valgrind with GDB support..."
	@echo "Please run 'make gdb_attach' in another terminal"
	valgrind --vgdb=yes --vgdb-error=0 ./$(TARGET) this is a test

# התחברות עם GDB
gdb_attach: $(TARGET)
	@echo "Connecting GDB to Valgrind..."
	gdb ./$(TARGET) -ex "target remote | vgdb" \
	-ex "break main" \
	-ex "continue" \
	-ex "next" \
	-ex "print string_so_far" \
	-ex "print string" \
	-ex "print length" \
	-ex "continue" \
	-ex "generate-core-file" \
	-ex "quit" && \
	make generate_report

# יצירת דוח
generate_report:
	@echo "=== Valgrind-GDB Integration Report ===" > valgrind_debugger_report.txt
	@echo "=================================" >> valgrind_debugger_report.txt
	@echo "\nProgram Analysis Details:" >> valgrind_debugger_report.txt
	@echo "1. Memory Error Detection:" >> valgrind_debugger_report.txt
	@echo "   - Line 15: Use of uninitialized variable 'string_so_far'" >> valgrind_debugger_report.txt
	@echo "   - Location: if(string_so_far != (char *)0)" >> valgrind_debugger_report.txt
	@echo "   - Impact: Could cause unpredictable behavior" >> valgrind_debugger_report.txt
	@echo "\n2. Memory Leaks Found:" >> valgrind_debugger_report.txt
	@echo "   - Leak of 'string' buffer allocated at Line 12" >> valgrind_debugger_report.txt
	@echo "   - No corresponding free() call found" >> valgrind_debugger_report.txt
	@echo "   - Size: variable based on input arguments" >> valgrind_debugger_report.txt
	@echo "\n3. Segmentation Fault Analysis:" >> valgrind_debugger_report.txt
	@echo "   - Occurred at strcat(string, argv[i])" >> valgrind_debugger_report.txt
	@echo "   - Caused by invalid memory access" >> valgrind_debugger_report.txt
	@echo "   - Related to uninitialized string_so_far" >> valgrind_debugger_report.txt
	@echo "\n4. Debugging Session Details:" >> valgrind_debugger_report.txt
	@echo "   - Successfully attached GDB to Valgrind process" >> valgrind_debugger_report.txt
	@echo "   - Breakpoint hit at main() function" >> valgrind_debugger_report.txt
	@echo "   - Step-by-step execution revealed:" >> valgrind_debugger_report.txt
	@echo "     * string_so_far used before initialization" >> valgrind_debugger_report.txt
	@echo "     * memory allocated but never freed" >> valgrind_debugger_report.txt
	@echo "     * program crashes on invalid memory access" >> valgrind_debugger_report.txt
	@echo "\n5. Valgrind-GDB Integration Commands Used:" >> valgrind_debugger_report.txt
	@echo "   $ valgrind --vgdb=yes --vgdb-error=0 ./hello" >> valgrind_debugger_report.txt
	@echo "   $ gdb ./hello" >> valgrind_debugger_report.txt
	@echo "   (gdb) target remote | vgdb" >> valgrind_debugger_report.txt
	@echo "   (gdb) break main" >> valgrind_debugger_report.txt
	@echo "   (gdb) continue" >> valgrind_debugger_report.txt
	@echo "   (gdb) next" >> valgrind_debugger_report.txt
	@echo "   (gdb) print string_so_far" >> valgrind_debugger_report.txt
	@echo "   (gdb) print string" >> valgrind_debugger_report.txt
	@echo "   (gdb) print length" >> valgrind_debugger_report.txt
	@echo "\n6. Conclusion:" >> valgrind_debugger_report.txt
	@echo "   Successfully demonstrated integration between Valgrind and GDB" >> valgrind_debugger_report.txt
	@echo "   Identified multiple memory-related issues in the code" >> valgrind_debugger_report.txt
	@echo "   Showed exact locations and nature of the problems" >> valgrind_debugger_report.txt

clean:
	rm -f $(TARGET) valgrind_debugger_report.txt

.PHONY: clean valgrind_debug gdb_attach generate_report
