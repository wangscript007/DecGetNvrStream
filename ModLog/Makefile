include  ../Makefile.param

AR    := $(CCARCH)ar
CC    := $(CCARCH)gcc

INC_DIR := ./inc  ../common/inc ../common/inc/tlsdk ../common/inc/mod ../preview/inc 
INC_DIR += $(TL_APP_MPP_PATH)/include
SRC_DIR := ./src
OBJ_DIR := ./obj
TEST_DIR := ./test
LIB_DIR := ../common/lib

LDFLAGS := -lcustommp4 -lm -lapi -lpthread
LDFLAGS += ../common/lib/tl_lib.a 
LDFLAGS += $(foreach lib,$(LIB_DIR),-L$(lib))
LDFLAGS += $(TL_APP_LIBS)

CFLAGS += -O2 -Wall -fno-strict-aliasing
#CFLAGS += -Wall -fno-strict-aliasing

#CFLAGS := $(foreach inc,$(INC_DIR),-I$(inc))
CFLAGS += $(foreach inc,$(INC_DIR),-I$(inc))
CFLAGS += $(foreach lib,$(LIB_DIR),-L$(lib))
CFLAGS += $(TL_APP_INC_PATH) 


OBJS := $(OBJ_DIR)/log	            \
		$(OBJ_DIR)/utils                \
		#$(OBJ_DIR)/preview       	    \
		#$(OBJ_DIR)/gal  			    \
		#$(OBJ_DIR)/tljpeg			    \
		#$(OBJ_DIR)/utils			    \


OBJS := $(foreach obj,$(OBJS),$(obj).o)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

#test : $(OBJS) $(TEST_DIR)/test.c
#	$(CC) $(CFLAGS) $(TEST_DIR)/test.c $(OBJS) -o $(TEST_DIR)/test $(LDFLAGS)
#	\cp test/test /mnt/nfs
#	\cp test/test /tftpboot

liblog.so : $(OBJS)
	$(CC) $(CFLAGS) -fPIC -shared -o liblog.so $(OBJS)
	\cp liblog.so ../common/lib/debug -rf
	\cp liblog.so /tftpboot
	\cp liblog.so /mnt/nfs

test : $(TEST_DIR)/test.c liblog.so
	$(CC) $(CFLAGS)  $(TEST_DIR)/test.c -o $(TEST_DIR)/test -llog $(LDFLAGS) -L.
	\cp test/test /mnt/nfs
	\cp test/test /tftpboot
	
clean :
	rm -rf $(OBJ_DIR)/*

	
	

	
	
	


	


