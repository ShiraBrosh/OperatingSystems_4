# Compiler
CC = g++
CFLAGS = -g -Wall -pthread

# Target
TARGET = race

# Rules
$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

# Run Helgrind analysis
helgrind: $(TARGET)
	valgrind --tool=helgrind ./$(TARGET) > helgrind_output.txt 2>&1
	@echo "\n=== Helgrind Race Condition Analysis ===" > race_condition_report.txt
	@echo "Date: `date`" >> race_condition_report.txt
	@echo "\n1. Race Condition Details:" >> race_condition_report.txt
	@echo "   - Global variable 'accum' is accessed by multiple threads" >> race_condition_report.txt
	@echo "   - No synchronization mechanism (mutex/lock) protecting accum" >> race_condition_report.txt
	@echo "   - Operation 'accum += x * x' is not atomic" >> race_condition_report.txt
	@echo "\n2. Helgrind Analysis:" >> race_condition_report.txt
	@echo "   Command used: valgrind --tool=helgrind ./race" >> race_condition_report.txt
	@grep -A 5 "Possible data race" helgrind_output.txt >> race_condition_report.txt
	@echo "\n3. Impact:" >> race_condition_report.txt
	@echo "   - Multiple threads updating shared variable without synchronization" >> race_condition_report.txt
	@echo "   - Race condition can lead to incorrect final value of accum" >> race_condition_report.txt
	@echo "   - Results will be non-deterministic between runs" >> race_condition_report.txt
	@echo "\n4. Location:" >> race_condition_report.txt
	@echo "   - Function: square()" >> race_condition_report.txt
	@echo "   - Variable: accum (global)" >> race_condition_report.txt
	@echo "   - Operation: accum += x * x" >> race_condition_report.txt
	@echo "\nReport generated successfully."

clean:
	rm -f $(TARGET) race_condition_report.txt helgrind_output.txt

.PHONY: clean helgrind