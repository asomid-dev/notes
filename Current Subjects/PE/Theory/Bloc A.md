# Bloc A
#pe #apunts #english #PARCIAL1 

## 1.1. Basic Definitions & Set Operations

- **Deterministic vs. Random Phenomena**: Deterministic phenomena always lead to the exact same results under the same initial conditions, whereas random phenomena involve uncertainty in the future outcome.
- **Sample Space (**$\Omega$**) & Events**: The sample space $\Omega$ is the set of all possible outcomes. An **event** is any subset of $\Omega$.
- **Partition**: A collection of mutually disjoint events $A_i \neq \emptyset$ whose union equals the full sample space $\Omega$ ($A_i \cap A_j = \emptyset$ for $i \neq j$ and $\bigcup A_i = \Omega$).
- **Set Operations**: Events follow standard set operations including **Union** ($A \cup B$), **Intersection** ($A \cap B$), **Complement** ($\neg A$), and **Difference** ($A - B$).
- **Representations**: Probability problems are visually represented using **Venn diagrams** or **Probability trees**.

---

## 1.2. Probability Axioms & Properties

- **Axioms**: A probability function assigns a value between 0 and 1 to each event such that:
    1. $0 \le P(A) \le 1$
    2. $P(\Omega) = 1$
    3. $P(\bigcup A_i) = \sum P(A_i)$ for disjoint events
- **Deducted Rules**:
    - **Complement Rule**: $P(\neg A) = 1 - P(A)$
    - **Empty Set**: $P(\emptyset) = 0$
    - **Inclusion-Exclusion Principle**: $P(A \cup B) = P(A) + P(B) - P(A \cap B)$
    - **Equiprobability**: $P(A) = \frac{\text{favourable cases}}{\text{total cases}}$ applies **only** when all outcomes have equal probability.

---

## 1.3. Conditional Probability & Multiplicative Rule

- **Conditional Probability**: $P(A|B) = \frac{P(A \cap B)}{P(B)}$ (for $P(B) > 0$) measures the probability of $A$ occurring given that $B$ has already occurred. Conditioning on $B$ effectively reduces the sample space to $B$.
- **Multiplicative Rule**: $P(A \cap B) = P(A) \cdot P(B|A)$. In a probability tree, the joint probability along any path is the product of the probabilities along its branches6.

---

## 1.4. Law of Total Probability & Bayes' Theorem

- **Law of Total Probability (LTP)**: Given a partition $A_1, A_2, \dots, A_J$ of $\Omega$, the probability of an event $B_k$ is calculated by summing across all partition paths: $$P(B_k) = \sum_{j} P(B_k | A_j) \cdot P(A_j)$$
- **Bayes' Formula**: Reverses conditional probabilities: $$P(A|B) = \frac{P(B|A) \cdot P(A)}{P(B)}$$
- **Bayes' Theorem**: Combining Bayes' formula with the LTP gives: $$P(A_i | B_k) = \frac{P(B_k | A_i) \cdot P(A_i)}{\sum_{j} P(B_k | A_j) \cdot P(A_j)}$$

---

## 1.5. Event Independence

- **Definition**: $A$ and $B$ are **independent** if and only if: $$P(A \cap B) = P(A) \cdot P(B)$$
- **Equivalences**: If $A$ and $B$ are independent, knowing $B$ occurred does not change the likelihood of $A$, meaning $P(A|B) = P(A)$ and $P(B|A) = P(B|\neg A) = P(B)$

---


## 2.1. Definitions: Discrete (DRVs) vs. Continuous (CRVs)

- **Random Variable (RV)**: A function $X: \Omega \rightarrow \mathbb{R}$ that assigns a real numerical value to each outcome in the sample space $\Omega$.
- **Discrete Random Variable (DRV)**: Takes a countable set of values (e.g., counts, integers).
    - **Probability Function (PMF)**: $p_X(k) = P(X = k)$, where $\sum_k p_X(k) = 1.$
    - **Cumulative Distribution Function (CDF)**: $F_X(k) = P(X \le k) = \sum_{j \le k} p_X(j)$.
