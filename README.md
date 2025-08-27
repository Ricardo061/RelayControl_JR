# 🔌 Controle de Relés  

Bibliotecas desenvolvidas para facilitar o **controle de relés** em projetos embarcados, compatíveis com:  
- **Arduino**  
- **MCUs da família ATmega**  
- **ESP32**  

## 📖 Sobre o projeto  
Este repositório contém bibliotecas em C/C++ criadas para simplificar a integração e o acionamento de relés em sistemas embarcados.  
O objetivo é oferecer uma interface clara, modular e reutilizável, reduzindo a complexidade no desenvolvimento de aplicações.  

## ⚡ Funcionalidades  
- Controle simples de relés digitais  
- Suporte a múltiplos relés  
- Compatível com Arduino, ATmega e ESP32  
- Código modular e reutilizável  

## 🛠️ Tecnologias  
- **C/C++**  
- **Arduino IDE**

---

## ⚙️ Funções disponíveis na classe `RelayControl`  

| Função | Descrição |
|--------|-----------|
| `RelayControl(const short pin, const bool StatusOn)` | Construtor: define o pino de controle e o nível lógico necessário para ligar o relé |
| `void SetPinOut(pinOut_t callback)` | Registra a função que define o nível lógico no pino do relé (ex: `digitalWrite`) |
| `void Wait(wait_t callback)` | Registra a função de espera/delay (ex: `delay`) |
| `void ControlRelay(const bool Status)` | Controla diretamente o estado do relé (liga/desliga) |
| `void RelayON()` | Liga o relé |
| `void RelayOFF()` | Desliga o relé |
| `void ToggleRelay()` | Inverte o estado atual do relé |
| `void RelayTimer(unsigned ms = 500)` | Liga o relé por um tempo definido (em ms) e depois desliga |
| `void SetTime(unsigned msTime)` | Define o tempo (em ms) usado pelo método `RelayTimer()` |
| `unsigned int GetTime() const` | Retorna o tempo configurado para o relé (em ms) |

---


```c
/* =======================================================================================================
 *
 * Arquivo principal .ino
 * 
 * RelayControl - Controle de Reles
 * 
 * Author: Joao Ricardo Chaves
 * Date: 05/06/25
 * 
 * ======================================================================================================= */ 

// ================================
// --- Libraries ---
#include "RelayControl.hpp"
#include "RelayDriver.hpp"

// ======================================
// --- Macros/Constants and Objects ---
RelayControl Relay1(RL, false);  // Relay aciona com False

// ================================
// --- Function Prototypes ---

// ================================
// --- Setup ---
void setup() 
{
  pinMode(RL,OUTPUT);
  Relay1.SetPinOut(SetPin);
  Relay1.Wait(WaitFor);
}// end Setup

// ================================
// --- Loop ---
void loop() 
{
  //Relay1.RelayON();
  //Relay1.RelayTimer(400);
}// end Loop


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

```
