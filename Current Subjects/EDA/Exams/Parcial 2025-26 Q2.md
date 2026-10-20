# EDA PARCIAL 2025/26 Q2
#eda #examen #PARCIAL1 
## Problema 1 (3.75 pts)

**(a) (1.25 pts.) Compareu asimptòticament les funcions $2^{n}$ i $3^{n / 2}$**

$$3^{n / 2}\iff(\sqrt{ 3 })^n$$
We apply limits to the division: $\lim_{ n \to \infty } \frac{f(n)}{g(n)}$ where $f(n)=2^{n}$ and $g(n)=(\sqrt{ 3 })^n$ 
$$\lim_{ n \to \infty } \frac{2^{n}}{(\sqrt{ 3 })^{n}} = \lim_{ n \to \infty } \left( \frac{2}{\sqrt{ 3 }} \right)^{n} = \lim_{ n \to \infty }\left( \frac{2}{\approx1.7} \right)^{n} = \infty $$
As the limit tends to infinity, the function $2^{n}$ is greater than $3^{n /2}$

**(b) (1.25 pts.) Disposem de cinc algorismes recursius tals que el seu cost ve des-
crit per una recurrència de la forma $T(n) = aT(m) + Θ(nk).$ La següent taula
voldria descriure la recurrència de cadascun d’ells, amb el corresponent cost
asimptòtic, però està desordenada. Reordeneu els elements dins cada columna
de manera que, a cada fila, la recurrència corresponent als valors $a$, $m$ i $k$ tingui
el cost indicat a la mateixa. No està permès canviar els elements de columna:
per exemple, no podeu posar $n/2$, que està a la columna $m$, a la columna $a$.
Només els podeu canviar de fila, tot mantenint-los a la mateix columna. No
cal justificació. Qualsevol error comporta 0 punts.**

**DESORDENADA**

| $a$                                           | $m$                                               | $k$                                           | Cost                                                   |
| --------------------------------------------- | ------------------------------------------------- | --------------------------------------------- | ------------------------------------------------------ |
| <span style="color:rgb(192, 0, 0)">$2$</span> | <span style="color:rgb(192, 0, 0)">$n / 2$</span> | <span style="color:rgb(192, 0, 0)">$1$</span> | <span style="color:rgb(192, 0, 0)">$n$</span>          |
| <span style="color:rgb(192, 0, 0)">$1$</span> | <span style="color:rgb(192, 0, 0)">$n / 2$</span> | <span style="color:rgb(192, 0, 0)">$1$</span> | <span style="color:rgb(192, 0, 0)">$2^n$</span>        |
| <span style="color:rgb(192, 0, 0)">$2$</span> | <span style="color:rgb(192, 0, 0)">$n-1$</span>   | <span style="color:rgb(192, 0, 0)">$0$</span> | <span style="color:rgb(192, 0, 0)">$n \log (n)$</span> |
| <span style="color:rgb(192, 0, 0)">$2$</span> | <span style="color:rgb(192, 0, 0)">$n / 2$</span> | <span style="color:rgb(192, 0, 0)">$0$</span> | <span style="color:rgb(192, 0, 0)">$n^{2}$</span>      |
| <span style="color:rgb(192, 0, 0)">$1$</span> | <span style="color:rgb(192, 0, 0)">$n-1$</span>   | <span style="color:rgb(192, 0, 0)">$0$</span> | <span style="color:rgb(192, 0, 0)">$\log(n)$</span>    |
**SOLUCIÓ** 

| $a$ | $m$     | $k$                                                                                            | Cost         | Correct? |
| --- | ------- | ---------------------------------------------------------------------------------------------- | ------------ | -------- |
| $2$ | $n / 2$ | $0$                                                                                            | $n$          | Yes      |
| $2$ | $n-1$   | <span style="color:rgb(192, 0, 0)">$1$</span> <span style="color:rgb(146, 208, 80)">$0$</span> | $2^n$        | No       |
| $2$ | $n / 2$ | <span style="color:rgb(192, 0, 0)">$0$</span> <span style="color:rgb(146, 208, 80)">$1$</span> | $n \log (n)$ | No       |
| $1$ | $n - 1$ | $1$                                                                                            | $n^{2}$      | Yes      |
| $1$ | $n / 2$ | $0$                                                                                            | $\log(n)$    | Yes      |

**(c) (1.25 pts.) Considereu el següent arbre binari de cerca que conté enters, tots ells diferents:**
```txt
								8
							  /   \
							 2     x
						    / \   / \
						   1   5 12  20
						      / \     /
						     4   6   16
							        /  \
							       15   17
```

