CC			= gcc
LINK			= gcc

CC_FLAGS		= -g -c -Wall -Ilib/include  -DDEVELOPMENT
TARGET_FLAGS		= -DNEED_NET_IF_H -DNEED_SYS_IOCTL_H -DNEED_LINUX_CAN_H -DNEED_LINUX_CAN_RAW_H -DNNED_TERMIO_H -DNEED_FILE_UTILS_TAR_FILE_C

LINK_FLAGS		= -g -Llib

TARGET			= canmon

ALLTARGETS		= $(TARGET)

OBJS			= $(sort 				\
			    AllCanDefinitions.o			\
			    BytesManage.o			\
			    CANInterface.o			\
			    CANInterfaceThread.o		\
			    CANRegisterDef.o			\
			    CANMonLog.o				\
			    CanMsg.o				\
			    DefFileToken.o			\
			    DeviceDef.o                         \
			    DeviceMessageDef.o			\
			    DeviceMessageDef.o			\
			    DeviceRegDef.o			\
			    DeviceRegDef.o			\
			    Devices.o				\
			    DirManagement.o			\
			    FileUtils.o				\
			    JSONIF.o				\
			    HTTPServerThread.o			\
			    MemoryManager.o			\
			    Messages.o				\
			    NumericTypes.o			\
			    SQLStatements.o			\
			    String.o				\
			    StringUtils.o			\
			    ThreadSafePrint.o			\
			    UserInputThread.o			\
			    WebSocketIF.o			\
			    jsoncanif.o				\
			    main.o				\
			    linenoise.o				\
			   )

LIBS			= -ldl -ljson -lmongoose -lm -lpthread -lsqlite3 -lrt

.PHONY			: all clean veryclean locallibs

all			: locallibs $(ALLTARGETS)

locallibs		: 
			  @cd lib && make

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
			  cd lib && make clean

