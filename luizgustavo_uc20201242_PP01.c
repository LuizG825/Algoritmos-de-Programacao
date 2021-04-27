//Nomecompleto: Luiz Gustavo da Costa Gon�alves Matr�cula: UC20201242 Curso: Ci�ncia da Computa��o
#include<stdio.h> //Biblioteca que disponibiliza entrada e sa�da de dados dentro do programa.
#include<locale.h> //Biblioteca que cont�m opera��es comuns como tratamento de entrada/sa�da e cadeia de caracteres.
#include<stdlib.h> //Biblioteca que envolve aloca��o de mem�ria, controle de processos, convers�es e outras fun��es.
#include<string.h> //Biblioteca que fornece fun��es, macros e defini��es para manipula��o de cadeias de caracteres e regi�es de mem�ria.

int main()
{
    //O nome das vari�veis foi escolhido com base no conceito de serem claras no seu proposito, como no livro c�digo limpo.
    int quantidade_de_sessoes; //Vari�vel do tipo inteiro para armazenar a quantidade de sess�es que o cinema apresentou.
    int quantidade_de_pessoas; //Vari�vel do tipo inteiro para armazenar a quantidade de pessoas que compareceram as sess�es.
    int quantidade_masculino = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de pessoas do sexo masculino que compareceram as sess�es.
    int quantidade_feminino = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de pessoas do sexo feminino que compareceram as sess�es.
    int quantidade_de_criancas = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de crian�as que compareceram as sess�es.
    int quantidade_de_adolescentes = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de adolescentes que compareceram as sess�es.
    int quantidade_de_adultos = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de adultos que compareceram as sess�es.
    int quantidade_de_idosos = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de idosos que compareceram as sess�es.
    int quantidade_adultos_m = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de adultos do sexo masculino que compareceram as sess�es.
    int quantidade_adultos_f = 0; //Vari�vel do tipo inteiro para armazenar a quantidade de adultos do sexo feminino que compareceram as sess�es.
    int idade; //Vari�vel do tipo inteiro para armazenar a idade das pessoas que compareceram as sess�es.
    int i; //Vari�vel do tipo inteiro para armazenar valores genericos.
	double avaliacao = 0; //Vari�vel do tipo double para armazenar as avalia��es individuais do filme.
    double avaliacao_total = 0; //Vari�vel do tipo double para armazenar a soma das avalia��es individuais do filme.
    double valor_do_ingresso; //Vari�vel do tipo double para armazenar o valor do ingresso.
    char nome_do_filme[50]; //Vari�vel do tipo char para armazenar o nome do filme.
    char genero; //Vari�vel do tipo char para armazenar o g�nero das pessoas que compareceram as sess�es.
    char escolha; //Vari�vel do tipo char para armazenar a escolha final de ver mais estat�sticas sobre as sess�es.

    setlocale(LC_ALL,"Portuguese"); //Fun��o da biblioteca locale.h que habilita o uso de acentua��o da lingua portuguesa nos printfs.

    //Printfs para intera��o com o usu�rio.
    printf("Seja Bem-vindo ao aplicativo de estat�sticas!\n\n");
    printf("Para come�ar insira a quantidade de sess�es do filme que deseja analisar.\n");
    printf("Lembrando que para o funcionamento correto do aplicativo � necessario analisar 2 sess�es.\n");
    printf("\nInsira a quantidade de sess�es: ");
    scanf("%d", &quantidade_de_sessoes); //Armazenamento da quantidade de sess�es que ser�o utilizadas para a coleta de dados.

    //Verifica��o da vari�vel quantidade_de_pessoas.
    do
    {
        if(quantidade_de_sessoes < 2 || quantidade_de_sessoes > 2)
        {
            printf("\nVoc� inseriu \"%d\", essa quantidade � inv�lida.\n", quantidade_de_sessoes);
            printf("Lembrando que para o funcionamento correto do aplicativo � necessario analisar 2 sess�es.\n");
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            printf("\nInsira a quantidade de sess�es: ");
            scanf("%d",&quantidade_de_sessoes); //Releitura da vari�vel no caso dela for diferente do valor 2.
        }
    }
    while(quantidade_de_sessoes < 2 || quantidade_de_sessoes > 2);

    //Printfs para intera��o com o usu�rio.
    printf("\nLegal, agora queremos saber o nome do filme.\n");
    printf("Lembre-se de n�o deixar o campo abaixo vazio.\n");
    printf("\nDigite o nome do filme: ");
    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
    fgets(nome_do_filme, 50, stdin); //Armazenamento do nome do filme.
    //Verifica��o da vari�vel nome_do_filme, caso ela seja igual a palavra "vazio" ou tenha apenas um caractere ser� feita a releitura.
    do
    {
        if(strncmp(nome_do_filme, "vazio", 5) == 0 || strlen(nome_do_filme) == 1)
        {
            printf("\nVoc� inseriu um nome invalido.\n", nome_do_filme);
            printf("Lembre-se de n�o deixar o campo abaixo vazio.\n");
            printf("\nDigite o nome do filme: ");
            fflush(stdin);//fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            fgets(nome_do_filme, 50, stdin); //Releitura da vari�vel.
        }
    }
    while(strncmp(nome_do_filme, "vazio", 5) == 0 || strlen(nome_do_filme) == 1);

    //Printfs para intera��o com o usu�rio.
    printf("\nUm cl�ssico!\n");
    printf("\nAgora precisamos da quantidade de pessoas que assistiram ao filme.\n");
    printf("Lembre-se que cada sess�o tem no m�nimo 10 pessoas.\n");
    printf("\nQuantidade de pessoas na sess�o: ");
    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
    scanf("%d", &quantidade_de_pessoas); //Armazenamento da quantidade de pessoas que compareceram as sess�es.

    //Verifica��o da vari�vel quantidade_de_pessoas, caso ela seja menor que 2 ser� feita a releitura.
    do
    {
        if(quantidade_de_pessoas < 2)
        {
            printf("\nVoc� inseriu \"%d\", esse n�mero � inv�lido.\n", quantidade_de_pessoas);
            printf("Lembre-se que cada sess�o tem no m�nimo 10 pessoas.\n");
            printf("\nQuantidade de pessoas na sess�o: ");
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            scanf("%d", &quantidade_de_pessoas); //Releitura da vari�vel.
        }
    }
    while(quantidade_de_pessoas < 2);

    //Printfs para intera��o com o usu�rio.
    printf("\nEstamos quase l�!\n");
    printf("Agora s� precisamos saber o g�nero e a idade das pessoas presente na sess�o.\n");
    printf("Lembre-se de usar aspenas os caracteres \"M\" ou \"F\" independe de serem mai�sculos ou min�sculos.\n");
    printf("E que que a idade deve ser maior que 3 e menor que 100 anos.\n");

    //Loop for onde a leitura do g�nero, idade e avalia��o do filme ser�o feitas.
    for(i = 0; i < quantidade_de_pessoas; /*O incremento � feito durante o loop*/)
    {
        printf("\nInsira o g�nero da %d� pessoa: ", (i + 1));
        fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
        genero = getchar(); //fun��o getchar para armazenar a vari�vel g�nero
        if(genero == 'm' || genero == 'M')
        {
            quantidade_masculino++; //Toda vez que o g�nero for masculino essa v�riavel soma 1.
            printf("\nPara melhorar a qualidade das estat�sticas por favor avalie o filme de 0 a 5 estrelas: ");
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            scanf("%lf", &avaliacao); //Armazenamento da quantidade de pessoas que compareceram as sess�es.

            //Verifica��o da vari�vel avaliacao. Caso ela seja menor que 0 ou maior que 5 � feita a releitura.
            do
            {
                if(avaliacao < 0 || avaliacao > 5)
                {
                    printf("\nVoc� inseriu \"%.0lf\", esse n�mero � inv�lido.\n", avaliacao);
                    printf("Por favor avalie o filme de 0 a 5 estrelas.\n");
                    printf("\nInsira sua avalia��o: ");
                    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
                    scanf("%lf", &avaliacao); //releitura da vari�vel.
                }
            }
            while(avaliacao < 0 || avaliacao > 5);

            avaliacao_total += avaliacao; //Ap�s checar a vari�vel avaliacao ela � somada a um total.
            avaliacao = 0; //Depois de ser somada ela tem o seu valor apagado para uma futura releitura.

            printf("\nInsira a idade da %d� pessoa: ", (i + 1));
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            scanf("%d", &idade);//Armazenamento da idade das pessoas que compareceram as sess�es.

            //Verifica��o da vari�vel idade. Caso ela seja menor que 3 ou maior que 100 � feita a releitura.
            do
            {
                if(idade < 3 || idade > 100)
                {
                    printf("\nVoc� inseriu \"%d\", esse n�mero � inv�lido.\n", idade);
                    printf("Lembre-se de que a idade deve ser maior que 3 e menor que 100 anos.\n");
                    printf("\nInsira a idade da %d� pessoa: ", (i + 1));
                    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
                    scanf("%d", &idade); //releitura da vari�vel.

                    //Conjunto de ifs que determina qual dos contadores ser� acrescentado de acordo com a idade lida.
                    if(idade >= 3 && idade <= 13)
                    {
                        quantidade_de_criancas++;
                        i++;
                    }
                    else if(idade >= 14 && idade <= 17)
                    {
                        quantidade_de_adolescentes++;
                        i++;
                    }
                    else if(idade >= 18 && idade <= 64)
                    {
                        quantidade_de_adultos++;
                        quantidade_adultos_m++;
                        i++;
                    }
                    else if(idade >= 65 && idade <= 100)
                    {
                        quantidade_de_idosos++;
                        quantidade_adultos_m++;
                        i++;
                    }
                }
                else //Conjunto de ifs que determina qual dos contadores ser� acrescentado de acordo com a idade lida. Mas dessa vez caso a idade sej� certa logo de primeira.
                {
                    if(idade >= 3 && idade <= 13)
                    {
                        quantidade_de_criancas++;
                        i++;
                    }
                    else if(idade >= 14 && idade <= 17)
                    {
                        quantidade_de_adolescentes++;
                        i++;
                    }
                    else if(idade >= 18 && idade <= 64)
                    {
                        quantidade_de_adultos++;
                        quantidade_adultos_m++;
                        i++;
                    }
                    else if(idade >= 65 && idade <= 100)
                    {
                        quantidade_de_idosos++;
                        quantidade_adultos_m++;
                        i++;
                    }
                }
            }
            while(idade < 3 || idade > 100);
        }
        else if(genero == 'f' || genero == 'F')
        {
            quantidade_feminino++;
            printf("\nPara melhorar a qualidade das estat�sticas por favor avalie o filme de 0 a 5 estrelas: ");
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            scanf("%lf", &avaliacao); //Armazenamento da quantidade de pessoas que compareceram as sess�es.

            //Verifica��o da vari�vel avaliacao. Caso ela seja menor que 0 ou maior que 5 � feita a releitura.
            do
            {
                if(avaliacao < 0 || avaliacao > 5)
                {
                    printf("\nVoc� inseriu \"%.0lf\", esse n�mero � inv�lido.\n", avaliacao);
                    printf("Por favor avalie o filme de 0 a 5 estrelas.\n");
                    printf("\nInsira sua avalia��o: ");
                    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
                    scanf("%lf", &avaliacao); //releitura da vari�vel.
                }
            }
            while(avaliacao < 0 || avaliacao > 5);

            avaliacao_total += avaliacao; //Ap�s checar a vari�vel avaliacao ela � somada a um total.
            avaliacao = 0; //Depois de ser somada ela tem o seu valor apagado para uma futura releitura.

            printf("\nInsira a idade da %d� pessoa: ", (i + 1));
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            scanf("%d", &idade);//Armazenamento da idade das pessoas que compareceram as sess�es.

            //Verifica��o da vari�vel idade. Caso ela seja menor que 3 ou maior que 100 � feita a releitura.
            do
            {
                if(idade < 3 || idade > 100)
                {
                    printf("\nVoc� inseriu \"%d\", esse n�mero � inv�lido.\n", idade);
                    printf("Lembre-se de que a idade deve ser maior que 3 e menor que 100 anos.\n");
                    printf("\nInsira a idade da %d� pessoa: ", (i + 1));
                    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
                    scanf("%d", &idade); //releitura da vari�vel.

                    //Conjunto de ifs que determina qual dos contadores ser� acrescentado de acordo com a idade lida.
                    if(idade >= 3 && idade <= 13)
                    {
                        quantidade_de_criancas++;
                        i++;
                    }
                    else if(idade >= 14 && idade <= 17)
                    {
                        quantidade_de_adolescentes++;
                        i++;
                    }
                    else if(idade >= 18 && idade <= 64)
                    {
                        quantidade_de_adultos++;
                        quantidade_adultos_f++;
                        i++;
                    }
                    else if(idade >= 65 && idade <= 100)
                    {
                        quantidade_de_idosos++;
                        quantidade_adultos_f++;
                        i++;
                    }
                }
                else //Conjunto de ifs que determina qual dos contadores ser� acrescentado de acordo com a idade lida. Mas dessa vez caso a idade sej� certa logo de primeira.
                {
                    if(idade >= 3 && idade <= 13)
                    {
                        quantidade_de_criancas++;
                        i++;
                    }
                    else if(idade >= 14 && idade <= 17)
                    {
                        quantidade_de_adolescentes++;
                        i++;
                    }
                    else if(idade >= 18 && idade <= 64)
                    {
                        quantidade_de_adultos++;
                        quantidade_adultos_f++;
                        i++;
                    }
                    else if(idade >= 65 && idade <= 100)
                    {
                        quantidade_de_idosos++;
                        quantidade_adultos_f++;
                        i++;
                    }
                }
            }
            while(idade < 3 || idade > 100);
        }
        else //Caso o g�nero seja inv�lido ser�o printadas as seguintes informa��es:
        {
            printf("\nVoc� inseriu \"%c\", esse caractere � inv�lido.\n", genero);
            printf("Lembre-se de usar aspenas os caracteres \"M\" ou \"F\" independe de serem mai�sculos ou min�sculos.\n");
        }
    }
    printf("\nPara melhorar a qualidade das estat�sticas por favor insira o pre�o individual do ingresso para uma �nica sess�o: ");
    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
    scanf("%lf", &valor_do_ingresso); // armazenamento do valor do inngresso.

    //printfs dos resultados finais.
    system("cls");
    printf("Obrigado por usar nosso aplicativo, aqui est�o os seus resultados: \n");
    printf("\nNome do filme: %s", nome_do_filme);
    printf("\nA quantidade de pessoas do sexo masculino que compareceram as sess�es �:  %d\n", quantidade_masculino);
    printf("A quantidade de pessoas do sexo feminino que compareceram as sess�es �:  %d\n", quantidade_feminino);
    printf("\nSegundo a classifica��o de idade:\n");
    printf("\n%d crian�as compareceram a sess�o.\n",quantidade_de_criancas);
    printf("%d adolescentes compareceram a sess�o.\n",quantidade_de_adolescentes);
    printf("%d adultos compareceram a sess�o.\n",quantidade_de_adultos);
    printf("%d idosos compareceram a sess�o.\n",quantidade_de_idosos);
    printf("\nA quantidade total de adultos do sexo masculino �: %d.\n",quantidade_adultos_m);
    printf("A quantidade total de adultos do sexo feminino �: %d.\n",quantidade_adultos_f);

    //Intera��o com o usu�rio sobre mais estat�sticas das sess�es
    printf("\nDeseja saber mais estatisticas sobre as sess�es?\n");
    printf("Se sim pressione \"S\".\nSe n�o pressione \"N\".\n");
    fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
    escolha = getchar(); //fun��o getchar para armazenar a vari�vel escolha.

    //verifica��o da vari�vel escolha.
    do
    {
        if(escolha == 'S' || escolha == 's')
        {
            printf("\nA m�dia de avalia��o do filme foi: %.1lf estrelas.", (avaliacao_total / quantidade_de_pessoas));
            printf("\nA arrecada��o total foi: %.2lf R$.", ((valor_do_ingresso * (double)quantidade_de_pessoas) * 2.0));
            break;
        }
        else if(escolha == 'N' || escolha == 'n')
        {
            break;
        }
        else
        {
            printf("Voc� pressionou \"%c\".\n", escolha);
            printf("Por favor pressione apenas \"S\" ou \"N\".\n");
            fflush(stdin); //fun��o que limpa o buffer do teclado, usada para evitar erros inesperados.
            escolha = getchar(); // releitura da escolha.
        }
    }
    while(escolha != 'S' || escolha != 's' || escolha != 'N' || escolha != 'n');

    return 0;
}

