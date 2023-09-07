### Kaiki Bellini Barbosa - 32249969 
### Linus Leonan Kiche Madera - 32234961 
### Luana Miho Yasuda - 42148677

## Como compilar? 
gcc NomeDoArquivo.c -o NomeDoProgramaCompilado

## Rode o programa anterior para valores grandes de n. As mensagens sempre estarao ordenadas pelo valor de i?
Nao, nem sempre, pois um processo pode acabar antes do outro, nos testes a ordem seguida sempre foi a do valor de I pois a maquina nao estava executando outras tarefas, executar esse codigo em uma maquina que esteja ja com diversos outros processos executandos fara com que as mensagens saiam nao na mesma ordem do valor de i.

## O que acontece se o programa anterior escreve-se as mensagens para sys.stdout, usando print, ao inves de para sys.stderr?

Se o programa anterior escrevesse as mensagens para sys.stdout usando print, em vez de para sys.stderr, as mensagens ainda seriam exibidas na saida padrao.
sys.stdout e sys.stderr são buffers diferentes. Isso significa que a ordem em que as mensagens sao exibidas pode acabar sendo diferente, apesar de no teste executado, como o computador nao estava ocupado o suficiente, mesmo com altos valores as mensagens foram impressas em ordem.
Tem que ser levado em conta que sys.stderr costuma ser normalmente usado para mensagens de erro e diagnostico e a sys.stdout é usado para a saida normal do programa.
