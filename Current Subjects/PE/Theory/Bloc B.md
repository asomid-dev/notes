# Bloc B
#pe #apunts #english #PARCIAL1 

## **General DRV Probability Rules**

Before jumping into specific distributions, remember these essential DRV interval formulas:

- **Point Probability**: $P(X = k) = p_X(k)$
- **Cumulative Probability**: $P(X \le k) = F_X(k) = \sum_{j \le k} p_X(j)$
- **Strict Inequality Below**: $P(X < k) = P(X \le k-1) = F_X(k-1)$
- **Interval** $(a, b]$: $P(a < X \le b) = F_X(b) - F_X(a)$
- **Interval** $[a, b]$: $P(a \le X \le b) = F_X(b) - F_X(a-1)$
- **Interval** $(a, b)$: $P(a < X < b) = F_X(b-1) - F_X(a)$
---
### **1. Bernoulli Model**

- **Notation**: $X \sim \text{Bern}(p)$
- **Definition**: Represents the outcome of a **single experiment** with only two possible complementary outcomes: $1$ ("success") or $0$ ("failure").
- **Parameters**:
    - $p \in (0,1)$: Probability of success
    - $q = 1 - p$: Probability of failure
- **Domain**: $k \in \{0, 1\}$
- **Probability Mass Function (PMF)**: $$p_X(k) = \begin{cases} p & \text{if } k = 1 \\ 1 - p = q & \text{if } k = 0 \end{cases}$$
- **Indicators**:
    - **Expectation**: $E(X) = p$
    - **Variance**: $V(X) = p \cdot q$
- **R Commands**:
```R
dbinom(x = k, size = 1, prob = p) # P(X = k)
```

---
### **2. Binomial Model**

- **Notation**: $X \sim B(n, p)$
- **Definition**: Total number of "successes" obtained across $n$ independent and identical Bernoulli trials with a constant probability of success $p$.
- **Parameters**:
    - $n \in \mathbb{N}$: Total number of repetitions/trials
    - $p \in (0,1)$: Constant probability of success per trial
    - $q = 1 - p$
- **Domain**: $k \in \{0, 1, 2, \dots, n\}$
- **PMF**: $$P(X = k) = \binom{n}{k} \cdot p^k \cdot q^{n-k}, \quad \text{for } k = 0, 1, \dots, n$$_(where_ $\binom{n}{k} = \frac{n!}{(n-k)! k!}$_, calculated in R as_ _choose(n, k))_.
- **CDF**: Has no closed analytical formula; computed via summation of point probabilities.
- **Indicators**:
    - **Expectation**: $E(X) = n \cdot p$
    - **Variance**: $V(X) = n \cdot p \cdot q$
- **R Commands**:
```R
dbinom(x = k, size = n, prob = p) # Point probability: P(X = k)
pbinom(q = k, size = n, prob = p) # Cumulative probability: P(X <= k)
qbinom(p = alpha, size = n, prob = p) # Quantile: x_alpha such that P(X <= x_alpha) >= alpha
```

- **Useful Symmetry Property**: $$P(X \le k) = 1 - P(Y \le n - k - 1), \quad \text{where } Y \sim B(n, 1-p)$$
---
### **3. Geometric Model**

- **Notation**: $X \sim \text{Geom}(p)$
- **Definition**: Number of attempts $k$ of a Bernoulli trial required until the **first success** is observed.
- **Parameters**: 
	- $p \in (0,1)$ (probability of success)
	- $q = 1-p$
- **Domain**: $k \in \{1, 2, 3, \dots\}$ (unbounded positive integers)
- **PMF**: $$P(X = k) = q^{k-1} \cdot p, \quad \text{for } k \ge 1$$
- **CDF**: Has an explicit analytical form: $$F_X(k) = P(X \le k) = 1 - q^k$$
- **Indicators**:
    - **Expectation**: $E(X) = \frac{1}{p}$
    - **Variance**: $V(X) = \frac{1-p}{p^2} = \frac{q}{p^2}$
- **⚠️ Crucial R Nuance**: In R functions (`dgeom`, `pgeom`), the parameter takes the **number of failures** ($k - 1$), not the total number of attempts $k$:

```R
# P(X = k attempts) = P(k-1 failures)
dgeom(x = k - 1, prob = p) 

# P(X <= k attempts) = P(k-1 failures)
pgeom(q = k - 1, prob = p) 

# Quantile for k attempts:
qgeom(p = alpha, prob = p) + 1
```

---
### **4. Negative Binomial Model**

