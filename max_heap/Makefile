SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)
TARGET := maxheap

CFLAGS := -g

GEN_DEP = $(CC) $(CFLAGS) $(INCLUDE) -MM
DEP_FILE = .depends

.PHONY: all clean

all: $(DEP_FILE) $(OBJ) $(TARGET)

$(DEP_FILE):$(SRC)
	$(GEN_DEP) $? >>$(DEP_FILE)
	sed "s#\($$*\).o: *#\1.o: $(DEP_FILE) #g" -i $(DEP_FILE)

$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(DEBUG) -c -o $@ $<

$(TARGET):$(OBJ)
	$(CC) $^ -o $@
	
clean:
	rm -rf $(OBJ) $(DEP_FILE) $(TARGET)

ifneq ($(wildcard $(DEP_FILE)),)
include $(DEP_FILE)
endif
