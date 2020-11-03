AllCanDefinitions.o: AllCanDefinitions.c CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 lib/include/json.h String.h DeviceMessageDef.h AllCanDefinitions.h
Bay.o: Bay.c Bay.h String.h Panel.h lib/include/sqlite3.h FuseBreaker.h \
 lib/include/json.h CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h DeviceMessageDef.h PanelType.h BayType.h main.h \
 lib/include/mongoose.h FuseBreakerType.h WebConnection.h CANInterface.h \
 PanelConnection.h MemoryManager.h FileUtils.h Devices.h
BayType.o: BayType.c BayType.h lib/include/json.h String.h \
 MemoryManager.h JSONIF.h ascii.h
BytesManage.o: BytesManage.c
CANInterface.o: CANInterface.c CANInterface.h String.h MemoryManager.h \
 CLIThread.h ThreadSafePrint.h BytesManage.h Devices.h CanMsg.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 lib/include/json.h DeviceMessageDef.h main.h lib/include/mongoose.h \
 lib/include/sqlite3.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h
CANInterfaceThread.o: CANInterfaceThread.c lib/include/sqlite3.h \
 CANInterface.h String.h CANInterfaceThread.h main.h \
 lib/include/mongoose.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h lib/include/json.h DeviceMessageDef.h \
 FuseBreakerType.h PanelType.h BayType.h WebConnection.h CanMsg.h \
 BytesManage.h CANMonLog.h FileUtils.h DirManagement.h MemoryManager.h \
 CANInterfaceThreadManageArchives.c \
 CANInterfaceThreadGetArchivedFilenames.c \
 CANInterfaceThreadCreateArchive.c CANInterfaceThreadThrottleFile.c \
 CANInterfaceThreadHandleRequest.c
CANInterfaceThreadCreateArchive.o: CANInterfaceThreadCreateArchive.c
CANInterfaceThreadGetArchivedFilenames.o: \
 CANInterfaceThreadGetArchivedFilenames.c
CANInterfaceThreadHandleRequest.o: CANInterfaceThreadHandleRequest.c
CANInterfaceThreadManageArchives.o: CANInterfaceThreadManageArchives.c
CANInterfaceThreadThrottleFile.o: CANInterfaceThreadThrottleFile.c
CANMonLog.o: CANMonLog.c String.h FileUtils.h MemoryManager.h CANMonLog.h \
 CANMonLogInit.c CANMonLogWrite.c CANMonLogSetFilename.c
CANMonLogInit.o: CANMonLogInit.c
CANMonLogSetFilename.o: CANMonLogSetFilename.c
CANMonLogWrite.o: CANMonLogWrite.c
CANRegisterDef.o: CANRegisterDef.c CANRegisterDef.h String.h \
 NumericTypes.h
CanMsg.o: CanMsg.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h lib/include/json.h String.h DeviceMessageDef.h \
 ThreadSafePrint.h
DefFileToken.o: DefFileToken.c DefFileToken.h
DeviceDef.o: DeviceDef.c DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h lib/include/json.h String.h DeviceMessageDef.h \
 DirManagement.h MemoryManager.h DefFileToken.h ThreadSafePrint.h
DeviceMessageDef.o: DeviceMessageDef.c DeviceMessageDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h lib/include/json.h String.h \
 MemoryManager.h DefFileToken.h ThreadSafePrint.h DeviceDef.h
DeviceRegDef.o: DeviceRegDef.c DeviceRegDef.h DeviceDefines.h \
 NumericTypes.h JSONIF.h lib/include/json.h String.h DefFileToken.h \
 MemoryManager.h ThreadSafePrint.h
Devices.o: Devices.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h lib/include/json.h String.h DeviceMessageDef.h \
 AllCanDefinitions.h CANInterface.h ThreadSafePrint.h UserInputThread.h \
 Devices.h MemoryManager.h main.h lib/include/mongoose.h \
 lib/include/sqlite3.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h BytesManage.h
DirManagement.o: DirManagement.c DirManagement.h String.h MemoryManager.h \
 CANMonLog.h DirManagementGetInstallDir.c DirManagementSetInstallDir.c
