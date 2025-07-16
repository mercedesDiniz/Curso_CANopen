# Curso CANopen

Minhas anotações e atividades do treinamento do professor Rodrigo Moreira Borges sobre [rede CANopen](https://www.udemy.com/course/rede-canopen/). Este repositório contém exercícios, códigos de exemplo, documentação e recursos sobre o curso. Utilize os links abaixo para acessar rapidamente os conteúdos.

---
## 📂 Estrutura do Repositório 

```bash
├── projects
│   └── ...
├── docs
│   ├── /imgs 
│   └── ...
├── tools
│   └── ...
├── README.md
```
## Documentação e Ferramentas

- [Site oficial do CANopen CC](https://www.can-cia.org/can-knowledge/canopen)
    - [CiA 301 versão 4.2.0](docs/cia301-v4.2.0.pdf)

- Referencias Extras:
    - [CAN: From physical layer to application layer and beyond](https://www.can-cia.org/can-knowledge)
    - [CANopen Explained - A Simple Intro [2025]](https://www.csselectronics.com/pages/canopen-tutorial-simple-intro)
    - [WEG - Manual da Comunicação CANopen](https://static.weg.net/medias/downloadcenter/h2f/h1a/WEG-cfw11-manual-da-comunicacao-canopen-plc11-10002134020-manual-portugues-br.pdf)

---

## Módulos
### 0. [Introdução](#0-introducao)

O CANopen é um protocolo de comunicação baseado em CAN (*Controller Area Network*), do qual a organização [*CAN in Automation* (CiA)](https://www.can-cia.org) cuida desde 1995 e é definido como um padrão pela norma europeia EN 50325-4.

Pode-se visualizar o CANopen a partir de um modelo OSI de 7 camadas, conforme ilustrado:

![alt text](docs/imgs/layers.png)

O barramento CAN representa as duas camadas mais baixas (física e de enlace de dados). Observe que o protocolo CANopen é frequentemente apresentado de forma ambígua quando se trata das 7 camadas OSI. O padrão oficial CiA 301 simplesmente ilustra o CANopen como abrangendo as 5 camadas acima das camadas física e de enlace de dados – mas sem distinção explícita entre as 5 camadas. Em algumas interpretações, o CANopen é indicado como sendo puramente um protocolo da "camada de aplicação", ou seja, abrangendo apenas a camada 7 do modelo OSI.

O CANopen adiciona uma série de novos conceitos importantes:

![alt text](docs/imgs/intro_principais_conceitos_canopen.png)

**Cronologia**:
- 1993: Pré-desenvolvimentos do CANOpen no âmbito de um projeto Esprit sob a presidência da Bosch.
- 1994: Publicação do perfil de comunicação baseado em CAL (*CAN Application Layer*) predecessor CANOpen versão 1.0.
- 1995: Publicação da CiA 301, camada de aplicação CANopen e perfil de comunicação 2.0.
- 1996: Publicação da Cia 301, camada de aplicação CANopen e perfil de comunicação 3.0.
- 1999: Publicação da Cia 301, camada de aplicação CANopen e perfil de comunicação 4. (EN 50325-4).
- 2007: Publicação da Cia 301, camada de aplicação CANopen e perfil de comunicação 4.2 (somente para membros da CiA).
- 2011: Publicação da Cia 301, camada de aplicação CANopen e perfil de comunicação 4.2 (público). 

![alt text](docs/imgs/cronologia.png)

**CiA - *CAN in Automation***:

É uma organização internacional de usuários e fabricantes que desenvolve e oferece suporte a protocolos de camada superior baseados em CAN.

- A especificações CAN são desenvolvidas dentro dos grupos de interesse da CiA (IG) em cooperação: IG CANopen, IG CANopen FD, IG profiles, IG layer 1/2, IG safety/securit, IG J1939.

- Os grupos de interesse gerenciam seus grupos de interesse especiais (SIG) relacionados. Esses SIGs desenvolvem, por exemplo, especificações e recomendações CiA dedicadas.

- Os representantes da CiA apoiam muitas atividades internacionais de padronização (ISO, IEC, CEN, Cenelec e SAE), lidando com o CAN.

- A Cia publica a revista técnica [CAN Newsletter](https://www.can-cia.org/services/publications/can-newsletter-magazine).


### 1. [Fundamentos do Protocolo CAN](#1-fundamentos-do-protocolo-can)

### 2. [Fundamentos da rede CANopen](#2-fundamentos-da-rede-canopen)

### 3. [Arquitetura, Componentes e Projeto de Rede](#3-arquitetura-componentes-e-projeto-de-rede)

### 4. [CANopen na Prática](#4-canopen-na-pratica)