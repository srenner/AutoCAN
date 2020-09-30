#define CAN_EPAS_MSG_ID             400     //message id when broadcasting a new epas steering mode
#define CAN_INFO_MSG_ID             411     //message id for messages on can bus
#define CAN_ENGINE_ERROR_MSG_ID     500     //message id for engine sensors out of range and/or errors

#define CAN_SH_VSS_MSG_ID           600     //message id for VSS from SensorHub
#define CAN_SH_TRP_MSG_ID           605     //message id for trip odometer from SensorHub (recorded as pulses)

#define CAN_ERROR_MSG_ID            911     //message id for errors related to can bus comms, etc.

#define VSS_PULSE_PER_MILE          8000    //used to determine both speed and distance, Ford is typically 8000, GM is sometimes 4000 or 16000


#define MS_BASE_ID      1512  // set this to match the MegaSquirt setting, default is 1512
#define MSG_MS_BASE     0     // array index of allCanMessages[] to find the base id
#define MSG_MS_PLUS1    1     // array index 
#define MSG_MS_PLUS2    2     // etc...
#define MSG_MS_PLUS3    3     // ...
#define MSG_MS_PLUS4    4     // last element of array

#define SH_BASE_ID      600     // first can msg id used by AutoCAN_SensorHub
#define MSG_SH_BASE     0       //array index of TBD array to find the base id

char *epasModeDescriptions[] = { "Manual Steering", "Firm Steering",  "Sport+ Steering", "Sport Steering", "Touring Steering", "Comfort Steering"};


typedef struct {
    uint16_t messageID;
    int16_t contentID;
    char* messageText;  //try to stay <= 16 chars to fit on single line of display
} canSystemMessage;

//generated by any AutoCAN module
const canSystemMessage canRxError =         {CAN_ERROR_MSG_ID, 100, "CAN RX ERROR"};
const canSystemMessage canNodeOffline =     {CAN_ERROR_MSG_ID, 105, "CAN NODE OFFLINE"};

//generated by AutoCAN_Epasuino
const canSystemMessage canEpas1 =           {CAN_EPAS_MSG_ID, 0, epasModeDescriptions[0]};
const canSystemMessage canEpas2 =           {CAN_EPAS_MSG_ID, 1, epasModeDescriptions[1]};
const canSystemMessage canEpas3 =           {CAN_EPAS_MSG_ID, 2, epasModeDescriptions[2]};
const canSystemMessage canEpas4 =           {CAN_EPAS_MSG_ID, 3, epasModeDescriptions[3]};
const canSystemMessage canEpas5 =           {CAN_EPAS_MSG_ID, 4, epasModeDescriptions[4]};
const canSystemMessage canEpas6 =           {CAN_EPAS_MSG_ID, 5, epasModeDescriptions[5]};



//generated by AutoCAN_SensorHub
canSystemMessage canSPD =                   {CAN_SH_VSS_MSG_ID, -1, "SPD"};
canSystemMessage canTRP =                   {CAN_SH_TRP_MSG_ID, -1, "TRP"};

//simple engine sensor range errors
const canSystemMessage canErrCLTLow =       {CAN_ENGINE_ERROR_MSG_ID, 5, "CLT LOW"};
const canSystemMessage canErrCLTHigh =      {CAN_ENGINE_ERROR_MSG_ID, 10, "CLT HIGH"};
const canSystemMessage canErrIATLow =       {CAN_ENGINE_ERROR_MSG_ID, 15, "IAT LOW"};
const canSystemMessage canErrIATHigh =      {CAN_ENGINE_ERROR_MSG_ID, 20, "IAT HIGH"};
const canSystemMessage canErrMAPLow =       {CAN_ENGINE_ERROR_MSG_ID, 25, "MAP LOW"};
const canSystemMessage canErrMAPHigh =      {CAN_ENGINE_ERROR_MSG_ID, 30, "MAP HIGH"};
const canSystemMessage canErrRPMLow =       {CAN_ENGINE_ERROR_MSG_ID, 35, "RPM LOW"};
const canSystemMessage canErrRPMHigh =      {CAN_ENGINE_ERROR_MSG_ID, 40, "RPM HIGH"};
const canSystemMessage canErrAFRLean =      {CAN_ENGINE_ERROR_MSG_ID, 45, "AFR LEAN"};
const canSystemMessage canErrAFRRich =      {CAN_ENGINE_ERROR_MSG_ID, 50, "AFR RICH"};
const canSystemMessage canErrBatLow =       {CAN_ENGINE_ERROR_MSG_ID, 55, "BAT LOW"};
const canSystemMessage canErrBatHigh =      {CAN_ENGINE_ERROR_MSG_ID, 60, "BAT HIGH"};
const canSystemMessage canTPSLow =          {CAN_ENGINE_ERROR_MSG_ID, 65, "TPS LOW"};
const canSystemMessage canTPSHigh =         {CAN_ENGINE_ERROR_MSG_ID, 70, "TPS HIGH"};

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

