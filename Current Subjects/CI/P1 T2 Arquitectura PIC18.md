# Tema 2: Arquitectura del Microcontrolador PIC18

> [!abstract] Resum del Tema En aquest tema s'estudia en profunditat l'arquitectura interna de la família de microcontroladors **PIC18** (concretament el model **PIC18F45K22**): la seva estructura de busos Harvard, l'organització de la memòria de programa (FLASH) i de dades (SRAM/GPR/SFR), la memòria EEPROM, els registres de control (BSR, STATUS, WREG), el conjunt d'instruccions, els modes d'adreçament, el concepte de _pipelining_ i exemples de programació en assemblador.

---

## 2.1 El Dispositiu PIC18F45K22

> [!info] Característiques Físiques i Internes
> 
> - **Encapçalat físic:** Dispositiu de 40 pins PDIP (_Plastic Dual In-line Package_).
> - **Pins principals:**
>     - Alimentació: $V_{DD}$ (voltatge d'alimentació positiu) i $V_{SS}$ (massa / terra).
>     - Reset / Programació: $\overline{MCLR}/V_{PP}/RE3$.
>     - Ports d'Entrada/Sortida: Multiplexats en 5 ports digitals (PORTA, PORTB, PORTC, PORTD, PORTE).
> - **Integració Total:** Com a microcontrolador, inclou el nucli de la CPU, la memòria de programa, la memòria de dades, els perifèrics i la lògica de control dins del mateix xip.

> [!example] Arquitectura de Busos (Harvard) i Mides de Memòria
> 
> - **Arquitectura Harvard:** Disposa de busos físicament separats per a la memòria de programa i la memòria de dades.
> - **Memòria de Programa (FLASH):**
>     - Bus d'adreces de $21\text{ bits}$.
>     - Bus d'instruccions de $16\text{ bits}$ d'amplada.
>     - Capacitat interna: $32\text{ KB}$ integrats al xip (d'un màxim teòric d'adreçament de $2\text{ MB}$).
> - **Memòria de Dades (SRAM):**
>     - Bus d'adreces de $12\text{ bits}$.
>     - Bus de dades de $8\text{ bits}$ d'amplada.
>     - Capacitat interna: $1536\text{ bytes}$ ($1.5\text{ KB}$) de SRAM integrats (d'un màxim teòric de $4096\text{ bytes}$).
> - **Memòria EEPROM:** $256\text{ bytes}$ de memòria no volàtil reescrivible per a paràmetres de l'aplicació o de l'usuari.

> [!gear] Unitat de Procés (CPU / ALU)
> 
> - **ALU:** Unitat Aritmètic-Lògica de $8\text{ bits}$.
> - **WREG (_Working Register_):** Registre d'acumulador de $8\text{ bits}$ situat al costat de l'ALU i utilitzat com a operand o destí en la majoria d'instruccions.
> - **Multiplicador per Maquinari:** Inclou un multiplicador de $8 \times 8\text{ bits}$ per maquinari que diposita el resultat de 16 bits en els registres dedicats `PRODH:PRODL`.
> - **Pila de Retorn (_Stack_):** Pila interna de 31 nivells de profunditat per emmagatzemar les adreces de retorn de subrutines, gestionada pel registre `STKPTR`.

---

## 2.2 Organització de la Memòria de Programa

> [!cite] Adreçament i Alineació d'Instruccions
> 
> - **Adreçament en Bytes:** La memòria de programa s'adreça per bytes, tot i que les instruccions ocupen $2\text{ bytes}$ ($1\text{ paraula}$) o $4\text{ bytes}$ $(2\text{ paraules})$.
> - **Program Counter (PC):** Té una longitud de 21\text{ bits}, permetent adreçar fins a \(2\text{ MB}\) (\(2^{21}\text{ bytes}\)).
> - **Alineació Parell:** El bit menys significatiu (LSb) de l'adreça d'una instrucció sempre és parell (\(\text{LSb} = 0\)). Per tant, el PC incrementa de 2 en 2 (o de 4 en 4).
> - **Límits de Memòria:** En el PIC18F45K22, la memòria integrada ocupa des de l'adreça `00000h` fins a `07FFFh` (\(32\text{ KB}\)). Si s'intenta llegir una posició superior no implementada (fins a `1FFFFFh`), el maquinari retorneu sempre zeros (`0`).

> [!tip] Vectors de la Memòria de Programa | Adreça Hex | Funció / Destí | | :--- | :--- | | `00000h` | **Reset Vector:** Adreça d'inici de la CPU en encendre o reiniciar. | | `00008h` | **High-Priority Interrupt Vector:** Vector d'interrupció d'alta prioritat. | | `00018h` | **Low-Priority Interrupt Vector:** Vector d'interrupció de baixa prioritat. |

> [!warning] Instruccions de Dues Paraules (4 Bytes) La majoria d'instruccions ocupen \(16\text{ bits}\) (\(1\text{ paraula}\)), però existeixen 4 instruccions que n'ocupen dues (\(32\text{ bits}\)): `CALL`, `MOVFF`, `GOTO` i `LFSR`.
> 
> - La segona paraula d'aquestes instruccions sempre conté els 4 bits més significatius (MSb) iguals a `1111`.
> - Si la primera paraula de la instrucció es salta (per exemple, per una condició de salt) i s'executa la segona paraula aïlladament, la CPU la descodifica i executa automàticament com una instrucció `NOP` (_No Operation_).

---

## 2.3 Organització de la Memòria de Dades

La memòria de dades està implementada en SRAM i conté dos tipus de registres:

1. **GPR (_General Purpose Registers_):** Registres de propòsit general utilitzats per guardar variables dinàmiques de l'usuari.
2. **SFR (_Special Function Registers_):** Registres de funció especial utilitzats per controlar el funcionament dels perifèrics i de la CPU.

> [!info] Divisió en Bancs i Registre BSR Com que les instruccions utilitzen \(8\text{ bits}\) per especificar un registre de dades (\(2^8 = 256\text{ posicions}\)), la memòria de dades de \(12\text{ bits}\) (\(4096\text{ bytes}\)) es divideix en **16 bancs** de \(256\text{ bytes}\) cada un.
> 
> - **BSR (_Bank Select Register_):** Proporciona els \(4\text{ bits}\) superiors (\(b<3:0>\)) de l'adreça de dades de 12 bits.
> - Es pot carregar directament el BSR mitjançant la instrucció `MOVLB k`.
> - En el PIC18F45K22 hi ha **7 bancs implementats**:
>     - 6 bancs de GPR (Bank 0 a Bank 5 = \(6 \times 256\text{ B} = 1536\text{ B} = 1.5\text{ KB}\)).
>     - 1 banc de SFR (Bank 15: des de `F38h` fins a `FFFh`, dels quals 200 B estan integrats).

```
Estructura de l'Adreça de Dades (12 bits):
[  BSR (4 bits)  ] + [ Campo f de la Instrucció (8 bits) ] = 12 bits d'adreça de RAM
```

> [!summary] Banked Mode vs. Access Bank
> 
> - **Banked Mode (\(\text{a} = 1\)):** L'adreça s'obté combinant el registre BSR i els 8 bits de la instrucció. Canviar de banc requereix actualitzar el BSR (_bank switching overhead_).
> - **Access Bank (\(\text{a} = 0\)):** Estructura especial de \(256\text{ bytes}\) dissenyada per evitar el canvi de bancs. Es crea combinant:
>     - Els 96 bytes inferiors del Bank 0 (`00h` a `5Fh` - GPR).
>     - Els 160 bytes superiors del Bank 15 (`60h` a `FFh`, corresponents a `F60h` a `FFFh` - SFR).

> [!note] Paràmetres `a` i `d` en les Instruccions
> 
> - **Paràmetre `a` (_Access bit_):**
>     - \(a = 0\): Força l'ús de l'**Access Bank** (s'ignora el valor del BSR).
>     - \(a = 1\): S'utilitza el banc seleccionat pel registre **BSR**.
> - **Paràmetre `d` (_Destination bit_):**
>     - \(d = 0\): El resultat de l'operació es guarda al registre de treball **WREG**.
>     - \(d = 1\): El resultat de l'operació es guarda al propi registre de fitxer **f**.

> [!check] Registre STATUS Registre d'estat de \(8\text{ bits}\) que conté els _flags_ de resultat de les operacions executades a l'ALU:
> 
> - **Bit 4 - `N` (_Negative_):** Vale \(1\) si el resultat de l'operació és negatiu en complement a 2.
> - **Bit 3 - `OV` (_Overflow_):** Vale \(1\) si s'ha produït un desbordament en aritmètica amb signe.
> - **Bit 2 - `Z` (_Zero_):** Vale \(1\) si el resultat de l'operació és igual a zero.
> - **Bit 1 - `DC` (_Digit Carry / Borrow_):** Vale \(1\) si hi ha hagut un acoblament des del bit 3 cap al bit 4.
> - **Bit 0 - `C` (_Carry / Borrow_):** Vale \(1\) si hi ha hagut un acoblament des del bit 7 (MSb).

---

## 2.4 Conjunt d'Instruccions (Instruction Set)

El PIC18 disposa de **75 instruccions estàndard** (83 si s'activa el conjunt estès). Aquestes es classifiquen en 5 tipus segons la seva codificació:

1. **Operacions d'Orientació a Byte (_Byte-oriented_):** `opcode d a f` (ex. `ADDWF f, d, a`, `MOVWF f, a`, `CLRF f, a`, `INCF f, d, a`).
2. **Operacions d'Orientació a Bit (_Bit-oriented_):** `opcode b a f` (ex. `BSF f, b, a`, `BCF f, b, a`, `BTFSS f, b, a`).
3. **Operacions amb Literals (_Literal operations_):** `opcode k` (ex. `MOVLW k`, `ADDLW k`, `MOVLB k`).
4. **Operacions de Control (_Control operations_):** Manteniment i modificació del flux d'execució (ex. `GOTO label`, `CALL label`, `BRA label`, `BC`, `BZ`, `RETFIE`, `RETURN`).
5. **Moviment Byte a Byte de 2 Paraules:** `MOVFF f_source, f_destination` (mou dades directament entre dues adreces qualsevol de 12 bits de la RAM).

> [!info] Operacions Memòria de Dades \(\leftrightarrow\) Memòria de Programa Les instruccions de taula permeten llegir o escriure a la FLASH des de l'execució del programa:
> 
> - `TBLRD*`, `TBLRD*+`, `TBLRD*-`, `TBLRD+*` (Lectura de taula amb opcions de pre/post increment o decrement del punter `TBLPTR`).
> - `TBLWT*`, `TBLWT*+`, `TBLWT*-`, `TBLWT+*` (Escriptura de taula).

---

## 2.5 Modes d'Adreçament (Addressing Modes)

El PIC18 disposa de **4 modes d'adreçament principals**:

> [!cite] 1. Inherent La instrucció no requereix cap argument explícit a l'opcode. Exemple: `sleep`, `reset`, `nop`.

> [!cite] 2. Literal La instrucció inclou una constant o valor immediat directament en la seva codificació. Exemple: `movlw 0x30` (carrega el valor hexadecimal `0x30` a WREG).

> [!cite] 3. Directe Especifica l'adreça de 8 bits del registre \(f\), combinada amb els bits de control \(d\) (destí) i \(a\) (selecció de banc: Access Bank o BSR). Exemple: `movf 0x20, d, a`.

> [!cite] 4. Indirecte (Puntermètric amb FSR) Accedeix a la memòria sense donar una adreça fixa a la instrucció, utilitzant registres de punter de \(12\text{ bits}\) anomenats **FSR** (_File Select Registers_: FSR0, FSR1 i FSR2).
> 
> - Cada FSR està format per dos registres de 8 bits: `FSRxH` (\(4\text{ bits}\) superiors) i `FSRxL` (\(8\text{ bits}\) inferiors).
> - **Operands Indirectes amb Auto-modificació:**
>     - `INDFx`: Accés indirecte a la posició apuntada per FSRx.
>     - `POSTDECx`: Accedeix a la posició apuntada i posteriorment decrementa FSRx.
>     - `POSTINCx`: Accedeix a la posició apuntada i posteriorment incrementa FSRx.
>     - `PREINCx`: Incrementa FSRx primer i posteriorment accedeix a la nova posició.
>     - `PLUSWx`: Accedeix a la posició de memòria resultat de sumar `FSRx + WREG` (sense modificar el valor contingut a FSRx).

---

## 2.6 Pipelining i Temps d'Execució

> [!example] Canonada d'Execució (Pipelining) El PIC18 divideix l'execució de les instruccions en **dues etapes**:
> 
> 1. **Fetch:** Cerca de la instrucció a la memòria de programa.
> 2. **Execute:** Execució de la instrucció descodificada.
> 
> Aquestes etapes es solapen en el temps (_pipelining_): mentre s'executa la instrucció \(N\), la CPU cerca simultàniament la instrucció \(N+1\). Gràcies a això, la majoria d'instruccions d'una sola paraula s'executen en **1 cicle d'instrucció** (\(T_{CY}\)).

> [!warning] Buit de la Canonada (_Flush_) Quan una instrucció modifica el Program Counter (salts incondicionals com `BRA`, `GOTO`, `CALL`, o salts condicionals positius com `INCFSZ`, `BTFSS`), la instrucció que s'havia cercat prèviament no és la correcta. En aquest cas, la CPU la descarta i força un cicle de `NOP` (_Flush_). Per tant, les instruccions de salt requereixen **2 cicles d'instrucció**.

> [!gear] Gestió del Program Counter (PC) El Program Counter té \(21\text{ bits}\) dividits en tres registres:
> 
> - `PCL` (bits \(7:0\)): Accessible directament per lectura i escriptura.
> - `PCH` (bits \(15:8\)) i `PCU` (bits \(20:16\)): **No accessibles directament**.
> - Per llegir o escriure en `PCH` i `PCU` s'utilitzen els registres de tancament (_latch_) **`PCLATH`** i **`PCLATU`**:
>     - En llegir `PCL`, el maquinari copia automàticament els valors de `PCH` i `PCU` cap a `PCLATH` i `PCLATU`.
>     - En escriure a `PCL`, el maquinari escriu simultàniament els valors continguts a `PCLATH` i `PCLATU` cap a `PCH` i `PCU`, garantint un canvi d'adreça atòmic de 21 bits.

---

## 2.7 Consells i Exemples de Programació en Assemblador

> [!info] Convencions de Codi (MPASM)
> 
> - **Majúscules vs. Minúscules:** L'ensamblador permet escriure instruccions en qualsevol cas. La convenció oficial utilitzada és: instruccions i directives en **minúscula**, i registres SFR i bits en **MAJÚSCULA**.
> - Fitxer de capçalera: S'ha d'incloure el fitxer `#include <p18F45K22.inc>` per importar les definicions dels registres i bits del processador.

> [!summary] Directives Principals de l'Ensamblador
> 
> - `#define <nom> <cadena>`: Defineix una substitució de text.
> - `#include <fitxer>`: Inclou el contingut d'un altre fitxer de codi.
> - `ORG <expressió>`: Estableix l'origen o direcció d'inici del codi a la memòria de programa (ex. `ORG 0x00`).
> - `EQU` / `SET`: Assignació de constants o adreces de variables.
> - `RADIX DEC`: Estableix la base numèrica per defecte a decimal.
> - `END`: Indica el final del fitxer font d'assemblador.

---

### Exemples Pràctics de Codi Assemblador

#### Exemple 1: Suma de 3 posicions de memòria

Programa que suma els tres nombres continguts a les adreces de RAM `0x20`, `0x30` i `0x40`, i diposita el resultat a la posició `0x50`:

```
#include <p18F45K22.inc>

org 0x00            ; Vector de Reset
goto start
org 0x08            ; Vector d'interrupció d'alta prioritat
retfie
org 0x18            ; Vector d'interrupció de baixa prioritat
retfie

start:
    movf  0x20, W, A  ; WREG <- [0x20]
    addwf 0x30, W, A  ; WREG <- [0x20] + [0x30]
    addwf 0x40, W, A  ; WREG <- [0x20] + [0x30] + [0x40]
    movwf 0x50, A     ; [0x50] <- sum (WREG)
end
```

---

#### Exemple 3: Bucle de suma acumulada \(\sum_{i=1}^{n} i\) (amb \(n = 50\))

Programa per calcular \(1 + 2 + 3 + \dots + n\) utilitzant un resultat de 16 bits (`sum_hi` i `sum_lo`) per evitar el desbordament:

```
#include <p18F45K22.inc>
radix dec

n      equ D'50'
sum_hi set 0x01      ; Byte alt del resultat
sum_lo set 0x00      ; Byte baix del resultat
i      set 0x02      ; Índex de bucle i

org 0x00
goto start
org 0x08
retfie
org 0x18
retfie

start:
    clrf sum_hi, A   ; Inicialitza sum_hi = 0
    clrf sum_lo, A   ; Inicialitza sum_lo = 0
    clrf i, A        ; Inicialitza i = 0
    incf i, F, A     ; i comença en 1

sum_lp:
    movlw n          ; Carrega n a WREG
    cpfsgt i, A      ; Compara i amb n, salta si i > n
    bra add_lp       ; Executa la suma si i <= 50
    bra exit_sum     ; Finalitza si i > 50

add_lp:
    movf i, W, A     ; WREG <- i
    addwf sum_lo, F, A ; sum_lo <- sum_lo + i
    movlw 0
    addwfc sum_hi, F, A ; sum_hi <- sum_hi + 0 + Carry
    incf i, F, A     ; Incrementa l'índex i en 1
    bra sum_lp

exit_sum:
    nop
    bra exit_sum
end
```

---

#### Exemple 4: Bucle de retard (\(1\text{ ms}\) a \(40\text{ MHz}\))

Generació d'un retard temporal mitjançant bucles niats de decrementació:

```
#include <p18F45K22.inc>

lp_cnt0 equ 0x20
lp_cnt1 equ 0x21
lp_cnt2 equ 0x22

    movlw D'10'
    movwf lp_cnt0, A
loop0:
    movlw D'200'
    movwf lp_cnt1, A
loop1:
    movlw D'250'
    movwf lp_cnt2, A
loop2:
    nop              ; 1 cicle d'instrucció
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    nop              ; 1 cicle
    decfsz lp_cnt2, F, A ; 1 cicle (2 quan lp_cnt2 = 0)
    goto loop2           ; 2 cicles
    decfsz lp_cnt1, F, A
    goto loop1
    decfsz lp_cnt0, F, A
    goto loop0
```
