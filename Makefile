# -------------------- #
# -- poiAV Makefile -- #
# -------------------- #

# -- Lile list ----------
FILE = main.c

# -- Paths ----------
SRC_PATH = src-test
OBJ_PATH = obj
EXE_PATH = exe
INC_PATH = include-test

LIB_LIB_PATH = -lrt -static-libgcc -lm
LIB_INC_PATH = 

# -- Macros ----------
CC = gcc
#CC = icc
AR = ar -rc

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
SRC = $(addprefix ${SRC_PATH}/, $(FILE))
OBJ = $(addprefix ${OBJ_PATH}/, $(addsuffix $(SUFFIX).o, $(basename $(FILE))))

# -- Base rules ----------
$(OBJ_PATH)/%$(SUFFIX).o : $(SRC_PATH)/%.c include/pints-polyfill-defines.h
	$(CC) $(CFLAGS) -c $< -o $@
   
#-----Main rule ----------
$(EXE_PATH)/$(PRODUCT): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(OPTFLAGS) $(CFG) $(INC) 

#-----Generator rules-----
include/pints-polyfill-defines.h : generator/template.py generator/templates/include/pints-polyfill-defines.h.jinja
	generator/template.py

generate: include/pints-polyfill-defines.h

# -- Other stuff ----------
depend:
	makedepend $(CFLAGS) -Y $(SRC)

clean:
	rm -f $(OBJ_PATH)/*
	rm -f $(EXE_PATH)/*
	rm -f include/pints-polyfill-defines.h
	rm -f include/pints-polyfill-funcs.h

run: $(EXE_PATH)/$(PRODUCT)
	$(EXE_PATH)/$(PRODUCT)

asm: $(EXE_PATH)/$(PRODUCT)
	objdump -d $(EXE_PATH)/$(PRODUCT) | vim -R -c 'set ft=asm' -