- **Notation**: $X \sim \text{NB}(r, p)$ 
- **Definition**: Total number of attempts $k$ in independent Bernoulli trials until $r$ successes occur. _(Can be viewed as the sum of_ $r$ _independent geometric variables)_.
- **Parameters**:
    - $r \in \mathbb{N}$: Target number of successes
    - $p \in (0,1)$: Probability of success
- **Domain**: $k \in \{r, r+1, r+2, \dots\}$
- **PMF**: $$P(X = k) = \binom{k-1}{r-1} \cdot p^r \cdot q^{k-r}, \quad \text{for } k \ge r$$
- **Indicators**:
    - **Expectation**: $E(X) = \frac{r}{p}$
    - **Variance**: $V(X) = \frac{r \cdot q}{p^2} = \frac{r(1-p)}{p^2}$
- **⚠️ Crucial R Nuance**: Like the geometric model, R counts the **number of failures** ($k - r$) prior to reaching $r$ successes:
```R
# P(X = k attempts) = P(k - r failures)
dnbinom(x = k - r, size = r, prob = p) 

# P(X <= k attempts) = P(k - r failures)
pnbinom(q = k - r, size = r, prob = p) 

# Quantile for k attempts:
qnbinom(p = alpha, size = r, prob = p) + r
```

---
### **5. Poisson Model**

- **Notation**: $X \sim P(\lambda)$
- **Definition**: Number of occurrences/events in a specified interval of time or space.
- **Parameters**: $\lambda > 0$ (the mean occurrence rate per interval unit).
- **Domain**: $k \in \{0, 1, 2, \dots\}$
- **PMF**: $$P(X = k) = \frac{e^{-\lambda} \cdot \lambda^k}{k!}, \quad \text{for } k = 0, 1, 2, \dots$$
- **Indicators**:
    - **Expectation**: $E(X) = \lambda$
    - **Variance**: $V(X) = \lambda$
- **Key Operational Properties**:
    - **Sum of Independent Poissons**: If $X \sim P(\lambda_1)$ and $Y \sim P(\lambda_2)$ are independent, then $X + Y \sim P(\lambda_1 + \lambda_2)$.
    - **Change of Interval**: If rate is $\lambda$ for interval $t$, the rate for an interval of length $k \cdot t$ becomes $k \cdot \lambda$.
- **R Commands**:

```R
dpois(x = k, lambda = lambda) # P(X = k)
ppois(q = k, lambda = lambda) # P(X <= k)
qpois(p = alpha, lambda = lambda) # Quantile: x_alpha
```

---
## **General Rules for CRVs**

Unlike discrete random variables, continuous variables are defined over continuous real intervals.

- **Point Probability is always ZERO**: $P(X = k) = 0$ for any specific value $k$. The value $f_X(k)$ is the density height, **not** a probability!
- **Strict vs. Non-Strict Inequalities are EQUAL**: $$P(a \le X \le b) = P(a < X \le b) = P(a < X < b) = F_X(b) - F_X(a)$$
- **Total Area under Density Function**: $\int_{-\infty}^{+\infty} f_X(x) \, dx = 1$.
- **Cumulative Distribution Function (CDF)**: $F_X(x) = P(X \le x) = \int_{-\infty}^{x} f_X(u) \, du$.
- **General Indicators**:
    - **Expectation**: $E(X) = \mu_X = \int_{-\infty}^{+\infty} x \cdot f_X(x) \, dx$
    - **Variance**: $V(X) = \sigma_X^2 = \int_{-\infty}^{+\infty} (x - E(X))^2 f_X(x) \, dx = E(X^2) - [E(X)]^2$

---
### **1. Continuous Uniform Model**

- **Notation**: $X \sim U(a, b)$
- **Definition**: A CRV with a constant density function across a bounded range $[a, b]$. The probability of falling into a sub-interval depends only on its length.
- **Parameters**:
    - $a \in \mathbb{R}$: Minimum value
    - $b \in \mathbb{R}$: Maximum value ($b > a$)
- **Density Function (**$f_X$**)**: $$f_X(x) = \frac{1}{b - a} \quad \text{for } a < x < b$$
- **CDF (**$F_X$**)**: $$F_X(x) = \begin{cases} 0 & \text{if } x < a \\ \frac{x - a}{b - a} & \text{if } a \le x \le b \\ 1 & \text{if } x > b \end{cases}$$
- **Indicators**:
    - **Expectation**: $E(X) = \frac{a + b}{2}$ (the midpoint)
    - **Variance**: $V(X) = \frac{(b - a)^2}{12}$
- **R Commands**:

