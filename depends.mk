AllCanDefinitions.o: AllCanDefinitions.c CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h String.h \
 DeviceMessageDef.h AllCanDefinitions.h
Bay.o: Bay.c Bay.h String.h Panel.h FuseBreaker.h CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h PanelType.h BayType.h main.h FuseBreakerType.h \
 WebConnection.h CANInterface.h PanelConnection.h MemoryManager.h \
 FileUtils.h Devices.h
BayType.o: BayType.c BayType.h String.h MemoryManager.h JSONIF.h ascii.h
BytesManage.o: BytesManage.c
CANDefsToJSON.o: CANDefsToJSON.c String.h FileUtils.h MemoryManager.h \
 AllCanDefinitions.h CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h DeviceMessageDef.h
CANInterface.o: CANInterface.c CANInterface.h String.h MemoryManager.h \
 CLIThread.h ThreadSafePrint.h BytesManage.h Devices.h CanMsg.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h main.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h
CANInterfaceDevDeviceName.o: CANInterfaceDevDeviceName.c
CANInterfaceThread.o: CANInterfaceThread.c CANInterface.h String.h \
 CANInterfaceThread.h main.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h DeviceMessageDef.h FuseBreakerType.h PanelType.h \
 BayType.h WebConnection.h CanMsg.h BytesManage.h CANMonLog.h FileUtils.h
CANMonLog.o: CANMonLog.c String.h FileUtils.h MemoryManager.h CANMonLog.h \
 CANMonLogInit.c CANMonLogWrite.c CANMonLogSetFilename.c
CANMonLogInit.o: CANMonLogInit.c
CANMonLogSetFilename.o: CANMonLogSetFilename.c
CANMonLogWrite.o: CANMonLogWrite.c
CANRegisterDef.o: CANRegisterDef.c CANRegisterDef.h String.h \
 NumericTypes.h
CANSimMain.o: CANSimMain.c CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h String.h DeviceMessageDef.h \
 Devices.h CANInterface.h ThreadSafePrint.h DirManagement.h
CanMsg.o: CanMsg.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h String.h DeviceMessageDef.h ThreadSafePrint.h
DefFileToken.o: DefFileToken.c DefFileToken.h
DeviceDef.o: DeviceDef.c DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h String.h DeviceMessageDef.h DirManagement.h \
 MemoryManager.h DefFileToken.h ThreadSafePrint.h
DeviceMessageDef.o: DeviceMessageDef.c DeviceMessageDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h String.h MemoryManager.h \
 DefFileToken.h ThreadSafePrint.h DeviceDef.h
DeviceRegDef.o: DeviceRegDef.c DeviceRegDef.h DeviceDefines.h \
 NumericTypes.h JSONIF.h String.h DefFileToken.h MemoryManager.h \
 ThreadSafePrint.h
Devices.o: Devices.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h String.h DeviceMessageDef.h AllCanDefinitions.h \
 CANInterface.h ThreadSafePrint.h UserInputThread.h Devices.h \
 MemoryManager.h main.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h BytesManage.h
DirManagement.o: DirManagement.c DirManagement.h String.h MemoryManager.h \
 CANMonLog.h DirManagementGetInstallDir.c DirManagementSetInstallDir.c
DirManagementGetInstallDir.o: DirManagementGetInstallDir.c
DirManagementSetInstallDir.o: DirManagementSetInstallDir.c
FileUtils.o: FileUtils.c String.h MemoryManager.h DirManagement.h \
 CANMonLog.h FileUtilsOpen.c
FileUtilsOpen.o: FileUtilsOpen.c
FuseBreaker.o: FuseBreaker.c FuseBreaker.h String.h CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h MemoryManager.h Panel.h PanelType.h Bay.h BayType.h \
 main.h FuseBreakerType.h WebConnection.h CANInterface.h \
 PanelConnection.h Devices.h
FuseBreakerType.o: FuseBreakerType.c MemoryManager.h String.h ascii.h \
 FuseBreakerType.h JSONIF.h
