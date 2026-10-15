# <span style="color:rgb(192, 0, 0)">Methods Cheatseet</span> 

### Method 1: Gauss Pairing
$$\sum_{m=1}^{n} m = 1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}$$
This can be explained intuitively using Gauss' Pairing Method:
$$\begin{cases}
S=1 + 2 + 3 + \dots + (n-1)+n \\
S=n+(n-1)+(n-2)+ \dots + 2 + 1
\end{cases}$$
- **First Pair:** $1 + n = n+1$
- **Second Pair:** $2 + (n-1) = n+1$
- **Third pair:** $3 + (n-2) = \mathbf{n+1}$
- **...**
- **Last pair:** $n + 1 = \mathbf{n+1}$
- $S + S = 2S$$$2S = (n+1) + (n+1) + (n+1) + \dots + (n+1) \iff 2S = n \times (n+1) \iff S=\frac{n(n+1)}{2}$$
### Method 2: 
