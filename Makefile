# Copyright (c) 2026 mykyta polishyk, see license.txt for more info #

# Cpp compiler
CXX = g++
# Targets
TARGETS = src/main.cpp \
	  src/client.cpp \
	  src/server.cpp
# Output
EXEC = teewarslegacy

all:
	$(CXX) $(TARGETS) -o $(EXEC)