- **Continuous Random Variable (CRV)**: Takes values from an uncountably infinite set (usually real numbers or intervals).
    - **Probability Density Function (PDF)**: A non-negative function $f_X(x) \ge 0$ where the total area under $f_X$ equals 1 $(\int_{-\infty}^{+\infty} f_X(x) dx = 1)$. **Crucial note**: Point probabilities for CRVs are zero ($P(X = k) = 0$), so $f_X(k)$ is a height/density, not a point probability.
    - **Cumulative Distribution Function (CDF)**: $F_X(k) = P(X \le k) = \int_{-\infty}^{k} f_X(x) dx$, with $f_X(x) = \frac{dF_X(x)}{dx}$.

---

## 2.2. Interval Probabilities & Quantiles

- **Interval Probabilities**:
    - **CRVs**: Strict vs. non-strict inequalities do not alter probabilities because single points have measure zero: $P(a \le X \le b) = P(a < X < b) = F_X(b) - F_X(a) = \int_a^b f_X(x) dx$.
    - **DRVs**: Boundaries matter! $P(a < X \le b) = F_X(b) - F_X(a)$, but $P(a \le X \le b) = F_X(b) - F_X(a-1)$.
- **Quantiles (**$x_\alpha$**)**: The value $x_\alpha$ such that the cumulative probability up to $x_\alpha$ equals $\alpha$ $(F_X(x_\alpha) = \alpha)$. Finding a quantile is the inverse problem of finding cumulative probabilities ($x_\alpha = F_X^{-1}(\alpha)$).

---

## 2.3. Indicators: Expectation & Variance

- **Expected Value (Mean** $\mu_X$ **or** $E(X)$**)**:
    - **DRV**: $E(X) = \sum_{\forall k} k \cdot p_X(k)$.
    - **CRV**: $E(X) = \int_{-\infty}^{+\infty} x \cdot f_X(x) dx$.
- **Variance (**$\sigma_X^2$ **or** $V(X)$**) & Standard Deviation (**$\sigma_X$**)**:
    - Measures dispersion about the mean.
    - **Key Computational Formula**: $V(X) = E(X^2) - [E(X)]^2$.
- **Linear Transformations & Properties**:
    - **Shift & Scale**: $E(a + bX) = a + b E(X)$ and $V(a + bX) = b^2 V(X)$ (adding a constant $a$ shifts the mean but does not alter variance).
    - **Sum of Expectations**: $E(X + Y) = E(X) + E(Y)$ (always holds, regardless of independence).
    - **Sum of Variances**: $V(X \pm Y) = V(X) + V(Y)$ **only if** $X$ and $Y$ are independent (notice it is always a "+" sign on the right side).

---

## 2.4. Bivariate Random Variables & Association

- **Joint & Conditional Functions**:
    - **Joint PMF / PDF**: Describes the joint behavior $p_{X,Y}(x,y) = P(X=x \cap Y=y)$ for DRVs or $f_{X,Y}(x,y)$ for CRVs.
    - **Conditional Functions**: $p_{X|Y=y}(x) = \frac{p_{X,Y}(x,y)}{p_Y(y)}$ or $f_{X|Y=y}(x) = \frac{f_{X,Y}(x,y)}{f_Y(y)}$.
- **Independence of RVs**:
    - $X$ and $Y$ are independent if and only if $p_{X,Y}(x,y) = p_X(x) \cdot p_Y(y)$ (or $f_{X,Y}(x,y) = f_X(x) \cdot f_Y(y)$).
    - When independent, $E(X \cdot Y) = E(X) \cdot E(Y)$ and $Cov(X,Y) = 0$.
- **Covariance (**$Cov(X,Y)$**) & Pearson Correlation (**$\rho_{X,Y}$**)**:
    - **General Expectation Formula**: $E(X \cdot Y) = E(X) \cdot E(Y) + Cov(X,Y)$
    - **General Variance Formula**: $V(X \pm Y) = V(X) + V(Y) \pm 2 Cov(X,Y)$
    - **Covariance Properties**: $Cov(aX, bY) = a \cdot b \cdot Cov(X,Y)$ and $Cov(X,X) = V(X)$
    - **Correlation Coefficient**: Standardized indicator of linear relationship bounded between $-1$ and $1$: $$\rho_{X,Y} = \frac{Cov(X,Y)}{\sigma_X \cdot \sigma_Y}$$
    - **Linearity Rules**: If $|\rho_{X,Y}| = 1$, the relationship is perfectly linear ($Y = a + bX$). If $X, Y$ are independent, then $\rho_{X,Y} = 0$; however, $\rho_{X,Y} = 0$ does **not** imply independence (it only implies the absence of a _linear_ relationship).

