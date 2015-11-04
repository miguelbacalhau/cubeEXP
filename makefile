# ----------------------------------------------------------------------------
# Makefile
#
# release: 0.1 (28-Ago-2010) create makefile
#
# purpose: searches recursively in current directory for c/cpp files (using find),
#          compile each source file and link them in a executable.
#  TODO give creditz
# ----------------------------------------------------------------------------

APP     = main
CC      = g++
RM      = rm
SRCDIR  = src
SRCEXT  = cpp
OBJDIR  = obj

SRCS    := $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
SRCDIRS := $(shell find . -name '*.$(SRCEXT)' -exec dirname {} \; | uniq)
OBJS    := $(patsubst %.$(SRCEXT),$(OBJDIR)/%.o,$(SRCS))

DEBUG   =
INCLUDE = -I Include -I src
CFLAGS  = -Wall -ansi -c $(DEBUG) $(INCLUDE)
OFLAGS  = -lglut -lm -lGL -lGLU

all:    $(APP)

$(APP): buildrepo $(OBJS)
	@echo "$(CC) $(OFLAGS) $(OBJS) -o $@"
	@$(CC) $(OBJS) $(OFLAGS) -o $@

$(OBJDIR)/%.o: %.$(SRCEXT)
	@echo "$(CC) $(CFLAGS) $< -o $@";
	@$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(APP)

buildrepo:
	$(call make-repo)

define make-repo
	for dir in $(SRCDIRS); \
		do \
        	mkdir -p $(OBJDIR)/$$dir; \
        done
endef
