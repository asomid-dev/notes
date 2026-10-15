# Formulari Maple – M2

El examen de taller consiste en 10 preguntas sacadas de los cuestionarios que habéis hecho durante el curso. Son exactamente las mismas, y de todos los cuestionarios que habéis hecho, son 10 aleatorias. Podéis usar Maple (una herramienta matemática, rollo calculadora pero más potente y con funciones ya hechas) y un formulario para resolverlos.

---

## Para instalar Maple

- Entrad en [https://www.maplesoft.com/download/](https://www.maplesoft.com/download/) o buscad "Maple download"
- Entrad en [https://distribuciosoftware.upc.edu/estudiants/maple/](https://distribuciosoftware.upc.edu/estudiants/maple/), poned vuestras credenciales de la UPC y copiad el código que os sale en la página anterior y descargadlo.

---

## Primeros pasos

- Cuando entres te saldrá la pantalla de inicio. Dale a **"New Worksheet"**.
- Para usar algunas de las funciones para el examen es necesario incluir algunas librerías (las del formulario de abajo). Es recomendable ponerlas todas al inicio para así no tener que ponerlas después.

---

## Mi primera función

En general, es recomendable definir funciones y variables para trabajar. Para declarar una función:

- Escribir en la línea: `f := 2*x + 1`
- Darle al Enter; debería ponerse azul.
- A partir de ahí puedes usar `f` para referirte a la función declarada. Lo mismo con las variables.

---

## Consejos

- Maple tiene muy buena memoria. Si asignaste `x := 5` al principio de tu documento, `x` seguirá valiendo 5 horas después en la línea 100, arruinando tus ecuaciones algebraicas. Acostúmbrate a escribir `restart` para borrar la memoria cuando quieras hacer una nueva operación. Pero cuidado, que también restablece las librerías.
- Si no te acuerdas de cómo se escribe un comando, simplemente pon un signo de interrogación `?` pegado al nombre del comando y presiona Enter.
- Dale al símbolo `!!!` (Execute worksheet) para ejecutar un seguido de comandos.
- Puedes referirte a una ecuación o comando clicando dos veces sobre el número a la derecha.
- Si te sale un número en expresión (⅔, sqrt(3)...) y quieres el número decimal, usa `evalf()`.
- Para expandir un resultado tipo `(18*(x - 2)^5)/25`, usa `expand()`.
- Si quieres definir funciones de verdad (que les puedas poner un valor y que lo evalúen, por ejemplo para hacer composición de funciones `f(g(x))`), tienes que definirlo así: `h := x -> x^2 + 1`.

---

## General

| Declarar función   | Evaluar decimal | Simplificar   | Evaluar en punto           |
| ------------------ | --------------- | ------------- | -------------------------- |
| `f := x^2 + x + 1` | `evalf(f)`      | `simplify(f)` | `eval(fx, [x = a, y = b])` |

---

## Librerías

```maple
with(Student[Calculus1]);
with(Student[NumericalAnalysis]);
with(plots);
```

---

## Ecuaciones e inecuaciones

**General:**

```maple
solve(f);
```

**Inecuación con valor absoluto (caso complejo):**

```maple
a := 5;
b := 10;
f := abs(x - a) + abs(x - b) <= k;
solve(f, x) assuming k <= abs(a - b);
cota := max(a, b) + (k - abs(a - b)) / 2;
```

> Si la condición de `k` es un `=`, ej. `k = |a − b|`, no usar `assume` para encontrar cotas.

---

## Sucesiones y límites

**Límites:**

```maple
limit(f, n = infinity);
```

**Límites con parámetros:**

```maple
restart;
v := 0;
assume(a < 0);
limit(f, n = infinity);
```

**Sucesiones (tipo L = x + L, crecimiento):**

```maple
a := Array(1..50);
a[1] := 3;
for n from 2 to 50 do
    a[n] := sqrt(7 + a[n - 1]);
end do;
seq(evalf(a[n]), n = 1..50);
```

> O haciendo `L = x + L`.

---

## Bisección, secante y Newton

**Bisección:**

```maple
Bisection(f, x = [-1, 0], tolerance = 0.00001, maxiterations = 100, stoppingcriterion = absolute, output = plot);
```

**Secante:**

```maple
Secant(f, x = [3.5225, 3.2475], tolerance = 0.00001, maxiterations = 100, stoppingcriterion = absolute, output = plot);
```

**Newton:**

```maple
ModifiedNewton(f, x = 0.702, tolerance = 0.1e-5, maxiterations = 100, stoppingcriterion = absolute, output = plot);
```

**Raíces:**

```maple
Solve(f' = 0);
```

---

## Taylor

**Polinomio de Taylor:**

```maple
TaylorPolynomial(f, x = 0, order = 5); expand();
```

**Lagrange (con error):**

```maple
result := TaylorPolynomial(f, x = 0, order = 2, errorboundvar = 'r');
```

**Plots:**

```maple
plot(f);  # y la que se parezca a la última
```

**Acotación del error:**

$$\frac{1}{n+1} \left(\frac{1}{3}\right)^{n+1}$$

> [^1] En M2, máximo valor posible. En trigonométricas = 1. Ver en qué intervalo crece y usar los intervalos de la integral.

---

## Integració

```maple
int(f - g, x = -1..4, numeric);
```

**Trapecios:**

$$\int_a^b f(x),dx \cong T_n = \frac{b-a}{n}\left(\frac{f(x_0)+f(x_n)}{2} + \sum_{i=1}^{n-1} f(x_i)\right)$$

$$x_i = a + i \cdot \frac{b-a}{n}, \quad i = 0, \ldots, n$$

```maple
ApproximateInt(f, x = 9/4..93/20, output = plot,
    partition = 6, partitiontype = normal, method = trapezoid);
```

**Simpson:**

$$\int_a^b f(x),dx \cong S_n = \frac{b-a}{3n}\left(f(a)+f(b)+4\sum_{i=1}^{n} f(x_{2i-1})+2\sum_{i=1}^{n-1} f(x_{2i})\right)$$

$$x_i = a + i \cdot \frac{b-a}{n}, \quad i = 0, \ldots, n$$

> **Atención:** `n` debe ser par.[^2]

```maple
ApproximateInt(f, x = 9/4..93/20, output = plot,
    partition = 6, partitiontype = normal, method = simpson);
```

**Error Trapecios:**

$$\varepsilon \leq \left|\frac{(b-a)^3}{12 \cdot n^2} \cdot M_2\right| ;\rightarrow; n \leq \sqrt{\frac{(b-a)^3}{12 \cdot \varepsilon} \cdot M_2}$$

**Error Simpson:**

$$\varepsilon \leq \left|\frac{(b-a)^5}{180 \cdot n^4} \cdot M_4\right| ;\rightarrow; n \leq \sqrt[4]{\frac{(b-a)^5}{180 \cdot \varepsilon} \cdot M_4}$$

---

## Varias Variables

**Derivadas parciales:**

```maple
diff(f, x, y$2);
```

**Curvas de nivel:**

```maple
contourplot(f, x = -3..3, y = -3..3);  # sin la función de fuera
```

**Plano tangente:**

$$z = f(a,b) + \frac{\partial f}{\partial x}(a,b)(x-a) + \frac{\partial f}{\partial y}(a,b)(y-b)$$

$$z = a \cdot x + b \cdot y + A; \quad (x, y, z)$$

```maple
# Definir f como función de dos variables:
f := (x, y) -> ...;

# Calcular derivadas:
derivadas: diff(f(x, y), x);  diff(f(x, y), y);

# Evaluar en el punto (a, b):
eval(fx, [x = a, y = b]);  # donde a es el primer punto dado y b el segundo
```

**Gradientes:**

$$\nabla f = \left(\frac{\partial f}{\partial x},, \frac{\partial f}{\partial y}\right)$$

$$D = \nabla f(p_1, p_2) \cdot v(v_1, v_2)$$

$$D(x,y) = p_1 \cdot v_1 + p_2 \cdot v_2$$

- La flecha indica hacia dónde crece.
- Mirar la dirección de ∇ y buscar un `u` paralelo o perpendicular.
- Si `D > 0` → crece
- Si `D < 0` → decrece
- Si `D = 0` → estable

**Evaluar punto (Hessiano):**

```maple
fx  := diff(f(x, y), x);
fy  := diff(f(x, y), y);
eval(fx, [x = 2, y = -1]);
eval(fy, [x = 2, y = -1]);
fxx := diff(f(x, y), x, x);
fyy := diff(f(x, y), y, y);
fxy := diff(f(x, y), x, y);
D_hessiano := fxx * fyy - fxy * fxy;
```

- Si `D < 0` → punto de silla
- Si `D > 0` y `fxx > 0` → mínimo local
- Si `D > 0` y `fxx < 0` → máximo local

**Máximo/Mínimo con restricciones:**

```maple
with(Optimization);
restricciones := {condiciones};
Maximize(f(x, y), restricciones);
```

---

[^1]: En M2, máximo valor posible. En trigonométricas = 1. Ver en qué crece y usar los intervalos de la integral. [^2]: El número de usos de Simpson debe ser par.