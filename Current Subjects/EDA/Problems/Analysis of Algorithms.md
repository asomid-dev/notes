# Analysis of Algorithms Problem Set
#eda #lab #english #PARCIAL1 

#### 1. Big sums everywhere.            Prove the following identities:

- (a) $\sum^{n}_{i=1} i = \frac{n(n+1)}{2}.$ 
- (b) $\sum^{n}_{i=1} i^{2} = n(n+1) \frac{2n+1}{6}.$
- (c) $\sum^{n}_{i=0} 2^{i} = 2^{n+1}-1.$

(a): $\sum^{n}_{i=1} i = \frac{n(n+1)}{2}.$ 

Base case: n = 1 $(i = 1)$
$$1 = \frac{1(1+1)}{2} = \frac{2}{2} = 1 \quad \text{True}$$
$$\text{I.H. (n-1 to n):} \sum^{n-1}_{i = 1} i = \frac{(n-1)n}{2} $$
Inductive Step:
$$\sum^{n}_{i=1} i \xrightarrow{I.H.} \left( \sum^{n-1}_{i=1}i \right) + n = \frac{(n-1)n}{2} + n = \frac{(n-1)n + 2n}{2} = \frac{n(n-1+2)}{2}=\frac{n(n+1)}{2} \quad \text{QED.}$$

(b): $\sum^{n}_{i=1} i^{2} = n(n+1) \frac{2n+1}{6}.$

Base case: n = 1 $(i^{2} = 1^{2} = 1)$
$$1 = \frac{1(1+1) \cdot (2 \cdot 1 + 1)}{6} = \frac{6}{6} = 1 \quad \text{True}$$
$$\text{I.H. (n-1 to n):} \sum_{i=1}^{n-1} i^{2} = \frac{((n-1)n)\cdot (2(n-1) + 1)}{6} = \frac{n(n-1) \cdot (2n - 1)}{6}$$
Inductive Step:
$$\sum^{n}_{i=1} \xrightarrow{I.H.}\left( \sum^{n-1}_{i=1} i^{2} \right) + n^{2}= \frac{n(n-1) \cdot (2n-1)}{6} + n^{2} = \frac{n(n-1) \cdot (2n-1) + 6n^{2}}{6} =$$
$$= \frac{n[(n-1) \cdot (2n-1) + 6n]}{6} =  \frac{n[2n^{2}-n-2n+1+6n]}{6} = \frac{n[2n^{2}+3n + 1]}{6}=$$$$= \frac{n(n+1)(2n+1)}{6} \quad \text{QED}.$$
(c): $\sum^{n}_{i=0} 2^{i} = 2^{n+1}-1.$

Base case: n = 0  $(2^0 = 1)$
$$1 = 2^{0+1} -1 = 1 \quad \text{True}$$
$$\text{I.H. (n-1 to n)}: \sum^{n-1}_{i=0}2^{i} = 2^{(n-1)+1} -1  = 2^{n} -1$$
Inductive Step:
$$\sum^{n}_{i=0}\xrightarrow{I.H.} \left( \sum^{n-1}_{i=0} 2^{i} \right)+ 2^{n} = 2^{n} -1 + 2^{n} = 2^{n+1} -1 \quad \text{QED} $$ 
#### 2. Exact time. Let us suppose that assignments, increments by one unit, and comparisons of integers take 15 μs, 21 μs, and 34 μs, respectively, and that the rest of instructions (increments of the program counter, jumps, etc.) take negligible time. Give the formula that expresses, as a function of the integer input n, the execution time T(n) of the following algorithm:

```cpp
int s = 0;
for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
		++s;
} }
```
$$T(n) = (15 + 15 + 15n + 21n^{2} + 21n + 21n^{2} + 34n^{2} + 34n + 34n + 34) \micro s = (76n^{2}+104n+64)\micro s$$
#### 3. 

| $f(n)$         |     1 s      |        1 min         |          1 h           |           1 day           |          1 month           |           1 year            |          1 century          |
| :------------- | :----------: | :------------------: | :--------------------: | :-----------------------: | :------------------------: | :-------------------------: | :-------------------------: |
| **$\log n$**   |  $2^{10^6}$  | $2^{6 \times 10^7}$  | $2^{3.6 \times 10^9}$  | $2^{8.64 \times 10^{10}}$ | $2^{2.592 \times 10^{12}}$ | $2^{3.1536 \times 10^{13}}$ | $2^{3.1536 \times 10^{15}}$ |
| **$\sqrt{n}$** |  $10^{12}$   | $3.6 \times 10^{15}$ | $1.296 \times 10^{19}$ |  $7.465 \times 10^{21}$   |   $6.718 \times 10^{24}$   |   $9.945 \times 10^{26}$    |   $9.945 \times 10^{29}$    |
| **$n$**        |    $10^6$    |   $6 \times 10^7$    |   $3.6 \times 10^9$    |   $8.64 \times 10^{10}$   |   $2.592 \times 10^{12}$   |   $3.1536 \times 10^{13}$   |   $3.1536 \times 10^{15}$   |
| **$n^2$**      |   $1,000$    |       $7,745$        |        $60,000$        |         $293,938$         |        $1,609,968$         |         $5,615,692$         |        $56,156,922$         |
| **$n^3$**      |     $99$     |        $391$         |        $1,532$         |          $4,420$          |          $13,736$          |          $31,593$           |          $146,645$          |
| **$2^n$**      | $\approx 19$ |     $\approx 25$     |      $\approx 31$      |       $\approx 36$        |        $\approx 41$        |        $\approx 44$         |        $\approx 51$         |

#### 28. Tricky max and min. Let $T$ be a vector with $n$ elements

**(a) Write an algorithm that makes exactly $n − 1$ comparisons to find the maximum
element in $T$.**
```cpp
//pre: n > 1
//post: returns the max element in T
int max_in_T(const vector<int>& T){
	int max = T[0];
	for (p : T){
		if (max < p) max = p;
	}
	return max;
}
```

**(b) Write an algorithm that makes exactly n − 1 comparisons to find the minimum
element in T.**
```cpp
//pre: n > 1
//post: returns the min element in T
int max_in_T(const vector<int>& T){
	int max = T[0];
	for (p : T){
		if (min > p) min = p;
	}
	return min;
}
```

**(c) Write an algorithm that finds both the minimum and the maximum elements in
$T$ and makes only $\frac{3}{2}n$ comparisons.**
```cpp
//pre: n > 1
//post: returns the min element in T
pair<int, int> min_max_in_T(const vector<int>& T){
	int i = 1;
	int min = T[0];
	int max = T[0];
	if (T.size() % 2 == 0){
		i = 2;
		if (T[0] > T[1]){
			min = T[1];
		} else{
			max = T[1];
		}
	}
	
	for (; i < T.size() - 1; i+=2){
		if (T[i] < T[i+1]){
			if (min > T[i]) min = T[i];
			if (max < T[i+1]) max = T[i+1];
		} else{
			if (min > T[i+1]) min = T[i+1];
			if (max < T[i]) max = T[i];
		}
	}
	
	return {min, max};
}
```

#### 30. Bisorted bidimensional table. Consider a bidimensional table of size $n × n$where each column has its elements sorted in strict increasing order from top to bottom, and each row has its elements sorted in strict decreasing order from left to right.

**(a) Give an algorithm of cost Θ(n) that, given an element x, determines if x is in the
table or not.**

**(b) Give an algorithm of cost Θ(n) that, given an element x, determines how many
elements in the table are strictly smaller than x.**