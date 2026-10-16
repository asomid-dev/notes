# 2025

## Problem 2 (B)

1.
$\lambda = 1.5$, prob no monster in 3 mins

a) more than 3 minutes = $1 - P(X \leq 3) = 1- Exp(1.5) = 0.011109$ 

b) Exactly 4 monsters in 2 minutes, $P(X=4) = Poisson = 0.1680314$
$\lambda = 1.5 \times 2,$ because we have an interval $t$.

2.
prob succesful atack = $p=0.3$
in a duel, $12$ attacks are done

a) At least 3 hits. (Binomial)
$$B(12, 0.3)= 1 - pbinom(2, 12, 0.3) = 0.7471847$$
b) Mean and desviation
$E(B) = n \times p = 12 \times 0.3 = 3.6$ and $\sigma = \sqrt{ n \times p \times q} = 1.587451$

3.
geometric
$p=0.35 / arrow$
a) prob of 1st hit b4 5th arrow.
$P(X\leq 4) = pgeom(3, 0.35) = 0.8214937$

b) 
$E(Geom) = \frac{1}{p} = \frac{1}{0.35}=2.857143$

4.
Every chest has a prob of $p=0.2$ to contain a legendary item.
a) Mean of chests a player has to open to get 3 legendary items.
$E(NB) = \frac{r}{p} = \frac{3}{0.2} = 15$

b) Prob after opening 12 empty chests to get the 3rd legendary item
12 empty chests + 3 legendary item chests are 15 chests so: 
$P(X=15) = dnbinom(14, 3, 0.2) = 0.05002778$