```R
dunif(x = k, min = a, max = b) # Density value f_X(k)
punif(q = k, min = a, max = b) # P(X <= k)
qunif(p = alpha, min = a, max = b) # Quantile x_alpha
``` 

---
### **2. Exponential Model(Geom)**

- **Notation**: $X \sim \text{Exp}(\lambda)$
- **Definition**: Models continuous **time or distance between consecutive occurrences** in a Poisson point process with constant rate $\lambda$ (e.g., component lifespan, time between server requests).
- **Parameters**: $\lambda > 0$ (event rate per unit of time/space).
- **Domain**: $x > 0$.
- **Density Function (**$f_X$**)**: $$f_X(x) = \lambda \cdot e^{-\lambda x} \quad \text{for } x > 0$$
- **CDF (**$F_X$**)**: Has an explicit analytical form: $$F_X(x) = 1 - e^{-\lambda x} \quad \text{for } x > 0$$
- **Indicators**:
    - **Expectation**: $E(X) = \frac{1}{\lambda}$
    - **Variance**: $V(X) = \frac{1}{\lambda^2}$
- **⭐ Memoryless (Markov) Property**: $$P(T > t_1 \mid T > t_0) = P(T > t_1 - t_0) \quad \text{for } t_1 > t_0$$_(The future lifespan probability does not depend on elapsed time!)_
- **R Commands**:

```R
dexp(x = k, rate = lambda) # Density value f_X(k)
pexp(q = k, rate = lambda) # P(X <= k)
qexp(p = alpha, rate = lambda) # Quantile x_alpha
``` 

---
### **3. Normal (Gaussian) Model**

- **Notation**: $X \sim N(\mu, \sigma)$
- **Definition**: Symmetrical bell-shaped distribution used to model real-world measurements that cluster around a central mean.
- **Parameters**:
    - $\mu \in \mathbb{R}$: Mean / Expected value ($E(X) = \mu$)
    - $\sigma > 0$: Standard deviation (Variance $V(X) = \sigma^2$)
- **Special Case**: $N(0, 1)$ is called the **Standard Normal distribution**.
- **Density Function (**$f_X$**)**: $$f_X(x) = \frac{1}{\sigma \sqrt{2\pi}} e^{-\frac{1}{2} \left(\frac{x - \mu}{\sigma}\right)^2} \quad \text{for } x \in \mathbb{R}$$
- **CDF (**$F_X$**)**: **No closed analytical expression** exists; probabilities and quantiles must be evaluated numerically or using R.
- **R Commands**:

```R
dnorm(x = k, mean = mu, sd = sigma) # Density value
pnorm(q = k, mean = mu, sd = sigma) # Cumulative P(X <= k)
qnorm(p = alpha, mean = mu, sd = sigma) # Quantile x_alpha
``` 

$$\text{z-score} = \frac{x-\mu}{\sigma} \qquad Var(Total)=n \cdot \sigma^{2}$$
$$\text{Total Deviation } (\sigma_{n}) = \sqrt{ n } \cdot \sigma$$
$$\text{Avg. } Var(\bar{X})=\frac{\sigma^{2}}{n} \qquad \text{Avg. Deviation }\sigma_{\bar{X}}=\frac{\sigma}{\sqrt{ n }}$$

---
### **4. Distributions Derived from the Normal (for Statistical Inference)**

These models represent combinations of standard normal variables $Z \sim N(0,1)$:

1. **Chi-Square (**$\chi^2_n$**)**:
    - **Definition**: Sum of $n$ squared independent standard normal variables: $\sum_{i=1}^n Z_i^2 \sim \chi^2_n$.
    - **Parameter**: $n$ (degrees of freedom).
    - **R Functions**: `dchisq()`, `pchisq()`, `qchisq()`.
2. **t-Student (**$t_n$**)**:
    - **Definition**: Ratio of a standard normal $Z$ to the square root of an independent Chi-Square divided by its degrees of freedom: $\frac{Z}{\sqrt{Y_n / n}} \sim t_n$.
    - **Parameter**: $n$ (degrees of freedom).
    - **Property**: As $n \to \infty$ ($n > 30$), $t_n$ converges to $N(0,1)$.
    - **R Functions**: `dt()`, `pt()`, `qt()`.
3. **Fisher-Snedecor (**$F_{n, m}$**)**:
    - **Definition**: Ratio of two independent Chi-Square variables, each divided by its respective degrees of freedom: $\frac{X_1 / n}{X_2 / m} \sim F_{n, m}$.
    - **Parameters**: $n$ (numerator df) and $m$ (denominator df).
    - **R Functions**: `df()`, `pf()`, `qf()`.