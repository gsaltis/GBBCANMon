AllCanDefinitions.o: AllCanDefinitions.c CanMsg.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h DeviceMessageDef.h AllCanDefinitions.h
CANInterface.o: CANInterface.c CANInterface.h CLIThread.h \
 ThreadSafePrint.h Devices.h CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h main.h \
 CANInterface/CANInterfaceReset.c CANInterface/CANInterfaceTransaction.c \
 CANInterface/CANInterfaceReadTimeout.c CANInterface/CANInterfaceRead.c \
 CANInterface/CANInterfaceWrite.c CANInterface/CANInterfaceClose.c \
 CANInterface/CANInterfaceInit.c
CANInterfaceThread.o: CANInterfaceThread.c CANInterface.h \
 CANInterfaceThread.h main.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h CanMsg.h CANMonLog.h DirManagement.h \
 CANInterfaceThread/CANInterfaceThreadManageArchives.c \
 CANInterfaceThread/CANInterfaceThreadGetArchivedFilenames.c \
 CANInterfaceThread/CANInterfaceThreadCreateArchive.c \
 CANInterfaceThread/CANInterfaceThreadThrottleFile.c \
 CANInterfaceThread/CANInterfaceThreadHandleRequest.c
CANMonLog.o: CANMonLog.c CANMonLog.h CANMonLog/CANMonLogInit.c \
 CANMonLog/CANMonLogWrite.c CANMonLog/CANMonLogSetFilename.c
CANRegisterDef.o: CANRegisterDef.c CANRegisterDef.h
CanMsg.o: CanMsg.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h ThreadSafePrint.h
DefFileToken.o: DefFileToken.c DefFileToken.h
DeviceDef.o: DeviceDef.c DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h DirManagement.h DefFileToken.h ThreadSafePrint.h
DeviceMessageDef.o: DeviceMessageDef.c DeviceMessageDef.h DeviceDefines.h \
 DeviceRegDef.h DefFileToken.h ThreadSafePrint.h DeviceDef.h
DeviceRegDef.o: DeviceRegDef.c DeviceRegDef.h DeviceDefines.h \
 DefFileToken.h ThreadSafePrint.h
Devices.o: Devices.c CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h AllCanDefinitions.h CANInterface.h ThreadSafePrint.h \
 UserInputThread.h Devices.h main.h Devices/FindRegisterByIndexGroup.c \
 Devices/GetDeviceNumbersString.c Devices/DeviceFindRegister.c \
 Devices/GetNextDevice.c Devices/GetFirstDevice.c \
 Devices/GetDeviceTypeCount.c Devices/HandleCanTraffic.c \
 Devices/HandleReguest.c Devices/GetRegisterByDef.c \
 Devices/GetRegisterByName.c Devices/SendResponses.c \
 Devices/GetRequestBreakdown.c Devices/DisableDevice.c \
 Devices/EnableDevice.c Devices/AddDevice.c Devices/AddSingleDevice.c \
 Devices/FindCANDeviceByDefNameAddress.c Devices/CreateDevice.c \
 Devices/AddCANDevice.c Devices/CopyDevice.c Devices/ClearDevice.c \
 Devices/RemoveDevice.c Devices/SetRegisterValueFlat.c \
 Devices/SetRegisterValueHex.c Devices/SetRegisterValue.c \
 Devices/GetDeviceRegisterFloat.c Devices/SetDeviceRegister.c \
 Devices/SetRegisterValueByName.c Devices/DumpGroup.c \
 Devices/ClearDeviceRegisters.c Devices/DumpDevice.c Devices/FindDevice.c \
 Devices/DumpDefs.c Devices/HandleShowMessages.c \
 Devices/DisplayDeviceDefMessages.c Devices/GetGroupAndAbbrev.c \
 Devices/GetRegisterByGroup.c Devices/GetAbbrevList.c \
 Devices/GetGroupList.c Devices/GetDeviceCount.c Devices/GetDeviceList.c \
 Devices/GetCanDeviceDefByName.c Devices/GetGroupArray.c
DirManagement.o: DirManagement.c DirManagement.h CANMonLog.h \
 DirManagement/DirManagementGetInstallDir.c \
 DirManagement/DirManagementSetInstallDir.c DirManagement/DMGetFileName.c \
 DirManagement/GetDeviceProtocolFileName.c \
 DirManagement/GetDeviceDataFileName.c \
 DirManagement/GetDeviceDefsFileName.c \
 DirManagement/DirManagementInitialize.c
HTTPEventHandler.o: HTTPEventHandler.c
HTTPServerThread.o: HTTPServerThread.c HTTPServerThread.h main.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h DeviceMessageDef.h \
 CANInterface.h DirManagement.h CANMonLog.h CANInterfaceThread.h \
 HTTPEventHandler.c
HandleCommandHelp.o: HandleCommandHelp.c
HandleCommandLimit.o: HandleCommandLimit.c
HandleCommandLimitSet.o: HandleCommandLimitSet.c
HandleCommandLog.o: HandleCommandLog.c
MessageSetLimitsResponse.o: MessageSetLimitsResponse.c
Messages.o: Messages.c Messages.h MessageSetLimitsResponse.c
SQLStatements.o: SQLStatements.c SQLStatements.h
ThreadSafePrint.o: ThreadSafePrint.c
UserInputThread.o: UserInputThread.c UserInputThread.h \
 CANInterfaceThread.h main.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h CANInterface.h CANMonLog.h HandleCommandLog.c \
 HandleCommandLimit.c HandleCommandLimitSet.c HandleCommandHelp.c
WebSocketIF.o: WebSocketIF.c WebSocketIF.h Messages.h main.h DeviceDef.h \
 DeviceDefines.h DeviceRegDef.h DeviceMessageDef.h CANInterface.h \
 Devices.h CanMsg.h ThreadSafePrint.h CANInterfaceThread.h CANMonLog.h \
 HTTPServerThread.h DirManagement.h WebSocketIF/WebSocketIFSetPort.c \
 WebSocketIF/WebSocketIFCreateInfoScript.c \
 WebSocketIF/HandlePrepareDownloadRequest.c \
 WebSocketIF/HandleGetLimitsRequest.c \
 WebSocketIF/WebSocketIFHandleSetTimeStampRequest.c \
 WebSocketIF/WebSocketFrameResponseSend.c \
 WebSocketIF/WebSocketFrameSend.c \
 WebSocketIF/WebSocketIFHandleSetLimitsRequest.c \
 WebSocketIF/WebSocketIFHandleGetMonitorInfoRequest.c \
 WebSocketIF/WebSocketIFHandlePacketRequest.c \
 WebSocketIF/WebSocketIFHandleRemoveArchiveFiles.c
canmoncl.o: canmoncl.c
canmonview.o: canmonview.c CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h
main.o: main.c CANInterface.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h CANInterfaceThread.h UserInputThread.h \
 HTTPServerThread.h WebSocketIF.h Messages.h DirManagement.h CANMonLog.h \
 main.h Main/MainProcessCommandLine.c Main/MainDisplayHelp.c \
 Main/MainInitialize.c Main/MainExit.c Main/MainRemoveTarFiles.c \
 Main/MainLimitSet.c Main/MainDisplayVersion.c \
 Main/MainInitializeStartTime.c Main/MainClearDatabase.c \
 Main/MainOpenDatabase.c Main/MainVerifyCommandLine.c
