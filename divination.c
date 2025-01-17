#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//tudo que começa com # é uma diretiva

// imprime cabeçalho do nosso jogo
int main(){
    printf("***************************\n");
    printf("*Welcome to the divination*\n");
    printf("***************************\n");


    int seconds = time(0);
    srand(seconds);


    int randNum = rand();

    int secretNumber = randNum % 100;

    //Se eu quiser imprimir o numero no meio de uma string
    //printf("o numero secreto e o %d. Nao conta para nimguem", secretNumber);

    //antigo numero de tentartivas
    //int attempt = 5;

    int resp;
    int win = 0;
    int attempts = 1;
    double score = 1000;

    int set = 0;

    int nivel;
    int numberAttempt;

    printf("Decida o nivel da dificuldade:\n");
    printf("(1) Easy (2)Medium (3)Hard\n\n");
    printf("Escolha:\n");
    scanf("%d", &nivel);
    switch(nivel){
        case 1:
            numberAttempt = 20;
            break;
        case 2:
            numberAttempt = 15;
            break;
        default:
            numberAttempt = 6;
            break;
    }
    




    for(int i = 1; i<= numberAttempt;i++){
        printf("Tentativa %d \n", attempts);
        printf("************ \n\n");

        printf("Qual é o seu chute?\n\n");
        scanf("%d", &resp);

        if (resp < 0){
            printf("Nao pode chutar numeros negativos.\n");
            //i-- garante que nao use as tentaivas caso o valor seja negativo
            continue;
        }

        set = (resp == secretNumber);
        int maior = (resp > secretNumber);

        //if(resp == secretNumber){
        if(set){
            break;
        }
       
       
        else if(maior){
                printf("Seu chute foi maior que o numero secreto!\n\n");
        }
        else {
                printf("Seu valor foi menor que o numero secreto\n\n");
        }
        attempts++;

        //ele le da diretita para a esquerda entao quando eu coloco 2.0 no final ele entende que e double

        double lostScore = abs(resp - secretNumber) / (double)2;

        score = score - lostScore;
        
    }
    printf("Fim de jogo! \n\n");

    if(set){
    printf("Voce ganhou! \n\n");
    printf("Voce precisou de %d tentativas para ganhar! \n\n", attempts);
    printf("Total da pontução: %.2f!!! \n\n", score);

    } else{
        printf("Voce perdeu!! o numero era: %d \n", secretNumber);
        printf("Tente  novamente!!\n");

    }
    
    
}