**Quin o quins enters poden ocupar el node buit? Una resposta correcta amb un
raonament incorrecte rebrà 0 punts.**

As we already know, a BST is ordered by a in-order structure,  smallest number is at the left greatest number is at the right, because of that, we know that $x$ MUST be greater than 8 and greater than 12, if we look more deep into the right subtree, we find that the smallest number located at the left is the number 15, making so $x$ greater than 12 but lower than 15

Set of numbers that satisfies this condition: $12 < x < 15$ is: $\{ 13, 14 \}$

---
## Problema 2 (6.25 pts)

**Una matriu d’enters de dimensions $N \times N$ és biordenada si cada columna té els ele-
ments ordenats en ordre no decreixent de dalt a baix, i cada fila té els elements
ordenats en ordre no decreixent d'esquerra a dreta. Per exemple, una matriu d’a-
quest tipus seria:**
$$\begin{pmatrix}
1 & 4 & 9 \\
9 & 9 & 9 \\
12 & 14 & 15
\end{pmatrix}$$ **Volem, donats un enter $x$ i una matriu biordenada $A$, decidir si $x$ apareix a $A$ o no.**

**(a) (3 pts) En aquest apartat suposarem que $N$ és una potència de 2. Donats un enter $x$, una matriu biordenada $A$, i tres enters $i, j, n$ tals que $n$ és una potència de $2$ i que $1 \leq n \leq N$ i $0 \leq i$, $j \leq N-n$, la funció
`bool search1 (int x, const vector <vector<int>>& A, int i, int j , int n)`
retorna si $x$ apareix a la submatriu $n \times n$ de $A$ que conté de la fila $i$ a la fila $i + n -1$, i de la columna $j$ a la $j + n -1$. Files i columnes s'indexen des de 0.**
```cpp
bool search1 (int x, const vector <vector<int>>& A, int i, int j , int n) {
	if (n == 1) /*RESPOSTA:*/ return A[i][j] == x;
	int mi = i + n/2 - 1;
	int mj = j + n/2 - 1;
	
	if (A[mi][mj] < x) /*RESPOSTA:*/ 
		return search1(x, A, i, mj + 1, n/2) ||
			   search1(x, A, mi + 1, j, n/2) ||
			   search1(x, A, mi + 1, mj + 1, n/2);
	if (A[mi][mj] > x) /*RESPOSTA:*/ 
		return search1(x, A, i, j, n/2) ||
			   search1(x, A, mi + 1, j, n/2) ||
			   search1(x, A, i, mj + 1, n/2);
	return /*RESPOSTA:*/ true;
}
```

**Com es pot utilitzar la funció search1 per determinar si x apareix a A o no?
Analitzeu el cost en el cas pitjor del vostre algorisme per fer-ho en funció de N.**

bool found = search1(x, A, 0, 0, N);

k = 0, a = 3, b = 2
$$T(n)=3T\left( \frac{n}{2} \right)+\Theta(n^{0}) \implies \log_{2} 3 = 1.5 > 0 \implies n^{\log_{2} 3}$$ **(b) (1.5 pts) Considereu la funció `search2` següent per dir si x apareix a A o no:**
```cpp
bool search2 (int x, const vector <vector<int>>& A) { 
	int i = A.size() − 1, j = 0;
	while (i ≥ 0 and j < A.size ()) {
		if (A[i][j] > x) −−i;
		else if (A[i][j] < x) ++j;
		else return true;
	}
	return false ;
}
```

**Demostreu que és correcta utilitzant un invariant de l'estil: si $x$ apareix a $A$,
necessàriament apareix a la submatriu $A[p · · · q][r · · · s]$ per certs enters $p, q, r, s$.**

- **Invariant:** If $x$ appears in $A$, it is located between rows $0 \dots i$ and columns $j \dots N-1$.
- **Maintenance:** In each step, if $A[i][j] > x$, we decrement $i$ (`--i`) to discard row $i$; if $A[i][j] < x$, we increment $j$ (`++j`) to discard column $j$, keeping the invariant true.
- **Termination:** If the loop finishes without finding the element, the search space is exhausted and the invariant ensures that $x$ is not in the matrix.

**(c) (1.75 pts) Analitzeu el cost en el cas pitjor de `search2` en funció de $N=A.size()$.**

In the worst case, we can subtract from $i$ at most $N$ times and the same goes for $j$ (via addition), so this algorithm worst case cost is $2\Theta(N)$, it does mean that the algorithm is linear so the cost is linear: $\Theta(N)$.