struct EngineVariable
{
  char* shortLabel;
  float currentValue;
  float previousValue;
  float minimum;
  float maximum;
  byte decimalPlaces;
  unsigned long goodCount;
  unsigned long lowCount;
  unsigned long highCount;
  unsigned long canCounter;
};
const byte ENGINE_VARIABLE_COUNT = 20;
EngineVariable* allGauges[ENGINE_VARIABLE_COUNT];
                            //label, current, previous, min, max, decimal, good, low, high, can
EngineVariable engine_map   = {"MAP", 0.0, 0.0, 15.0, 250.0, 1, 0, 0, 0, 0};        //manifold absolute pressure
EngineVariable engine_rpm   = {"RPM", 0.0, 0.0, 700.0, 6000.0, 0, 0, 0, 0, 0};      //engine rpm
EngineVariable engine_clt   = {"CLT", 0.0, 0.0, 20.0, 240.0, 0, 0, 0, 0, 0};        //coolant temp
EngineVariable engine_tps   = {"TPS", 0.0, 0.0, 0.0, 100.0, 0, 0, 0, 0, 0};         //throttle position
EngineVariable engine_pw1   = {"PW1", 0.0, 0.0, 0.0, 20.0, 2, 0, 0, 0, 0};          //injector pulse width bank 1
EngineVariable engine_pw2   = {"PW2", 0.0, 0.0, 0.0, 20.0, 2, 0, 0, 0, 0};          //injector pulse width bank 2
EngineVariable engine_iat   = {"IAT", 0.0, 0.0, 40.0, 150.0, 0, 0, 0, 0, 0};        //intake air temp aka 'mat'
EngineVariable engine_adv   = {"ADV", 0.0, 0.0, 10.0, 40.0, 1, 0, 0, 0, 0};         //ignition advance
EngineVariable engine_tgt   = {"TGT", 0.0, 0.0, 10.0, 20.0, 1, 0, 0, 0, 0};         //afr target
EngineVariable engine_afr   = {"AFR", 0.0, 0.0, 10.0, 20.0, 1, 0, 0, 0, 0};         //air fuel ratio
EngineVariable engine_ego   = {"EGO", 0.0, 0.0, 70.0, 130.0, 0, 0, 0, 0, 0};        //ego correction %
EngineVariable engine_egt   = {"EGT", 0.0, 0.0, 0.0, 2000.0, 0, 0, 0, 0, 0};        //exhaust gas temp
EngineVariable engine_pws   = {"PWS", 0.0, 0.0, 0.0, 20.0, 2, 0, 0, 0, 0};          //injector pulse width sequential
EngineVariable engine_bat   = {"BAT", 0.0, 0.0, 11.0, 15.0, 1, 0, 0, 0, 0};         //battery voltage
EngineVariable engine_sr1   = {"SR1", 0.0, 0.0, 0.0, 999.0, 1, 0, 0, 0, 0};         //generic sensor 1
EngineVariable engine_sr2   = {"SR2", 0.0, 0.0, 0.0, 999.0, 1, 0, 0, 0, 0};         //generic sensor 2
EngineVariable engine_knk   = {"KNK", 0.0, 0.0, 0.0, 50.0, 1, 0, 0, 0, 0};          //knock ignition retard
EngineVariable engine_vss   = {"VSS", 0.0, 0.0, 0.0, 140.0, 0, 0, 0, 0, 0};         //vehicle speed
EngineVariable engine_tcr   = {"TCR", 0.0, 0.0, 0.0, 50.0, 1, 0, 0, 0, 0};          //traction control ignition retard
EngineVariable engine_lct   = {"LCT", 0.0, 0.0, 0.0, 50.0, 1, 0, 0, 0, 0};          //launch control timing
//variables added from SensorHub instead of MegaSquirt:
EngineVariable engine_spd   = {"SPD", 0.0, 0.0, 0.0, 140.0, 0, 0, 0, 0, 0};         //vehicle speed from SensorHub
EngineVariable engine_trp   = {"TRP", 0.0, 0.0, 0.0, 16000000.0, 0, 0 ,0, 0, 0};    //trip odometer, expressed in vss pulses