HTTPServerThread.o: HTTPServerThread.c HTTPServerThread.h String.h main.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h CANInterface.h MemoryManager.h DirManagement.h \
 CANMonLog.h
HandleCommandLog.o: HandleCommandLog.c
HandlePrepareDownloadRequest.o: HandlePrepareDownloadRequest.c
JSONIF.o: JSONIF.c String.h MemoryManager.h JSONIF.h
MainDisplayHelp.o: MainDisplayHelp.c
MainExit.o: MainExit.c
MainInitialize.o: MainInitialize.c
MainProcessCommandLine.o: MainProcessCommandLine.c
MemoryManager.o: MemoryManager.c MemoryManager.h ThreadSafePrint.h
NumericTypes.o: NumericTypes.c
Panel.o: Panel.c Panel.h FuseBreaker.h String.h CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h PanelType.h MemoryManager.h Bay.h BayType.h main.h \
 FuseBreakerType.h WebConnection.h CANInterface.h PanelConnection.h \
 Devices.h SQLStatements.h
PanelConnection.o: PanelConnection.c PanelConnection.h String.h \
 MemoryManager.h JSONIF.h Bay.h Panel.h FuseBreaker.h CanMsg.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h \
 DeviceMessageDef.h PanelType.h BayType.h main.h FuseBreakerType.h \
 WebConnection.h CANInterface.h
PanelType.o: PanelType.c MemoryManager.h ascii.h PanelType.h String.h \
 JSONIF.h
SQLStatements.o: SQLStatements.c String.h SQLStatements.h
String.o: String.c String.h MemoryManager.h ascii.h
StringUtils.o: StringUtils.c StringUtils.h
ThreadSafePrint.o: ThreadSafePrint.c
UserInputThread.o: UserInputThread.c UserInputThread.h linenoise.h \
 String.h MemoryManager.h ANSIColors.h CANInterfaceThread.h main.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h CANInterface.h FileUtils.h CANMonLog.h \
 HandleCommandLog.c
WebConnection.o: WebConnection.c WebConnection.h MemoryManager.h \
 ThreadSafePrint.h String.h
WebSocketIF.o: WebSocketIF.c WebSocketIF.h FuseBreaker.h String.h \
 CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h \
 JSONIF.h DeviceMessageDef.h Bay.h Panel.h PanelType.h BayType.h main.h \
 FuseBreakerType.h WebConnection.h CANInterface.h PanelConnection.h \
 MemoryManager.h FileUtils.h Devices.h ThreadSafePrint.h \
 CANInterfaceThread.h CANMonLog.h HTTPServerThread.h DirManagement.h \
 WebSocketIFSetPort.c WebSocketIFCreateInfoScript.c \
 HandlePrepareDownloadRequest.c
WebSocketIFCreateInfoScript.o: WebSocketIFCreateInfoScript.c
WebSocketIFSetPort.o: WebSocketIFSetPort.c
canmoncl.o: canmoncl.c
canmonview.o: canmonview.c String.h CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h DeviceMessageDef.h \
 MemoryManager.h ANSIColors.h FileUtils.h
jsoncanif.o: jsoncanif.c jsoncanif.h CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h String.h DeviceMessageDef.h \
 AllCanDefinitions.h ThreadSafePrint.h Devices.h CANInterface.h \
 MemoryManager.h main.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h
linenoise.o: linenoise.c linenoise.h
main.o: main.c CANInterface.h String.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h DeviceMessageDef.h \
 CANInterfaceThread.h MemoryManager.h UserInputThread.h \
 HTTPServerThread.h WebSocketIF.h FuseBreaker.h CanMsg.h Bay.h Panel.h \
 PanelType.h BayType.h main.h FuseBreakerType.h WebConnection.h \
 PanelConnection.h DirManagement.h CANMonLog.h MainProcessCommandLine.c \
 MainDisplayHelp.c MainInitialize.c MainExit.c
mongoose.o: mongoose.c
