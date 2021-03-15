obj/CANInterface.o: CANInterface.c CANInterface.h ThreadSafePrint.h \
 Devices.h CanMsg.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h main.h CANInterface/CANInterfaceReset.c \
 CANInterface/CANInterfaceTransaction.c \
 CANInterface/CANInterfaceReadTimeout.c CANInterface/CANInterfaceRead.c \
 CANInterface/CANInterfaceWrite.c CANInterface/CANInterfaceClose.c \
 CANInterface/CANInterfaceInit.c
obj/CANInterfaceThread.o: CANInterfaceThread.c CANInterface.h \
 CANInterfaceThread.h main.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h CanMsg.h CANMonLog.h DirManagement.h \
 CANInterfaceThread/CANInterfaceThreadManageArchives.c \
 CANInterfaceThread/CANInterfaceThreadGetArchivedFilenames.c \
 CANInterfaceThread/CANInterfaceThreadCreateArchive.c \
 CANInterfaceThread/CANInterfaceThreadThrottleFile.c \
 CANInterfaceThread/CANInterfaceThreadHandleRequest.c
obj/CANMonLog.o: CANMonLog.c CANMonLog.h CANMonLog/CANMonLogInit.c \
 CANMonLog/CANMonLogWrite.c CANMonLog/CANMonLogSetFilename.c
obj/canmonview.o: canmonview.c CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h
obj/CanMsg.o: CanMsg.c CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h ThreadSafePrint.h \
 CanMsg/CANValueGetFromString.c CanMsg/CanRegGetFromString.c \
 CanMsg/CanRegSetFromString.c CanMsg/ParseData.c CanMsg/ParseId.c \
 CanMsg/GetDataFrame.c CanMsg/GetFrameId.c CanMsg/GetBitsI.c \
 CanMsg/GetBits.c
obj/DefFileToken.o: DefFileToken.c DefFileToken.h \
 DefFileToken/ReadDefToken.c DefFileToken/ReadDefTokenFromFile.c
obj/DeviceDef.o: DeviceDef.c DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h DirManagement.h DefFileToken.h ThreadSafePrint.h \
 DeviceDef/FindDeviceDefByProtocol.c DeviceDef/FindRegDefByValueType.c \
 DeviceDef/DeviceDefFindRegByValueType.c \
 DeviceDef/DeviceDefFindMessageByType.c \
 DeviceDef/DeviceDefErrorCodeToString.c \
 DeviceDef/DeviceDefGetMessageCount.c DeviceDef/DeviceDefGetRegCount.c \
 DeviceDef/FindDeviceDef.c DeviceDef/RemoveDeviceDefByName.c \
 DeviceDef/RemoveDeviceDef.c DeviceDef/AddDeviceDef.c \
 DeviceDef/DestroyDeviceDefList.c DeviceDef/DeviceDefListAppendDef.c \
 DeviceDef/DeviceDefResolveResponseDefs.c DeviceDef/DeviceDefListToJSON.c \
 DeviceDef/DeviceDefToJSON.c DeviceDef/DeviceDefFromJSON.c \
 DeviceDef/DeviceDefListFromJSON.c DeviceDef/DumpDeviceDefList.c \
 DeviceDef/CreateDeviceDefList.c DeviceDef/DumpDeviceDef.c \
 DeviceDef/DumpDeviceDefShort.c DeviceDef/DestroyDeviceDef.c \
 DeviceDef/CreateNewDeviceDef.c DeviceDef/CreateDeviceDef.c
obj/DeviceMessageDef.o: DeviceMessageDef.c DeviceMessageDef.h \
 DeviceDefines.h DeviceRegDef.h DefFileToken.h ThreadSafePrint.h \
 DeviceDef.h DeviceMessageDef/DeviceMessageResponseSetFromJSON.c \
 DeviceMessageDef/DeviceMessageDefListToJSON.c \
 DeviceMessageDef/DeviceMessageDefToJSON.c \
 DeviceMessageDef/DeviceMessageDefFromJSON.c \
 DeviceMessageDef/FindMessageDefByMessageType.c \
 DeviceMessageDef/GetDeviceMessageCount.c \
 DeviceMessageDef/AddDeviceMessageDef.c \
 DeviceMessageDef/DeviceMessageDefAddResponseType.c \
 DeviceMessageDef/CreateDeviceMessageDefList.c \
 DeviceMessageDef/DestroyDeviceMessageDeviceList.c \
 DeviceMessageDef/DumpDeviceMessageDefList.c \
 DeviceMessageDef/DumpDeviceMessageDefListShort.c \
 DeviceMessageDef/DumpDeviceMessageDefShort.c \
 DeviceMessageDef/DumpDeviceMessageDef.c \
 DeviceMessageDef/DestroyDeviceMessageDef.c \
 DeviceMessageDef/CreateDeviceMessageDef.c
