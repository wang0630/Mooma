# $(info obj is $(OBJ)) can be used for debug
TARGET=build/a.exe
ODIR=obj
IDIR=header
DDIR=dep
SDIR=src
# Src files
SRC = $(wildcard $(SDIR)/*.cpp)

# Object files
OBJ = $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SRC))

# Automatic generated dependencies
DEP = $(patsubst $(SDIR)/%.cpp, $(DDIR)/%.d, $(SRC))

CXXVER=-std=c++11 -std=gnu++11
# -Iheader specifies that all #include should look for target header in 'header' folder
# -MF writes the auto generate dependencies into 'dep' folder
# -MMD only re-compile when user-defined headers have been modified(do not watch system header like iostream or string.h)
# Hence make the makefile faster since it watches fewer files now
CXXFLAGS+=$(CXXVER) -MMD -MP -MF $(DDIR)/$*.d -I$(IDIR)
LD =-lwsock32

$(TARGET):	$(OBJ)
	$(CXX) $^  -o $@ $(LD)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include all dependencies in DEP folder
-include $(DEP)

# RM is default to 'rm -r'
clean:
	$(RM) $(ODIR)/* $(DDIR)/* build/* $(DDIR)/*
