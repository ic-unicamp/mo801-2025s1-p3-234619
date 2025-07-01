# Repositório base para o Projeto 3

Aluno: Gabriel Ayres de Oliveira
RA: 234619

## Breve descrição dos objetivos

- Execução do código em Litex
- Modificação do SoC do litex_sim
- integração de um arquivo verilog com CSR

## Desafios encontrados

- O LiteX é muito mal documentado, o que faz qualquer mudança simples algo homérico.
- Não consegui usar o wishbone e tive que ficar com o CSR para a comunicação do módulo

## Barreiras alcançadas

- Acelerar o processo de convolução em si mais que por software

## Comentários gerais e conclusões

O trabalho está escrito inteiramente no arquivo `trab3.md`. O PDF gerado desse markdown não será adicionado aqui, somente no Google Classroom.

As pastas `litex` e `verilog` podem ser arrastadas diretamente para a instalação do litex, em sua pasta raiz, para recriar a estrutura usada no trabalho.

A pasta arquivos_suporte contém versões base dos arquivos discutidos e o script de python que gera as linhas de verilog para os pesos.