DirManagementGetInstallDir.o: DirManagementGetInstallDir.c
DirManagementSetInstallDir.o: DirManagementSetInstallDir.c
FileUtils.o: FileUtils.c String.h MemoryManager.h DirManagement.h \
 CANMonLog.h ascii.h FileUtilsOpen.c FilenameExtractSuffix.c \
 FileUtilsCopyFile.c
FileUtilsCopyFile.o: FileUtilsCopyFile.c
FileUtilsOpen.o: FileUtilsOpen.c
FileUtilsTarFile.o: FileUtilsTarFile.c
FilenameExtractSuffix.o: FilenameExtractSuffix.c
FuseBreaker.o: FuseBreaker.c FuseBreaker.h String.h lib/include/json.h \
 CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h \
 JSONIF.h DeviceMessageDef.h MemoryManager.h Panel.h \
 lib/include/sqlite3.h PanelType.h Bay.h BayType.h main.h \
 lib/include/mongoose.h FuseBreakerType.h WebConnection.h CANInterface.h \
 PanelConnection.h Devices.h
FuseBreakerType.o: FuseBreakerType.c MemoryManager.h String.h ascii.h \
 FuseBreakerType.h lib/include/json.h JSONIF.h
HTTPEventHandler.o: HTTPEventHandler.c
HTTPServerThread.o: HTTPServerThread.c lib/include/mongoose.h \
 HTTPServerThread.h String.h main.h lib/include/sqlite3.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 lib/include/json.h DeviceMessageDef.h FuseBreakerType.h PanelType.h \
 BayType.h WebConnection.h CANInterface.h MemoryManager.h DirManagement.h \
 CANMonLog.h FileUtils.h CANInterfaceThread.h HTTPEventHandler.c
HandleCommandHelp.o: HandleCommandHelp.c
HandleCommandLimit.o: HandleCommandLimit.c
HandleCommandLimitSet.o: HandleCommandLimitSet.c
HandleCommandLog.o: HandleCommandLog.c
HandleGetLimitsRequest.o: HandleGetLimitsRequest.c
HandlePrepareDownloadRequest.o: HandlePrepareDownloadRequest.c
JSONIF.o: JSONIF.c lib/include/json.h String.h MemoryManager.h JSONIF.h
MainDisplayHelp.o: MainDisplayHelp.c
MainDisplayVersion.o: MainDisplayVersion.c
MainExit.o: MainExit.c
MainInitialize.o: MainInitialize.c
MainInitializeStartTime.o: MainInitializeStartTime.c
MainLimitSet.o: MainLimitSet.c
MainProcessCommandLine.o: MainProcessCommandLine.c
MainRemoveTarFiles.o: MainRemoveTarFiles.c
MemoryManager.o: MemoryManager.c MemoryManager.h ThreadSafePrint.h
MessageSetLimitsResponse.o: MessageSetLimitsResponse.c
Messages.o: Messages.c Messages.h String.h NumericTypes.h \
 MessageSetLimitsResponse.c
NumericTypes.o: NumericTypes.c
Panel.o: Panel.c Panel.h lib/include/sqlite3.h FuseBreaker.h String.h \
 lib/include/json.h CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h DeviceMessageDef.h PanelType.h MemoryManager.h \
 Bay.h BayType.h main.h lib/include/mongoose.h FuseBreakerType.h \
 WebConnection.h CANInterface.h PanelConnection.h Devices.h \
 SQLStatements.h
PanelType.o: PanelType.c MemoryManager.h ascii.h PanelType.h \
 lib/include/json.h String.h JSONIF.h
SQLStatements.o: SQLStatements.c String.h SQLStatements.h
String.o: String.c String.h MemoryManager.h ascii.h
StringUtils.o: StringUtils.c StringUtils.h
ThreadSafePrint.o: ThreadSafePrint.c
UserInputThread.o: UserInputThread.c UserInputThread.h linenoise.h \
 String.h MemoryManager.h ANSIColors.h CANInterfaceThread.h main.h \
 lib/include/mongoose.h lib/include/sqlite3.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h NumericTypes.h JSONIF.h lib/include/json.h \
 DeviceMessageDef.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h CANInterface.h FileUtils.h CANMonLog.h \
 HandleCommandLog.c HandleCommandLimit.c HandleCommandLimitSet.c \
 HandleCommandHelp.c
