# Sistema de Gestão de Clínica Médica
Este projeto consiste na implementação de um sistema de gestão hospitalar em linguagem C, desenvolvido como Trabalho Final da disciplina de Algoritmos e Estruturas de Dados I (UFMT-2025/1), a partir de um fluxograma.

## Funcionalidades do Sistema

O software simula o fluxo de atendimento de uma clínica, abrangendo três áreas principais:

### 1. Gestão de Pacientes
O sistema gerencia um banco de dados em memória (vetores) que armazena:
* Dados Pessoais (Nome, CPF, RG).
* Dados Médicos (Tipo Sanguíneo, Peso, Altura).
* Validação de segurança via CPF para acessar os prontuários.

### 2. Agendamentos
Módulo responsável por marcar consultas e exames, com verificação automática de disponibilidade para evitar conflitos de agenda.
* **Especialidades:** Clínica Médica, Pediatria, Oftalmologia e Oncologia.
* **Exames:** Suporte para exames de imagem e laboratoriais.

### 3. Financeiro
* Geração de nota fiscal simulada no terminal.
* Cálculo de valores baseado nos procedimentos realizados.
* Opções de pagamento simulado via Pix ou Cartão.

## Estrutura do Código
O projeto foi estruturado com foco em modularização, dividindo os requisitos/funcionalidades em funções específicas para facilitar a leitura e manutenção.

## Autoras

* [Carolina Peruare](https://github.com/carol-peruare)
* [Maressa Luiza](https://github.com/Malu006)
