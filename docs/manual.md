# Para rodar na máquina local:
### Para rodar os testes siga os passos a seguir:
* Vá para a pasta do teste.
* Abra o makefile e descomente a a linha 2, HFOS_ROOT... e coloque o path da pasta hf-risc-st.
* No terminal vá para a pasta do teste e execute "make test".

### *Deve-se ter executado o teste antes de utilizar as seguintes ferramentas:*
### Para utilizar o CPPCHECK no test, execute no terminal, no diretório do teste, os passos a seguir:
* cppcheck test.c > cppcheck.log
* head cppcheck.log -n 200

### Para utilizar o gcov no test, execute no terminal, no diretório do teste, os passos a seguir:
* gcov hf_riscv_sim.c >gcov.log
* head gcov.log -n 200

### Para utilizar o gprof no test, execute no terminal, no diretório do teste, os passos a seguir:
* gprof ./hf_riscv_sim gmon.out >gprof.log
* head gprof.log -n 200

# Para rodar no travis:
* Apenas de um commit.

# Para adicionar novos testes:
### Na máquina local:
* Crie um diretório para o novo teste.
* Crie os arquivos test.c, tester.c, makefile (baseie-se nos já existentes).
* Execute com make test

### No travis:
* No github, abra o arquivo *travis.yml*.
* Adicione na parte do *script*:
  * Um comando para chegar a pasta do teste.
  * Um comando para executar o teste (*make test*).
  * (opcional) Adicione os comandos para utilizar as ferramentas (citadas anteriormente).
