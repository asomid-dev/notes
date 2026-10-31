# EDA PARCIAL 2025/26 Q1
#eda #examen #PARCIAL1 
## Problema 1 (3.75 pts)
**(a) (1.25 pts) Considereu la funció**
```cpp
int f (int n){
	int i = 0, s = 0, q = 0;
	while (q < n){
		++i;
		s += i;
		q = 2*s - i;
	}
	return q;
}
```

En funció d'$n$ quantes voltes fa **exactament** (no pas asimptòticament) el bucle de dins $f$ ? Quin és el cost d'una crida a $f(n)$, també en funció d'$n$?

for n = 6

1: $i = 1, s = 1, q = 1$
2: $i = 2, s=3, q = 4$
3: $i = 3, s = 6, q = 9$
4: $i = 4, s=10, q = 16$
5: $i = 5, s=15, q = 25$

$q = i^{2} \to i^{2} \geq n \to i \geq \sqrt{ n } \implies \sqrt{ n } \text{ is the number of iterations}$

Each iteration costs $\Theta(1)$ as we compute $\sqrt{ n }$, $\sqrt{ n }\cdot \Theta(1) \to T(n) \in \Theta(\sqrt{ n })$

**(b) (1.25 pts.)** Disposem de dos algorismes basats en dividir i vèncer per resoldre un problema. 

A : a=3, b = 3, k = 1 $\to$ n log n 
B: a = 1, c = 1, k = p $\to$ $n^{p+1}$

$$A < B \implies n \log n < n^{p+1}$$
if p=0, then n log n is greater than n, otherwise, B will be always greater than A, so when p = 0, A > B, and when p > 0, A < B.

