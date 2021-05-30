
# ----------------------- #
#          OPTS	 
# ----------------------- #


CC := gcc
CFLAGS := -Wall  
AR := ar
RM := rm -rf


# ----------------------- #
# 	BIN PATHS
# ----------------------- #


BDIR := ../bin
ODIR := $(BDIR)/obj
LDIR := $(BDIR)/lib
XDIR := $(BDIR)/exec


# ----------------------- #
# 	CNET LIB
# ----------------------- #


CNET := cnet
CNET_SDIR := ../$(CNET)/src
CNET_IDIR := ../$(CNET)/include
CNET_LIB := $(LDIR)/lib$(CNET).a
CNET_SRC := $(wildcard $(CNET_SDIR)/*.c)
CNET_OBJ := $(CNET_SRC:$(CNET_SDIR)/%.c=$(ODIR)/%.o)

$(ODIR)/%.o: $(CNET_SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -I$(CNET_IDIR) -c $? -o $@

$(CNET_LIB): $(CNET_OBJ)
	mkdir -p $(LDIR)
	$(AR) rc $@ $^

#$(CNET): $(CNET_LIB) 


# ----------------------- #
# 	  TESTS
# ----------------------- #


TEST := test
TEST_SDIR := ../$(TEST)


inte: $(XDIR)/integration.o  $(CNET_LIB)
	$(CC)  -o $@  -I$(CNET_IDIR) -L$(LDIR) -l$(CNET) -lm -I$(TEST)
	
$(XDIR)/integration.o: $(TEST_SDIR)/integration.c 
	mkdir -p $(XDIR)
	$(CC)  -c  -I$(CNET_IDIR)  -I$(TEST)   $^





# ----------------------- #
#	find char
# ----------------------- #
findbyline.o:findbyline.c
	$(CC)  -c $^
find:findbyline.o
	$(CC) $(CFLAGS) -o $@ $^  
# ----------------------- #
#	save_file_by_name
# ----------------------- #
save_test_dat.o:save_test_dat.c
	$(CC)  -c $^
save_data:save_test_dat.o
	$(CC) $(CFLAGS) -o $@ $^  
# ----------------------- #
#	  MNIST
# ----------------------- #

MNIST := mnist
MNIST_SDIR := $(MNIST)
MNIST_SRC := $(wildcard $(MNIST)/*.c)
MNIST_IN := $(wildcard $(MNIST)/*.h)


train: train.o 
	$(CC) $(CFLAGS) -o $@ $^  -lcnet -L$(LDIR) -lm -I$(MNIST) 
	
train.o:train.c 
	$(CC)  -c $^ -I$(CNET_IDIR) 

test: test.o 
	$(CC) $(CFLAGS) -o $@ $^  -lcnet -L$(LDIR) -lm -I$(MNIST) 
	
test.o:test.c 
	$(CC)  -c $^ -I$(CNET_IDIR) 


# ----------------------- #
#	  CLEANS
# ----------------------- #
clean_o:
	$(RM) ./*.o
clean_obj:
	$(RM) $(ODIR)
clean_lib:
	$(RM) $(LDIR)

clean_exec:
	$(RM) $(XDIR)

clean: clean_o clean_obj clean_lib clean_exec 
	$(RM) $(BDIR)
