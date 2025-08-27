/* =======================================================================================================
 *
 * Arquivo .cpp
 * RelayControl
 * Author: Joao Ricardo Chaves
 * Date: 30/05/25
 * 
 * ======================================================================================================= */ 

// ============================================
// --- Libraries ---
#include "RelayControl.hpp"

// ============================================
// --- Functions ---

// ============================================
// --- Constructor --- 
RelayControl::RelayControl(const short int pin, const bool StatusOn):
_Pin(pin), _StatusOn(StatusOn), _msTime(500)
{

}// end Constructor

// ============================================
// --- pinOUT --- 
void RelayControl::SetPinOut(pinOut_t callback)
{
  pinOut = callback;
  InitOff();
}// end pinOut

// ============================================
// --- Wait ---
void RelayControl::Wait(wait_t callback)
{
  waiting = callback;
}// end Wait


// ============================================
// --- ControlRelay ---
void RelayControl::ControlRelay(const bool Status)
{
  bool StatusTemp;
  
  StatusTemp = Status ^ (!_StatusOn);
  _Status = StatusTemp;

  if(pinOut != NULL)
    pinOut(_Pin,_Status);

}//end ControlRelay

// ============================================
// --- RelayON ---
void RelayControl::RelayON()
{
  _Status = _StatusOn;
  if(pinOut != NULL)
    pinOut(_Pin,_Status);
}// end RelayON

// ============================================
// --- RelayOFF ---
void RelayControl::RelayOFF()
{
  _Status = !_StatusOn;
  if(pinOut != NULL)
    pinOut(_Pin,!_StatusOn);
}// end RelayOFF

// ============================================
// --- ToggleRelay ---
void RelayControl::ToggleRelay()
{
  _Status = !_StatusOn;
  if(pinOut != NULL)
    pinOut(_Pin,_Status);
}// end ToggleRelay

// ============================================
// --- RelayTimer ---
void RelayControl::RelayTimer(unsigned ms)
{
  _msTime = ms;
  RelayON();

  if(waiting!=NULL)
    waiting(_msTime);

  RelayOFF();

  if(waiting!=NULL)
    waiting(_msTime);
}// end RelayTimer

// ============================================
// --- SetTime --- 
void RelayControl::SetTime(unsigned msTime)
{
  _msTime = msTime;
}// end SetTime

// ============================================
// --- GetTime ---
unsigned int RelayControl::GetTime() const
{
  return _msTime;
}// end GetTime

// ============================================
// --- InitOff ---
void RelayControl::InitOff()
{
  if(pinOut != NULL)
    pinOut (_Pin,!_StatusOn);
}// end InitOff


// ================================
// --- End Of File ---

//=======================================================================================================
//
//     ██╗██████╗     ███████╗██╗     ███████╗ ██████╗████████╗██████╗  ██████╗ ███╗   ██╗██╗ ██████╗
//     ██║██╔══██╗    ██╔════╝██║     ██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗████╗  ██║██║██╔════╝
//     ██║██████╔╝    █████╗  ██║     █████╗  ██║        ██║   ██████╔╝██║   ██║██╔██╗ ██║██║██║     
//██   ██║██╔══██╗    ██╔══╝  ██║     ██╔══╝  ██║        ██║   ██╔══██╗██║   ██║██║╚██╗██║██║██║     
//╚█████╔╝██║  ██║    ███████╗███████╗███████╗╚██████╗   ██║   ██║  ██║╚██████╔╝██║ ╚████║██║╚██████╗
// ╚════╝ ╚═╝  ╚═╝    ╚══════╝╚══════╝╚══════╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝ ╚═════╝
//                                                                                                 
//=======================================================================================================