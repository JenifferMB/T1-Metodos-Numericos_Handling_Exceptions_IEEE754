# t1_metodos_numericos
Trabalho 1 da disciplina Métodos Numéricos, Professor: Joao Batista Souza de Oliveira - PUCRS

Seu primeiro trabalho nesta disciplina consiste em explorar o padrão IEEE-754. Você deve
implementar um programa que cumpra as seguintes tarefas:
1. Ele recebe pela linha de comando uma expressão no formato
val₁ op val
onde op é uma operação (+,-, */) e val₁ e val, são dois valores em ponto flutuante, NaN
ou too.
2. Depois de receber a expressão seu programa deve realizar a operação op e mostrar o resultado
dela;
3. Seu programa também deve mostrar a configuração de bits das duas variáveis e do resul-
tado. Tome cuidado com a en di anness do seu processador para que a saída seja apresentada
corretamente;
4. Seu programa também deve informar se alguma exceção do padrão IEEE-754 foi sinalizada
quando a operação foi feita.
Por exemplo, seu programa poderia funcionar assim:

python3 meucalculeitor.py 21 / -0
Recebi 21.000000 / -0.000000 e resultado deu -inf
val1 = 0 10000011 01010000000000000000000 = 21
val2 = 1 00000000 00000000000000000000000 = -0
res = 1 11111111 00000000000000000000000 = -inf
Exceção FE INEXACT: 0
Exceção FE_DIVBYZERO: 4
Exceção FE UNDERFLOW: 0
Exceção FE_OVERFLOW: 0
Exceção FE_INVALID: 0
