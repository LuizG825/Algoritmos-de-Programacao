//Inclus�o das bibliotecas necess�rias para o funcionamento do c�digo: 

//Biblioteca padr�o
#include <stdio.h>
//Biblioteca matem�tica para o uso da fun��o exponencial "pow(vari�vel base, vari�vel expoente)" e  da fun��o raiz quadrada "sqrt(vari�vel)"
#include <math.h>

//Inicio do c�digo: fun��o main
int main(){

//Inicializa��o das vari�veis em double para armazenar os valores com precis�o
  double a, b, c;

//Fun��o scanf para armazenar os valores das vari�veis na mem�ria
  scanf("%lf %lf %lf",&a,&b,&c);

//If else para separar os casos inv�lidos dos casos v�lidos
//De acordo com a formula, se "ax^2 = 0"  ent�o n�o � poss�vel calcular
//Portanto se a = 0 o programa ir� imprimir na tela a mensagem "Impossivel calcular" e encerrar o processo
  if (a == 0) {
    printf("Impossivel calcular\n");
  }
//Caso seja v�lido � inicializada a vari�vel delta que executa a primeira parte da formula com a fun��o pow
    else {
    double delta;
    delta = pow(b,2) - 4 * a * c;

//De acordo com a formula se o delta for negativo n�o � poss�vel calcular
//Portanto o if else separa o caso inv�lido do v�lido, assim como anteriormente
    if (delta < 0) {
      printf("Impossivel calcular\n");
    } 
//Caso seja v�lido o else inicia duas vari�veis, x1 e x2, que ser�o o resultado do calculo
      else {
      double x1, x2;

//Uso final da formula de bhaskara com o uso da fun��o sqrt e impress�o dos resultados com a fun��o printf
      x1 = (-b + sqrt(delta)) / (2 * a);
      printf("R1 = %.5lf\n",x1);
      x2 = (-b - sqrt(delta)) / (2 * a);
      printf("R2 = %.5lf\n",x2);
    }
  }

//fim do programa
  return 0;
}


