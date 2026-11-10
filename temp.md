# Ej 4

x al ser var global definida, se encuentra en el "rw-" (data)
las vars locales van al "stack"

mmap para dar permisos especificos

the fuck a SRBK is?

# Ej 15
Usuario:
$\text{4KB}$ código
$\text{4KB}$ datos
$\text{4KB}$ stack

Kernel:
$\text{4KB}$ PCB

```c
fork(); // -> 2 procs
fork(); // -> 4 procs
fork(); // -> 8 procs 
```

w/o COW (Copy-On-Write): 
$8 \times (4+4+4)=96\text{KB}$ de usuario y Kernel $8 \times 4 = 32\text{KB}$ total = $128\text{KB}$

w COW:
1 copia de cada región
Usuario: 4+4+4 = $12\text{KB}$ 
Kernel: $8 \times 4 = 32\text{KB}$ 
Total = $44\text{KB}$

Cuando dos procesos comparten programa, se pone todo en un frame que llamamos pagina fisica (solo en READ)

si P1 quisiera escribir en el programa, se tendria que crear una copia 0 


# Ej 19
Page Size = 4KB
Frame Size = 4KB
Dirección Memoria = 32 bit $\to \frac{2^{32}}{4KB}=\frac{2^{32}}{2^{12}}=2^{20}$
int = 4B
char = 1B

ya me he cansado de apuntar