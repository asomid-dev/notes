# Bloc C
#pe #apunts #english #PARCIAL2

## **1. Basic Concepts & Study Types**

- **Parameter (**$\theta$**)**: Population value to be estimated (e.g., population mean $\mu$, variance $\sigma^2$, proportion $\pi$).
- **Statistic**: Any numerical function calculated from sample data.
- **Estimator (**$\hat{\theta}$**)**: A statistic used to estimate an unknown population parameter (e.g., sample mean $\bar{x}$, sample variance $s^2$, sample proportion $p$).
- **Types of Variables**:
    - **Response (**$Y$**)**: Outcome measure of performance or goal achievement.
    - **Decisions (**$X$**)**: Interventions assigned in experimental studies to evaluate causal effects on $Y$.
    - **Co-variables (**$Z$**)**: Observed conditions used to reduce uncertainty when predicting $Y$.
- **Types of Studies**:
    - **Experimental ("DO")**: Researchers randomly assign treatment levels $X$ to ensure independence from covariates $Z$ and establish causality.
    - **Observational ("SEE")**: Researchers observe natural $Z$ to predict $Y$; covariates may be collinear/confounded, so establishing causality is difficult.

---
## **2. Point Estimation & Properties**

- **Point Estimate**: The specific numerical value taken by an estimator $\hat{\theta}$ in a sample.
- **Standard Error (**$se$**)**: The standard deviation of an estimator across repeated sampling: $$se(\bar{X}) = \frac{\sigma}{\sqrt{n}} \quad \text{or approximated as} \quad \widehat{se} = \frac{s}{\sqrt{n}} \quad \text{(when } \sigma \text{ is unknown)}$$
- **Estimator Properties**:
    - **Bias**: $E(\hat{\theta}) - \theta$ (desirable to be near $0$).
    - **Efficiency**: High precision with minimal variance/dispersion.

---
## **3. Estimation using Confidence Intervals**

- **Core Concept**: Transitioning from an interval that contains the sample mean $\bar{x}$ around $\mu$ to an interval that approximates the unknown population parameter $\mu$ from $\bar{x}$.
- **Confidence Level (**$1-\alpha$**) & Risk (**$\alpha$**)**: The long-run proportion of calculated intervals that successfully capture the true parameter.

### **3.a. Confidence & Risk Quantiles**

Common two-tailed critical values for the Standard Normal $Z \sim N(0,1)$:

| Confidence ($1-\alpha$) | Risk ($\alpha$) | Tail ($\alpha/2$) | Upper Quantile ($1-\alpha/2$) | Quantile Value      | R Command      |
| ----------------------- | --------------- | ----------------- | ----------------------------- | ------------------- | -------------- |
| **90%**                 | 0.10            | 0.05              | 0.95                          | $z_{0.95} = 1.645$  | `qnorm(0.95)`  |
| **95%**                 | 0.05            | 0.025             | 0.975                         | $z_{0.975} = 1.960$ | `qnorm(0.975)` |
| **99%**                 | 0.01            | 0.005             | 0.995                         | $z_{0.995} = 2.576$ | `qnorm(0.995)` |

### **3.b. Pivot Statistics for Inference**

