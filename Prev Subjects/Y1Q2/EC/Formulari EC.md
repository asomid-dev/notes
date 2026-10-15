## MATES BASIQUES:

Com sabem quins decimals van a $\frac{15}{14}$ ? Fàcil:
$$15 \equiv 1 \mod 14 \quad \text{Com el residu es 1 fem el seguent:}$$
$$\text{Quants cops cap el 14 a }10? \;0 \to 1,0$$
$$\text{Quants cops cap el 14 a 100?} \; 7 \to 1,07 \quad\text{Per tant } \frac{15}{14} \approx 1,07$$

## FORMULES

### CPI, Speedup, Temps
$$CPI_{ideal}=\sum(\% \text{ d'intruccions} \times \text{CPI ideal del tipus})$$
$$CPI_{penalització}=(Mem_{inst}\times MissRate)\times Cicles_{Pen}$$
$$Avg(CPI) = \frac{\sum N_{i} \times CPI_{i}}{N}$$
$$CPI_{real}=CPI_{ideal}+CPI_{penalització}$$
$$T_{exe}=\frac{N\times CPI_{real}}{f} \qquad T_{exeideal} = \frac{N\times CPI_{ideal}}{f}$$
$$Spe edup=\frac{\text{Temps Vell}}{\text{Temps Nou}}=\frac{\text{Cicles Vells}}{\text{Cicles Nous}}$$
$$Spe edup_{\text{max de X}}=\frac{\text{Cicles Vells}}{\text{Cicles Nous Mínims}}$$

### Accés Matriu
$$M_{desplaçament}=(i\times NC + j)\times Type$$

### Cache

### MV, TP, TLB
$$\text{Marcs de pagina}= \frac{\text{Espai memoria fisica}}{\text{Tamany pàgines}}$$
$$\text{Entrades TP}=\frac{\text{Mida total de la TP}}{\text{Mida d'una entrada}}$$
$$\text{Mida MV} = \text{Nombre de pàgines} \times \text{Mida de pàgina}$$
_**Nombre de pàgines = nombre d'entrades**_
#### Com desmuntar l'adreça a la Cache exemple:
$$32 \text{ bytes}=2^{5}\to 5\text{ offset bits}$$
$$16 \text{ conjunts} \quad 16 = 2^{4} \to 4 \text{ index bits}$$
$$\text{Resultat: } [TAG_{23}] [Index_{4}] [Offset_{5}] = 32 bits$$
#### Com desmuntar la VPN a la MV:
$$\text{Pàgines de 4KB}\to 2^{12} \to 12 \text{ offset bits, } 12 \text{ bits = 3 hexa numbers}$$

### Algorismes

#### Divisió

R / D
-7/4 -> 0000 0111 | 0100 0000
```c
D = D >> 1;
R = R - D
Q = Q << 1
if (R positiu){
	Q += 1
} else{
	R = R + D
}
```

11 * 6
MD -> 0000 1011
MR -> 0000 0110
#### Multiplicació
```c
while (i < MR bits){
	MD = MD << 1;
	MR = MR >> 1;
	if (MR0 == 1){
		P += MD;
	}
	i++;
}
```


### Macros

| Instrucció           | Equivalent                                                                                                          |
| -------------------- | ------------------------------------------------------------------------------------------------------------------- |
| b                    | beq $zero, $zero, etiq                                                                                              |
| move                 | addu $rd, $zero, $rt                                                                                                |
| li                   | si Imm = 16 bits<br>addiu rd, $zero, Imm16<br><br>Si Imm = 32 bits<br>lui $at, hi(imm32)<br>ori $rd, $at, lo(imm32) |
| la                   | lui $at, hi(@)<br>ori $rd, $at, lo(@)                                                                               |
| bxx<br>(bgt, bge...) | 2 instruccions                                                                                                      |

