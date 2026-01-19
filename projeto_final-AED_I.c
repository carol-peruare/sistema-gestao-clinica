#include <stdio.h>
#include <math.h>
#include <string.h>

    //Funções
    int retornoConsulta();
    int agendamento();
    int entregaExames(int indice_paciente);

    //Variaveis Cadastro
    char cpfs[10][15];
    char RG[10][20]; 
    char nomes[10][100];
    char nomes_sociais[10][100];
    char sexos_biologicos[10][20];
    char datas_nascimento[10][12];
    char telefones[10][20];
    char emails[10][100];
    char contatos_emergencia[10][20];
    char tipos_sanguineos[10][5]; 
    float pesos[10];
    float alturas[10];
    int num_pacientes_cadastrados = 0;

    //Variaveis Atendtimento e Retorno 
    int consultaMarcada = 0;
    int solicitacaoMedica = 1;
    int retornoMarcado =0; 


int entregaExames(int indice_paciente) {
    char rg_digitado[20];


    printf("Por seguranca, por favor, confirme seu RG (apenas numeros): ");
    fgets(rg_digitado, sizeof(rg_digitado), stdin);
    rg_digitado[strcspn(rg_digitado, "\n")] = '\0';

    if (strcmp(rg_digitado, RG[indice_paciente]) == 0) {

        printf("\n--- Verificacao bem-sucedida! ---\n");
       
        printf("Seus resultados de exame estao prontos:\n");
        printf("\n----------- RESULTADO DE EXAME -----------\n");
        printf("Paciente....: %s\n", nomes[indice_paciente]);
        printf("Exame.......: Hemograma Completo\n");
        printf("------------------------------------------\n");
        printf("  Leucocitos..: 8.500 /mm³\n");
        printf("  Hemacias....: 4.8 milhoes/mm³\n");
        printf("  Plaquetas...: 250.000 /mm³\n");
        printf("  Hemoglobina.: 14.2 g/dL\n");
        printf("------------------------------------------\n");
        printf("Observacao: Valores dentro da normalidade.\n");


    } else {
       
        printf("\n--- ERRO ---\n");
        printf("O RG informado nao corresponde ao do cadastro.\n");
    }
    return 0; 
}