## R Studio Formularium

### Set Operations
```R
A <- c(1, 2, 3, 4) 
B <- c(3, 4, 5, 6) 
Omega <- 1:10 # Define the full sample space 

# Union (A U B) 
union(A, B) 

# Intersection (A ^ B) 
intersect(A, B) 

# Difference (A - B) 
setdiff(A, B) 

# Complement (¬A) 
setdiff(Omega, A)
```

### Law of Total Prob. & Bayes' Theorem
```R
# --- STEP 1: Define Priors and Conditional Likelihoods --- 
# P(A_i): Prior probabilities of partition causes (A1, A2, A3) 
P_A <- c(0.50, 0.30, 0.20) 

# P(B | A_i): Likelihood of observing event B given each cause
# P(B | A_i) =  P(B ^ A) / P(A)
P_B_given_A <- c(0.02, 0.05, 0.10) 

# Check Axiom: sum of priors must equal 1 
sum(P_A) == 1 

# --- STEP 2: Calculate Joint Probabilities P(B ∩ A_i) --- 
# Multiplicative rule along each tree path: P(B ∩ A_i) = P(A_i) * P(B | A_i) 
P_joint <- P_A * P_B_given_A 

# --- STEP 3: Law of Total Probability (LTP) --- 
# P(B) = Sum of all joint path probabilities 
P_B <- sum(P_joint) cat("Total Probability P(B) =", P_B, "\n") 

# --- STEP 4: Bayes' Theorem P(A_i | B) --- 
# P(A_i | B) = P(B ∩ A_i) / P(B) 
P_A_given_B <- P_joint / P_B 

# --- STEP 5: Display as a Summary Table --- 
bayes_table <- data.frame( 
	Cause = paste0("A", 1:length(P_A)), 
	Prior_P_A = P_A, 
	Likelihood_P_B_given_A = P_B_given_A, 
	Joint_Path = P_joint, 
	Posterior_Bayes = P_A_given_B 
) 

print(bayes_table)
```

### DRVs

Defining a DRV & Checking Axioms
```R
# Values of X and their probabilities 
x <- c(0, 1, 2, 3, 4) 
p_x <- c(0.10, 0.25, 0.35, 0.20, 0.10) 

# Check axiom: sum of probabilities must equal 1 
sum(p_x) == 1
```

CDF, Fx
```R
# Cumulative probabilities P(X >= k)
F_x <- cumsum(p_x)

# Evaluate P(a < X <= b) = F_X(b) - F_X(a) 
# Example: P(1 < X <= 3) = F_X(3) - F_X(1) 
prob_interval <- F_x[which(x == 3)] - F_x[which(x == 1)]
```

Mean $E(X)$ and Variance $V(X)$
```R
# Expected Value E(X) = sum(x * p(x)) 
E_X <- sum(x * p_x) 

# Mean of X^2: E(X^2) = sum(x^2 * p(x)) 
E_X2 <- sum(x^2 * p_x) 

# Variance V(X) = E(X^2) - (E(X))^2 

V_X <- E_X2 - (E_X)^2 

# Standard Deviation sigma_X = sqrt(V(X)) 
sd_X <- sqrt(V_X) 

cat("E(X) =", E_X, "| V(X) =", V_X, "| SD =", sd_X, "\n")
```

### CRVs

Checking Validity of Density Function $f_X(x)$
```R
# Define the PDF f(x) 
f_x <- function(x) { 
	# Example: f(x) = 2*x for 0 <= x <= 1, 0 otherwise 
	ifelse(x >= 0 & x <= 1, 2 * x, 0) 
} 

# Total area must equal 1 
total_area <- integrate(f_x, lower = 0, upper = 1)$value 
cat("Total area =", total_area, "\n")
```