WebConnection.o: WebConnection.c lib/include/mongoose.h WebConnection.h \
 MemoryManager.h ThreadSafePrint.h String.h
WebSocketFrameResponseSend.o: WebSocketFrameResponseSend.c
WebSocketFrameSend.o: WebSocketFrameSend.c
WebSocketIF.o: WebSocketIF.c WebSocketIF.h lib/include/mongoose.h \
 FuseBreaker.h String.h lib/include/json.h CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 DeviceMessageDef.h Bay.h Panel.h lib/include/sqlite3.h PanelType.h \
 BayType.h main.h FuseBreakerType.h WebConnection.h CANInterface.h \
 PanelConnection.h Messages.h MemoryManager.h FileUtils.h Devices.h \
 ThreadSafePrint.h CANInterfaceThread.h CANMonLog.h HTTPServerThread.h \
 DirManagement.h WebSocketIFSetPort.c WebSocketIFCreateInfoScript.c \
 HandlePrepareDownloadRequest.c HandleGetLimitsRequest.c \
 WebSocketIFHandleSetTimeStampRequest.c WebSocketFrameResponseSend.c \
 WebSocketFrameSend.c WebSocketIFHandleSetLimitsRequest.c \
 WebSocketIFHandleGetMonitorInfoRequest.c \
 WebSocketIFHandlePacketRequest.c WebSocketIFHandleRemoveArchiveFiles.c
WebSocketIFCreateInfoScript.o: WebSocketIFCreateInfoScript.c
WebSocketIFHandleGetMonitorInfoRequest.o: \
 WebSocketIFHandleGetMonitorInfoRequest.c
WebSocketIFHandlePacketRequest.o: WebSocketIFHandlePacketRequest.c
WebSocketIFHandleRemoveArchiveFiles.o: \
 WebSocketIFHandleRemoveArchiveFiles.c
WebSocketIFHandleSetLimitsRequest.o: WebSocketIFHandleSetLimitsRequest.c
WebSocketIFHandleSetTimeStampRequest.o: \
 WebSocketIFHandleSetTimeStampRequest.c
WebSocketIFSetPort.o: WebSocketIFSetPort.c
canmoncl.o: canmoncl.c
canmonview.o: canmonview.c lib/include/json.h String.h MemoryManager.h \
 ascii.h FileUtils.h NumericTypes.h CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h JSONIF.h DeviceMessageDef.h
jsoncanif.o: jsoncanif.c jsoncanif.h lib/include/json.h CanMsg.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h NumericTypes.h JSONIF.h \
 String.h DeviceMessageDef.h AllCanDefinitions.h ThreadSafePrint.h \
 Devices.h CANInterface.h MemoryManager.h main.h lib/include/mongoose.h \
 lib/include/sqlite3.h FuseBreakerType.h PanelType.h BayType.h \
 WebConnection.h
linenoise.o: linenoise.c linenoise.h
main.o: main.c lib/include/sqlite3.h lib/include/mongoose.h \
 CANInterface.h String.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 NumericTypes.h JSONIF.h lib/include/json.h DeviceMessageDef.h \
 CANInterfaceThread.h MemoryManager.h UserInputThread.h \
 HTTPServerThread.h WebSocketIF.h FuseBreaker.h CanMsg.h Bay.h Panel.h \
 PanelType.h BayType.h main.h FuseBreakerType.h WebConnection.h \
 PanelConnection.h Messages.h DirManagement.h CANMonLog.h FileUtils.h \
 MainProcessCommandLine.c MainDisplayHelp.c MainInitialize.c MainExit.c \
 MainRemoveTarFiles.c MainLimitSet.c MainDisplayVersion.c \
 MainInitializeStartTime.c
