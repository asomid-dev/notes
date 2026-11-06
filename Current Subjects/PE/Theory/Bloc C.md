# Bloc C
#pe #apunts #english #PARCIAL2
## Descriptive Statistics
Will be done on R.
- Table
- Plot
- Chart
- Residual plot

## 1. Statistical Inference

- We must provide evidence based on data
<span style="color:rgb(161, 87, 28)">For example, saying “my program works” requires evidence/data.</span>
- It must be <span style="color:rgb(33, 78, 129)">reproducible</span>: only reproducible results might be of interest
<span style="color:rgb(161, 87, 28)">For example, a</span> <span style="color:rgb(33, 78, 129)">miraculous</span> <span style="color:rgb(161, 87, 28)">cure will not be useful for future patients.</span>
- It must be <span style="color:rgb(33, 78, 129)">transparent</span>
<span style="color:rgb(161, 87, 28)">to enable others to replicate the same results.</span>
- <span style="color:rgb(33, 78, 129)">We infer</span> the characteristics of the <span style="color:rgb(33, 78, 129)">population</span> from a <span style="color:rgb(33, 78, 129)">Random Sample (RS)</span>
<span style="color:rgb(161, 87, 28)">For example, I can infer the population-wide connection speed from a random sample of speeds.</span>
$$\text{Sample} \to \text{Population}$$

### Risks 
- The scientific and technical (statistical) method:

	- by <span style="color:rgb(33, 78, 129)">deduction</span> $\to$ data collection design (population $\to$ RS)
	- by <span style="color:rgb(33, 78, 129)">induction</span> $\to$ inferring results (RS $\to$ population)

- Statistical inference defines and quantifies the risks of this process
<span style="color:rgb(161, 87, 28)"><i>Using a random sample to estimate unknown population parameters and quantify uncertainty/error.</i> </span> 

- The **evidence** provided by **data** ends with **the analysis**:
	- "My program works well"
		- estimating a measure (e.g., **average** performance) and <span style="color:rgb(192, 0, 0)">its error</span>.
	- "My program improves the results of..."
		- estimating performance improvement (e.g., **mean difference**) and <span style="color:rgb(192, 0, 0)">its error</span>.

### Types of Variables
To analyse the relationship between variables, we must establish the role of each one:

- Response Y. Measuring goal achievement (sometimes it can be an indirect measure.)
<span style="color:rgb(161, 87, 28)">E.g., performance <b><i>Y</i></b> measured for a subject.</span>

- Decisions X. We assign their values in experimental studies.
They represent the potential to change the future: we want to measure the **effect** of _**X**_ on _**Y**_.
An experimental design allows the **X** to be independent of other variables.
<span style="color:rgb(161, 87, 28)">E.g., a teaching method based on <b>printed lists</b> of exercises <b>(<i>X</i>=1)</b> compared with a method based on <b>e-status (<i>X</i>=2)</b></span>

- Co-variables Z. These represent the conditions observed in _real_ data. 
We can use _**Z**_ to reduce the uncertainty of _**Y**_ (we will have to quantify its success).
We can obtain _**Z**_ in both experimental and observational studies.
_**Z**_ are usually interrelated (_colinear or non-orthogonal_).
<span style="color:rgb(161, 87, 28)">E.g., the marks of two previous subjects <b>(<i>Z1, Z2</i>)</b> usually have a certain relationship.</span> 

### Types of Study

- DO: Experimental studies 
We want to change the future Y through interventions in X.
In the analysis we estimate the effects of X on Y.
<span style="color:rgb(161, 87, 28)">E.g., To try to improve the marks <b><i>Y</b></i>, we assign at random the students different work environments <i><b>X</i></b>.</span>

- SEE: Observational studies
They allow us _**to predict Y**_ from the observed values _**Z**_.
We will quantify the **capacity** of _**Z**_ for **reducing** the **uncertainty** in the prediction of _**Y**_

<span style="color:rgb(161, 87, 28)">E.g., we compare the prediction of <b><i>Y</b></i> according to <b><i>Z1</b></i> or according to <b><i>Z2</b></i>, or depending on a certain <b>model m</b> of the two variables <b>m=f(Z1, Z2)</b>.  </span>
<span style="color:rgb(161, 87, 28)"><b>→</b> <i>The group <b>Z1</b> reduces the uncertainty by 10%; <b>Z2</b> by 20%; and the model <b>m</b>, with both, by 25%.</i></span> 

- **Parameter**: an indicator of the **population** that we wish to know or estimate. 
<span style="color:rgb(161, 87, 28)">E.g., the expectation (μ) of the heights of FIB students.</span>

- **Statistic**: any indicator that is obtained as a function of the data of a **sample**. 
<span style="color:rgb(161, 87, 28)">E.g., the sum of the heights of the students in a sample.  </span>

- **Estimator**: a statistic of a **sample** used to know the value of a parameter of the **population**. 
<span style="color:rgb(161, 87, 28)">E.g., the average height in a random sample of FIB students is an estimator of the expectation (μ) of the heights of FIB students.</span> 

> [!INFO] NOTE
> 
> _**Mean**_ may mean _**expectation parameter**_ regarding the centre of gravity of the population distribution, or _**statistical mean**_ regarding the average of a series of values obtained from a sample.


## 2. Point Estimation

- An estimator $\hat{\theta}$ of the unknown parameter $\theta$ from the sample M($\omega_{i}$) ($X_{1},X_{2},\dots,X_{n}$) (_a simple random sample defined in the appendix to Section B_) is a function of the RVs:

