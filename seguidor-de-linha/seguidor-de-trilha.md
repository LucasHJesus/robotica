# Robô seguidor de trilha
## Alunos:
### Lucas Humberto jesus de Lima 12011ECP011
### Izabela da Silva Neves 11811ECP026

## introdução

O projeto tem o objetivo de projetar e contruir um robô autonomo que, dada uma linha preta em superficie de cor diferente, seja capaz de se manter sobre a linha enqunato move-se para frente. Para isso, ao encontrar uma curva, o robô deve mover uma das rodas para frente enquanto a outra segue para trás, girando o robô até que ele fique alinhado com o trajeto. Para realizar tal tarefa, foram usados dois modulos detectores de reflexo colocados um de cada lado da linha a ser detectada, dois motores DC ligados em rodas, que movem o equipamento um arduino, que recebe os sinais dos sensores, e os usa para controlar as rodas.

## lista de materiais

 `* 1 arduino
  * 1 mini protoboard
  * 1 modulo L298N 
  * 2 modulos MH-sensor-series (sesores infravermelho)
  * 2 pilhas 4.2V, 9800mA. 
  * 1 kit 2WD(two wheel drive) - contém:
  * 2 motores DC com caixa de redução
  * 2 rodas com pneus
  * 1 roda boba
  * 1 placa de acrilico, 
  * suporte para pilhas

O kit 2WD foi usado para dar estrutura ao carrinho, deixando-o com as rodas, motores, suporte de pilhas, e uma placa acrilica para fixação dos outros componentes(figura 1). 

 ![2WD-kkit](https://github.com/LucasHJesus/robotica/assets/96553038/cfd74b10-2df7-44a7-9161-2a376d1a42da)

 Após a montagem da base, os motores foram conectados em uma ponte H, através do módulo L298N, que fornece duas pontes em um mesmo moódulo. Para conectá-la aos motores, é necessário enviar dois fios para cada motor, que controlam o lado e a velocidade com que eles giram, além de alimentá-los. É impotante ressaltar que a alimentação da ponte H é feita diretamente das pilhas, já que o arduino não possui saida com potência suficiente para alimentar ambos os motores

 O passo seguinte foi montar o arduino e programá-lo para controlar os motores, girando-os nos sentidos e velocidades desejados. Para isso, foram ligados dois fios de comando do arduino para a ponte H para cada motor, um para cada sentido em que o motor deve girar.

 Por último, foram montados os sensores de reflexo, na frente do carrinho. A distibuição espacial deles se dá de forma que cada um fique de um lado da linha a ser seguida. Desse modo, quando qualquer um deles passar sobre a linha, para de detectar reflexo, já que a linha é preta, e não refletindo luz, ao contrário do chão. Ao não detectar reflexo, o sinal mandado ao arduino muda, e esse sinal é usado para decidir a movimentação das rodas, que giram de modo a posicionar os sensores ao redor da linha.

 Nessa montagem, o protoboard foi usado para ligar as alimentações, tanto dos sensores quanto da ponte H.
 
![robo](https://github.com/LucasHJesus/robotica/assets/96553038/35746a49-48e7-45ff-9628-276afa0e0df0)

 ## Conclusão

 Para esse projeto, foram usados apenas dois sensores, porém, ao adicionar outros, é possivel melhorar a responsividade do robô.

A maior dificuldade encontrada foi programar o sentido de rotação dos motores, e sincronizá-los com os valores lidos pelos sensores. Porém, além dela, houve dificuldade em alimentar a pone H e os sensores, sendo necessaria a adição de um protoboard para realizar essa função.

