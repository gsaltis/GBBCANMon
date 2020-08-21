CC			= gcc
LINK			= gcc

CC_FLAGS		= -g -c -Wall -Ilib/include  -DDEVELOPMENT

LINK_FLAGS		= -g -Llib

TARGET			= canmon

TARGET2			= canmoncl

TARGET3			= canmonview

ALLTARGETS		= $(TARGET) $(TARGET2) $(TARGET3)

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

OBJS2			= $(sort				\
			    canmoncl.o				\
			    CANMonLog.o				\
			    String.o				\
			    MemoryManager.o			\
			    FileUtils.o				\
			    ThreadSafePrint.o			\
			    AllCanDefinitions.o			\
	                    DirManagement.o             	\
			   )

OBJS3			= $(sort				\
			    canmonview.o			\
		    	    BytesManage.o			\
			    CanMsg.o				\
			    Devices.o				\
			    DefFileToken.o			\
			    DeviceDef.o                         \
			    DeviceMessageDef.o			\
			    DeviceRegDef.o			\
			    CANMonLog.o				\
			    String.o				\
			    MemoryManager.o			\
			    FileUtils.o				\
			    ThreadSafePrint.o			\
			    AllCanDefinitions.o			\
			    CanMsg.o				\
			    NumericTypes.o			\
			    DirManagement.o			\
			    json.o				\
			    jsoncanif.o				\
			    JSONIF.o				\
	 		   )

LIBS			= -ljson -lmongoose -lm -lpthread -lsqlite3 -lrt

.PHONY			: all clean veryclean

all			: $(ALLTARGETS)

$(TARGET)		: $(OBJS)
			  @echo [LD] $(TARGET)
			  @$(LINK) $(LINK_FLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(TARGET2)		: $(OBJS2)
			  @echo [LD] $(TARGET2)
			  @$(LINK) $(LINK_FLAGS) -o $(TARGET2) $(OBJS2)

$(TARGET3)		: $(OBJS3)
			  @echo [LD] $(TARGET3)
			  @$(LINK) $(LINK_FLAGS) -o $(TARGET3) $(OBJS3)

%.o			: %.c
			  @echo [CC] $@
			  @$(CC) $(CC_FLAGS) $<

%.o			: lib/%.c
			  @echo [CC] $@
			  @$(CC) $(CC_FLAGS) $<

include			  depends.mk

junkclean		: 
			  -rm -rf $(wildcard)

clean			: 
			  -rm -rf $(wildcard *.o $(ALLTARGETS))