- **Point estimation**: the value that the estimator $\hat{\theta}$ takes in a specific sample
E.g., $\bar{x}=\frac{\sum x_{i}}{n}$ is the sample mean and is a **point estimate** of $\mu$.
Distinguish between the value $\bar{x}$ (small letter) of a specific simple random sample and the sample mean random variable $\bar{X}$ (capital letter).

- Standard error: the variability of the estimator. In the above case of MEAN, the standard error of the mean (or mean standard error, or SE) is
$$se=\sqrt{ V(\bar{X}_{n}) }=\sqrt{ E[(\bar{X}_{n}-\mu)^{2}] }=\frac{\sigma}{\sqrt{ n }}$$
Generally, the σ will be unknown and the standard error will have to be approximated using the corresponding estimator ($\hat{\sigma}$) with the sample data: $\hat{se}=\frac{\hat{\sigma}}{\sqrt{ n }}=\frac{s}{\sqrt{ n }}$ (with s the point estimator of $\sigma$).

### Cases

| Parameter ($\theta$) (**POPULATION**)                                          | Estimator ($\hat{\theta}$) (**SAMPLE**)                      |
| ------------------------------------------------------------------------------ | ------------------------------------------------------------ |
| $\mu$ (expectation, population mean)                                           | $\bar{x}$ (sample mean)                                      |
| $\sigma^{2}$ (population variance)<br>$\sigma$ (population standard deviation) | $s^{2}$ (sample variance)<br>$s$ (sample standard deviation) |
| $\pi$ (probability)                                                            | **p** (proportion)                                           |
MEAN: 
$\bar{x}=\frac{\sum^{n}_{{i=1}}x_{i}}{n}$ The sample mean is a point estimate of the parameter $\mu$ of central tendency.

STANDARD DEVIATION: 
$s=\sqrt{ \frac{\sum^{n}_{i=1}(x_{i}-\bar{x})^{2}}{n-1} }$ The sample standard deviation is a poijnt estimate of the parameter $\sigma$ of dispersion.

PROPORTION:
$p=\sum_{i,x_{i}=1}1 / n$ The sample proportion is a point estimate of the parameter $\pi$.

PROPERTIES: (see appendix)

### Descriptive statistics

- Estimators proprieties: Parameters could have different estimators (approximations to the punctual unknown value) and have a margin of error depending of the sample. So we could compare in base to some proprieties:
	- **Bias** that it's preferable to be near 0 in order to assure that the expected value will fit the real value
	- **Efficiency** that it's preferable to be high pointing out more precision and less dispersion
	- other proprieties like consistency, ...

The previous punctual estimators are what is called Descriptive Statistics to summarise data numerically

## 3. Estimation using confidence intervals
- We know how to calculate an "interval" that contains $\bar{x}$ from $\mu$. But the real problem is to approximate $\mu$ from $\bar{x}$ (i.e.)

## 4.a. Confidence interval for one parameter

### Confidence interval of $\mu$ (with known $\sigma$)
Z test
$Z_{\alpha / 2}, \frac{\sigma}{\sqrt{ n }}$
Normally distributed.
### Confidence interval of $\mu$ (with unknown $\sigma$)
t-test
$S \to \text{sample deviation}$.
Approx. Normally
$$IC(\mu, 1-\alpha)=\bar{x}\pm t_{n-1,1-\frac{\sigma}{2}} \cdot \frac{s}{\sqrt{ n }}$$
 
(R: $t_{n-1, 1-\frac{\sigma}{2}}$: `qt(1-alpha/2, n-1)`)

### Confidence interval of $\mu$. Assumptions

To guarantee the confidence level of the IC, certain premises must be met.
The fundamental premise is that the origin of the sample must be random.
In addition:
- If sigma known, one of the following two conditions is requires:
	- X~N $\to$ since the linear combination of normals is also normal ($\bar{X}$~N)
	- The sample is "large" $\to$ by the CLT, $\bar{X}$~N

### Confidence interval of $\pi$
$\implies$ If one experiment generate some sample with the $\bar{p}=0.7$
$\implies$ IC with 90%
$$IC(\pi,1-\alpha)=P\pm z_{1-\frac{\alpha}{2}}\sqrt{ \frac{\hat{\pi}(1-\hat{\pi})}{n} }$$
As a summary guide, check that $\pi \times n \geq 5$ and $(1-\pi)\times n \geq 5$

For block T, it is recommended to use 
a) $P$ as $\hat{\pi}$ $IC(\pi,1-\alpha)=P\pm z_{1-\alpha / 2}\cdot \sqrt{ (P(1-P)) / n }$
b) Maximum $\hat{\pi}$ value (0.5) $IC(\pi,1-\alpha)=P\pm z_{1-\alpha / 2} \cdot \sqrt{ (0.5(1-0.5)) / n }$
### Confidence interval of $\sigma^{2}$

If $X_{i}\to N$ ~ $X^{2}_{n-1}$

We can relate the variance ratio statistic (S2/$\sigma$ 2) to a $X^{2}$ as the sum squared normal variables is $X^{2}$ (see models derived from the normal in the Appendix to Section B).

$$IC(\sigma ^{2}, 1-\alpha)=\left[ \frac{s^{2}(n-1)}{X^{2}_{n-1},1 - \frac{\sigma}{2}} , \frac{s^{2}(n-1)}{X^{2}_{n-1, \frac{\sigma}{2}}}\right]$$
