#CI #PARCIAL1 
# Tema 1: Introducció i Arquitectures Bàsiques

> [!abstract] Resum del Tema Aquest primer tema estableix les bases de l'assignatura Interfícies amb l'Entorn (CI): la comparació entre microprocessadors i microcontroladors, les arquitectures de computadors (RISC/CISC, Harvard/Von Neumann), la gestió de registres d'E/S i espais de memòria (Memory-Mapped vs Isolated I/O), les tecnologies de memòria (RAM i ROM), la configuració del laboratori (PIC18F45K22, EasyPIC 7, Proteus) i les preguntes de reflexió de l'Entregable 1.

---

## 1.1 Coneixements Previs Esperats

> [!info] Prerequisits de l'Assignatura Per assolir les competències de CI es requereixen els següents coneixements:
> 
> - **Dispositius electrònics passius:** Resistències ($R$), condensadors ($C$) i inductàncies ($L$).
> - **Semiconductors:** Díodes, LED i transistors BJT i MOSFET.
> - **Anàlisi de circuits de corrent continu (DC):** Llei d'Ohm 
> ($V = I \cdot R$), així com el càlcul de voltatges ($V$), corrents ($I$) en amperes, ($A$) i potència ($P = V \cdot I$) en watts, ($W$).
> - **Programació:** Programació en llenguatge C.
> - **Documentació tècnica:** Comprensió de documentació tècnica en anglès, sent aquesta la competència transversal de l'assignatura.

---

## 1.2 Microprocessador vs. Microcontrolador

> [!note] Microprocessador És una CPU continguda en un únic xip. Els recursos principals del sistema com la memòria principal (RAM/ROM) o els perifèrics d'E/S no estan integrats al xip, sinó que es connecten mitjançant dispositius externs (com la placa base d'un PC).

> [!note] Microcontrolador (MCU) És un ordinador complet contingut en un únic xip que inclou el nucli del processador, la memòria i els perifèrics d'entrada/sortida programables. S'utilitza en sistemes encastats (_embedded systems_) com drons, automòbils i dispositius IoT (_Internet of Things_).
> 
> - **Mercat global de microcontroladors:** Estimat en $20.61\text{ milers de milions de USD}$ el 2022 i $22.73\text{ milers de milions de USD}$ el 2023.

---

## 1.3 Arquitectures de Computadors

### RISC vs. CISC

**Comparativa d'Arquitectures de Processador**

|**Característica**|**RISC (Reduced Instruction Set Computer)**|**CISC (Complex Instruction Set Computer)**|
|---|---|---|
|**Conjunt d'instruccions**|Conjunt d'instruccions simples|Conjunt d'instruccions complex|
|**Format d'instrucció**|Regular i de mida fixa|Irregular i de mida variable|
|**Execució d'instruccions**|Cablejades (wired), s'executen en un (1) o pocs cicles de rellotge|Microcodificades, requereixen múltiples cicles de rellotge|
|**Modes d'adreçament**|Modes d'adreçament simples|Modes d'adreçament complexos|
|**Accés a operands**|Majoritàriament operacions entre registres (register to register)|Operacions directes entre registres i memòria|
|**Registres a la CPU**|Gran quantitat de registres|Nombre més reduït de registres|
|**Memòria**|Memòries de dades i de programa separades (Harvard)|Memòria combinada per a dades i programa (Von Neumann)|
|**Disseny i depuració**|Temps de disseny i depuració més curts|Temps de disseny i depuració més llargs|
|**Mida del codi**|Instruccions simples que requereixen programes més llargs|Instruccions complexes que permeten programes més curts|


### Harvard vs. Von Neumann

