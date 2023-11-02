# README - Cálculo do Valor de Pi Utilizando Pthreads e Mutex
Kaiki Bellini Barbosa - 32249969
Linus Leonan Kiche Madera - 32234961
Luana Miho Yasuda - 42148677

## Descrição

Este programa realiza a aproximação do valor de π utilizando uma série matemática e paralelização com pthreads.
A versão inicial, sem mutex para sincronização, apresentou valores de π inconsistentes.
A implementação com mutex corrige isso evitando as condições de corrida.

## Resultados(os prints estão no mesmo diretório)

### Execução Sem Mutex

- Quantidade de threads: 4
- Valores de π variaram de forma inconsistente:

```
Execucao (sem mutex) numero 1 - valor de pi: 3.120734
Execucao (sem mutex) numero 2 - valor de pi: 2.912573
Execucao (sem mutex) numero 3 - valor de pi: 3.128943
Execucao (sem mutex) numero 4 - valor de pi: 3.117326
Execucao (sem mutex) numero 5 - valor de pi: 3.150874
Execucao (sem mutex) numero 6 - valor de pi: 0.015940
Execucao (sem mutex) numero 7 - valor de pi: 2.816034
Execucao (sem mutex) numero 8 - valor de pi: 3.173633
```

### Execução Com Mutex

- Quantidade de threads: 4
- Valores de π consistentes e precisos:

```
Execucao numero 1 - Valor calculado para pi: 3.141592
Execucao numero 2 - Valor calculado para pi: 3.141592
Execucao numero 3 - Valor calculado para pi: 3.141592
Execucao numero 4 - Valor calculado para pi: 3.141592
Execucao numero 5 - Valor calculado para pi: 3.141592
Execucao numero 6 - Valor calculado para pi: 3.141592
Execucao numero 7 - Valor calculado para pi: 3.141592
Execucao numero 8 - Valor calculado para pi: 3.141592
```

## Conclusão

O uso de mutex eliminou as divergências nos valores de π calculados, uma vez que a condição de corrida foi removida.
