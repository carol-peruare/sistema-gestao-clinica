# 🏥 Sistema de Atendimento em Clínica Médica

Implementação completa de um sistema de gestão hospitalar em linguagem C. Este projeto foi desenvolvido como **Trabalho Final** da disciplina de Algoritmos e Estruturas de Dados I (UFMT - 2025).

O objetivo foi transformar um fluxograma complexo em um software funcional, utilizando modularização e estruturas de dados em memória.

## 👥 Equipe de Desenvolvimento
* **Carolina Peruare (https://github.com/carol-peruare)**
* **Maressa Luiza (https://github.com/Malu006)**

## ⚙️ Funcionalidades do Sistema

### 1. Gestão de Pacientes (Banco de Dados em Memória)
O sistema utiliza **vetores** para simular um banco de dados persistente durante a execução, armazenando:
* Dados Pessoais (Nome, Nome Social, CPF, RG).
* Dados Médicos (Tipo Sanguíneo, Peso, Altura).
* Validação de segurança via CPF para acesso aos dados.

### 2. Módulo de Agendamentos
Lógica robusta para marcar consultas e exames, com validação de:
* **Especialidades:** Clínica Médica, Pediatria, Oftalmologia e Oncologia.
* **Horários:** Verificação de conflitos de agenda e disponibilidade por médico.
* **Exames:** Suporte para exames de Imagem (Raio-X, Tomografia) e Laboratoriais.

### 3. Módulo Financeiro
* Geração automática de "Nota Fiscal" simulada no terminal.
* Cálculo de valores baseado no tipo de procedimento.
* Opções de pagamento (Pix/Cartão).

## 💻 Estrutura do Código
O projeto foi estruturado com foco em **Modularização**, dividindo os requisitos em funções específicas:
* `agendamento()`: Gerencia o fluxo de marcar consultas.
* `entregaExames()`: Verifica credenciais e exibe resultados.
* `retornoConsulta()`: Lógica para agendar o retorno médico.
* `cadastros_fixos()`: Popula o sistema com dados iniciais para testes.

---
**Desenvolvido por**
  
Carolina Peruare • Maressa Luiza

</div>

![Badge Concluído](http://img.shields.io/static/v1?label=STATUS&message=CONCLUIDO&color=GREEN&style=for-the-badge)
![Badge Linguagem](http://img.shields.io/static/v1?label=LINGUAGEM&message=C&color=blue&style=for-the-badge)
