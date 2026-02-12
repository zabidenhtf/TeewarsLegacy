# Copyright (c) 2026 mykyta polishyk, see license.txt for more info #

# Cpp compiler
CXX = g++
# Targets
TARGETS = src/main.cpp \
	  src/client.cpp \
	  src/server.cpp
# Output
EXEC = teewarslegacy
# Linker flags
LDFLAGS = -lSDL

all:
	$(CXX) $(TARGETS) $(LDFLAGS) -o $(EXEC)
