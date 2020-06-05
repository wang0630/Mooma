TARGET=a.exe
ODIR=obj
IDIR=include
DDIR=dep
SDIR=src
# SRC = $(wildcard $(SDIR)/*.cpp)
OBJ = $(SRC: $(ODIR)/%.o=$(SDIR)/%.cpp)
DEP = $(SRC: $(DDIR)/%.d=$(SDIR)/%.cpp)

# CXXVER=-std=c++11 -std=gnu++11
# CXXFLAGS+=$(CXXVER) -MM -MF $(DDIR)/%.d -MP -I$(IDIR)
# LDLIBS+=-lwsock32

# $(TARGET):	$(OBJ)
# 	$(CXX) $^ -o $@ $(LDLIBS)

# $(ODIR)/%.o:	$(SDIR)/%.cpp
# 	$(CXX) $(CXXLAGS) -c $< -o $@

clean:
	$(RM) $(ODIR)/*

-include $(DEP)

