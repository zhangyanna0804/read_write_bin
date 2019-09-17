SRC = readbin.cpp
TARGET = readbin

$(TARGET):$(SRC)
	g++ -std=c++11 $(SRC) `pkg-config --cflags --libs opencv` -lpthread -o $(TARGET)
	@echo "build ok!" 

.PHONY: clean
clean:
	@rm -rf $(TARGET) pic.txt
	@echo "remove output file"
