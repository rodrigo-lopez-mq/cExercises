#MAKEFILE
#https://hiltmon.com/blog/2015/09/28/the-simple-c-plus-plus-makefile-executable-edition/

UNAME_S := $(shell uname -s)

# CC
CC := g++

# Folders
SRCDIR := src
INCDIR := inc
BUILDDIR := build
TARGETDIR := $(CURDIR)

# Targets
EXECUTABLE := binary_heap_ex
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final Paths
INSTALLBINDIR := $(CURDIR)

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
# Note: Intentionally excludes the root of the include folder so the lists are clean
INCDIRS := $(shell find $(INCDIR) -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))

# Shared Compiler Flags
CFLAGS := -c
INC := -I include $(INCLIST) 
LIB := -L #/usr/local/lib -lsantacruzengine -lsantacruzlib -larcadia -lcorinth -lyaml-cpp -lzmq -lhiredis -lbondoas

CFLAGS += -std=gnu++11 -O2 # -fPIC



$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo "Linking $(TARGET)"; $(CC) $^ -o $(TARGET) #$(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	#@echo "$(BUILDDIR)"
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -r $(BUILDDIR) $(TARGET)

install:
	@echo "Installing $(EXECUTABLE)..."; cp $(TARGET) $(INSTALLBINDIR)
	
distclean:
	@echo "Removing $(EXECUTABLE)"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

.PHONY: clean