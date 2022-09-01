# 
# UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
# INGENIERÍA DE SOFTWARE
# 	AUTORES:
  # 		Dylan Hernández
# 		Andrés Almeida
# 		Juan Reyes
# 		Brandon Masacela
# 		GRUPO: 3
#    FECHA DE CREACION:        Martes, 16 de agosto de 2022 07:41 p.m.
#    FECHA DE MODIFICACION:    Jueves, 18 de agosto de 2022 05:37 p.m.
#  * --------------------------
  #  * Planteamiento: Imprimir las Complejidades Temporales de distintos programas
#  * en las herramientas MATLAB y R.
#  * --------------------------
  #  * Este programa incorpora:
  #  * Complejidad Constante O(1) - Hash Abierto / Agregar Datos a la Tabla
#  * Complejidad Lineal O(n) - Imprimir los datos de una Lista Doble
#  * Complejidad Polinómica O(n³) - Pascal
#  * Complejidad Exponencial O(2^n) - Fibonacci
#  * Complejidad Logarítmica O(log n) - Problema de la Dicotomía
#  * Complejidad Factorial O(n!) - Factorial
#  */
  
# Complejidad Constante O(1) - Hash Abierto / Agregar Datos a la Tabla
y <- scan('hash.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
pred<- rep(mean(y),N)
plot(x,y,col='firebrick',main='Complejidad Constante(1)')
lines(x,pred,col='firebrick',lwd=2)

#  Complejidad Lineal O(n) - Imprimir los datos de una Lista Doble
y <- scan('lista.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
model <- lm(y ~ poly(x,1))
pred<- predict(model)
plot(x,y,col='chocolate',main='Complejidad Lineal O(n)')
lines(x,pred,col='aquamarine',lwd=2)

#  Complejidad Polinómica O(n³) - Pascal
y <- scan('pascal.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
model <- lm(y ~ poly(x,3))
pred<- predict(model)
plot(x,y,col='darkorchid',main='Líneas del Triángulo de Pascal vs. Tiempo (en s).'
     ,xlab='Número de Líneas'
     ,ylab = 'Tiempo (en Segundos)')
lines(x,pred,col='chocolate',lwd=1)

#  Complejidad Exponencial O(2^n) - Fibonacci
y <- scan('minimos.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
model <- lm(formula = log(y) ~ x)
pred<- predict(model)
plot(x,y,col='chocolate',main='Complejidad Exponencial O(2^n) - Fibonacci')
lines(x,y,col='chocolate',lwd=2)

#  Complejidad Logarítmica O(log n) - Problema de la Dicotomía
y <- scan('dicotomia.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
model <- lm(formula = y ~ log(x))
pred<- predict(model)
plot(x,y,col='black',main='Complejidad Logarítmica O(log n) - Dicotomía')
lines(x,pred,col='aquamarine4',lwd=2)

#  Complejidad Factorial O(n!) - Cálculo de un Factorial
y <- scan('factorial.txt')
N <- length(y)
x <- seq(from=1,to=N,by=1)
x1 <- seq(from=1,to=N,by=0.1)
pred<- factorial(x1)/(100000*(x1-1))
plot(x,y,col='darkgoldenrod',main='Complejidad Factorial O(n!) - Factorial')
lines(x1,pred,col='deepskyblue4',lwd=2)