int retornoConsulta() {

    int medicoEscolhido, diaRetorno, mesRetorno, horaRetorno;
    
    char diaSemanaa[8][50] = {"", "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    char medicosCad[5][50] = {"", "Mateus Ferreira Almeida", "Beatriz Lima Gomes", "Júlia Barbosa Lima", "Miguel Dias Barbosa"};

    if (retornoMarcado == 1) {
        printf("\nERRO: Paciente já possui uma consulta ou retorno agendado no sistema.\n");
        printf("Por favor, confirme a presença (opção 2) ou remarque após a data atual.\n");
        return 0; 
    }

    printf("\nEscolha o médico para o seu retorno:\n");
    printf("1- Dr. Mateus Ferreira Almeida (Clínica Médica) - 08h às 12h - Segunda a Sexta\n");
    printf("2- Dra. Beatriz Lima Gomes (Pediatria) - 12h às 18h - Segunda a Sexta\n");
    printf("3- Dra. Júlia Barbosa Lima (Oftalmologia) - 08h às 18h - Segunda a Sexta\n");
    printf("4- Dr. Miguel Dias Barbosa (Oncologia) - 08h às 18h - Segunda a Quarta\n");
    scanf("%d", &medicoEscolhido);

    printf("Insira o dia da semana do retorno (2-Segunda, 3-Terça, ..., 6-Sexta):\n");
    scanf("%d", &diaRetorno);
    printf("Insira o mês do retorno:\n");
    scanf("%d", &mesRetorno);
    printf("Insira a hora do retorno (formato 24h):\n");
    scanf("%d", &horaRetorno);
    while(getchar() != '\n');

    switch (medicoEscolhido) {
        case 1: 
            if ((horaRetorno >= 8 && horaRetorno <= 12) && (diaRetorno >= 2 && diaRetorno <= 6)) {
                printf("\n--- SUCESSO! ---\n");
                printf("Retorno agendado para %s, no mês %d, às %dh com o(a) Dr(a). %s\n", diaSemanaa[diaRetorno], mesRetorno, horaRetorno, medicosCad[medicoEscolhido]);
                retornoMarcado = 1; 
            } else {
                printf("\nERRO DE AGENDAMENTO: Horário indisponível para este profissional.\n");
            }
            break;
        case 2: 
            if ((horaRetorno >= 12 && horaRetorno <= 18) && (diaRetorno >= 2 && diaRetorno <= 6)) {
                printf("\n--- SUCESSO! ---\n");
                printf("Retorno agendado para %s, no mês %d, às %dh com o(a) Dr(a). %s\n", diaSemanaa[diaRetorno], mesRetorno, horaRetorno, medicosCad[medicoEscolhido]);
                retornoMarcado = 1;
            } else {
                printf("\nERRO DE AGENDAMENTO: Horário indisponível para este profissional.\n");
            }
            break;
        case 3: 
            if ((horaRetorno >= 8 && horaRetorno <= 18) && (diaRetorno >= 2 && diaRetorno <= 6)) {
                printf("\n--- SUCESSO! ---\n");
                printf("Retorno agendado para %s, no mês %d, às %dh com o(a) Dr(a). %s\n", diaSemanaa[diaRetorno], mesRetorno, horaRetorno, medicosCad[medicoEscolhido]);
                retornoMarcado = 1;
            } else {
                printf("\nERRO DE AGENDAMENTO: Horário indisponível para este profissional.\n");
            }
            break;
        case 4: 
            if ((horaRetorno >= 8 && horaRetorno <= 18) && (diaRetorno >= 2 && diaRetorno <= 4)) {
                printf("\n--- SUCESSO! ---\n");
                printf("Retorno agendado para %s, no mês %d, às %dh com o(a) Dr(a). %s\n", diaSemanaa[diaRetorno], mesRetorno, horaRetorno, medicosCad[medicoEscolhido]);
                retornoMarcado = 1;
            } else {
                printf("\nERRO DE AGENDAMENTO: Horário indisponível para este profissional.\n");
            }
            break;
        default:
            printf("\nERRO: Opção de médico inválida.\n");
            break;
    }
    return 0; 
}

int agendamento()
{
    int agendamento_e_c; 
    int exame, exameImg, exameLab, consulta, diaConsulta, horaConsulta, mesConsulta;
    int diaSemana, horaAg, pagamento, entrarPag = 0, pagConsulta;
    float radiografia = 155.50, tomografia = 2000, ressonanciaM = 1550.25, ultrassom = 548.75;
    float hemograma = 65.00, glicemia = 9.50, testeGravidez = 150.45, urinaFezes = 75.50;
    char formaPag[50];
    char diaSemanaa[8][50] = {"", "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    char nome_digitado[50];
    char medicosCad[5][50] = {"", "Mateus Ferreira Almeida", "Beatriz Lima Gomes", "Júlia Barbosa Lima", "Miguel Dias Barbosa"};

    printf("Digite o nome do paciente:\n");
    fgets(nome_digitado, sizeof(nome_digitado), stdin);
    nome_digitado[strcspn(nome_digitado, "\n")] = '\0';

    printf("Qual operação deseja realizar: \n1- Agendamento de exames\n2- Agendamento de consulta \n");
    scanf("%d", &agendamento_e_c);

    switch (agendamento_e_c)
    {
    case 1:
        if (solicitacaoMedica == 0)
        {
            printf("Você não pode realizar exame sem solicitação de um especialista.\n");
        }
        else
        {
            printf("Que tipo de exame deseja:\n1- Imagem \n2- Laboratorial \n");
            scanf("%d", &exame);

            switch (exame)
            {
            case 1:
                printf("Escolha a opção:\n");
                printf("1- Radiografia\n");
                printf("2- Tomografia\n");
                printf("3- Ressonância Magnética\n");
                printf("4- Ultrassonografia\n");
                scanf("%d", &exameImg);

                printf("Insira o dia da semana que deseja agendar o exame:\n");
                printf("Exemplo: Domingo = 1, Segunda = 2, ... Sábado = 7.\n");
                scanf("%d", &diaSemana);

                printf("Insira aqui a hora que deseja agendar (formato 24h):\n");
                scanf("%d", &horaAg);

                if ((horaAg >= 8 && horaAg <= 18) && (diaSemana >= 2 && diaSemana <= 6))
                {
                    printf("Data e hora disponível!\n");
                    printf("Realize o pagamento.\n1- Sim\n2- Não\n");
                    scanf("%d", &pagamento);

                    if (pagamento == 1)
                    {
                        getchar(); // consumir enter
                        printf("Insira a forma de pagamento:\n");
                        fgets(formaPag, sizeof(formaPag), stdin);

                        switch (exameImg)
                        {
                        case 1:
                            printf("Valor da radiografia = %.2f\n", radiografia);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Radiografia\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Valor: %.2f\n", radiografia);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Troco = R$0,00\n");
                            break;
                        case 2:
                            printf("Valor da tomografia = %.2f\n", tomografia);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Tomografia\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Valor: %.2f\n", tomografia);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Troco = R$0,00\n");
                            break;
                        case 3:
                            printf("Valor da Ressonância Magnética = %.2f\n", ressonanciaM);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Ressonância Magnética\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Valor: %.2f\n", ressonanciaM);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Troco = R$0,00\n");
                            break;
                        case 4:
                            printf("Valor da Ultrassonografia = %.2f\n", ultrassom);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Ultrassonografia\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Valor: %.2f\n", ultrassom);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Troco = R$0,00\n");
                            break;
                        default:
                            printf("Operação inválida!\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("----- Operação cancelada por falta de pagamento -----\n");
                    }
                }
                else
                {
                    printf("Data ou hora indisponível!\n");
                }
                break;

            case 2:
                printf("Escolha a opção:\n");
                printf("1- Hemograma\n");
                printf("2- Glicemia\n");
                printf("3- Beta HCG\n");
                printf("4- Análise de urina e fezes\n");
                scanf("%d", &exameLab);

                printf("Insira o dia da semana que deseja agendar o exame:\n");
                scanf("%d", &diaSemana);

                printf("Insira aqui a hora que deseja agendar (formato 24h):\n");
                scanf("%d", &horaAg);

                if ((horaAg >= 8 && horaAg <= 18) && (diaSemana >= 2 && diaSemana <= 6))
                {
                    printf("Data e hora disponível!\n");
                    printf("Realize o pagamento.\n1- Sim\n2- Não\n");
                    scanf("%d", &pagamento);

                    if (pagamento == 1)
                    {
                        getchar(); 
                        printf("Insira a forma de pagamento (Cartão ou Pix):\n");
                        fgets(formaPag, sizeof(formaPag), stdin);

                        switch (exameLab)
                        {
                        case 1:
                            printf("Valor do Hemograma = %.2f\n", hemograma);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Hemograma\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Valor: %.2f\n", hemograma);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Troco = R$0,00\n");
                            break;
                        case 2:
                            printf("Valor da Glicemia = %.2f\n", glicemia);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Glicemia\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Valor: %.2f\n", glicemia);
                            printf("Troco = R$0,00\n");
                            break;
                        case 3:
                            printf("Valor da Beta HCG = %.2f\n", testeGravidez);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Beta HCG\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Valor: %.2f\n", testeGravidez);
                            printf("Troco = R$0,00\n");
                            break;
                        case 4:
                            printf("Valor da Análise de Urina e Fezes = %.2f\n", urinaFezes);
                            printf("----------- Nota Fiscal -----------\n");
                            printf("Paciente: %s\n", nome_digitado);
                            printf("Exame: Urina e Fezes\n");
                            printf("Dia = %s, Hora = %dh\n", diaSemanaa[diaSemana], horaAg);
                            printf("Forma de pagamento: %s", formaPag);
                            printf("Valor: %.2f\n", urinaFezes);
                            printf("Troco = R$0,00\n");
                            break;
                        default:
                            printf("Operação inválida!\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("Operação cancelada!\n");
                    }
                }
                else
                {
                    printf("Data ou hora indisponível!\n");
                }
                break;

            default:
                printf("Operação inválida!\n");
                break;
            }
        }
        break;

    case 2:
        printf("Escolha qual médico você deseja consultar e o dia e hora:\n");
        printf("Profissionais disponíveis:\n");
        printf("1- Dr. Mateus Ferreira Almeida (Clínica Médica) - 08h às 12h - Segunda á Sexta\n");
        printf("2- Dra. Beatriz Lima Gomes (Pediatria) - 12h às 18h - Segunda á Sexta\n");
        printf("3- Dra. Júlia Barbosa Lima (Oftalmologia) - 08h às 18h - Segunda á Sexta\n");
        printf("4- Dr. Miguel Dias Barbosa (Oncologia) - 08h às 18h - Segunda á Quarta\n");

        scanf("%d", &consulta);

        printf("Insira o dia da semana da consulta (2-Segunda, 3- Terça, ..., 6- Sexta):\n");
        scanf("%d", &diaConsulta);
        printf("Insira o mês da consulta:\n");
        scanf("%d", &mesConsulta);
        printf("Insira a hora da consulta (24h):\n");
        scanf("%d", &horaConsulta);

        if (consultaMarcada == 0)
        {
            switch (consulta)
            {
            case 1:
                if ((horaConsulta >= 8 && horaConsulta <= 12) && (diaConsulta >= 2 && diaConsulta <= 6))
                {
                    printf("Consulta marcada com o Dr. Mateus Ferreira Almeida, %s, mês %d, às %dh\n", diaSemanaa[diaConsulta], mesConsulta, horaConsulta);
                    consultaMarcada = 1;
                    entrarPag = 15;
                }
                else
                    printf("Esse horário não está disponível!\n");
                break;
            case 2:
                if ((horaConsulta >= 12 && horaConsulta <= 18) && (diaConsulta >= 2 && diaConsulta <= 6))
                {
                    printf("Consulta marcada com a Dra. Beatriz Lima Gomes, %s, mês %d, às %dh\n", diaSemanaa[diaConsulta], mesConsulta, horaConsulta);
                    consultaMarcada = 1;
                    entrarPag = 15;
                }
                else
                    printf("Esse horário não está disponível!\n");
                break;
            case 3:
                if ((horaConsulta >= 8 && horaConsulta <= 18) && (diaConsulta >= 2 && diaConsulta <= 6))
                {
                    printf("Consulta marcada com a Dra. Júlia Barbosa Lima, %s, mês %d, às %dh\n", diaSemanaa[diaConsulta], mesConsulta, horaConsulta);
                    consultaMarcada = 1;
                    entrarPag = 15;
                }
                else
                    printf("Esse horário não está disponível!\n");
                break;
            case 4:
                if ((horaConsulta >= 8 && horaConsulta <= 18) && (diaConsulta >= 2 && diaConsulta <= 4))
                {
                    printf("Consulta marcada com o Dr. Miguel Dias Barbosa, %s, mês %d, às %dh\n", diaSemanaa[diaConsulta], mesConsulta, horaConsulta);
                    consultaMarcada = 1;
                    entrarPag = 15;
                }
                else
                    printf("Esse horário não está disponível!\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
            }
        }

        if (entrarPag == 15)
        {
            printf("Realize o pagamento.\n1- Sim\n2- Não\n");
            scanf("%d", &pagConsulta);

            if (pagConsulta == 1)
            {
                getchar();
                printf("Insira a forma de pagamento (Cartão ou Pix):\n");
                fgets(formaPag, sizeof(formaPag), stdin);

                switch (consulta)
                {
                case 1:
                    printf("----------- Nota Fiscal -----------\n");
                    printf("Paciente: %s\n", nome_digitado);
                    printf("Consulta com o médico %s\n", medicosCad[consulta]);
                    printf("Valor da consulta R$1500\n");
                    printf("Forma de pagamento: %s", formaPag);
                    printf("Troco = R$0,00\n");
                    break;
                case 2:
                    printf("----------- Nota Fiscal -----------\n");
                    printf("Paciente: %s\n", nome_digitado);
                    printf("Consulta com a médica %s\n", medicosCad[consulta]);
                    printf("Valor da consulta R$1850\n");
                    printf("Forma de pagamento: %s", formaPag);
                    printf("Troco = R$0,00\n");
                    break;
                case 3:
                    printf("----------- Nota Fiscal -----------\n");
                    printf("Paciente: %s\n", nome_digitado);
                    printf("Consulta com a médica %s\n", medicosCad[consulta]);
                    printf("Valor da consulta R$1900\n");
                    printf("Forma de pagamento: %s", formaPag);
                    printf("Troco = R$0,00\n");
                    break;
                case 4:
                    printf("----------- Nota Fiscal -----------\n");
                    printf("Paciente: %s\n", nome_digitado);
                    printf("Consulta com o médico %s\n", medicosCad[consulta]);
                    printf("Valor da consulta R$3650\n");
                    printf("Forma de pagamento: %s", formaPag);
                    printf("Troco = R$0,00\n");
                    break;
                }
                consulta = 1;
                solicitacaoMedica = 1;
            }
            else
            {
                printf("Você não pode se consultar!\n");
                entrarPag = 0;
            }
        }
        break;

    default:
        printf("Operação inválida!\n");
        break;
    }

    return 0;
}

void confirmarPresenca() {
    if (consultaMarcada == 1) {
        printf("Presença confirmada para a consulta!\n");
        consultaMarcada = 0;
    }
    else if (solicitacaoMedica == 1) {
        printf("Presença confirmada para o exame!\n");
        solicitacaoMedica = 0;
    }
    else {
        printf("Não existe consulta ou exame agendado!\n");
    }
}

void cadastros_fixos() {

    strcpy(cpfs[0], "11111111111");
    strcpy(RG[0], "1234567-8");
    strcpy(nomes[0], "Maressa Luiza");
    strcpy(nomes_sociais[0], "Maressa");
    strcpy(sexos_biologicos[0], "Feminino");
    strcpy(datas_nascimento[0], "31/04/1899");
    strcpy(telefones[0], "65911111111");
    strcpy(emails[0], "lulu@gmail.com");
    strcpy(contatos_emergencia[0], "65988887777");
    strcpy(tipos_sanguineos[0], "O+");
    pesos[0] = 60.5;
    alturas[0] = 1.70;


    strcpy(cpfs[1], "22222222222");
    strcpy(RG[1], "8765432-1");
    strcpy(nomes[1], "Ana Souza");
    strcpy(nomes_sociais[1], "Ana");
    strcpy(sexos_biologicos[1], "Feminino");
    strcpy(datas_nascimento[1], "20/10/1995");
    strcpy(telefones[1], "65922222222");
    strcpy(emails[1], "ana@email.com");
    strcpy(contatos_emergencia[1], "65999990000");
    strcpy(tipos_sanguineos[1], "A-");
    pesos[1] = 75.0;
    alturas[1] = 1.65;
    
   
    num_pacientes_cadastrados = 2;
}


int buscarPacientePorCPF(const char* cpf) {
    for (int i = 0; i < num_pacientes_cadastrados; i++) {
        if (strcmp(cpfs[i], cpf) == 0) {
            return i;
        }
    }
    return -1;
}

//******************************************************************Função Principal******************************************************************
int main() { 
    cadastros_fixos();
    int operacao; 
    
    do {
        char cpf_digitado[15];
        printf("----- VERIFICACAO -----\n");
       printf("Digite seu CPF: ");
        fgets(cpf_digitado, sizeof(cpf_digitado), stdin);
        cpf_digitado[strcspn(cpf_digitado, "\n")] = '\0';
        printf("DEBUG: CPF digitado = '%s'\n", cpf_digitado); // Adicione esta linha
        
        int indice_encontrado = buscarPacientePorCPF(cpf_digitado);
        
        if (indice_encontrado != -1) {
            char nome_digitado[100];
            printf("\n----- LOGIN -----\n");
            printf("CPF reconhecido. Confirme seu nome legal: ");
            fgets(nome_digitado, sizeof(nome_digitado), stdin);
            nome_digitado[strcspn(nome_digitado, "\n")] = '\0';

            if (strcmp(nome_digitado, nomes[indice_encontrado]) == 0) {
               
                printf("\nLogin realizado com sucesso! Bem-vindo(a), %s!\n", nomes_sociais[indice_encontrado]);
                printf("---------------------------------------------\n");
                
                do {
                    printf("\n----- MENU DE OPÇÕES -----\n");
                    printf("1. Agendamento\n");
                    printf("2. Confirmacao de Presenca\n");
                    printf("3. Quadro de horario dos profissionais\n");
                    printf("4. Retorno de consulta\n");
                    printf("5. Entrega de resultados de exames\n");
                    printf("6. Meus Dados Cadastrais\n");
                    printf("7. Quadro de horario do laboratorio\n");
                    printf("8. Historico de paciente\n");
                    printf("9. Historico de notas fiscais\n");
                    printf("0. Sair do Programa\n");
                    printf("\nSelecione a opcao desejada: ");
                    scanf("%d", &operacao);
                    while(getchar() != '\n');

                   

                    switch(operacao) {
                        case 0:
                            printf("\nEncerrando o programa... Ate logo!\n");
                            return 0;
                            break; 

                        case 1:
                            printf("\n>> Opcao 'Agendamento' selecionada.\n"); 
                             agendamento(); // chama a função
                            break;

                        case 2: 
                            printf("\n>> Opcao 'Confirmacao de Presenca' selecionada.\n");
                            confirmarPresenca();
                            break;

                        case 3: 
                            printf("\n>> Opcao 'Quadro de horario dos profissionais' selecionada.\n"); 
                            printf("Escolha qual médico você deseja consultar e o dia e hora:\n");
                            printf("Profissionais disponíveis:\n");
                            printf("1- Dr. Mateus Ferreira Almeida (Clínica Médica) - 08h às 12h - Segunda á Sexta\n");
                            printf("2- Dra. Beatriz Lima Gomes (Pediatria) - 12h às 18h - Segunda á Sexta\n");
                            printf("3- Dra. Júlia Barbosa Lima (Oftalmologia) - 08h às 18h - Segunda á Sexta\n");
                            printf("4- Dr. Miguel Dias Barbosa (Oncologia) - 08h às 18h - Segunda á Quarta\n");
                            break;

                        case 4:
                            printf("\n>> Opcao 'Retorno de consulta' selecionada.\n"); 
                                retornoConsulta(); //chama a funçao
                            break;

                        case 5: 
                           printf("\n>> Opcao 'Entrega de resultados de exames' selecionada.\n"); 
                            
                            entregaExames(indice_encontrado);
                            break;

                        case 6: 
                            printf("\n>> DADOS CADASTRAIS DO PACIENTE:\n");
                            printf("\n  --- Dados Pessoais ---\n");
                            printf("  Nome Legal: %s\n", nomes[indice_encontrado]);
                            printf("  Nome Social: %s\n", nomes_sociais[indice_encontrado]);
                            printf("  RG: %s\n", RG[indice_encontrado]);
                            printf("  CPF: %s\n", cpfs[indice_encontrado]);
                            printf("  Sexo Biologico: %s\n", sexos_biologicos[indice_encontrado]);
                            printf("  Data de Nascimento: %s\n", datas_nascimento[indice_encontrado]);
                            
                            printf("\n  --- Contatos ---\n");
                            printf("  Email: %s\n", emails[indice_encontrado]);
                            printf("  Numero de Telefone: %s\n", telefones[indice_encontrado]);
                            printf("  Contato de Emergencia: %s\n", contatos_emergencia[indice_encontrado]);

                            printf("\n  --- Saude ---\n");
                            printf("  Tipo Sanguineo: %s\n", tipos_sanguineos[indice_encontrado]);
                            printf("  Peso: %.1f kg\n", pesos[indice_encontrado]);
                            printf("  Altura: %.2f m\n", alturas[indice_encontrado]);
                            break;

                        case 7: 
                            printf("\n>> Opcao 'Quadro de horario do laboratorio' selecionada.\n"); 
                            //codigo
                            break;

                        case 8: 
                            printf("\n>> Opcao 'Historico de paciente' selecionada.\n"); 
                            //codigo
                            break;
                            
                        case 9: 
                            printf("\n>> Opcao 'Historico de notas fiscais' selecionada.\n"); 
                            //codigo
                            break;

                        default: 
                            printf("\nOpcao invalida!Tente novamente...\n"); 
                            break;
                    }
                } while(operacao != 0);

            } else {
                printf("\nNome incorreto. Acesso negado.\n\n");
            }

        } else {
        
            printf("\n----- CADASTRO -----\n");
            if (num_pacientes_cadastrados >= 10) {
                printf("Sistema cheio. Nao e possivel cadastrar novos usuarios.\n\n");
                continue;
            }

            printf("Você ainda não possui cadastro. Por favor, complete suas informacoes.\n");

            int novo_indice = num_pacientes_cadastrados;
            strcpy(cpfs[novo_indice], cpf_digitado);

            printf("Nome Legal: ");
            fgets(nomes[novo_indice], sizeof(nomes[novo_indice]), stdin);
            nomes[novo_indice][strcspn(nomes[novo_indice], "\n")] = '\0';
            
            printf("Nome Social: ");
            fgets(nomes_sociais[novo_indice], sizeof(nomes_sociais[novo_indice]), stdin);
            nomes_sociais[novo_indice][strcspn(nomes_sociais[novo_indice], "\n")] = '\0';

            printf("RG: ");
            fgets(RG[novo_indice], sizeof(RG[novo_indice]), stdin);
            RG[novo_indice][strcspn(RG[novo_indice], "\n")] = '\0';

            printf("Sexo Biologico: ");
            fgets(sexos_biologicos[novo_indice], sizeof(sexos_biologicos[novo_indice]), stdin);
            sexos_biologicos[novo_indice][strcspn(sexos_biologicos[novo_indice], "\n")] = '\0';

            printf("Data de Nascimento (DD/MM/AAAA): ");
            fgets(datas_nascimento[novo_indice], sizeof(datas_nascimento[novo_indice]), stdin);
            datas_nascimento[novo_indice][strcspn(datas_nascimento[novo_indice], "\n")] = '\0';

            printf("Email: ");
            fgets(emails[novo_indice], sizeof(emails[novo_indice]), stdin);
            emails[novo_indice][strcspn(emails[novo_indice], "\n")] = '\0';

            printf("Numero de Telefone: ");
            fgets(telefones[novo_indice], sizeof(telefones[novo_indice]), stdin);
            telefones[novo_indice][strcspn(telefones[novo_indice], "\n")] = '\0';

            printf("Contato de Emergencia (telefone): ");
            fgets(contatos_emergencia[novo_indice], sizeof(contatos_emergencia[novo_indice]), stdin);
            contatos_emergencia[novo_indice][strcspn(contatos_emergencia[novo_indice], "\n")] = '\0';

            printf("Tipo Sanguineo (ex: O+): ");
            fgets(tipos_sanguineos[novo_indice], sizeof(tipos_sanguineos[novo_indice]), stdin);
            tipos_sanguineos[novo_indice][strcspn(tipos_sanguineos[novo_indice], "\n")] = '\0';

            printf("Peso (em kg, ex: 70.5): ");
            scanf("%f", &pesos[novo_indice]);
            while(getchar() != '\n');

            printf("Altura (em m, ex: 1.75): ");
            scanf("%f", &alturas[novo_indice]);
            while(getchar() != '\n');
            
            num_pacientes_cadastrados++;
            printf("\nCadastro realizado com sucesso! Voce sera redirecionado.\n\n");
        }
    } while(1); 
    
    return 0;  
}