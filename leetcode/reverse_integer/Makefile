CC := g++
SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)
TARGET := reverseinteger

CFLAGS := -g -std=c++0x

GEN_DEP = $(CC) $(CFLAGS) $(INCLUDE) -MM
DEP_FILE = .depends

.PHONY: all clean

all: $(DEP_FILE) $(OBJ) $(TARGET)

$(DEP_FILE):$(SRC)
	$(GEN_DEP) $? >>$(DEP_FILE)
	sed "s#\($$*\).o: *#\1.o: $(DEP_FILE) #g" -i $(DEP_FILE)

$(OBJ):%.o:%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(DEBUG) -c -o $@ $<

$(TARGET):$(OBJ)
	$(CC) $^ -o $@
	
clean:
	rm -rf $(OBJ) $(DEP_FILE) $(TARGET)

ifneq ($(wildcard $(DEP_FILE)),)
include $(DEP_FILE)
endif
