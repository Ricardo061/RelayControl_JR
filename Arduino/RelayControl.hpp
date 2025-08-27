/* =======================================================================================================
 *
 * Biblioteca Desenvolvida para controle de Relés
 * Arquivo Classe RelayControl .hpp
 * Author: Joao Ricardo Chaves
 * Date: 05/06/25
 * 
 * ======================================================================================================= */ 

// ============================================
// --- Pre-processing directives ---
#ifndef RELAYCONTROL_HPP
#define RELAYCONTROL_HPP 

// ============================================
// --- Libraries ---
#include <stdlib.h>

// ============================================
// --- typdef ---
typedef void (*pinOut_t)(const short pin, const bool Status); // Ponteiro para função responsável por definir o nível lógico de um pino (ex: digitalWrite)
typedef void (*wait_t)(const unsigned int ms);                // Ponteiro para função de espera/delay, com tempo especificado em milissegundos

// ============================================
// --- Class ---

class RelayControl
{
    public:
        RelayControl(const short pin, const bool StatusOn);   // Construtor: define o pino de controle e o nível lógico necessário para ligar o relé

        void SetPinOut(pinOut_t callback);                    // Registra a função que define o nível lógico no pino do relé (ex: digitalWrite)
        void Wait(wait_t callback);                           // Registra a função de espera/delay (ex: delay)

        void ControlRelay(const bool Status);                 // Controla diretamente o estado do relé (liga/desliga)
        void RelayON();                                       // Liga o Relé
        void RelayOFF();                                      // Desliga o Relé
        void ToggleRelay();                                   // Inverte o estado atual do relé

        void RelayTimer(unsigned ms = 500);                   // Liga o relé por um tempo definido (em ms), depois desliga
        void SetTime(unsigned msTime);                        // Define o tempo (em ms) usado pelo método RelayTimer()
        unsigned int GetTime() const;                         // Retorna o tempo configurado para o relé (em ms)
        
    private:
        const short int _Pin;                                 // Pino de controle do relé
        const bool _StatusOn;                                 // Nível lógico necessário para ligar o relé
        unsigned     _msTime;                                 // Tempo em milissegundos para controle temporizado
        bool         _Status;                                 // Estado atual do relé (true = ligado)

        pinOut_t pinOut = nullptr;                            // Ponteiro para função de escrita no pino
        wait_t  waiting = nullptr;                            // Ponteiro para função de espera/delay

        void InitOff();                                       // Inicializa o relé desligado

}; // end class





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