OBJS=RingBuffer.o 

TARGET=libRingBuf.a
ifeq "$(GCC_VERSION)" "ARMGCC_Hi3531"
TARGET=libHIRingBuf.a
endif

OWNLINK=cr
IFLAGS+=-I ../include

$(TARGET):$(OBJS)
	$(AR) $(OWNLINK) $(TARGET) $(OBJS)
	cp $(TARGET) $(LIB_INSTALL_DIR)


debug:$(OBJS)
	$(AR) $(OWNLINK) $(TARGET) $(OBJS)
	cp $(TARGET) $(LIB_INSTALL_DIR)

%.o:%.c
	$(CC)  $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@


install:
	cp $(TARGET) $(DIR)/lib

clean:
	rm -f $(OBJS) $(TARGET) $(LIB_INSTALL_DIR)/$(TARGET)
