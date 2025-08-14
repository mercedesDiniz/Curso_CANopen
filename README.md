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
    - [CiA 303-1 (versão 2.0): Device and network design - Part 1: CANopen physical layer](docs/cia303.1-v2.0.1_device_and_network_design-part1_canopen_physical_layer.pdf)
    - [CiA 106 (versão 1.1): Connector pin-assignment recommendations](docs/cia106-v1.1_connector_pin_assignmente_recommendations.pdf)
- Referencias:
    - [CAN: From physical layer to application layer and beyond](https://www.can-cia.org/can-knowledge)
    - [CAN Bus Explained - A Simple Intro [2025]](https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial)
    - [Application Report - Texas Instruments - Introduction to the Controller Area Network (CAN) [2016]](https://www.ti.com/lit/an/sloa101b/sloa101b.pdf?ts=1750050977741&ref_url=https%253A%252F%252Fwww.google.com%252F)
    - [CANopen Explained - A Simple Intro [2025]](https://www.csselectronics.com/pages/canopen-tutorial-simple-intro)
    - [CANopen EDS File Explained - A Simple Intro [2025]](https://www.csselectronics.com/pages/canopen-eds-file-electronic-data-sheet)
    - [WEG - Manual da Comunicação CANopen](https://static.weg.net/medias/downloadcenter/h2f/h1a/WEG-cfw11-manual-da-comunicacao-canopen-plc11-10002134020-manual-portugues-br.pdf)
    - [SIEMENS - CANopen Tutorial - Version 2](https://cache.industry.siemens.com/dl/files/771/109479771/att_993267/v1/109479771_CANopen_Tutorial_V20_en.pdf)

---

## Módulos
### 0. [Introdução](#0-introducao)

O CANopen é um protocolo de comunicação baseado em CAN (*Controller Area Network*), do qual a organização [*CAN in Automation* (CiA)](https://www.can-cia.org) cuida desde 1995 e é definido como um padrão pela norma europeia EN 50325-4.

Pode-se visualizar o CANopen a partir de um modelo OSI de 7 camadas, conforme ilustrado:

![alt text](docs/imgs/layers.png)

O barramento CAN representa as duas camadas mais baixas (física e de enlace de dados). Observe que o protocolo CANopen é frequentemente apresentado de forma ambígua quando se trata das 7 camadas OSI. O padrão oficial CiA 301 simplesmente ilustra o CANopen como abrangendo as 5 camadas acima das camadas física e de enlace de dados – mas sem distinção explícita entre as 5 camadas. Em algumas interpretações, o CANopen é indicado como sendo puramente um protocolo da "camada de aplicação", ou seja, abrangendo apenas a camada 7 do modelo OSI.

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

A camada física ([ISO 11898-2](https://www.iso.org/obp/ui/en/#iso:std:iso:11898:-2:ed-3:v1:en)) do barramento CAN define tipos de cabos, níveis de sinais elétricos, requisitos de nós, impedância de cabos etc. Por exemplo, a camada física especifica abaixo:

- Taxa de transmissão: os nós devem ser conectados por meio de um barramento de dois fios com taxas de transmissão de até 1 Mbit/s (CAN clássico) ou 8 Mbit/s (CAN FD).
- Comprimento do cabo: o comprimento máximo do cabo CAN deve estar entre 500 metros (125 kbit/s) e 40 metros (1 Mbit/s).
- Terminação: O barramento CAN deve ser terminado usando um resistor de terminação de 120 Ohm em cada extremidade do barramento.

A camada de enlace de dados ([ISO 11898-1](https://www.iso.org/obp/ui/en/#iso:std:iso:11898:-1:ed-3:v1:en)) do barramento CAN define, por exemplo, formatos de quadros CAN, tratamento de erros, transmissão de dados e ajuda a garantir a integridade dos dados. Por exemplo, a camada de enlace de dados especifica:

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

**Frames**

De acordo com a camada de enlace de dados, a comunicação pelo barramento CAN é feita por meio de frames CAN.

![alt text](docs/imgs/data_frame_can.png)

- **Campos do Frame:**
    - **Start of Frame (SOF)**: Indica o início do frame com um bit "0 dominante", e é utilizado para sincronizar os nós sob o barramento após ele estar ocioso.
    - **Identifier (ID)**: É o identificador do frame - valores mais baixos têm prioridade mais alta. Pode ter 11 bits (CAN 1.0 e o CAN 2.0A) ou 29 bits (CAN 2.0B).
    - **Remote Transmission Request (RTR)**: Indica se um nó envia dados ou solicita dados dedicados de outro nó. Se definido como "0 dominante" é um *data frame*, se definido como "1 recessivo" é um *remote frame*.
    - **Substitute Remote Request (SRR)**: Nos frames extended (CAN 2.0B), substitui o bit RTR no local da mensagem padrão.
    - **Controle**: O contém o  *Identifier Extension Bit* (IDE), que é um "0 dominante" para indicar frames de 11 bits, e "1 recessivo" para indicar frames de 29 bits. Ele também contém o *Data Length Code* (DLC) de 4 bits, que especifica o comprimento dos bytes de dados a serem transmitidos.
    - **Dados**: Os dados contêm os bytes de dados, também conhecidos como carga útil, que incluem sinais CAN que podem ser decodificados para obter informações.
    - **Cyclic Redundancy Check (CRC)**: Verificação de erro.
    - **Acknowledgement (ACK)**: A confirmação de recepção, trata-se de um bit sobrescrito pelos receptores como "0 dominante", caso não haja erros.
    - **End of Frame (EOF)**: Indica o encerramento do frame, com 7 bits "1 recessivos", e desabilita o *bit stuffing*.
    - **Inter-Frame Space (IFS)**: É o espaço entre frames, sendo 7 bits que contém a quantidade de tempo requerido para move um frame.

- **Tipos de Frame:**
    - **Data frame**: transporta dados de um nó CAN emissor para um ou mais nós receptores.
    - **Error frame**: usado por um nó CAN para indicar a detecção de um erro de comunicação e contém um sinalizador de erro e um delimitador de erro.
    - **Remote frame**: pode ser usado para solicitar determinados dados de um nó CAN e é semelhante ao quadro de dados, exceto pela ausência de um campo de dados e pelo campo RTR ser 1 (recessivo).
    - **Overload frame**: pode ser usado para fornecer atraso adicional entre outros frames CAN, caso alguns nós CAN necessitem de tempo adicional para processamento.

**Sinais Diferenciais**

A transmissão de dados no CAN utiliza sinais diferenciais. Essa técnica melhora significativamente a imunidade a ruído, pois qualquer interferência eletromagnética tende a afetar igualmente ambos os fios, mantendo constante a diferença de potencial entre eles, que é o que carrega a informação no barramento.

O nível recessivo (1) corresponde a uma diferença de tensão menor que 0,5V entre o CAN_H e o CAN_L. Já o nível dominante (0) é detectado quando a diferenção de tensão for no mínimo 0,9V.

![alt text](docs/imgs/sinal_can.png) ![alt text](docs/imgs/sinal_can_2.png)

**Verificação e Sinalização de Erros**

O protocolo CAN possui algumas formas de identificar erros, senso as principais:

- **Bit Stuffing**: Técnica preventiva aplicada apenas nos *data frames* e *remote frames*, na qual após cada conjunto de **5 bits iguais consecutivos** é inserido um bit *stuffing*. Os campos ACK e EOF não passam por essa técnica. O controlador do receptor remove os bits *stuffing*.

- **Cyclic Redundancy Check (CRC)**: Antes da transmissão de um *data frame* seu CRC é calculado e inserido no campo CRC. Na recepção desse frame, o cálculo é refeito (a parti do campo SOF até o EOF) e comparado com o valor do campo CRC do frame, e em caso de erro um *error frame* é transmitido.

    - [Calculadora de CRC Online](https://emn178.github.io/online-tools/crc/)

- **Acknowledgement (ACK)** : Uma transmissor, ao enviar uma mensagem CAN, envia no campo ACK bits recessivos (1). No receptor, ao receber essas mensagens, ele retorna esses campo tendo bits dominantes (0) para indicar que a mensagem foi recebida com sucesso.  

- **Contadores de Erro**: São definidos os contadores **TXECTR** (contador de erros de transmissão) e **RXCTR** (contadores de erros de recepção), que determinam os estados de erro de cada nó, podendo ser erro passivo ou ativo.

    - **Erro passivo**: representa o estado normal de um nós, podendo transmitir ou receber mensagens, mas o flag de erro passivo é enviado. Há um limite de falhas que podem ser aceitas de um dispositivos (TXECTR e RXCTR $\leq$ 127 erros), e caso a mesma seja ultrapassada este passa a ser um erro ativo.  

    - **Erro ativo**: indica que o nó está com erros frequentes, e nesse caso flags de erro ativo são enviados. Isso possibilita impedir que nós com erro frequentes utilizem o barramento. 

- **Barramento Off**: Se um nó atinge 255 erros (no TXECTR e RXCTR), o mesmo é desconectado do barramento e somente será iniciado por um reset.

**Processo de Arbitragem**

Em uma rede CAN, a prioridade com que uma mensagem é transmitida relativamente à outra é especificada pelos seu identificadores. A prioridade das mensagens são definidas durante a fase de projeto do sistema na forma de valores binários. Nesta definição de prioridades é considerado que o **identificador de menor valor numérico detém maior prioridade**.

Como o protocolo CAN permite o acesso simultâneo ao barramento por diferentes nós, quando mais de um nó acessa o barramento a arbitragem é requerida. O método de solução dos conflitos ao acesso usado é o ***Carrier Sense Multiple Access with Collision Avoidance* (CSMA/CA)**, em que a arbitragem é realizada bit a bit dos identificadores das mensagens. Cada nó observa a rede bit a bit utilizando o mecanismo *bitwise*, em que o estado dominante (0) se sobrepõe ao recessivo (1). Todos os nós que perdem a arbitragem tornam-se imediatamente receptores, e não fazem mais nenhuma tentativa enquanto a rede não estiver livre.

![alt text](docs/imgs/exemplo_arbitragem_can.png)

**Filtragem**

A maioria dos controladores CAN oferecem um serviço de filtragem de mensagens. O mesmo faz com que somente mensagens co o padrão de identificação pré-programado sejam armazenadas e sinalizadas no microcontrolador. Isso possibilita uma economia de tempo de leitura e processamento das mensagens recebidas. Essa operação normalmente envolve a configuração de duas máscaras para o identificador, de forma a selecionar as mensagens ou grupos de mensagens desejadas e descartar as não desejadas.

**Barramento Físico, Terminação e Conectores**

O barramento CAN é formado por um cabo de par trançado havendo o baseado em 2 e 4 fios, e os mesmos trabalham com os sinais de dados CAN_H e CAN_L. No caso dos barramentos com 4 fios, além dos sinais de dados, um fio com  Vcc (alimentação) e outro com o GND (referencia) fazem parte do barramento, levando a alimentação às duas terminações ativas da rede.

![alt text](docs/imgs/barramento_can.png)

Entre os tipos de terminação, temos: 
- **Terminação Básica**: um resistor de 120 $\Omega$ em cada terminação.

- **Terminação com Filtragem**: um capacitor entre dois resistores de 60 $\Omega$ em cada terminação. Com isso temos um filtra passa-baixa para reduzir picos de alta frequência. Um capacitor de 4,7nF gera uma atenuação de -3dB a uma frequência de 1,1Mbps. 

    ![alt text](docs/imgs/terminacao_com_filtragem_can.png)

Para a conexão dos nós ao barramento, a CiA recomenta o utilização do conector padronizado de 9 pinos (DB9):

![alt text](docs/imgs/conector_DB9_can.png)

Além do DB9 podemos encontrar conectores dos tipos RJ10, RJ45, M12 e 5 Mini.

**Práticas**:

1. **Prática CAN 01 (s2a18)**: Comunicação entre dois nós pelo barramento CAN, onde um nó envia um mensagem de 5 bytes (ID `0x12` e os caracteres `h`, `e`, `l`, `l` e `o`) e um mensagem estendida (ID `0xabcdef` e os caracteres `w`, `o`, `r`, `l`, `d`),  e o outro nó apenas recebe e exibe os dados.

    **Materiais**: 
    - 1 x [Arduino Uno](https://docs.arduino.cc/hardware/uno-rev3/);
    - 1 x [Arduino Mega](https://docs.arduino.cc/hardware/mega-2560/);
    - 2 x Módulo CAN BUS MCP2515 TJA1050 (Controlador [MCP2515](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP2515-Stand-Alone-CAN-Controller-with-SPI-20001801J.pdf) e Transceiver [TJA1050](https://hfo.pl/pdf/T/tja1050.pdf)).

        ![alt text](docs/imgs/modulo_can_mcp2515_tja1050.png)

    **Método**:
    - Utilizar a biblioteca [CAN (by Sandeep Mistry)](https://github.com/sandeepmistry/arduino-CAN) na versão 0.3.1.
    - Carregar o exemplo `CANSender.ino` no Arduino Uno.
    - Editar o exemplo `CANReceiver.ino` para `CS` na comunicação SPI ser compatível com a pinagem do Arduino Mega:
        ~~~c
        #include <CAN.h>
        void setup(){
            CAN.setPins(53); // Define o pino CS
            // ...
        }
        ~~~
    - Carregar o exemplo `CANReceiver.ino` modificado no Arduino Mega.

    **Implementação**: [projects/pratica_can_01](projects/pratica_can_01).

2. **Prática CAN 02 (s2a19)**: Enviar do status de uma chave monitorada por um nó sensor para um outro nó, que habilitará um led sinalizador. Introdução a logica dos filtros.

    **Materiais**: Os materiais da prática 01, mais:
    - 1 x chave;
    - 1 x led.

    **Método**:
    - Utilizar a biblioteca [mcp2515 (by Autowp)](https://github.com/autowp/arduino-mcp2515) na versão 1.2.1.
    - Carregar o exemplo `CAN_write.ino` no Arduino Uno.
    - Carregar o exemplo `CAN_read.ino` no Arduino Mega.

    **Implementação**: [projects/pratica_can_02](projects/pratica_can_02)

3. **Prática CAN 03 (s2a20)**: Enviar informações de sinais analógicos e digitais monitorado por um nó sensor para outro nó, que ligará um cooler  e/ou led. Introdução ao tratamentos dos bytes.

    **Materiais**: Os materiais da prática 02, mais:
    - 1 x Trimpot;
    - 1 x Cooler Ventoinha.

    **Método**:
    - Utilizar a biblioteca [mcp2515 (by Autowp)](https://github.com/autowp/arduino-mcp2515) na versão 1.2.1.
    - Carregar o exemplo `CAN_write.ino` no Arduino Uno.
    - Carregar o exemplo `CAN_read.ino` no Arduino Mega.

    **Implementação**: [projects/pratica_can_03](projects/pratica_can_03)

4. **Prática CAN 04 (s2a21)**: Monitorar o barramento CAN através de um analisador caseiro feito com o Arduino Nano. 

    **Materiais**: 
    - 1 x [Arduino Nano](https://docs.arduino.cc/hardware/nano).
    - 1 x Módulo CAN BUS MCP2515 TJA1050

    **Método**:
    - Baixar e instalar o software [CANHacker](https://www.mictronics.de/projects/usb-can-bus).
    - Baixar e instalar a [biblioteca MCP2515](https://github.com/autowp/arduino-mcp2515).
    - Baixar a biblioteca Arduino CAN Hacker pelo [arquivo ZIP](https://github.com/autowp/arduino-canhacker/archive/master.zip) ou seguindo as instruções do repositório [CAN Hacker (by Autowp) ](https://github.com/autowp/arduino-canhacker).
    - Após a instalação da biblioteca Arduino CAN Hacker, edite no arquivo `CanHacker.h` o valor de `canClock` para `MCP_8MHK` (de acordo as configurações do barramento do projeto).
    - Carregue o exemplo `usb_cdc.ino` da biblioteca `arduino-canhacker-master` no Arduino Nano.
    - Teste o analisador nos projetos das praticas anteriores.

    **Implementação**: [projects/pratica_can_04](projects/pratica_can_04)

5. **Prática CAN 05 (s2a22)**: Enviar as mensagens recebidas pelo CAN para a plataforma Node-RED. 

    **Materiais**: Os mesmos das práticas anteriores.

    **Método**:
    - Instale o [Node-RED](https://nodered.org) de acordo com as instruções do [site oficial](https://nodered.org/docs/getting-started/local).
    -  Rode localmente e acesse a plataforma pelo navegador em `http://localhost:1880`.
    - Em `Menage palette`, instale `node-red-node-serialport`.
    - Use as funções `serial in`, `serial out`, `serial request` e `serial control` para interagir com a serial no Arduino.
    - Click duas vezes nos elementos em blocos referentes as funções anteriores, e em `Properties`defina a porta `COM` do Arduino e o *baud rate* da serial.
    - Edite as praticas anteriores para deixei na implementação apenas os `Serial.print()` das informações que deseja enviar para a plataforma.  

### 2. [Fundamentos da rede CANopen](#2-fundamentos-da-rede-canopen)

**Características Gerais**:
- Suporta ambientes nom níveis de EMI elevador, característica intrínseca de imunidade:
    - Linha de *graund* (GND) separada;
    - Sinal com transmissão diferencial;
    - *Short data frames*.

- Modelo de comunicação adaptável;

- Transmissão de parâmetros e dados de configuração.

- Performance da comunicação:
    - Tempo de resposta 
        - <1ms para 256 I/Os (digital)- 1Mbps
        - 5ms para 128 I/Os (analógico) - 1Mbps
    - Priorização de mensagens;
    - Processo de transmissão de dados flexível:
        - Transmissão somente quando requerido (*change-of-state*);
        - Base de tempo pode ser definida para cada valor (*cyclic*);
        - Transmissão simultânea a todos os dispositivos conectados a rede (*broadcast*).
- Acesso não destrutivo ao barramento (*Non-destructive bus access*):
    - Mensagens prévias serão sempre transmitidas;
    - Não perde frames no caso de colisão.

- Detecção de erro de frame
    - Permite implementar histórico de erro;
    - Watchdog monitora a disponibilidade do dispositivo.

**Principais Conceitos**:

![alt text](docs/imgs/intro_principais_conceitos_canopen.png)

Os mesmos se relacionam da seguinte forma:

![alt text](docs/imgs/relacao_entre_os_conceitos_canopen.png)

**Modelos Comunicação**:

![alt text](docs/imgs/modelos_comunicacao_canopen.png)

- **Mestre/escravo**: Neste modo, um nó atua como mestre (por exemplo, uma interface de controlo), enquanto os outros nós funcionam como escravos (por exemplo, um servo motor).
    - O mestre é responsável por enviar ou solicitar dados dos escravos.
    - É tipicamente utilizado para diagnósticos, configuração ou gestão de estados dos nós.
    - Um exemplo de serviço que utiliza este protocolo é o NMT (*Network Management Objects*), que permite ao mestre controlar o estado dos escravos.

- **Cliente/Servidor**: Um cliente envia um pedido de dados a um servidor, que por sua vez responde com os dados solicitados.
    - Este modelo é empregado quando, por exemplo, um mestre necessita de dados do Dicionário de Objeto (OD) de um escravo.
    - A leitura de dados de um servidor é chamada de '*upload*', enquanto a escrita é um '*download*'.
    - O principal serviço que utiliza este protocolo é o SDO (*Service Data Object*), que permite a leitura e escrita de valores do Dicionário de Objeto de um nó CANopen através do bus CAN.

- **Produtor/Consumidor**: Neste modelo, um nó produtor transmite dados para a rede, e um ou mais nós consumidores recebem e utilizam esses dados.
    - O produtor pode enviar os dados mediante solicitação (modelo "*pull*") ou sem um pedido específico (modelo "*push*").
    - Este protocolo é utilizado para a transferência eficiente de dados operacionais em tempo real.
    - O serviço associado é o PDO (*Process Data Object*), que transporta dados operacionais como pressão ou temperatura. Os PDOs podem ser enviados de forma síncrona (em resposta a uma mensagem SYNC) ou orientada por eventos (por exemplo, periodicamente).

**Object Dictionary (OD)**

Todos os nós CANopen têm um dicionario de objetos, que são uma estrutura padronizada que contém todos os parâmetros que descrevem o comportamento do mesmo.

As entradas do OD são pesquisadas por meio de um índice de 16 bits e um subíndice de 8 bits. Especificamente, uma entrada no dicionário de objetos é definida por atributos:

- **Índice**: endereço base de 16 bits do objeto.
- **Nome do objeto**: Nome do dispositivo do fabricante.
- **Código objeto**: matriz, variável ou registro.

    ![alt text](docs/imgs/ob_opcoes_definitions.png)

- **Tipo de dados**: Ex.: VISIBLE_STRING, ou UNSIGNED32 ou Nome do Registro.
- **Acesso**: 

    ![alt text](docs/imgs/ob_opcoes_acesso.png)

- **Categoria**: Indica se este parâmetro é obrigatório/opcional (M/O).

O dicionário de objetos é dividido em **seções padronizadas** onde algumas entradas são obrigatórias e outras são totalmente personalizáveis:

![alt text](docs/imgs/ob_structure_canopem.png)

É importante ressaltar que as entradas OD de um dispositivo podem ser acessadas por outro dispositivo via CAN usando, por exemplo, **SDOs**.

Para entender o OD, é útil consultar o *electronic data sheet* e o *device configuration file*:

![alt text](docs/imgs/eds_and_dcf.png)

- **Electronic Data Sheet (EDS)**: Na prática, a configuração/gerenciamento de redes CANopen é feito por meio de ferramentas de software/API. Para simplificar, a CiA 306-1 define um formato de arquivo INI, que atua como o "modelo" para o OD de um dispositivo.

- **Device Configuration File (DCF)**: Suponha que uma fábrica tenha adquirido um equipamento que sera integrado ao sue sistema. Ao fazer isso, o operador edita o EDS do dispositivo com detalhes específicos da integração, por exemplo, especificando a taxa de bits do dispositivo e o ID do nó. Este EDS modificado pode ser exportado como um DCF para habilitar o dispositivo para integração em uma rede específica.

**Frames e COB-IDs**

Para entender a comunicação, é útil entender primeiro o frame CANopen:
- Os identificadores (IDs) dos dispositivos vão de 1 a 127;
- 127 é um limite lógico;
- O *transceiver* pode ser um fator limitante; 
- Não pode haver identificadores duplicados. 

![alt text](docs/imgs/frame_canopen.png)

Os 11-bit do ID são referidos como o **Identificador de Objeto de Comunicação** (COB-ID) e é dividido em duas partes:
- **Fuction Code**: 4 bits refletem a 'funcionalidade' da mensagem.
- **Node ID**: 7 bits refletem o ID do nó (entre 1 e 127).

Além disso, CANopen especifica uma série de ***Communication Object*** que atendam casos de uso diferentes. Cada objeto de comunicação representa uma estrutura pré-definida na comunicação CANopen, incluindo:

![alt text](docs/imgs/exemplos_co_fc_canopen.png)

-  **NMT (*Network Management Objects*)**: 
    - Segue o protocolo mestre/escravo.
    - Um mestre NMT controla o estado (pré-operacional, operacional e parado) dos escravos através de comandos NMT (iniciar, parar e reiniciar), redefinindo um nó ou alterando o seu estado operacional.
    - Para alterar o estado, o mestre envia um frame de 2 bytes com **CAN ID 0** (*Function Code*= 0000 e *Node ID*= 0000000 - *broadcast*), e todos os escravos processam esta mensagem. 
    - O primeiro bytes contém o estado solicitado, podendo este ser:
        - ***Operational*** : 0x01
        - ***Stopped***: 0x02
        - **Pre Operational**: 0x80
        - ***Reset Application***: 0x81
        - ***Reset Communication***: 0x82

        ![alt text](docs/imgs/estados_dos_dispositivos_canopen.jpg)

    - O segundo byte contém o ID do nó de destino.

    - Exemplo de um frame NMT:

        ![alt text](docs/imgs/frame_nmt_canopen.png)

- **SYNC (*Synchronization Object*)**: 
    - Segue o protocolo produtor/consumidor. 
    - Fornece o mecanismo básico de sincronização da rede.

        ![alt text](docs/imgs/sync_canopem.png)

    - Um produtor (em geral, o controlador/mestre da rede) transmite o SYNC (**COB-ID 0x80**) periodicamente, sendo este período de transmissão configurável.

        ![alt text](docs/imgs/exemplo_sync_canopen.png)

    - Qualquer dispositivo pode ser o consumidor da mensagem SYNC.
    - Geralmente é usado para fins de gerenciamento de carga. Em tais casos de uso, os PDOs nos consumidores são acionados pela recepção de um número pré-configurado de SYNCs. 
    - Por padrão, as mensagens não transportam dados, mas a parti da CiA 301 versão 4.1 podem opcionalmente oferecer um valor de contador SYNC de 1 byte. 

- **EMCY (*Emergency Object*)**: 
    - Acionadas por um erro interno do diapositivo.
    - Segue o protocolo produtor/consumidor, onde a mensagem de emergência é transmitida pelo produtor como um único frame de até 8 bytes. Zero ou mais consumidores emergência podem receber essas mensagens e iniciar contra-medidas adequadas. 

        ![alt text](docs/imgs/frame_emcy_canopen.png)

    - Uma mensagem de emergência é transmitida apenas uma vez por evento de erro.

    - A mensagem EMCY tem o **COB-ID 0x80 + ID do nó**. Os bytes de dados contêm informações sobre o erro, incluindo um código de erro de 2 bytes, um registrador de erro de 1 byte e até 5 bytes de informações de erro específicas do fabricante.

    - A tabela de códigos de erro da CiA 301: 

        ![alt text](docs/imgs/emcy_error_codes_canopem.png)

    - Códigos de erro adicionais podem ser especificados em perfis de dispositivos conforme a CiA 4XX. O suporte para EMCY é opcional, mas se um dispositivo o suportar, deverá suportar pelo menos os códigos de erro 0x0000 e 0x1000.

- **TIME (*Timestamp Object*)**: 
    - Segue o protocolo produtor/consumidor e fornece um relógio em toda a rede.
    - O produtor transmite a mensagem TIME com o **COB-ID 0x100** e um payload de 6 bytes: 4 bytes de dados contêm o tempo em ms após a meia-noite e os próximos 2 bytes contêm o número de dias desde 1º de janeiro de 1984.

        ![alt text](docs/imgs/time_canopem.png)

    - Os *jitters* de tempo devem ser considerados, pois atrasos na transmissão podem ocorrer devido a arbitragem.
    - O tempo entre as mensagens de TIME dependem da aplicação, ou seja, é definido pelo produtor. 

- **HEARTBEAT (*Heartbeat Object*)**: Um nó envia periodicamente uma mensagem HEARTBEAT para comunicar o seu estado. É usado para verificar se todos os dispositivos da rede tem seu estado NMT como foram configurados.

    ![alt text](docs/imgs/heartbeat_canopem.png)

    - Se o *heartbeat* estiver ativado, o nó envia seu estado NMT para o barramento sem sem solicitação e ciclicamente.

    - Este serviço é ativado definindo o tempo *heartbeat-producer-time* no dicionario de objetos para um valor diferente de zero. Como regra geral, o timeout do consumidor deve ser duas vezes o período do produtor.

    - A mensagem tem o **COB-ID 0x700 + ID do nó** e a carga útil contém o estado do nó no primeiro byte de dados.

    - Em sistemas CANopen antigos, o protocolo *Node/Life-Guarding* baseado em frames remotos CAN era usado para a mesma finalidade.

-  **PDO (*Process Data Object*)**: Utilizado para a transferência eficiente de dados operacionais em tempo real, como pressão ou temperatura. Os PDOs podem ser enviados de forma síncrona (em resposta a uma mensagem SYNC) ou orientada por eventos (por exemplo, periodicamente). A comunicação PDO utiliza o protocolo produtor/consumidor.
    - **Campos de um frames PDO:** 

        ![alt text](docs/imgs/frame_pdo_canopen.png)

        - **COB-ID**:

            ![alt text](docs/imgs/exemplo_cobid_pdo.png)
        
            - **TPDO (*Transmit Process Data Object*)** : Usado pelo produtor para transmitir seus dados para outros dispositivos na rede, permitindo configurar a quantidade e o tipo de dados a serem transmitidos.
                - **COB-ID = 0x180 + Node ID + TPDO Number**

                ![alt text](docs/imgs/pdo_write_canopem.png)

            - **RPDO (*Receive Process Data Object*)**: Usado pelo consumidor para receber dados de outros dispositivos na rede, permitindo configurar o nó para "escuta" a transmissão.
                - **COB-ID = 0x200 + Node ID + RPDO Number**

                ![alt text](docs/imgs/pdo_read_canopem.png)

            Obs.: O *TPDO Number* e o *RPDO Number* são um número entre 1 e 4, representando um dos quatro possíveis tipos que um dispositivo pode ter.

        - **Campos de dados**: 
            - **Bytes 0-1** - 2 bytes
            - **Bytes 2-3** - 2 bytes
            - **Bytes 4-7** - 4 bytes

    - **Modos de transferência das mensagens PDOs:**

        ![alt text](docs/imgs/tipos_de_transmissao_pdo.png)

-  **SDO (*Service Data Object*)**: Permite que um nó CANopen leia ou escreva valores do dicionário de objeto (OD) de outro nó através do barramento CAN. As mensagens SDOs são enviadas através do protocolo "cliente/servidor". Especificamente, um "cliente" SDO inicia a comunicação com um "servidor" SDO. O objetivo pode ser atualizar uma entrada OD ("*download* SDO") ou ler uma entrada ("*upload* SDO"), o que permite, por exemplo, configuração e diagnóstico de nós.

    - **Campos de um frames SDO:**
        - **COB-ID**: 
            - ***Transmit* SDO** (0x580 + ID do nó): Usado para enviar comandos SDO (geralmente comandos de *download* ou *upload*).
            - ***Receive*** (0x600 + ID do nó): Usado para receber os dados solicitados no processo de *upload* ou *download*. 
        - **Bytes 0**:
            - **CCS (*client command specifier*)** - 3 bits: Identifica o tipo de transferência.
                - *Download* (1 - $001_b$): Comando para escrever dados em um OD de um dispositivo.
                - *Upload* (2 - $010_b$): Comando para ler dados de um OD de um dispositivo.
            - ***n*** - 2 bits: Número de bytes do campo de dados (bytes 4-7) que não contêm dados.
            - **e** - 1 bits: Se definido, indica uma 'transferência rápida' (todos os dados estão em um único quadro CAN).
            - **s** - 1 bits: se definido, indica que o tamanho dos dados é mostrado em *n*.
        - **Byte 1-2** - 16 bits: Índice refletem o endereço OD a ser acessado
        - **Byte 3** - 8 bits: Subíndice refletem o endereço OD a ser acessado.
        - **Bytes 4-7**: Contêm os dados (máximo 4 bytes). Quando um comando de *download* é enviado, esse campo na mensagem de resposta fica vazio, pois é apenas uma confirmação que a operação de escrita foi realizada. Já quando um comando de *upload* é executado, esse campo na mensagem de resposta contêm o valor do dado armazenado OD especificado.

    - **Exemplo de um frame SDO**:
    
        ![alt text](docs/imgs/sdo_frame_canopem.png)

    - **Modos de transferência das mensagens SDOs:**

        ![alt text](docs/imgs/sdo_variantes_canopem.png)

        - Transferência rápida,
        - Transferência normal (segmentada),
        - Transferência em bloco.

- **USDO (*Universal Service Data Object*)**: Uma adição no CANopen FD, que permite o estabelecimento dinâmico de comunicação cruzada em unicast e broadcast, beneficiando sistemas embarcados que podem ser modificados pelo utilizador em tempo de execução.

**Device Profiles**

O perfis de dispositivos são especificações padronizadas que definem o comportamento e a funcionalidade de dispositivos típicos em uma rede CANopen. Eles fornecem uma descrição detalhada das funções que um dispositivo pode desempenhar, como deve se comunicar na rede e como os dados devem ser estruturados.

Lista dos perfis padronizados da CiA:
- [Generic device profiles](https://www.can-cia.org/can-knowledge/generic-device-profiles)
- [Application-specific device profiles](https://www.can-cia.org/can-knowledge/application-specific-device-profiles)
- [Interface profiles](https://www.can-cia.org/can-knowledge/interface-profiles)
- [Application profiles](https://www.can-cia.org/can-knowledge/application-profiles)

**Protocolos de Controle de Erros**

Além do objeto de comunicação HEARTBEAT, os seguintes protocolos também permitem o monitoramento de uma rede CANopem:

- ***Node/Life-Guarding***: Este serviço baseia-se no fato de o mestre NMT enviar uma mensagem RTR, de tal forma que o escravo apenas a responde. Na estrutura da mensagem temos o bit 7 sendo alterado em cada transferência ( permitindo assim determina se a mesma foi perdida) e nos bit 6 à 0 é inserido o status NMT atual do escravo.

    ![alt text](docs/imgs/nodeguarding_intrelavos.png)

    Existem 3 intervalos de tempo: o *Guard time*, que é o tempo entre duas mensagens RTR; o *Live time factor*, que é um multiplicador para o tempo de guarda; e o *Possible live time*, que é o tempo resultante da multiplicação do *Guard time* pelo *Live time factor*.

- ***Boot-up***: O o protocolo de inicialização representa um tipo especial de protocolo de controle de erros. O mesmo é transmitido como a ação final do estado NMT de *initialising* e antes do *pre-operational*. A recepção desta mensagem pode indica que um novo equipamento foi cadastrado na rede ou a ocorrência de falha na alimentação do dispositivo já conhecido.  

    ![alt text](docs/imgs/boot-up_canopem.png)


### 3. [Arquitetura, Componentes e Projeto de Rede](#3-arquitetura-componentes-e-projeto-de-rede)

**Arquiteturas:**

- **Topologia Básica**

    A rede CANopen utiliza uma linha de transmissão principal (*trunk cable*), que deve ser terminada em ambas as extremidades físicas com resistores de terminação de 120 Ω compatíveis com a impedância característica do cabo. O cabo principal pode interligar dispositivos por meio de *T-connectors* ou ramais curtos (*stub cables*).

    Um TAP, em combinação com *cabos drop* (ou *stub*), permite a formação de uma topologia de estrela parcial. Para minimizar reflexões e preservar a integridade do sinal, a regra geral é manter os cabos o mais curtos possível, seguindo as fórmulas de dimensionamento recomendadas. Além disso, a soma dos comprimentos de todos os *cabos drop* não deve exceder o limite calculado para a taxa de transmissão utilizada.

    O comprimento máximo do barramento depende diretamente da velocidade de transmissão (*bit rate*) e da bitola do cabo. Por exemplo, cabos de 0,25 mm² permitem até cerca de 200 m a 125 kbit/s com 32 nós, enquanto cabos mais grossos (0,75 mm²) podem chegar a 550 m. Atrasos de propagação, perdas resistivas e a qualidade dos conectores devem ser considerados no projeto.

    ![alt text](docs/imgs/topologia_basica_redes_canopem.png)

    Obs.: Não pode haver o cascateamento de TAPs.

- **Topologia com Repetidor**

    A rede CANopem pode ser composta por um ou vários segmentos, interligados fisicamente através de um repetidor CAN. Ele recebe os sinais de um lado, recondiciona (restaura níveis de tensão, forma de onda e temporização) e retransmite para o outro lado.

    Um repetidor:
    - Permitindo assim mais de 64 nós;
    - Pode fornecer isolamento entre os segmentos, senso do que cada uma desses segmentos ter os resistores de terminação;
    - É transparente, do ponto de vista da rede, pois simplesmente encaminha os sinais CAN, com os dispositivos conectados ao barramento participando da mesma arbitragem;
    - Não permite aumentar o comprimento total do barramento. 
    - Adiciona um atraso de propagação no barramento, e esse atraso reduz o comprimento máximo do barramento. Um atraso de 5ns leva a uma redução de 1m.

        ![alt text](docs/imgs/topologia_com_repetidor_redes_canopem.png)

- **Topologia com Encadeamento de Cabo**

    Os dispositivos são conectados em série ao longo de um único cabo principal (*trunk cable*). Cada nó possui dois conectores — um de entrada e um de saída — permitindo que o cabo passe “através” do dispositivo até o próximo.

    O encadeamento pode ser realizado de duas maneiras:

    - Conectando dois cabos ao mesmo conector:

        ![alt text](docs/imgs/topologia_com_encadeamento_de_cabo_1_redes_canopem.png)

    - Conectando os dois cabos aos conectores individuais de dispositivos com uma conector para entrada e outros para saída:

        ![alt text](docs/imgs/topologia_com_encadeamento_de_cabo_2_redes_canopem.png)

- **Topologia com Bridge**

    Uma *bridge* CAN (ponte) conecta duas ou mais redes CAN que não compartilham o mesmo barramento físico. Ela lê mensagens de uma rede, interpreta de acordo com regras configuradas e retransmite para outra rede apenas as mensagens desejadas. Ao contrário do repetidor, a bridge não precisa repetir tudo — pode filtrar, alterar IDs, ou até converter protocolos.

    Um *bridge*:
    - Pode separar a rede CAN geral em sub-redes independentes;
    - Fornece uma arbitragem individual;
    - Possibilita que cada sub-rede tenha velocidades de transmissão distintas;
    - Permite ampliar o tamanho máximo da rede.

    ![alt text](docs/imgs/topologia_com_bridge_redes_canopem.png)

- **Topologia com Fonte de Alimentação Externa**

    Trata-se de uma variação na infraestrutura elétrica da rede para que os dispositivos recebam energia pelo próprio cabo de comunicação. Além dos dois fios de sinal do barramento CAN (`CAN_H` e `CAN_L`) e do fio de referência (`CAN_GND`), o cabo do barramento leva também linhas de alimentação (tipicamente `CAN_V+` e `CAN_V-` e usa o `CAN_GND` como retorno). O CiA 303-1 recomenda que essa tensão esteja entre +18 VDC e +30 VDC para permitir o uso de fontes padrão de 24 VDC.

    ![alt text](docs/imgs/topologia_com_alimentacao_externa_redes_canopem.png)

    Obs.: Repetidores, *bridges*, cabos RJ45 não encaminham o sinal de alimentação `CAN_V+`.

**Sistema de Cabeamento** ([CiA 303-1](docs/cia303.1-v2.0.1_device_and_network_design-part1_canopen_physical_layer.pdf))

- **Elementos**
    - ***Bus Cable***: Cabo de barramento terminado em ambas as extremidades por resistores de terminação.
    - ***Stub/Drop Cable***: Ramal curto conectado ao cabo de barramento, não terminado por resistor, que liga o dispositivo CANopen ao barramento.
    - ***T-connector***: Conector elétrico em formato de “T”, com três pontos de conexão, usado para ligar o cabo de barramento a um dispositivo ou a um *stub cable*.
    - ***Trunk Cable***: Espinha dorsal do cabo de barramento, sem ramais (*stub cables*), que interliga os dispositivos ao longo da rede.

- **Recomendações**:
    - **Cabos**:
        - **Impedância característica**: usar cabos com 120 Ω e atraso específico de 5 ns/m (típico para cabos CAN de alta velocidade – ISO 11898-2).
        - **Comprimento máximo**: 

            ![alt text](docs/imgs/tabela1_cia303.1.png)

            Obs.: Recomendação para redes com memos de 64 dispositivos.

        - **Bitola mínima**:

            ![alt text](docs/imgs/tabela2_cia303.1.png)

        - **Cabo vs *Bit rate***: 

            O *bit rate* depende do tipo de cabo (impedância e bitola) e do seu comprimento. A estimativa da CiA 301 para tal relação é: 

            ![alt text](docs/imgs/comprimento_do_caso_vs_bit_rate_canopen.png)

            Obs.: A estimativa foi baseada em um atraso de propagação de 5ns/m. Os atrasos de controladores, *transceiveres* e optoacopladores precisam ser considerados.

            Obs.: Em algumas documentações, frequentemente encontra-se o valor máximo de 40m para um *bit rate* de 1Mbit/s. Este dado, corresponde ao calculo realizado considerando um cabo sem isolamento elétrico.

        - **Correspondência de impedâncias**: cabos e conectores devem ter impedância compatível para evitar reflexões.
        - **Cabos *Stub* (*Drop*)**: Devem ser o mais curtos possível para evitar reflexões.
            - Cumprir fórmulas do CiA para calcular comprimento máximo de stub em função da taxa de bits: $l_u < \frac{t_{\mathrm{PROPSEG}}}{50 \cdot t_p}$

            - A soma de todos os stubs também é limitada por: $\sum_{i=1}^{n} l_{u_i} < \frac{t_{\mathrm{PROPSEG}}}{10 \cdot t_p}$
    
    - **Comprimento Máximo dos *Stub/Drop Cable***:

        ![alt text](docs/imgs/comprimento_max_cabo_drop.png)
        
        Sendo:
        - $Lmax$: comprimento máximo de um cabo drop.
        - $\sum Lmax$: valormáximo da soma dos cabos drop de um mesmo TAP.
        - $TAP_{distance}$: distancia mínima necessária entre dois TAPs (deve ser $>$ 60% do maior dos dois $\sum Lmax$).
        - $\sum LGmax$: valor máximo da soma dos cabos drop na rede.

        **Exemplo do calculo**:

        ![alt text](docs/imgs/exemplo_calculo_comprimento_drop.png)

    - **Conectores**:
        - Usar conectores cuja resistência de transmissão seja entre 2,5 mΩ e 10 mΩ.
        - Plug (macho) não deve ser alimentado; tomada (fêmea) pode ser alimentada.
        - Seguir [CiA 106](docs/cia106-v1.1_connector_pin_assignmente_recommendations.pdf) para pinagem padronizada de conectores.

    - **Resistores de Terminação**:
        - Valor nominal 120 Ω ± (mínimo aceitável: 118 Ω).
        - Devem estar apenas nas duas extremidades físicas do barramento.
        - Resistores devem ser posicionados o mais próximo possível do último nó.

**Projeto da Rede**   
- **Dicas básicas**:
    - Documente o projeto da rede com os cálculos associados;
    - Atribuir a cada nó um endereço exclusivo;
    - Certifique-se que os nós de uma mesma rede tenham a mesma velocidade de transmissão;
    - Verificar se o comprimento e a seção transversal dos cabos estão de acordo com a norma;
    - Verificar se todos os segmentos têm resistores de terminação em suas extremidades.

- **Blindagem e Aterramento**
Para minimizar distúrbios de modo comum e garantir alta imunidade a interferências eletromagnéticas, recomenda-se:

    - Em redes CANopen totalmente isoladas galvanicamente, o fio de terra (CAN_GND) deve ser conduzido junto com o cabo de comunicação. Esse fio deve ser conectado ao potencial de terra do CAN em apenas um ponto da rede.

    - Se houver um dispositivo com interface não isolada galvanicamente, ele será o responsável por fornecer a conexão ao terra do barramento. Apenas um dispositivo desse tipo deve estar conectado à rede.

    - O projetista deve garantir que a tensão de modo comum nos transceptores não ultrapasse o limite suportado pelos dispositivos.

    - Recomenda-se usar cabos de par trançado blindados. A blindagem deve ser conectada ao terra funcional (FE) de cada dispositivo. Isso pode ser feito, por exemplo, conectando a blindagem à carcaça metálica do conector (ex.: conector SUB-D de 9 pinos).

- **Cabeamento em Gabinetes**

    Normalmente a cabeamento de dispositivos em gabinetes é baseado em conectores RJ45.

    ![alt text](docs/imgs/topologia_de_cabeamento_de_dispositivos_em_gabinetes.png)
    
    Quando se utilizam esses elementos de infraestrutura diretamente na linha tronco da rede, algumas restrições devem ser observadas:

    -  O comprimento máximo permitido para o cabo é reduzido em 50% em relação ao especificado para um cabo CANopen padrão.

    - Esses elementos de cabeamento devem ser empregados apenas dentro de um único gabinete. Não são recomendados para interligar gabinetes diferentes diretamente.

    - Caso seja necessário distribuir a rede CANopen entre gabinetes distintos, deve-se utilizar cabos CANopen padrão para fazer essa interligação.

    - Conectores RJ45 não possuem pinos para o CAN_V+, impossibilitando a distribuição de energia pela rede. Assim, dispositivos que dependam de alimentação pelo barramento não receberão energia por esse tipo de conexão.

### 4. [CANopen na Prática](#4-canopen-na-pratica)