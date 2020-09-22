#define CAN_INFO_MSG_ID             411     //message id for messages on can bus
#define CAN_ENGINE_ERROR_MSG_ID     500     //message id for engine sensors out of range and/or errors

#define CAN_SH_VSS_MSG_ID           600     //message id for VSS from SensorHub
#define CAN_SH_TRP_MSG_ID           605     //message id for trip odometer from SensorHub (recorded as pulses)

#define CAN_ERROR_MSG_ID            911     //message id for errors related to can bus comms, etc.

#define VSS_PULSE_PER_MILE          8000    //used to determine both speed and distance, Ford is typically 8000, GM is sometimes 4000

typedef struct {
    uint16_t messageID;
    int16_t contentID;
    char* messageText;  //try to stay <= 16 chars to fit on single line of display
} canSystemMessage;

//generated by any AutoCAN module
const canSystemMessage canRxError =         {CAN_ERROR_MSG_ID, 100, "CAN RX ERROR"};
const canSystemMessage canNodeOffline =     {CAN_ERROR_MSG_ID, 105, "CAN NODE OFFLINE"};

//generated by AutoCAN_Epasuino
const canSystemMessage canEpas1 =           {CAN_INFO_MSG_ID, 200, "Manual Steering"};
const canSystemMessage canEpas2 =           {CAN_INFO_MSG_ID, 205, "Firm Steering"};
const canSystemMessage canEpas3 =           {CAN_INFO_MSG_ID, 210, "Sport+ Steering"};
const canSystemMessage canEpas4 =           {CAN_INFO_MSG_ID, 215, "Sport Steering"};
const canSystemMessage canEpas5 =           {CAN_INFO_MSG_ID, 220, "Touring Steering"};
const canSystemMessage canEpas6 =           {CAN_INFO_MSG_ID, 225, "Comfort Steering"};

//generated by AutoCAN_SensorHub
canSystemMessage canSPD =                   {CAN_SH_VSS_MSG_ID, -1, "SPD"};
canSystemMessage canTRP =                   {CAN_SH_TRP_MSG_ID, -1, "TRP"};

//simple engine sensor range errors
const canSystemMessage canErrCLTLow =       {CAN_ENGINE_ERROR_MSG_ID, 400, "CLT LOW"};
const canSystemMessage canErrCLTHigh =      {CAN_ENGINE_ERROR_MSG_ID, 405, "CLT HIGH"};
const canSystemMessage canErrIATLow =       {CAN_ENGINE_ERROR_MSG_ID, 410, "IAT LOW"};
const canSystemMessage canErrIATHigh =      {CAN_ENGINE_ERROR_MSG_ID, 415, "IAT HIGH"};
const canSystemMessage canErrMAPLow =       {CAN_ENGINE_ERROR_MSG_ID, 420, "MAP LOW"};
const canSystemMessage canErrMAPHigh =      {CAN_ENGINE_ERROR_MSG_ID, 425, "MAP HIGH"};
const canSystemMessage canErrRPMLow =       {CAN_ENGINE_ERROR_MSG_ID, 420, "RPM LOW"};
const canSystemMessage canErrRPMHigh =      {CAN_ENGINE_ERROR_MSG_ID, 425, "RPM HIGH"};
const canSystemMessage canErrAFRLean =      {CAN_ENGINE_ERROR_MSG_ID, 430, "AFR LEAN"};
const canSystemMessage canErrAFRRich =      {CAN_ENGINE_ERROR_MSG_ID, 435, "AFR RICH"};
const canSystemMessage canErrBatLow =       {CAN_ENGINE_ERROR_MSG_ID, 440, "BAT LOW"};
const canSystemMessage canErrBatHigh =      {CAN_ENGINE_ERROR_MSG_ID, 445, "BAT HIGH"};
const canSystemMessage canTPSLow =          {CAN_ENGINE_ERROR_MSG_ID, 450, "TPS LOW"};
const canSystemMessage canTPSHigh =         {CAN_ENGINE_ERROR_MSG_ID, 455, "TPS HIGH"};

//calculated engine sensor errors
const canSystemMessage canErrColdIdleLow =  {CAN_ENGINE_ERROR_MSG_ID, 500, "COLD IDLE LOW"};
const canSystemMessage canErrColdIdleHigh = {CAN_ENGINE_ERROR_MSG_ID, 505, "COLD IDLE HIGH"};
const canSystemMessage canErrHotIdleLow =   {CAN_ENGINE_ERROR_MSG_ID, 510, "HOT IDLE LOW"};
const canSystemMessage canErrHotIdleHigh =  {CAN_ENGINE_ERROR_MSG_ID, 515, "HOT IDLE HIGH"};
const canSystemMessage canErrIdleUnsteady = {CAN_ENGINE_ERROR_MSG_ID, 520, "IDLE UNSTEADY"};
const canSystemMessage canAFRTGTLean =      {CAN_ENGINE_ERROR_MSG_ID, 525, "AFR OFF TGT LEAN"};
const canSystemMessage canAFRTGTRich =      {CAN_ENGINE_ERROR_MSG_ID, 530, "AFR OFF TGT RICH"};
//forced induction only: fuel pressure should rise 1:1 with boost pressure
const canSystemMessage canFPRegErr =        {CAN_ENGINE_ERROR_MSG_ID, 535, "FP REGULATOR ERR"};

