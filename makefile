CFLAGS= -fPIC -g
LDFLAGS= -shared

SOURCES = $(shell echo *.c)
HEADERS = $(shell echo *.h)
OBJECTS=$(SOURCES:.c=.o)


TEST_SOURCES := $(shell find Tests -name '*.c') 
TEST := testlib

TARGET=libgenlist.so

all: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	sudo cp libgenlist.so /usr/lib/

test:	$(TARGET)
	echo $(TEST_SOURCES)
	gcc  -Wall -o $(TEST) $(TEST_SOURCES)  -lgenlist	
	./$(TEST)
