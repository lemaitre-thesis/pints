# -------------------- #
# -- poiAV Makefile -- #
# -------------------- #

# -- Lile list ----------
SRCS = main.c

# -- Paths ----------
SRC_PATH = src-test
OBJ_PATH = obj
EXE_PATH = exe
INC_PATH = include-test
DEP_PATH = deps

$(shell mkdir -p $(OBJ_PATH) >/dev/null)
$(shell mkdir -p $(EXE_PATH) >/dev/null)
$(shell mkdir -p $(DEP_PATH) >/dev/null)

LIB_LIB_PATH = -lrt -static-libgcc -lm
LIB_INC_PATH = 

# -- Macros ----------
CC = gcc
#CC = icc
AR = ar -rc
POSTCOMPILE = mv -f $(DEP_PATH)/$*.Td $(DEP_PATH)/$*.d


# -- Make arguments ----------
ifndef DEBUG
	DEBUG = 0
endif
ifneq ($(if $(DEBUG),$(strip $(DEBUG)),0),0)
	DEBUG_SUFFIX = _dbg
else
	DEBUG_SUFFIX = 
endif

SUFFIX = $(DEBUG_SUFFIX)

# -- Flags ----------
C_DEBUG_FLAGS = -std=c99 -O0 -g
C_OPTIMISATION_FLAGS = -std=c99 -O1 -fstrict-aliasing
C_ARCH_FLAGS = -march=native
C_INC_FLAGS = -I$(INC_PATH) -Iinclude
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.Td

# -- Options ----------

ifneq ($(if $(DEBUG),$(strip $(DEBUG)),0),0)
	CFLAGS  = $(C_DEBUG_FLAGS)        $(C_ARCH_FLAGS) $(C_INC_FLAGS) $(LIB_INC_PATH)
	LDFLAGS = $(C_DEBUG_FLAGS)        $(C_ARCH_FLAGS) $(C_INC_FLAGS) $(LIB_LIB_PATH)
else
	CFLAGS  = $(C_OPTIMISATION_FLAGS) $(C_ARCH_FLAGS) $(C_INC_FLAGS) $(LIB_INC_PATH)
	LDFLAGS = $(C_OPTIMISATION_FLAGS) $(C_ARCH_FLAGS) $(C_INC_FLAGS) $(LIB_LIB_PATH)
endif

# -- Final product ----------
PRODUCT   = simd-helper$(SUFFIX)

# -- src and obj List ----------
SRC = $(addprefix ${SRC_PATH}/, $(SRCS))
OBJ = $(addprefix ${OBJ_PATH}/, $(addsuffix $(SUFFIX).o, $(basename $(SRCS))))

# -- Base rules ----------
$(OBJ_PATH)/%$(SUFFIX).o : $(SRC_PATH)/%.c
$(OBJ_PATH)/%$(SUFFIX).o : $(SRC_PATH)/%.c $(DEP_PATH)/%.d
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	$(POSTCOMPILE)

   
#-----Main rule ----------
$(EXE_PATH)/$(PRODUCT): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(OPTFLAGS) $(CFG) $(INC)
#-----Generator rules-----
include/%.h : generator/templates/include/%.h.jinja generator/template.py generator/templates-bases/definitions.jinja
	generator/template.py

generate:
	generator/template.py



#-----Dependencies--------
$(DEP_PATH)/%.d: ;
.PRECIOUS: $(DEP_PATH)/%.d

-include $(patsubst %,$(DEP_PATH)/%.d,$(basename $(SRCS)))

# -- Other stuff ----------

clean:
	rm -f $(OBJ_PATH)/*
	rm -f $(EXE_PATH)/*
	rm -f $(DEP_PATH)/*
	#rm -f $(shell find generator/templates/ -type f -name "*.jinja" | sed 's:generator/templates/\(.*\).jinja:\1:')

run: $(EXE_PATH)/$(PRODUCT)
	$(EXE_PATH)/$(PRODUCT)

asm: $(EXE_PATH)/$(PRODUCT)
	objdump -d $(EXE_PATH)/$(PRODUCT) | vim -R -c 'set ft=asm' -

doc: pints-doc.h
	doxygen


.PHONY: generate clean run asm doc
