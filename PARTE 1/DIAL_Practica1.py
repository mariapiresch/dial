#!/usr/bin/env python3
# -*- coding: utf-8 -*-



'''

    PRÁCTICA 1: ANÁLISIS DE LA EFICIENCIA DE ALGORITMOS (PYTHON)

    ASIGNATURA: DISEÑO DE ALGORITMOS
    CURSO:      2022-2023
    SUBGRUPO:   U1 / U2

    APELLIDOS:  Pires Choupina
    NOMBRE:     María

'''



import matplotlib.pyplot as plt
import numpy as np
import timeit
import time
import random



# EJEMPLO: MÁXIMO COMÚN DIVISOR



def mcd_rec(a, b):
    
    if a > b :
        return mcd_rec(a - b, b)
    elif a == b :
        return a
    else :
        return mcd_rec(a, b - a)



def mcd_rec2(a, b):
    
    if b == 0 :
        return a
    else :
        return mcd_rec2(b, a % b)
    
    

def mcd_iter(a, b):
    
    a1 = a
    b1 = b
    
    while a1 != b1 :
        
        if a1 > b1 :
            a1 = a1 - b1
        else :
            b1 = b1 - a1
            
    return a1



def main():
    
    MAX_LEN = 500  # Maximum length of input list.

    # Initialise results containers:
    
    lengths_mcd_rec  = []
    times_mcd_rec    = []
    
    lengths_mcd_rec2 = []
    times_mcd_rec2   = []
    
    lengths_mcd_iter = []
    times_mcd_iter   = []
    

    for length in range(0, MAX_LEN, 10):
        
        # Generate random values:
        
        a = random.randint(length, 10*length)
        b = random.randint(length, 10*length)

        # Time execution (mcd_rec):
        
        start = time.perf_counter()
        mcd_rec(a, b)
        end = time.perf_counter()

        # Store results (mcd_rec):
        
        lengths_mcd_rec.append(length)
        times_mcd_rec.append(end - start)

        # Time execution (mcd_rec2):
        
        start = time.perf_counter()
        mcd_rec2(a, b)
        end = time.perf_counter()

        # Store results (mcd_rec2):
        
        lengths_mcd_rec2.append(length)
        times_mcd_rec2.append(end - start)
        
        # Time execution (mcd_iter):
        
        start = time.perf_counter()
        mcd_iter(a, b)
        end = time.perf_counter()

        # Store results (mcd_iter):
        
        lengths_mcd_iter.append(length)
        times_mcd_iter.append(end - start)
        
        
        
    # Plot results
    
    plt.style.use("dark_background")
    plt.figure().canvas.manager.set_window_title("Algoritmos de MCD - Time Complexity")
    plt.xlabel("List Length")
    plt.ylabel("Execution Time (s)")
    plt.plot(lengths_mcd_rec, times_mcd_rec, label="mcd_rec()")
    plt.plot(lengths_mcd_rec2, times_mcd_rec2, label="mcd_rec2()")
    plt.plot(lengths_mcd_iter, times_mcd_iter, label="mcd_iter()")
    plt.legend()
    plt.tight_layout()
    plt.show()
    
    
    # Polynomial fit
    
    ns = np.linspace(1, 100000, 100, dtype = int)
    ts = [timeit.timeit('mcd_rec2(lst[0], lst[len(lst) - 1])',
                    setup='lst=list(range({})); random.shuffle(lst)'.format(n),
                    globals=globals(),
                    number=1000)
          for n in ns]

    plt.plot(ns, ts, 'or')

    degree = 5
    coeffs = np.polyfit(ns, ts, degree)
    p = np.poly1d(coeffs)
    plt.plot(ns, [p(n) for n in ns], '-b')



'''

EJERCICIO: Programa en Python los algoritmos 'queHace1', 'queHace2' y 'queHace3'
que has programado anteriormente en C++. Usa el código anterior para visualizar 
los tiempos de ejecución de estos tres programas, para determinar cuál es más 
eficiente en la práctica, así como para visualizar la función de coste que 
define, para cada algoritmo, su orden de complejidad.

'''
    
