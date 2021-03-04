CC			= gcc
LINK			= gcc

CC_FLAGS		= -g -c -Wall  -DDEVELOPMENT
TARGET_FLAGS		= -DNEED_NET_IF_H -DNEED_SYS_IOCTL_H -DNEED_LINUX_CAN_H -DNEED_LINUX_CAN_RAW_H -DNNED_TERMIO_H -DNEED_FILE_UTILS_TAR_FILE_C

LINK_FLAGS		= -g 

TARGET			= canmon
OBJ			= obj
ALLTARGETS		= $(TARGET)

OBJS			= $(sort 				\
			    $(OBJ)/CANInterface.o		\
			    $(OBJ)/CANInterfaceThread.o	        \
			    $(OBJ)/CANMonLog.o			\
			    $(OBJ)/CanMsg.o			\
			    $(OBJ)/DefFileToken.o		\
			    $(OBJ)/DeviceDef.o                  \
			    $(OBJ)/DeviceMessageDef.o		\
			    $(OBJ)/DeviceRegDef.o		\
			    $(OBJ)/Devices.o			\
			    $(OBJ)/DirManagement.o		\
			    $(OBJ)/HTTPServerThread.o		\
			    $(OBJ)/Messages.o			\
			    $(OBJ)/SQLStatements.o		\
			    $(OBJ)/ThreadSafePrint.o		\
			    $(OBJ)/UserInputThread.o		\
			    $(OBJ)/WebSocketIF.o		\
			    $(OBJ)/main.o			\
			   )

LIBS			= -ldl -lutils -lmongoose -lm -lpthread -lsqlite3 -lrt -llinenoise



$(TARGET)		: $(OBJS)
			  @echo [LD] $(TARGET)
			  @$(LINK) $(LINK_FLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(OBJ)/%.o		: %.c
			  @echo [CC] $@
			  @$(CC) $(CC_FLAGS) $(TARGET_FLAGS) $< -o $@

include			  depends.mk

.PHONY			: clean junkclean
junkclean		:
			  @echo Removing junk files
			  @-rm -rf $(wildcard CANMon*.txt *-bak *~)

clean			:
			  @echo Removing build files
			  @-rm -rf $(wildcard $(OBJS) $(ALLTARGETS))

