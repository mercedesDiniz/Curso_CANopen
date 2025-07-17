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

- Referencias:
    - [CAN: From physical layer to application layer and beyond](https://www.can-cia.org/can-knowledge)
    - [CAN Bus Explained - A Simple Intro [2025]](https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial)
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

O protocolo CAN (*Controller Area Network*) é um sistema de comunicação serial usado em veículos/máquinas para permitir que as ECUs (*Electronic Control Units*), também conhecidas como "nós CAN", se comuniquem entre si — sem a necessidade de um computador host. 

Em termos físicos, todas as ECUs são conectadas a um barramento de dois fios composto por um par trançado: CAN high e CAN low.

![alt text](docs/imgs/ecu_can.png)

**Cronologia**:
- Pré-CAN: ECUs de automóveis dependiam de fiação ponto a ponto complexa
- 1986: A Bosch desenvolveu o protocolo CAN como uma solução
- 1991: Bosch publicou o CAN 2.0 (CAN 2.0A: 11 bits, 2.0B: 29 bits)
- 1993: CAN é adotado como padrão internacional (ISO 11898)
- 2003: ISO 11898 se torna uma série padrão
- 2012: A Bosch lançou o CAN FD 1.0 (taxa de dados flexível)
- 2015: O protocolo CAN FD é padronizado (ISO 11898-1)
- 2016: A camada física CAN para taxas de dados de até 5 Mbit/s padronizada na ISO 11898-2 (na prática até 8 Mbit/s)
- 2018: CiA inicia desenvolvimento do CAN XL
- 2024: CAN XL padronizado (ISO 11898-1:2024, 11898-2:2024)

    ![alt text](docs/imgs/cronologia_can.png)

**Arquitetura**

Pode-se visualizar o CAN a partir de um modelo OSI de 7 camadas, conforme ilustrado:

![alt text](docs/imgs/layers_can.png)

A camada física (ISO 11898-2) do barramento CAN define tipos de cabos, níveis de sinais elétricos, requisitos de nós, impedância de cabos etc. Por exemplo, a camada física especifica abaixo:

- Taxa de transmissão: os nós devem ser conectados por meio de um barramento de dois fios com taxas de transmissão de até 1 Mbit/s (CAN clássico) ou 8 Mbit/s (CAN FD).
- Comprimento do cabo: o comprimento máximo do cabo CAN deve estar entre 500 metros (125 kbit/s) e 40 metros (1 Mbit/s).
- Terminação: O barramento CAN deve ser terminado usando um resistor de terminação de 120 Ohm em cada extremidade do barramento.

A camada de enlace de dados (ISO 11898-1) do barramento CAN define, por exemplo, formatos de quadros CAN, tratamento de erros, transmissão de dados e ajuda a garantir a integridade dos dados. Por exemplo, a camada de enlace de dados especifica:

- Formatos de quadro: Quatro tipos (quadros de dados, quadros remotos, quadros de erro, quadros de sobrecarga) e identificadores de 11 bits/29 bits
- Tratamento de erros: métodos para detecção/tratamento de erros CAN, incluindo CRC, slots de reconhecimento, contadores de erros e muito mais.
- Arbitragem: A arbitragem bit a bit não destrutiva ajuda a gerenciar o acesso ao barramento CAN e evitar colisões por meio de prioridade baseada em ID.

**Variantes**:
- **Low-speed CAN**: o CAN tolerante a falhas é uma opção de baixo custo quando a tolerância a falhas é crítica - mas está sendo cada vez mais substituído pelo barramento LIN.
- **High-speed CAN**: o CAN clássico é a variante mais comum hoje em dia em automóveis/máquinas.
- **CAN FD**: Oferece cargas úteis mais longas e velocidade mais rápida.
- **CAN XL**: Oferece cargas úteis ainda maiores e velocidade mais rápida para preencher a lacuna entre CAN e Ethernet automotiva (100BASE-T1).

    ![alt text](docs/imgs/caracteristicas_das_variante_can.png)

**Versões**:
- **CAN 1.0**: possuem identificadores de 11 bits.
- **CAN 2.0** 
    - **CAN 2.0A**: possuem identificadores de 11 bits.
    - **CAN 2.0B**: possuem identificadores de 29 bits (também sendo compativeis com os de 11 bits).

**Características**:
- Possui base no conceito de *broadcast*;
- Possui capacidade *multicast*;
- Possui capacidade multimestre;
- Apresenta flexibilidade de configuração;
- Todos os nós do barramento são sincronizados;
- Um esquema de arbitragem não destrutivo (*bitwise arbotration*) decentralizado, baseado na adoção dos níveis dominante e recessivo, é usado para controlar o acesso ao barramento;
- As mensagens de dados são pequenas e são conferidas po checksum;
- Atribui prioridades às mensagens;
- Não há endereço explícito nas mensagens, cada una delas carrega um identificador que controla sua prioridade no barramento e que pode servir como uma identificação de conteúdo;
- Possui a capacidade de detectar e sinalizar erros;
- Utiliza um esquema de tratamento de erro que resulta na retransmissão das mensagens que não são apropriadamente recebidas;
- Realiza retransmissão automática de mensagens "em espera" logo que o barramento esteja livre;
- Faz distinção entre erros temporários e erros permanentes dos nós;
- Fornece meios para isolar falhas e remover nós com problemas do barramento;
- Oferece meios para filtragem das mensagens;
- O meio físico de transmissão pode ser escolhido, sendo o mais comum o par trançado, mas também podem ser utilizados a fibra óptica e a radiofrequência; 
- Usa o protocolo standard ISO.

**Relação da Taxa de Transmissão com Distãncia**:
|Taxa (Kbits/s)|Distância máx (m)|
|:---|:---:|
|1000|40|
|500|130|
|250|270|
|125|530|
|100|620|
|50|1300|
|20|3300|
|10|6700|
|5|10000|

### 2. [Fundamentos da rede CANopen](#2-fundamentos-da-rede-canopen)

### 3. [Arquitetura, Componentes e Projeto de Rede](#3-arquitetura-componentes-e-projeto-de-rede)

### 4. [CANopen na Prática](#4-canopen-na-pratica)