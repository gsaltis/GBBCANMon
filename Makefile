CC			= gcc
LINK			= gcc

CC_FLAGS		= -g -c -Wall  -DDEVELOPMENT
TARGET_FLAGS		= -DNEED_NET_IF_H -DNEED_SYS_IOCTL_H -DNEED_LINUX_CAN_H -DNEED_LINUX_CAN_RAW_H -DNNED_TERMIO_H -DNEED_FILE_UTILS_TAR_FILE_C

LINK_FLAGS		= -g 

TARGET			= canmon

ALLTARGETS		= $(TARGET)

OBJS			= $(sort 				\
			    CANInterface.o			\
			    CANInterfaceThread.o		\
			    CANMonLog.o				\
			    CanMsg.o				\
			    DefFileToken.o			\
			    DeviceDef.o                         \
			    DeviceMessageDef.o			\
			    DeviceRegDef.o			\
			    Devices.o				\
			    DirManagement.o			\
			    HTTPServerThread.o			\
			    Messages.o				\
			    SQLStatements.o			\
			    ThreadSafePrint.o			\
			    UserInputThread.o			\
			    WebSocketIF.o			\
			    main.o				\
			   )

 LIBS			= -ldl -lutils -lmongoose -lm -lpthread -lsqlite3 -lrt -llinenoise

.PHONY			: all clean veryclean

all			: $(ALLTARGETS)

$(TARGET)		: $(OBJS)
			  @echo [LD] $(TARGET)
			  @$(LINK) $(LINK_FLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o			: %.c
			  @echo [CC] $@
			  @$(CC) $(CC_FLAGS) $(TARGET_FLAGS) $<

%.o			: lib/%.c
			  @echo [CC] $@
			  @$(CC) $(CC_FLAGS) $<

include			  depends.mk

junkclean		: 
			  -rm -rf $(wildcard CANMon*.txt *-bak *~)

clean			: 
			  -rm -rf $(wildcard *.o $(ALLTARGETS))