> [!tip] Arquitectura Harvard Disposa de camins de senyal (busos d'adreces i dades) i espais d'emmagatzematge físicament separats per a les instruccions (Memòria de Programa) i per a les dades (Memòria de Dades). Permet accedir simultàniament a instruccions i dades.

> [!warning] Arquitectura Von Neumann Les instruccions i les dades s'emmagatzemen en la mateixa memòria compartida i es demanen mitjançant el mateix bus de dades. L'accés a instruccions i dades s'ha de multiplexar en el temps.

| Harvard Arch                         | Von Neumann Arch                     |
| ------------------------------------ | ------------------------------------ |
| ![[Pasted image 20260921105929.png]] | ![[Pasted image 20260921105949.png]] |

---

## 1.4 Registres d'E/S i Espai de Memòria

> [!cite] Interfícies i Ports
> 
> - Les interfícies del sistema o microcontrolador es programen mitjançant **registres** (de comanda, dades, estat, etc.).
> - Els registres de les interfícies digitals s'anomenen **PORTS**.
> - Tots els dispositius (teclats, pantalles, àudio) es gestionen mitjançant **interfícies**. En sistemes amb Sistema Operatiu, els _drivers_ amaguen aquestes interfícies als usuaris.

### Mapeig d'E/S en Memòria

Quan es comparteix el mateix bus d'adreces per a la memòria i per a les E/S, cal definir com el maquinari diferencia les lectures i escriptures de memòria respecte a les d'E/S:

> [!info] Memory-Mapped I/O (ex. Motorola)
> 
> - S'utilitza el mateix bus d'adreces tant per a la memòria com per a les E/S.
> - Qualsevol instrucció que llegeixi o escrigui a memòria pot accedir directament a un port d'E/S.
> - L'adreça especifica quin mòdul (RAM, ROM, entrada, sortida) es comunica amb el processador.
> - **Exemples d'instruccions en assemblador:**
>     - `LDAA $200A` _(Carrega el valor de l'adreça `$200A`)_
>     - `STAA $0024` _(Escriu el valor a l'adreça de port `$0024`)_

> [!info] Isolated I/O / Port-Mapped I/O (ex. Intel)
> 
> - Els senyals del bus de control que activen les E/S estan separats dels que activen la memòria.
> - Aquests sistemes tenen un espai d'adreçament independent per a les E/S.
> - Es requereixen instruccions específiques per accedir als ports d'E/S i a la memòria.
> - **Exemples d'instruccions en assemblador:**
>     - `IN AL, $10` _(Llegeix del port `$10`)_
>     - `MOV $200A, AL` _(Escriu el valor a l'adreça de RAM `$200A`)_

---

## 1.5 Tecnologies de Memòria

> [!summary] Classificació General
> 
> - **Volàtil:** Perd la informació emmagatzemada quan es talla l'alimentació elèctrica (ex. RAM, memòria de lectura i escriptura).
> - **No volàtil:** Manté la informació emmagatzemada quan es desconnecta l'alimentació (ex. ROM, memòria de només lectura per al processador).

### Tipus de Memòria RAM (Volàtil)

> [!info] DRAM (_Dynamic RAM_)
> 
> - Basada en tecnologia de condensadors.
> - Requereix un refresc periòdic de les dades.
> - Oferix grans capacitats (ex. $8\text{ GB}$, $32\text{ GB})$.
> - Utilitzada com a memòria principal en PC.

> [!info] SRAM (_Static RAM_)
> 
> - Basada en tecnologia de transistors.
> - No requereix refresc periòdic.
> - Consumeix més energia.
> - Ràpida i simple d'operar.
> - Capacitats més petites (de $\text{KB}$ a $\text{MB}$).
> - Utilitzada com a memòria de microcontroladors, registres de la CPU i memòries cau.

### Tipus de Memòria ROM / No Volàtil

> [!check] MROM (_Mask-programmed ROM_) Programada directament durant el procés de fabricació del xip.

> [!check] PROM (_Programmable ROM_) Programable una sola vegada per l'usuari final (OTP - _One Time Programmable_).

> [!check] EEPROM (_Electrically Erasable Programmable ROM_)
> 
> - Programable i esborrable elèctricament moltes vegades.
> - Esborrat granular: permet esborrar una posició individual (byte), una fila o tot el xip en una sola operació.

> [!check] Memòria Flash (ex. USB, discos SSD)
> 
> - Programable i esborrable elèctricament moltes vegades.
> - A diferència de l'EEPROM, només es pot esborrar en blocs (sectors) o el xip sencer.

---

## 1.6 Ús de Microcontroladors i Entorn de Treball de CI

> [!gear] Entorn de Pràctiques de CI (_Setup_) L'assignatura es basa en dispositius de l'empresa **Microchip Technology** (líder industrial amb \(8.3\text{ milers de milions de USD}\) en vendes el 2023 i \(22.500\) empleats):
> 
> 1. **PIC18F45K22:** Microcontrolador objecte d'estudi.
>     - Arquitectura **RISC** i **Harvard**.
>     - Registres d'E/S mapejats en memòria (_Memory-mapped I/O_).
>     - Memòria **FLASH** per emmagatzemar el programa/codi.
>     - Memòria **EEPROM** per a configuracions de l'usuari i de l'aplicació.
>     - Memòria **SRAM** per als registres i la RAM de dades.
> 2. **Mikroe EasyPIC 7:** Placa de desenvolupament utilitzada als laboratoris.
> 3. **Proteus:** Programari de simulació de maquinari i codi.

---

## 1.7 Preguntes de Reflexió del Tema 1 (Entregable Nº 1)

> [!question] Q1: Un microcontrolador amb l'entrada/sortida mapejada en la memòria RAM serà més aviat RISC o CISC? **Resposta:** Més aviat **RISC**. Les arquitectures RISC afavoreixen el mapeig d'E/S en memòria (_Memory-Mapped I/O_), ja que permet utilitzar el mateix conjunt d'instruccions d'accés a memòria (`MOV`, `LOAD`, `STORE`) tant per a variables de la RAM com per als registres de port, mantenint el conjunt d'instruccions simple i uniforme.

> [!question] Q2: Un xip microcontrolador que pretén ser de baix consum tindrà molta, poca RAM o no té res a veure? **Resposta:** Tendirà a tenir **poca RAM**. La memòria interna dels microcontroladors és **SRAM** (tecnologia de transistors), la qual no requereix refresc però consumeix més energia proporcionalment a la seva mida. Per tant, limitar la quantitat de RAM és clau en dissenys de baix consum.

> [!question] Q3: Si en la ROM es guarda el programa i en la RAM es guarden els valors de les variables, on es guarden els valors de les comandes, consignes i paràmetres? **Resposta:** Es guarden a la memòria **EEPROM**. Aquestes dades (paràmetres de configuració, llenguatge, consignes) s'han de mantenir quan el dispositiu s'apaga (no volàtil), però han de poder-se modificar puntualment durant el funcionament de l'aplicació, funció que la memòria EEPROM permet realitzar a nivell de byte o fila.

