# AlgoritmoBanqueiro

projeto da cadeira de Infraestrutura de Software (SO), do professor Marcelo Arcoverde

### Para testar o código, basta definir os argumentos e usar   (args=argumentos, substitua a palavra args pelos seus args numericos):
    make && ./banker args 
### E para limpar o output, pós execução, basta usar:

        make clean


### Arquivos utilizados na preparação de código

##### comandos.h -> struct de dados representando os comandos a serem coletados, e atendidos

##### dados.h -> struct de dados representando os dados relativos aos clientes, a serem coletados

##### lerdados.h -> protótipos das funções utilizadas em lerdados.c.

###### lerdados.c -> contém as declarações das funções contidas em lerdados.h, no caso: 

###### lerLinhas(para contabilizar as linhas presentes em customer.txt);
###### estadoSeguro (para calcular o cenário de estado inseguro dentro da função de leitura e execução dos comandos);
###### verificarConta(em conformidade com coletarComandos, realiza a ação, em caso de NÃO ser possível executar comandos, também conectada a estadoSeguro);
###### coletarComandos(acessar commands.txt para registrar os comandos, utilizar verificarConta para avaliar ser possível os realizar, caso sim, os executa e salva no arquivo result.txt criado pela própria função);
###### buscarDados (acessa customers.txt para coletar e registrar os dados presentes neste arquivo).