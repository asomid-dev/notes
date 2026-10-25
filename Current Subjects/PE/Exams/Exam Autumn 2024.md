# 2024
#pe #examen #PARCIAL1 
## Problem 2 (B)

### P(Lleus): 0.4, P(Mitjans): 0.25, P(Greus): 0.1

1. Binom: 
$$1 - pbinom(28, 30, 0.4) = 5.1 \times 10^{-11}$$
2. Binom:
$E(B) = n \cdot p = 30 \cdot 0.1 = 3$
$Var(B) = p \cdot q \cdot n = 0.1 \cdot 0.9 \cdot 30 = 2.7$
$$\sigma = \sqrt{ 2.7 } = 1.643$$
3. Geom:
$$P(Geom) = 1- (1 - q^{k}) = 1 - (1- 0.75^{5}) = 0.2373046875$$
4. NBinom
$$P(NB) = \begin{pmatrix}
k-1 \\
r-1
\end{pmatrix} \cdot p^{r} \cdot q ^{k-r} = \begin{pmatrix}
7 \\
4
\end{pmatrix} \cdot 0.4^{5} \cdot 0.6^{3} =0.077$$
5. Poisson
$$\lambda = 2 / h$$
$$\lambda_{2hores} = 4$$
$$P(Poisson) = \frac{\lambda^{k}\cdot e^{-\lambda}}{k!} = 0.1953 \implies P(X = 3)$$
$$P(X < 2) = P(X=0) + P(X=1) = 0.091578$$
6. Exponential
$$P(Exp) = 1-(1-e^{-\lambda \cdot x}) = 1-(1-e^{-1}) = 0.3678$$

$\mu = 180h$, $\sigma = 100h$
7. Normal

$$\mu = \mu \cdot n, \sigma = \sigma = \sigma \cdot \sqrt{  \mu } \implies = \mu = 180 * 25 = 4500, \sigma = 100 \cdot \sqrt{ 25 } = 500$$
$\text{z-score} = \frac{x-\mu}{\sigma} = \frac{4800 - 4500}{500} = 0.6 \implies 1- pnom(0.6) = 0.274$

8. Normal
$$X <= 10$$
$$\text{Avg Deviation} = \frac{100}{\sqrt{ n }} \leq 10 \implies 10^{2} \leq 10 \implies 100 \leq 10$$
9. Normal
$$330 - 130 = 200$$
$$\text{z-score} = P\left( \frac{330 - 180}{100} \right) - \left( 1- P\left( \frac{130 - 180}{100}  \right)\right) = 0.624655$$
10. Normal
$$\frac{X\cdot x -\mu }{\sigma}=\frac{X\cdot 160 - 4500}{500}=qn or m(0.95) = 33.265 \implies 34$$