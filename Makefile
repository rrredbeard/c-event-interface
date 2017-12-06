CC= gcc    
CC_FLAG= -Wall -O0 -g 

makePublicInterface: clean
	$(CC) -E    src/lib/libevents.h > build/libevents.h

.PHONY: clean
clean:  
	rm -rf ./build/*
