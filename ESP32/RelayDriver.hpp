/* =======================================================================================================
 *
 * Arquivo RelayDriver.hpp
 * Author: Joao Ricardo Chaves
 * Date: 05/06/25
 * 
 * ======================================================================================================= */ 
 
#ifndef RELAYDRIVER_HPP
#define RELAYDRIVER_HPP

// ============================================
// --- Libraries ---
#include <Arduino.h>

// ============================================
// --- Mapping Hardware ---
#define RL 26

// ============================================
// ---  Functions ---

// ============================================
// ---  SetPin ---
/**
 * @brief Define o nível lógico de um pino digital.
 * 
 * Esta função é usada como callback na classe RelayControl para acionar/desligar o relé.
 * 
 * @param pin Pino digital a ser controlado
 * @param State Nível lógico desejado (true = HIGH, false = LOW)
 */
void SetPin(const short pin, const bool State)
{
  digitalWrite(pin,State);
}//end SetPin

// ============================================
// ---  WaitFor ---
/**
 * @brief Aguarda por um tempo especificado em milissegundos.
 * 
 * Esta função encapsula a função delay() do Arduino, e pode ser usada como callback para controle de tempo.
 * 
 * @param ms Tempo de espera em milissegundos
 */
void WaitFor(const unsigned ms)
{
  for(int i = 0; i < ms; i++)
    vTaskDelay(1/portTICK_PERIOD_MS);
}//end WaitFor





#endif

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