- **Signal-to-Noise Ratio**: $$\text{Statistic } \hat{z} = \frac{\text{Signal}}{\text{Noise}} = \frac{\bar{x} - \mu_0}{\sigma / \sqrt{n}} \sim N(0,1)$$$$\text{Statistic } \hat{t} = \frac{\text{Signal}}{\text{Noise}} = \frac{\bar{x} - \mu_0}{s / \sqrt{n}} \sim t_{\nu} \quad \text{(Student's } t \text{ with } \nu = n-1 \text{ df)}$$
- **Variance Ratio**: $$\text{Statistic } \hat{F} = \frac{s_A^2}{s_B^2} \sim F_{\nu_1, \nu_2} \quad \text{(Fisher-Snedecor } F \text{ distribution)}$$

### **3.c. Assumptions for Inference**

1. **Random Sampling**: Independent and identically distributed (IID) variables from a random sample.
2. **Normality**: Required directly for small samples ($n < 30$), or guaranteed asymptotically by the Central Limit Theorem (CLT) when $n$ is large.
3. **Normality Verification**: Checked graphically using Normal Q-Q plots in R (`qqnorm(X)`, `qqline(X)`).

---
## **4.a. Confidence Intervals for One Parameter**

### **Confidence Interval of** $\mu$ **(Known** $\sigma$**)**

$$IC(\mu, 1-\alpha) = \bar{x} \pm z_{1-\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}$$

- **R Quantile**: $z_{1-\alpha/2}$ $\to$ `qnorm(1 - alpha/2)`
- **Requirements**: $X \sim N$ or sample size $n$ is "large".

### **Confidence Interval of** $\mu$ **(Unknown** $\sigma$**)**

$$IC(\mu, 1-\alpha) = \bar{x} \pm t_{n-1, 1-\alpha/2} \cdot \frac{s}{\sqrt{n}}$$

- **R Quantile**: $t_{n-1, 1-\alpha/2}$ $\to$ `qt(1 - alpha/2, n - 1)`
- **Notes**: Replaces $\sigma$ with sample deviation $s$ and normal $Z$ with Student's $t$ ($df = n-1$). For small $n$, the interval is wider due to added uncertainty from estimating $\sigma$.

### **Summary of Assumptions for** $\mu$:

| Condition                                | $\sigma$ Known | $\sigma$ Unknown                          |
| ---------------------------------------- | -------------- | ----------------------------------------- |
| $X \sim N$                               | Use Normal $Z$ | Use Student's $t_{n-1}$                   |
| $X$ **not Normal, but** $n$ **is large** | Use Normal $Z$ | Use Normal $Z$ (since $s \approx \sigma$) |

---
### **Confidence Interval of** $\pi$

Let $X \sim B(n, \pi)$ and $P = X/n$. By Central Limit Theorem convergence to Normal: $$IC(\pi, 1-\alpha) = P \pm z_{1-\alpha/2} \cdot \sqrt{\frac{\hat{\pi}(1-\hat{\pi})}{n}}$$

- **Assumption Check**: Verify $n\pi \ge 5$ and $n(1-\pi) \ge 5$ (or using sample proportions: $n P \ge 5$ and $n(1-P) \ge 5$).
- **Estimating** $\hat{\pi}$:
    - **Option A (Sample proportion)**: Use $\hat{\pi} = P \implies P \pm z_{1-\alpha/2} \cdot \sqrt{\frac{P(1-P)}{n}}$
    - **Option B (Conservative maximum variability)**: Set $\hat{\pi} = 0.5 \implies P \pm z_{1-\alpha/2} \cdot \sqrt{\frac{0.5(1-0.5)}{n}}$

---
### **Confidence Interval of** $\sigma^2$

Based on the Chi-square statistic $\frac{(n-1)s^2}{\sigma^2} \sim \chi^2_{n-1}$: $$IC(\sigma^2, 1-\alpha) = \left[ \frac{(n-1)s^2}{\chi^2_{n-1, 1-\alpha/2}}, \; \frac{(n-1)s^2}{\chi^2_{n-1, \alpha/2}} \right]$$

- **R Quantiles**: `qchisq(1 - alpha/2, n - 1)` and `qchisq(alpha/2, n - 1)`
- **Important Note**: Because the $\chi^2$ distribution is **asymmetric**, lower and upper quantiles must be evaluated separately rather than using $\pm$. This interval estimates **variance** $\sigma^2$, not standard deviation $\sigma$.

## **4.b. Confidence Intervals to Compare 2 Parameters**

### **Comparing Means ($\mu_1 - \mu_2$)**

- **Paired Samples (**$\mu_D = \mu_1 - \mu_2$**)**:
    - **Context**: Two measurements taken on the **same individuals** (e.g., before/after).
    - **Method**: Calculate differences $d_i = y_{1i} - y_{2i}$ and treat as **1 single sample** of differences with mean $\bar{d}$ and standard deviation $s_d$.
    - **Statistic**: $\hat{t} = \frac{\bar{d} - \mu_D}{se} \sim t_{n-1}$, where standard error $se = \frac{s_d}{\sqrt{n}}$.
    - **Formula**: $$\text{IC}(\mu_1 - \mu_2, 1-\alpha) = \bar{d} \pm t_{n-1, 1-\alpha/2} \cdot \frac{s_d}{\sqrt{n}}$$
    - **R Command**: `qt(1 - alpha/2, n - 1)` or `t.test(Y1, Y2, paired = TRUE)`.
- **Independent Samples (**$\mu_1 - \mu_2$**)**:
    - **Context**: Two separate random samples of sizes $n_1$ and $n_2$.
    - **Assumption**: Normal distributions and **equal variances** ($\sigma_1^2 = \sigma_2^2 = \sigma^2$).
    - **Pooled Variance**: $s^2 = \frac{(n_1 - 1)s_1^2 + (n_2 - 1)s_2^2}{(n_1 - 1) + (n_2 - 1)}$.
    - **Standard Error**: $se = s \cdot \sqrt{\frac{1}{n_1} + \frac{1}{n_2}}$.
    - **Formula**: $$\text{IC}(\mu_1 - \mu_2, 1-\alpha) = (\bar{y}_1 - \bar{y}_2) \pm t_{n_1+n_2-2, 1-\alpha/2} \cdot s \cdot \sqrt{\frac{1}{n_1} + \frac{1}{n_2}}$$
    - **R Command**: `qt(1 - alpha/2, n1 + n2 - 2)` or `t.test(Y1, Y2, paired = FALSE, var.equal = TRUE)`.

---
### **Comparing Proportions (**$\pi_1 - \pi_2$**)**

- **Context**: Two independent samples from binomial populations.
- **Standard Error**: $se = \sqrt{\frac{P_1(1-P_1)}{n_1} + \frac{P_2(1-P_2)}{n_2}}$.
- **Condition**: Requires large samples ($P \cdot n > 5$ and $(1-P) \cdot n > 5$) for Central Limit Theorem convergence.
- **Formula**: $$\text{IC}(\pi_1 - \pi_2, 1-\alpha) = (P_1 - P_2) \pm z_{1-\alpha/2} \cdot \sqrt{\frac{P_1(1-P_1)}{n_1} + \frac{P_2(1-P_2)}{n_2}}$$
- **R Command**: `qnorm(1 - alpha/2)`.

---
### **3. Comparing Variances (**$\sigma_1^2 / \sigma_2^2$**)**

- **Context**: Ratio of sample variances from two independent normal populations.
- **Statistic**: $\hat{F} = \frac{s_1^2 / \sigma_1^2}{s_2^2 / \sigma_2^2} \sim F_{n_1-1, n_2-1}$ (Fisher-Snedecor distribution).
- **Formula** (Note non-symmetric quantiles): $$\text{IC}\left(\frac{\sigma_1^2}{\sigma_2^2}, 1-\alpha\right) = \left[ \frac{s_1^2 / s_2^2}{F_{n_1-1, n_2-1, 1-\alpha/2}}, \; \frac{s_1^2 / s_2^2}{F_{n_1-1, n_2-1, \alpha/2}} \right]$$
- **R Command**: `qf(1 - alpha/2, n1 - 1, n2 - 1)` and `qf(alpha/2, n1 - 1, n2 - 1)`.

---
### **4.c. R Functions for Confidence Intervals**

- **Graphical Normality Check**: `qqnorm(X)` and `qqline(X)`.
- **Means**: `t.test(X, conf.level = 0.95)` or linear models `lm(Y ~ 1)` / `summary(lm(Y ~ 1))`.
- **2 Paired Means**: `t.test(Y1, Y2, paired = TRUE)`.
- **2 Independent Means**: `t.test(Y1, Y2, paired = FALSE, var.equal = TRUE)`.

---
## **5. Designs: How Data Is Obtained**

- **Experimental Studies ("DO")**:
    - Investigates interventions by randomly assigning decision variable $X$.
    - Random assignment guarantees independence from covariates $Z$.
    - Allows establishing **causal relationships** ($X \to Y$).
- **Observational Studies ("SEE")**:
    - Observes natural/real-world covariate values $Z$ without intervention.
    - Quantifies $Z$'s ability to reduce uncertainty in predicting response $Y$.
    - Covariates $Z$ may be correlated/collinear, leading to **confounded effects**.
    - Demonstrates **association/prediction**, NOT direct causality.

---
## **6. Descriptive Statistics Functions in R**

- **Univariate Numerical**:
    - Indicators: `length()`, `mean()`, `var()`, `sd()`, `median()`, `summary()`.
    - Graphics: `hist()`, `boxplot()`.
- **Univariate Categorical**:
    - Table & Plot: `table()`, `barplot(table())`.
- **Bivariate Numerical**:
    - Indicators & Plot: `cov(X,Y)`, `cor(X,Y)`, `plot(X,Y)`.