obj/DeviceRegDef.o: DeviceRegDef.c DeviceRegDef.h DeviceDefines.h \
 DefFileToken.h ThreadSafePrint.h DeviceRegDef/DeviceRegDefToJSON.c \
 DeviceRegDef/DeviceRegDefListToJSON.c \
 DeviceRegDef/DeviceRegDefFromJSON.c \
 DeviceRegDef/DeviceRegDefCompareByNumber.c \
 DeviceRegDef/DeviceRegDefCompareByGroupName.c \
 DeviceRegDef/DeviceRegDefCompareByName.c \
 DeviceRegDef/GetDeviceRegCount.c DeviceRegDef/AddDeviceRegDef.c \
 DeviceRegDef/FindRegDefByValue.c DeviceRegDef/FindRegDefByName.c \
 DeviceRegDef/CreateDeviceRegDefList.c DeviceRegDef/CreateDeviceRegDef.c \
 DeviceRegDef/DestroyDeviceRegDef.c DeviceRegDef/DumpDeviceRegDefShort.c \
 DeviceRegDef/DumpDeviceRegDef.c DeviceRegDef/DumpDeviceRegDefList.c \
 DeviceRegDef/DumpDeviceRegDefListShort.c DeviceRegDef/ReadDeviceReg.c \
 DeviceRegDef/DestroyDeviceRegList.c DeviceRegDef/ReadDeviceRegsList.c
obj/Devices.o: Devices.c CanMsg.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h CANInterface.h ThreadSafePrint.h \
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
obj/DirManagement.o: DirManagement.c DirManagement.h CANMonLog.h \
 DirManagement/DirManagementGetInstallDir.c \
 DirManagement/DirManagementSetInstallDir.c DirManagement/DMGetFileName.c \
 DirManagement/GetDeviceProtocolFileName.c \
 DirManagement/GetDeviceDataFileName.c \
 DirManagement/GetDeviceDefsFileName.c \
 DirManagement/DirManagementInitialize.c DirManagement/DirManagementLog.c \
 DirManagement/DirManagementGetWebDir.c
obj/HTTPServerThread.o: HTTPServerThread.c HTTPServerThread.h main.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h DeviceMessageDef.h \
 CANInterface.h DirManagement.h CANMonLog.h CANInterfaceThread.h \
 HTTPServerThread/HTTPEventHandler.c HTTPServerThread/HTTPServerThread.c \
 HTTPServerThread/HTTPServerThreadInit.c
obj/main.o: main.c CANInterface.h DeviceDef.h DeviceDefines.h \
 DeviceRegDef.h DeviceMessageDef.h CANInterfaceThread.h UserInputThread.h \
 HTTPServerThread.h WebSocketIF.h Messages.h DirManagement.h CANMonLog.h \
 main.h Main/MainProcessCommandLine.c Main/MainDisplayHelp.c \
 Main/MainInitialize.c Main/MainExit.c Main/MainRemoveTarFiles.c \
 Main/MainLimitSet.c Main/MainDisplayVersion.c \
 Main/MainInitializeStartTime.c Main/MainClearDatabase.c \
 Main/MainOpenDatabase.c Main/MainVerifyCommandLine.c
obj/Messages.o: Messages.c Messages.h Messages/MessageSetLimitsResponse.c
obj/ThreadSafePrint.o: ThreadSafePrint.c
obj/UserInputThread.o: UserInputThread.c UserInputThread.h \
 CANInterfaceThread.h main.h DeviceDef.h DeviceDefines.h DeviceRegDef.h \
 DeviceMessageDef.h CANInterface.h CANMonLog.h \
 UserInputThread/HandleCommandLog.c UserInputThread/HandleCommandLimit.c \
 UserInputThread/HandleCommandLimitSet.c \
 UserInputThread/HandleCommandHelp.c \
 UserInputThread/CANInterfaceMonitorCountReset.c \
 UserInputThread/HandleCommandMonitorClear.c \
 UserInputThread/HandleCommandMonitorStart.c \
 UserInputThread/HandleCommandMonitorStop.c \
 UserInputThread/HandleCommandMonitor.c \
 UserInputThread/HandleCommandMessageCount.c \
 UserInputThread/HandleCommandMessage.c \
 UserInputThread/HandleCommandExit.c \
 UserInputThread/HandleCommandTimeElapsed.c \
 UserInputThread/HandleCommandTime.c UserInputThread/HandleCommand.c
obj/WebSocketIF.o: WebSocketIF.c WebSocketIF.h Messages.h main.h \
 DeviceDef.h DeviceDefines.h DeviceRegDef.h DeviceMessageDef.h \
 CANInterface.h Devices.h CanMsg.h ThreadSafePrint.h CANInterfaceThread.h \
 CANMonLog.h HTTPServerThread.h DirManagement.h \
 WebSocketIF/WebSocketIFSetPort.c \
 WebSocketIF/WebSocketIFCreateInfoScript.c \
 WebSocketIF/HandlePrepareDownloadRequest.c \
 WebSocketIF/HandleGetLimitsRequest.c \
 WebSocketIF/WebSocketIFHandleSetTimeStampRequest.c \
 WebSocketIF/WebSocketFrameResponseSend.c \
 WebSocketIF/WebSocketFrameSend.c \
 WebSocketIF/WebSocketIFHandleSetLimitsRequest.c \
 WebSocketIF/WebSocketIFHandleGetMonitorInfoRequest.c \
 WebSocketIF/WebSocketIFHandlePacketRequest.c \
 WebSocketIF/WebSocketIFHandleRemoveArchiveFiles.c \
 WebSocketIF/WebSocketFrameResponseSendError.c \
 WebSocketIF/HandleToggleMonitorRequest.c \
 WebSocketIF/HandleSetBayRegValuesRequest.c \
 WebSocketIF/HandleWebSocketRequest.c WebSocketIF/WebSocketEventHandler.c \
 WebSocketIF/WebSocketServerThread.c WebSocketIF/WebSocketServerInit.c
